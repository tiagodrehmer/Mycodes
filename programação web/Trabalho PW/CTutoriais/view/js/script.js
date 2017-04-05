/* Mudar a classe do menu superior*/
function responsiveMenu() {
    var x = document.getElementById("myTopnav");
    if (x.className === "topnav") {
        x.className += " responsive";
    } else {
        x.className = "topnav";
    }

    var x = document.getElementById("right-topnav");
    if (x.className === "right-topnav") {
        x.className += " responsive";
    } else {
        x.className = "right-topnav";
    }

}

function mantemMenuAberto() {
    var tamanho_janela = window.outerWidth;

    if (tamanho_janela > 850) {
        document.getElementById("mySidenav").style.width = "200px";
        document.getElementById("main").style.marginLeft = "220px";
    } else {
        document.getElementById("mySidenav").style.width = "200px";
    }
}


/* Redimensionar as margens quando for dado zoom in ou zoom out na página*/
function redimenciona() {
    var tamanho_janela = window.outerWidth;

    if (tamanho_janela < 850) {
        document.getElementById("main").style.marginLeft = "0px";
        document.getElementById("main").style.marginRight = "0px";
    } else {
        if (document.getElementById("mySidenav").style.width === "200px") {
            document.getElementById("main").style.marginLeft = "220px";
        } else {
            document.getElementById("main").style.marginLeft = "50px";
            document.getElementById("main").style.marginRight = "50px";
        }
    }
}



/*Botao "X" do lado do título da sideNav*/
function closeNav() {
    var tamanho_janela = $(window).width();
    if (tamanho_janela < 850) {
        document.getElementById("mySidenav").style.width = "0px";
        document.getElementById("main").style.marginLeft = "0px";
    } else {
        document.getElementById("mySidenav").style.width = "0px";
        document.getElementById("main").style.marginLeft = "50px";
        document.getElementById("main").style.marginRight = "50px";
    }
}

/*Botão Tutoriais no menu superior*/
function onCLickTutorial() {
    var tamanho_janela = $(window).width();

    //fecha a sidenav
    if (document.getElementById("mySidenav").style.width === "200px") {

        if (tamanho_janela < 850) {
            document.getElementById("mySidenav").style.width = "0px";
            document.getElementById("main").style.marginLeft = "0px";
        } else {
            document.getElementById("mySidenav").style.width = "0px";
            document.getElementById("main").style.marginLeft = "50px";
            document.getElementById("main").style.marginRight = "50px";
        }

        //abre a sidenav
    } else {
        if (tamanho_janela > 850) {
            document.getElementById("mySidenav").style.width = "200px";
            document.getElementById("main").style.marginLeft = "220px";
        } else {
            document.getElementById("mySidenav").style.width = "200px";
        }
    }
}



var uma_vez = [true, true, true];
function teste_correto(id, correto, questao) {
    var x = "correta" + questao;
    if (correto == 1 && uma_vez[questao - 1]) {
        id.style.background = "#FA1418";
    }
    document.getElementById(x).style.background = "#13D83F";
    uma_vez[questao - 1] = false;
}
/*Smooth Scroll 
 
 $(document).ready(function(){
 $('a[href*=#]').click(function() {
 if (location.pathname.replace(/^\//,'') == this.pathname.replace(/^\//,'')
 && location.hostname == this.hostname) {
 var $target = $(this.hash);
 $target = $target.length && $target
 || $('[name=' + this.hash.slice(1) +']');
 if ($target.length) {
 var targetOffset = $target.offset().top;
 $('html,body')
 .animate({scrollTop: targetOffset}, 1000);
 return false;
 }
 }
 });
 });*/

