CREATE DATABASE IF NOT EXISTS forum;
use forum;

CREATE TABLE IF NOT EXISTS forum.usuario (
	userID int NOT NULL AUTO_INCREMENT,
	username varchar(64) NOT NULL,
	email varchar(64) NOT NULL,
	senha varchar(32) NOT NULL,
	nome varchar(64) NOT NULL,
	PRIMARY KEY (`userID`)
);

CREATE TABLE IF NOT EXISTS forum.questao(
	questaoID int NOT NULL AUTO_INCREMENT,
    userID int NOT NULL ,
    titulo varchar(128) NOT NULL,
	descricao varchar(2048),
    codigodescricao varchar(2048),
	dataquestao datetime NOT NULL,
    FOREIGN KEY (userID) REFERENCES usuario(userID) ON DELETE CASCADE,
	PRIMARY KEY (questaoID)
);


CREATE TABLE IF NOT EXISTS forum.resposta(
	respostaID int NOT NULL AUTO_INCREMENT,
    userID int NOT NULL ,
	questaoID int NOT NULL,
	dataresposta datetime NOT NULL,
    resposta varchar(2048) NOT NULL,
    codigoresposta varchar(2048),
    FOREIGN KEY (userID) REFERENCES usuario(userID) ON DELETE CASCADE,
    FOREIGN KEY (questaoID) REFERENCES questao(questaoID)  ON DELETE CASCADE,
	PRIMARY KEY (respostaID) 
);
