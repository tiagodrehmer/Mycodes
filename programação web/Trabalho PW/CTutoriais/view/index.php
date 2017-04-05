<?php
session_start();
require '/../vendor/autoload.php';
$sessao = new ControllerSessao();
$sessao->logOut();
$sessao->excluir($sessao);
// Menu Superior e Menu Latera
$pagina = new PageView();
$pagina->showHeadHTML();
$pagina->showMenuSuperior();
$pagina->showMenuLateral();
?>


        <div id="main" class="texto" > 
            <img id="logo" src="imgs/logo.png" alt="logo" ></img>
            <p id="home"><br><br></p>
            <div  class="panel panel-primary">
                <div class="panel-heading"><h4>C Tutoriais</h4></div>
                <div class="panel-body">
                    <p id="tutoriais" class="texto">	 
                        Bem-vindo ao site C Tutoriais, se você estava procurando por dicas e tutoriais para programar em C, aqui você vai encontrar uma série de tutoriais sobre a linguagem que podem te ajudar conhecer melhor a programação em C. O site também conta com exercícios de fixação a cada final de um tópico.
                    </p>
                </div>
                <h3 >Tópicos</h3>
                <a href="Conceitos.php"><h3>Conceitos Básicos </h3></a>
                <a href="Conceitos.php#criando"><h4> - Criando e Compilando</h4></a>
                <br>
                <a href="Variaveis.php"><h3>Variáveis </h3></a>
                <a href="Variaveis.php#variaveis"><h4> - Variáveis e seus Tipos</h4></a>	
                <a href="Variaveis.php#utilizando"><h4> - Utilizando Variáveis</h4></a>
                <br>
                <a href="Operadores.php" ><h3>Operadores Aritméticos e Lógicos</h3></a>		
                <a href="Operadores.php#lista"><h4> - Lista de Operadores</h4></a>		
                <a href="Operadores.php#estrutura"><h4> - Estrutura Seletiva if e else</h4></a>	
                <br>
                <a href="Controladores.php"><h3>Controladores de Fluxo</h3></a>		
                <a href="Controladores.php#while"><h4> - While</h4></a>		
                <a href="Controladores.php#dowhile"><h4> - Do While</h4></a>
                <a href="Controladores.php#for"><h4> - For</h4>	</a>	
                <a href="Controladores.php#switch"><h4> - Switch</h4></a>
                <br>
                <a href="Funcoes.php"><h3>Funções</h3></a>		
                <a href="Funcoes.php#criando"><h4> - Criando Funções</h4>	</a>	
                <a href="Funcoes.php#recursiva"><h4> - Funções Recursivas</h4></a>

                <div class="panel-body">
                    <a href="Conceitos.php"><button type="button" class="btn btn-success" id="botaoMenu" href="Variaveis.php">
                            Começe a Aprender Agora!
                        </button> 
                    </a>
                </div>
            </div>
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
            <img id="logo_pe" src="imgs/logo.png" alt="logorodapé">
        </footer>		 
    </body>
</html>