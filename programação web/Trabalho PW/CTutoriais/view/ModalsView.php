<?php

require '/../vendor/autoload.php';

class ModalsView {

    function __construct() {
        
    }

    //mostrar um modal para o usuário perguntando se ele tem certeza que quer realizar uma determinada ação
    function showModalAviso($titulo, $mensagem) {
        echo '<!-- Modal -->
                <div id="modalAviso" class="modal fade" role="dialog">
                  <div class="modal-dialog">

                    <!-- Modal content-->
                    <div class="modal-content">
                      <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">' . $titulo . '</h4>
                      </div>
                      <div class="modal-body">
                        <p>' . $mensagem . '</p>
                        <form action="index.php?excluir=true" role="form" method="POST">
                            <button type="submit"  class="btn btn-danger btn-block">Confirmar</button>
                        </form>

                      </div>
                      <div class="modal-footer">
                        <button type="button" class="btn btn-default" data-dismiss="modal">Cancelar</button>
                      </div>
                    </div>

                  </div>
                </div>';
    }
    
    function showModalAvisoQuestao($titulo, $mensagem, $id) {
        echo '<div class="modal fade ModalEditarResposta" id="modalAviso'.$id.'" tabindex="-1" role="dialog" 
                             aria-labelledby="myModalLabel" aria-hidden="true">
                  <div class="modal-dialog">

                    <!-- Modal content-->
                    <div class="modal-content">
                      <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">' . $titulo . '</h4>
                      </div>
                      <div class="modal-body">
                        <p>' . $mensagem . '</p>
                        <form action="forum.php?excluir='. $id . '" role="form" method="POST">
                            <button type="submit"  class="btn btn-danger btn-block">Confirmar</button>
                        </form>

                      </div>
                      <div class="modal-footer">
                        <button type="button" class="btn btn-default" data-dismiss="modal">Cancelar</button>
                      </div>
                    </div>

                  </div>
                </div>';
    }

    //modal que mostra um form para o usuário preencher e enviar sua questão
    function showModalQuestao() {
        echo '  <div class="modal fade" id="ModalQuestao" tabindex="-1" role="dialog" 
                         aria-labelledby="myModalLabel" aria-hidden=tabindex="-1""true">
                        <div class="modal-dialog modal-lg">
                            <div class="modal-content">
                                <!-- Modal Header -->
                                <div class="modal-header">
                                    <button type="button" class="close" 
                                            data-dismiss="modal">
                                        <span aria-hidden="true">&times;</span>
                                        <span class="sr-only">Close</span>
                                    </button>
                                    <h4 class="modal-title" id="myModalLabel">
                                        Criar uma nova Questão 
                                    </h4>
                                </div>

                                <!-- Modal Body -->
                                <div class="modal-body">

                                    <form action="forum.php?inserir=true" role="form" method="POST">
                                        <div class="form-group">
                                            <label for="titulo">Título da Questão</label>
                                            <input type="text" name="titulo" class="form-control" maxlength="127"
                                                   id="titulo" placeholder="Título da Questão" required="required"/>' ;
        
                                            echo ' <br><br><label for="descricao">Descrição do problema/questão(Opcional)</label>
                                            <textarea name="desc" id="descricao" maxlength="2000"
                                                      placeholder="Escreva aqui a descrição de sua questão (Opcional)" class="form-control"></textarea>
                                                      <br>
                                                      <label for="resposta">Espaço para inserir código</label>
                                                      <textarea name="codigo" id="codigo" maxlength="2000"
                                                      placeholder="#incude <stdio.h> ..." class="form-control"></textarea> 
                                                    </div>
                                        <button type="submit"  class="btn btn-success btn-block">Criar Questão</button>
                                    </form>

                                    
                                </div>

                                <!-- Modal Footer -->
                                <div class="modal-footer">
                                    <button type="button" class="btn btn-default"
                                            data-dismiss="modal">
                                        Cancelar
                                    </button>
                                </div>
                            </div>
                        </div>
                    </div>';
    }

    //modal que mostra um form para o usuário preencher e enviar sua resposta
    function showModalResposta() {
        echo '  <div class="modal fade" id="ModalResposta" tabindex="-1" role="dialog" 
                         aria-labelledby="myModalLabel" aria-hidden="true">
                        <div class="modal-dialog modal-lg">
                            <div class="modal-content">
                                <!-- Modal Header -->
                                <div class="modal-header">
                                    <button type="button" class="close" 
                                            data-dismiss="modal">
                                        <span aria-hidden="true">&times;</span>
                                        <span class="sr-only">Close</span>
                                    </button>
                                    <h4 class="modal-title" id="myModalLabel">
                                        Responder Questão
                                    </h4>
                                </div>

                                <!-- Modal Body -->
                                <div class="modal-body">

                                    <form action="discussao.php?responder=true&questao=' . $_GET['questao'] . '" role="form" method="POST">
                                        <div class="form-group">
                                        
                                            <label for="resposta">Sua Resposta para a Questão</label>
                                            <textarea name="resposta" id="resposta" maxlength="2000" required="required"
                                                      placeholder="Escreva aqui sua resposta" class="form-control"></textarea>    
                                                      <br>
                                            <label for="resposta">Espaço para inserir código</label>
                                            <textarea name="codigo" id="codigo" maxlength="2000"
                                                      placeholder="#incude <stdio.h> ..." class="form-control"></textarea> 
                                                      
                                        </div>
                                        <button type="submit"  class="btn btn-success btn-block">Enviar Resposta</button>
                                    </form>
                                </div>

                                <!-- Modal Footer -->
                                <div class="modal-footer">
                                    <button type="button" class="btn btn-default"
                                            data-dismiss="modal">
                                        Cancelar
                                    </button>
                                </div>
                            </div>
                        </div>
                    </div>';
    }

