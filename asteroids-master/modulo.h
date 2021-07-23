#ifndef _MODULO_H_
#define _MODULO_H_

#include "herramientas.h"
#include "nave.h"


#define MAX_SPRITES 7 

sprite_t sprite[MAX_SPRITES];

bool graficador_inicializar(const char *fn);

bool graficador_dibujar(SDL_Renderer *r, const char *nombre, float escala, float x, float y, float angulo);

void graficador_finalizar();

#endif