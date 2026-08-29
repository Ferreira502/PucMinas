Questão 01
==========

Base: `restaurante.csv`

Classe alvo: `Conclusao`, com os valores:

- `Sim`: 6 instâncias
- `Nao`: 6 instâncias
- Total: 12 instâncias

## Fórmulas usadas, conforme o slide

A entropia de um conjunto `S` é:

```text
Entropia(S) = - soma(p_i * log2(p_i))
```

Onde:

- `S` é o conjunto de dados.
- `p_i` é a proporção de elementos de `S` pertencentes à classe `i`.
- `log2` é o logaritmo na base 2.

O ganho de informação, conforme o slide, é:

```text
ganho(atributo) = Entropia(classe) - Entropia(atributo)
```

Neste exercício:

```text
Entropia(classe) = Entropia(Conclusao)
Entropia(atributo) = soma((quantidade do valor / total) * Entropia(subconjunto do valor))
```

Como a base possui 6 exemplos `Sim` e 6 exemplos `Nao`:

```text
Entropia(classe) = - (6/12)log2(6/12) - (6/12)log2(6/12)
Entropia(classe) = - 0,5log2(0,5) - 0,5log2(0,5)
Entropia(classe) = 1,0000
```

## 1) Ganho de informação de cada atributo

### Atributo `Alternativo`

```text
Alternativo = Nao: 6 casos -> 3 Sim, 3 Nao
H = 1,0000

Alternativo = Sim: 6 casos -> 3 Sim, 3 Nao
H = 1,0000

Entropia(Alternativo) = (6/12)*1,0000 + (6/12)*1,0000
Entropia(Alternativo) = 1,0000

ganho(Alternativo) = Entropia(classe) - Entropia(Alternativo)
ganho(Alternativo) = 1,0000 - 1,0000 = 0,0000
```

### Atributo `Bar`

```text
Bar = Nao: 6 casos -> 3 Sim, 3 Nao
H = 1,0000

Bar = Sim: 6 casos -> 3 Sim, 3 Nao
H = 1,0000

Entropia(Bar) = (6/12)*1,0000 + (6/12)*1,0000
Entropia(Bar) = 1,0000

ganho(Bar) = Entropia(classe) - Entropia(Bar)
ganho(Bar) = 1,0000 - 1,0000 = 0,0000
```

### Atributo `SexSab`

```text
SexSab = Nao: 7 casos -> 4 Sim, 3 Nao
H = - (4/7)log2(4/7) - (3/7)log2(3/7)
H = 0,9852

SexSab = Sim: 5 casos -> 2 Sim, 3 Nao
H = - (2/5)log2(2/5) - (3/5)log2(3/5)
H = 0,9710

Entropia(SexSab) = (7/12)*0,9852 + (5/12)*0,9710
Entropia(SexSab) = 0,9793

ganho(SexSab) = Entropia(classe) - Entropia(SexSab)
ganho(SexSab) = 1,0000 - 0,9793 = 0,0207
```

### Atributo `fome`

```text
fome = Nao: 5 casos -> 1 Sim, 4 Nao
H = - (1/5)log2(1/5) - (4/5)log2(4/5)
H = 0,7219

fome = Sim: 7 casos -> 5 Sim, 2 Nao
H = - (5/7)log2(5/7) - (2/7)log2(2/7)
H = 0,8631

Entropia(fome) = (5/12)*0,7219 + (7/12)*0,8631
Entropia(fome) = 0,8043

ganho(fome) = Entropia(classe) - Entropia(fome)
ganho(fome) = 1,0000 - 0,8043 = 0,1957
```

### Atributo `Cliente`

```text
Cliente = Alguns: 4 casos -> 4 Sim, 0 Nao
H = 0,0000

Cliente = Cheio: 6 casos -> 2 Sim, 4 Nao
H = - (2/6)log2(2/6) - (4/6)log2(4/6)
H = 0,9183

Cliente = Nenhum: 2 casos -> 0 Sim, 2 Nao
H = 0,0000

Entropia(Cliente) = (4/12)*0,0000 + (6/12)*0,9183 + (2/12)*0,0000
Entropia(Cliente) = 0,4591

ganho(Cliente) = Entropia(classe) - Entropia(Cliente)
ganho(Cliente) = 1,0000 - 0,4591 = 0,5409
```

