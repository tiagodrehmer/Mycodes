<?php
session_start();
require '/../vendor/autoload.php';
$sessao = new ControllerSessao();
$forum = new ControllerForum();
$modal = new ModalsView();
$pagina = new PageView();
$forumview = new ForumView();

$sessao->logOut();

$forum->editarResposta();
$forum->removerResposta();
$forum->insertNovaResposta();
$forum->UpdateBanco();

$questao = $forum->getQuestaoByID();
$modal->showModalAvisoQuestao("Excluir minha Questão", "Tem certeza que deseja excluir sua Questão?", $questao->getQuestaoID());


    //cabeçalho da página
    $pagina->showHeadHTML();
    
    //Menu Superior e Menu Lateral 
    $pagina->showMenuSuperior();
    $pagina->showMenuLateral();
    
    //modal que permite o usuário escrever uma resposta
    $modal->showModalResposta();
    $modal->showModalEditarQuestao($questao);
    $modal->showModalAvisoQuestao("Excluir minha Questão", "Tem certeza que deseja excluir sua Questão?", $questao->getQuestaoID());
    $forum->mostraDiscussao($questao);
    
    ?>
    </div> <!-- div main-->
</body>
</html>