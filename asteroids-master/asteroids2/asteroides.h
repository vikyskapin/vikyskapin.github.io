#ifndef _ASTEROIDES_H_
#define _ASTEROIDES_H_

#include "graficador.h"
#include <stdbool.h>

struct asters
{
	sprite_t *sp_asteroide;
	float posicion_x;
	float posicion_y;
	float velocidad_x;
	float velocidad_y;
	float angulo_rotacion;
	size_t radio;
	
};

typedef struct asters asteroide_t;

asteroide_t * asteroide_crear(size_t radio, float px, float py);
void asteroide_mover(asteroide_t *rock, float dt);
bool asteroide_dibujar(asteroide_t *rock);
void asteroide_destruir(void *asteroide);

#endif