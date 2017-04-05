<?php
session_start();
require '/../vendor/autoload.php';
$sessao = new ControllerSessao();
$forum = new ControllerForum();
$modal = new ModalsView();
$forumview = new ForumView();

$forum->testaExcluir();
$sessao->logOut();
$forum->insertNovaQuestao();
$listaQuestoes = $forum->getQuestoes();

// Menu Superior e Menu Lateral
$pagina = new PageView();
$pagina->showHeadHTML();
$pagina->showMenuSuperior();
$pagina->showMenuLateral();
?>

    <div id="main" class="texto" > <!-- div main-->

            <img id="logo" src="imgs/logo.png" alt="logo"></img>
            <p id="forum"><br><br></p>
            <div  class="panel panel-primary">
                <div class="panel-heading"><h4>Fórum</h4></div>
                <div class="panel-body">
                    <p class="texto"> O espaço do fórum é reservado para os usuários elaborarem questões que
                        serão respondidas por outras pessoas, somente quem é usuário pode elaborar questões, se você ainda
                        não possui uma conta <a href="signup.php">Crie agora mesmo.</a>
                    </p>
                    <?php
                    $forum->buttonNovaQuestao();
                    $modal->showModalQuestao();
                    ?>



                </div>
            </div>
        <div class="modal fade" id="ModalQuestao" tabindex="-1" role="dialog"
             aria-labelledby="myModalLabel" aria-hidden="true">
            <div class="modal-dialog modal-lg">
                <div class="modal-content">
                    <!-- Modal Header -->
                    <div class="modal-header">
                        <button type="button" class="close"
                                data-dismiss="modal">
                            <span aria-hidden="true">&times;</span>
                            <span class="sr-only">Close</span>
                        </button>
                        <h4 class="modal-title" id="myModalLabel">
                            Criar uma nova Questão
                        </h4>
                    </div>

                    <!-- Modal Body -->
                    <div class="modal-body">

                        <form action="forum.php?inserir=true" role="form" method="POST">
                            <div class="form-group">
                                <label for="titulo">Título da Questão</label>
                                <input type="text" name="titulo" class="form-control" maxlength="127"
                                       id="titulo" placeholder="Título da Questão" required="required"/>' ;
                                echo "<input type='button' class=' btn btn-primary' value='Inserir Código' onclick=insertText('descricao', '<pre><code></code></pre>')>";
                                echo ' <label for="descricao">Descrição do problema/questão (Opcional)</label>
                                <textarea name="desc" id="descricao" maxlength="2000"
                                          placeholder="Escreva aqui a descrição de sua questão (Opcional)" class="form-control"></textarea>
                            </div>
                            <button type="submit"  class="btn btn-success btn-block">Criar Questão</button>
                        </form>


                    </div>

                    <!-- Modal Footer -->
                    <div class="modal-footer">
                        <button type="button" class="btn btn-default"
                                data-dismiss="modal">
                            Cancelar
                        </button>
                    </div>
                </div>
            </div>
        </div>

            <div  class="panel panel-primary">
                <div class="panel-heading"><h4>Questões mais recentes</h4></div>
                <div class="panel-body">
                    <?php
                    if (!empty($listaQuestoes)) {
                        foreach ($listaQuestoes as &$questao) {
                            $forumview->mostraQuestao($questao);
                        }
                    }
                    ?>


                   
                </div>
            </div> <!-- div main-->
    </body>
</html>