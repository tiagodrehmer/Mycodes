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
            <img id="logo" src="imgs/logo.png" alt="logo">

            <p id="criando"><br><br></p>
            <div class="panel panel-primary">
                <div class="panel-heading"><h4>Criando Funções</h4></div>
                <div class="panel-body">
                    <p class="texto">
                        Uma função na linguagem C, nada mais é que um bloco de código. Um função pode ser declarada como varios tipo: float, int, double, bool, void, char...
                        O tipo de função bool, nescessita de um cuidado especial. Pois precisa ser declarado uma biblioteca no cabeçalho do codigo: #include &lt;bool&gt;
                        No final da função, exite um comando "return", que ser para retornar alguma coisa(do mesmo tipo da função, ex: int). As funções do tipo void, nao possuem esse recurso, elas simplesmente terminam e voltam para o local onde ela foram "chamadas", sem retornar nenhum valor.
                        As funções podem receber variaveis ou valores como parâmetros, que pode ser de qualquer tipo, independentes do tipo da função.
                        A "main" é a principal função do seu código. <br> Exemplo:  
                    </p>
                    <pre><code>
#include &lt;stdio.h&gt;
int main(){
	int x, y;

	printf("Digite o primeiro número:\n");
	scanf("%d", &x);

	printf("Digite o segundo número:\n");
	scanf("%d", &y);

	printf("%d", x + y);

	return 0;
}
</code></pre>

                    <p class="texto">
                        Mas e se quisermos calcular outra vez? Teriamos que repetir o "printf("%d", x + y)"?<br>
                        Com o auxilio de uma outra função nao seria nescessário, poderiamos simplesmente criar uma função do tipo inteiro para retornar a soma.
                        <br> Exemplo:  
                    </p>
<pre><code>
#include &lt;stdio.h&gt;
int soma(int valor_1, int valor_2){
	return (valor_1 + valor_2);
}

int main(){
 		int x, y;

 		while(1){//laço infinito, so para mostra a reutilização da função soma
			printf("Digite o primeiro número:\n");
			scanf("%d", &x);

			printf("Digite o segundo número:\n");
			scanf("%d", &y);

	 		printf("%d", soma(x, y));
		} 		
 		return 0;
 	}
</code></pre>                    <p class="texto">
                        No código é feito uma soma inumeras vezes, reaproveitando o código da função soma.
                        Podemos usar funções para usar em uma condição.
                        Ex: Precisamos de um programa que identifique se um número é impar ou par:
                    </p>

                    <pre><code>
#include &lt;stdio.h&gt;
#include &lt;bool&gt; 

bool identificador(int numero){

	//se for par
	if(numero%2 == 0){
		//verdade
		return true;
	}else{
		//falso
		return false;
	}
}

int main(){

	int numero;

	printf("Digite um número:\n");
	scanf("%d", &numero);

	//se a funcao for verdade
	if(identificador(numero)){
		printf("PAR");
	}else{
		printf("IMPAR");
	}

	return 0;
}
</code></pre>


                    <p class="texto">
                        Quando o usuário digita um valor, ele é armazena na variavel 'numero' e logo depois e passado para a função 'identificador'. Observer como a chamada da função esta dentro de um 'if', se a função retornar verade(true), então oque esta dentro das chaves do 'if' será executada, se não será executado o código de dentro das chaves do 'else'.
                    </p>

                </div>
            </div>

            <p id="recursiva"><br><br></p>
            <div  class="panel panel-primary">
                <div class="panel-heading"><h4>Funções Recursivas</h4></div>
                <div class="panel-body">
                    <p class="texto">
                        Uma função pode ser chamada dentro da própria função, criando assim uma recursividade.
                        Ex: Precisamos criar um programa que tenha um contador simples usando recusividade.
                    </p>


                    <pre><code>
#include &lt;stdio.h&gt; 
int contador(int numero, int total){
	if(numero < total){
		printf("%d", numero);
		contador((numero+1), total);
	}
	return 0;
}

int main(){

	int inicio, fim;

	printf("Digite um numero inicial")
	scanf("%d", &inicio);

	printf("Digite ate quanto deve ser contado");
	scanf("%d", &fim);

	contador(inicio, fim);

	return 0;
}</code></pre>
                    <p class="texto">
                        No código a função 'contador' é chamada apenas uma vez dentro da função principal. Logo dentro dela mesma, ela fica sendo chamada até que a condição do 'if' não seja mais verdade.
                    </p>
                </div>
            </div>
            <div class="panel panel-primary">
                <div class="panel-heading"><h4>Questões:</h4></div>
                <div class="panel-body">
                    <table id = "questao">
                        <tr>
                            <th id = "enunciado"><h3><p>1 - Oque será mostrado na tela?</p>
                              
                                    <pre><code>
int teste(int numero){
	
	if(numero > 4){
		return 1;
	}else{
		return 0;
	}
}

int main(){

	int x = 5;

	if(teste(x)){
		printf("Verdade");
	}else{
		printf("Falso")
	}

}

}</code></pre></h3></th>
                        </tr>
                        <tr>
                            <th><button id = "correta1" onclick="teste_correto(this, 0, 1)">Verdade</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 1)">Falso</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 1)">1</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 1)">Nenhum dos anteriores</button></th>
                        </tr>
                    </table>
                    <hr>
                    <table id = "questao">
                        <tr>
                            <th id = "enunciado"><h3><p>2 - Qual será o valor de 'x'?</p>
                                    <pre><code>
int calcula(int numero){
	
	if(numero > 10){
		calcula(numero - 1);
	}else{
		return numero;
	}
}

int main(){

	int x = 15;

	x = teste(x);
	printf("%d", x);
	
	return 0;
}</code></pre></h3></th><
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 2)">15</button></th>
                        </tr>
                        <tr>
                            <th><button id = "correta2" onclick="teste_correto(this, 0, 2)">10</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 2)">0</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 2)">100</button></th>
                        </tr>
                    </table>
                    <hr>

                    <table id = "questao">
                        <tr>
                            <th id = "enunciado"><h3><p>3 - Qual será o valor de 'x'?</p>
                                    <pre><code>
int valor_y(int numero){
	
	return 3
}

int valor_x(int numero){
	
	return 150;
} 

int main(){

	int x = 10, y = 2;

	x = valor_x(x);
	y = valor_y(y);

	printf("%d\n", (x/y))
	
	return 0;
}</code></pre></h3></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 0, 3)">50</button></th>
                        </tr>
                        <tr>
                            <th><button id = "correta3" onclick="teste_correto(this, 1, 3)">150</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 3)">3</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 3)">5</button></th>
                        </tr>
                    </table>
                </div>
            </div>
            <div>
                <a href="Controladores.php">
                    <button type="button" class="btn btn-success" id="botaoPrevious"  ">&#8592;Controladores</button>
                </a>
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
            <img id="logo_pe" src="imgs/logo.png" alt="logo"></img>
        </footer>
    </div>
</body>
</html>