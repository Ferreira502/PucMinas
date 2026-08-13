# Unidade 1 - Introducao a SBD e Modelos de Dados

## 1. Visao geral

Esta unidade introduz os fundamentos de banco de dados. O foco e entender:

- o que e um banco de dados;
- o que e um sistema de banco de dados;
- o papel do SGBD;
- por que modelamos dados em niveis diferentes.

Sem essa base, o restante da disciplina vira decoracao. Com ela, os assuntos seguintes passam a fazer sentido como partes de um mesmo sistema.

## 2. Banco de Dados, SBD e SGBD

### Banco de Dados

Banco de dados e uma colecao organizada de dados relacionados, criada para representar uma parte do mundo real e atender um objetivo.

Exemplos:

- sistema academico;
- sistema bancario;
- loja virtual;
- hospital.

### Sistema de Banco de Dados

O SBD e o ambiente completo que envolve:

- o banco de dados;
- o SGBD;
- usuarios;
- aplicacoes;
- regras de acesso, seguranca e manutencao.

### SGBD

O SGBD e o software que gerencia os dados.

Funcoes principais:

- criar estruturas;
- armazenar dados;
- consultar e atualizar informacoes;
- impor restricoes;
- controlar concorrencia;
- recuperar falhas.

## 3. Por que usar banco de dados

Antes de SGBD, era comum guardar tudo em arquivos isolados. Isso gera varios problemas:

- redundancia de dados;
- inconsistencias;
- dificuldade de compartilhamento;
- seguranca fraca;
- manutencao dificil;
- programas muito acoplados aos arquivos.

Com banco de dados, busca-se:

- centralizacao;
- integridade;
- compartilhamento controlado;
- independencia de dados;
- flexibilidade para consultas.

## 4. Exemplo de redundancia e inconsistencia

Imagine dois arquivos:

- `alunos.txt`;
- `matriculas.txt`.

Se o nome do aluno aparece nos dois, uma mudanca de nome exige alterar em ambos. Se um for atualizado e o outro nao, o sistema passa a ter duas versoes diferentes da mesma informacao.

No modelo relacional, o ideal e:

- guardar os dados do aluno em uma tabela `ALUNO`;
- guardar as matriculas em `MATRICULA`;
- referenciar o aluno por chave.

Isso reduz redundancia e inconsistencias.

## 5. Propriedades de um banco de dados

As propriedades mais importantes sao:

- persistencia;
- compartilhamento;
- controle de redundancia;
- integridade;
- seguranca;
- suporte a concorrencia;
- independencia de dados.

### Persistencia

Os dados continuam existindo apos o encerramento do programa.

### Compartilhamento

Mais de um usuario ou sistema pode acessar os dados.

### Integridade

Os dados devem obedecer regras do dominio.

Exemplo:

- nao pode existir matricula sem aluno;
- nao pode existir nota fora do intervalo permitido.

## 6. Atores no ambiente de BD

### DBA

Responsavel por:

- administracao do banco;
- seguranca;
- backup e recuperacao;
- desempenho;
- criacao de usuarios e permissoes.

### Projetista de BD

Cuida da modelagem conceitual e logica.

### Desenvolvedor

Escreve aplicacoes e consultas.

### Usuario final

Consome o sistema, muitas vezes sem ver o banco diretamente.

## 7. Projeto de banco de dados

O projeto de BD normalmente segue uma sequencia:

1. levantamento de requisitos;
2. modelagem conceitual;
3. projeto logico;
4. projeto fisico;
5. ajuste e manutencao.

### Exemplo rapido

Para um sistema academico:

- requisitos: controlar alunos, disciplinas e matriculas;
- conceitual: criar entidades e relacionamentos;
- logico: transformar em tabelas;
- fisico: decidir indices, blocos e organizacao.

## 8. Modelos de dados

Modelo de dados e o conjunto de conceitos usados para descrever:

- dados;
- relacionamentos;
- restricoes;
- operacoes.

## 9. Niveis de modelagem

### Modelo conceitual

Representa o dominio de forma abstrata, independente do SGBD.

Exemplo:

- entidades `Aluno`, `Disciplina`, `Professor`.

### Modelo logico

Traduz o modelo conceitual para uma estrutura de banco.

Exemplo:

- tabelas `ALUNO`, `DISCIPLINA`, `PROFESSOR`.

### Modelo fisico

Mostra como os dados serao armazenados de fato.

Exemplo:

- arquivos;
- blocos;
- indices;
- metodos de acesso.

## 10. Exemplo completo dos tres niveis

### Mundo real

"Alunos se matriculam em disciplinas."

### Conceitual

- entidade `Aluno`;
- entidade `Disciplina`;
- relacionamento `Matricula`.

### Logico

```text
ALUNO(matricula, nome, curso)
DISCIPLINA(codigo, nome, carga_horaria)
MATRICULA(matricula, codigo, semestre)
```

### Fisico

- tabela `ALUNO` armazenada em arquivo heap;
- indice em `ALUNO(matricula)`;
- `MATRICULA` ocupando varios blocos de disco.

## 11. Contas simples que ja podem aparecer

Nesta unidade nao ha muitas contas pesadas, mas ja vale a ideia de volume.

Se:

- existem 500 alunos;
- cada aluno cursa em media 5 disciplinas;

entao o numero aproximado de registros de matricula e:

```text
500 x 5 = 2500 matriculas
```

Esse raciocinio e importante porque o tamanho das relacoes influencia armazenamento, indices e custo de consultas.

## 12. Perguntas classicas

### Banco de dados e arquivo sao a mesma coisa?

Nao. Um arquivo e apenas uma forma de guardar dados. Um banco envolve estrutura, controle, regras, compartilhamento e administracao.

### Todo sistema precisa de SGBD?

Nao necessariamente, mas quando o volume, a concorrencia ou a necessidade de integridade cresce, o SGBD passa a ser muito vantajoso.

## 13. O que revisar para prova

- diferenca entre BD, SBD e SGBD;
- vantagens de banco sobre arquivos;
- papel dos atores;
- etapas do projeto;
- diferenca entre modelo conceitual, logico e fisico.

## 14. Resumo final

Esta unidade forma a base da disciplina. O ponto mais importante e perceber que banco de dados nao e apenas armazenar informacao, e sim representar um dominio com estrutura, regras, compartilhamento e controle.
