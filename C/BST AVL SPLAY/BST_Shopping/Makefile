main: main.o categorias.o produtos.o execution.o
		gcc -o main main.o categorias.o produtos.o execution.o -I.

main.o: main.c BST_shopping.h
		gcc -c main.c BST_shopping.h -I.

categorias.o: categorias.c BST_shopping.h
		gcc -c categorias.c BST_shopping.h -I.

produtos.o: produtos.c BST_shopping.h
		gcc -c produtos.c BST_shopping.h -I.

execution.o: execution.c BST_shopping.h
		gcc -c -D_EXECUTION_TIME execution.c BST_shopping.h -I.

##################################################################
#make put
put: main_put

main_put:	main_put.o categorias_put.o produtos_put.o execution_put.o
		gcc -o main_put main.o categorias.o produtos.o execution.o -I.

main_put.o: main.c BST_shopping.h
		gcc -c main.c BST_shopping.h -I.

categorias_put.o: categorias.c BST_shopping.h
		gcc -c categorias.c BST_shopping.h -I.

produtos_put.o: produtos.c BST_shopping.h
		gcc -c produtos.c BST_shopping.h -I.

execution_put.o: execution.c BST_shopping.h
		gcc -c -D_PUT	execution.c BST_shopping.h -I.

clean_put:
		rm *o main_put

clean:
		rm *o main
