#include <stdbool.h>
#include "disparos_fx.h"
#include "disparos.h"
#include "lista.h"


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

bool dibujar_lista_disparos(lista_t*l_shot){
	struct nodo *aux;
	if(l_shot->prim==NULL)//caso lista vacia
		return false;

	aux= l_shot->prim;
	while(aux!=NULL){

		if(disparo_dibujar(((disparo_t*)aux->dato)));
		aux=aux->sig;
	}
	return true;
}
