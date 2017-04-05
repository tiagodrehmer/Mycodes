<?php

require '/../vendor/autoload.php';


/*
 *  Classe criada para reunir todos os atributos ou elementos visuais comuns a qualquer página
 */

class PageView {

    function __construct() {
        
    }

    //Método para mostrar o menu lateral em uma página
    function showMenuLateral() {
        echo '<div id="mySidenav" class="sidenav">
                <a class="sideNavTitulo" href="index.php#tutoriais" >Tutoriais     </a>
                <a id="sideNavClose" href="javascript:void(0)" class="closebtn" onclick="closeNav()">&times;</a> 
                <a class="tutorialPrincipal" data-toggle="collapse" data-parent="#accordion" href="#collapse1" onclick="highLightTutorial()"> Conceitos Básicos<span class="caret"></span></a>
                <div id="collapse1" class="panel-collapse collapse in">
                    <div class="panel-body">
                        <a id="tutorialSecundarioUnico" class="tutorialSecundario" href="Conceitos.php#compilando"> Criando e compilando seu primeiro programa em C</a>
                    </div>
                </div>

                <a class="tutorialPrincipal" data-toggle="collapse" data-parent="#accordion" href="#collapse2"> Variáveis<span class="caret"></span></a>
                <div id="collapse2" class="panel-collapse collapse">
                    <div class="panel-body">
                        <a id="tutorialSecundario" class="tutorialSecundario" href="Variaveis.php#variaveis">Variáveis e seus Tipos</a>
                        <a id="tutorialSecundarioultimo" class="tutorialSecundario" href="Variaveis.php#utilizando"> Utilizando variáveis </a>
                    </div>
                </div>


                <a class="tutorialPrincipal" data-toggle="collapse" data-parent="#accordion" href="#collapse3"> Operadores Aritméticos e Lógicos<span class="caret"></span></a>
                <div id="collapse3" class="panel-collapse collapse">
                    <div class="panel-body">
                        <a class="tutorialSecundario" href="Operadores.php#lista"> Lista de operadores </a>
                        <a id="tutorialSecundarioultimo" class="tutorialSecundario" href="Operadores.php#estrutura">Estrutura Seletiva - if e else</a>
                    </div>
                </div>



                <a class="tutorialPrincipal" data-toggle="collapse" data-parent="#accordion" href="#collapse4">Controladores de Fluxo<span class="caret"></span></a>
                <div id="collapse4" class="panel-collapse collapse">
                    <div class="panel-body">
                        <a class="tutorialSecundario" href="Controladores.php#while"> While </a>
                        <a class="tutorialSecundario" href="Controladores.php#dowhile" > Do While </a>
                        <a class="tutorialSecundario" href="Controladores.php#for"> For </a>
                        <a id="tutorialSecundarioultimo" class="tutorialSecundario" href="Controladores.php#switch"> Switch</a>
                    </div>
                </div>


                <a id="tutorial" class="tutorialPrincipal" data-toggle="collapse" data-parent="#accordion" href="#collapse5">Funções<span class="caret"></span></a>
                <div id="collapse5" class="panel-collapse collapse">
                    <div class="panel-body">
                        <a class="tutorialSecundario" href="Funcoes.php#criando">Criando Funções</a>
                        <a id="tutorialSecundarioultimo" class="tutorialSecundario" href="Funcoes.php#recursiva">Funções Recursivas</a>
                    </div>
                </div> 
                
        </div>';
    }

