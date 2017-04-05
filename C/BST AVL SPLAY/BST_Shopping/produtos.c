#include <BST_shopping.h>


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


// as funções desse arquivo seguem a mesma logica da de categorias

int height_product (node_product_t* root_product){
   if((root_product == NULL) || (root_product->left == NULL && root_product->right == NULL))
       return 0;
   else
       return 1+maior(height_product (root_product->right), height_product (root_product->left));
}

node_product_t* put_product (node_product_t* root_product, node_product_t* data_product){
	//cont_product++;
	if (root_product == NULL){//testa se arvore esta vazia então cria o nó raiz
		root_product = (node_product_t*) malloc(sizeof(node_product_t));
		init_product(root_product);
		memcpy(root_product, data_product, sizeof(node_product_t));
	}
	/*Percorre a arvore até encontrar o local de incerção do novo produto*/
	else if (root_product->code < data_product->code){
		root_product->right = put_product (root_product->right, data_product);
	}
	else if (root_product->code > data_product->code){
		root_product->left = put_product (root_product->left, data_product);
	}
	return root_product;
}

int contains_product(node_product_t *root_product, int search_code){
	while (1){
		if (root_product == NULL){
			//printf ("produto não existe");
			return 0;
		}
		else if (root_product->code == search_code)
			return 1;
		else if (root_product->code > search_code)
			root_product = root_product->left;
		else if (root_product->code < search_code)
			root_product = root_product->right;
	}
}

int size_product (node_product_t* node_product){
	if (node_product!=NULL){
		int soma = 1;	// variavel que soma o tamanho da arvore, soma começa em 1 do proprio nó;
		soma += size_product(node_product->left); // soma size da arvore esquerda
		soma += size_product(node_product->right); // soma size da arvore direita
		return soma;
	}
}	 

int rank_product (node_product_t* root_product, int search_code){
	int soma = 0;	// variavel para somar todos os elementos a esquerda
	if (contains_product(root_product, search_code)){
		while (root_product->code != search_code){ 
			if (root_product->code < search_code){
				soma += 1 + size_product(root_product->left); // soma 1 do proprio nó mais a arvore da esquerda do galho
				root_product = root_product->right; // apos somar vai para direita
			}
			else
				root_product = root_product->left; // nao soma pois o galho é maior que o nó 
		}
		soma+= 1 + size_product(root_product->left); // pega arvore da esquerda do nó e soma aos outros nós que estavam a esquerda
		return soma;
	}
	return -1;
}

node_product_t* get_product (node_product_t* root_product, int search_code){
	if (contains_product(root_product, search_code)){
		while (root_product->code != search_code){
			if (search_code > root_product->code)
				root_product = root_product->right;
			else if (search_code < root_product->code)
				root_product = root_product->left;
		}
		return root_product;
	}
	else 
		return NULL;

}

//Função para encontrar o nó mais a esquerda da arvore de produtos
node_product_t* min_product (node_product_t *root_product){
	while(root_product->left != NULL){
		root_product = root_product->left;
	}
	return root_product;
}

//Função para encontrar o nó mais a esquerda da arvore de produtos
node_product_t* max_product (node_product_t *root_product){
	while(root_product->right != NULL){
		root_product = root_product->right;
	}
	return root_product;
}

//Função para liberar toda a arvore de produtos
node_product_t* delete_all_products(node_product_t* root_product){
	if (root_product != NULL){
		delete_all_products (root_product->left);
		delete_all_products (root_product->right);
		free (root_product);
		return NULL;
	}
}

node_product_t* aux_delete_product (node_product_t *node_delete){
	if (node_delete->left == NULL) 
		return node_delete->right;
		
	node_delete->left = aux_delete_product(node_delete->left);
	return node_delete;			
}

node_product_t  *delete_product (node_product_t  *root_product, int code_search){
	if  (root_product == NULL)	
		return NULL;		
	if (root_product->code > code_search){
				root_product->left = delete_product(root_product->left, code_search);
	}else if(root_product->code < code_search){
				root_product->right = delete_product(root_product->right, code_search);
	}else {
		if ((root_product->left == NULL)&&(root_product->right == NULL)){
			free(root_product);
			return NULL;
		}
		else if (root_product->left == NULL){
			node_product_t *aux = root_product->right;
			return aux; 
		}
		else if (root_product->right == NULL){
			node_product_t *aux = root_product->left;
			free(root_product);
			return aux; 	
		}
		else{
			node_product_t *aux = root_product;
			root_product = min_product(aux->right);
			root_product->right = aux_delete_product (aux->right);
			root_product->left = aux->left;
			free (aux);
			return root_product;
		}
	}
	return root_product;			
}

int ceiling_product(node_product_t *root_product, int code_search){
    // Base case
    if (root_product == NULL)
        return -1;
 
    // We found equal key
    if( root_product->code == code_search )
        return root_product->code;
 
    // If root's key is smaller, ceil must be in right subtree
    if( root_product->code < code_search )
        return ceiling_product(root_product->right, code_search);
 
    // Else, either left subtree or root has the ceil value
    int ceil = ceiling_product(root_product->left, code_search);
    return (ceil >= code_search) ? ceil : root_product->code;
}

int floor_product(node_product_t *root_product, int code_search)
{
    // Base case
    if( root_product == NULL )
        return -1;
 
    // We found equal key
    if( root_product->code == code_search )
        return root_product->code;
 
    // If root's key is smaller, ceil must be in right subtree
    if( root_product->code > code_search )
        return floor_product(root_product->left, code_search);
 
    // Else, either left subtree or root has the ceil value
    int flor = floor_product(root_product->right, code_search);
    return (flor >= code_search) ? flor : root_product->code;
}

void inorder_product (node_product_t *root_product){
	if (root_product != NULL){	
		inorder_product (root_product->left);
		printf ("\t%s\t%d\t%s\t%d\t%s\t%.2f \t\n", root_product->name, root_product->code, root_product->fabricator, root_product->year, root_product->model, root_product->value);
		inorder_product (root_product->right);
	}
}