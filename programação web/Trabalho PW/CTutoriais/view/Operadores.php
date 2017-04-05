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

        <div id="main" class="texto"> 
            <img id="logo" src="imgs/logo.png" alt="logo"></img>

            <p id="lista"><br><br></p>
            <div id="ifelse" class="panel panel-primary">
                <div class="panel-heading"><h3>Operadores lógicos</h3></div>
                <div class="panel-body">
                    <div id="ifelse" class="panel panel-primary">

                        <table id = "operadores">
                            <tr>
                                <th id = "sub">&gt;</th>
                                <th id = "sub">MAIOR DO QUE</th>
                            </tr>

                            <tr>
                                <th>situação</th>
                                <th>resultado</th>
                            </tr>

                            <tr>
                                <th>20>&gt;10</th>
                                <th>verdadeiro</th>
                            </tr>

                            <tr>
                                <th>10&gt;20</th>
                                <th>falso</th>
                            </tr>

                            <tr>
                                <th>20&gt;20</th>
                                <th>falso</th>
                            </tr>

                            <tr>
                                <th id = "sub">&gt;=</th>
                                <th id = "sub">MAIOR OU IGUAL A</th>
                            </tr>

                            <tr>
                                <th>situação</th>
                                <th>resultado</th>
                            </tr>

                            <tr>
                                <th>20&gt;=10</th>
                                <th>verdadeiro</th>
                            </tr>

                            <tr>
                                <th>10&gt;=20</th>
                                <th>falso</th>
                            </tr>

                            <tr>
                                <th>20&gt;=20</th>
                                <th>verdadeiro</th>
                            </tr>

                            <tr>
                                <th id = "sub">&lt;</th>
                                <th id = "sub">MENOR DO QUE</th>
                            </tr>

                            <tr>
                                <th>situação</th>
                                <th>resultado</th>
                            </tr>

                            <tr>
                                <th>20<10</th>
                                <th>falso</th>
                            </tr>

                            <tr>
                                <th>10<20</th>
                                <th>verdadeiro</th>
                            </tr>

                            <tr>
                                <th>20<20</th>
                                <th>falso</th>
                            </tr>

                            <tr>
                                <th id = "sub">&lt;=</th>
                                <th id = "sub">MENOR OU IGUAL A</th>
                            </tr>

                            <tr>
                                <th>stuação</th>
                                <th>resultado</th>
                            </tr>

                            <tr>
                                <th>20<=10</th>
                                <th>falso</th>
                            </tr>

                            <tr>
                                <th>10<=20</th>
                                <th>verdadeiro</th>
                            </tr>

                            <tr>
                                <th>20<=20</th>
                                <th>verdadeiro</th>
                            </tr>

                            <tr>
                                <th id = "sub">==</th>
                                <th id = "sub">IGUAL A</th>
                            </tr>

                            <tr>
                                <th>situação</th>
                                <th>resultado</th>
                            </tr>

                            <tr>
                                <th>20==10</th>
                                <th>falso</th>
                            </tr>

                            <tr>
                                <th>10==20</th>
                                <th>falso</th>
                            </tr>

                            <tr>
                                <th>20==20</th>
                                <th>verdadeiro</th>
                            </tr>

                            <tr>
                                <th id = "sub">!=</th>
                                <th id = "sub">DIFERENTE DE</th>
                            </tr>

                            <tr>
                                <th>situação</th>
                                <th>resultado</th>
                            </tr>

                            <tr>
                                <th>20!=10</th>
                                <th>verdadeiro</th>
                            </tr>

                            <tr>
                                <th>10!=20</th>
                                <th>verdadeiro</th>
                            </tr>

                            <tr>
                                <th>20!=20</th>
                                <th>falso</th>
                            </tr>
                        </table>
                        <br>
                        <p class="texto">
                            Além desses também há outros. Os mais comuns além desses é o E e o OU. Que servem para comparar duas ou mais sentenças no mesmo if.

                            O E (&&) exige que todas as sentenças sejam verdadeiras para considerar o IF verdadeiro.
                            && 	E
                        </p>
                        <table id = "operadores">
                            <tr id = "sub">
                                <th>&&</th>
                                <th>'E'</th>
                            </tr>

                            <tr>
                                <th>situação</th>
                                <th>resultado</th>
                            </tr>

                            <tr>
                                <th>10<20 && 20>10</th>
                                <th>verdadeiro</th>
                            </tr>

                            <tr>
                                <th>10<20 && 10>20</th>
                                <th>falso</th>
                            </tr>

                            <tr>
                                <th>10>20 && 20>10</th>
                                <th>falso</th>
                            </tr>

                            <tr>
                                <th>10>20 && 20<10</th>
                                <th>falso</th>
                            </tr>
                        </table>
                        <br>
                        <p class="texto">
                            O OU (|| - duas barras verticais) exige que apenas uma das sentenças seja verdadeira para considerar o IF 	verdadeiro.
                            || 	OU
                        </p>

                        <table id = "operadores">
                            <tr id = "sub">
                                <th>||</th>
                                <th>'OU'</th>
                            </tr>


                            <tr>
                                <th>situação</th>
                                <th>resultado</th>
                            </tr>
                            <th>10<20 || 20>10</th>
                            <th>verdadeiro</th>
                            <tr>
                                <th>10<20 || 10>20</th>
                                <th>verdadeiro</th>
                            </tr>

                            <tr>
                                <th>10>20 || 20>10</th>
                                <th>verdadeiro</th>
                            </tr>

                            <tr>
                                <th>10>20 || 20<10</th>
                                <th>falso</th>
                            </tr>

                        </table>
                    </div>
                </div>
            </div>


            <p id="estrutura"><br><br></p>
            <div class="panel panel-primary">
                <div class="panel-heading"><h4>Estrutura seletiva - if e else</h4></div>
                <div class="panel-body">
                    <p class="texto">
                        Para fazer um bom programa, ele deve ser capaz de definir caminhos diferentes de acordo com decisões que o próprio programa toma. Para isso, precisamos de uma estrutura seletiva.

                        Usando IF

                        Para usar a estrutura 'if', e preciso define entrer parênteses oque deve ser comparado.

                        Se oque está dentro dos parênteses for verdade, então a linha seguinte do 'if' será executada.

                    </p>
                    <pre><code>
