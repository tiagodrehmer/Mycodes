/*
	bisso@bisso-HP-14-Notebook-PC:~/CC_UNIPAMPA/ED_2/BST_SHOPPING/ed2-t1-grt$ git pull
	bisso@bisso-HP-14-Notebook-PC:~/CC_UNIPAMPA/ED_2/BST_SHOPPING/ed2-t1-grt$ git add -A * 
	bisso@bisso-HP-14-Notebook-PC:~/CC_UNIPAMPA/ED_2/BST_SHOPPING/ed2-t1-grt$ git commit -m "..."
	bisso@bisso-HP-14-Notebook-PC:~/CC_UNIPAMPA/ED_2/BST_SHOPPING/ed2-t1-grt$ git push
*/

/* 
	BUG's emplementados por:
	*G U S T A V O    C R O D - 151151360 
	*R O D R I G O    B I S S O - 151150178
	*T I A G O    D R E H M E R  - 151150180
*/

/*
	NOTAS: 
		*ARRUMAR OS PONTEIROS - PRODUTOS EM CATEGORIAS ERRADAS !
		*PROBLEMA ESTAVA NA NODE_CATEGORY NULL PARA BUSCA !

	NOTAS 2:
		*QUANDO A CATEGORIA JA EXISTIA - CHAMADA DA FUNCAO DE INSERCAO DE PRODUTOS RECEBIA UM "Data_Category" COMO RAIZ
		*funcionando

*/


#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

/*Criação do tipo estruturado com informações do produto*/
struct node_product { 
	char name[128], fabricator[128], model[128];
	int code, year;
	float value;
	int height;
	struct node_product *left, *right;
};
typedef struct node_product node_product_t;

/*Criação do tipo estruturado com informações da categoria*/
struct node_category{
	char name[128];
	int code;
	int height;
	struct node_product *root_product;
	struct node_category *left, *right;	
};
typedef struct node_category node_category_t;

/*Criação do tipo estruturado com um ponteiro para a raiz da arvore de categorias*/
struct tree_category
{
	struct node_category *root;
};
typedef struct tree_category tree_category_t;



/* cria uma nova arvore AVL. */
tree_category_t *avl_create() {
	tree_category_t *tree = NULL;

	if( ( tree = malloc( sizeof( tree_category_t ) ) ) == NULL ) {
		return NULL;
	}

	tree->root = NULL;

	return tree;
}

void init_category (node_category_t *category){
	memset(category->name, '\0', strlen(category->name));
	category->code = 0;
	category->root_product = NULL;
	category->left = NULL;
	category->right = NULL;
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
}

int height_categ( node_category_t *node ) {
	int height_left = 0;
	int height_right = 0;

	if( node->left ) height_left = height_categ( node->left );
	if( node->right ) height_right = height_categ( node->right );

	return height_right > height_left ? ++height_right : ++height_left;
}

int height_product( node_product_t *node ) {
	int height_left = 0;
	int height_right = 0;

	if( node->left ) height_left = height_product( node->left );
	if( node->right ) height_right = height_product( node->right );

	return height_right > height_left ? ++height_right : ++height_left;
}

/* Find the balance of an AVL node */
int avl_balance_factor_category( node_category_t *node_category ) {
	int balance_factor = 0;

	if( node_category->left  ) balance_factor += height_categ( node_category->left );
	if( node_category->right ) balance_factor -= height_categ( node_category->right );

	return balance_factor ;
}

/* Left Left Rotate */
node_category_t *avl_single_rotate_right_category( node_category_t *node_category ) {
 	node_category_t *a = node_category;
	node_category_t *b = a->left;
	
	a->left = b->right;
	b->right = a;
	#if defined(DEBUG_ROTATION)
	printf("\n\tfiz R CATEGORY\n");
	#endif

	return( b );
}

/* Left Right Rotate */
node_category_t *avl_double_rotate_right_category( node_category_t *node_category )
{
	node_category_t *a = node_category;
	node_category_t *b = a->left;
	node_category_t *c = b->right;
	
	a->left = c->right;
	b->right = c->left; 
	c->left = b;
	c->right = a;
	#if defined(DEBUG_ROTATION)
	printf("\n\tfiz RR CATEGORY");
	#endif

	return( c );
}

/* Right Left Rotate */
node_category_t *avl_double_rotate_left_category( node_category_t *node_category )
{
	node_category_t *a = node_category;
	node_category_t *b = a->right;
	node_category_t *c = b->left;
	
	a->right = c->left;
	b->left = c->right; 
	c->right = b;
	c->left = a;
	#if defined(DEBUG_ROTATION)
	printf("\n\tfiz LL CATEGORY\n");
	#endif

	return( c );
}

