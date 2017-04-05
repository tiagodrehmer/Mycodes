#include <SPLAY_shopping.h>


/*Inicializaçaõ de uma variavel de tipo categoria*/
void init_category (node_category_t *category){
	memset(category->name, '\0', strlen(category->name));
	category->code = 0;
	category->root_product = NULL;
	category->left = NULL;
	category->right = NULL;
	category->father = NULL;
}

//função para ver algura de uma arvore de categoria
int height_categ (node_category_t* root_category){
   if(root_category == NULL) //teste para ver se existe ou se é um nó sem filhos
       return -1; 
   else //se não for
   		/*Usa a função maior para saber qual dos filhos tem mais nós ate o "chão" e soma +1 para o nó em que esta*/	
       return 1+maior(height_categ(root_category->right), height_categ(root_category->left));
}

//função para criar um novo nó na arvore
//mesma função de put_product só que para arvores de categorias
node_category_t* put_category (node_category_t* root_category, node_category_t *data_category, node_product_t *data_product){
	//cont_categ++;
	node_category_t *father = NULL;
	while(root_category != NULL){
		father = root_category;
		if (root_category->code > data_category->code){
			root_category = root_category->left;
		}
		else if (root_category->code < data_category->code){
			root_category = root_category->right;
		}
		else{
			root_category->root_product = put_product(root_category->root_product, data_product); //insere o produto
			break;
		}
	}
	if (root_category == NULL){
		root_category = (node_category_t*) malloc(sizeof(node_category_t));
		init_category(root_category);
		memcpy(root_category, data_category, sizeof(node_category_t));
		root_category->father = father; //ajeita o ponteiro pra pai do novo noh	
		root_category->root_product = put_product(root_category->root_product, data_product); //insere o produto
	}		
	root_category = splay_category(root_category);
	return root_category;
}

//função para verificar a existencia ou não de uma categoria
int contains_categ(node_category_t *root_category, int search_code){
	while (1){
		if (root_category == NULL){
			//printf ("\ncategoria não existe %d", search_code);
			return 0; //se retornar falso não existe			
		}
		else if (root_category->code == search_code)
			return 1;//se retornar verdade existe
		else if (root_category->code > search_code)
			root_category = root_category->left;
		else if (root_category->code < search_code)
			root_category = root_category->right;
	}
}

//Função para saber o tamanho de um nó
int size_categ (node_category_t* node_category){
	if (node_category!=NULL){
		int soma = 1;	// variavel que soma o tamanho da arvore, soma começa em 1 do proprio nó;
		soma += size_categ(node_category->left); // soma size da arvore esquerda
		soma += size_categ(node_category->right); // soma size da arvore direita
		return soma;
	} 
}

int rank_categ (node_category_t* root_category, int search_code){
	int soma = -1;	// variavel para somar todos os elementos a esquerda
	if (contains_categ(root_category, search_code)){
		while (root_category->code != search_code){ //percorre ate achar o codigo
			if (root_category->code < search_code){ 
				soma += 1 + size_categ(root_category->left); // soma 1 do proprio nó mais a arvore da esquerda do galho
				root_category = root_category->right; // apos somar vai para direita
			}
			else
				root_category = root_category->left; // nao soma pois o galho é maior que o nó 
		}
		soma+= 1 + size_categ(root_category->left); // pega arvore da esquerda do nó e soma aos outros nós que estavam a esquerda
		return soma;
	}
	return -1;
}

//função para pegar um nó da arvore de categoria
node_category_t* get_category (node_category_t* root_category, int search_code){
	if (contains_categ(root_category, search_code)){ // testa se existe a categoria
		while (root_category->code != search_code){ //percorre ate encontrar a categoria
			if (search_code > root_category->code)
				root_category = root_category->right;
			else if (search_code < root_category->code)
				root_category = root_category->left;
		}
		return root_category;
	}
	else 
		return NULL;
}

//Função para encontrar o nó mais a esquerda da arvore de categorias
node_category_t* min_categ(node_category_t *root_category){
	while(root_category->left != NULL){
		root_category = root_category->left;
	}
	return root_category;
}

//Função para encontrar o nó mais a direita da arvore de categorias
node_category_t* max_categ (node_category_t *root_category){
	while(root_category->right != NULL){
		root_category = root_category->right;
	}
	return root_category;
}

