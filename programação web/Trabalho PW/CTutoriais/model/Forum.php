<?php
require '/../vendor/autoload.php';
class Forum{
    
    function __construct() {
        
    }
    
    //Método para verificar se um usuário está logado no fórum, caso esteja habilita o botão de 
    //criar uma nova questão, caso contrário desabilita ele.
    function buttonNovaQuestao(){
        if(!empty($_SESSION['nome'])){
            return "<button type='button' class='btn btn-success btn-lg btn-block' data-toggle='modal' data-target='#ModalQuestao'>"
                        . "<span class='glyphicon glyphicon-plus'></span> Criar uma questão"
                    . "</button>";
        }else{
            return "<button type='button' class='btn btn-success btn-lg btn-block disabled'  >"
                        . "<span class='glyphicon glyphicon-plus'></span> Criar uma questão"
                    . "</button>";
        }
    } 
    
    //Método para verificar se um usuário está logado no fórum, caso esteja habilita o botão de 
    //adicionar uma nova resposta, caso contrário desabilita ele.
    function buttonNovaResposta(){
        if(!empty($_SESSION['nome'])){
            return "<button type='button' class='btn btn-success btn-lg btn-block' data-toggle='modal' data-target='#ModalResposta'>"
                        . "<span class='glyphicon glyphicon-plus'></span> Adicionar Uma Resposta"
                    . "</button>";
        }else{
            return "<button type='button' class='btn btn-success btn-lg btn-block disabled'  >"
                        . "<span class='glyphicon glyphicon-plus'></span> Adicionar Uma Resposta"
                    . "</button>";
        }
    } 

    //inserir nova questão no banco
    function insertNovaQuestao($questaoVO) {
        $db = new QuestaoDAO();
        $db->insert($questaoVO);
    }

    //retorna uma array contendo todas as questões existentes no banco
    function selectQuestoes(){
        $db = new QuestaoDAO();
        return $db->selectAll();
    }

    //retorna o objeto QuestaoVO que tem questaoID = $questaoID
    function getQuestaoByID($questaoID){
        $db = new QuestaoDAO();
        return $db->selectByID($questaoID);
    }

    
    function alteraQuestao($questaoVO){
        $db = new questaoDAO();
        if (testaUsuarioQuestao($questaoVO)){
            $db = new questaoDAO();
            $db->update($questaoDAO);
            return;
        }
    }
    
    function testaUsuarioQuestao($questaoVO){
        if ($questaoVO->getUsuarioID() == $_SESSION["userID"]){
            return true;
        }
        return false;
    }
    //inserir uma nova resposta no banco
    function insertNovaResposta($respostaVO){
        $db = new RespostaDAO();
        $db->insert($respostaVO);
    }
    
    function selectRespostasByQuestao($questaoID){
        $db = new RespostaDAO();
        return $db->selectRespostasByQuestao($questaoID);
    }
    
    function getQuantidadeRespostas($questaoID){
        $db = new RespostaDAO();
        return $db->selectNumeroRespostas($questaoID);
    }
    
}