<?php
require '/../vendor/autoload.php';
session_start();
$validador = new ControllerValidacoes();
$modal = new ModalsView();
$sessao = new ControllerSessao();
$sessao->logOut();
// Menu Superior e Menu Lateral
$pagina = new PageView();
$pagina->showHeadHTML();
$pagina->showMenuSuperior();
$pagina->showMenuLateral();
?>

        <div id="main" class="texto" > 
            <div id="divprincipal">
                <p id="divtitle">
                    Edição de Informações
                </p>
                <hr>
                <div id="formcontent">
                    <form action="infousuario.php?update=true" method="POST"> 
                        <p></p>
                        <?php
                        echo "<h4>Nome:</h4> <input type='text' name='nome' value='" . $_SESSION['nome'] . "' required='required'> 
                                 <h4>Email:</h4> <input type='email' name='email' value='" . $_SESSION['email'] . "'required='required' >
                                 <h4>Username:</h4> <input type='text' name='username' value='" . $_SESSION['username'] . "' required='required'>
                                 <h4>Trocar Senha</h4>
                                 <input type='password' placeholder='Senha Atual' name='senhaatual' > 
                                 <input type='password' placeholder='Senha Nova' name='senhanova'> 
                                 <input type ='submit' name ='submit' value = 'Salvar Alterações'>
                                 <br><br>";
                        ?>
                    </form>
                    <?php
                    $modal->showModalAviso("Excluir Minha Conta", "Tem certeza que deseja excluir sua conta?");
                    ?>
                    <button class='btn btn-danger center-block' data-toggle='modal' data-target='#modalAviso'>Excluir minha Conta</button>

                </div>
                </body>
                </html>