### Atributo `Preco`

```text
Preco = R: 7 casos -> 3 Sim, 4 Nao
H = - (3/7)log2(3/7) - (4/7)log2(4/7)
H = 0,9852

Preco = RR: 2 casos -> 2 Sim, 0 Nao
H = 0,0000

Preco = RRR: 3 casos -> 1 Sim, 2 Nao
H = - (1/3)log2(1/3) - (2/3)log2(2/3)
H = 0,9183

Entropia(Preco) = (7/12)*0,9852 + (2/12)*0,0000 + (3/12)*0,9183
Entropia(Preco) = 0,8043

ganho(Preco) = Entropia(classe) - Entropia(Preco)
ganho(Preco) = 1,0000 - 0,8043 = 0,1957
```

### Atributo `Chuva`

```text
Chuva = Nao: 7 casos -> 3 Sim, 4 Nao
H = 0,9852

Chuva = Sim: 5 casos -> 3 Sim, 2 Nao
H = 0,9710

Entropia(Chuva) = (7/12)*0,9852 + (5/12)*0,9710
Entropia(Chuva) = 0,9793

ganho(Chuva) = Entropia(classe) - Entropia(Chuva)
ganho(Chuva) = 1,0000 - 0,9793 = 0,0207
```

### Atributo `Res`

```text
Res = Nao: 7 casos -> 3 Sim, 4 Nao
H = 0,9852

Res = Sim: 5 casos -> 3 Sim, 2 Nao
H = 0,9710

Entropia(Res) = (7/12)*0,9852 + (5/12)*0,9710
Entropia(Res) = 0,9793

ganho(Res) = Entropia(classe) - Entropia(Res)
ganho(Res) = 1,0000 - 0,9793 = 0,0207
```

### Atributo `Tipo`

```text
Tipo = Frances: 2 casos -> 1 Sim, 1 Nao
H = 1,0000

Tipo = Hamburger: 4 casos -> 2 Sim, 2 Nao
H = 1,0000

Tipo = Italiano: 2 casos -> 1 Sim, 1 Nao
H = 1,0000

Tipo = Tailandes: 4 casos -> 2 Sim, 2 Nao
H = 1,0000

Entropia(Tipo) = (2/12)*1,0000 + (4/12)*1,0000 + (2/12)*1,0000 + (4/12)*1,0000
Entropia(Tipo) = 1,0000

ganho(Tipo) = Entropia(classe) - Entropia(Tipo)
ganho(Tipo) = 1,0000 - 1,0000 = 0,0000
```

### Atributo `Tempo`

```text
Tempo = 0-10: 6 casos -> 4 Sim, 2 Nao
H = - (4/6)log2(4/6) - (2/6)log2(2/6)
H = 0,9183

Tempo = 10-30: 2 casos -> 1 Sim, 1 Nao
H = 1,0000

Tempo = 30-60: 2 casos -> 1 Sim, 1 Nao
H = 1,0000

Tempo = >60: 2 casos -> 0 Sim, 2 Nao
H = 0,0000

Entropia(Tempo) = (6/12)*0,9183 + (2/12)*1,0000 + (2/12)*1,0000 + (2/12)*0,0000
Entropia(Tempo) = 0,7925

ganho(Tempo) = Entropia(classe) - Entropia(Tempo)
ganho(Tempo) = 1,0000 - 0,7925 = 0,2075
```

### Resumo dos ganhos

| Atributo | Ganho de informação |
|---|---:|
| Cliente | 0,5409 |
| Tempo | 0,2075 |
| fome | 0,1957 |
| Preco | 0,1957 |
| SexSab | 0,0207 |
| Chuva | 0,0207 |
| Res | 0,0207 |
| Alternativo | 0,0000 |
| Bar | 0,0000 |
| Tipo | 0,0000 |

