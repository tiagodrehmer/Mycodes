<?php
require '/../vendor/autoload.php';
session_start();
$sessao = new ControllerSessao();
$sessao->logOut();
// Menu Superior e Menu Latera
$pagina = new PageView();
$pagina->showHeadHTML();
$pagina->showMenuSuperior();
$pagina->showMenuLateral();
?>
        
        <div id="main" class="texto" > 
            <img id="logo" src="imgs/logo.png" alt="logo" ></img>
            <p id="contato"><br><br></p>
            <div  class="panel panel-primary">
                <div class="panel-heading"><h3>Endereços para Contato</h3></div>
                <div class="panel-body">
                    <p class="texto">	
                    <h4>E-mail:	    contato@ctutoriais.com.br</h4>
                    <h4>Telefone:	 (55)1234-5678</h4>
                    </p>
                </div>
                <br>
                <br>
                <br>
                <hr>
                <footer>
                    <p id = "contato_pe">Contatos</p>
                    <p id = "contato_pe">E-mail: tiagodrehmer@hotmail.com</p>
                    <p id = "contato_pe">E-mail: marcelocm97@hotmail.com</p>
                    <p id = "contato_pe">E-mail: leo-brondani@hotmail.com</p>
                    <img id="logo_pe" src="imgs/logo.png" alt="logo"></img>
                </footer>
            </div>
        </div>
    </body>
</html>