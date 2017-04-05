<?php

require '/../vendor/autoload.php';

class ControllerSessao {

    private $sessao;

    function __construct() {
        $this->sessao = new Sessao();
    }

    function testaAcesso($questaoID){
        $questaBD = new QuestaoDAO();
        $questaoVO = $questaBD->selectByID($questaoID);
        if($questaoVO){
            if ($questaoVO->getUserID() != $_SESSION["userID"]){
                header("Location: http://localhost/CTutoriais/view/forum.php");
            }
        }
        else{
            header("Location: http://localhost/CTutoriais/view/forum.php");
        }
    }
    //Retorna TRUE se uma sessão estiver ativa, senão FALSE
    function isSessaoAtiva() {
        return $this->sessao->checkSessionID();
    }

    //recebe dados da sessão ativa caso haja uma
    function getSessao() {
        @session_start();
    }

    //encerra a sessão do usuário
    function logOut() {
        if (isset($_GET['sair'])) {
            $this->sessao->logOut();
        }
    }

    //inicia uma sessão com os dados do usuário
    function logIn($user) {
        $this->sessao->logIn($user);
    }

    //Ao realizar o login o usuário é redirecionado para a página inicial
    function redirect() {
        $this->sessao->redirect();
    }

    //Atualizar os dados da sessão quando o usuário realizar uma edição em seus dados
    function refresh($user) {
        $this->sessao->refresh($user);
    }

    /*
     *  Verificar se o usuário selecionou a opção de excluir conta, caso tenha escolhido,
     *  Exclui a conta e mostra uma mensagem de que a conta foi excluida
     */

    function excluir($sessao) {
        if (isset($_GET['excluir'])) {
            $id = $_SESSION['userID'];
            $sessao = unserialize($_SESSION["sessao"]);
            $this->sessao->logOut();
            $db = new UsuarioDAO();
            $db->delete($id);

            echo"<br><br><br>
                <div class='alert alert-success alert-dismissible'>
                <a href='#' class'close' data-dismiss='alert' aria-label='close'>&times;</a>
                <strong> Usuário foi excluído com sucesso !</strong>
                </div>";
        }
    }

    /*
     *  Método para criar um usuário com os dados recebidos e em seguida  
     *  criar a conta desse usuário e realizar o login do usuário criado
     *  
     *  @param $nome string nome do usuário a ser adicionado
     *  @param $email string email do usuário a ser adicionado
     *  @param $senha string senha do usuário a ser adicionado
     *  @param $username username do usuário a ser adicionado
     */

    function criarConta($nome, $email, $senha, $username) {
        $user = new UsuarioVO($nome, $senha, $email, $username, "");
        $this->sessao->criarConta($user);
    }
    
    function atualizarConta($atualizasenha){
        $this->sessao->atualizarConta($atualizasenha);
    }
}