/* Right Right Rotate */
node_category_t *avl_simgle_rotate_left_category( node_category_t *node_category )
{
	node_category_t *a = node_category;
	node_category_t *b = a->right;
	
	a->right = b->left;
	b->left = a; 
	#if defined(DEBUG_ROTATION)
	printf("\n\tfiz L CATEGORY\n");
	#endif

	return( b );
}


/* Balance a given node */
node_category_t* avl_balance_node_category( node_category_t *node_category )
{
	node_category_t *new_root = NULL;

	/* Balancia os filhos - se eles existirem*/
	if( node_category->left )
		node_category->left  = avl_balance_node_category( node_category->left  );
	if( node_category->right ) 
		node_category->right = avl_balance_node_category( node_category->right );

	int balance_factor = avl_balance_factor_category(node_category); // balance_factor é o calculo do fator de balanceamento;


	if( balance_factor >= 2 ) {
		/* Left Heavy */	
		if( avl_balance_factor_category( node_category->left ) <= -1 ) 
			new_root = avl_double_rotate_right_category( node_category );
		else 
			new_root = avl_single_rotate_right_category( node_category );

	} else if( balance_factor <= -2 ) {
		/* Right Heavy */
		if( avl_balance_factor_category( node_category->right ) >= 1 )
			new_root = avl_double_rotate_left_category( node_category );
		else 
			new_root = avl_simgle_rotate_left_category( node_category );

	} else {
		/* This node is balanced -- no change. */
		new_root = node_category;

	}

	return( new_root );	
}


/* Find the balance of an AVL node */
int avl_balance_factor_product( node_product_t *node_product ) {
	int balance_factor = 0;

	if( node_product->left  ) balance_factor += height_product( node_product->left );
	if( node_product->right ) balance_factor -= height_product( node_product->right );

	return balance_factor ;
}

/* Left Left Rotate */
node_product_t *avl_single_rotate_right_product( node_product_t *node_product ) {
 	node_product_t *a = node_product;
	node_product_t *b = a->left;
	
	a->left = b->right;
	b->right = a;
	#if defined(DEBUG_ROTATION)
	printf("\n\tfiz R PRODUCT\n");
	#endif

	return( b );
}

/* Left Right Rotate */
node_product_t *avl_double_rotate_right_product( node_product_t *node_product )
{
	node_product_t *a = node_product;
	node_product_t *b = a->left;
	node_product_t *c = b->right;
	
	a->left = c->right;
	b->right = c->left; 
	c->left = b;
	c->right = a;
	#if defined(DEBUG_ROTATION)
	printf("\n\tfiz RR PRODUCT\n");
	#endif

	return( c );
}

/* Right Left Rotate */
node_product_t *avl_double_rotate_left_product( node_product_t *node_product )
{
	node_product_t *a = node_product;
	node_product_t *b = a->right;
	node_product_t *c = b->left;
	
	a->right = c->left;
	b->left = c->right; 
	c->right = b;
	c->left = a;
	#if defined(DEBUG_ROTATION)
	printf("fiz LL PRODUCT\n\n");
	#endif

	return( c );
}

/* Right Right Rotate */
node_product_t *avl_single_rotate_left_product( node_product_t *node_product )
{
	node_product_t *a = node_product;
	node_product_t *b = a->right;
	
	a->right = b->left;
	b->left = a;
	#if defined(DEBUG_ROTATION)
		printf("\n\tfiz L PRODUCT\n");
	#endif

	return( b );
}


/* Balance a given node */
node_product_t* avl_balance_node_product( node_product_t *node_product )
{
	node_product_t *new_root = NULL;

	/* Balance our children, if they exist. */
	if( node_product->left )
		node_product->left  = avl_balance_node_product( node_product->left  );
	if( node_product->right ) 
		node_product->right = avl_balance_node_product( node_product->right );

	int balance_factor = avl_balance_factor_product( node_product ); // balance_factor é o calculo do fator de balanceamento;

	if( balance_factor >= 2 ) {
		/* Left Heavy */	
		if( avl_balance_factor_product( node_product->left ) <= -1 ) 
			new_root = avl_double_rotate_right_product( node_product );
		else 
			new_root = avl_single_rotate_right_product( node_product );

	} else if( balance_factor <= -2 ) {
		/* Right Heavy */

		if( avl_balance_factor_product( node_product->right ) >= 1 )
			new_root = avl_double_rotate_left_product( node_product );
		else 
			new_root = avl_single_rotate_left_product( node_product );

	} else {
		/* This node is balanced -- no change. */

		new_root = node_product;
	}

	return( new_root );	
}


