USE SPD;

-- Inserindo tipos de item

INSERT INTO tipo_item (cod_tipo, descricao)
VALUES
(1, 'Roupa'),
(2, 'Calcado'),
(3, 'Cobertor'),
(4, 'Brinquedo'),
(5, 'Objeto de necessidade basica');


-- Inserindo itens

INSERT INTO item (cod_item, nome, estado_conserv, tamanho, cod_tipo)
VALUES
(1, 'Camiseta infantil', 'Bom', 'M', 1),
(2, 'Tenis infantil', 'Otimo', '32', 2),
(3, 'Cobertor casal', 'Bom', 'Unico', 3),
(4, 'Boneca', 'Novo', NULL, 4),
(5, 'Kit higiene', 'Novo', NULL, 5);


-- Inserindo doadores

INSERT INTO doador (cpf, telefone, endereco, primeiro_nome, sobrenome)
VALUES
('11111111111', '31999999999', 'Rua A, 100', 'Joao', 'Silva'),
('22222222222', '31888888888', 'Rua B, 200', 'Maria', 'Oliveira'),
('33333333333', '31777777777', 'Rua C, 300', 'Carlos', 'Souza');


-- Inserindo doacoes

INSERT INTO doacao (cod_doacao, data_doacao, cpf_doador)
VALUES
(1, '2025-05-10', '11111111111'),
(2, '2025-05-20', '22222222222'),
(3, '2025-06-01', '33333333333');


-- Inserindo itens das doacoes

INSERT INTO doacao_item (cod_doacao, cod_item, quantidade)
VALUES
(1, 1, 30),
(1, 3, 15),
(2, 2, 20),
(2, 4, 10),
(3, 5, 25);


-- Inserindo campanhas

INSERT INTO campanha (cod_campanha, nome, descricao, data_inicio, data_termino)
VALUES
(1, 'Inverno Solidario', 'Campanha para arrecadacao de roupas e cobertores.', '2025-05-01', '2025-06-30'),
(2, 'Dia das Criancas', 'Campanha para arrecadacao de brinquedos.', '2025-09-01', '2025-10-12'),
(3, 'Cuidado Essencial', 'Campanha para arrecadacao de itens basicos de higiene.', '2025-07-01', '2025-07-31');


-- Inserindo vinculo campanha_item

INSERT INTO campanha_item (cod_campanha, cod_item)
VALUES
(1, 1),
(1, 3),
(2, 4),
(3, 5);


-- Inserindo voluntarios

INSERT INTO voluntario (cpf, nome, telefone, funcao)
VALUES
('44444444444', 'Ana Lima', '31666666666', 'Organizadora'),
('55555555555', 'Pedro Santos', '31555555555', 'Distribuidor'),
('66666666666', 'Mariana Costa', '31444444444', 'Triagem de doacoes');


-- Inserindo vinculo voluntario_campanha

INSERT INTO voluntario_campanha (cpf_voluntario, cod_campanha)
VALUES
('44444444444', 1),
('66666666666', 1),
('44444444444', 2),
('66666666666', 3);


-- Inserindo familias

INSERT INTO familia (cod_familia, endereco, telefone, qtd_membros)
VALUES
(1, 'Rua das Flores, 10', '31333333333', 4),
(2, 'Rua Central, 20', '31222222222', 3),
(3, 'Rua Esperanca, 35', '31111111111', 5);


-- Inserindo pessoas

INSERT INTO pessoa (cpf, nome, sexo, data_nascimento, cod_familia)
VALUES
('77777777777', 'Jose Ferreira', 'M', '1980-05-10', 1),
('88888888888', 'Ana Ferreira', 'F', '1985-08-15', 1),
('99999999999', 'Lucas Ferreira', 'M', '2012-01-10', 1),
('10101010101', 'Paula Martins', 'F', '1990-03-22', 2),
('20202020202', 'Rafael Martins', 'M', '2015-09-05', 2),
('30303030303', 'Carla Souza', 'F', '1978-12-01', 3);


-- Inserindo distribuicoes

INSERT INTO distribuicao (cod_distribuicao, data_entrega, cod_familia)
VALUES
(1, '2025-06-15', 1),
(2, '2025-06-20', 2),
(3, '2025-07-10', 3);


-- Inserindo itens distribuidos

INSERT INTO distribuicao_item (cod_distribuicao, cod_item, quantidade)
VALUES
(1, 1, 5),
(1, 3, 2),
(2, 2, 3),
(2, 4, 1),
(3, 5, 4);


-- Inserindo vinculo voluntario_distribuicao

INSERT INTO voluntario_distribuicao (cpf_voluntario, cod_distribuicao)
VALUES
('55555555555', 1),
('44444444444', 1),
('55555555555', 2),
('66666666666', 3);