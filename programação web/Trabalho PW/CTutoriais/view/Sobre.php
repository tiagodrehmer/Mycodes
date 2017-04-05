<?php
session_start();
require '/../vendor/autoload.php';
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
            <p id="sobre"><br><br></p>
            <div  class="panel panel-primary">
                <div class="panel-heading"><h4>Sobre</h4></div>
                <div class="panel-body">
                    <p class="texto">	
                        O site C Tutoriais foi desenvolvido por acadêmicos do curso de Ciência da Computação, como um trabalho envolvendo a disciplina de Programação Web - 2016/02.
                    </p>
                </div>
                <br><br><br><hr>
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