O atributo com maior ganho de informação é `Cliente`.

Portanto, a raiz da árvore é:

```text
Cliente
```

## 2) Atributo no segundo nível da árvore

Depois de escolher `Cliente` como raiz, os ramos ficam assim:

```text
Cliente = Alguns: 4 casos -> 4 Sim, 0 Nao -> folha Sim
Cliente = Nenhum: 2 casos -> 0 Sim, 2 Nao -> folha Nao
Cliente = Cheio: 6 casos -> 2 Sim, 4 Nao -> ainda precisa dividir
```

Logo, é necessário calcular o melhor atributo apenas para o subconjunto:

```text
Cliente = Cheio
```

Nesse subconjunto:

```text
Total = 6 casos
Sim = 2
Nao = 4

Entropia(classe no ramo Cliente=Cheio) = - (2/6)log2(2/6) - (4/6)log2(4/6)
Entropia(classe no ramo Cliente=Cheio) = 0,9183
```

### Ganhos dentro do ramo `Cliente = Cheio`

#### Atributo `Alternativo`

```text
Alternativo = Nao: 1 caso -> 0 Sim, 1 Nao
H = 0,0000

Alternativo = Sim: 5 casos -> 2 Sim, 3 Nao
H = - (2/5)log2(2/5) - (3/5)log2(3/5)
H = 0,9710

Entropia(Alternativo) = (1/6)*0,0000 + (5/6)*0,9710
Entropia(Alternativo) = 0,8091

ganho(Alternativo) = Entropia(classe no ramo Cliente=Cheio) - Entropia(Alternativo)
ganho(Alternativo) = 0,9183 - 0,8091 = 0,1092
```

#### Atributo `Bar`

```text
Bar = Nao: 3 casos -> 1 Sim, 2 Nao
H = 0,9183

Bar = Sim: 3 casos -> 1 Sim, 2 Nao
H = 0,9183

Entropia(Bar) = (3/6)*0,9183 + (3/6)*0,9183
Entropia(Bar) = 0,9183

ganho(Bar) = Entropia(classe no ramo Cliente=Cheio) - Entropia(Bar)
ganho(Bar) = 0,9183 - 0,9183 = 0,0000
```

#### Atributo `SexSab`

```text
SexSab = Nao: 1 caso -> 0 Sim, 1 Nao
H = 0,0000

SexSab = Sim: 5 casos -> 2 Sim, 3 Nao
H = 0,9710

Entropia(SexSab) = (1/6)*0,0000 + (5/6)*0,9710
Entropia(SexSab) = 0,8091

ganho(SexSab) = Entropia(classe no ramo Cliente=Cheio) - Entropia(SexSab)
ganho(SexSab) = 0,9183 - 0,8091 = 0,1092
```

#### Atributo `fome`

```text
fome = Nao: 2 casos -> 0 Sim, 2 Nao
H = 0,0000

fome = Sim: 4 casos -> 2 Sim, 2 Nao
H = 1,0000

Entropia(fome) = (2/6)*0,0000 + (4/6)*1,0000
Entropia(fome) = 0,6667

ganho(fome) = Entropia(classe no ramo Cliente=Cheio) - Entropia(fome)
ganho(fome) = 0,9183 - 0,6667 = 0,2516
```

#### Atributo `Preco`

```text
Preco = R: 4 casos -> 2 Sim, 2 Nao
H = 1,0000

Preco = RRR: 2 casos -> 0 Sim, 2 Nao
H = 0,0000

Entropia(Preco) = (4/6)*1,0000 + (2/6)*0,0000
Entropia(Preco) = 0,6667

ganho(Preco) = Entropia(classe no ramo Cliente=Cheio) - Entropia(Preco)
ganho(Preco) = 0,9183 - 0,6667 = 0,2516
```

#### Atributo `Chuva`

