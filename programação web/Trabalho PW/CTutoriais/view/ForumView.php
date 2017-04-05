<?php
require '/../vendor/autoload.php';
class ForumView{

    function __construct() {
        
    }
    
    /**
     * Método para exibir uma questão no fórum
     * @param $questaoVO objeto que contém todas as informações de uma questão a ser 
     * 
     * 
     * href='discussao.php?questao=".$questaoVO->getQuestaoID()."&remover=".$questaoVO->getQuestaoID()."'
     * 
     * 
     * 
     * 
     * mostrada
     */
    function mostraQuestao($questaoVO){
        $questaoModal = new ModalsView();
        $questaoModal->showModalEditarQuestao($questaoVO);
        $questaoModal->showModalAvisoQuestao("Excluir Questão", "Tem certeza que deseja excluir sua Questão?", $questaoVO->getQuestaoID());
        $botoes = "<div class='direita'>
                        <button class=' btn btn-success'  data-toggle='modal' data-target='#ModalEditarQuestao".$questaoVO->getQuestaoID()."'>
                            <span class='glyphicon glyphicon-edit'></span>
                            Editar
                        </button>
                        <button class=' btn btn-danger' data-toggle='modal' data-target='#modalAviso".$questaoVO->getQuestaoID()."'>
                            <span class='glyphicon glyphicon-remove'></span>
                            Excluir
                        </button>
                    </div>";
        $msg = "<div class='panel-body'>";
        if(!empty($_SESSION['nome'])){
            if($_SESSION['userID'] == $questaoVO->getUserID()){
                $msg = $msg . $botoes;
            }    
        }
        $msg = $msg . "            
                        <div class='esquerda panel-body '>
                            <a href='discussao.php?questao=".$questaoVO->getQuestaoID()."'>
                                <h3>".$questaoVO->getTitulo()."</h3>
                            </a> 
                            <p>".$questaoVO->getDescricao()."</p>
                            <br>
                            ".$questaoVO->getCodigoFormatado()."
                            <p> Por ".$questaoVO->getAutor()." em ".$questaoVO->getDataQuestao()."</p>
                            <hr>
                        </div>
                    </div>";
        echo $msg;
    }
   
    
     /**
     * Método para exibir uma resposta na sessão de discussão
     * @param $respostaVO objeto que contém todas as informações de uma resposta a ser
     * mostrada
     */
    function mostraResposta($respostaVO){
        $respostaModal = new ModalsView();
        $respostaModal->showModalEditarResposta($respostaVO);
        $db = new UsuarioDAO();
        $botoes = "<div class='direita'>
                        <button class=' btn btn-success'  data-toggle='modal' data-target='#ModalEditarResposta".$respostaVO->getRespostaID()."'>
                            <span class='glyphicon glyphicon-edit'></span>
                            Editar
                        </button></a>
                        <a href='discussao.php?questao=".$respostaVO->getQuestaoID()."&remover=".$respostaVO->getRespostaID()."'><button class=' btn btn-danger '>
                            <span class='glyphicon glyphicon-remove'></span>
                            Excluir
                        </button></a>
                    </div>";
        $nome = $respostaVO->getAutor();
        $msg = "<hr> <div class='panel-body'>";
        if(!empty($_SESSION['nome'])){
            if($_SESSION['userID'] == $respostaVO->getUserID()){
                $msg = $msg . $botoes;
            }    
        }               
        $msg = $msg . " ".$respostaVO->getResposta()."</p>
                            <br>
                            ".$respostaVO->getCodigoFormatado()."
                            <p> Por $nome em ".$respostaVO->getDataResposta()."</p>
                            <hr>
                    </div>";
        echo $msg;
    }
}