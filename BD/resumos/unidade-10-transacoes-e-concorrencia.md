# Unidade 10 - Projeto Fisico, Transacoes e Concorrencia

## 1. Visao geral

Esta unidade fecha a disciplina com temas de confiabilidade e desempenho:

- projeto fisico;
- ajuste e sintonia;
- transacoes;
- escalonamento;
- controle de concorrencia.

## 2. Projeto fisico

Define como o banco sera implementado para suportar o uso real.

Leva em conta:

- organizacao de arquivos;
- indices;
- volume de dados;
- consultas frequentes;
- custo de atualizacoes.

## 3. Sintonia

### Sintonia de indice

Escolher quais indices criar.

### Sintonia de projeto

Revisar a estrutura do banco para melhorar desempenho.

### Sintonia de consulta

Reescrever consultas e reduzir resultados intermediarios.

## 4. Transacao

Transacao e uma unidade logica de trabalho que deve ser tratada como um todo.

Exemplo:

- transferencia bancaria;
- matricula em disciplina;
- compra em loja online.

## 5. Exemplo de transferencia

Transferencia de R$ 100 de A para B:

1. ler saldo de A;
2. debitar 100 de A;
3. ler saldo de B;
4. creditar 100 em B;
5. confirmar.

## 6. ACID

### Atomicidade

Ou tudo acontece, ou nada acontece.

### Consistencia

O banco sai de um estado valido para outro estado valido.

### Isolamento

Transacoes nao devem interferir incorretamente umas nas outras.

### Durabilidade

Depois do `commit`, a mudanca deve permanecer.

## 7. Conta simples de consistencia

Antes da transferencia:

- conta A = 500;
- conta B = 300.

Total:

```text
500 + 300 = 800
```

Depois de transferir 100:

- conta A = 400;
- conta B = 400.

Total:

```text
400 + 400 = 800
```

O total foi preservado.

## 8. Commit e rollback

```sql
BEGIN;
UPDATE Conta SET saldo = saldo - 100 WHERE id = 1;
UPDATE Conta SET saldo = saldo + 100 WHERE id = 2;
COMMIT;
```

Se algo falhar:

```sql
ROLLBACK;
```

## 9. Exemplo completo de transacao

```sql
BEGIN;

UPDATE Conta
SET saldo = saldo - 100
WHERE id = 1;

UPDATE Conta
SET saldo = saldo + 100
WHERE id = 2;

COMMIT;
```

Se a segunda atualizacao falhar, o correto e:

```sql
ROLLBACK;
```

Assim o debito da conta 1 nao fica gravado sozinho.

## 10. Concorrencia

Varias transacoes podem rodar ao mesmo tempo.

Isso melhora o uso do sistema, mas cria riscos:

- leitura suja;
- leitura nao repetivel;
- perda de atualizacao.

## 11. Exemplo de perda de atualizacao

Saldo inicial = 1000.

### T1

- le 1000;
- soma 100;
- quer gravar 1100.

### T2

- le 1000;
- subtrai 200;
- quer gravar 800.

Se T1 grava 1100 e depois T2 grava 800, a atualizacao de T1 se perde.

## 12. Exemplo de leitura suja

T1:

1. altera saldo de 500 para 900;
2. ainda nao faz `commit`.

T2:

1. le o saldo 900.

Se T1 der `rollback`, T2 leu um valor que nunca deveria ter existido de forma definitiva. Isso e leitura suja.

## 13. Escalonamento

Escalonamento e a ordem em que operacoes de transacoes diferentes se intercalam.

Objetivo:

- permitir paralelismo;
- manter corretude.

## 14. Exemplo de escalonamento

### Serial

```text
T1: R(A) W(A) R(B) W(B)
T2: R(C) W(C)
```

### Intercalado

```text
T1: R(A)
T2: R(C)
T1: W(A)
T2: W(C)
T1: R(B)
T1: W(B)
```

Nem todo intercalamento e errado. O problema e quando ele viola isolamento e consistencia.

## 15. Exemplo de serializabilidade intuitiva

Se o resultado final de um escalonamento intercalado for o mesmo que executar:

1. primeiro T1 inteira;
2. depois T2 inteira;

entao esse escalonamento pode ser considerado serializavel.

## 16. Bloqueio

Uma transacao pode bloquear um item antes de acessa-lo.

Ideias:

- bloqueio compartilhado para leitura;
- bloqueio exclusivo para escrita.

## 17. Exemplo de bloqueio

Se T1 quer escrever em `X`, ela precisa de bloqueio exclusivo.

Enquanto isso, outra transacao nao deve escrever no mesmo item, e muitas vezes tambem nao deve le-lo, dependendo do nivel de isolamento.

## 18. Tabela rapida de compatibilidade

### Bloqueio compartilhado (S)

- com S: compativel;
- com X: incompativel.

### Bloqueio exclusivo (X)

- com S: incompativel;
- com X: incompativel.

## 19. Deadlock

### Exemplo

- T1 bloqueia `A` e pede `B`;
- T2 bloqueia `B` e pede `A`.

As duas ficam esperando.

## 20. Timestamp

Outra estrategia e ordenar transacoes por marcas de tempo.

Se:

- `TS(T1) = 5`;
- `TS(T2) = 8`;

entao T1 e mais antiga. O protocolo tenta manter acessos coerentes com essa ordem.

## 21. O que revisar para prova

- conceito de transacao;
- propriedades ACID;
- `commit` e `rollback`;
- concorrencia;
- perda de atualizacao;
- bloqueio, deadlock e timestamp.

## 22. Resumo final

Esta unidade mostra que banco de dados nao e apenas guardar e consultar. Ele precisa continuar correto, rapido e confiavel mesmo com muitos acessos simultaneos e possibilidade de falhas.