```text
Chuva = Nao: 4 casos -> 1 Sim, 3 Nao
H = - (1/4)log2(1/4) - (3/4)log2(3/4)
H = 0,8113

Chuva = Sim: 2 casos -> 1 Sim, 1 Nao
H = 1,0000

Entropia(Chuva) = (4/6)*0,8113 + (2/6)*1,0000
Entropia(Chuva) = 0,8742

ganho(Chuva) = Entropia(classe no ramo Cliente=Cheio) - Entropia(Chuva)
ganho(Chuva) = 0,9183 - 0,8742 = 0,0441
```

#### Atributo `Res`

```text
Res = Nao: 4 casos -> 2 Sim, 2 Nao
H = 1,0000

Res = Sim: 2 casos -> 0 Sim, 2 Nao
H = 0,0000

Entropia(Res) = (4/6)*1,0000 + (2/6)*0,0000
Entropia(Res) = 0,6667

ganho(Res) = Entropia(classe no ramo Cliente=Cheio) - Entropia(Res)
ganho(Res) = 0,9183 - 0,6667 = 0,2516
```

#### Atributo `Tipo`

```text
Tipo = Frances: 1 caso -> 0 Sim, 1 Nao
H = 0,0000

Tipo = Hamburger: 2 casos -> 1 Sim, 1 Nao
H = 1,0000

Tipo = Italiano: 1 caso -> 0 Sim, 1 Nao
H = 0,0000

Tipo = Tailandes: 2 casos -> 1 Sim, 1 Nao
H = 1,0000

Entropia(Tipo) = (1/6)*0,0000 + (2/6)*1,0000 + (1/6)*0,0000 + (2/6)*1,0000
Entropia(Tipo) = 0,6667

ganho(Tipo) = Entropia(classe no ramo Cliente=Cheio) - Entropia(Tipo)
ganho(Tipo) = 0,9183 - 0,6667 = 0,2516
```

#### Atributo `Tempo`

```text
Tempo = 10-30: 2 casos -> 1 Sim, 1 Nao
H = 1,0000

Tempo = 30-60: 2 casos -> 1 Sim, 1 Nao
H = 1,0000

Tempo = >60: 2 casos -> 0 Sim, 2 Nao
H = 0,0000

Entropia(Tempo) = (2/6)*1,0000 + (2/6)*1,0000 + (2/6)*0,0000
Entropia(Tempo) = 0,6667

ganho(Tempo) = Entropia(classe no ramo Cliente=Cheio) - Entropia(Tempo)
ganho(Tempo) = 0,9183 - 0,6667 = 0,2516
```

### Resumo dos ganhos no ramo `Cliente = Cheio`

| Atributo | Ganho de informação |
|---|---:|
| fome | 0,2516 |
| Preco | 0,2516 |
| Res | 0,2516 |
| Tipo | 0,2516 |
| Tempo | 0,2516 |
| Alternativo | 0,1092 |
| SexSab | 0,1092 |
| Chuva | 0,0441 |
| Bar | 0,0000 |

Há empate entre `fome`, `Preco`, `Res`, `Tipo` e `Tempo`, todos com ganho de informação igual a `0,2516`.

Adotando o critério de desempate pela ordem dos atributos na base, o atributo escolhido para o segundo nível é:

```text
fome
```

## Árvore gerada até o segundo nível

```text
Cliente?
|-- Alguns -> Sim
|-- Nenhum -> Nao
`-- Cheio
    `-- fome?
        |-- Nao -> Nao
        `-- Sim -> continua a divisão
```

Assim, até o segundo nível, a árvore possui `Cliente` como raiz e `fome` como atributo escolhido no ramo `Cliente = Cheio`.


Questão 02
==========

Base: `restaurante.csv`

Código usado como referência: `AD-Restaurante - codifica treina e avalia.ipynb`

## Preparação feita pelo código

O código primeiro separa os atributos da classe:

```text
X = atributos de entrada
y = classe Conclusao
```

A classe possui:

```text
Sim: 6 exemplos
Nao: 6 exemplos
```

Depois, os atributos categóricos são codificados assim:

```text
Sim/Nao:
Nao = 0
Sim = 1

Cliente:
Nenhum = 0
Algum/Alguns = 1
Cheio = 2

