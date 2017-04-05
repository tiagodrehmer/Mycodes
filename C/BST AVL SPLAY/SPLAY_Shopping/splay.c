#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

/* MENSAGEM DE DEBUG
#if defined(debug_splay)
		printf ("[DEBUG]\n");
#endif
*/

struct node_product { 
	char name[128], fabricator[128], model[128];
	int code, year;
	float value;
	struct node_product *left, *right, *father;
};typedef struct node_product node_product_t;

/*Criação do tipo estruturado com informações da categoria*/
struct node_category{
	char name[128];
	int code;
	struct node_product *root_product;
	struct node_category *left, *right, *father;	
};typedef struct node_category node_category_t;

/*Inicializaçaõ de uma variavel de tipo categoria*/
void init_category (node_category_t *category){
	memset(category->name, '\0', strlen(category->name));
	category->code = 0;
	category->root_product = NULL;
	category->left = NULL;
	category->right = NULL;
	category->father = NULL;
}

/*Inicializaçaõ de uma variavel de tipo produto*/
void init_product (node_product_t *product){
	memset(product->name, '\0', strlen(product->name));
	memset(product->fabricator, '\0', strlen(product->fabricator));
	memset(product->model, '\0', strlen(product->model));
	product->code = 0;
	product->year = 0;
	product->value = 0.0;
	product->left = NULL;
	product->right = NULL;
	product->father = NULL;
}

node_product_t *zig_left_product(node_product_t* node_up){
	node_product_t *aux = NULL;// cria um auxiliar pai

	aux = node_up->right;
	node_up->right = aux->left; 
	aux->left = node_up;
	#if defined(debug_splay)
		printf ("\t[DEBUG - CAEGORY] zig - left \n");
	#endif
	return aux;
}

node_product_t *zig_right_product(node_product_t* node_up){
	node_product_t *aux = NULL; //cria um auxiliar pai


	aux = node_up->left;
	node_up->left = aux->right; 
	aux->right = node_up; 
	#if defined(debug_splay)
		printf ("\t[DEBUG - CATEGORY] zig - right \n");
	#endif
	return aux;
}

node_product_t* splay_product(node_product_t* new_root){
	while (new_root->father != NULL){//Quando o pai for nullo ja é a raiz
		if (new_root->father->code > new_root->code){ // pai > filho
			/*zig*/

			if (new_root->father->father == NULL){// avo = NULL
				#if defined(debug_splay)
					printf ("[DEBUG - PRODUCT] pai > filho & avo = NULL\n");
				#endif
				new_root = zig_right_product(new_root); // gira direita filho
				#if defined(debug_splay)
					printf ("  [DEBUG - CATEGORY] Girei a direita filho - ZIG\n");
				#endif
			}
			/*zig-zig*/
			else if (new_root->father->father->code > new_root->father->code){// vo > pai
				#if defined(debug_splay)
					printf ("[DEBUG - PRODUCT] pai > filho & vo > pai\n");
				#endif
				new_root = zig_left_product(new_root->father);// gira esquerda pai
				#if defined(debug_splay)
					printf ("  [DEBUG - PRODUCT] Girei a esquerda pai\n");
				#endif
				new_root->father->father->left = new_root; // o ponteiro para o filho da esquerda do avo do up, agora aponta para o up
				new_root = zig_left_product(new_root); // gira esquerda filho
				#if defined(debug_splay)
					printf ("  [DEBUG - PRODUCT] Girei filho esquerda - ZIG ZIG\n\n");
				#endif
			}
			/*zig-zag*/
			else { // vo < pai
				#if defined(debug_splay)
					printf ("[DEBUG - PRODUCT] pai > filho & vo < pai \n");
				#endif
				new_root = zig_left_product(new_root); //gira esquerda filho;
				#if defined(debug_splay)
					printf ("  [DEBUG - PRODUCT] Girei esquerda filho\n");
				#endif
				new_root->father->father->right = new_root; // o ponteiro para o filho da direita do avo do up, agora aponta para o up
				new_root = zig_right_product(new_root); // gira direita filho;
				#if defined(debug_splay)
					printf ("  [DEBUG - PRODUCT] Girei direita filho - ZIG ZAG\n\n");
				#endif
			}
		}
		else { // pai < filho
			/*zig*/
			if (new_root->father->father == NULL){ // vo == NULL
				#if defined(debug_splay)
					printf ("[DEBUG - PRODUCT] pai < filho & vo = NULL;\n");
				#endif
				new_root = zig_left_product(new_root->father); // gira esquerda filho
				#if defined(debug_splay)
					printf ("  [DEBUG - CATEGORY] Girei esquerda filho - ZIG\n\n");
				#endif
			}
			/*zig-zag*/
			else if (new_root->father->father->code > new_root->father->code){ // vo > pai
				#if defined(debug_splay)
					printf ("[DEBUG - PRODUCT] pai < filho & vo > pai; \n");
				#endif
				new_root = zig_right_product(new_root->father); //gira direita filho
				#if defined(debug_splay)
					printf ("  [DEBUG - PRODUCT] Girei direita filho\n");
				#endif
				new_root->father->father->left = new_root; // o ponteiro para o filho da esquerda do avo do up, agora aponta para o up
				new_root = zig_left_product(new_root->father); // gira esquerda filho
				#if defined(debug_splay)
					printf ("  [DEBUG - PRODUCT] Girei esquerda filho - ZIG ZAG \n\n");
				#endif
			}
			/*zig-zig*/
			else{ // vo < pai
				#if defined(debug_splay)
					printf ("[DEBUG - PRODUCT] pai < filho & vo < pai;\n");
				#endif
				new_root = zig_right_product(new_root->father); // gira direita pai
				#if defined(debug_splay)
					printf ("  [DEBUG - PRODUCT] Girei direita pai\n");
				#endif
				new_root->father->father->right = new_root; // o ponteiro para o filho da direita do avo do up, agora aponta para o up
				new_root = zig_right_product(new_root->father); // gira direita filho
				#if defined(debug_splay)
					printf ("  [DEBUG - PRODUCT] Girei direita filho - ZIG ZIG\n\n");
				#endif
			}
		}	 
	}
	return new_root;
} 

