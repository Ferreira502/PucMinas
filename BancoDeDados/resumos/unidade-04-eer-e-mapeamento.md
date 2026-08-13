# Unidade 4 - Modelo EER e Mapeamento Relacional

## 1. Visao geral

O EER amplia o ER e depois conecta a modelagem conceitual ao modelo relacional.

Os pontos centrais sao:

- supertipo e subtipo;
- especializacao;
- generalizacao;
- restricoes da hierarquia;
- mapeamento EER -> relacional.

## 2. Supertipo e subtipo

Supertipo guarda caracteristicas comuns.
Subtipo guarda caracteristicas especificas.

### Exemplo

`Pessoa(cpf, nome)` como supertipo.

Subtipos:

- `Aluno(matricula)`;
- `Professor(siape)`.

Todos herdam `cpf` e `nome`.

## 3. Especializacao e generalizacao

### Especializacao

Parte de um tipo geral e cria tipos mais especificos.

Exemplo:

- `Funcionario` -> `Professor` e `Tecnico`.

### Generalizacao

Parte de tipos parecidos e cria um tipo mais geral.

Exemplo:

- `Carro`, `Moto`, `Caminhao` -> `Veiculo`.

## 4. Restricoes da especializacao

### Disjunta

Uma entidade so pode estar em um subtipo.

### Sobreposta

Uma entidade pode estar em mais de um subtipo.

### Total

Toda entidade do supertipo deve pertencer a algum subtipo.

### Parcial

Algumas entidades do supertipo podem nao pertencer a subtipo nenhum.

## 5. Exemplo de interpretacao

Se `Pessoa` pode ser `Aluno` e `Professor` ao mesmo tempo:

- a especializacao e sobreposta.

Se toda `Pessoa` obrigatoriamente precisa ser `Aluno` ou `Professor`:

- a participacao e total.

## 6. Mapeamento para modelo relacional

### Entidade forte

```text
ALUNO(matricula PK, nome, curso)
```

### Relacionamento 1:N

Se `Curso 1:N Aluno`, a chave estrangeira vai para `Aluno`:

```text
CURSO(cod_curso PK, nome)
ALUNO(matricula PK, nome, cod_curso FK)
```

### Relacionamento N:M

Se `Aluno N:M Disciplina`, cria-se uma tabela associativa:

```text
ALUNO(matricula PK, nome)
DISCIPLINA(codigo PK, nome)
MATRICULA(matricula FK, codigo FK, semestre, PRIMARY KEY (matricula, codigo, semestre))
```

## 7. Atributo multivalorado

Se um aluno tem varios telefones:

```text
ALUNO(matricula PK, nome)
ALUNO_TELEFONE(matricula FK, telefone, PRIMARY KEY (matricula, telefone))
```

## 8. Mapeamento de especializacao

### Estrategia 1: supertipo + subtipos

```text
PESSOA(cpf PK, nome)
ALUNO(cpf PK/FK, matricula)
PROFESSOR(cpf PK/FK, siape)
```

Vantagem:

- menos redundancia.

Desvantagem:

- mais juncoes.

### Estrategia 2: tabela unica

```text
PESSOA(cpf PK, nome, tipo, matricula, siape)
```

Vantagem:

- consulta simples.

Desvantagem:

- campos nulos;
- menor normalizacao.

## 9. Conta de quantas tabelas surgem

Se um diagrama tem:

- 3 entidades fortes;
- 1 relacionamento N:M;
- 1 atributo multivalorado;

entao o resultado minimo mais comum sera:

```text
3 tabelas das entidades
+ 1 tabela do relacionamento N:M
+ 1 tabela do atributo multivalorado
= 5 tabelas
```

Nao e regra absoluta, mas funciona bem como previsao inicial.

## 10. Exemplo completo

### Conceitual

- `Aluno`;
- `Disciplina`;
- `Curso`;
- `Aluno` pertence a `Curso`;
- `Aluno` cursa `Disciplina`.

### Relacional

```text
CURSO(cod_curso PK, nome)
ALUNO(matricula PK, nome, cod_curso FK)
DISCIPLINA(codigo PK, nome)
MATRICULA(matricula FK, codigo FK, semestre, PRIMARY KEY (matricula, codigo, semestre))
```

## 11. O que revisar para prova

- supertipo e subtipo;
- especializacao e generalizacao;
- total/parcial;
- disjunta/sobreposta;
- mapeamento 1:N e N:M;
- mapeamento de multivalorado.

## 12. Resumo final

Esta unidade e a ponte entre a modelagem conceitual e as tabelas. O essencial e saber transformar corretamente regras do mundo real em relacoes, chaves e tabelas auxiliares.