Preco:
R = 0
RR = 1
RRR = 2

Tempo:
0-10 = 0
10-30 = 1
30-60 = 2
>60 = 3

Tipo:
codificado com One-Hot Encoding
```

A divisão entre treino e teste foi:

```text
Treino: 9 exemplos
Teste: 3 exemplos
test_size = 0,20
random_state = 42
stratify = y
```

Os exemplos usados no teste foram as linhas 7, 8 e 9:

| Linha | Classe real |
|---:|---|
| 7 | Sim |
| 8 | Nao |
| 9 | Nao |

As previsões da árvore foram:

| Linha | Classe real | Classe prevista |
|---:|---|---|
| 7 | Sim | Sim |
| 8 | Nao | Sim |
| 9 | Nao | Sim |

Assim, a acurácia foi:

```text
Acurácia = acertos / total
Acurácia = 1 / 3
Acurácia = 0,3333 = 33,33%
```

## 1) Árvore obtida

A árvore de decisão obtida pelo código foi:

```text
Cliente <= 0,5?
|-- True  -> Nao
`-- False
    |-- Tempo <= 1,5?
    |   |-- True  -> Sim
    |   `-- False
    |       |-- Tipo_Hamburger <= 0,5?
    |       |   |-- True  -> Nao
    |       |   `-- False -> Sim
```

Interpretando os valores codificados:

```text
Cliente <= 0,5 significa Cliente = Nenhum
Cliente > 0,5 significa Cliente = Alguns ou Cheio

Tempo <= 1,5 significa Tempo = 0-10 ou 10-30
Tempo > 1,5 significa Tempo = 30-60 ou >60

Tipo_Hamburger <= 0,5 significa Tipo diferente de Hamburger
Tipo_Hamburger > 0,5 significa Tipo = Hamburger
```

## 2) Recall, precision e F1-Score

Matriz de confusão, considerando as classes na ordem `Nao` e `Sim`:

```text
                Previsto Nao   Previsto Sim
Real Nao             0             2
Real Sim             0             1
```

### Classe `Nao` ou `Não esperar`

```text
VP = 0
FP = 0
FN = 2

precision = VP / (VP + FP)
precision = 0 / (0 + 0) = 0,00

recall = VP / (VP + FN)
recall = 0 / (0 + 2) = 0,00

F1-Score = 2 * (precision * recall) / (precision + recall)
F1-Score = 0,00
```

Como a árvore não previu nenhum exemplo como `Nao`, a precisão da classe `Nao` fica indefinida matematicamente. O `sklearn` registra esse valor como `0,00`.

### Classe `Sim` ou `Esperar`

```text
VP = 1
FP = 2
FN = 0

precision = VP / (VP + FP)
precision = 1 / (1 + 2) = 0,33

recall = VP / (VP + FN)
recall = 1 / (1 + 0) = 1,00

F1-Score = 2 * (0,33 * 1,00) / (0,33 + 1,00)
F1-Score = 0,50
```

Resumo das métricas:

| Classe | Precision | Recall | F1-Score | Support |
|---|---:|---:|---:|---:|
| Nao | 0,00 | 0,00 | 0,00 | 2 |
| Sim | 0,33 | 1,00 | 0,50 | 1 |
| Accuracy |  |  | 0,33 | 3 |
| Macro avg | 0,17 | 0,50 | 0,25 | 3 |
| Weighted avg | 0,11 | 0,33 | 0,17 | 3 |

## 3) Regras obtidas

### Regra 1

```text
Se Cliente <= 0,5
Então Conclusao = Nao
```

Em termos da base original:

```text
Se Cliente = Nenhum
Então não esperar pelo restaurante.
```

### Regra 2

```text
Se Cliente > 0,5
E Tempo <= 1,5
Então Conclusao = Sim
```

Em termos da base original:

```text
Se Cliente = Alguns ou Cheio
E Tempo = 0-10 ou 10-30
Então esperar pelo restaurante.
```

### Regra 3

```text
Se Cliente > 0,5
E Tempo > 1,5
E Tipo_Hamburger <= 0,5
Então Conclusao = Nao
```

