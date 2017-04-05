<?php
require '/../vendor/autoload.php';
session_start();

$logado = false;
$temdados = false;
$sessao = new ControllerSessao();
// ao clicar em logout, encerra a sessão
if (isset($_GET['sair'])) {
    $sessao = unserialize($_SESSION["sessao"]);
    $sessao->logOut();
}

//ao clicar em login, inicia a sessão
if (isset($_POST['submit'])) {
    $temdados = true;
    $username = $_POST['username'];
    $senha = $_POST['senha'];

    $validador = new ControllerValidacoes();
    if ($validador->verificaLogin($username, $senha)) {
        $sessao = new ControllerSessao();
        $db = new UsuarioDAO();
        
        $user = $db->selectByLogin($username, $senha);
        $sessao->logIn($user);
        $logado = true;
    } else {
        $logado = false;
    }
}
$sessao->redirect();

// Menu Superior e Menu Latera
$pagina = new PageView();
$pagina->showHeadHTML();
$pagina->showMenuSuperior();
$pagina->showMenuLateral();
?>


            <br><br><br><br>
            <div id="divprincipal">
                <p id="divtitle">
                    Login
                </p>
                <hr>

                <div id="formcontent">
                    <?php
                        if ($logado) {
                        echo "<div id='success' > "
                                . "<p id='successmessage'>Login realizado com sucesso &excl; </p>"
                            . "</div>";
                        }else if(!$logado && $temdados ){
                        echo "<div id='err' > "
                                . "<p id='errmessage'>Username ou senha inválido &excl; </p>"
                            . "</div>";
                        }
                    ?>
                <form action="login.php" method="POST"> 
                    <p> </p>
                    <input type="text" name="username" placeholder="Username ou email" required="required" maxlength="64">
                    <br><br>
                    <input type="password" name="senha" placeholder="Senha" required="required" >
                    <br><br>  
                    <input type="submit" name="submit" value="Log in" maxlength="64">
                    <br>
                    Não possui uma conta? <a href="signup.php">Criar Conta</a>
                </form>

            </div>
        </div>
        <br><br><hr>
    </body>
</html>