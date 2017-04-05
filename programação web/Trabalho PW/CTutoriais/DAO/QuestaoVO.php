<?php

class QuestaoVO{
    private $titulo;
    private $descricao;
    private $dataquestao;
    private $questaoID;
    private $userID;
    private $autor;
    private $codigo;
    
    function __construct($titulo, $descricao, $dataquestao, $questaoID, $userID, $autor, $codigo) {
        $this->titulo = $titulo;
        $this->descricao = $descricao;
        $this->dataquestao = $dataquestao;
        $this->questaoID = $questaoID;
        $this->userID = $userID;
        $this->autor = $autor;
        $this->codigo = $codigo;
    }
    function getTitulo() {
        return $this->titulo;
    }

    function getDescricao() {
        return $this->descricao;
    }

    function getDataquestao() {
        return $this->dataquestao;
    }

    function getQuestaoID() {
        return $this->questaoID;
    }

    function getUserID() {
        return $this->userID;
    }

    function setTitulo($titulo) {
        $this->titulo = $titulo;
    }

    function setDescricao($descricao) {
        $this->descricao = $descricao;
    }

    function setDataquestao($dataquestao) {
        $this->dataquestao = $dataquestao;
    }

    function setQuestaoID($questaoID) {
        $this->questaoID = $questaoID;
    }

    function setUserID($userID) {
        $this->userID = $userID;
    }
    
    function getAutor() {
        return $this->autor;
    }

    function setAutor($autor) {
        $this->autor = $autor;
    }

    function getCodigo() {
        return $this->codigo;
    }

    function setCodigo($codigo) {
        $this->codigo = $codigo;
    }

    function getCodigoFormatado() {
        if(strlen($this->codigo) > 2){
            $tag = "<pre><code><br>";
            $fechatag = "</code></pre>";
            $tag = $tag . $this->codigo . $fechatag;
            return $tag;
        }else{
            return "";
        }
    }

}