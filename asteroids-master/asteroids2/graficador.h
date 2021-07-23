#ifndef _MODULO_H_
#define _MODULO_H_

#include <SDL2/SDL.h>
#include <stdbool.h>

struct sprt {
	char nombre[10];
	uint16_t n;
	float (*cords)[2];
};

typedef struct sprt sprite_t; 


sprite_t **sprite;

extern size_t sprites_size;

SDL_Renderer *renderer;

bool graficador_inicializar(const char *fn,SDL_Renderer *renderer);

bool graficador_dibujar(const char *nombre, float escala, float x, float y, float angulo);

void graficador_finalizar();

void graficador_ajustar_variables(float *x, float *y);

#endif