    //Método para mostrar o menu superior em uma página
    function showMenuSuperior() {
        $page = basename($_SERVER['PHP_SELF']);
        // id='menuativo'

        echo'<nav class="fixed-nav-bar">
                 <ul class="topnav" id="myTopnav">

                <li> 
                    <button type="button" class="btn btn-primary" id="botaoMenu" onclick="onCLickTutorial()">
                        &#9776; C Tutoriais
                    </button> 
                </li>';

        if ($page == "index.php") {
            echo '<li><a id="menuativo" href="index.php" onclick="responsiveMenu()" >Home</a></li>';
        } else {
            echo '<li><a  href="index.php" onclick="responsiveMenu()" >Home</a></li>';
        }
        if ($page == "Sobre.php") {
            echo ' <li><a id="menuativo" href="Sobre.php" onclick="responsiveMenu()">Sobre</a></li>';
        } else {
            echo ' <li><a href="Sobre.php" onclick="responsiveMenu()">Sobre</a></li>';
        }

        if ($page == "Contato.php") {
            echo '<li><a id="menuativo" href="Contato.php" onclick="responsiveMenu()">Contato</a></li>';
        } else {
            echo '<li><a href="Contato.php" onclick="responsiveMenu()">Contato</a></li>';
        }

        if ($page == "forum.php" || $page == "discussao.php" || $page == "editaQuestao") {
            echo ' <li><a id="menuativo" href="forum.php" onclick="responsiveMenu()">Forum</a></li>';
        } else {
            echo ' <li><a  href="forum.php" onclick="responsiveMenu()">Forum</a></li>';
        }
        if (empty($_SESSION['nome'])) {
            echo "<ul class='nav navbar-nav navbar-right'>";

            if ($page == "signup.php") {
                echo "<li><a id='menuativo' href='signup.php' onclick='responsiveMenu()'><span class='glyphicon glyphicon-user'></span> Criar Conta</a></li>";
            } else {
                echo "<li><a href='signup.php' onclick='responsiveMenu()'><span class='glyphicon glyphicon-user'></span> Criar Conta</a></li>";
            }
            if ($page == "login.php") {
                echo "<li><a id='menuativo' href='login.php' onclick='responsiveMenu()'><span class='glyphicon glyphicon-log-in'></span> Login</a></li>";
            } else {
                echo "<li><a href='login.php' onclick='responsiveMenu()'><span class='glyphicon glyphicon-log-in'></span> Login</a></li>";
            }
            echo "</ul>";
        } else {
            echo "<ul class='nav navbar-nav navbar-right'>";

            if ($page == "infousuario.php" || $page == "editarinfo.php") {
                echo "<li><a  id='menuativo' class='username' href='infousuario.php' onclick='responsiveMenu()'><span class='glyphicon glyphicon-user'></span> " . $_SESSION['nome'] . "</a></li>";
            } else {
                echo "<li><a class='username' href='infousuario.php' onclick='responsiveMenu()'><span class='glyphicon glyphicon-user'></span> " . $_SESSION['nome'] . "</a></li>";
            }
            echo "<li><a href='$page?sair=true' onclick='responsiveMenu()'><span class='glyphicon glyphicon-log-out'></span> Logout</a></li></ul>";
        }
        echo '<li class="icon">
                        <a href="javascript:void(0);" onclick="responsiveMenu()">☰</a>
                     </li>
                </ul>
            </nav>';
    }

    function showHeadHTML() {
        echo
        '<!DOCTYPE html>
        <html lang="pt-BR">

            <head>
                <title>C Tutoriais</title>
                <meta charset="UTF-8"> <!-- habilitar acentuação -->

                <link rel="stylesheet" type="text/css" href="css/styles.css">
                <meta name="viewport" content="width=device-width, initial-scale=1">

                <link rel="stylesheet" href="bootstrap-3.3.7-dist/css/bootstrap.min.css">
                <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
                <script src="bootstrap-3.3.7-dist/js/bootstrap.min.js"></script>
                <script src="js/script.js"></script>

                <!-- highlights no pre e code -->
                <link rel="stylesheet" href="highlights/styles/default.css">
                <script src="highlights/highlight.pack.js"></script>
                <script>hljs.initHighlightingOnLoad();</script>
                
                <script type="text/javascrips">
                function insertText(elemID, text){
                    var elem = document.getElementById(elemID);
                    elem.innerHTML += text;
                }
                </script>
            </head>

            <body onresize="redimenciona()" >';
    }

    function showFooter() {
        echo'<footer>
        <p id = "contato_pe">Contatos</p>
        <p id = "contato_pe">E-mail: tiagodrehmer@hotmail.com</p>
        <p id = "contato_pe">E-mail: marcelocm97@hotmail.com</p>
        <p id = "contato_pe">E-mail: leo-brondani@hotmail.com</p>
        <img id="logo_pe" src="imgs/logo.png" alt="logo"></img>
        </footer>';
    }

}
