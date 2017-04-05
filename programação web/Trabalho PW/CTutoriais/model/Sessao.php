<?php

require '/../vendor/autoload.php';

class Sessao {

    function __construct() {
        
    }

    /*
     * Método para iniciar uma sessão mantendo alguns dados (nome,username e email)
     * do usuário logado no sistema 
     * 
     * @param $user usuarioVO esse parâmetro contém as informações do usuario
     * que está realizando o login
     */

    function logIn($user) {
        if (!isset($_SESSION['nome'])) {
            $_SESSION["nome"] = $user->getNome();
            $_SESSION["email"] = $user->getEmail();
            $_SESSION["username"] = $user->getUsername();
            $_SESSION["userID"] = $user->getID();
            $_SESSION["senha"] = $user->getSenha();

            $sessao = new ControllerSessao();
            $_SESSION["sessao"] = serialize($sessao);
        } else {
            
        }
    }

    /*
     * Método para encerrar a sessão do usuário e limpar suas informações da sessão
     */

    function logOut() {
        $_SESSION = FALSE;
        if (ini_get("session.use_cookies")) {
            $params = session_get_cookie_params();
            setcookie(session_name(), '', time() - 42000, $params["path"], $params["domain"], $params["secure"], $params["httponly"]
            );
        }
        @session_destroy();
        if (empty($_SESSION['nome'])) {
            header("Location: http://localhost/CTutoriais/view/index.php");
        }
    }

    /*
     * Método para redirecionar o usuário para a página inicial quando ele realizar
     * o login
     */

    function redirect() {
        if (!empty($_SESSION['nome'])) {
            header("Location: http://localhost/CTutoriais/view/index.php");
        }
    }

    /**
     * Método para atualizar a sessão quando o usuário editar os dados da sua conta
     * @param $user usuarioVO, objeto contendo informações atualizadas sobre a sessão
     */
    function refresh($user) {
        $_SESSION["nome"] = $user->getNome();
        $_SESSION["email"] = $user->getEmail();
        $_SESSION["username"] = $user->getUsername();
        $_SESSION["senha"] = $user->getSenha();
    }

    /**
     * Método para criar a conta e a sessão quando o usuário realizar a criação de conta
     * @param $user usuarioVO, objeto contendo informações sobre o usuário a ser criado
     */
    function criarConta($user) {
        $db = new UsuarioDAO();
        $db->insert($user);
        $user = $db->selectByLogin($user->getUsername(), $user->getSenha());
        $this->logIn($user);
    }

    function atualizarConta($atualizasenha) {

        if ($atualizasenha) {
            $user = new UsuarioVO($_POST['nome'], md5($_POST['senhanova']), $_POST['email'], $_POST['username'], $_SESSION['userID']);
        } else {
            $user = new UsuarioVO($_POST['nome'], $_SESSION['senha'], $_POST['email'], $_POST['username'], $_SESSION['userID']);
        }

        $db = new UsuarioDAO();
        $db->update($user);

        $sessao = unserialize($_SESSION["sessao"]);
        $sessao->refresh($user);
    }

}
