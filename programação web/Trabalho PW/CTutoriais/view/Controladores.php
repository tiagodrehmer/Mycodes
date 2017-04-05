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

            <p id="while"><br><br></p>
            <div  class="panel panel-primary">
                <div class="panel-heading"><h3>While</h3></div>
                <div class="panel-body">
                    <h4>Repetir e repetir: o que são e para que servem os laços em C</h4>
                    <p>
                        Repetir é uma das coisas mais importantes na programação. Na verdade, elas não se repetem indefinidamente, elas se repetem dependendo dos testes que fazem.

                        Por exemplo, seu computador faz várias repetições para saber se você está conectado a internet.
                        Se esse teste der resultado positivo, nada acontece.
                        Porém, se ele testar e ver que a conexão não existe mais, ele manda uma mensagem dizendo que você perdeu a conexão.

                        Fazer testes você já está careca de saber.
                        Porém, como faria todos esses testes? Colocaria um if else a cada segundo, durante 1h?
                        E se o usuário passar 2h conectado? Ou 1 dia?

                        E se você fosse contratado para criar um programa em C que diz se cada aluno em uma sala de aula passou.
                        Se essa sala tem 30 alunos, você vai criar 30 testes condicionais?
                        E se a sala tiver 60 alunos? Ou se você for contratado para testar as notas de todos os 2mil alunos de uma escola?
                        2mil blocos de IF ELSE?

                    <h4>Exemplo:</h4>
                    <br>
                    Primeiro declaramos uma variável, e inicializamos ela com o valor inicial, que é 1.
                    Logo em seguida ,fazemos com que o while dê um printf, mostrando o valor dessa variável ENQUANTO ela for MENOR ou IGUAL a 10.
                    Após imprimir o número 10, a variável é incrementada e passa a ter valor 11.
                    Como 11 não é menor ou igual a 10, o laço recebe valor lógico FALSE e termina sua execução.

                    <pre><code>
#include &lt;stdio.h&gt;

int main(void)
{
        int numero=1;

        while(numero <= 10)
        {
            printf("%d\n", numero);
            numero++;
        }

}
                    </pre></code>

                    </p>      	
                </div>
            </div>


            <p id="dowhile"><br><br></p>
            <div  class="panel panel-primary">
                <div class="panel-heading"><h3>Do-While</h3></div>
                <div class="panel-body">
                    <p>
                        Se você notar bem, em nosso artigo sobre o laço WHILE, pode reparar que esse laço só roda se a condição for verdadeira.
                        Se essa condição for uma variável ou comparação, por exemplo, devemos sempre nos certificar que, inicialmente, essa condição vai ser verdadeira.

                        Geralmente inicializamos as variáveis ou pedimos algum dado pro usuário, tudo para nos certificarmos que o programa vai entrar no WHILE, o que as vezes pode ser um pouco incômodo e nada eficiente.

                        O que o laço DO WHILE faz é executar, PELO MENOS UMA VEZ, o que está dentro dele e só ao final da execução é que ele faz o teste, usando o velho e conhecido laço WHILE.
                        Ou seja, temos a garantia que o laço vai ser executado uma vez, sempre precisar inicializar variável ou pedir dados ao usuário antes do WHILE (pois fazer isso pode bagunçar o sistema).

                        E qual a diferença do laço DO WHILE para o WHILE ?
                        Bom, para o WHILE rodar é necessário que a condição seja sempre verdadeira.
                        Logo, se ela for inicialmente FALSE, o looping while nunca irá rodar.

                        Já o DO WHILE vai rodar sempre, ao menos uma vez, mesmo que a condição existente no WHILE seja falsa (se for falsa, vai rodar só uma vez e termina).

                        A sintaxe desse comando é a seguinte

                    </p>

                    <pre><code>
do
{
   //código que
   //será repetido
   //aqui

} while (condição);
                    </pre></code>
                    <p>
                        Vale realçar aqui que esse laço, diferente dos outros, POSSUI PONTO E VÍRGULA no final! Não se esqueçam!
                        No mais, não há segredos, é igual ao WHILE, a lógica é a mesma. Sabendo bem o WHILE, saberá bem o laço DO WHILE.
                    </p>
                </div>
            </div>


            <p id="for"><br><br></p>
            <div  class="panel panel-primary">
                <div class="panel-heading"><h3>For</h3></div>
                <div class="panel-body">

                    <h4>Estrutura de repetição for</h4>
                    <p>

                        Denominamos “laço” (loop em inglês) a uma estrutura de repetição.

                        As estruturas de repetição, executam a repetição de um conjunto de instruções enquanto uma determinada condição é verdadeira.

                        Em linguagem C, existem três estruturas de repetição, são elas: for, while e do…while.

                        Cada uma destas estruturas tem a sua particularidade em termos de funcionamento.

                        Veremos cada uma delas em artigos separados no blog, iniciando pelo for.
                    </p>

                    <pre><code>
