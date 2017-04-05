#include <Mapa.h>

int main(int argc, char **argv) {

	Rua_t **matriz;
	dia = -1;
	hora = -1;

	matriz = ler_entrada(matriz, argv[1]);
	
	system("clear");
	printf("Verificando cidade...");
	if (testa_matriz(matriz) != (numero_vertices * numero_vertices)){
		printf ("\nERRO: 01, vide help para obter informação -h\n");
		matriz = libera_matriz(matriz);
		exit (-1);
	}

	while(dia < 1 || dia > 7){
		system("clear");
		__fpurge(stdin);
		printf("Digite dia da semana:\n<<1 para Domingo, 2 Segunda, 3 Terca, 4 Quarta, 5 Quinta, 6 Sexta e 7 Sabado>>\n");
		printf("Dia:");
		scanf ("%d", &dia);
	}
	while (hora < 0 || hora > 23){
		system("clear");
		__fpurge(stdin);
		printf("Digite a hora:");
		scanf ("%d", &hora);
	}

	// teste thread
	pthread_t thread;
	int execute;
	srand(time(NULL));

	execute = pthread_create(&thread , NULL, modifica, (void *)matriz);
	//pthread_join(thread, NULL);
	menu(matriz);

	pthread_exit(NULL);
	matriz = libera_matriz(matriz);
}


/*
THREADS

pthread_create

pthread_join

pthread_mutex_lock    não alterar o trafego no caminho durante o trajeto

pthread_mutex_unlock  libera o caminho para ter o trafego alterado
*/