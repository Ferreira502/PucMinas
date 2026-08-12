# Unidade 8 - Indexacao e Metodos de Acesso

## 1. Visao geral

Indices aceleram buscas ao criar estruturas auxiliares de acesso.

O ponto central e entender:

- por que o indice ajuda;
- quando ele ajuda;
- qual o custo de mantelo.

## 2. Conceito

Indice funciona como o indice de um livro:

- em vez de procurar em todas as paginas;
- procura-se primeiro em uma estrutura menor que aponta para o local certo.

## 3. Exemplo intuitivo

Tabela `Aluno` com 10000 linhas.

Consulta:

```sql
SELECT nome
FROM Aluno
WHERE matricula = 2026001;
```

### Sem indice

Pode exigir varredura grande da tabela.

### Com indice em `matricula`

O banco localiza primeiro a entrada no indice e depois vai ao bloco certo.

## 4. Tipos de indice de nivel unico

### Primario

Associado ao campo de ordenacao principal do arquivo.

### De agrupamento

Usado quando o arquivo esta organizado por um atributo que nao e necessariamente chave.

### Secundario

Criado sobre atributos que nao definem a ordenacao fisica principal.

## 5. Conta simples de custo

Se:

- arquivo de dados = `1000 blocos`;
- indice = `50 blocos`;

uma busca sem indice pode custar ate:

```text
1000 leituras de bloco
```

Uma busca com indice pode custar algo na ordem de:

```text
leituras do indice + leitura do bloco de dados
```

Mesmo sem detalhar a estrutura interna, a ideia principal e que o custo tende a ser muito menor que uma varredura completa.

## 6. Indexacao multinivel

Quando o indice cresce, podemos indexar o proprio indice.

Isso reduz o numero de blocos examinados por busca.

## 7. Conta de indice multinivel

Se:

- o indice tem `1000 entradas`;
- cada bloco de indice comporta `100 entradas`;

entao o primeiro nivel ocupa:

```text
ceil(1000 / 100) = 10 blocos
```

O nivel acima para indexar esses 10 blocos ocupa:

```text
ceil(10 / 100) = 1 bloco
```

Busca aproximada:

- 1 bloco do nivel superior;
- 1 bloco do nivel inferior;
- 1 bloco de dados.

Total:

```text
3 acessos de bloco
```

## 8. Quando o indice ajuda

- consultas seletivas;
- campos usados em `WHERE`;
- juncoes frequentes;
- ordenacao e agrupamento.

## 9. Quando pode nao compensar

- tabela pequena;
- atributo com pouca seletividade;
- coluna que muda demais;
- sistema com muitas escritas e poucas leituras.

## 10. Exemplo de baixa seletividade

Campo `ativo` com valores `S` ou `N`.

Se quase todos os registros tem `ativo = 'S'`, um indice nesse campo pode nao ajudar muito, porque a consulta ainda vai retornar grande parte da tabela.

## 11. O que revisar para prova

- conceito de indice;
- primario, agrupamento e secundario;
- indice multinivel;
- custo x beneficio;
- seletividade.

## 12. Resumo final

Indice e uma das principais ferramentas de desempenho em banco de dados. O segredo nao e "criar muitos indices", e sim criar os indices certos para as consultas certas.
