#include <Mapa.h>

char* dia_da_semana(){

	char* dia_semana;
	dia_semana = (char*)malloc(20*sizeof(char));

	strcpy(dia_semana,"");

	if(dia == 1){
		strcpy(dia_semana, "Domingo");
	}

	if(dia == 2){
		strcpy(dia_semana, "Segunda-Feira");
	}

	if(dia == 3){
		strcpy(dia_semana, "Terca-Feira");
	}

	if(dia == 4){
		strcpy(dia_semana, "Quarta-Feira");
	}

	if(dia == 5){
		strcpy(dia_semana, "Quinta-Feira");
	}

	if(dia == 6){
		strcpy(dia_semana, "Sexta-Feira");
	}

	if(dia == 7){
		strcpy(dia_semana, "Sábado");
	}

	return dia_semana;
}


void *interface(void* thread_id){
	while (para_interface){
		system("clear");
		printf("Dia: %s, Hora: %d:00\n", dia_da_semana(), hora);
		printf("1 - Buscar Caminho\n");
		printf("2 - Gerar Mapa\n");
		printf("3 - Boletim do Trânsito\n");
		printf("4 - Sair do Programa\n");
		sleep(1);
	}
}

void* printa_transito(void* thread_id){
	int i, j, k, z;
	Rua_t **matriz;
	matriz = (Rua_t**)malloc(numero_vertices*(sizeof(Rua_t*)));
	for(i=0; i<numero_vertices; i++){
		matriz[i] = (Rua_t*)malloc(numero_vertices*(sizeof(Rua_t)));
	}
	matriz = (Rua_t **)thread_id;

	while (para_print_transito){
		system("clear");
		printf("Trânsito atualizado: \n");
		printf("%s, Hora: %d:00\n", dia_da_semana(), hora);	
		
		for(i=0; i < numero_vertices; i++){
			for(j=0; j < numero_vertices; j++){
				if(matriz[i][j].transito != 0 && matriz[i][j].visitado == 0){
					matriz[i][j].visitado = 1;
					printf("| %s |->", matriz[i][j].nome);
					
					for(k=0; k < numero_vertices; k++){
						for(z=0; z < numero_vertices; z++){
							if( matriz[i][j].transito != 0 && matriz[k][z].visitado == 0){
								if(strncmp(matriz[i][j].nome, matriz[k][z].nome, TAMANHO_NOME) == 0 ){
									printf(" %d ", matriz[k][z].transito);
									matriz[k][z].visitado = 1;
								}
							}
						}
					}

					printf("\n");
				}
			}			
		}

		for(i=0; i < numero_vertices; i++){
			for(j=0; j < numero_vertices; j++){
				matriz[i][j].visitado = 0;
			}
		}
		printf ("\n Aperte um botao + enter para sair \n");
		
		sleep(TEMPO_ATUALIZACAO);
	}	
}

void menu(Rua_t** matriz){
	int nunca_para = 1, i, j, k, z, pos=0, origem = -1, destino = -1, *caminho_distancia, *caminho_tempo;
	char opcao;
	while (nunca_para == 1){
		pthread_t thread_interface, thread_transito;
		int execute, execute2;
		para_interface = 1;
		execute = pthread_create(&thread_interface, NULL, interface, NULL);
		__fpurge(stdin);
		opcao = getc(stdin);
		switch(opcao){
			case '1':
				para_interface = 0;
				system("clear");
				while(origem < 0 || origem > numero_vertices){
					printf("Informe seu cruzamento de origem:");
					__fpurge(stdin);
					scanf("%d", &origem);
				}
				while(destino < 0 || destino > numero_vertices){
					printf("Informe ses cruzamento destino:");
					__fpurge(stdin);
					scanf("%d", &destino);
				}
				printf("Buscando caminho...\n\n");

				caminho_tempo = dijkstra_tempo(matriz, caminho_tempo, origem, destino);
				mostra_caminho(origem,destino, caminho_tempo);
				free(caminho_tempo);
				
				printf("\n");

				caminho_distancia = dijkstra_distancia(matriz, caminho_distancia, origem, destino);
				mostra_caminho(origem,destino, caminho_distancia);
				free(caminho_distancia);
				
				origem = destino = -1;
				printf("\n");

				sleep(3);
			break;

			case '2':
				para_interface = 0;
				system("clear");
				printf("Gerando mapa...\n");
				sleep(0.5);
				gera_mapa(matriz);
				printf("Mapa gerado com sucesso\n");
				sleep(1);
			break;

			case '3':
				para_interface = 0;
				para_print_transito = 1;
				system("clear");
				printf ("Carregando transito... \n");
				execute2 = pthread_create(&thread_transito, NULL, printa_transito, (void *)matriz);
				__fpurge(stdin);
				getc(stdin);
				para_print_transito = 0;
				system("clear");
				printf("Voltando ao menu, espere um momento...");
				sleep(TEMPO_ATUALIZACAO);			
			break;

			case '4':
				para_interface = 0;
				printf("Saindo do Programa\n");
				exit(1);
			break;

			default:
				para_interface = 0;
				sleep(1);
			break;
		}
	}
}

// void scanf_menu (Rua_t ** matriz){
// 	int execute;
// 	pthread_t thread;
// 	srand(time(NULL));
// 	execute = pthread_create(&thread , NULL, menu, (void *)matriz);
// }






/*
	desenha_menu(menuitem, matriz);
	keypad(stdscr,TRUE);
	noecho();	
	initscr();		
	do{
		key = getch();
		switch(key){
			case KEY_DOWN:
				menuitem++;
				if(menuitem > MENU_MAX-1){
					menuitem = 0;
				}
				break;

			case KEY_UP:
				menuitem--;
				if(menuitem < 0){
					menuitem = MENU_MAX-1;
				}
				break;

			default:
				break;
		}
		desenha_menu(menuitem, matriz);
	} while(key != '\n');
	echo();
	endwin();
	system("clear");

	switch(menuitem){
		case 0:
			while(origem < 0 || origem > numero_vertices){
				printf("Informe sua origem:");
				scanf("%d", &origem);
			}
			while(destino < 0 || destino > numero_vertices){
				printf("Informe seu destino:");
				scanf("%d", &destino);
			}
			printf("Buscando caminho...\n");
			caminho = dijkstra(matriz, caminho, origem, destino);
			//mostra_caminho(origem,destino, caminho);
			sleep(5);
		break;

		case 1:
			printf("Gerando mapa...\n");
			sleep(1);
			gera_mapa(matriz);
			printf("Mapa gerado com sucesso\n");
			sleep(1);
		break;

		case 2:
			printf("Saindo do Programa\n");
			exit(1);
		break;

		default:
		break;
	}
	scanf_menu(matriz);*/