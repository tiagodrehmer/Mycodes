#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h> 
#include <math.h>
#include <unistd.h>

#define TAMANHO_NOME 128
#define TEMPO_ATUALIZACAO 5
#define MENU_MAX 3

struct Rua {

	char nome[TAMANHO_NOME];
	int distancia;
	int transito;	//Define o nível de trânsito da rua, variando de 1 a 5 [1-Pouco Trânsito e 5-Muito Trânsito]
	int velocidade_minima;
	double velocidade_atual;
	int tipo_rua; // tipo 3 = movimentada, 2 = medio, 1 = pouco movimentada
	int visitado;

};typedef struct Rua Rua_t;

struct vetor_passeio{
		int visita;
}; typedef struct vetor_passeio passeio_t;
 
int hora, dia;
int numero_vertices;
int para_interface;
int para_print_transito;

//leitura.c
Rua_t** libera_matriz(Rua_t **matriz);

int percorre_matriz (Rua_t **matriz, int i, int j, passeio_t* passeio);

int testa_matriz (Rua_t **matriz);

Rua_t** ler_entrada(Rua_t **matriz, char *arquivo); //ler_entrada_f

Rua_t** insere_rua(Rua_t **matriz, int linha, int coluna, char *nome, int distancia, int transito, int velocidade_minima, int tipo_rua);

Rua_t** init_matriz(Rua_t **matriz);

//thread.c
void *modifica(void* thread_id);

//distrak.c
int* dijkstra_distancia(Rua_t **matriz, int* caminho, int origem, int destino);

int* dijkstra_tempo(Rua_t **matriz, int* caminho, int origem, int destino);

void mostra_caminho(int origem, int destino, int* caminho);

//interface.c
char* dia_da_semana();

void *interface(void* thread_id);

void* printa_transito(void* thread_id);

void menu(Rua_t** matriz);

//dots.c
void gera_mapa(Rua_t**  matriz);

void gera_caminho_curto(Rua_t**  M, int* caminho, int origem, int destino, int tam_caminho);

void gera_caminho_rapido(Rua_t**  M, int* caminho, int origem, int destino, int tam_caminho);
