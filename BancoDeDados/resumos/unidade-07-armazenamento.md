# Unidade 7 - Armazenamento e Organizacao de Dados

## 1. Visao geral

Esta unidade trata do armazenamento fisico dos dados e do custo de acesso.

Pontos centrais:

- hierarquia de memoria;
- disco e I/O;
- blocos;
- arquivos de registros;
- heap, sequencial e hash.

## 2. Hierarquia de memoria

Em geral:

- memorias mais rapidas sao menores e mais caras;
- memorias mais lentas sao maiores e mais baratas.

No banco de dados, a diferenca mais importante costuma ser entre:

- memoria principal;
- disco.

## 3. Disco e I/O

Ler dados do disco e muito mais caro que ler da memoria.

Por isso, muitas analises de custo em BD se baseiam em:

```text
quantidade de leituras e escritas de bloco
```

## 4. Blocos e paginas

Os dados sao transferidos em blocos/paginas, nao registro por registro.

## 5. Conta de fator de bloco

Se:

- tamanho do bloco = `B`;
- tamanho do registro = `R`;

entao:

```text
fator de bloco = floor(B / R)
```

### Exemplo

Se:

- `B = 4096 bytes`;
- `R = 200 bytes`;

entao:

```text
floor(4096 / 200) = floor(20,48) = 20 registros por bloco
```

## 6. Conta de quantidade de blocos

Se a tabela tem `1000 registros` e cabem `20 registros por bloco`:

```text
blocos = ceil(1000 / 20) = 50 blocos
```

## 7. Conta de bytes realmente usados

Se temos 50 blocos com 20 registros por bloco e cada registro ocupa 200 bytes:

```text
50 x 20 x 200 = 200000 bytes
```

Se cada bloco tem 4096 bytes:

```text
50 x 4096 = 204800 bytes reservados
```

Espaco livre interno:

```text
204800 - 200000 = 4800 bytes
```

## 8. Conta de varredura completa

Se a tabela ocupa `50 blocos`, entao uma leitura completa custa aproximadamente:

```text
50 leituras de bloco
```

Se o sistema varrer a tabela 3 vezes:

```text
3 x 50 = 150 leituras
```

## 9. Conta de busca sequencial media

Em uma busca sequencial em 50 blocos:

- pior caso: 50 leituras;
- melhor caso: 1 leitura;
- caso medio aproximado: 25 leituras.

## 10. Arquivos de registros

Um arquivo armazena varios registros de uma relacao.

Aspectos importantes:

- tamanho fixo ou variavel;
- ordem dos registros;
- modo de acesso.

## 11. Heap

Registros sem ordenacao especifica.

### Vantagens

- insercao simples;
- estrutura direta.

### Desvantagens

- busca pode custar caro sem indice.

## 12. Sequencial

Registros armazenados em ordem de um campo.

### Vantagens

- bom para leitura ordenada;
- bom para busca por faixa.

### Desvantagens

- insercoes no meio podem custar mais.

## 13. Hash

Usa funcao hash para localizar registros.

### Vantagem

- muito bom para igualdade.

### Desvantagens

- ruim para intervalos;
- pode haver colisao.

### Exemplo de conta

Se:

```text
h(chave) = chave mod 10
```

Para a chave `123`:

```text
123 mod 10 = 3
```

Para a chave `153`:

```text
153 mod 10 = 3
```

Houve colisao.

## 14. Conta simples com hash

Se 1000 chaves forem distribuidas por 10 compartimentos:

```text
1000 / 10 = 100 chaves por compartimento, em media
```

Se a distribuicao for ruim, alguns compartimentos ficam muito cheios e o desempenho piora.

## 15. Comparacao pratica

### Heap

Melhor quando ha muitas insercoes simples.

### Sequencial

Melhor para leituras ordenadas e consultas por intervalo.

### Hash

Melhor para busca por igualdade.

## 16. O que revisar para prova

- fator de bloco;
- numero de blocos;
- custo de varredura;
- diferenca entre heap, sequencial e hash.

## 17. Resumo final

Aqui aparece uma virada importante da disciplina: o desempenho passa a depender diretamente de como os dados ocupam memoria e disco, e nao apenas da modelagem logica.
