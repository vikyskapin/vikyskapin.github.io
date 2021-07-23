#ifndef _DISPAROS_H_
#define _DISPAROS_H_

#include "herramientas.h"

typedef struct
{
	sprite_t  sp_disparo;
	float escala;
	float posicion_x;
	float posicion_y;
	float velocidad;
	float angulo;
	float tiempo_vida;
}disparo_t;


disparo_t * disparo_crear(float px, float py, float angulo);
void disparo_destruir(void*shot);
bool disparo_dibujar(disparo_t *shot,SDL_Renderer *r);
void disparo_mover(disparo_t *shot, float dt);
bool cargar_disparos(lista_t *l_shot,float px,float py,float angulo);
bool dibujar_lista_disparos(lista_t*l_shot,SDL_Renderer *r);
void mover_lista_disparos(lista_t*l,float dt);

#endif