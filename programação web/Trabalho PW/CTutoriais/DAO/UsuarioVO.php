<?php
require '/../vendor/autoload.php';
class UsuarioVO {
    
    private $id;
    private $nome;
    private $senha;
    private $email;
    private $username;
    
    function __construct($nome, $senha, $email, $username, $id) {
        $this->nome = $nome;
        $this->senha = $senha;
        $this->email = $email;
        $this->username = $username;
        $this->id = $id;
    }

    
    function getID() {
        return $this->id;
    }

    function setID($id) {
        $this->id = $id;
    }

    
    function getNome() {
        return $this->nome;
    }

    function getSenha() {
        return $this->senha;
    }

    function getEmail() {
        return $this->email;
    }

    function getUsername() {
        return $this->username;
    }

    function setNome($nome) {
        $this->nome = $nome;
    }

    function setSenha($senha) {
        $this->senha = $senha;
    }

    function setEmail($email) {
        $this->email = $email;
    }

    function setUsername($username) {
        $this->username = $username;
    }


    
}