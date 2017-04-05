Trab3: main.o leitura.o thread.o distrak.o interface.o dots.o
	gcc -o Trab3 main.o leitura.o thread.o distrak.o interface.o dots.o -I. -lpthread -lm

main.o: main.c Mapa.h
	gcc -c main.c -I.

leitura.o: leitura.c Mapa.h
	gcc -c leitura.c -I.

thread.o: thread.c Mapa.h
	gcc -c thread.c -I.	

distrak.o: distrak.c Mapa.h
	gcc -c distrak.c -I.

dots.o: dots.c Mapa.h
	gcc -c dots.c -I.

interface.o: interface.c Mapa.h
	gcc -c interface.c -I.

run:
	./Trab3 cidade.txt

clean:
	rm Trab3 main.o leitura.o thread.o distrak.o mapa.dot dots.o interface.o map.png caminho_curto.dot caminho_curto.png caminho_rapido.dot caminho_rapido.png
