#ifndef __DISPAROS_FX__
#define __DISPAROS_FX__

#include <stdbool.h>
#include "lista.h"

bool cargar_disparos(lista_t *l_shot,float px,float py,float angulo);
bool dibujar_lista_disparos(lista_t*l_shot);
void mover_lista_disparos(lista_t*l,float dt);

#endif