Em termos da base original:

```text
Se Cliente = Alguns ou Cheio
E Tempo = 30-60 ou >60
E Tipo diferente de Hamburger
Então não esperar pelo restaurante.
```

### Regra 4

```text
Se Cliente > 0,5
E Tempo > 1,5
E Tipo_Hamburger > 0,5
Então Conclusao = Sim
```

Em termos da base original:

```text
Se Cliente = Alguns ou Cheio
E Tempo = 30-60 ou >60
E Tipo = Hamburger
Então esperar pelo restaurante.
```

## 4) Qualidade de cada regra

Pelos nós folha da árvore, a qualidade no conjunto de treino é de 100% para todas as regras, pois todas as folhas ficaram puras.

| Regra | Classe prevista | Exemplos de treino cobertos | Acertos no treino | Qualidade no treino |
|---|---|---:|---:|---:|
| Regra 1 | Nao | 2 | 2 | 100% |
| Regra 2 | Sim | 4 | 4 | 100% |
| Regra 3 | Nao | 2 | 2 | 100% |
| Regra 4 | Sim | 1 | 1 | 100% |

No conjunto de teste, a qualidade ficou:

| Regra | Exemplos de teste cobertos | Acertos no teste | Qualidade no teste |
|---|---:|---:|---:|
| Regra 1 | 0 | 0 | não se aplica |
| Regra 2 | 2 | 1 | 50% |
| Regra 3 | 0 | 0 | não se aplica |
| Regra 4 | 1 | 0 | 0% |

Portanto, apesar de a árvore ter qualidade perfeita no conjunto de treino, ela teve desempenho baixo no conjunto de teste, acertando apenas 1 dos 3 exemplos.


Questão 03
==========

Base: `titanic completo.csv`

Objetivo: encontrar padrões de sobrevivência e mortalidade no desastre do Titanic usando árvore de decisão.

## 1) Tratamento dos dados ausentes

A base original possui:

```text
1309 registros
14 atributos
```

As colunas originais são:

```text
pclass, survived, name, sex, age, sibsp, parch, ticket, fare, cabin,
embarked, boat, body, home.dest
```

Como ainda não foi estudado tratamento de dados ausentes, a estratégia usada foi:

```text
1. Remover os atributos boat, body, cabin e home.dest.
2. Depois disso, eliminar as instâncias que ainda possuíam algum valor ausente.
```

Os atributos removidos foram:

```text
boat
body
cabin
home.dest
```

Depois de remover esses atributos, sobraram 10 colunas:

```text
pclass, survived, name, sex, age, sibsp, parch, ticket, fare, embarked
```

Valores ausentes restantes depois da remoção desses atributos:

| Atributo | Valores ausentes |
|---|---:|
| pclass | 0 |
| survived | 0 |
| name | 0 |
| sex | 0 |
| age | 263 |
| sibsp | 0 |
| parch | 0 |
| ticket | 0 |
| fare | 1 |
| embarked | 2 |

Em seguida, foram eliminadas as instâncias com ausência em `age`, `fare` ou `embarked`.

Resultado final:

```text
Base original: 1309 instâncias
Após remover boat, body, cabin e home.dest: 1309 instâncias e 10 atributos
Após eliminar instâncias com ausência: 1043 instâncias completas
```

## 2) Visualização inicial da base limpa

A classe alvo é:

```text
survived
0 = morreu
1 = sobreviveu
```

Distribuição da classe na base limpa:

| Classe | Quantidade | Percentual |
|---|---:|---:|
| Morreu (`0`) | 618 | 59,25% |
| Sobreviveu (`1`) | 425 | 40,75% |

Distribuição por sexo:

| Sexo | Morreu | Sobreviveu | Taxa de sobrevivência |
|---|---:|---:|---:|
| female | 96 | 290 | 75,13% |
| male | 522 | 135 | 20,55% |

Distribuição por classe do passageiro:

