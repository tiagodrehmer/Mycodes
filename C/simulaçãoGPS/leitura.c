#include <Mapa.h>

// falta testar o numero_vertices
Rua_t** libera_matriz(Rua_t **matriz){
	int i, j;
	for (i = 0; i < numero_vertices; i++){
		free(matriz[i]);
	}
	free(matriz);
	return matriz;
}

int percorre_matriz (Rua_t **matriz, int i, int j, passeio_t* passeio){
	int k, teste = 0;
	passeio[i].visita = 1;
	if (matriz[i][j].transito != 0){
		return 1;
	}
	else{
		for (k = 0; k < numero_vertices; k++){
			if (matriz[i][k].transito){
				if (passeio[k].visita == 0){
					teste = percorre_matriz(matriz, k, j, passeio);
					if (teste){
						break;
					}
				}
			}
		}
	}	
	return teste;
}

int testa_matriz (Rua_t **matriz){
	int i, j, k, teste = 0;
	char x;
	passeio_t* passeio = (passeio_t*) malloc(numero_vertices * sizeof(passeio_t));

	for (i = 0; i < numero_vertices; i++){
		for (j = 0; j < numero_vertices; j++){
			for (k = 0; k < numero_vertices; k++){
				passeio[k].visita = 0;
			}
			if (percorre_matriz(matriz, i, j, passeio)){
				printf ("Somou: %d, %d\n", i, j);
				teste++;
			}
		}
	}
	return teste;
}

Rua_t** ler_entrada(Rua_t **matriz, char *arquivo) { //ler_entrada_f

	FILE *fd_entrada;
	char linha_leitura[512], nome[164], extra;
	int linha, coluna, distancia, transito, velocidade_minima, tipo_rua, j;

	fd_entrada = fopen(arquivo,"r");
	if(fd_entrada == NULL) {
		printf("ERRO AO INSERIR DADOS.\nNão foi possivel abrir o arquivo %s\nPrograma será encerrado.\n",arquivo);
		exit(-1);
	}

	fscanf(fd_entrada,"%d\n", &numero_vertices);

	matriz = init_matriz(matriz);

	while(fscanf(fd_entrada,"%s\n", linha_leitura) != EOF){

		j = sscanf(linha_leitura,"%d;%d;%[^;];%d;%d;%d;%d%c", &linha, &coluna, nome, &distancia, &transito, &velocidade_minima, &tipo_rua, &extra);

		if (linha > numero_vertices || coluna > numero_vertices){
			printf("\nVoce informou o numero errado de cruzamentos existe uma rua com cruzamentos: %d, %d\n". linha, coluna);
			fclose(fd_entrada);
			matriz = libera_matriz(matriz);
			exit(-1);
		}
		else if(j == 7) {
			matriz = insere_rua(matriz, (linha-1), (coluna-1), nome, distancia, transito, velocidade_minima, tipo_rua);
		}


	}
	fclose(fd_entrada);
	return matriz;
}

Rua_t** insere_rua(Rua_t **matriz, int linha, int coluna, char *nome, int distancia, int transito, int velocidade_minima, int tipo_rua) { //insere_rua_f

	strcpy(matriz[linha][coluna].nome,nome); 
	matriz[linha][coluna].distancia = distancia;
	matriz[linha][coluna].transito = transito;
	matriz[linha][coluna].velocidade_minima = velocidade_minima;
	matriz[linha][coluna].tipo_rua = tipo_rua;

	return matriz;

}

Rua_t** init_matriz (Rua_t **matriz) {	
	int i, j;
	matriz = (Rua_t**)malloc(numero_vertices * sizeof(Rua_t*));
	for (i = 0; i < numero_vertices; i++){
		matriz[i] = (Rua_t*)malloc(numero_vertices * sizeof(Rua_t));
		for (j = 0; j < numero_vertices; j++){
			memset(matriz[i][j].nome, '\0' , sizeof(matriz[i][j].nome));
			matriz[i][j].tipo_rua = 0;
			matriz[i][j].distancia = 0;
			matriz[i][j].transito = 0;
			matriz[i][j].velocidade_minima = 0;
			matriz[i][j].visitado = 0;
		}
	}
	return matriz;
}