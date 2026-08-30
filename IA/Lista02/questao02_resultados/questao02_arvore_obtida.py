import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
import plotly.express as px
from pathlib import Path
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, plot_tree, export_text
from sklearn.metrics import accuracy_score


PASTA_ATUAL = Path(__file__).resolve().parent
PASTA_LISTA02 = PASTA_ATUAL.parent


# Leitura da base
base = pd.read_csv(PASTA_LISTA02 / "restaurante.csv", sep=";")


# Verificacao da coluna de classificacao
Classificacao = base.columns[-1]
print(np.unique(base[Classificacao], return_counts=True))
sns.countplot(x=base[Classificacao])
plt.show()


# A ultima coluna e o target
X = base.iloc[:, :-1]
y = base.iloc[:, -1]


# 3.1 Colunas binarias Sim/Nao: identificacao e codificacao automaticas
mapa_binario = {"Nao": 0, "Sim": 1}

colunas_binarias = [
    coluna for coluna in X.columns
    if set(X[coluna].dropna().unique()).issubset(mapa_binario.keys())
]

X[colunas_binarias] = X[colunas_binarias].apply(
    lambda coluna: coluna.map(mapa_binario)
)


# 3.2 Cliente: ordem definida explicitamente
# A base original usa "Alguns"; "Algum" tambem e aceito.
mapa_cliente = {
    "Nenhum": 0,
    "Algum": 1,
    "Alguns": 1,
    "Cheio": 2,
}
X["Cliente"] = X["Cliente"].map(mapa_cliente)


# 3.3 Variaveis ordinais
X["Preco"] = X["Preco"].map({
    "R": 0,
    "RR": 1,
    "RRR": 2,
})

X["Tempo"] = X["Tempo"].map({
    "0-10": 0,
    "10-30": 1,
    "30-60": 2,
    ">60": 3,
})


# 3.4 Variavel nominal Tipo: One-Hot Encoding
X = pd.get_dummies(X, columns=["Tipo"], dtype=int)


# Divisao treino/teste
X_treino, X_teste, y_treino, y_teste = train_test_split(
    X,
    y,
    test_size=0.20,
    random_state=42,
    stratify=y,
)

print("Treino:", X_treino.shape)
print("Teste:", X_teste.shape)


# Treinamento da arvore
arvore = DecisionTreeClassifier(
    criterion="entropy",
    random_state=42,
)

arvore.fit(X_treino, y_treino)

previsoes = arvore.predict(X_teste)
acuracia = accuracy_score(y_teste, previsoes)

print(f"Acuracia: {acuracia:.2%}")
print()
print(export_text(arvore, feature_names=list(X.columns)))


# Geracao da imagem da arvore obtida
plt.figure(figsize=(20, 10))

plot_tree(
    arvore,
    feature_names=X.columns,
    class_names=[str(classe) for classe in arvore.classes_],
    filled=True,
    rounded=True,
    fontsize=10,
)

plt.title("Arvore de Decisao")
plt.savefig(PASTA_ATUAL / "01_arvore_original_notebook.png", dpi=200, bbox_inches="tight")
plt.show()
