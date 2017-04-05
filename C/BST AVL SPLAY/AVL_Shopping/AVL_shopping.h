/* BUG's emplementados por:
	*G U S T A V O    C R O D - 151151360
	*R O D R I G O    B I S S O - 151150178
	*T I A G O    D R E H M E R  - 151150180

*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

/*Criação do tipo estruturado com informações do produto*/
struct node_product {
	char name[128], fabricator[128], model[128];
	int code, year;
	float value;
	struct node_product *left, *right;
};typedef struct node_product node_product_t;

/*Criação do tipo estruturado com informações da categoria*/
struct node_category{
	char name[128];
	int code;
	struct node_product *root_product;
	struct node_category *left, *right;
};typedef struct node_category node_category_t;

int avl_balance_factor_category( node_category_t *node_category ); //funcao de bf
node_category_t *avl_single_rotate_right_category( node_category_t *node_category ); //funcao de rotacao a direita
node_category_t *avl_double_rotate_right_category( node_category_t *node_category ); // funcao de rotacao direita direita
node_category_t *avl_double_rotate_left_category( node_category_t *node_category ); //funcao de ]rotacao dupla a esquerda
node_category_t *avl_simgle_rotate_left_category( node_category_t *node_category ); //funcao de rotacao a esquerda
node_category_t *avl_balance_category( node_category_t *node_category); //funcao de balanceamento da categoria
int avl_balance_factor_product( node_product_t *node_product ); //funcao de bf dos produtos (altura)
node_product_t *avl_single_rotate_right_product( node_product_t *node_product ); //funcao de rotacao a direita produtos
node_product_t *avl_double_rotate_right_product( node_product_t *node_product ); //funcao de rotacao a direita e direita produtos
node_product_t *avl_double_rotate_left_product( node_product_t *node_product ); //funcao de dupla rotacao a esquerda produtos
node_product_t *avl_single_rotate_left_product( node_product_t *node_product );// funcao de rotacao a esquerda produtos
node_product_t *avl_balance_product( node_product_t *node_product); //funcao de balanceamento da arvore de produtos
void init_category (node_category_t *category); //Inicializacao de uma variavel de tipo categoria
void init_product (node_product_t *product); //Inicializacao de uma variavel de tipo produto
int maior (int a, int b); //função para auxiciliar height
int height_categ (node_category_t* root_category); //funcao para ver altura de uma arvore de categoria
int height_product (node_product_t* root_product); //função para ver altura de uma arvore de produtos
node_product_t* put_product (node_product_t* root_product, node_product_t* data_product); //Inserção de um produto na arvore de produtos
node_category_t* put_category (node_category_t* root_category, node_category_t* data_category, node_product_t *data_product); //mesma função de put_product só que para arvores de categorias
int contains_categ(node_category_t *root_category, int search_code); //função para verificar a existencia ou não de uma categoria
int contains_product(node_product_t *root_product, int search_code); //Mesma logica da de categorias
int rank_categ (node_category_t* root_category, int search_code); // função para ver o rank de um nó
int rank_product (node_product_t* root_product, int search_code); //Mesma logica da de categorias
node_category_t* get_category (node_category_t* root_category, int search_code); //função para pegar um nó da arvore de categoria
node_product_t* get_product (node_product_t* root_product, int search_code); //Função para pegar um nó da arvore de produtos
node_category_t* min_categ(node_category_t *root_category); //Função para encontrar o nó mais a esquerda da arvore de categorias
node_category_t* max_categ (node_category_t *root_category); //Função para encontrar o nó mais a direita da arvore de categorias
node_product_t* min_product (node_product_t *root_product); //Função para encontrar o nó mais a esquerda da arvore de produtos
node_product_t* max_product (node_product_t *root_product); //Função para encontrar o nó mais a esquerda da arvore de produtos
node_product_t* delete_all_products(node_product_t* root_product); //Função para liberar toda a arvore de produtos
node_category_t* aux_delete_category (node_category_t *node_delete); //Função de auxilio para deletar uma categoria
node_category_t  *delete_category (node_category_t  *root_category, int code_search); //Função para deletar uma categoria
node_product_t* aux_delete_product (node_product_t *node_delete); //Mesmos comentarios da de deletar categorias
node_product_t  *delete_product (node_product_t  *root_product, int code_search); //Mesmos comentarios da de deletar categorias
int size_categ (node_category_t* node_category); //Função para saber o tamanho de um nó de categoria
int size_product (node_product_t* node_product); //Função para saber o tamanho de um nó da arvore de produtos
int ceiling_categ (node_category_t *root_category, int code_search); //funcao para encontrar o ceil de uma categoria
int ceiling_product(node_product_t *root_product, int code_search); //funcao para encontrar o ceil de um produto
int floor_categ(node_category_t *root_category, int code_search); //funcao para encontrar o floor de uma categoria
int floor_product(node_product_t *root_product, int code_search); //function para encontrar o floor de um produto
void inorder_product (node_product_t *root_product); //função para printar em ordem a arvore de rodutos
void inorder_all(node_category_t *root_category); //função para printar em ordem a arvore de categorias junto com o print da arvore de produtos também em ordem
//As funções daqui:
//======================================================================================================================
void max_all (node_category_t *root_category);
void min_all (node_category_t *root_category);
void height_all (node_category_t *root_category);
void size_all_prod(node_product_t* root_product);
void size_all (node_category_t *root_category);
//até aqui, são funções de auxilio pra printar o que for desejado de todas as arvores existentes
//======================================================================================================================
node_category_t free_all_categ (node_category_t* root_category); //função de liberação de toda arvore de categorias
int arquivos_check(char opcao, FILE* arquivo); //Função para checar o arquivo
node_category_t *recept_put(FILE* put, node_category_t* root_category); //funcao para descobrir o tipo de separados - funcao auxiliar para put
node_category_t* aplication_delete(FILE* del, node_category_t* root_category);
void aplication_ceiling(FILE *ceiling, node_category_t* root_category);
void aplication_floor(FILE *flooor, node_category_t* root_category);
void aplication_rank(FILE *rank, node_category_t* root_category);
void aplication_contain(FILE *contain, node_category_t* root_category);
void aplication_get(FILE *get, node_category_t* root_category);
void help(); //funcao exibe ajuda