   function showModalEditarQuestao($questaoVO) {
                  echo '  <div class="modal fade ModalEditarResposta" id="ModalEditarQuestao'.$questaoVO->getQuestaoID().'" tabindex="-1" role="dialog" 
                             aria-labelledby="myModalLabel" aria-hidden="true">
                            <div class="modal-dialog modal-lg">
                                <div class="modal-content">
                                    <!-- Modal Header -->
                                    <div class="modal-header">
                                        <button type="button" class="close" 
                                                data-dismiss="modal">
                                            <span aria-hidden="true">&times;</span>
                                            <span class="sr-only">Close</span>
                                        </button>
                                        <h4 class="modal-title" id="myModalLabel">
                                            Editar Questão
                                        </h4>
                                    </div>

                                    <!-- Modal Body -->
                                    <div class="modal-body" id="modal-body">
                                        
                                        <form action="discussao.php?update=true&questao='.$questaoVO->getQuestaoID().'" role="form" method="POST">
                                            <div class="form-group">
                                            <label for="titulo">Título da Questão</label>
                                            <input type="text" name="titulo" class="form-control" maxlength="127"
                                                   id="titulo" placeholder="Título da Questão" value="'.$questaoVO->getTitulo().'"/><br><br>
                                                <label for="descricao">Descrição do problema/questão(Opcional)</label>
                                            <textarea name="descricao" id="descricao" maxlength="2000"
                                                      placeholder="Escreva aqui a descrição de sua questão (Opcional)" class="form-control">'.$questaoVO->getDescricao().'</textarea><br>
                                            <label for="resposta">Espaço para inserir código</label>
                                            <textarea name="codigo" id="codigo" maxlength="2000"
                                                      placeholder="#incude <stdio.h> ..." class="form-control">'.$questaoVO->getCodigo().'</textarea>                                                             
                                            </div>
                                            <button type="submit"  class="btn btn-success btn-block">Editar Resposta</button>
                                        </form>
                                    </div>

                                    <!-- Modal Footer -->
                                    <div class="modal-footer">
                                        <button type="button" class="btn btn-default"
                                                data-dismiss="modal">
                                            Cancelar
                                        </button>
                                    </div>
                                </div>
                            </div>
                        </div>';
        
    }
    
    function showModalEditarResposta($respostaVO) {
                  echo '  <div class="modal fade ModalEditarResposta" id="ModalEditarResposta'.$respostaVO->getRespostaID().'" tabindex="-1" role="dialog" 
                             aria-labelledby="myModalLabel" aria-hidden="true">
                            <div class="modal-dialog modal-lg">
                                <div class="modal-content">
                                    <!-- Modal Header -->
                                    <div class="modal-header">
                                        <button type="button" class="close" 
                                                data-dismiss="modal">
                                            <span aria-hidden="true">&times;</span>
                                            <span class="sr-only">Close</span>
                                        </button>
                                        <h4 class="modal-title" id="myModalLabel">
                                            Editar Resposta
                                        </h4>
                                    </div>

                                    <!-- Modal Body -->
                                    <div class="modal-body" id="modal-body">
                                        
                                        <form action="discussao.php?editarquestao='.$respostaVO->getRespostaID().'&questao='.$respostaVO->getQuestaoID().'" role="form" method="POST">
                                            <div class="form-group">
                                                <label for="resposta">Sua Resposta para a Questão</label>
                                                <textarea name="resposta" id="resposta  " maxlength="2000" required="required"
                                                        class="form-control" value="">'.$respostaVO->getResposta().'</textarea> 
                                                      <br>
                                            <label for="resposta">Espaço para inserir código</label>
                                            <textarea name="codigo" id="codigo" maxlength="2000"
                                                      placeholder="#incude <stdio.h> ..." class="form-control">'.$respostaVO->getCodigo().'</textarea>                                                             
                                            </div>
                                            <button type="submit"  class="btn btn-success btn-block">Editar Resposta</button>
                                        </form>
                                    </div>

                                    <!-- Modal Footer -->
                                    <div class="modal-footer">
                                        <button type="button" class="btn btn-default"
                                                data-dismiss="modal">
                                            Cancelar
                                        </button>
                                    </div>
                                </div>
                            </div>
                        </div>';
        
    }

}