| Classe | Morreu | Sobreviveu | Taxa de sobrevivência |
|---|---:|---:|---:|
| 1ª classe | 103 | 179 | 63,48% |
| 2ª classe | 146 | 115 | 44,06% |
| 3ª classe | 369 | 131 | 26,20% |

Distribuição por porto de embarque:

| Porto | Morreu | Sobreviveu | Taxa de sobrevivência |
|---|---:|---:|---:|
| C | 80 | 132 | 62,26% |
| Q | 37 | 13 | 26,00% |
| S | 501 | 280 | 35,85% |

Resumo dos atributos numéricos:

| Atributo | Média | Mediana | Mínimo | Máximo |
|---|---:|---:|---:|---:|
| age | 29,81 | 28,00 | 0,17 | 80,00 |
| fare | 36,60 | 15,75 | 0,00 | 512,33 |

## 3) Codificação dos atributos

Para gerar a árvore, foram usados os atributos:

```text
pclass, sex, age, sibsp, parch, fare, embarked
```

Os atributos `name` e `ticket` ficaram fora da árvore, pois são identificadores textuais com muitos valores diferentes e não representam bem categorias gerais para gerar regras simples.

A codificação escolhida foi:

```text
sex:
male = 0
female = 1

embarked:
S = 0
C = 1
Q = 2

pclass:
mantido como ordinal: 1, 2, 3

age:
mantido como numérico

fare:
mantido como numérico

sibsp:
mantido como numérico

parch:
mantido como numérico
```

Foi usada uma árvore de decisão com critério de entropia e ganho de informação. Para deixar as regras interpretáveis na lista, a árvore foi limitada a profundidade 4.

## 4) Árvore de decisão obtida

A raiz da árvore foi o atributo `sex`, indicando que ele foi o atributo mais importante para separar os grupos.

Árvore obtida:

```text
sex <= 0,5?
|-- True: male
|   |-- age <= 9,5?
|   |   |-- True -> Sobreviveu
|   |   `-- False
|   |       |-- pclass <= 1,5?
|   |       |   |-- True
|   |       |   |   |-- age <= 53,5?
|   |       |   |   |   |-- True -> Morreu
|   |       |   |   |   `-- False -> Morreu
|   |       |   `-- False
|   |       |       |-- age <= 32,25?
|   |       |       |   |-- True -> Morreu
|   |       |       |   `-- False -> Morreu
`-- False: female
    |-- pclass <= 2,5?
    |   |-- True
    |   |   |-- fare <= 32,09?
    |   |   |   |-- True
    |   |   |   |   |-- parch <= 0,5?
    |   |   |   |   |   |-- True -> Sobreviveu
    |   |   |   |   |   `-- False -> Sobreviveu
    |   |   |   `-- False
    |   |   |       |-- fare <= 149,04?
    |   |   |       |   |-- True -> Sobreviveu
    |   |   |       |   `-- False -> Sobreviveu
    |   `-- False
    |       |-- fare <= 19,74?
    |       |   |-- True
    |       |   |   |-- age <= 17,5?
    |       |   |   |   |-- True -> Sobreviveu
    |       |   |   |   `-- False -> Morreu
    |       |   `-- False -> Morreu
