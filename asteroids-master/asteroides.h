#ifndef _ASTEROIDES_H_
#define _ASTEROIDES_H_

#include "nave.h"
#include "disparos.h"
#include "herramientas.h"

typedef struct
{
	sprite_t *sp_asteroide;
	float posicion_x;
	float posicion_y;
	float velocidad_x;
	float velocidad_y;
	float angulo_rotacion;
	size_t radio;
	
}asteroide_t;

asteroide_t * asteroide_crear(size_t radio, float px, float py);
void asteroide_mover(asteroide_t *rock, float dt);
bool asteroide_dibujar(asteroide_t *rock,SDL_Renderer *r);
void asteroide_destruir(void *asteroide);
bool cargar_asteroides_lista(lista_t *l_rock, float px, float py,size_t radio);
bool crear_asteroides_iniciales(size_t cant,lista_t* l_rock);
void mover_lista_asteroides(lista_t*l_rock,float dt);
bool dibujar_lista_asteroides(lista_t*l_rock,SDL_Renderer *r);
float distancia(asteroide_t *asteroide, float objeto_x, float objeto_y);
bool asteroide_choco(nave_t *nave,lista_t *l_shot, asteroide_t *asteroide);
void lista_asteroide_choco(lista_t *l_rock,nave_t *nave,lista_t *l_shot,int *score);
bool revivir_nave(lista_t *l_rock,nave_t* nave,int *vidas_nave);
#endif