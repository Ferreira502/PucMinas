# Unidade 2 - Esquemas, Linguagens e Arquitetura

## 1. Visao geral

Nesta unidade, o curso mostra como o banco e descrito e separado em camadas. Os conceitos centrais sao:

- esquema;
- instancia;
- arquitetura de tres esquemas;
- independencia de dados;
- linguagens de banco.

## 2. Esquema

Esquema e a definicao da estrutura do banco.

Ele descreve:

- tabelas;
- atributos;
- tipos;
- chaves;
- restricoes;
- relacionamentos.

O esquema muda pouco ao longo do tempo.

## 3. Instancia

Instancia e o estado atual dos dados em um momento.

### Exemplo

Esquema:

```sql
CREATE TABLE Aluno (
    matricula INT PRIMARY KEY,
    nome VARCHAR(100),
    curso VARCHAR(50)
);
```

Instancia em um certo dia:

| matricula | nome   | curso      |
|-----------|--------|------------|
| 1         | Ana    | Sistemas   |
| 2         | Bruno  | Computacao |

Se amanha entrar mais um aluno, muda a instancia, nao o esquema.

## 4. Arquitetura de tres esquemas

Ela divide o banco em tres niveis.

### Nivel externo

Visoes para usuarios ou grupos de usuarios.

Exemplo:

- secretaria ve dados academicos;
- financeiro ve dados de pagamento.

### Nivel conceitual

Descricao logica global do banco.

### Nivel interno

Descricao fisica do armazenamento.

Exemplo:

- arquivos;
- paginas;
- indices;
- blocos.

## 5. Mapeamentos

Para essa arquitetura funcionar, o sistema faz mapeamentos:

- externo -> conceitual;
- conceitual -> interno.

Esses mapeamentos ajudam a proteger aplicacoes contra mudancas internas.

## 6. Independencia de dados

Esse e um dos conceitos mais importantes da unidade.

### Independencia fisica

Mudancas no nivel interno nao deveriam exigir mudancas no nivel conceitual ou nas aplicacoes.

Exemplo:

```sql
CREATE INDEX idx_aluno_matricula ON Aluno(matricula);
```

A aplicacao continua fazendo:

```sql
SELECT nome
FROM Aluno
WHERE matricula = 10;
```

A consulta nao mudou, mas a forma de acesso sim.

### Independencia logica

Mudancas no esquema conceitual nao deveriam quebrar todas as visoes e programas.

Exemplo:

Tabela original:

```text
ALUNO(matricula, nome)
```

Depois:

```text
ALUNO(matricula, nome, email)
```

Consultas antigas que usam apenas `matricula` e `nome` podem continuar validas.

## 7. Exemplo de visoes externas

### Visao da secretaria

- matricula;
- nome;
- curso.

### Visao do financeiro

- matricula;
- nome;
- mensalidade;
- situacao de pagamento.

Ambos usam o mesmo banco, mas enxergam partes diferentes.

## 8. Linguagens de banco de dados

### DDL

Linguagem de definicao de dados.

Comandos:

- `CREATE`;
- `ALTER`;
- `DROP`.

Exemplo:

```sql
CREATE TABLE Disciplina (
    codigo CHAR(6) PRIMARY KEY,
    nome VARCHAR(80)
);
```

### DML

Linguagem de manipulacao de dados.

Comandos:

- `INSERT`;
- `UPDATE`;
- `DELETE`;
- `SELECT`.

Exemplos:

```sql
INSERT INTO Disciplina (codigo, nome)
VALUES ('BD001', 'Banco de Dados');
```

```sql
SELECT nome
FROM Disciplina;
```

## 9. Exemplo completo ligando os conceitos

### Esquema

```sql
CREATE TABLE Curso (
    codigo INT PRIMARY KEY,
    nome VARCHAR(80)
);
```

### Instancia

| codigo | nome                  |
|--------|-----------------------|
| 10     | Sistemas              |
| 20     | Computacao            |

### Nivel externo

Uma aplicacao pode mostrar apenas o nome do curso.

### Nivel interno

O SGBD decide como guardar isso em disco.

## 10. Conta conceitual simples

Se uma visao externa mostra apenas 3 colunas de uma tabela que tem 10 colunas, isso nao significa que o banco tenha ficado menor. Significa apenas que o usuario esta vendo:

```text
3 / 10 = 30% das colunas
```

Isso ajuda a entender que visao externa nao e copia fisica necessariamente, e sim uma perspectiva sobre os dados.

## 11. O que revisar para prova

- esquema x instancia;
- nivel externo, conceitual e interno;
- independencia fisica x logica;
- DDL x DML.

## 12. Resumo final

Esta unidade explica como o banco consegue evoluir sem quebrar tudo. A separacao entre estrutura logica, visoes e armazenamento e o fundamento da independencia de dados.
