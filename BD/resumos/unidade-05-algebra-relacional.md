# Unidade 5 - Algebra Relacional

## 1. Visao geral

A algebra relacional e a base formal do modelo relacional. Ela mostra como consultas podem ser construidas como operacoes sobre relacoes.

Isso ajuda a entender:

- a logica por tras do SQL;
- a ideia de composicao de consultas;
- o processamento interno do SGBD.

## 2. SELECAO

Selecao filtra linhas de uma relacao.

```text
sigma condicao (R)
```

### Exemplo

Relacao `ALUNO`:

| matricula | nome  | curso      |
|-----------|-------|------------|
| 1         | Ana   | Sistemas   |
| 2         | Beto  | Computacao |
| 3         | Caio  | Sistemas   |

Consulta:

```text
sigma curso='Sistemas' (ALUNO)
```

Resultado:

| matricula | nome | curso    |
|-----------|------|----------|
| 1         | Ana  | Sistemas |
| 3         | Caio | Sistemas |

## 3. PROJECAO

Projecao escolhe colunas.

```text
pi atributos (R)
```

### Exemplo

```text
pi nome (ALUNO)
```

Resultado:

| nome |
|------|
| Ana  |
| Beto |
| Caio |

Na algebra relacional teorica, duplicatas sao eliminadas.

## 4. RENOMEACAO

Serve para renomear relacoes ou atributos temporariamente.

E muito util em autojuncoes.

Exemplo conceitual:

```text
rho A(ALUNO)
```

## 5. PRODUTO CARTESIANO

Combina cada tupla de `R` com cada tupla de `S`.

```text
R x S
```

### Conta

Se:

- `|R| = 100`;
- `|S| = 20`;

entao:

```text
|R x S| = 100 x 20 = 2000 tuplas
```

Por isso, produto cartesiano puro costuma ser caro.

## 6. JUNCAO

Juncao combina tuplas relacionadas.

### Exemplo

`ALUNO(matricula, nome, cod_curso)`

`CURSO(cod_curso, nome_curso)`

```text
ALUNO |x| ALUNO.cod_curso = CURSO.cod_curso CURSO
```

Resultado:

| matricula | nome | cod_curso | nome_curso |
|-----------|------|-----------|------------|
| 1         | Ana  | SI        | Sistemas   |
| 2         | Beto | CC        | Computacao |

## 7. AGREGACAO

Resume dados com operacoes como:

- contagem;
- soma;
- media;
- maximo;
- minimo.

### Exemplo conceitual

Contar quantos alunos ha por curso.

## 8. Operacoes de conjunto

### Uniao

Combina tuplas de relacoes compativeis.

### Intersecao

Retorna tuplas em comum.

### Diferenca

Retorna tuplas que estao em uma relacao e nao em outra.

### Exemplo de uniao

`ALUNOS_BD(nome)`:

- Ana
- Bruno

`ALUNOS_IA(nome)`:

- Bruno
- Carla

Resultado da uniao:

- Ana
- Bruno
- Carla

## 9. DIVISAO

Divisao e muito usada em consultas do tipo "todos".

### Exemplo

Queremos os alunos que cursaram todas as disciplinas obrigatorias.

Se `OBRIGATORIA` tem:

- BD
- ED

E `CURSA` tem:

- Ana, BD
- Ana, ED
- Bruno, BD

Entao o resultado da divisao sera:

- Ana

## 10. Sequencia de operacoes

As operacoes podem ser compostas.

Exemplo:

1. selecionar matriculas do semestre 1;
2. juntar com alunos;
3. projetar apenas nome.

Em notacao:

```text
pi nome (ALUNO |x| sigma semestre=1 (MATRICULA))
```

## 11. Ligacao com SQL

- selecao -> `WHERE`;
- projecao -> colunas do `SELECT`;
- juncao -> `JOIN`;
- uniao -> `UNION`;
- agregacao -> `COUNT`, `SUM`, `AVG`.

## 12. Contas comuns

### Seletividade

Se uma relacao tem 1000 linhas e uma selecao mantem 10%:

```text
0,10 x 1000 = 100 linhas
```

### Projecao

O numero de linhas projetadas sera menor ou igual ao original, pois duplicatas podem desaparecer.

## 13. O que revisar para prova

- selecao x projecao;
- juncao x produto cartesiano;
- uniao, intersecao, diferenca;
- divisao;
- composicao de operacoes.

## 14. Resumo final

A algebra relacional mostra a logica das consultas. Quem entende bem essas operacoes geralmente encontra muito menos dificuldade em SQL e em otimizacao de consultas.