node_category_t *zig_left_category(node_category_t* node_down){
	node_category_t *node_up = NULL;// cria um auxiliar node_up

	node_up = node_down->right;
	node_down->right = node_up->left; 
	node_up->left = node_down;
	node_down->father = node_up;
	#if defined(debug_splay)
		printf ("\t[DEBUG - CAEGORY] zig - left \n");
	#endif
	return node_up;
}

node_category_t *zig_right_category(node_category_t* node_down){
	node_category_t *node_up = NULL; //cria um auxiliar node_up


	node_up = node_down->left;
	node_down->left = node_up->right; 
	node_up->right = node_down; 
	node_down->father = node_up;
	#if defined(debug_splay)
		printf ("\t[DEBUG - CATEGORY] zig - right \n");
	#endif
	return node_up;
}

node_category_t* splay_category(node_category_t *new_root){
	
	while (new_root->father != NULL){//porque Quando o pai for nullo entao estamos na raiz
		
		if (new_root->father->code > new_root->code){ // pai > filho
			/*zig*/
			if ((new_root->father)->father == NULL){// avo = NULL
				#if defined(debug_splay)
					printf ("[DEBUG - CATEGORY] pai > filho & avo = NULL\n");
				#endif
				new_root = zig_right_category(new_root->father); // gira  pai
				new_root->father = NULL;
				#if defined(debug_splay)
					printf ("[DEBUG - CATEGORY] Girei a direita filho - ZIG\n");
				#endif
					break;
			}
			/*zig-zig*/
			else if (new_root->father->father->code > new_root->father->code){// vo > pai
				#if defined(debug_splay)
					printf ("[DEBUG - CATEGORY] pai > filho & vo > pai\n");
				#endif
				new_root = zig_right_category(new_root->father);// gira direita pai -  
				#if defined(debug_splay)
					printf ("  [DEBUG - CATEGORY] Girei a direita pai\n");
				#endif
				new_root->father->father->left = new_root; // o ponteiro para o filho da esquerda do avo do up, agora aponta para o up
				new_root->father = new_root->father->father; //novo pai do no up eh o antigo avo dele
				new_root = zig_right_category(new_root->father); // gira direita avo (atual pai)
				#if defined(debug_splay)
					printf ("  [DEBUG - CATEGORY] Girei filho direita - ZIG ZIG\n\n");
				#endif
			}
			/*zig-zag*/
			else { // vo < pai
				#if defined(debug_splay)
					printf ("[DEBUG - CATEGORY] pai > filho & vo < pai \n");
				#endif
				new_root = zig_right_category(new_root->father); //gira direita pai;
				#if defined(debug_splay)
					printf ("  [DEBUG - CATEGORY] Girei direita pai\n");
				#endif
				new_root->father->father->right = new_root; // o ponteiro para o filho da direita do avo do up, agora aponta para o up
				new_root->father = new_root->father->father;
				new_root = zig_left_category(new_root->father); // gira esquerda avo (atual pai);
				#if defined(debug_splay)
					printf ("  [DEBUG - CATEGORY] Girei esquerda avo (atual pai) - ZIG ZAG\n\n");
				#endif
			}
		}
		else { // pai < filho
			/*zig*/
			#if defined(debug_splay)
				printf ("[DEBUG - CATEGORY] pai < filho & vo = NULL;\n");
			#endif
			if (new_root->father->father == NULL){ // vo == NULL
				new_root = zig_left_category(new_root->father); // gira esquerda pai
				#if defined(debug_splay)
					printf ("  DEBUG - CATEGORY] Girei esquerda pai - ZIG\n\n");
				#endif 
			}
			/*zig-zag*/
			else if (new_root->father->father->code > new_root->father->code){ // vo > pai
				#if defined(debug_splay)
					printf ("[DEBUG - CATEGORY] pai < filho & vo > pai; \n");
				#endif
				new_root = zig_left_category(new_root->father); //gira left pai
				#if defined(debug_splay)
					printf ("  [DEBUG - CATEGORY] Girei esquerda pai\n");
				#endif
				new_root->father->father->left = new_root; // o ponteiro para o filho da esquerda do avo do up, agora aponta para o up
				new_root->father = new_root->father->father;
				new_root = zig_right_category(new_root->father); // gira direita vo (atual pai)
				#if defined(debug_splay)
					printf ("  [DEBUG - CATEGORY] Girei direita vo (atual pai) - ZIG ZAG \n\n");
				#endif

			}
			/*zig-zig*/
			else{ // vo < pai
				#if defined(debug_splay)
					printf ("[DEBUG - CATEGORY] pai < filho & vo < pai;\n");
				#endif
				new_root = zig_left_category(new_root->father); // gira esquerda pai
				#if defined(debug_splay)
					printf ("  [DEBUG - CATEGORY] Girei esquerda pai\n");
				#endif
				new_root->father->father->right = new_root; // o ponteiro para o filho da direita do avo do up, agora aponta para o up
				new_root->father = new_root->father->father;
				new_root = zig_left_category(new_root->father); // gira esquerda avo (atual pai)
				#if defined(debug_splay)
					printf ("  [DEBUG - CATEGORY] Girei esquerda avo (atual pai) - ZIG ZIG\n\n");
				#endif
			}
		}	 
	}
	return new_root;
} 