void avl_put_product( node_category_t *tree, node_product_t *data_product ) {
	node_product_t *node_product = NULL;
	node_product_t *next = NULL;
	node_product_t *last = NULL;
	
	#if defined(DEBUG_PRINT)
		printf("Cheguei na funcao de insercao de produtos\n\n");
	#endif

	if( tree->root_product == NULL ) {
		
		#if defined(DEBUG_PRINT)
			printf("vou por o produto como raiz\n\n");
		#endif

		node_product = (node_product_t*) malloc(sizeof(node_product_t));
		init_product(node_product);

		#if defined(DEBUG_PRINT)
			printf("Inicializei o produto pra por ele como raiz\n");
		#endif

		memcpy(node_product, data_product, sizeof(node_product_t));
		tree->root_product = node_product;

		#if defined(DEBUG_PRINT)
			printf("Inseri produto como raiz\n\n");
		#endif

		return;

	} else {

		#if defined(DEBUG_PRINT)
			printf("Ja existe produto na raiz\n");
		#endif

		next = tree->root_product;

		while( next != NULL ) {
			last = next;
			if( data_product->code < next->code ) {
				next = next->left;

			} else if( data_product->code > next->code ) {
				next = next->right;
			/*  
			 * se ja existe um produto com o codigo inserido
			 * atualiza o antigo com os dados do novo
			 * nao precisa realocar nem acertar os ponteiros do pai
			 * nem balancear
			*/
			} else if( data_product->code == next->code ) {
				memcpy(node_product, data_product, sizeof(node_product_t));	
				return;
			}
		}

		node_product = (node_product_t*) malloc(sizeof(node_product_t));
		init_product(node_product);
		memcpy(node_product, data_product, sizeof(node_product_t));
		if( data_product->code < last->code ) last->left = node_product; //ponteiro pai
		if( data_product->code > last->code ) last->right = node_product;

	}
	#if defined(DEBUG_PRINT)
			printf("vou fazer o balanceamento da arvore de produtos\n");
	#endif
}

//mesma função de put_product só que para arvores de categorias
void avl_put_category( tree_category_t *tree, node_category_t *data_category, node_product_t *data_product ) {
	node_category_t *node_category = NULL;
	node_category_t *next = NULL;
	node_category_t *last = NULL;

	if( tree->root == NULL ) {

		node_category = (node_category_t*) malloc(sizeof(node_category_t)); //alocacao do no que vai ser a raiz
		init_category(node_category); //incializacao do no q vai ser a raiz
		memcpy(node_category, data_category, sizeof(node_category_t));
		tree->root = node_category;

		#if defined(DEBUG_PRINT)
			printf("Inseri categoria na raiz\n");
		#endif

	} else { //se ja tem raiz procura ate o lugar da categoria ser inserida
		next = tree->root;

		#if defined(DEBUG_PRINT)
			printf("next = tree->root (a partir do segundo elemento category)\n");
		#endif

		while( next != NULL ) {
			last = next;

			#if defined(DEBUG_PRINT)
				printf("last = next\n");
				printf("codigo da root_category: %d\n",next->code);
				printf("data_category->code: %d\n", data_category->code);
				if(node_category == NULL)
				{
					printf("node_category == NULL\n");
					//exit(0);
				}
			#endif

			if( data_category->code < next->code ) {
				next = next->left;
				#if defined(DEBUG_PRINT)
					printf("Codigo a ser inserido eh menor e eu fui pra esquerda\n\n");
				#endif

			} else if( data_category->code > next->code ) {
				next = next->right;
				#if defined(DEBUG_PRINT)
					printf("Codigo a ser inserido eh maior e eu fui pra direita\n\n");
				#endif

			/* se a categoria ja existe
			 * nao insere ela denovo
			 * apenas chama a insercao da arvore de produtos
			 * por isso da um return apos chamar a insercao de um produto
			 * manda o next, pois ele eh o ponteiro de percorrer
			*/

			} else if( data_category->code == next->code ) {
				#if defined(DEBUG_PRINT)
					printf("Codigo a ser inserido eh igual e eu chamei a insercao de produtos\n\n");
				#endif

				avl_put_product( next, data_product);
				node_category->root_product = avl_balance_node_product (node_category->root_product)
				return;
			}
		}//fim do while

		/* se a categoria nao existe
		 * entao eh preciso alocar dinamicamente um no pra ela
		 * acertar o ponteiro do pai e depois chamar a insercao da arvore de produtos
		 * por fim balanceala*/

		node_category = (node_category_t*) malloc(sizeof(node_category_t)); //alocacao do no que vai ser a raiz
		init_category(node_category); //incializacao do no q vai ser a raiz
		memcpy(node_category, data_category, sizeof(node_category_t));
		#if defined(DEBUG_PRINT)
			printf("Aloquei a categoria\n");
		#endif

		if( node_category->code < last->code ) {
			last->left = node_category;
			#if defined(DEBUG_PRINT)
				printf("inseri na esquerda\n");
			#endif
		}else {
			last->right = node_category;
			#if defined(DEBUG_PRINT)
				printf("inseri na direita\n");
			#endif
		}
	
	}
	#if defined(DEBUG_PRINT)
		printf("Vou ir para a put_produto\n");
		if (node_category->root_product != NULL) 
			printf ("Existe raiz de produtos\n\n");
	#endif

	avl_put_product(node_category, data_product);
	//avl_balance_category( tree );

	#if defined(DEBUG_PRINT)
			printf("Balanciei a Arvore de categs\n");
	#endif
}

