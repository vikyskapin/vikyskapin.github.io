#ifndef _DISPAROS_H_
#define _DISPAROS_H_

#include <stdbool.h> 

struct disp
{
	sprite_t  sp_disparo;
	float escala;
	float posicion_x;
	float posicion_y;
	float velocidad;
	float angulo;
	float tiempo_vida;
};

typedef struct disp disparo_t; 

disparo_t * disparo_crear(float px, float py, float angulo);
void disparo_destruir(void*shot);
bool disparo_dibujar(disparo_t *shot);
void disparo_mover(disparo_t *shot, float dt);

#endif