...
	x = 10;
	y = 5;

	if(x &gt y)
		printf("Verdade");
...</code></pre>				

                    <p class="texto">
                        E mais de uma linha seja executada, basta definir o bloco que será executado usando as chaves '{}' após o comando 'if'.
                    </p>
                    <pre><code>
...
	x = 10;
	y = 5;

	if(x &gt y){
		y = y + 5;
		x = y - 2;
		printf("X: %d\nY: %d", x, y);
	}
...</code></pre>
                    <h4>O comando Else</h4>
                    <p class="texto">
                        Com a estrutura 'else' em conjunto com o 'if', e possível executar um bloco de código ou outro, por exemplo, o 'if' código anterior verificava se o 'x' era maior que o 'y', se isso fosse verdade ele executava o que esta dentro das chaves do 'if', e qualquer trecho de código após o final do 'if' também seria executado. Para resolver isso, usamos o 'else', veja a seguir como ficaria um programa que diria se um número e maior que o outro ou não, fazendo apenas uma comparação usando a estrura 'if'.
                    </p>

                    <pre><code>
...
	x = 10;
	y = 5;

	if(x &gt y){
		y = y + 5;
		x = y - 2;
		printf("X: %d\nY: %d", x, y);
	}
...</code></pre>
                </div>
            </div>
            <div class="panel panel-primary">
                <div class="panel-heading"><h4>Questões:</h4></div>
                <div class="panel-body">
                    <table id = "questao">
                        <tr>
                            <th id = "enunciado"><h3><p>1 - Oque será o valor de 'x' ao final do seguinte código?</p>
                                    <pre><code>
int main(){
	int x = 10;

	if(x > 5){
		x = x + 2;
	}

	printf("%d\n", x);
}</code></pre></h3></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 1)">6</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 1)">8</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 1)">10</button></th>
                        </tr>
                        <tr>
                            <th><button id = "correta1" onclick="teste_correto(this, 0, 1)">12</button></th>
                        </tr>
                    </table>


                    </table>


                    <hr>
                    <table id = "questao">
                        <tr>
                            <th id = "enunciado"><h3><p>2 - Oque será o valor de 'x' ao final do seguinte código?</p>
                                    <pre><code>
int main(){

	int x = 10;

	if(x > 9){
		x  = x + 10;
		if(x < 30){
			x = x - 15;
		}else{
			x = x + 5;
		}
	}else{
		x = 0;
	}

	printf("%d\n", x);

}</code></pre></h3></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 2)">10</button></th>
                        </tr>
                        <tr>
                            <th><button id = "correta2" onclick="teste_correto(this, 0, 2)">5</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 2)">30</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 2)">25</button></th>
                        </tr>
                    </table>


                    <table id = "questao">
                        <tr>
                            <th id = "enunciado"><h3><p>3 - Oque será o valores de 'x' e 'y' ao final do seguinte código?</p>
                                    <pre><code>
int main(){

	int x = 0, y = 5;

	x = y*2;
	if(x > y){
		x  = y;
		if(x < 10){
			y = x*3
		}else{
			x = y*2
		}
	}else{
		x = y;
	}

	printf("%d e %d\n", x, y);

}</code></pre></h3></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 3)">X = 0 e Y = 0</button></th>
                        </tr>
                        <tr>
                            <th><button id = "correta3" onclick="teste_correto(this, 0, 3)">a - X = 5 e Y = 15</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 3)"> X = 10 e Y = 5</button></th>
                        </tr>
                        <tr>
                            <th><button id = "incorreta" onclick="teste_correto(this, 1, 3)">X = 5 e Y = 5</button></th>
                        </tr>
                    </table>
                </div>
            </div>
            <div>
                <a href="Variaveis.php">
                    <button type="button" class="btn btn-success" id="botaoPrevious"  ">&#8592;Variáveis</button>
                </a>
                <a href="Controladores.php">
                    <button type="button" class="btn btn-success" id="botaoNext">Controladores&#8594;</button>
                </a>
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

    </body>
</html>
