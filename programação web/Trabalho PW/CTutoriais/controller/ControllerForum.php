<?php

require '/../vendor/autoload.php';

class ControllerForum {

    private $forum;

    function __construct() {
        $this->forum = new Forum();
    }

    function buttonNovaQuestao() {
        echo $this->forum->buttonNovaQuestao();
    }

    function buttonNovaResposta() {
        echo $this->forum->buttonNovaResposta();
    }

    function insertNovaQuestao() {
        if (isset($_GET['inserir'])) {
            $questaoVO = new QuestaoVO($_POST['titulo'], $_POST['desc'], "now()", "", $_SESSION['userID'], "", $_POST['codigo']);
            $this->forum->insertNovaQuestao($questaoVO);
        }
    }

    function getQuestoes() {
        return $this->forum->selectQuestoes();
    }

    function getNomeByID($questao) {
        if ($questao) {
            return $this->forum->getNomeByID($questao->getUserID());
        }
    }

    function getQuestaoByID() {
        if (isset($_GET['questao'])) {
            return $this->forum->getQuestaoByID($_GET['questao']);
        }
    }

    function testaExcluir() {
        if (isset($_GET['excluir']) && !empty($_SESSION['userID'])) {
            $questaoDAO = new QuestaoDAO();
            $questaoDAO->delete($_GET['excluir']);
        }
    }

    function updateBanco() {
        if (isset($_GET['update'])) {
            $questao = $this->getQuestaoByID();
            $questao->setTitulo($_POST['titulo']);
            $questao->setDescricao($_POST['descricao']);
            $questao->setCodigo($_POST['codigo']);
            $bd = new QuestaoDAO();
            $bd->update($questao);
        }
    }

    function insertNovaResposta() {
        if (isset($_GET['responder'])) {
            $respostaVO = new RespostaVO("", $_GET['questao'], $_SESSION['userID'], "", $_POST['resposta'], "", $_POST['codigo']);
            $this->forum->insertNovaResposta($respostaVO);
        }
    }

    function getRespostasByQuestao() {
        if (isset($_GET['questao'])) {
            return $this->forum->selectRespostasByQuestao($_GET['questao']);
        }
    }

    function getQuantidadeRespostas() {
        if (isset($_GET['questao'])) {
            return $this->forum->getQuantidadeRespostas($_GET['questao']);
        }
    }

    /**
     * Método para remover uma resposta de uma questão e gerar uma mensagem de feedback para o usuário
     */
    function removerResposta() {
        if (isset($_GET['remover'])) {
            $db = new RespostaDAO();
            $db->delete($_GET['remover']);

            echo"<br><br><br>
                <div class='alert alert-success alert-dismissible'>
                <a href='#' class'close' data-dismiss='alert' aria-label='close'>&times;</a>
                <strong> Resposta foi excluída com sucesso !</strong>
                </div>";
        }
    }

    function editarResposta() {
        if (isset($_GET['editarquestao'])) {
            $respostaVO = new RespostaVO($_GET['editarquestao'], "", "", "", $_POST['resposta'], "", $_POST['codigo']);
            $db = new RespostaDAO();
            $db->update($respostaVO);
        }
    }

    function getRespostaByID() {
        if (isset($_GET['editar'])) {
            $db = new RespostaDAO();
            return $db->selectRespostaByID($_GET['editar']);
        }
    }

    /**
     * Método para mostrar o conteúdo de uma questão caso ela exista no banco,
     * caso contrário mostra uma tela de erro
     * @param type $questao questaoVO objeto que contem as informações da questão que esta
     * sendo mostrada
     */
    function mostraDiscussao($questao) {
        $listaRespostas = $this->getRespostasByQuestao();
        $numresp = $this->getQuantidadeRespostas();
        $forumview = new ForumView();
        echo ' <div id="main" class="texto" > <!-- div main-->

            <img id="logo" src="imgs/logo.png" alt="logo">
            <p id="forum"><br><br></p>
            <div  class="panel panel-primary">
                <div class="panel-heading"><h4>';

        if ($questao) {
            $botoes = "<div class='direita'>
                         <button class=' btn btn-success'  data-toggle='modal' data-target='#ModalEditarQuestao".$questao->getQuestaoID()."'>
                            <span class='glyphicon glyphicon-edit'></span>
                            Editar
                        </button>
                        <button class=' btn btn-danger'  data-toggle='modal' data-target='#modalAviso".$questao->getQuestaoID()."'>
                            <span class='glyphicon glyphicon-remove'></span>
                            Excluir
                        </button>              
                    </div>";
            $autor = $questao->getAutor();
            echo $questao->getTitulo() . "";
            echo "</h4></div> <div class = 'panel-body'> ";
            if (!empty($_SESSION['nome'])) {
                if ($_SESSION['userID'] == $questao->getUserID()) {
                    echo $botoes;
                }
            }
            echo $questao->getDescricao() . "
                        <br>
                        " . $questao->getCodigoFormatado() . "
                    <hr>Por " . $autor . ", em " . $questao->getDataQuestao() . "  
                    <p class = 'texto'>  </p>";
        } else {
            echo "Não foi possível encontrar questão";
        }
        echo"</div>
            </div>";

        if ($questao) {
            echo '<div  class="panel panel-primary">
                <div class="panel-heading">
                    <h4>  ' . $numresp . ' Respostas</h4>
                </div>
                <div class = "panel-body">';

            $this->buttonNovaResposta();

            if (!empty($listaRespostas)) {
                foreach ($listaRespostas as &$resposta) {
                    $forumview->mostraResposta($resposta);
                }
            }
            echo'</div></div>';
        }
    }

}
