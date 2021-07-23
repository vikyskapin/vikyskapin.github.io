all: asteroides.o caracteres.o disparos.o graficar.o  lista.o graficador.o nave.o herramientas.o asteroides_fx.o disparos_fx.o main.o 
	gcc -std=c99 -Wall -pedantic -g asteroides.o caracteres.o disparos.o graficar.o lista.o graficador.o disparos_fx.o asteroides_fx.o nave.o herramientas.o main.o -o asteroids -lm -lSDL2

asteroides.o: asteroides.c
	gcc -std=c99 -Wall -pedantic -c asteroides.c -o asteroides.o -lm -lSDL2

caracteres.o: caracteres.c
	gcc -std=c99 -Wall -pedantic -c caracteres.c -o caracteres.o

disparos.o: disparos.c 
	gcc -std=c99 -Wall -pedantic -c disparos.c -o disparos.o -lm -lSDL2

graficar.o : graficar.c
	gcc -std=c99 -Wall -pedantic  -c graficar.c -o graficar.o -lm -lSDL2

lista.o: lista.c 
	gcc -std=c99 -Wall -pedantic  -c lista.c -o lista.o

graficador.o: graficador.c 
	gcc -std=c99 -Wall -pedantic  -c graficador.c -o graficador.o -lm -lSDL2

nave.o: nave.c 
	gcc -std=c99 -Wall -pedantic  -c nave.c -o nave.o -lm -lSDL2

herramientas.o: herramientas.c 
	gcc -std=c99 -Wall -pedantic  -c herramientas.c -o herramientas.o -lm -lSDL2

disparos_fx.o: disparos_fx.c
	gcc -std=c99 -Wall -pedantic  -c disparos_fx.c -o disparos_fx.o -lm -lSDL2

asteroides_fx.o: asteroides_fx.c
	gcc -std=c99 -Wall -pedantic  -c asteroides_fx.c -o asteroides_fx.o -lm -lSDL2	

main.o: main.c
	gcc -std=c99 -Wall -pedantic  -c main.c -o main.o -lm -lSDL2

clean: 
	rm *.o

run: all
	./asteroids