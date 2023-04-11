CREATE TABLE inf_tb (
inf_placa VARCHAR(6) NOT NULL,
inf_marca VARCHAR NOT NULL,
inf_capacidade NUMERIC NOT NULL,
inf_consumo VARCHAR NOT NULL,
inf_quilometragem NUMERIC(2) NOT NULL,
inf_modelo VARCHAR NOT NULL,
CONSTRAINT inf_tb_pk PRIMARY KEY (inf_placa)
);

CREATE TABLE tb_combustivel (
inf_placa VARCHAR(6) NOT NULL,
comb_qunatidade NUMERIC NOT NULL,
comb_valor NUMERIC NOT NULL,
comb_data DATE NOT NULL,
CONSTRAINT tb_combustivel_pk PRIMARY KEY (inf_placa)
);

CREATE TABLE tb_motoristas (
mt_CPF NUMERIC NOT NULL,
mt_CNH NUMERIC NOT NULL,
inf_placa VARCHAR(6) NOT NULL,
mt_tel NUMERIC NOT NULL,
mt_CEP NUMERIC NOT NULL,
mt_nome VARCHAR NOT NULL,
CONSTRAINT tb_motoristas_pk PRIMARY KEY (mt_CPF, mt_CNH, inf_placa)
);

CREATE TABLE tb_infra (
mt_CPF NUMERIC NOT NULL,
mt_CNH NUMERIC NOT NULL,
inf_placa VARCHAR(6) NOT NULL,
infra_cometida VARCHAR NOT NULL,
infra_prazo DATE NOT NULL,
infra_valor NUMERIC NOT NULL,
CONSTRAINT tb_infra_pk PRIMARY KEY (mt_CPF, mt_CNH, inf_placa)
);

CREATE TABLE tb_manutencao (
inf_placa VARCHAR(6) NOT NULL,
manu_custo NUMERIC NOT NULL,
manu_revisao NUMERIC NOT NULL,
manu_oleo NUMERIC NOT NULL,
CONSTRAINT tb_manutencao_pk PRIMARY KEY (inf_placa)
);

ALTER TABLE tb_manutencao ADD CONSTRAINT inf_tb_tb_manutencao_fk
FOREIGN KEY (inf_placa)
REFERENCES inf_tb (inf_placa)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE tb_motoristas ADD CONSTRAINT inf_tb_tb_motoristas_fk
FOREIGN KEY (inf_placa)
REFERENCES inf_tb (inf_placa)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE tb_combustivel ADD CONSTRAINT inf_tb_tb_combustivel_fk
FOREIGN KEY (inf_placa)
REFERENCES inf_tb (inf_placa)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE tb_infra ADD CONSTRAINT tb_motoristas_tb_infra_fk
FOREIGN KEY (mt_CPF, mt_CNH, inf_placa)
REFERENCES tb_motoristas (mt_CPF, mt_CNH, inf_placa)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;