//função para pegar um nó da arvore de categoria
node_category_t* get_category (node_category_t* root_category, int search_code){
	
	if(root_category == NULL){
		return NULL;
	}
	else if (root_category->code == search_code){
		return root_category;
	}
	else if (search_code > root_category->code){
		get_category(root_category->right, search_code);
	}
	else if (search_code < root_category->code){
		get_category(root_category->left, search_code);
	}

}

//função para printar em ordem a arvore de rodutos
void inorder_product (node_product_t *root_product){
	if (root_product != NULL){	
		inorder_product (root_product->left);
		printf("\t\t%s,%d\n", root_product->name, root_product->code);
		inorder_product (root_product->right);
	}
}

//função para printar em ordem a arvore de categorias junto com o print da arvore de produtos também em ordem
void inorder_all(node_category_t *root_category){
	if (root_category != NULL){	
		inorder_all(root_category->left); //vai até a esquerda
		printf("=============================\n");// destaca as arvores de categorias
		printf("%s,%d\n", root_category->name, root_category->code);// printa o codigo e nome
		inorder_product(root_category->root_product); // printa a arvore de produtos em ordem
		printf("=============================\n"); // destaca as arvores de categorias
		inorder_all (root_category->right);// vai para direita depois de tudo
	}

}
void test_null_product (node_product_t *data_product){
	if(data_product->left && data_product->right )
			{
				printf("left e right do produto nao sao null\n");
			}
}

void test_null_category (node_category_t *data_category){
	if(data_category->left && data_category->right && data_category->root_product)
			{
				printf("left, right e root_product da category nao sao null\n");
			}
}

int main (int argc, char **argv)
{
	FILE *fd_entrada;
	node_product_t data_product, *aux_product=NULL;
	node_category_t data_category, *root_category=NULL, *aux_categ=NULL;
	tree_category_t *tree = NULL;
	int qtd_elements = 0;
	char datas[512], x;

	#if defined(DEBUG_PRINT) 
    	printf("\t**MODO DEBUGGER ATIVADO**\n\n");
    #endif

    //exit(0);

	fd_entrada = fopen(argv[1],"r");
	if(argc < 2)
	{
		printf("falta argumento!\n");
	}

	if(fd_entrada == NULL)
	{
		printf("nao abriu a entrada!\n");
		exit(0);
	}

	tree = avl_create();

	init_category(&data_category);
	init_product(&data_product);
	test_null_category (&data_category);
	test_null_product (&data_product);
	
	while (fscanf(fd_entrada, "%s\n", datas)!=EOF){
		qtd_elements = sscanf(datas, "%[^;];%d;%[^;];%d;%[^;];%[^;];%d;%f%c",  data_category.name, &data_category.code, data_product.name, &data_product.code, data_product.fabricator, data_product.model, &data_product.year, &data_product.value, &x) ;
		#if defined(DEBUG_PRINT)
			printf("li %d elementos\n", qtd_elements);
		#endif					
		if (qtd_elements == 8){
			#if defined(DEBUG_PRINT)
				test_null_category (&data_category);
				test_null_product (&data_product);
			#endif
			/*data_category.left = NULL;
			data_category.right = NULL;
			data_category.root_product = NULL;
			data_product.left = NULL;
			data_product.right = NULL;*/
			avl_put_category(tree, &data_category, &data_product);
			tree->root = avl_balance_node_category(tree->root);
		} else{
		#if defined(DEBUG_PRINT)
			printf("To lendo mas n deu 8\n");
			test_null_category (&data_category);
			test_null_product (&data_product);
		#endif
		init_category(&data_category);
		init_product(&data_product);
		}
		
	}

	inorder_all(tree->root);

	fclose(fd_entrada);

}
