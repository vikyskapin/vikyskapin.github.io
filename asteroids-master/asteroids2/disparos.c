#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "config.h"
#include "herramientas.h"
#include "disparos.h"


disparo_t * disparo_crear(float px, float py, float angulo){
	disparo_t * shot; 
	shot = malloc(sizeof(disparo_t));
	if (shot==NULL)
		return NULL;

	shot->sp_disparo=*sprite[identificar_sprite(SHOT)];	
	shot->posicion_x=px;
	shot->posicion_y=py;
	shot->angulo=angulo;
	shot->velocidad=VELOCIDAD_DISPARO;
	shot->tiempo_vida= TIEMPO_VIDA_SHOT;
	shot->escala=ESCALA_DISPARO; 

	return shot;
}

void disparo_destruir(void *shot){
	free((disparo_t*)shot);
} 

bool disparo_dibujar(disparo_t *shot){
	if(shot->tiempo_vida>0.0){
		return graficador_dibujar(
				shot->sp_disparo.nombre, 
				shot->escala, 
				shot->posicion_x,
				shot->posicion_y, 
				shot->angulo);
	}
	else 
		return false;
}

void disparo_mover(disparo_t *shot, float dt){
	(shot->tiempo_vida)+=-dt;
	shot->posicion_x=computar_posicion(shot->posicion_x,shot->velocidad*cos(shot->angulo),dt);
	shot->posicion_y=computar_posicion(shot->posicion_y,-(shot->velocidad*sin(shot->angulo)),dt);
}
