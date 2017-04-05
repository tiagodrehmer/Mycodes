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
    <img id="logo" src="imgs/logo.png" alt="logo"></img>

    <p id="compilando"><br><br></p>
    <div  class="panel panel-primary">
        <div class="panel-heading"><h4>Criando e compilando seu primeiro programa em C</h4></div>
        <div class="panel-body">
            <p class="texto">	 

                Para começar vamos utilizar um código simples, que ira mostrar para o usuario a mensagem "Hello world!", para isso crie um arquivo com a extensão .c, e insira o código listado abaixo;
            </p>

            <pre><code>
#include &lt;stdio.h&gt;

int main(){
	printf("Hello world!");
	return 0;
}</code></pre>
            <p class="texto">	 
                Para compilar o seu codigo, você precisa estar no mesmo diretório que o "arquivo.c":<br>
                <kbd>user@Aspire-5750:~/Praticas/Exercicio7$.</kbd>	<br>
                Para chegar ao diretório desejado, utilize o comando "cd": <br>
                <kbd>user@Aspire-5750:~$ cd Praticas/</kbd><br>
                <kbd>user@Aspire-5750:~/Praticas$ cd Exercicio7/</kbd><br>
                <kbd>user@Aspire-5750:~/Praticas/Exercicio7$</kbd><br>
                Pronto, agora que você está na pasta onde o "arquivo.c" se encontra, use o seguinte comando para compilar o programa:<br>
                <kbd>gcc -o meuprograma arquivo.c</kbd><br>
                Se estiver tudo certo, você ja pode executar seu programa utilizando o comando:<br>
                <kbd>./meuprograma</kbd><br>
                <kbd>Hello world 	!</kbd>

            </p>


        </div>
    </div>
    <div>
        <a href="index.php">
            <button type="button" class="btn btn-success" id="botaoPrevious"  ">&#8592;Home</button>
        </a>
        <a href="Variaveis.php">
            <button type="button" class="btn btn-success" id="botaoNext">Variáveis&#8594;</button>
        </a>
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