//função de put_product 
node_product_t* put_product (node_product_t* root_product, node_product_t *data_product){
	//cont_categ++;
	node_product_t *father = NULL;
	if (root_product == NULL){
		root_product = (node_product_t*) malloc(sizeof(node_product_t));
		init_product(root_product);
		memcpy(root_product, data_product, sizeof(node_product_t));
		#if defined(debug_splay)
			printf ("[DEBUG - PRODUCT] Inseri na raiz\n");
		#endif
	}
	else {
		while(root_product != NULL){
			if (root_product->code > data_product->code){
				father = root_product;
				root_product = root_product->left;
			}
			else if (root_product->code < data_product->code){
				father = root_product;
				root_product = root_product->right;
			}
			else{
				memcpy(root_product, data_product, sizeof(node_product_t));
				root_product->father = father;
				break;
			}
			if (root_product == NULL){
				root_product = (node_product_t*) malloc(sizeof(node_product_t));
				init_product(root_product);
				memcpy(root_product, data_product, sizeof(node_product_t));
				#if defined(debug_splay)
					printf ("[DEBUG - PRODUCT] Inseri produto - ja existe raiz\n");
				#endif
				root_product->father = father;
			}
		}
	}
	//root_product = splay_product(root_product);
	#if defined(debug_splay)
		printf ("[DEBUG - PRODUCT] Balanciei a arvore de produto\n");
	#endif
	return root_product;
}

