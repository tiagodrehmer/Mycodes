main: main.o categorias_avl.o produtos_avl.o execution_avl.o AVL_aplication.o
		gcc -o main main.o categorias_avl.o produtos_avl.o execution_avl.o AVL_aplication.o -I.

main.o: main.c AVL_shopping.h
		gcc -c main.c AVL_shopping.h -I.

categorias_avl.o: categorias_avl.c AVL_shopping.h
		gcc -c categorias_avl.c AVL_shopping.h -I.

produtos_avl.o: produtos_avl.c AVL_shopping.h
		gcc -c produtos_avl.c AVL_shopping.h -I.

execution_avl.o: execution_avl.c AVL_shopping.h
		gcc -c -D_EXECUTION_TIME execution_avl.c AVL_shopping.h -I.

AVL_aplication.o: AVL_aplication.c AVL_shopping.h
		gcc -c AVL_aplication.c AVL_shopping.h -I.


###################################################
#put
put: main_put

main_put:	main_put.o categorias_avl_put.o produtos_avl_put.o execution_avl_put.o AVL_aplication_put.o
		gcc -o main_put main.o categorias_avl.o produtos_avl.o execution_avl.o AVL_aplication.o -I.

main_put.o: main.c AVL_shopping.h
		gcc -c main.c AVL_shopping.h -I.

categorias_avl_put.o: categorias_avl.c AVL_shopping.h
		gcc -c categorias_avl.c AVL_shopping.h -I.

produtos_avl_put.o: produtos_avl.c AVL_shopping.h
		gcc -c produtos_avl.c AVL_shopping.h -I.

execution_avl_put.o: execution_avl.c AVL_shopping.h
		gcc -c -D_PUT	execution_avl.c AVL_shopping.h -I.

AVL_aplication_put.o: AVL_aplication.c AVL_shopping.h
		gcc -c AVL_aplication.c AVL_shopping.h -I.

clean_put:
		rm *o main_put

clean:
		rm *o main