//Exemplo1: Programa usando loop for em C
#include &lt;stdio.h&gt;
int main(void)
{
  int contador; //variável de controle do loop
  for(contador = 1; contador <= 10; contador++)
  {
      printf("%d ", contador);
  }
  getch();
  return(0);
}
                    </pre></code>
                    <h5>Explicação:</h5>
                    <p>
                        <br>
                        Neste primeiro exemplo podemos observar três coisas sobre o funcionamento da estrutura de repetição for:
                        <br><br>
                        Primeiramente o contador foi inicializado com um valor determinado
                        <br><br>
                        Depois testamos se a condição que envolve o contador é verdadeira (ou seja  se contador <= 10), em caso afirmativo, a repetição continua; caso – contrário,  ela será encerrada.
                        <br><br>
                        A cada nova repetição a variável do contador foi incrementada

                    </p>
                </div>
            </div>

            <p id="switch"><br><br></p>
            <div  class="panel panel-primary">
                <div class="panel-heading"><h3>Switch</h3></div>
                <div class="panel-body">
                    <p class="texto">
                        SWITCH é um comando em C que serve para fazer testes condicionais, testando igualdades, onde podemos usar várias opções de comparações.
                        <br>
                        Assim como o nosso conhecido par IF ELSE, o comando switch também serve para fazer testes condicionais
                        <br>
                        Imagine que você quer testar um valor digitado pelo usuário com 10 números.
                        Você poderia fazer com IF, tranquilamento.
                        Porém, seu código iria ficar enorme e você teria que digitar várias vezes IF (...), IF(...)
                        <br>
                        Visando reduzir isso, vamos aprender como usar o comando switch, que iremos usar várias vezes durante nossa apostila de C, para criar menus, por exemplo, onde iremos exibir uma série de opções, o usuário vai escolher uma e vamos saber qual opção ele escolheu através de um comando switch.
                        <br>
                        A sintaxe do switch é a seguinte:  
                        <br>
                    </p>
                    <pre><code>
			switch( opção )
			{
			    case opção1:
			            comandos caso a opção 1 tenha sido escolhida
			            break;
			    
			    case opção2:
			            comandos caso a opção 2 tenha sido escolhida
			            break;
			    
			    case opção3:
			            comandos caso a opção 3 tenha sido escolhida
			            break;
			    
			    default:
			            comandos caso nenhuma das opções anteriores tenha sido escolhida
			}
			}
			</code></pre>	      	
                </div>
            </div>

            <div class="panel panel-primary">
                <div class="panel-heading"><h4>Questões:</h4></div>
                <div class="panel-body">
                    <table id = "questao">
                        <tr>
                            <th id = "enunciado"><h3><p>1 - Qual será o valor de 'cont'?</p>
                                    <pre><code>
int main(){

	int x = 50;
	int cont = 0;
	while(x < 100){
		x = x + 2;
		cont++;
	}	

	printf("%d", cont);
	return 0;
}</code></pre></h3></th>
                        </tr>
                        <tr>
                            <th><button id = "correta1" onclick="teste_correto(this, 1, 1)">50</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 1)">100</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 0, 1)">25</button></th>
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
int main(){

	int x = 0;
	int cont = 0;
	while(cont < 150){
		if((cont % 2) == 0){
			x++;
		}
		
		cont++;
	}	

	printf("%d", x);
	return 0;
}</code></pre></h3></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 2)">0</button></th>
                        </tr>
                        <tr>
                            <th><button id = "correta2" onclick="teste_correto(this, 0, 2)">75</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 2)">25</button></th>
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
int main(){

	int x = 0;
	int cont = 25;

	while(cont < 78){
		x = x + 2;
		cont++;
	}	

	printf("%d", x);
	return 0;
}</code></pre></h3></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 3)">25</button></th>
                        </tr>
                        <tr>
                            <th><button id = "correta3" onclick="teste_correto(this, 1, 3)">78</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 0, 3)">106</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 3)">Nenhuma das alternativas acima</button></th>
                        </tr>
                    </table>		
                </div>
            </div>
            <div>
                <a href="Operadores.php">
                    <button type="button" class="btn btn-success" id="botaoPrevious"  ">&#8592;Operadores</button>
                </a>
                <a href="Funcoes.php">
                    <button type="button" class="btn btn-success" id="botaoNext">Funções&#8594;</button>
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
            <img id="logo_pe" src="imgs/logo.png" alt="logo">
        </footer>
    </body>
</html>