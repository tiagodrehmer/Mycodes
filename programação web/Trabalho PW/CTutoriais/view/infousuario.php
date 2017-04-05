<?php
require '/../vendor/autoload.php';
session_start();
$sessao = new ControllerSessao();
$sessao->logOut();
$atualizou = FALSE;
$atualizaSenha = FALSE;
$errosenha = FALSE;

if (isset($_GET['update'])) {
    $atualizou = TRUE;
    $validador = new ControllerValidacoes();

    if ($validador->hasEmailChanged()) {
        $emailUnico = $validador->isEmailUnico($_POST['email']);
    } else {
        $emailUnico = TRUE;
    }

    if ($validador->hasUsernameChanged()) {
        $usernameUnico = $validador->isUsernameUnico($_POST['username']);
    } else {
        $usernameUnico = TRUE;
    }

    if (!empty($_POST['senhaatual'])) {
        
        $senhasIguais = $validador->isSenhasIguais();
        if (!empty($_POST['senhanova']) && $senhasIguais){
            $atualizaSenha = TRUE;
        }else{
            $errosenha = TRUE;
        }
        
    } else {
        $atualizaSenha = FALSE;
    }

    $usernameValido = $validador->isUsernameValido($_POST['username']);
    if ($usernameUnico && $emailUnico && $usernameValido) {
        $sessao->atualizarConta($atualizaSenha);
    }
}
// Menu Superior e Menu Latera
$pagina = new PageView();
$pagina->showHeadHTML();
$pagina->showMenuSuperior();
$pagina->showMenuLateral();
?>


        <div id="main" class="texto" > 
            <div id="divprincipal">
                <p id="divtitle">
                    Informações do Usuário
                </p>
                <hr>

                <div id="formcontent">
                    <?php
                    if ($atualizou && $emailUnico && $usernameUnico && $usernameValido && !$errosenha) {
                        echo "<div id='success' > "
                        . "<p id='successmessage'>Edição realizada com sucesso &excl; </p>"
                        . "</div>";
                    }else if($errosenha){
                        echo " <div id='err'>
                                   <p id='errmessage'> Não foi possível atualizar a senha &excl; </p>
                               </div>";
                    }
                    ?>
                    <form action="editarinfo.php" method="POST"> 
                        <p></p>
                        <?php
                        if ($atualizou) {
                            $errmessage = $validador->setErros($atualizou, $usernameUnico, $emailUnico, $usernameValido);
                            if ($errmessage != "") {
                                echo $errmessage;
                            }
                        }
                        echo "<h4>Nome:</h4>  <h3> " . $_SESSION['nome'] . " </h3>
                                <br>
                                <h4>Email:</h4>  <h3> " . $_SESSION['email'] . " </h3>
                                <br>
                                <h4>Username:</h4> <h3> " . $_SESSION['username'] . " </h3>
                                <br><br>
                                <input type ='submit' name ='submit' value = 'Editar minhas informações'>
                                <br>";
                        ?>
                    </form>

                </div>
            </div>
            <br><br><hr>
        </div>
    </body>
</html>