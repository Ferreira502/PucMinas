CREATE DATABASE IF NOT EXISTS SPD;
USE SPD;

-- Tabelas principais

CREATE TABLE IF NOT EXISTS tipo_item (
  cod_tipo INT NOT NULL AUTO_INCREMENT,
  descricao VARCHAR(100) NOT NULL,
  PRIMARY KEY (cod_tipo),
  CONSTRAINT uk_tipo_item_descricao UNIQUE (descricao)
);

CREATE TABLE IF NOT EXISTS item (
  cod_item INT NOT NULL AUTO_INCREMENT,
  nome VARCHAR(100) NOT NULL,
  estado_conserv VARCHAR(50) NOT NULL,
  tamanho VARCHAR(30) DEFAULT NULL,
  cod_tipo INT NOT NULL,
  PRIMARY KEY (cod_item),
  CONSTRAINT fk_item_tipo
    FOREIGN KEY (cod_tipo) REFERENCES tipo_item(cod_tipo)
    ON UPDATE CASCADE
    ON DELETE RESTRICT
);

CREATE TABLE IF NOT EXISTS doador (
  cpf CHAR(11) NOT NULL,
  telefone CHAR(20) NOT NULL,
  endereco VARCHAR(200) NOT NULL,
  primeiro_nome VARCHAR(50) NOT NULL,
  sobrenome VARCHAR(50) NOT NULL,
  PRIMARY KEY (cpf)
);

CREATE TABLE IF NOT EXISTS doacao (
  cod_doacao INT NOT NULL AUTO_INCREMENT,
  data_doacao DATE NOT NULL,
  cpf_doador CHAR(11) NOT NULL,
  PRIMARY KEY (cod_doacao),
  CONSTRAINT fk_doacao_doador
    FOREIGN KEY (cpf_doador) REFERENCES doador(cpf)
    ON UPDATE CASCADE
    ON DELETE RESTRICT
);

CREATE TABLE IF NOT EXISTS campanha (
  cod_campanha INT NOT NULL AUTO_INCREMENT,
  nome VARCHAR(100) NOT NULL,
  descricao TEXT DEFAULT NULL,
  data_inicio DATE NOT NULL,
  data_termino DATE NOT NULL,
  PRIMARY KEY (cod_campanha),
  CONSTRAINT chk_campanha_periodo CHECK (data_termino >= data_inicio)
);

CREATE TABLE IF NOT EXISTS voluntario (
  cpf CHAR(11) NOT NULL,
  nome VARCHAR(100) NOT NULL,
  telefone CHAR(20) NOT NULL,
  funcao VARCHAR(100) NOT NULL,
  PRIMARY KEY (cpf)
);

CREATE TABLE IF NOT EXISTS familia (
  cod_familia INT NOT NULL AUTO_INCREMENT,
  endereco VARCHAR(200) NOT NULL,
  telefone CHAR(20) NOT NULL,
  qtd_membros INT NOT NULL,
  PRIMARY KEY (cod_familia),
  CONSTRAINT chk_familia_qtd_membros CHECK (qtd_membros > 0)
);

CREATE TABLE IF NOT EXISTS pessoa (
  cpf CHAR(11) NOT NULL,
  nome VARCHAR(100) NOT NULL,
  sexo ENUM('M', 'F') NOT NULL,
  data_nascimento DATE NOT NULL,
  cod_familia INT NOT NULL,
  PRIMARY KEY (cpf),
  CONSTRAINT fk_pessoa_familia
    FOREIGN KEY (cod_familia) REFERENCES familia(cod_familia)
    ON UPDATE CASCADE
    ON DELETE RESTRICT
);

CREATE TABLE IF NOT EXISTS distribuicao (
  cod_distribuicao INT NOT NULL AUTO_INCREMENT,
  data_entrega DATE NOT NULL,
  cod_familia INT NOT NULL,
  PRIMARY KEY (cod_distribuicao),
  CONSTRAINT fk_distribuicao_familia
    FOREIGN KEY (cod_familia) REFERENCES familia(cod_familia)
    ON UPDATE CASCADE
    ON DELETE RESTRICT
);

-- Tabelas associativas

CREATE TABLE IF NOT EXISTS doacao_item (
  cod_doacao INT NOT NULL,
  cod_item INT NOT NULL,
  quantidade INT NOT NULL,
  PRIMARY KEY (cod_doacao, cod_item),
  CONSTRAINT chk_doacao_item_quantidade CHECK (quantidade > 0),
  CONSTRAINT fk_doacao_item_doacao
    FOREIGN KEY (cod_doacao) REFERENCES doacao(cod_doacao)
    ON UPDATE CASCADE
    ON DELETE CASCADE,
  CONSTRAINT fk_doacao_item_item
    FOREIGN KEY (cod_item) REFERENCES item(cod_item)
    ON UPDATE CASCADE
    ON DELETE RESTRICT
);

CREATE TABLE IF NOT EXISTS campanha_item (
  cod_campanha INT NOT NULL,
  cod_item INT NOT NULL,
  PRIMARY KEY (cod_campanha, cod_item),
  CONSTRAINT fk_campanha_item_campanha
    FOREIGN KEY (cod_campanha) REFERENCES campanha(cod_campanha)
    ON UPDATE CASCADE
    ON DELETE CASCADE,
  CONSTRAINT fk_campanha_item_item
    FOREIGN KEY (cod_item) REFERENCES item(cod_item)
    ON UPDATE CASCADE
    ON DELETE RESTRICT
);

CREATE TABLE IF NOT EXISTS voluntario_campanha (
  cpf_voluntario CHAR(11) NOT NULL,
  cod_campanha INT NOT NULL,
  PRIMARY KEY (cpf_voluntario, cod_campanha),
  CONSTRAINT fk_voluntario_campanha_voluntario
    FOREIGN KEY (cpf_voluntario) REFERENCES voluntario(cpf)
    ON UPDATE CASCADE
    ON DELETE CASCADE,
  CONSTRAINT fk_voluntario_campanha_campanha
    FOREIGN KEY (cod_campanha) REFERENCES campanha(cod_campanha)
    ON UPDATE CASCADE
    ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS distribuicao_item (
  cod_distribuicao INT NOT NULL,
  cod_item INT NOT NULL,
  quantidade INT NOT NULL,
  PRIMARY KEY (cod_distribuicao, cod_item),
  CONSTRAINT chk_distribuicao_item_quantidade CHECK (quantidade > 0),
  CONSTRAINT fk_distribuicao_item_distribuicao
    FOREIGN KEY (cod_distribuicao) REFERENCES distribuicao(cod_distribuicao)
    ON UPDATE CASCADE
    ON DELETE CASCADE,
  CONSTRAINT fk_distribuicao_item_item
    FOREIGN KEY (cod_item) REFERENCES item(cod_item)
    ON UPDATE CASCADE
    ON DELETE RESTRICT
);

CREATE TABLE IF NOT EXISTS voluntario_distribuicao (
  cpf_voluntario CHAR(11) NOT NULL,
  cod_distribuicao INT NOT NULL,
  PRIMARY KEY (cpf_voluntario, cod_distribuicao),
  CONSTRAINT fk_voluntario_distribuicao_voluntario
    FOREIGN KEY (cpf_voluntario) REFERENCES voluntario(cpf)
    ON UPDATE CASCADE
    ON DELETE CASCADE,
  CONSTRAINT fk_voluntario_distribuicao_distribuicao
    FOREIGN KEY (cod_distribuicao) REFERENCES distribuicao(cod_distribuicao)
    ON UPDATE CASCADE
    ON DELETE CASCADE
);