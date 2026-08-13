# Unidade 9 - Processamento e Otimizacao de Consultas

## 1. Visao geral

Escrever a consulta e apenas o primeiro passo. O SGBD ainda precisa decidir como executa-la.

Aqui entram:

- traducao da consulta;
- plano de execucao;
- algoritmos fisicos;
- otimizacao heuristica e por custo.

## 2. Processamento de consulta

Etapas gerais:

1. leitura da consulta SQL;
2. traducao para forma interna;
3. geracao de planos;
4. escolha do plano;
5. execucao.

## 3. Arvore de consulta

Uma consulta pode ser representada como uma arvore de operacoes.

### Exemplo

```sql
SELECT A.nome
FROM Aluno A
JOIN Matricula M ON A.matricula = M.matricula
WHERE M.semestre = 1;
```

Leitura logica:

1. selecionar em `Matricula` apenas `semestre = 1`;
2. juntar com `Aluno`;
3. projetar `nome`.

## 4. Arvore inicial nao otimizada

Para a consulta da video-locadora:

```sql
SELECT A.Nome, D.Nome
FROM Clientes A, Aluguel B, Midias C, Filmes D
WHERE A.CPF = B.CPF_Cliente
  AND C.Tipo = 'BD'
  AND D.Genero = 'Drama'
  AND B.ID_Midia = C.Identificador
  AND A.Sexo = 'M'
  AND B.ValorPagar < 20
  AND C.CodFilme = D.Codigo
```

A arvore inicial fica:

```text
π A.Nome, D.Nome
  |
σ A.CPF = B.CPF_Cliente
  AND C.Tipo = 'BD'
  AND D.Genero = 'Drama'
  AND B.ID_Midia = C.Identificador
  AND A.Sexo = 'M'
  AND B.ValorPagar < 20
  AND C.CodFilme = D.Codigo
  |
  ×
 / \
A   ×
   / \
  B   ×
     / \
    C   D
```

Aqui o `FROM` vira produto cartesiano, o `WHERE` vira uma selecao grande e o `SELECT` vira a projecao no topo.

## 5. Arvore otimizada

Aplicando heuristica, empurramos selecoes e projecoes para baixo e trocamos produto + selecao por juncoes:

```text
π A.Nome, D.Nome
  |
⨝ C.CodFilme = D.Codigo
 /                     \
⨝ B.ID_Midia = C.Identificador   π Codigo, Nome (σ Genero='Drama' (D))
/                    \
⨝ A.CPF = B.CPF_Cliente   π Identificador, CodFilme (σ Tipo='BD' (C))
/                \
π CPF, Nome (σ Sexo='M' (A))   π CPF_Cliente, ID_Midia (σ ValorPagar<20 (B))
```

Essa arvore reduz o tamanho das relacoes antes das juncoes, que e exatamente a ideia da otimizacao heuristica.

## 6. Heuristica importante

Empurrar selecoes para baixo.

Ou seja, filtrar cedo para reduzir resultados intermediarios.

## 7. Conta de seletividade

Se `Matricula` tem `10000` linhas e apenas `2000` sao do semestre 1:

```text
seletividade = 2000 / 10000 = 0,2 = 20%
```

Isso significa que a selecao reduz a relacao para 20% do tamanho original.

## 8. Conta de custo simplificada

Se:

- `Aluno` ocupa `100 blocos`;
- `Matricula` ocupa `500 blocos`.

### Estrategia ruim

Ler tudo e so depois filtrar:

```text
100 + 500 = 600 blocos
```

### Estrategia melhor

Se o filtro reduz `Matricula` para `50 blocos` antes da juncao:

```text
100 + 50 = 150 blocos
```

Ja houve grande reducao.

## 9. Conta com varias selecoes

Se:

- `Clientes` tem 5000 linhas e `Sexo='M'` retorna 40%;
- `Aluguel` tem 20000 linhas e `ValorPagar < 20` retorna 10%;
- `Midias` tem 8000 linhas e `Tipo='BD'` retorna 25%;
- `Filmes` tem 3000 linhas e `Genero='Drama'` retorna 20%;

entao os tamanhos filtrados ficam:

```text
Clientes: 5000 x 0,40 = 2000
Aluguel: 20000 x 0,10 = 2000
Midias: 8000 x 0,25 = 2000
Filmes: 3000 x 0,20 = 600
```

Isso mostra por que filtrar cedo ajuda tanto: as juncoes passam a trabalhar com relacoes menores.

## 10. Algoritmos fisicos

### Ordenacao externa

Usada quando os dados nao cabem em memoria.

### Selecao

Pode usar:

- varredura linear;
- indice;
- hashing;
- busca binaria, se houver ordenacao adequada.

### Projecao

Pode exigir eliminacao de duplicatas.

### Agregacao

Pode usar ordenacao ou hashing.

### Juncao

Algoritmos classicos:

- nested loop;
- sort-merge;
- hash join.

## 11. Exemplo de escolha de juncao

Se uma tabela e pequena e outra e grande, nested loop com a menor como externa pode ser razoavel.

Se ambas sao grandes e ja estao ordenadas, sort-merge pode ser interessante.

Se ha memoria e boa distribuicao, hash join pode ser muito eficiente.

## 12. Otimizacao baseada em custo

O otimizador compara planos usando estimativas como:

- quantidade de blocos lidos;
- cardinalidade dos resultados intermediarios;
- uso de memoria;
- seletividade.

## 13. Otimizacao semantica

Usa informacoes do esquema e restricoes para simplificar consultas.

Exemplo conceitual:

se um atributo e chave, o sistema sabe que nao havera duplicatas naquele campo.

## 14. O que revisar para prova

- plano de consulta;
- arvore de consulta;
- seletividade;
- nested loop, sort-merge e hash join;
- heuristica x custo.

## 15. Resumo final

Nesta unidade fica claro que consultas equivalentes podem ter desempenhos muito diferentes. O que decide isso nao e apenas o SQL escrito, mas o plano escolhido pelo SGBD.
