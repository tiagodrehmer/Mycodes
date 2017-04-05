<?php
require '/../vendor/autoload.php';
session_start();
$validador = new ControllerValidacoes();
$modal = new ModalsView();
$sessao = new ControllerSessao();
$sessao->logOut();
$sessao->testaAcesso($_GET["questao"]);

$forum = new ControllerForum();
$questao = $forum->getQuestaoByID();
// Menu Superior e Menu Latera
$pagina = new PageView();
$pagina->showHeadHTML();
$pagina->showMenuSuperior();
$pagina->showMenuLateral();
?>




        <div id="main" class="texto" > 
            <div id="divprincipal">
                <p id="divtitle">
                    Editar Questão
                </p>
                <hr>
                <div id="formcontent">
                    <form action="discussao.php?update=true&questao=<?php echo $questao->getQuestaoID();?>" method="POST"> 
                        <p></p>
                        <?php
                        echo "<h4>Titulo:</h4> <input type='text' name='titulo' value='" . $questao->getTitulo() . "' required='required' maxlength='127'> 
                              <h4>Descricao:</h4> <textarea id='descricao' name='descricao' required='required' maxlength='2000' class='form-control'>" . $questao->getDescricao() . "</textarea>
                                 <input type ='submit' name ='submit' value = 'Salvar Alterações'>
                                 <br><br>";
                        ?>
                    </form>
                    <?php

                    ?>
                    <!--$modal->showModalAvisoQuestao("Excluir minha Questão", "Tem certeza que deseja excluir sua Questão?", $questao->getQuestaoID());-->
                    <!--<button class='btn btn-danger center-block' data-toggle='modal' data-target='#modalAviso'>Excluir Questao</button>-->

                </div>
    </body>
</html>

