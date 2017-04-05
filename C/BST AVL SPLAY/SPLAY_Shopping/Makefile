all: main
main: main.o categorias_splay.o produtos_splay.o execution_splay.o SPLAY_aplication.o
		gcc -o main main.o categorias_splay.o produtos_splay.o execution_splay.o SPLAY_aplication.o -I.

main.o: main.c SPLAY_shopping.h
		gcc -c main.c SPLAY_shopping.h -I.

categorias_splay.o: categorias_splay.c SPLAY_shopping.h
		gcc -c categorias_splay.c SPLAY_shopping.h -I.

produtos_splay.o: produtos_splay.c SPLAY_shopping.h
		gcc -c produtos_splay.c SPLAY_shopping.h -I.

execution_splay.o: execution_splay.c SPLAY_shopping.h
		gcc -c -D_EXECUTION_TIME execution_splay.c SPLAY_shopping.h -I.

SPLAY_aplication.o: SPLAY_aplication.c SPLAY_shopping.h
		gcc -c SPLAY_aplication.c SPLAY_shopping.h -I.
##################################################################
#make put
put: main_put

main_put:	main_put.o categorias_splay_put.o produtos_splay_put.o execution_splay_put.o SPLAY_aplication_put.o
		gcc -o main_put main.o categorias_splay.o produtos_splay.o execution_splay.o SPLAY_aplication.o -I.

main_put.o: main.c SPLAY_shopping.h
		gcc -c main.c SPLAY_shopping.h -I.

categorias_splay_put.o: categorias_splay.c SPLAY_shopping.h
		gcc -c categorias_splay.c SPLAY_shopping.h -I.

produtos_splay_put.o: produtos_splay.c SPLAY_shopping.h
		gcc -c produtos_splay.c SPLAY_shopping.h -I.

execution_splay_put.o: execution_splay.c SPLAY_shopping.h
		gcc -c -D_PUT	execution_splay.c SPLAY_shopping.h -I.

SPLAY_aplication_put.o: SPLAY_aplication.c SPLAY_shopping.h
		gcc -c SPLAY_aplication.c SPLAY_shopping.h -I.

clean_put:
		rm *o main_put

clean:
		rm *o main