//Função de auxilio para deletar uma categoria
node_category_t* aux_delete_category (node_category_t *node_delete, int flag){
	/*Percorre ate econtrar o nó que assumiu o lugar do nó deletado*/
	if (node_delete->left == NULL){ //encontra o nó
		if (flag){
			node_category_t* aux = node_delete->right;
			if (node_delete->right){			
				aux->father = node_delete->father;
			}
			return aux;// retorna o filho da direita reajustando a arvore
		}
		else{
			return node_delete->right;
		}
	}	
	flag = 1;
	node_delete->left = aux_delete_category(node_delete->left, flag);
	return node_delete;			
}

//Função para deletar uma categoria
node_category_t  *delete_category (node_category_t  *root_category, int code_search, node_category_t* father){	
	if (root_category->code > code_search){
		father = root_category;
		root_category->left = delete_category(root_category->left, code_search, father);
		/*pesquisando pelo codigo */
	}else if(root_category->code < code_search){
		father = root_category;
		root_category->right = delete_category(root_category->right, code_search, father);		
	}else { //apos o codigo ser encontrado
		if ((root_category->left == NULL) && (root_category->right == NULL)){ // testa se tem filhos
			root_category->root_product = delete_all_products(root_category->root_product);
			free(root_category);
			return NULL;
		}	
		else if (root_category->left == NULL){  //sem filho a esquerda
			root_category->root_product = delete_all_products(root_category->root_product);
			node_category_t *aux = root_category->right;//ponteiro auxiliar para exclusão
			aux->father = father;
			free(root_category);// liberado o nó apagado					
			return aux; // retorna o nó da direita
		}
		else if (root_category->right == NULL){ //sem filho a direita
			root_category->root_product = delete_all_products(root_category->root_product);
			node_category_t *aux = root_category->left;//ponteiro auxiliar para exclusão
			aux->father = father;	
			free(root_category);// libera o nó apagado
			return aux; // retorna o nó da esquerda
		}
		else{//tem os dois filhos
			root_category->root_product = delete_all_products(root_category->root_product);//liberação da arvore de produtos
			node_category_t *aux = root_category;//criação de uma variavel auxiliar
			root_category = min_categ(aux->right);//encontrando o nó mais proximo a direita da arvore
			root_category->right = aux_delete_category (aux->right, 0);//reajusta a nova arvore da direita
			aux->right->father = root_category;
			root_category->left = aux->left; //o novo nó assumi o filho da esquerda do antigo nó
			aux->left->father = root_category;
			root_category->father = father;
			free (aux);// libera o nó apagado
			return root_category;
		}
	}
	return root_category;
}

/* Ceiling construido com base na implementacao do site: http://www.geeksforgeeks.org/floor-and-ceil-from-a-bst/*/
 int ceiling_categ (node_category_t *root_category, int code_search)
{
    // Base case
    if( root_category == NULL )
        return -1;
 
    // We found equal key
    if( root_category->code == code_search )
        return root_category->code;
 
    // If root's key is smaller, ceil must be in right subtree
    if( root_category->code < code_search )
        return ceiling_categ(root_category->right, code_search);
 
    // Else, either left subtree or root has the ceil value
    int ceil = ceiling_categ(root_category->left, code_search);
    return (ceil >= code_search) ? ceil : root_category->code;
}

/* Floor construido com base no Ceiling, que por sua vez, foi construido com base na implementacao do site: http://www.geeksforgeeks.org/floor-and-ceil-from-a-bst/*/
int floor_categ(node_category_t *root_category, int code_search)
{
    // Base case
    if( root_category == NULL )
        return -1;
 
    // We found equal key
    if( root_category->code == code_search )
        return root_category->code;
 
    // If root's key is smaller, ceil must be in right subtree
    if( root_category->code > code_search )
        return floor_categ(root_category->left, code_search);
 
    // Else, either left subtree or root has the ceil value
    int flor = floor_categ(root_category->right, code_search);
    return (flor <= code_search) ? flor : root_category->code; //operador ternario
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

//função de liberação de toda arvore de categorias
node_category_t free_all_categ (node_category_t* root_category){
	if (root_category != NULL){
		free_all_categ(root_category->left);
		free_all_categ(root_category->right);
		delete_all_products(root_category->root_product);
		free (root_category);
	}	
}