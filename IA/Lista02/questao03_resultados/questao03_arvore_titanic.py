from pathlib import Path

import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
from sklearn.metrics import (
    accuracy_score,
    classification_report,
    confusion_matrix,
)
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, export_text, plot_tree


PASTA_ATUAL = Path(__file__).resolve().parent
PASTA_LISTA02 = PASTA_ATUAL.parent
ARQUIVO_TITANIC = PASTA_LISTA02 / "titanic completo.csv"


# 1. Leitura e visualizacao inicial da base
base_original = pd.read_csv(ARQUIVO_TITANIC)

print("Dimensoes da base original:", base_original.shape)
print("\nPrimeiras instancias:")
print(base_original.head())
print("\nValores ausentes por coluna:")
print(base_original.isna().sum())


# 2. Tratamento dos dados ausentes
# Estas colunas possuem muitas ausencias e nao serao utilizadas.
colunas_removidas = ["boat", "body", "cabin", "home.dest"]
base = base_original.drop(columns=colunas_removidas).copy()

print("\nColunas restantes:")
print(base.columns.tolist())
print("\nAusencias antes da remocao das linhas incompletas:")
print(base.isna().sum())

# Como ainda nao foi estudada imputacao, removemos as linhas que continuam
# contendo pelo menos um valor ausente.
base = base.dropna().reset_index(drop=True)

print("\nDimensoes depois da limpeza:", base.shape)
print("Total de valores ausentes depois da limpeza:", int(base.isna().sum().sum()))


# 3. Distribuicao da classe e de atributos importantes
print("\nDistribuicao da classe survived (0 = morreu; 1 = sobreviveu):")
print(base["survived"].value_counts().sort_index())
print("\nDistribuicao por sexo e classe:")
print(pd.crosstab(base["sex"], base["survived"], margins=True))
print("\nDistribuicao por classe do passageiro e classe-alvo:")
print(pd.crosstab(base["pclass"], base["survived"], margins=True))
print("\nDistribuicao por porto de embarque e classe-alvo:")
print(pd.crosstab(base["embarked"], base["survived"], margins=True))

sns.countplot(data=base, x="survived")
plt.title("Distribuicao da classe: 0 = morreu; 1 = sobreviveu")
plt.tight_layout()
plt.show()


# 4. Separacao dos atributos e da classe
# name e ticket continuam presentes na base limpa, mas nao sao usados na
# arvore porque sao identificadores textuais com muitos valores diferentes.
atributos_utilizados = [
    "pclass",
    "sex",
    "age",
    "sibsp",
    "parch",
    "fare",
    "embarked",
]

X = base[atributos_utilizados].copy()
y = base["survived"].astype(int).copy()


# 5. Codificacao dos atributos
# sex e binario; embarked e nominal e, por isso, recebe one-hot encoding.
X["sex"] = X["sex"].map({"male": 0, "female": 1})
X = pd.get_dummies(X, columns=["embarked"], dtype=int)

print("\nAtributos depois da codificacao:")
print(X.head())
print("\nColunas usadas pela arvore:")
print(X.columns.tolist())


# 6. Divisao entre treino e teste
X_treino, X_teste, y_treino, y_teste = train_test_split(
    X,
    y,
    test_size=0.20,
    random_state=42,
    stratify=y,
)

print("\nTreino:", X_treino.shape)
print("Teste:", X_teste.shape)


# 7. Treinamento da arvore
# A profundidade foi limitada a 3 para produzir regras que possam ser interpretadas.
arvore = DecisionTreeClassifier(
    criterion="entropy",
    max_depth=3,
    random_state=42,
)
arvore.fit(X_treino, y_treino)


# 8. Avaliacao no conjunto de teste
previsoes = arvore.predict(X_teste)
acuracia = accuracy_score(y_teste, previsoes)

print(f"\nAcuracia no teste: {acuracia:.2%}")
print("\nMatriz de confusao:")
print(confusion_matrix(y_teste, previsoes, labels=[0, 1]))
print("\nMetricas por classe:")
print(
    classification_report(
        y_teste,
        previsoes,
        labels=[0, 1],
        target_names=["Morreu", "Sobreviveu"],
        zero_division=0,
    )
)


# 9. Regras obtidas
print("\nRegras da arvore:")
print(export_text(arvore, feature_names=list(X.columns), decimals=2))


def imprimir_qualidade_das_regras(modelo, dados, classe_real, conjunto):
    """Mostra cobertura, acertos e qualidade de cada folha/regra."""
    folhas = modelo.apply(dados)
    previsao = modelo.predict(dados)
    tabela = pd.DataFrame(
        {
            "folha": folhas,
            "real": classe_real.to_numpy(),
            "previsto": previsao,
        }
    )

    print(f"\nQualidade das regras no conjunto de {conjunto}:")
    for numero, (folha, grupo) in enumerate(tabela.groupby("folha"), start=1):
        cobertura = len(grupo)
        acertos = int((grupo["real"] == grupo["previsto"]).sum())
        qualidade = acertos / cobertura
        classe = "Sobreviveu" if int(grupo["previsto"].iloc[0]) == 1 else "Morreu"
        print(
            f"Regra {numero} (folha {folha}, classe {classe}): "
            f"cobertura = {cobertura}, acertos = {acertos}, "
            f"qualidade = {qualidade:.2%}"
        )


imprimir_qualidade_das_regras(arvore, X_treino, y_treino, "treino")
imprimir_qualidade_das_regras(arvore, X_teste, y_teste, "teste")


# 10. Visualizacao da arvore
plt.figure(figsize=(28, 14))
plot_tree(
    arvore,
    feature_names=X.columns,
    class_names=["Morreu", "Sobreviveu"],
    filled=True,
    rounded=True,
    fontsize=8,
)
plt.title("Arvore de decisao - Titanic")
plt.tight_layout()
plt.savefig(
    PASTA_ATUAL / "09_arvore_titanic_codigo.png",
    dpi=200,
    bbox_inches="tight",
)
plt.show()
