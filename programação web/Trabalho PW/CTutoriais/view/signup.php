<?php
require '/../vendor/autoload.php';
session_start();
$sessao = new ControllerSessao();
$validador = new ControllerValidacoes();

$usernameUnico = false;
$emailUnico = false;
$usernameValido = false;
$temdados = false;

if (isset($_POST['submit'])) {
    $temdados = true;

    $nome = $_POST['nome'];
    $email = $_POST['email'];
    $username = $_POST['username'];
    $senha = $_POST['senha'];

    $emailUnico = $validador->isEmailUnico($email);
    $usernameUnico = $validador->isUsernameUnico($username);
    $usernameValido = $validador->isUsernameValido($username);
    
    if($usernameUnico && $emailUnico && $usernameValido){
        $sessao->criarConta($nome, $email, $senha, $username);
    }   
}
$sessao->redirect();

// Menu Superior e Menu Lateral
$pagina = new PageView();
$pagina->showHeadHTML();
$pagina->showMenuSuperior();
$pagina->showMenuLateral();
?>


        <br><br><br><br>
        <div id="divprincipal">
            <p id="divtitle">
                Criar Conta
            </p>
            <hr>

            <div id="formcontent">
                <?php                
                    $errmessage = $validador->setErros($temdados, $usernameUnico, $emailUnico, $usernameValido);
                    if($errmessage == ""){
                        $sessao->redirect();
                    }else{
                        echo $errmessage;
                    }
                ?>

                <form action="signup.php" method="POST"> 
                    <p> </p>
                    <input type="text" name="nome" placeholder="Nome" required="required" maxlength="64">
                    <br><br>
                    <input type="email" name="email" placeholder="usuario@domínio" required="required" maxlength="64">
                    <br><br>
                    <input type="text" name="username" placeholder="Username" required="required" maxlength="64">
                    <br><br>  
                    <input type="password" name="senha" placeholder="Senha" required="required" maxlength="64">
                    <br><br>
                    <input type="submit" name="submit" value="Criar Conta">
                    <br>
                    Já possui uma conta? <a href="login.php"> Login</a>
                </form>

            </div>
        </div>
        <br><br><hr>

    </body>
</html>