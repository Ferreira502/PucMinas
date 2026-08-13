# Unidade 6 - SQL DDL e DML

## 1. Visao geral

Nesta unidade, a teoria vira comando real. O foco e aprender a:

- definir tabelas;
- impor restricoes;
- inserir e alterar dados;
- escrever consultas.

## 2. DDL

DDL define a estrutura do banco.

Comandos:

- `CREATE`;
- `ALTER`;
- `DROP`.

## 3. Restricoes principais

- `PRIMARY KEY`;
- `FOREIGN KEY`;
- `NOT NULL`;
- `UNIQUE`;
- `DEFAULT`;
- `CHECK`.

## 4. Exemplo completo de criacao

```sql
CREATE TABLE Curso (
    codigo INT PRIMARY KEY,
    nome VARCHAR(80) NOT NULL
);

CREATE TABLE Aluno (
    matricula INT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    email VARCHAR(120) UNIQUE,
    codigo_curso INT NOT NULL,
    semestre INT DEFAULT 1,
    CONSTRAINT fk_aluno_curso
        FOREIGN KEY (codigo_curso)
        REFERENCES Curso(codigo),
    CONSTRAINT ck_semestre
        CHECK (semestre >= 1)
);
```

## 5. DML

DML manipula os dados.

Comandos:

- `INSERT`;
- `UPDATE`;
- `DELETE`;
- `SELECT`.

## 6. INSERT

```sql
INSERT INTO Curso (codigo, nome)
VALUES (10, 'Sistemas de Informacao');

INSERT INTO Aluno (matricula, nome, email, codigo_curso, semestre)
VALUES (2026001, 'Ana Souza', 'ana@email.com', 10, 1);
```

Cuidados:

- respeitar tipos;
- nao repetir chave primaria;
- respeitar chave estrangeira.

## 7. UPDATE

### Exemplo correto

```sql
UPDATE Aluno
SET semestre = 2
WHERE matricula = 2026001;
```

### Exemplo perigoso

```sql
UPDATE Aluno
SET semestre = 2;
```

Sem `WHERE`, altera todas as linhas.

## 8. SELECT

### Consulta basica

```sql
SELECT nome, semestre
FROM Aluno
WHERE codigo_curso = 10;
```

## 9. Duplicatas e DISTINCT

```sql
SELECT DISTINCT codigo_curso
FROM Aluno;
```

## 10. Operadores especiais

### LIKE

```sql
SELECT nome
FROM Aluno
WHERE nome LIKE 'A%';
```

### BETWEEN

```sql
SELECT nome
FROM Aluno
WHERE semestre BETWEEN 2 AND 4;
```

### IS NULL

```sql
SELECT nome
FROM Aluno
WHERE email IS NULL;
```

### IN

```sql
SELECT nome
FROM Aluno
WHERE codigo_curso IN (10, 20);
```

## 11. ORDER BY

```sql
SELECT nome, semestre
FROM Aluno
ORDER BY semestre DESC, nome ASC;
```

## 12. NULL

Errado:

```sql
SELECT nome
FROM Aluno
WHERE email = NULL;
```

Certo:

```sql
SELECT nome
FROM Aluno
WHERE email IS NULL;
```

## 13. Subconsulta

```sql
SELECT nome
FROM Aluno
WHERE codigo_curso IN (
    SELECT codigo
    FROM Curso
    WHERE nome = 'Sistemas de Informacao'
);
```

## 14. Agregacao

```sql
SELECT codigo_curso, COUNT(*) AS qtd_alunos
FROM Aluno
GROUP BY codigo_curso;
```

Com filtro em grupos:

```sql
SELECT codigo_curso, COUNT(*) AS qtd_alunos
FROM Aluno
GROUP BY codigo_curso
HAVING COUNT(*) >= 30;
```

## 15. Contas comuns

### Contagem

Se a tabela `Aluno` tem 120 linhas:

```sql
SELECT COUNT(*) FROM Aluno;
```

Resultado:

```text
120
```

### Media

Se as notas sao `7, 8, 5, 10`:

```text
media = (7 + 8 + 5 + 10) / 4 = 30 / 4 = 7,5
```

Em SQL:

```sql
SELECT AVG(nota) FROM Avaliacao;
```

## 16. Ligacao com algebra relacional

- `WHERE` lembra selecao;
- colunas do `SELECT` lembram projecao;
- `JOIN` lembra juncao;
- `COUNT` e outras lembram agregacao.

## 17. SQL nao otimizado x SQL otimizado

Essa comparacao aparece quando a materia mistura SQL com processamento de consultas.

### Exemplo nao otimizado

```sql
SELECT A.nome, D.nome
FROM Clientes A, Aluguel B, Midias C, Filmes D
WHERE A.CPF = B.CPF_Cliente
  AND C.Tipo = 'BD'
  AND D.Genero = 'Drama'
  AND B.ID_Midia = C.Identificador
  AND A.Sexo = 'M'
  AND B.ValorPagar < 20
  AND C.CodFilme = D.Codigo;
```

Essa forma funciona, mas mistura:

- produto cartesiano implicito;
- filtros;
- juncoes.

### Exemplo otimizado e mais claro

```sql
SELECT A.nome, D.nome
FROM Clientes A
JOIN Aluguel B
  ON A.CPF = B.CPF_Cliente
JOIN Midias C
  ON B.ID_Midia = C.Identificador
JOIN Filmes D
  ON C.CodFilme = D.Codigo
WHERE A.Sexo = 'M'
  AND B.ValorPagar < 20
  AND C.Tipo = 'BD'
  AND D.Genero = 'Drama';
```

Vantagens da versao otimizada:

- separa melhor as juncoes;
- facilita leitura;
- ajuda a enxergar os filtros locais de cada tabela.

## 18. Exemplo com filtros cedo

Outra forma de pensar a otimizacao e enxergar subconsultas filtradas:

```sql
SELECT A.nome, D.nome
FROM
    (SELECT CPF, nome
     FROM Clientes
     WHERE Sexo = 'M') A
JOIN
    (SELECT CPF_Cliente, ID_Midia
     FROM Aluguel
     WHERE ValorPagar < 20) B
  ON A.CPF = B.CPF_Cliente
JOIN
    (SELECT Identificador, CodFilme
     FROM Midias
     WHERE Tipo = 'BD') C
  ON B.ID_Midia = C.Identificador
JOIN
    (SELECT Codigo, nome
     FROM Filmes
     WHERE Genero = 'Drama') D
  ON C.CodFilme = D.Codigo;
```

Essa forma deixa explicito o principio de reduzir cada relacao antes das juncoes.

## 19. O que revisar para prova

- restricoes;
- `PRIMARY KEY` e `FOREIGN KEY`;
- diferenca entre `INSERT`, `UPDATE`, `DELETE` e `SELECT`;
- `NULL`;
- subconsultas;
- `GROUP BY` e `HAVING`.

## 20. Resumo final

SQL costuma ser muito cobrada porque mistura teoria, sintaxe e interpretacao. O ideal e praticar cada comando junto com exemplos pequenos e bem entendidos.
