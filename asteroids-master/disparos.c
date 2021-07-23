#include "disparos.h"

disparo_t * disparo_crear(float px, float py, float angulo){
	disparo_t * shot; 
	shot = malloc(sizeof(disparo_t));
	if (shot==NULL)
		return NULL;

	shot->sp_disparo=sprite[6];	
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

bool disparo_dibujar(disparo_t *shot,SDL_Renderer *r){
	if(shot->tiempo_vida>0.0){
		return graficador_dibujar(r,
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

bool cargar_disparos(lista_t *l_shot,float px,float py,float angulo){
	disparo_t * shot = disparo_crear(px,py,angulo);
	return (lista_insertar_comienzo(l_shot,shot));
}

void mover_lista_disparos(lista_t*l_shot,float dt){
	struct nodo *aux;
	aux= l_shot->prim;
	while(aux!=NULL){
		if(((disparo_t*)aux->dato)->tiempo_vida > 0.0)
			disparo_mover(((disparo_t*)aux->dato),dt);
		else {
			lista_estructura_borrar(l_shot, ((disparo_t*)aux->dato)); 
		}
			aux=aux->sig;
	}
}

bool dibujar_lista_disparos(lista_t*l_shot,SDL_Renderer *r){
	struct nodo *aux;
	if(l_shot->prim==NULL)//caso lista vacia
		return false;

	aux= l_shot->prim;
	while(aux!=NULL){

		if(disparo_dibujar(((disparo_t*)aux->dato),r));
		aux=aux->sig;
	}
	return true;
}
