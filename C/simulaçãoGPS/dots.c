#include <Mapa.h>


void gera_mapa(Rua_t**  M){
	int i, j;
	FILE* saida;
	saida = fopen("mapa.dot", "w");

	fprintf(saida,"digraph{\n");
	for(i=0; i < numero_vertices; i++){
		fprintf(saida,"\t %d[shape=box, style=filled,color=""gray""];\n", i);
	}


	for(i = 0; i < numero_vertices; i++){
		for(j = 0; j < numero_vertices; j++){
			if(M[i][j].transito != 0){
				fprintf(saida, "\t%d -> %d[style=bold,label=""%s""];\n", i, j , M[i][j].nome);//M[i][j].distancia);
			}			
		}
	}
	fprintf(saida,"}");
	fclose(saida);
	system("dot -Tpng mapa.dot > map.png");
}



void gera_caminho_curto(Rua_t**  M, int* caminho, int origem, int destino, int tam_caminho){
	int i, j, atual, mudou=0;
	FILE* saida;
	saida = fopen("caminho_curto.dot", "w");

	fprintf(saida,"digraph{\n");
	for(i=0; i < numero_vertices; i++){
		for(atual=0; atual < tam_caminho; atual++){
			if(caminho[atual] == i){
				if(caminho[atual] == destino){
					fprintf(saida,"\t %d[shape=box, style=filled,color=""green""];\n", i);
				}else if(caminho[atual] == origem){
					fprintf(saida,"\t %d[shape=box, style=filled,color=""red""];\n", i);	
				}else if(caminho[atual] != origem && caminho[atual] != destino){
					fprintf(saida,"\t %d[shape=box, style=filled,color=""yellow""];\n", i);	
				}

				mudou = 1;
			}
		}
		if(mudou != 1){
			fprintf(saida,"\t %d[shape=box, style=filled,color=""gray""];\n", i);
		}
		mudou = 0;
	}

	mudou = 0;

	for(i = 0; i < numero_vertices; i++){
		for(j = 0; j < numero_vertices; j++){
			if(M[i][j].transito != 0){
				for(atual=0; atual< tam_caminho-1; atual++){
					if(caminho[atual] == i && caminho[atual+1] == j){
						fprintf(saida, "\t%d -> %d[style=bold,label=""%s"", color=red];\n", i, j , M[i][j].nome);
						mudou = 1;
					}
				}
				
				if(mudou != 1){
					fprintf(saida, "\t%d -> %d[style=bold,label=""%s""];\n", i, j , M[i][j].nome);//M[i][j].distancia);
				}
				mudou = 0;
			}			
		}
	}
	fprintf(saida,"}");
	fclose(saida);
	system("dot -Tpng caminho_curto.dot > caminho_curto.png");
}


void gera_caminho_rapido(Rua_t**  M, int* caminho, int origem, int destino, int tam_caminho){
	int i, j, atual, mudou=0;
	FILE* saida;
	saida = fopen("caminho_rapido.dot", "w");

	fprintf(saida,"digraph{\n");
	for(i=0; i < numero_vertices; i++){
		for(atual=0; atual < tam_caminho; atual++){
			if(caminho[atual] == i){
				if(i == destino){
					fprintf(saida,"\t %d[shape=box, style=filled,color=""green""];\n", i);
				}else if(i == origem){
					fprintf(saida,"\t %d[shape=box, style=filled,color=""red""];\n", i);	
				}else if (i != origem && i != destino){
					fprintf(saida,"\t %d[shape=box, style=filled,color=""yellow""];\n", i);	
				}

				mudou = 1;
			}
		}
		if(mudou != 1){
			fprintf(saida,"\t %d[shape=box, style=filled,color=""gray""];\n", i);
		}
		mudou = 0;
	}

	mudou = 0;

	for(i = 0; i < numero_vertices; i++){
		for(j = 0; j < numero_vertices; j++){
			if(M[i][j].transito != 0){
				for(atual=0; atual< tam_caminho-1; atual++){
					if(caminho[atual] == i && caminho[atual+1] == j){
						fprintf(saida, "\t%d -> %d[style=bold,label=""%s"", color=red];\n", i, j , M[i][j].nome);
						mudou = 1;
					}
				}
				
				if(mudou != 1){
					fprintf(saida, "\t%d -> %d[style=bold,label=""%s""];\n", i, j , M[i][j].nome);//M[i][j].distancia);
				}
				mudou = 0;
			}			
		}
	}
	fprintf(saida,"}");
	fclose(saida);
	system("dot -Tpng caminho_rapido.dot > caminho_rapido.png");
}
