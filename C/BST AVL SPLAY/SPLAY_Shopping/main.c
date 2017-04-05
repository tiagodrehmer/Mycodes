/* BUG's emplementados por:
	*G U S T A V O    C R O D - 151151360 
	*R O D R I G O    B I S S O - 151150178
	*T I A G O    D R E H M E R  - 151150180

*/

#include <SPLAY_shopping.h>


int main (int argc, char** argv){

	node_category_t *root_category=NULL;
	FILE *put=NULL, *get=NULL, *del=NULL, *contain=NULL, *rank=NULL, *flooor=NULL, *ceiling=NULL, *sequencia=NULL;
	char opcao;
	int file_check;

	while ((opcao = getopt(argc, argv,"p:g:d:c:R:F:C:S:h\n")) != -1) {
		switch (opcao){
			case 'p':
				put = fopen(optarg,"r");	
				file_check = arquivos_check(opcao, put);
			break;
			case 'g':
				get = fopen(optarg,"r");
				file_check = arquivos_check(opcao, get);
			break;
			case 'd':
				del = fopen(optarg,"r");
				file_check = arquivos_check(opcao, del);
			break;
			case 'c':	
				contain =fopen(optarg,"r");	
				file_check = arquivos_check(opcao, contain);			
			break;
			case 'R':
				rank = fopen(optarg,"r");
				file_check = arquivos_check(opcao, rank);
			break;
			case 'F':
				flooor = fopen(optarg,"r");
				file_check = arquivos_check(opcao, flooor);
			break;	
			case 'C':
				ceiling = fopen(optarg,"r");
				file_check = arquivos_check(opcao, ceiling);
			break;
			case 'S':
				sequencia = fopen(optarg,"r");
			break;
			case 'h':
				help();
			break;
			default: 
				help();
				exit(EXIT_FAILURE);
			break;
		}
		if (!file_check) //acaba com o while se nao foi possivel abrir algum arquivo
			break;	
	}

	if(sequencia == NULL){
		printf ("\n*NAO HA UMA SEQUENCIA DE COMANDOS PARA SER EXECUTADA\n");
		file_check = 0;
	}
	else if (file_check){
		while (fscanf (sequencia, "%c", &opcao)!= EOF){
			switch (opcao){
				case 'p':
					root_category = recept_put(put,root_category);
				break;
				case 'g':
					root_category = aplication_get(get, root_category);
				break;
				case 'd':
					root_category = aplication_delete(del, root_category);
				break;
				case 'c':
					root_category = aplication_contain(contain, root_category);
				break;
				case 's':
					size_all(root_category);
				break;
				case 'm':
					printf ("\nMinimo das categorias: %d \n", min_categ(root_category)->code);
					min_all(root_category);
				break;
				case 'M':
					printf ("\nMaximo das categorias: %d \n", max_categ(root_category)->code);
					max_all(root_category);
				break;
				case 'R':
					root_category = aplication_rank(rank, root_category);
				break;
				case 'H':
					printf ("\nO height das categoria: %d", height_categ(root_category));
					height_all(root_category);
				break;	
				case 'F':
					root_category = aplication_floor(flooor, root_category);
				break;	
				case 'C':
					root_category = aplication_ceiling(ceiling, root_category);
				break;
				case 'i':
					inorder_all(root_category);
				break;
				case '\n':
				break;
				case ' ':
				break;
				default:
					printf ("\n*INVALID COMMAND* -%c\n", opcao);
				break;
			}
		}
	}


	//printf ("Total de categorias: %d", cont_categ);
	//printf ("\n total de produtos: %d", cont_product);

	#if defined(gnuplot)
		FILE* saida;
		saida = fopen("arvore.dot", "w");
		fprintf (saida, "digraph{\n");
		gnuplote(saida, root_category);
		fprintf (saida, "}");
		fclose(saida);
		system("dot -Tpng arvore.dot > arvore1.png\n");
		printf("imagem criada no mesmo diretorio do codigo fonte\n");

		FILE* saida2;
		saida2 = fopen("arvore.dot", "w");
		fprintf (saida2, "digraph{\n");
		gnuplote2 (saida2, root_category->root_product);
		fprintf (saida2, "}");
		fclose(saida2);
		system("dot -Tpng arvore.dot > arvore2.png\n");
		printf("imagem criada no mesmo diretorio do codigo fonte\n");
	#endif
	if (del != NULL)
		fclose (del);
	if (get != NULL)
		fclose (get);
	if (put != NULL)
		fclose (put);
	if (rank != NULL)
		fclose (rank);
	if (flooor != NULL)
		fclose (flooor);
	if (contain != NULL)
		fclose (contain);
	if (ceiling != NULL)
		fclose (ceiling);
	if (root_category!=NULL)
		free_all_categ(root_category);
	if (sequencia != NULL)
		fclose (sequencia);
}