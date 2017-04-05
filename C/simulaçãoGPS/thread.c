#include <Mapa.h>  
//===================  EXECUÇÃO -lpthread

void *modifica(void* thread_id){
	int i, j, nunca_para=1;
	Rua_t **rua_thread;
	rua_thread = (Rua_t**)malloc(numero_vertices*(sizeof(Rua_t*)));
	for(i=0; i<numero_vertices; i++){
		rua_thread[i] = (Rua_t*)malloc(numero_vertices*(sizeof(Rua_t)));
	}
	rua_thread = (Rua_t **)thread_id;

	while(nunca_para == 1){
		sleep(TEMPO_ATUALIZACAO);  
		
		for(i=0; i<numero_vertices; i++){
			for(j=0; j<numero_vertices; j++){
				if(rua_thread[i][j].transito != 0) { //Madrugada
					if (hora > 0 && hora < 6){						
						rua_thread[i][j].transito = 1;
					}
					else if ((hora >= 6 && hora < 8) || (hora >= 12 && hora < 14) || (hora >= 19 && hora < 20)){ //Horarios com muito movimento
						if(rua_thread[i][j].tipo_rua == 3){
							rua_thread[i][j].transito = (rand()%3) + 3;
						}
						else if (rua_thread[i][j].tipo_rua == 2){
							rua_thread[i][j].transito = (rand()%4) + 1;
						}
						else{
							rua_thread[i][j].transito = (rand()%2) + 1;
						}
					}else if ((hora > 8 && hora <= 12) || (hora > 14 && hora <= 17) || (hora > 20 && hora <= 24)){ //Horarios "normais"
								if(rua_thread[i][j].tipo_rua == 3){
									rua_thread[i][j].transito = (rand()%3) + 3;
								}
								else if (rua_thread[i][j].tipo_rua == 2){
									rua_thread[i][j].transito = (rand()%4) + 1;
								}
								else{
									rua_thread[i][j].transito = (rand()%2) + 1;
								}
					}


					if(rua_thread[i][j].transito == 1){
						rua_thread[i][j].velocidade_atual = rua_thread[i][j].velocidade_minima;
					}else if(rua_thread[i][j].transito == 2){
						rua_thread[i][j].velocidade_atual = 1.25 * rua_thread[i][j].velocidade_minima;
					}else if(rua_thread[i][j].transito == 3){
						rua_thread[i][j].velocidade_atual = 1.5 * rua_thread[i][j].velocidade_minima;
					}else if(rua_thread[i][j].transito == 4){
						rua_thread[i][j].velocidade_atual = 1.75 * rua_thread[i][j].velocidade_minima;
					}else if(rua_thread[i][j].transito == 5){
						rua_thread[i][j].velocidade_atual = 2 * rua_thread[i][j].velocidade_minima;
					}
				}
			}
		}

		hora++;
		if (hora == 24){
			hora = 0;
			dia++;
			if (dia == 7)
				dia = 0;
		}
	}
}