//mesma função de put_product só que para arvores de categorias
node_category_t* put_category (node_category_t* root_category, node_category_t *data_category, node_product_t *data_product){
	//cont_categ++;
	node_category_t *father = NULL;
	if (root_category == NULL){
		root_category = (node_category_t*) malloc(sizeof(node_category_t));
		init_category(root_category);
		#if defined(debug_splay)
			printf ("[DEBUG - CATEGORY] criei a arvore\n");
		#endif
		memcpy(root_category, data_category, sizeof(node_category_t));
		root_category->root_product = put_product(root_category->root_product, data_product);

		#if defined(debug_splay)
			printf ("[DEBUG - CATEGORY] Inseri o produto\n");
		#endif
		
	}
	else {
		#if defined(debug_splay)
			printf ("[DEBUG - CATEGORY] raiz != NULL\n");
			printf ("[DEBUG - CATEGORY] raiz do momento = %d\n", root_category->code);
		#endif
		while(root_category != NULL){
			father = root_category;
			if (root_category->code > data_category->code){
				#if defined(debug_splay)
					if (root_category->left){
						printf ("[DEBUG - CATEGORY] O filho atual da esquerda eh o %d\n", root_category->left->code);
					}
				#endif
				root_category = root_category->left;
				#if defined(debug_splay)
					printf ("[DEBUG - CATEGORY] vou encontrar o lugar de insercao - fui pra esquerda\n");
				#endif
			}
			else if (root_category->code < data_category->code){
				#if defined(debug_splay)
					if (root_category->right){
						printf ("[DEBUG - CATEGORY] O filho atual da direita eh o %d\n", root_category->right->code);
					}
				#endif
				root_category = root_category->right;
				#if defined(debug_splay)
					printf ("[DEBUG - CATEGORY] vou encontrar o lugar de insercao - fui pra direita\n");	
				#endif
			}
			else{
				root_category->root_product = put_product(root_category->root_product, data_product); //insere o produto
				#if defined(debug_splay)
					printf ("[DEBUG CATEGORY] Inseri o produto\n");
					printf ("[DEBUG CATEGORỸ] Nao foi necessario levar o noh para a raiz\n\n");
				#endif
				return root_category;
			}
		}
		if (root_category == NULL){
			root_category = (node_category_t*) malloc(sizeof(node_category_t));
			init_category(root_category);
			#if defined(debug_splay)
				printf ("[DEBUG - CATEGORY] Inseri categoria na arvore - ja tinha raiz\n");
			#endif
			memcpy(root_category, data_category, sizeof(node_category_t));
			root_category->father = father; //ajeita o ponteiro pra pai do novo noh	
			#if defined(debug_splay)
				printf ("[DEBUG - CATEGORY] Pai do noh %d eh a categoria %d\n", root_category->code, root_category->father->code);
			#endif
			root_category->root_product = put_product(root_category->root_product, data_product); //insere o produto
			#if defined(debug_splay)
				printf ("[DEBUG - CATEGORY] Inseri produto\n");
			#endif
		}	
	}
	root_category = splay_category(root_category);
	#if defined(debug_splay)
		printf ("[DEBUG - CATEGORY] Levei o noh pra raiz da arvore de categorias\n\n");
	#endif
	return root_category;
}

void inorder_product (node_product_t *root_product){
	if (root_product != NULL){	
		inorder_product (root_product->left);
		printf ("\t%s\t%d\t%s\t%d\t%s\t%.2f \t\n", root_product->name, root_product->code, root_product->fabricator, root_product->year, root_product->model, root_product->value);
		inorder_product (root_product->right);
	}
}

//função para printar em ordem a arvore de categorias junto com o print da arvore de produtos também em ordem
void inorder_all(node_category_t *root_category){
	if (root_category != NULL){	
		inorder_all (root_category->left); //vai até a esquerda
		printf ("\n|======================================================================================|\n");// destaca as arvores de categorias
		printf ("\t\t\tCategoria: %s\t\tCodigo: %d\t\t\t\t\n\n", root_category->name, root_category->code);// printa o codigo e nome
		printf ("\t  Produto     Codigo \tFabricante\t Ano\t Modelo \t Preco \t \n");
		inorder_product(root_category->root_product); // printa a arvore de produtos em ordem
		printf ("|======================================================================================|\n"); // destaca as arvores de categorias
		inorder_all (root_category->right);// vai para direita depois de tudo
	}

}



int main(int argc, char **argv){
	node_category_t data_category;
	node_product_t data_product;
	node_category_t* root_category=NULL;
	FILE *put;
	char datas[320], x;
	int qtd_elements = 0;
	
	if (argc < 2){
		printf ("argumentos invalidos!\n");
	}	
	put = fopen (argv[1], "r");
	if (!put){
		 return -1;
	}
	#if defined(debug_splay)
		printf ("\n\n\t**MODO DEBUGGER ATIVADO**\n\n");
	#endif
	init_category(&data_category);
	init_product(&data_product);

	while (fscanf(put, "%s\n", datas)!=EOF){
		qtd_elements = sscanf(datas, "%[^;];%d;%[^;];%d;%[^;];%[^;];%d;%f%c",  data_category.name, &data_category.code, data_product.name, &data_product.code, data_product.fabricator, data_product.model,&data_product.year, &data_product.value, &x) ;
		if (qtd_elements == 8){
			#if defined(debug_splay)
				printf ("[DEBUG] Vou inserir categoria %d - produto %d\n", data_category.code, data_product.code);
			#endif
			root_category = put_category(root_category, &data_category, &data_product);

		}
		init_category(&data_category);			
		init_product(&data_product);		
	}//fim while
	inorder_all(root_category);
	free (root_category);
	fclose(put);
	return 0;
}

