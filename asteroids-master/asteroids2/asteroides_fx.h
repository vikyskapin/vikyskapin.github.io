#ifndef __ASTEROIDES_FX__
#define __ASTEROIDES_FX__
#include <stdbool.h>
#include "lista.h"
#include "asteroides.h"
#include "nave.h"
#include "disparos.h"

bool cargar_asteroides_lista(lista_t *l_rock, float px, float py,size_t radio);
bool crear_asteroides_iniciales(size_t cant,lista_t* l_rock);
void mover_lista_asteroides(lista_t*l_rock,float dt);
bool dibujar_lista_asteroides(lista_t*l_rock);
float distancia(asteroide_t *asteroide, float objeto_x, float objeto_y);
bool asteroide_choco(nave_t *nave,lista_t *l_shot, asteroide_t *asteroide);
void lista_asteroide_choco(lista_t *l_rock,nave_t *nave,lista_t *l_shot,int *score);
bool revivir_nave(lista_t *l_rock,nave_t* nave,int *vidas_nave);


#endif