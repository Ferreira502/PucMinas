# Unidade 3 - Modelo Entidade-Relacionamento

## 1. Visao geral

O modelo ER e a principal ferramenta de modelagem conceitual. Ele descreve o dominio antes de pensar em tabela, SQL ou armazenamento.

Os elementos centrais sao:

- entidades;
- atributos;
- relacionamentos;
- restricoes.

## 2. Entidade

Entidade e um objeto ou conceito relevante do mundo real.

Exemplos:

- Aluno;
- Professor;
- Disciplina;
- Departamento.

## 3. Atributos

Atributo e uma propriedade de uma entidade ou relacionamento.

Exemplos:

- `Aluno` -> `matricula`, `nome`, `curso`;
- `Disciplina` -> `codigo`, `nome`, `carga_horaria`.

### Tipos importantes

- simples;
- composto;
- multivalorado;
- derivado;
- chave.

### Exemplo de atributo composto

`endereco` pode ser decomposto em:

- rua;
- numero;
- bairro;
- cidade.

### Exemplo de atributo multivalorado

`telefone` de um aluno pode ter varios valores.

## 4. Atributo-chave

E o atributo que identifica unicamente cada entidade.

Exemplo:

- `matricula` identifica um aluno;
- `codigo` identifica uma disciplina.

## 5. Relacionamentos

Relacionamento conecta entidades.

Exemplos:

- `Aluno` cursa `Disciplina`;
- `Professor` ministra `Disciplina`;
- `Professor` pertence a `Departamento`.

## 6. Grau do relacionamento

- binario: duas entidades;
- ternario: tres entidades;
- n-ario: varias entidades.

Na pratica, os binarios sao os mais comuns.

## 7. Cardinalidade

Define quantas ocorrencias de uma entidade podem se associar com outra.

Casos principais:

- 1:1;
- 1:N;
- N:1;
- N:M.

### Exemplo

Se um curso possui varios alunos e cada aluno pertence a um curso:

```text
Curso 1:N Aluno
```

## 8. Participacao

### Total

Toda entidade deve participar do relacionamento.

Exemplo:

todo aluno deve estar ligado a algum curso.

### Parcial

A participacao e opcional.

Exemplo:

nem todo professor precisa coordenar um curso.

## 9. Exemplo completo de modelagem

### Enunciado

"Cada aluno pode se matricular em varias disciplinas. Cada disciplina pode ter varios alunos. Todo aluno pertence a exatamente um curso."

### Entidades

- `Aluno`;
- `Disciplina`;
- `Curso`.

### Relacionamentos

- `Matricula` entre `Aluno` e `Disciplina`;
- `Pertence` entre `Aluno` e `Curso`.

### Cardinalidades

- `Aluno` N:M `Disciplina`;
- `Curso` 1:N `Aluno`.

## 10. Como distinguir entidade de atributo

### Use atributo quando

- apenas descreve algo;
- nao precisa existir sozinho;
- nao tem relacionamentos proprios.

Exemplo:

- `nome`.

### Use entidade quando

- tem varios atributos;
- pode se relacionar com outras entidades;
- tem existencia relevante no dominio.

Exemplo:

- `Curso`.

## 11. Conta de cardinalidade

Se:

- a faculdade tem 500 alunos;
- cada aluno cursa em media 5 disciplinas;

entao o relacionamento `Matricula` tera aproximadamente:

```text
500 x 5 = 2500 ocorrencias
```

Esse tipo de conta ajuda a prever tamanho de tabelas futuras.

## 12. Autorrelacionamento

Exemplo:

- um funcionario supervisiona outro funcionario.

Papeis:

- supervisor;
- supervisionado.

Esse tipo de caso exige cuidado para nao confundir a leitura do diagrama.

## 13. Exercicio resolvido

### Enunciado

"Um departamento possui varios professores. Cada professor pertence a um unico departamento."

### Solucao

- entidades: `Departamento`, `Professor`;
- relacionamento: `Lotacao`;
- cardinalidade: `Departamento 1:N Professor`.

Se todo professor precisa estar lotado, a participacao de `Professor` e total.

## 14. Erros comuns

- confundir entidade com atributo;
- esquecer cardinalidade;
- nao marcar chave;
- ignorar participacao;
- criar nomes vagos.

## 15. O que revisar para prova

- entidade, atributo e relacionamento;
- atributo-chave;
- cardinalidade;
- participacao total e parcial;
- diferenca entre atributo e entidade.

## 16. Resumo final

O ER e o idioma da modelagem conceitual. Se a modelagem ER estiver boa, o mapeamento relacional ficara muito mais facil e consistente.
