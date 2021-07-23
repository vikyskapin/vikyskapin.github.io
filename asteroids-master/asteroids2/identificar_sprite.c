#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "graficador.h"

#define NAVE "SHIP"
#define CHORRO "THURST"
#define SHOT "SHOT"
#define ROCK1 "ROCK1"
#define ROCK2 "ROCK2"
#define ROCK3 "ROCK3"
#define ROCK4 "ROCK4"

size_t identificar_sprite(char nombre[10]);
  

int main (void){
	if(!(graficador_inicializar("sprites.bin",renderer)))
		return 0;
	size_t n;
	n = identificar_sprite(ROCK1);
	printf("n de ROCK1:%d\n",n );

	graficador_finalizar();

	return 0;
}

size_t identificar_sprite(char nombre[10]){
	size_t n;

	for(n=0; n < sprites_size; n++){
		if(!strcmp(sprite[n]->nombre, nombre))
			break;
	}
	return n;
}