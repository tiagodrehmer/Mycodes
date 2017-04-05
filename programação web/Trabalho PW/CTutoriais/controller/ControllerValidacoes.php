<?php

require '/../vendor/autoload.php';

class ControllerValidacoes {

    private $validador;

    function __construct() {
        $this->validador = new Validacoes();
    }

    function isEmailUnico($email) {
        return $this->validador->isEmailUnico($email);
    }

    function isUsernameUnico($username) {
        return $this->validador->isUsernameUnico($username);
    }

    function verificaLogin($username_email, $senha) {
        return $this->validador->isLoginValido($username_email, $senha);
    }

    function isUsernameValido($username) {
        return $this->validador->isUsernameValido($username);
    }

    function setErros($temdados, $usernameUnico, $emailUnico, $usernameValido) {
        if ($temdados) {
            $username = $_POST['username'];
            $email = $_POST['email'];
            return $this->validador->setErros($usernameUnico, $emailUnico, $usernameValido, $username, $email);
        }
    }

    function hasEmailChanged() {
        return $this->validador->hasEmailChanged();
    }

    function hasUsernameChanged() {
        return $this->validador->hasUsernameChanged();
    }
    
    function isSenhasIguais(){
        return $this->validador->isSenhasIguais();
    }

}
