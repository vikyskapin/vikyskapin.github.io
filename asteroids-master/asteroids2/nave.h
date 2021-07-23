#ifndef _NAVE_H_
#define _NAVE_H_

#include <stdbool.h>
#include "graficador.h"

struct nav
{
	sprite_t *sp_nave;
	sprite_t sp_chorro;
	size_t vida;//utilizo esta variable como bool para verificar si choca contra un asteroide.
	float escala;
	float posicion_x;
	float posicion_y;
	float velocidad_x;
	float velocidad_y;
	float angulo_rotacion;
	size_t potencia;
};

typedef struct nav nave_t;

nave_t nave_crear();
void nave_mover(nave_t *nave, float dt, int potencia);
bool nave_dibujar(nave_t *x);

#endif