#include "asteroides.h"
#include <stdlib.h>
#include <stdio.h>
#include "graficador.h"
#include "config.h"
#include "herramientas.h"

asteroide_t * asteroide_crear(size_t radio, float px, float py){
	asteroide_t * asteroide; 
	asteroide = malloc(sizeof(asteroide_t));
	if (asteroide==NULL)
		return NULL;

	int asteroide_aleatorio= generar_aleatorio(identificar_sprite(ROCK4)+1,identificar_sprite(ROCK1));

	asteroide->sp_asteroide=sprite[asteroide_aleatorio];
	
	asteroide->posicion_x=px;
	asteroide->posicion_y=py;
	asteroide->radio=radio;

	asteroide->velocidad_x = generar_aleatorio(((VELOCIDAD_ASTEROIDE_ORIGINAL/radio) + VELOCIDAD_ASTEROIDE_OFFSET), ((VELOCIDAD_ASTEROIDE_ORIGINAL/radio) - VELOCIDAD_ASTEROIDE_OFFSET));

	asteroide->velocidad_y = generar_aleatorio(((VELOCIDAD_ASTEROIDE_ORIGINAL/radio) + VELOCIDAD_ASTEROIDE_OFFSET), ((VELOCIDAD_ASTEROIDE_ORIGINAL/radio) - VELOCIDAD_ASTEROIDE_OFFSET));

	asteroide->angulo_rotacion = generar_aleatorio(NAVE_ANGULO_INICIAL, NAVE_ANGULO_INICIAL + PI);

	return asteroide;
}

void asteroide_mover(asteroide_t *rock, float dt){
	rock->posicion_x = computar_posicion(rock->posicion_x, rock->velocidad_x, dt);
	rock->posicion_y = computar_posicion(rock->posicion_y, rock->velocidad_y, dt);

	graficador_ajustar_variables(&rock->posicion_x, &rock->posicion_y);
}

bool asteroide_dibujar(asteroide_t *rock){
	return graficador_dibujar(
				rock->sp_asteroide->nombre, 
				rock->radio, 
				rock->posicion_x,
				rock->posicion_y, 
				rock->angulo_rotacion);
}

void asteroide_destruir(void *asteroide){
	free((asteroide_t *)asteroide);
}

