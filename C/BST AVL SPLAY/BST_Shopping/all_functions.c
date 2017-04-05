/*Inicializaçaõ de uma variavel de tipo categoria*/
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

//função para auxiciliar height
int maior (int a, int b){
	if (a>b)
		return a;
	else
		return b;
}

//função para ver algura de uma arvore de categoria
int height_categ (node_category_t* root_category){
   if((root_category == NULL) || (root_category->left == NULL && root_category->right == NULL)) //teste para ver se existe ou se é um nó sem filhos
       return 0; 
   else //se não for
   		/*Usa a função maior para saber qual dos filhos tem mais nós ate o "chão" e soma +1 para o nó em que esta*/	
       return 1+maior(height_categ(root_category->right), height_categ(root_category->left));
}

//Mesma logica da de categorias
int height_product (node_product_t* root_product){
   if((root_product == NULL) || (root_product->left == NULL && root_product->right == NULL))
       return 0;
   else
       return 1+maior(height_product (root_product->right), height_product (root_product->left));
}


//int cont_categ=0, cont_product=0;

/*Inserção de um produto na arvore de produtos*/
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

//mesma função de put_product só que para arvores de categorias
node_category_t* put_category (node_category_t* root_category, node_category_t* data_category, node_product_t *data_product){
	//cont_categ++;
	if (root_category == NULL){
		root_category = (node_category_t*) malloc(sizeof(node_category_t));
		init_category(root_category);
		memcpy(root_category, data_category, sizeof(node_category_t));
		root_category->root_product = put_product(root_category->root_product, data_product);
	}
	else if (root_category->code < data_category->code){
		root_category->right = put_category (root_category->right, data_category, data_product);
	}
	else if (root_category->code > data_category->code){
		root_category->left = put_category(root_category->left, data_category, data_product);
	}
	else if (root_category->code == data_category->code){
		root_category->root_product = put_product(root_category->root_product, data_product);
	}
	return root_category;
}

//função para verificar a existencia ou não de uma categoria
int contains_categ(node_category_t *root_category, int search_code){
	while (1){
		if (root_category == NULL){
			printf("Categoria %d não encontrada", search_code);
			return 0;//se retornar falso não existe
		}
		else if (root_category->code == search_code){
			return 1; //retorna verdade se existir
		}	
		else if (root_category->code > search_code)
			root_category = root_category->left;
		else if (root_category->code < search_code)
			root_category = root_category->right;
	}
}