```

## 5) Regras obtidas

### Regras principais de sobrevivência

| Regra | Condições | Classe | Cobertura | Acertos | Qualidade |
|---:|---|---|---:|---:|---:|
| 1 | `sex = male` e `age <= 9,5` | Sobreviveu | 43 | 25 | 58,14% |
| 6 | `sex = female`, `pclass <= 2,5`, `fare <= 32,09`, `parch <= 0,5` | Sobreviveu | 70 | 59 | 84,29% |
| 7 | `sex = female`, `pclass <= 2,5`, `fare <= 32,09`, `parch > 0,5` | Sobreviveu | 32 | 30 | 93,75% |
| 8 | `sex = female`, `pclass <= 2,5`, `fare > 32,09`, `fare <= 149,04` | Sobreviveu | 99 | 99 | 100,00% |
| 9 | `sex = female`, `pclass <= 2,5`, `fare > 32,09`, `fare > 149,04` | Sobreviveu | 33 | 30 | 90,91% |
| 10 | `sex = female`, `pclass > 2,5`, `fare <= 19,74`, `age <= 17,5` | Sobreviveu | 30 | 22 | 73,33% |

### Regras principais de mortalidade

| Regra | Condições | Classe | Cobertura | Acertos | Qualidade |
|---:|---|---|---:|---:|---:|
| 2 | `sex = male`, `age > 9,5`, `pclass <= 1,5`, `age <= 53,5` | Morreu | 117 | 71 | 60,68% |
| 3 | `sex = male`, `age > 9,5`, `pclass <= 1,5`, `age > 53,5` | Morreu | 31 | 27 | 87,10% |
| 4 | `sex = male`, `age > 9,5`, `pclass > 1,5`, `age <= 32,25` | Morreu | 324 | 272 | 83,95% |
| 5 | `sex = male`, `age > 9,5`, `pclass > 1,5`, `age > 32,25` | Morreu | 142 | 134 | 94,37% |
| 11 | `sex = female`, `pclass > 2,5`, `fare <= 19,74`, `age > 17,5` | Morreu | 90 | 48 | 53,33% |
| 12 | `sex = female`, `pclass > 2,5`, `fare > 19,74` | Morreu | 32 | 24 | 75,00% |

## Conclusão

O padrão mais forte encontrado foi a diferença entre homens e mulheres:

```text
Mulheres sobreviveram mais: 75,13%.
Homens sobreviveram menos: 20,55%.
```

A classe do passageiro também teve grande influência:

```text
1ª classe: 63,48% sobreviveram.
2ª classe: 44,06% sobreviveram.
3ª classe: 26,20% sobreviveram.
```

Assim, os padrões principais foram:

```text
Maior chance de sobrevivência:
mulheres, principalmente da 1ª e 2ª classes.

Maior chance de mortalidade:
homens com mais de 9,5 anos, principalmente da 2ª e 3ª classes.

Exceção importante:
meninos de até 9,5 anos tiveram maior chance de sobrevivência.
```


Questão 04
==========

A árvore da figura usa principalmente os atributos:

```text
petallength = Tamanho da Pétala
petalwidth = Largura da Pétala
```

As regras da árvore são:

```text
1) Se petallength <= 2,35
   Então classe = Iris_Setosa

2) Se petallength > 2,35
   E petalwidth <= 1,75
   E petallength <= 4,95
   Então classe = Iris_Versicolor

3) Se petallength > 2,35
   E petalwidth <= 1,75
   E petallength > 4,95
   Então classe = Iris_Virgínica

4) Se petallength > 2,35
   E petalwidth > 1,75
   E petallength <= 4,85
   Então classe = Iris_Versicolor

5) Se petallength > 2,35
   E petalwidth > 1,75
   E petallength > 4,85
   Então classe = Iris_Virgínica
```

## Classificação das instâncias

### Instância 1

```text
Tamanho da Pétala = 3,46
Largura da Pétala = 0,87

3,46 > 2,35
0,87 <= 1,75
3,46 <= 4,95

Classe = Iris_Versicolor
```

### Instância 2

```text
Tamanho da Pétala = 1,67
Largura da Pétala = 1,89

1,67 <= 2,35

Classe = Iris_Setosa
```

### Instância 3

```text
Tamanho da Pétala = 2,56
Largura da Pétala = 2,34

2,56 > 2,35
2,34 > 1,75
2,56 <= 4,85

Classe = Iris_Versicolor
```

### Instância 4

```text
Tamanho da Pétala = 6,67
Largura da Pétala = 2,34

6,67 > 2,35
2,34 > 1,75
6,67 > 4,85

Classe = Iris_Virgínica
```

## Resposta

As saídas da árvore para as quatro instâncias são, respectivamente:

```text
Iris_Versicolor, Iris_Setosa, Iris_Versicolor, Iris_Virgínica
```

Portanto, a alternativa correta é:

```text
c) Iris_Versicolor, Iris_Setosa, Iris_Versicolor, Iris_Virgínica
```
