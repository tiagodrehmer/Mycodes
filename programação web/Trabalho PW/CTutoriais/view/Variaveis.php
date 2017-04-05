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

            <p id="variaveis"><br><br></p>
            <div  class="panel panel-primary">
                <div class="panel-heading"><h4>Variáveis e seus Tipos</h4></div>
                <div class="panel-body">
                    <p class="texto">	      	
                        Nesse topico vamos escrever sobre um dos assuntos mais básicos da linguagem c, vamos falar sobre variaveis.
                        Variaveis são os nomes que vamos dar a determinado bloco de memória, esse bloco da memoria servira para armezar valores que voce precisa para execução de um programa, ou seja sempre que voce quiser usar um dado(numero, caractere, texto, etc) da memória, na linguagem C, voce precisara de uma variavel. Então quando voce declara uma variavel, voce estara determinando o bloco da memória para ela e podera alterar ele atravez do seu codigo.
                    </p>
                    <p class="texto">
                        Por exemplo, suponha que você queria armazenar sua pontuação em um jogo que desenvolveu em C. Se esse valor for inteiro, voce precisará declarar uma variavel (poderia usar o nome "pontos", por exemplo), e o C irá alocar um espaço de 2 ou 4 bytes de memória. Aquele espaço em memória ser somenta para sua variável, é o endereço dela. No site trataremos alguns tipos de variaveis como inteiros, reais e caracteres.
                    </p>


                    <p class="texto">
                    <h4>Variáveis Inteiras.</h4>
                    Variaveis inteiras são valores númericos sem ponto flutuante ou seja pertecentes ao conjunto dos inteiros. Existem vários tipos de inteiros, cada um de um tamanho diferente (dependendo do sistema operacional e/ou arquitetura do processador), mas da pra dizer que ele varia entre 16 	bits, 32 bits ou 64 bits, e isso determina o numero limite que essas variaveis podem possuir.
                    <br>
                    Algumas formas de declaração de uma variável inteira:
                    </p>

                    <pre ><code>
int nome_da_variavel; // nenhum valor atribuido
int nome_da_variavel = 10; // valor atribuido = 10
					</code></pre>


                    <p class="texto">
                    <h4>Variaveis reais.</h4>
                    Variaveis reais assim como as variáveis inteiras são usadas para numeros, a diferença é a aceitação de pontos flutuantes (casas decimais). Elas são declaradas usando a palavra reservada float, que em inglês equivale a real em português.
                    </p>

                    <pre><code>
float nome_da_variavel; // nenhum valor atribuido
float nome_da_variavel = 10,2; // valor atribuido: 10,2
                    </pre></code>


                    <p class="texto">
                        Variaveis de caracters tem o tamanho de 1 bytes e servem para armazenar um caracter ou inteiro. Isso significa que o programa reserva um espaço de 8 bits na memória ram ou em registradores do processador para armazenar um valor, char de tamannho menor que 8 bits, com mais estudos são possiveis criar strings com essas variaveis, palavras em português.<br>
                        Algumas formas de declaração de uma váriavel do tipo caractere:
                    </p>
                    <pre ><code>
char nome_da_variavel;  // sem valor
char nome_da_variavel = 'a'; // valor atribuido: a
</code></pre >

                    <p class="texto">
                        Obs.: Voces podem ter notado que não foi usado espaço para serparar o nome da variavel e sim um underline "_", isso se da porque variáveis não podem ter espaço em suas declarações assim como números e caracteres especiais no início, preste atenção nisso pois se não cumprir um desses requisistos o programa pode não compilar.
                    </p>
                </div>
            </div>    







            <p id="utilizando"><br><br></p>
            <div  class="panel panel-primary">
                <div class="panel-heading"><h4>Utilizando Variáveis</h4></div>
                <div class="panel-body">
                    <p class="texto">
                        Como visto nos capitulos anteriors existem funções para mostrar um conteudo na tela e pegar algo digitado pelo usuario, essas funções podem ser usadas junto com variaveis, um exemplo de codigo é

                    </p>
                    <pre><code>
#include &lt;stdio.h&gt;
int main(){
	int ano_de_nascimento;
	printf("Digite seu ano de nascimento");
	scanf("%d", &ano_de_nascimento);
	printf("Você nasceu em %d", ano_de_nascimento);
}

</code></pre>
                    <p class="texto">
                        No codigo a cima foi criada uma variavel com o nome "ano_de_nascimento" depois atraves da função printf foi printada na tela a mensagem "Digite o seu ano de nascimento" e então a função scanf pegou o que foi digitado pelo ususario e armazenou esse valor na posição de memoria da varaivel "ano_de_nascimento" e por fim o ano de nascimento foi mostrado na tela novamente pela função printf.

                        obs.: No codigo foi usado %d para referenciar as variaveis que seguem a mensagem entre as aspas, mas o %d só é usado para variaveis de tipo inteira. Para referenciar variaveis do tipo float e char são usados respectivamente %f e %c.

                    </p>
                </div>
            </div>

            <div class="panel panel-primary">
                <div class="panel-heading"><h4>Questões:</h4></div>
                <div class="panel-body">
                    <table id = "questao">
                        <tr>Qual maneira estaria correta para declarar uma variavel do tipo inteira que representa o codigo de um produto?</p>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 1)">float codigo_produto;</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 1)">int codigo produto;</button></th>
                        </tr>
                        <tr>
                            <th><button id = "correta1" onclick="teste_correto(this, 0, 1)">int codigo_produto;</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 1)">char 1codigo_produto;</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 1)">codigo_produto;</button></th>
                        </tr>
                    </table>
                </div>
            </div>
            <div>
                <a href="Conceitos.php">
                    <button type="button" class="btn btn-success" id="botaoPrevious"  ">&#8592;Conceitos</button>
                </a>
                <a href="Operadores.php">
                    <button type="button" class="btn btn-success" id="botaoNext">Operadores&#8594;</button>
                </a>
            </div>
        </div>
    </div>
    <br><br><br><hr>
    <?php
        $menu->showFooter();
    ?>
</div>
</body>
</html>
