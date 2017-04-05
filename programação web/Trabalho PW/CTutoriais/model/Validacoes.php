<?php

require '/../vendor/autoload.php';

class Validacoes {

    private $usuarioDAO;

    function __construct() {
        $this->usuarioDAO = new UsuarioDAO();
    }

    /**
     * Métodos para verificar se os campos de username e email são únicos no banco
     * @param string $email
     * @param string $username
     * @return boolean true se o parâmetro for único, senão false
     */
    //verificar se o email já não existe no banco
    function isEmailUnico($email) {
        $sql = "SELECT * FROM forum.usuario WHERE email = '$email';";
        if ($this->usuarioDAO->existeNoBanco($sql)) {
            return FALSE;
        } else {
            return TRUE;
        }
    }

    //verificar se o username já não existe no banco
    function isUsernameUnico($username) {
        $sql = "SELECT * FROM forum.usuario WHERE username = '$username';";
        if ($this->usuarioDAO->existeNoBanco($sql)) {
            return FALSE;
        } else {
            return TRUE;
        }
    }

    function isLoginValido($username_email, $senha) {
        $sql_username = "SELECT * FROM forum.usuario WHERE username = '" . $username_email . "' "
                . "and senha = MD5('" . $senha . "');";
        $sql_email = "SELECT * FROM forum.usuario WHERE email = '" . $username_email . "' "
                . "and senha = MD5('" . $senha . "');";

        $username = $this->usuarioDAO->existeNoBanco($sql_username);
        $email = $this->usuarioDAO->existeNoBanco($sql_email);

        if ($username || $email) {
            return TRUE;
        } else {
            return FALSE;
        }
    }

    function isUsernameValido($username) {
        if (ctype_alnum($username)) {
            return TRUE;
        } else {
            if (strpos($username, ' ')) {
                return FALSE;
            }
        }
    }
    
    function isUserIDAutor($userID, $questaoID){
    
        
    }

    /**
     * Método para verificar as condições dos campos informados e gerar mensagens de erro se for o caso
     * 
     * @param $usernameUnico representa se o username é unico true é unico, false se já existe
     * @param $emailUnico  representa se o email é unico true é unico, false se já existe
     * @param $usernameValido representa se o username é valido, true é válido false se não for válido
     * @param $username string contendo o username
     * @param $email string que contem o email
     * @return string especificando o erro ecorrido, se nao ocorreu nenhum ela é vazia
     */
    function setErros($usernameUnico, $emailUnico, $usernameValido, $username, $email) {
        $err = "";
        if ($usernameUnico && $emailUnico && $usernameValido) {
            return $err;
        } else {
            $err = $err . "<div id='err'> ";
        }
        if (!$usernameValido) {
            $err = $err . "<p id='errmessage'> Username $username inválido, username não pode conter espaços ou caracteres especiais &excl;</p>";
        }
        if (!$emailUnico) {
            $err = $err . "<p id='errmessage'> Email " . $email . " já está cadastrado &excl; </p>";
        }
        if (!$usernameUnico) {
            $err = $err . "<p id='errmessage'> Username " . $username . " já está cadastrado &excl; </p>";
        }
        $err = $err . "</div>";
        return $err;
    }

    //verifica se o usuário alterou seu email na página de edição
    //se foi alterado retorna TRUE senão FALSE
    function hasEmailChanged() {
        if ($_POST['email'] == $_SESSION['email']) {
            return FALSE;
        } else {
            return TRUE;
        }
    }

    //verifica se o usuário alterou seu username na página de edição
    //se foi alterado retorna TRUE senão FALSE 
    function hasUsernameChanged() {
        if ($_POST['username'] == $_SESSION['username']) {
            return FALSE;
        } else {
            return TRUE;
        }
    }

    //verifica se as senhas são iguais na hora de alterar a senha do usuário
    //se forem iguais retorna TRUE senão FALSE
    function isSenhasIguais() {
        if (md5($_POST['senhaatual']) == $_SESSION['senha']) {
            return TRUE;
        } else {
            return FALSE;
        }
    }

}