//Mesma logica da de categorias
int contains_product(node_product_t *root_product, int search_code){
	while (1){
		if (root_product == NULL){
			printf ("\nproduto %d não existe\n", search_code);
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


// função para ver o rank de um nó
int rank_categ (node_category_t* root_category, int search_code){
	int soma = 0;	// variavel para somar todos os elementos a esquerda
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

//Mesma logica da de categorias
int rank_product (node_product_t* root_product, int search_code){
	int soma = 0;	// variavel para somar todos os elementos a esquerda
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

//função para pegar um nó da arvore de categoria
node_category_t* get_category (node_category_t* root_category, int search_code){
	if (contains_categ(root_category, search_code)){
		while (root_category->code != search_code){
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

//Função para pegar um nó da arvore de produtos
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

//Função de auxilio para deletar uma categoria
node_category_t* aux_delete_category (node_category_t *node_delete){
	/*Percorre ate econtrar o nó que assumiu o lugar do nó deletado*/
	if (node_delete->left == NULL) //encontra o nó
		return node_delete->right; // retorna o filho da direita reajustando a arvore
	
	node_delete->left = aux_delete_category(node_delete->left);
	return node_delete;			
}

//Função para deletar uma categoria
node_category_t  *delete_category (node_category_t  *root_category, int code_search){	
	if(!contains_categ(root_category, code_search))
		return root_category;
	if (root_category->code > code_search){
		root_category->left = delete_category(root_category->left, code_search);
		/*pesquisando pelo codigo */
	}else if(root_category->code < code_search){
		root_category->right = delete_category(root_category->right, code_search);		
	}else { //apos o codigo ser encontrado
		node_category_t *aux = root_category->right;
		if ((root_category->left == NULL) && (root_category->right == NULL)){ // testa se tem filhos
			root_category->root_product = delete_all_products(root_category->root_product);
			free(root_category);
			return NULL;
		}	
		else if (root_category->left == NULL){  //sem filho a esquerda
			root_category->root_product = delete_all_products(root_category->root_product);
			node_category_t *aux = root_category->right;//ponteiro auxiliar para exclusão
			free(root_category);// liberado o nó apagado						
			return aux; // retorna o nó da direita
		}
		else if (root_category->right == NULL){ //sem filho a direita
			root_category->root_product = delete_all_products(root_category->root_product);
			node_category_t *aux = root_category->left;//ponteiro auxiliar para exclusão
			free(root_category);// libera o nó apagado
			return aux; // retorna o nó da esquerda
		}
		else{//tem os dois filhos
			root_category->root_product = delete_all_products(root_category->root_product);//liberação da arvore de produtos
			node_category_t *aux = root_category;//criação de uma variavel auxiliar
			root_category = min_categ(aux->right);//encontrando o nó mais proximo a direita da arvore
			root_category->right = aux_delete_category (aux->right);//reajusta a nova arvore da direita
			root_category->left = aux->left; //o novo nó assumi o filho da esquerda do antigo nó
			free (aux);// libera o nó apagado
			return root_category;
		}
	}
	return root_category;
}

//Mesmos comentarios da de deletar categorias
node_product_t* aux_delete_product (node_product_t *node_delete){
	if (node_delete->left == NULL) 
		return node_delete->right;
		
	node_delete->left = aux_delete_product(node_delete->left);
	return node_delete;			
}

node_product_t  *delete_product (node_product_t  *root_product, int code_search){
	if (!contains_product(root_product, code_search))
		return root_product;
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

//Função para saber o tamanho de um nó
int size_categ (node_category_t* node_category){
	if (node_category!=NULL){
		int soma = 1;	// variavel que soma o tamanho da arvore, soma começa em 1 do proprio nó;
		soma += size_categ(node_category->left); // soma size da arvore esquerda
		soma += size_categ(node_category->right); // soma size da arvore direita
		return soma;
	} 
}

//Mesma logica da de categorias
int size_product (node_product_t* node_product){
	if (node_product!=NULL){
		int soma = 1;	// variavel que soma o tamanho da arvore, soma começa em 1 do proprio nó;
		soma += size_product(node_product->left); // soma size da arvore esquerda
		soma += size_product(node_product->right); // soma size da arvore direita
		return soma;
	}
}	 



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
    return (flor <= code_search) ? flor : root_category->code;
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

//função para printar em ordem a arvore de rodutos
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

//Tdas funções daqui:
//======================================================================================================================

void max_all (node_category_t *root_category){
	if (root_category != NULL){	
		max_all (root_category->left);
		printf ("\nCat: %s \n max dos produtos:", root_category->name);
		printf ("%d\n", max_product(root_category->root_product)->code);
		max_all (root_category->right);
	}
}

void min_all (node_category_t *root_category){
	if (root_category != NULL){	
		min_all (root_category->left);
		printf ("\nCat: %s \n min dos produtos:", root_category->name);
		printf ("%d\n", min_product(root_category->root_product)->code);
		min_all (root_category->right);
	}
}

void height_all (node_category_t *root_category){
	if (root_category != NULL){	
		height_all (root_category->left);
		printf ("\nCat: %s \n height dos produtos:", root_category->name);
		printf ("%d\n", height_product(root_category->root_product));
		height_all (root_category->right);
	}
}

void size_all_prod(node_product_t* root_product){
	if (root_product != NULL){	
		size_all_prod (root_product->left);
		printf ("\n\t\tsize do produto %s: %d\n", root_product->name, size_product(root_product));
		size_all_prod (root_product->right);
	}
}


void size_all (node_category_t *root_category){
	if (root_category != NULL){	
		size_all (root_category->left);
		printf ("\nsize da categ %s: %d\n", root_category->name, size_categ(root_category));
		size_all_prod(root_category->root_product);
		size_all (root_category->right);
	}
}
//até aqui, são funções de auxilio pra printar o que for desejado de todas as arvores existentes
//======================================================================================================================

//função de liberação de toda arvore de categorias
node_category_t free_all_categ (node_category_t* root_category){
	if (root_category != NULL){
		free_all_categ(root_category->left);
		delete_all_products(root_category->root_product);
		free (root_category);
		free_all_categ(root_category->right);
	}	
}


//Função para checar o arquivo
int arquivos_check(char opcao, FILE* arquivo){
	if (arquivo == NULL){
		printf("Erro ao abrir o arquivo da opcao %c\n", opcao);
		return 0;
	}
	return 1;
}

node_category_t *recept_put(FILE* put, node_category_t* root_category){
	node_product_t data_product;
	node_category_t data_category;
	char separador, datas[310];
	init_category(&data_category);
	init_product(&data_product);
	int qtd_elements;
	char x; // char para pegar excedentes de uma linha do arquivo
		while (fscanf (put, "%c", &separador)!=EOF){
			if (separador == ';' || separador == '.' || separador == ':' || separador == '#' ||separador == '@' || separador == '$' || separador == '*'){
				break;
			}
		}
				
		rewind (put);
		printf ("\nseparador: %c \n", separador);
		
		switch (separador){
			case ';':
				init_category(&data_category);
				init_product(&data_product);
				while (fscanf(put, "%s\n", datas)!=EOF){
					qtd_elements = sscanf(datas, "%[^;];%d;%[^;];%d;%[^;];%[^;];%d;%f%c",  data_category.name, &data_category.code, data_product.name, &data_product.code, data_product.fabricator, data_product.model,&data_product.year, &data_product.value, &x) ;
					if (qtd_elements == 8){
						root_category = put_category(root_category, &data_category, &data_product);
					}
					init_category(&data_category);			
					init_product(&data_product);		
				}
			break;
			case '.':
				init_category(&data_category);
				init_product(&data_product);
				while (fscanf(put, "%s\n", datas)!=EOF){
					qtd_elements = sscanf(datas, "%[^.].%d.%[^.].%d.%[^.].%[^.].%d.%f%c",  data_category.name, &data_category.code, data_product.name, &data_product.code, data_product.fabricator, data_product.model,&data_product.year, &data_product.value,&x) ;
					if (qtd_elements == 8){
						root_category = put_category(root_category, &data_category, &data_product);
					}
					init_category(&data_category);			
					init_product(&data_product);
				}
			break;
			case ':':
				init_category(&data_category);
				init_product(&data_product);
				while (fscanf(put, "%s\n", datas)!=EOF){
					qtd_elements = sscanf(datas, "%[^:]:%d:%[^:]:%d:%[^:]:%[^:]:%d:%f%c",  data_category.name, &data_category.code, data_product.name, &data_product.code, data_product.fabricator, data_product.model,&data_product.year, &data_product.value,&x) ;
					if (qtd_elements == 8){
						root_category = put_category(root_category, &data_category, &data_product);
					}
					init_category(&data_category);			
					init_product(&data_product);		
				}
			break;
			case '#':
				init_category(&data_category);
				init_product(&data_product);
				while (fscanf(put, "%s\n", datas)!=EOF){
					qtd_elements = sscanf(datas, "%[^#]#%d#%[^#]#%d#%[^#]#%[^#]#%d#%f%c",  data_category.name, &data_category.code, data_product.name, &data_product.code, data_product.fabricator, data_product.model,&data_product.year, &data_product.value,&x) ;
					if (qtd_elements == 8){
						root_category = put_category(root_category, &data_category, &data_product);
					}
					init_category(&data_category);			
					init_product(&data_product);
				}
			break;
			case '@':
				init_category(&data_category);
				init_product(&data_product);
				while (fscanf(put, "%s\n", datas)!=EOF){
					qtd_elements = sscanf(datas, "%[^@]@%d@%[^@]@%d@%[^@]@%[^@]@%d@%f%c",  data_category.name, &data_category.code, data_product.name, &data_product.code, data_product.fabricator, data_product.model,&data_product.year, &data_product.value,&x) ;
					if (qtd_elements == 8){
						root_category = put_category(root_category, &data_category, &data_product);
					}
					init_category(&data_category);			
					init_product(&data_product);	
				}
			break;				
			case '$':
				init_category(&data_category);
				init_product(&data_product);
				while (fscanf(put, "%s\n", datas)!=EOF){
					qtd_elements = sscanf(datas, "%[^$]$%d$%[^$]$%d$%[^$]$%[^$]$%d$%f%c",  data_category.name, &data_category.code, data_product.name, &data_product.code, data_product.fabricator, data_product.model,&data_product.year, &data_product.value,&x) ;
					if (qtd_elements == 8){
						root_category = put_category(root_category, &data_category, &data_product);
					}
					init_category(&data_category);			
					init_product(&data_product);
				}
			break;
			case '*':
				init_category(&data_category);
				init_product(&data_product);
				while (fscanf(put, "%s\n", datas)!=EOF){
					qtd_elements = sscanf(datas, "%[^*]*%d*%[^*]*%d*%[^*]*%[^*]*%d*%f%c",  data_category.name, &data_category.code, data_product.name, &data_product.code, data_product.fabricator, data_product.model,&data_product.year, &data_product.value,&x) ;
					if (qtd_elements == 8){
						root_category = put_category(root_category, &data_category, &data_product);
					}
					init_category(&data_category);			
					init_product(&data_product);
				}
			break;
			default:
				printf ("\nSEPARADOR INVALIDO!\n");
			break;					
		}
		return root_category;
}	

node_category_t* aplication_for_files_fuction (FILE* arquivo, char opcao, node_category_t* root_category){
	if (arquivo == NULL){
		printf ("\nOpcao sem arquivo %c\n", opcao);
		return root_category;
	}
	node_category_t *aux_categ=NULL; // variaveis auxiliares para execução
	node_product_t *aux_product=NULL;
	char leitor[10], leitor2[8], linha[20]; // variaveis para leitura de arguivos
	int code_categ, code_product, qtd_teste;//variaveis para pegar informações de execução
	char x; // para pegar excedentes do arquivo
	switch (opcao){
		case 'g':
			while (fscanf (arquivo, "%[^;];%d\n", leitor, &code_categ)!= EOF){
				qtd_teste = sscanf(linha, "%[^;];%d;%[^;];%d%c", leitor, &code_categ, leitor2, &code_product, &x);
				if (qtd_teste==2){
					aux_categ = get_category(root_category, code_categ);
					printf("Deu get nessa categoria: %s, %d", aux_categ->name, aux_categ->code);
				}	
				else if (qtd_teste==4){
					aux_product = get_product(get_category(root_category,code_categ)->root_product, code_product);
					printf("Deu get nesse produto: %s, %d", aux_product->name, aux_product->code);
				}
				else 
					printf ("\nArquivo para get com quantidade invalide de informações\n");
			}	
		break;
		case 'd':
			while (fscanf (arquivo, "%s\n", linha)!= EOF){
				qtd_teste = sscanf(linha, "%[^;];%d;%[^;];%d%c", leitor, &code_categ, leitor2, &code_product,&x);
				if (qtd_teste==2){
					root_category = delete_category(root_category, code_categ);
				}
				else if (qtd_teste==4){
					aux_categ = get_category(root_category, code_categ);
					aux_categ->root_product = delete_product(aux_categ->root_product, code_product);
				}
				else 
					printf ("\nArquivo para delete com quantidade invalide de informações\n");
			}	
		break;
		case 'c':	
			while (fscanf (arquivo, "%s\n", linha)!= EOF){
				qtd_teste = sscanf(linha, "%[^;];%d;%[^;];%d%c", leitor, &code_categ, leitor2, &code_product,&x);
				if ((qtd_teste==2)&&(contains_categ(root_category,code_categ))){
						printf ("Categoria existente");
				}
				else if (qtd_teste==4){	
					if(contains_categ(root_category,code_categ)){
						aux_categ = get_category(root_category, code_categ);
						if (contains_product(aux_categ->root_product, code_product))
							printf ("Produto existe");
					}	
				}
				else 
					printf ("\nArquivo para delete com quantidade invalide de informações\n");
			}				
		break;
		case 'R':
			while (fscanf (arquivo, "%s\n", linha)!= EOF){
				qtd_teste = sscanf(linha, "%[^;];%d;%[^;];%d%c", leitor, &code_categ, leitor2, &code_product,&x);
				if ((qtd_teste==2) && (contains_categ(root_category,code_categ))){
					printf ("rank da categoria  %d eh: %d", code_categ, rank_categ(root_category,code_categ));
				}
				else if (qtd_teste==4){
					aux_categ = get_category(root_category, code_categ);
					if (contains_product(aux_categ->root_product, code_product)){
						printf ("rank do produto  %d eh: %d", code_product, rank_product(aux_categ->root_product,code_product));
					}
				}	
				else 
					printf ("\nArquivo para delete com quantidade invalide de informações\n");
			}	 	
		break;	
		case 'F':	
			while (fscanf (arquivo, "%s\n", linha)!= EOF){
				qtd_teste = sscanf(linha, "%[^;];%d;%[^;];%d%c", leitor, &code_categ, leitor2, &code_product,&x);
				if (qtd_teste==2){
					qtd_teste = floor_categ(root_category, code_categ);
					if(qtd_teste==-1)
						printf("\nNumero %d nao tem floor\n", code_categ);
					else
						printf ("\nFloor de %d eh a categoria: %d\n", code_categ, qtd_teste);
				}
				else if (qtd_teste==4){
					aux_categ = get_category(root_category, code_categ);
					qtd_teste = floor_product(aux_categ->root_product, code_product);
					if(qtd_teste==-1)
						printf("\nNumero %d nao tem floor\n", code_product);
					else
						printf ("\nFloor de %d eh o produto: %d\n", code_product, qtd_teste);
				}
				else 
					printf ("\nArquivo para delete com quantidade invalide de informações\n");
			} 	
		break;	
		case 'C':
			while (fscanf (arquivo, "%s\n", linha)!= EOF){
				qtd_teste = sscanf(linha, "%[^;];%d;%[^;];%d%c", leitor, &code_categ, leitor2, &code_product,&x);
				if (qtd_teste==2){
					qtd_teste = ceiling_categ(root_category, code_categ);
					if(qtd_teste==-1)
						printf("\nNumero %d nao tem ceil\n", code_categ);
					else
						printf ("\nCeil de %d eh a categoria: %d\n", code_categ, qtd_teste);
				}
				else if (qtd_teste==4){
					aux_categ = get_category(root_category, code_categ);
					qtd_teste = ceiling_product(aux_categ->root_product, code_product);
					if(qtd_teste==-1)
						printf("\nNumero %d nao tem ceil\n", code_product);
					else
						printf ("\nCeil de %d eh o produto: %d\n", code_product, qtd_teste);
				}
				else 
					printf ("\nArquivo para delete com quantidade invalide de informações\n");
			} 	
		break;
	}
	return root_category;
}
			
void help(){
	printf ("\n\n|=========================================================================================================|\n")
	printf ("|              ********************************* COMO USAR *********************************              |\n");
	printf ("|                 -p <entrada.csv> Para determinar um arquivo que adciona produtos a loja                 |\n");
	printf ("|     -g <entrada.csv> Para determinar um arquivo que pega um determinado produto ou categoria da loja    |\n");
	printf ("|         -d <entrada.csv> Para determinar um arquivo que deleta um produto ou categoria da loja          |\n");
	printf ("|    -c <entrada.csv> Para determinar um arquivo que verifica se um produto ou categoria existe na loja   |\n");
	printf ("|  -R <entrada.csv> Para determinar um arquivo que ve o Rank na arvore de uma categoria ou de um Produto  |\n");
	printf ("| -F <entrada.csv> Para determinar um arquivo que ve o floor na arvore de uma categoria ou de um produto  |\n");
	printf ("|-C <entrada.csv> Para determinar um arquivo que ve o ceiling na arvore de uma categoria ou de um produto |\n");
	printf ("|                         -S <entrada.txt> Determina a sequencia de execucao;                             |\n");
	printf ("|                                      *Opcoes de sequencia*                                              |\n");
	printf ("|                   p, g, d, c, R, F, C ou S, para executar uma das funcoes acima                         |\n");
	printf ("|                               H mostra a altura de todas as arvores                                     |\n");
	printf ("|                               s mostra o tamanho de todas as arvores                                    |\n");
	printf ("|                                M mostra o maior de todas as arvores                                     |\n");
	printf ("|                                m mostra o menor de todas as arvores                                     |\n");
	printf ("|                                    i mostrar todas as arvores                                           |\n");
	printf ("|=========================================================================================================|\n\n")
}
