<?php

class RespostaVO{
    private $respostaID;
    private $questaoID;
    private $userID;
    private $dataResposta;
    private $resposta;
    private $codigo;
    private $autor;
    
    function __construct($respostaID, $questaoID, $userID, $dataResposta, $resposta, $autor, $codigo) {
        $this->respostaID = $respostaID;
        $this->questaoID = $questaoID;
        $this->userID = $userID;
        $this->dataResposta = $dataResposta;
        $this->resposta = $resposta;
        $this->autor = $autor;
        $this->codigo = $codigo;
    }

    function getRespostaID() {
        return $this->respostaID;
    }

    function getQuestaoID() {
        return $this->questaoID;
    }

    function getUserID() {
        return $this->userID;
    }

    function getDataResposta() {
        return $this->dataResposta;
    }

    function getResposta() {
        return $this->resposta;
    }

    function setRespostaID($respostaID) {
        $this->respostaID = $respostaID;
    }

    function setQuestaoID($questaoID) {
        $this->questaoID = $questaoID;
    }

    function setUserID($userID) {
        $this->userID = $userID;
    }

    function setDataResposta($dataResposta) {
        $this->dataResposta = $dataResposta;
    }

    function setResposta($resposta) {
        $this->resposta = $resposta;
    }

    function getAutor() {
        return $this->autor;
    }

    function setAutor($autor) {
        $this->autor = $autor;
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
    function getCodigo() {
        return $this->codigo;
    }

    function setCodigo($codigo) {
        $this->codigo = $codigo;
    }



}

