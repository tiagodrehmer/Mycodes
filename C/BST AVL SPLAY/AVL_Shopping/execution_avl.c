#include <AVL_shopping.h>
/*Funcao auxiliar da funcao Height*/
int maior (int a, int b){
	if (a > b)
		return a;
	else
		return b;
}

//As funções daqui:
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
		//printf ("\nCat: %s \n height dos produtos:", root_category->name);
		printf ("%d\n", height_product(root_category->root_product));
		height_all (root_category->right);
	}
}

void size_all_prod(node_product_t* root_product){
	if (root_product != NULL){
		size_all_prod (root_product->left);
		//printf ("\n\t\tsize do produto %s: %d\n", root_product->name, size_product(root_product));
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

/*Função para checar a abertura arquivo*/
int arquivos_check(char opcao, FILE* arquivo){
	if (arquivo == NULL){
		printf("\nERROR IN THE %c FILE\nIT WAS NOT POSSIBLE TO OPEN IT\n", opcao);
		return 0;
	}
	return 1;
}

node_category_t *recept_put(FILE* put, node_category_t* root_category){
	if (put == NULL){
		printf ("\nA OPCAO -p ESTA SEM ARQUIVO\n");
		return root_category;
	}

	node_product_t data_product;
	node_category_t data_category;
	char separador, datas[310];
	init_category(&data_category);
	init_product(&data_product);
	int qtd_elements;
	char x; // char para pegar excedentes de uma linha do arquivo
	#if defined(_PUT)
		clock_t start, stop;
		start = 0;
		stop = 0;
		double time = 0;
		start = clock();
	#endif
	while (fscanf (put, "%c", &separador)!=EOF){
		if (separador == ';' || separador == '.' || separador == ':' || separador == '#' ||separador == '@' || separador == '$' || separador == '*'){
			break;
		}
	}

	rewind (put); //coloca o ponteiro do arquivo para o inicio do mesmo apos descobrir o separador
	//printf ("\nseparador: %c \n", separador);

	switch (separador){
		case ';': //se separador for ponto e virgula
			init_category(&data_category);
			init_product(&data_product);
			while (fscanf(put, "%s\n", datas)!=EOF){
				qtd_elements = sscanf(datas, "%[^;];%d;%[^;];%d;%[^;];%[^;];%d;%f%c",  data_category.name, &data_category.code, data_product.name, &data_product.code, data_product.fabricator, data_product.model,&data_product.year, &data_product.value, &x) ;
				if (qtd_elements == 8){
					root_category = put_category(root_category, &data_category, &data_product);
				}
				init_category(&data_category);
				init_product(&data_product);
			}//fim while
		break; //break case ;

		case '.': //se o separador for um ponto
			init_category(&data_category);
			init_product(&data_product);
			while (fscanf(put, "%s\n", datas)!=EOF){
				qtd_elements = sscanf(datas, "%[^.].%d.%[^.].%d.%[^.].%[^.].%d.%f%c",  data_category.name, &data_category.code, data_product.name, &data_product.code, data_product.fabricator, data_product.model,&data_product.year, &data_product.value,&x) ;
				if (qtd_elements == 8){
					root_category = put_category(root_category, &data_category, &data_product);
				}
				init_category(&data_category);
				init_product(&data_product);
			}//fim while
		break; //breake case .

		case ':': //se o separador for dois pontos
			init_category(&data_category);
			init_product(&data_product);
			while (fscanf(put, "%s\n", datas)!=EOF){
				qtd_elements = sscanf(datas, "%[^:]:%d:%[^:]:%d:%[^:]:%[^:]:%d:%f%c",  data_category.name, &data_category.code, data_product.name, &data_product.code, data_product.fabricator, data_product.model,&data_product.year, &data_product.value,&x) ;
				if (qtd_elements == 8){
					root_category = put_category(root_category, &data_category, &data_product);
				}
			init_category(&data_category);
			init_product(&data_product);
			}//fim while de leitura
		break; //break case :

		case '#': //se o separador for uma cerquilha
			init_category(&data_category);
			init_product(&data_product);
			while (fscanf(put, "%s\n", datas)!=EOF){
				qtd_elements = sscanf(datas, "%[^#]#%d#%[^#]#%d#%[^#]#%[^#]#%d#%f%c",  data_category.name, &data_category.code, data_product.name, &data_product.code, data_product.fabricator, data_product.model,&data_product.year, &data_product.value,&x) ;
				if (qtd_elements == 8){
					root_category = put_category(root_category, &data_category, &data_product);
				}
				init_category(&data_category);
				init_product(&data_product);
			}//fim do while de leitura
			break; //break case #

		case '@': //se o separador for um arroba
			init_category(&data_category);
			init_product(&data_product);
			while (fscanf(put, "%s\n", datas)!=EOF){
				qtd_elements = sscanf(datas, "%[^@]@%d@%[^@]@%d@%[^@]@%[^@]@%d@%f%c",  data_category.name, &data_category.code, data_product.name, &data_product.code, data_product.fabricator, data_product.model,&data_product.year, &data_product.value,&x) ;
				if (qtd_elements == 8){
					root_category = put_category(root_category, &data_category, &data_product);
				}
				init_category(&data_category);
				init_product(&data_product);
			}//fim while de leitura
		break;//fim case @

		case '$': //se o separador for um cifrao
			init_category(&data_category);
			init_product(&data_product);
			while (fscanf(put, "%s\n", datas)!=EOF){
				qtd_elements = sscanf(datas, "%[^$]$%d$%[^$]$%d$%[^$]$%[^$]$%d$%f%c",  data_category.name, &data_category.code, data_product.name, &data_product.code, data_product.fabricator, data_product.model,&data_product.year, &data_product.value,&x) ;
				if (qtd_elements == 8){
					root_category = put_category(root_category, &data_category, &data_product);
				}
				init_category(&data_category);
				init_product(&data_product);
			}//fim while leitura
		break; //fim case $

		case '*': //se o separador for um asterisco
			init_category(&data_category);
			init_product(&data_product);
			while (fscanf(put, "%s\n", datas)!=EOF){
				qtd_elements = sscanf(datas, "%[^*]*%d*%[^*]*%d*%[^*]*%[^*]*%d*%f%c",  data_category.name, &data_category.code, data_product.name, &data_product.code, data_product.fabricator, data_product.model,&data_product.year, &data_product.value,&x) ;
				if (qtd_elements == 8){
					root_category = put_category(root_category, &data_category, &data_product);
				}
				init_category(&data_category);
				init_product(&data_product);
			}//fim while de leitura
		break;//fim do case *

		default: //se o separador nao for nenhum dos citados acima
			printf ("\nSEPARADOR INVALIDO!\n");
		break;

	}//fim do switch
	#if defined(_PUT)
		stop = clock();
		time = (double)(stop - start)* (double)1000/CLOCKS_PER_SEC;
		printf ("%f\n", time);
	#endif
	return root_category;
}

node_category_t* aplication_delete(FILE* del, node_category_t* root_category){
	if (del == NULL){
		printf ("Arquivo para delete vazio");
		return root_category;
	}
	node_category_t *aux_categ=NULL; // variaveis auxiliares para execução
	char leitor[20], leitor2[20], linha[60]; // variaveis para leitura de arguivos
	int code_categ = 0, code_product = 0, qtd_teste = 0;//variaveis para pegar informações de execução
	char x; // para pegar excedentes do arquivo
	#if defined(_EXECUTION_TIME)
		clock_t start, stop;
		start = 0;
		stop = 0;
		double time = 0;
		start = clock();
	#endif
	while (fscanf (del, "%s\n", linha) != EOF){
		qtd_teste = sscanf(linha, "%[^;];%d;%[^;];%d%c", leitor, &code_categ, leitor2, &code_product,&x);
		if (qtd_teste == 2){
			if(contains_categ(root_category,code_categ)){
				root_category = delete_category(root_category, code_categ);
			}
		}
		else if (qtd_teste == 4){
			aux_categ = get_category(root_category, code_categ);
			if ((aux_categ != NULL) && (contains_product(aux_categ->root_product, code_product))){
				aux_categ->root_product = delete_product(aux_categ->root_product, code_product);
			}
		}
		/**else
			printf ("\nARQUIVO PARA Delete COM QUANTIDADE INVALIDA DE INFORMACOES\nVIDE HELP -h\n");*/
	}//fim while de leitura do arquivo
	#if defined(_EXECUTION_TIME)
		stop = clock();
		time = (double)(stop - start)* (double)1000/CLOCKS_PER_SEC;
		printf ("%f\n", time);
	#endif
	return root_category;
}

void aplication_get(FILE *get, node_category_t* root_category){
	if (get == NULL){
		printf ("Arquivo para get vazio");;
	}
	node_category_t *aux_categ=NULL; // variaveis auxiliares para execução
	node_product_t *aux_product = NULL;
	char leitor[20], leitor2[20], linha[60]; // variaveis para leitura de arguivos
	int code_categ = 0, code_product = 0, qtd_teste = 0;//variaveis para pegar informações de execução
	char x; // para pegar excedentes do arquivo
	#if defined(_EXECUTION_TIME)
		clock_t start, stop;
		start = 0;
		stop = 0;
		double time = 0;
		start = clock();
	#endif
	while (fscanf (get, "%s\n", linha)!= EOF){
		qtd_teste = sscanf(linha, "%[^;];%d;%[^;];%d%c", leitor, &code_categ, leitor2, &code_product, &x);
		if (qtd_teste == 2){

			aux_categ = get_category(root_category, code_categ);
			//if (aux_categ != NULL)
			//printf("GET COM SUCESSO NA CATEGORIA: %s\tCODIGO: %d", aux_categ->name, aux_categ->code);
		}
		else if (qtd_teste == 4){
			aux_categ = get_category(root_category, code_categ);
			if (aux_categ){
				aux_product = get_product(aux_categ->root_product, code_product);
			}
		}
		else
			printf ("\nARQUIVO PARA Get COM QUANTIDADE INVALIDA DE INFORMACOES\nVIDE HELP -h\n");
	}//fim while de leitura do arquivo
	#if defined(_EXECUTION_TIME)
		stop = clock();
		time = (double)(stop - start)* (double)1000/CLOCKS_PER_SEC;
		printf ("%f\n", time);
	#endif
}

void aplication_contain(FILE *contain, node_category_t* root_category){
	if (contain == NULL){
		printf ("Arquivo para contain vazio");
	}
	node_category_t *aux_categ=NULL; // variaveis auxiliares para execução
	node_product_t *aux_product = NULL;
	char leitor[20], leitor2[20], linha[60]; // variaveis para leitura de arguivos
	int code_categ = 0, code_product = 0, qtd_teste = 0;//variaveis para pegar informações de execução
	char x; // para pegar excedentes do arquivo
	#if defined(_EXECUTION_TIME)
		clock_t start, stop;
		start = 0;
		stop = 0;
		double time = 0;
		start = clock();
	#endif
	while (fscanf (contain, "%s\n", linha) != EOF){
		qtd_teste = sscanf(linha, "%[^;];%d;%[^;];%d%c", leitor, &code_categ, leitor2, &code_product,&x);

		if ((qtd_teste == 2) && (contains_categ(root_category, code_categ))){
			//printf ("CATEGORIA %d EXISTENTE", code_categ);
		}
		else if (qtd_teste == 4){
			if(contains_categ(root_category,code_categ)){
				aux_categ = get_category(root_category, code_categ);
				if ((aux_categ != NULL) && (contains_product(aux_categ->root_product, code_product))){
					//printf ("O PRODUTO %d SE ENCONTRA NO CATALOGO", code_product);
				}
			}
		}
		//else
			//printf ("\nARQUIVO PARA Contains COM QUANTIDADE INVALIDA DE INFORMACOES\nVIDE HELP -h\n");
	}//fim while de leitura do arquivo
	#if defined(_EXECUTION_TIME)
		stop = clock();
		time = (double)(stop - start)* (double)1000/CLOCKS_PER_SEC;
		printf ("%f\n", time);
	#endif
}


void aplication_rank(FILE *rank, node_category_t* root_category){
	if (rank == NULL){
		printf ("Arquivo para rank vazio");
	}
	node_category_t *aux_categ=NULL; // variaveis auxiliares para execução
	node_product_t *aux_product = NULL;
	char leitor[20], leitor2[20], linha[60]; // variaveis para leitura de arguivos
	int code_categ = 0, code_product = 0, qtd_teste = 0;//variaveis para pegar informações de execução
	char x; // para pegar excedentes do arquivo
	#if defined(_EXECUTION_TIME)
		clock_t start, stop;
		start = 0;
		stop = 0;
		double time = 0;
		start = clock();
	#endif
	while (fscanf (rank, "%s\n", linha) != EOF){
		qtd_teste = sscanf(linha, "%[^;];%d;%[^;];%d%c", leitor, &code_categ, leitor2, &code_product,&x);
		if ((qtd_teste == 2) && (contains_categ(root_category,code_categ))){
			//printf ("O RANK DA CATEGORIA %d EH: %d", code_categ, rank_categ(root_category, code_categ));
			qtd_teste = rank_categ(root_category, code_categ);
		}
		else if (qtd_teste == 4){
			aux_categ = get_category(root_category, code_categ);
			if ((aux_categ != NULL) && (contains_product(aux_categ->root_product, code_product))){
				//printf ("O RANK DO PRODUTO %d EH: %d", code_product, rank_product(aux_categ->root_product, code_product));
				qtd_teste = rank_product(aux_categ->root_product, code_product);
			}
		}
		//else
			//printf ("\nARQUIVO PARA Rank COM QUANTIDADE INVALIDA DE INFORMACOES\nVIDE HELP -h\n");
	}//fim while de leitura do arquivo
	#if defined(_EXECUTION_TIME)
		stop = clock();
		time = (double)(stop - start)* (double)1000/CLOCKS_PER_SEC;
		printf ("%f\n", time);
	#endif
}


void aplication_floor(FILE *flooor, node_category_t* root_category){
	if (flooor == NULL){
		printf ("Arquivo para floor vazio");
	}
	node_category_t *aux_categ=NULL; // variaveis auxiliares para execução
	node_product_t *aux_product = NULL;
	char leitor[20], leitor2[20], linha[60]; // variaveis para leitura de arguivos
	int code_categ = 0, code_product = 0, qtd_teste = 0;//variaveis para pegar informações de execução
	char x; // para pegar excedentes do arquivo
	#if defined(_EXECUTION_TIME)
		clock_t start, stop;
		start = 0;
		stop = 0;
		double time = 0;
		start = clock();
	#endif
	while (fscanf (flooor, "%s\n", linha)!= EOF){
		qtd_teste = sscanf(linha, "%[^;];%d;%[^;];%d%c", leitor, &code_categ, leitor2, &code_product, &x);
		if (qtd_teste == 2){
			qtd_teste = floor_categ(root_category, code_categ);
			//if(qtd_teste == -1)
				//printf("\nO NUMERO %d NAO POSSUI FLOOR\n", code_categ);
			//else
				//printf ("\nO FLOOR DE %d EH A CATEGORIA: %d\n", code_categ, qtd_teste);
		}
		else if (qtd_teste == 4){
			aux_categ = get_category(root_category, code_categ);
			if (aux_categ){
			qtd_teste = floor_product(aux_categ->root_product, code_product);
				//if(qtd_teste == -1)
					//printf("\nO NUMERO %d NAO POSSUI FLOOR\n", code_product);
			//	else
					//printf ("\nO FLOOR DE %d EH O PRODUTO: %d\n", code_product, qtd_teste);
			}
		}
	//else
			//printf ("\nARQUIVO PARA Floor COM QUANTIDADE INVALIDA DE INFORMACOES\nVIDE HELP -h\n");
	} //fim while de leitura do arquivo
	#if defined(_EXECUTION_TIME)
		stop = clock();
		time = (double)(stop - start)* (double)1000/CLOCKS_PER_SEC;
		printf ("%f\n", time);
	#endif
}



void aplication_ceiling(FILE *ceiling, node_category_t* root_category){
	if (ceiling == NULL){
		printf ("Arquivo para ceiling vazio");
	}
	node_category_t *aux_categ=NULL; // variaveis auxiliares para execução
	node_product_t *aux_product = NULL;
	char leitor[20], leitor2[20], linha[60]; // variaveis para leitura de arguivos
	int code_categ = 0, code_product = 0, qtd_teste = 0;//variaveis para pegar informações de execução
	char x; // para pegar excedentes do arquivo
	#if defined(_EXECUTION_TIME)
		clock_t start, stop;
		start = 0;
		stop = 0;
		double time = 0;
		start = clock();
	#endif
	while (fscanf (ceiling, "%s\n", linha) != EOF){
		qtd_teste = sscanf(linha, "%[^;];%d;%[^;];%d%c", leitor, &code_categ, leitor2, &code_product,&x);
		if (qtd_teste == 2){
			qtd_teste = ceiling_categ(root_category, code_categ);
			//if(qtd_teste == -1)
				//printf("\nO NUMERO %d NAO POSSUI CEIL\n", code_categ);
			//else
				//printf ("\nO CEIL DO CODIGO %d EH A CATEGORIA: %d\n", code_categ, qtd_teste);
		}
		else if (qtd_teste == 4){
			aux_categ = get_category(root_category, code_categ);
			if (aux_categ){
				qtd_teste = ceiling_product(aux_categ->root_product, code_product);
				//if(qtd_teste == -1)
					//printf("\nO NUMERO %d NAO POSSUI CEIL\n", code_product);
				//else
					//printf ("\nCEIL DO CODIGO %d EH O PRODUTO: %d\n", code_product, qtd_teste);
			}
		}
	//else
			//printf ("\nARQUIVO PARA Ceil COM QUANTIDADE INVALIDA DE INFORMACOES\nVIDE HELP -h\n");
	}//fim while de leitura do arquivo
	#if defined(_EXECUTION_TIME)
		stop = clock();
		time = (double)(stop - start)* (double)1000/CLOCKS_PER_SEC;
		printf ("%f\n", time);
	#endif
}



void help(){
	printf ("\n\n|=========================================================================================================|\n");
	printf ("|              ********************************* COMO USAR *********************************              |\n");
	printf ("|                 -p <entrada.csv> Para determinar um arquivo que adciona produtos a loja                 |\n");
	printf ("|     -g <entrada.csv> Para determinar um arquivo que pega um determinado produto ou categoria da loja    |\n");
	printf ("|         -d <entrada.csv> Para determinar um arquivo que deleta um produto ou categoria da loja          |\n");
	printf ("|    -c <entrada.csv> Para determinar um arquivo que verifica se um produto ou categoria existe na loja   |\n");
	printf ("|  -R <entrada.csv> Para determinar um arquivo que ve o Rank na arvore de uma categoria ou de um Produto  |\n");
	printf ("| -F <entrada.csv> Para determinar um arquivo que ve o floor na arvore de uma categoria ou de um produto  |\n");
	printf ("|-C <entrada.csv> Para determinar um arquivo que ve o ceiling na arvore de uma categoria ou de um produto |\n");
	printf ("|                         -S <entrada.txt> Determina a sequencia de execucao;                             |\n");
	printf ("|                        *-S EH SEMPRE NECESSARIA PARA A EXECUCAO DO SOFTWARE*                            |\n");
	printf ("|                                      *Opcoes de sequencia*                                              |\n");
	printf ("|                     p, g, d, c, R, F, C ou S, para executar uma das funcoes acima                       |\n");
	printf ("|                                H mostra a altura de todas as arvores                                    |\n");
	printf ("|                               s mostra o tamanho de todas as arvores                                    |\n");
	printf ("|                                M mostra o maior de todas as arvores                                     |\n");
	printf ("|                                m mostra o menor de todas as arvores                                     |\n");
	printf ("|                                    i mostrar todas as arvores                                           |\n");
	printf ("|=========================================================================================================|\n\n");
}
