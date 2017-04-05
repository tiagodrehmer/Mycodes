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

#include <AVL_shopping.h>

/* Find the balance of an AVL node */
int avl_balance_factor_category( node_category_t *node_category) {
	int balance_factor = 0;

	balance_factor += height_categ(node_category->left); //testa se existe um nó a esquerda e soma a altura dele
	balance_factor -= height_categ(node_category->right); //testa se existe um nó a direita e desconta a altura dele

	return balance_factor;  // retorna o fator de balanceamento
}

/* Left Left Rotate */
node_category_t *avl_single_rotate_right_category( node_category_t *node_category ) {
 	node_category_t *a = node_category;
	node_category_t *b = a->left;
	
	a->left = b->right;
	b->right = a;
	#if defined(DEBUG_ROTATION)
		printf("fiz R CATEGORY\n");
	#endif

	return( b );
}

//duas rotações direitas, quando o filho esta a esquerda e o neto a direita
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
		printf("fiz RR CATEGORY\n");
	#endif

	return( c );
}

//duas rotações esquerda, quando o filho esta a direita e o neto a esquerda
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
		printf("fiz LL CATEGORY\n");
	#endif

	return( c );
}

//rotação simples a esquerda, quando os filhos e netos estão a esquerda
node_category_t *avl_simgle_rotate_left_category( node_category_t *node_category )
{
	node_category_t *a = node_category;
	node_category_t *b = a->right;
	
	a->right = b->left;
	b->left = a; 
	#if defined(DEBUG_ROTATION)
		printf("fiz L CATEGORY\n");
	#endif

	return( b );
}


/* Balance a given node */
node_category_t* avl_balance_category(node_category_t *node_category)
{
	if (node_category){
		node_category_t *new_root = NULL;
		//percorre a arvore
		int balance_factor = avl_balance_factor_category(node_category); // balance_factor é o calculo do fator de balanceamento

		if( balance_factor >= 2 ) { // se for maior ou igual que 2 quer dizer que o filho da esquerda esta mais pesado
			/* Left Heavy */	
			if( avl_balance_factor_category(node_category->left) <= -1 ) // testa se o fator de balanceamento do filho da esquerda for menor q-1
				new_root = avl_double_rotate_right_category(node_category); // nesse caso é preciso fazer duas rotação a direita 
			else 
				new_root = avl_single_rotate_right_category(node_category); // se não caso seja maior ou igual que 1 ele faz uma rotação a direita apenas

		} else if( balance_factor <= -2 ) { // filho da direita esta pesado
			/* Right Heavy */
			if( avl_balance_factor_category( node_category->right ) >= 1 ) // se o o fator de balanceamento do filho da direita for maior que 1
				new_root = avl_double_rotate_left_category(node_category); //aplica duas rotação a esquerda
			else 
				new_root = avl_simgle_rotate_left_category(node_category); // aplica uma rotação simples a esquerda

		} else {
			/* This node is balanced -- no change. */
			new_root = node_category;

		}
		return(new_root);
	}

	return NULL;
}


/* Find the balance of an AVL node */
int avl_balance_factor_product( node_product_t *node_product ) {
	int balance_factor = 0;

	balance_factor += height_product(node_product->left);
	balance_factor -= height_product(node_product->right);
		//printf("%d", balance_factor);
	return balance_factor ;
}

/* Left Left Rotate */
node_product_t *avl_single_rotate_right_product( node_product_t *node_product ) {
 	node_product_t *a = node_product;
	node_product_t *b = a->left;
	
	a->left = b->right;
	b->right = a;
	#if defined(DEBUG_ROTATION)
		printf("fiz R PRODUCT\n");
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
		printf("fiz RR PRODUCT\n");
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
		printf("fiz LL PRODUCT\n");
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
		printf("fiz L PRODUCT\n");
	#endif

	return( b );
}


/* Balance a given node */
node_product_t* avl_balance_product (node_product_t *node_product)
{
	if (node_product){
	node_product_t* new_root = NULL;

	int balance_factor = avl_balance_factor_product(node_product); // balance_factor é o calculo do fator de balanceamento;

	if(balance_factor >= 2) {
		/* Left Heavy */	
		if( avl_balance_factor_product(node_product->left) <= -1) 
			new_root = avl_double_rotate_right_product(node_product);
		else 
			new_root = avl_single_rotate_right_product(node_product);

	} else if(balance_factor <= -2) {
		/* Right Heavy */

		if( avl_balance_factor_product( node_product->right) >= 1)
			new_root = avl_double_rotate_left_product(node_product);
		else 
			new_root = avl_single_rotate_left_product(node_product);

	} else {
		/* This node is balanced -- no change. */

		new_root = node_product;
	}

	return( new_root );	
	}
	
	return NULL;
}
