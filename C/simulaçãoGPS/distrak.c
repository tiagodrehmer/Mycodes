#include <Mapa.h>

//Calcula a rota com menor distancia
int* dijkstra_distancia(Rua_t **matriz, int* caminho_distancia, int origem, int destino) {
	int aux_origem = origem;
	int *custo = (int*)malloc(numero_vertices*sizeof(int));
	int *visitados = (int*)malloc(numero_vertices*sizeof(int));
	int *tmp = (int*)malloc(numero_vertices*sizeof(int));
	int i;
	int cont = 0;
	caminho_distancia = (int*)malloc(numero_vertices*sizeof(int));

	for(i = 0 ; i < numero_vertices ; i++) {
		visitados[i] = 0;
		custo[i] = (int) HUGE_VAL;
		caminho_distancia[i] = -1;
	}

	custo[origem] = 0;

	while(visitados[destino] == 0) {
		visitados[origem] = 1;
		for(i = 0 ; i < numero_vertices ; i++) {
			if(matriz[origem][i].distancia != 0) {
				if(custo[i] > custo[origem] + matriz[origem][i].distancia) {
					custo[i] = custo[origem] + matriz[origem][i].distancia;
					caminho_distancia[i] = origem;
				}
			}
		}
		int menor_custo = (int)HUGE_VAL;
		for(i = 0 ; i < numero_vertices ; i++) {
			if(custo[i] < menor_custo && visitados[i] == 0) {
				menor_custo = custo[i];
				origem = i;
			}
		}
	}

	printf("Caminho mais curto é de: %dm\n", custo[destino]);

	int caminho_mesmo[numero_vertices];
	int pos=0;

	i = caminho_distancia[destino];
	while (i != -1) {
		tmp[cont] = i;
		cont++;
		i = caminho_distancia[i];
	}

	for (i = cont; i > 0 ; i--){
		//printf("%d -> ", tmp[i-1]);
		caminho_mesmo[pos] = tmp[i-1];
		pos++;
	}
	caminho_mesmo[pos] = destino;
	pos++;

	int caminho_dot[pos];
	for(i=0; i<pos; i++){
		caminho_dot[i] = caminho_mesmo[i];
	}
	
	free(custo);
	free(visitados);
	free(tmp);

	gera_caminho_curto(matriz, caminho_dot, aux_origem, destino, pos);
	return caminho_distancia;
}

//Calcula a rota com menor tempo
int* dijkstra_tempo(Rua_t **matriz, int* caminho_tempo, int origem, int destino) {
	int aux_origem = origem;
	double *custo = (double*)malloc(numero_vertices*sizeof(double));
	int *visitados = (int*)malloc(numero_vertices*sizeof(int));
	int *tmp = (int*)malloc(numero_vertices*sizeof(int));
	int i;
	int cont = 0;
	caminho_tempo = (int*)malloc(numero_vertices*sizeof(int));

	for(i = 0 ; i < numero_vertices ; i++) {
		visitados[i] = 0;
		custo[i] = HUGE_VAL;
		caminho_tempo[i] = -1;
	}

	custo[origem] = 0;

	while(visitados[destino] == 0) {
		visitados[origem] = 1;
		for(i = 0 ; i < numero_vertices ; i++) {
			if(matriz[origem][i].distancia != 0){
				if(custo[i] > custo[origem] + ((matriz[origem][i].distancia)/((matriz[origem][i].velocidade_atual)/3.6))) {
					custo[i] = custo[origem] + ((matriz[origem][i].distancia)/((matriz[origem][i].velocidade_atual)/3.6));
					caminho_tempo[i] = origem;
				}
			}
		}
		double menor_custo = HUGE_VAL;
		for(i = 0 ; i < numero_vertices ; i++) {
			if(custo[i] < menor_custo && visitados[i] == 0) {
				menor_custo = custo[i];
				origem = i;
			}
		}
	}

	printf("Caminho mais rapido leva aproximadamente: %.1lfs\n", custo[destino]);
	int caminho_mesmo[numero_vertices];
	int pos=0;

	i = caminho_tempo[destino];
	while (i != -1) {
		tmp[cont] = i;
		cont++;
		i = caminho_tempo[i];
	}

	for (i = cont; i > 0 ; i--){
		//printf("%d -> ", tmp[i-1]);
		caminho_mesmo[pos] = tmp[i-1];
		pos++;
	}
	caminho_mesmo[pos] = destino;
	pos++;

	int caminho_dot[pos];
	for(i=0; i<pos; i++){
		caminho_dot[i] = caminho_mesmo[i];
	}


	free(custo);
	free(visitados);
	free(tmp);
	gera_caminho_rapido(matriz, caminho_dot, aux_origem, destino, pos);
	return caminho_tempo;
}


void mostra_caminho(int origem, int destino, int *caminho){
	
	if(origem == destino){
		printf("%d-> ", origem);
	}else if(caminho[destino] == -1){
		printf("nao tem caminho %d a %d ", origem, destino);
	}else{
		mostra_caminho(origem, caminho[destino], caminho);
		printf("%d-> ",destino);
	}
}