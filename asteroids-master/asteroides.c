#include "asteroides.h"


asteroide_t * asteroide_crear(size_t radio, float px, float py){
	asteroide_t * asteroide; 
	asteroide = malloc(sizeof(asteroide_t));
	if (asteroide==NULL)
		return NULL;
	int asteroide_aleatorio= generar_aleatorio(6,2);

	asteroide->sp_asteroide=&sprite[asteroide_aleatorio];
	
	asteroide->posicion_x=px;
	asteroide->posicion_y=py;
	asteroide->radio=radio;

	asteroide->velocidad_x = generar_aleatorio(((VELOCIDAD_ASTEROIDE_ORIGINAL/radio) + VELOCIDAD_ASTEROIDE_OFFSET), ((VELOCIDAD_ASTEROIDE_ORIGINAL/radio) - VELOCIDAD_ASTEROIDE_OFFSET));

	asteroide->velocidad_y = generar_aleatorio(((VELOCIDAD_ASTEROIDE_ORIGINAL/radio) + VELOCIDAD_ASTEROIDE_OFFSET), ((VELOCIDAD_ASTEROIDE_ORIGINAL/radio) - VELOCIDAD_ASTEROIDE_OFFSET));

	asteroide->angulo_rotacion = generar_aleatorio(NAVE_ANGULO_INICIAL, NAVE_ANGULO_INICIAL + PI);

	return asteroide;
}

void asteroide_mover(asteroide_t *rock, float dt){
	rock->posicion_x = computar_posicion(rock->posicion_x, rock->velocidad_x, dt);
	rock->posicion_y = computar_posicion(rock->posicion_y, rock->velocidad_y, dt);

	if(rock->posicion_x < 0)
		rock->posicion_x = VENTANA_ANCHO;

    if(rock->posicion_x > VENTANA_ANCHO)
		rock->posicion_x = 0;

	if(rock->posicion_y < 0)
		rock->posicion_y = VENTANA_ALTO;

	if(rock->posicion_y > VENTANA_ALTO)
		rock->posicion_y = 0;
}

bool asteroide_dibujar(asteroide_t *rock,SDL_Renderer *r){
	return graficador_dibujar(r,
				rock->sp_asteroide->nombre, 
				rock->radio, 
				rock->posicion_x,
				rock->posicion_y, 
				rock->angulo_rotacion);
}

void asteroide_destruir(void *asteroide){
	free((asteroide_t *)asteroide);
}

bool cargar_asteroides_lista(lista_t *l_rock, float px, float py,size_t radio){
	asteroide_t *asteroide = asteroide_crear(radio,px,py);
	return (lista_insertar_comienzo(l_rock,asteroide));
}

bool crear_asteroides_iniciales(size_t cant,lista_t* l_rock){
	int i;
	float px,py;
	for(i=0;i<cant;i++){
		px=generar_aleatorio(VENTANA_ANCHO, 0);
		py=generar_aleatorio(VENTANA_ALTO, 0);

		if(cargar_asteroides_lista(l_rock,px,py,ASTEROIDE_RADIO_GRANDE)==false)
			return false;
	}
	return true;
}

void mover_lista_asteroides(lista_t*l_rock,float dt){
	struct nodo *aux;
	aux= l_rock->prim;
	while(aux!=NULL){
		asteroide_mover(((asteroide_t*)aux->dato),dt);
		aux=aux->sig;
	}
}

bool dibujar_lista_asteroides(lista_t*l_rock,SDL_Renderer *r){
	struct nodo *aux;
	if(l_rock->prim==NULL)//caso lista vacia
		return false;

	aux= l_rock->prim;
	while(aux!=NULL){

		if(asteroide_dibujar(((asteroide_t*)aux->dato),r)==false)
			return false;		
		aux=aux->sig;
	}

	return true;
}

float distancia(asteroide_t *asteroide, float objeto_x, float objeto_y)
{ 
	float dx = asteroide->posicion_x - objeto_x;
	float dy = asteroide->posicion_y - objeto_y;

	return sqrt((dx*dx + dy*dy));
}//DEVUELVE LA DISTANCIA AL CENTRO DEL ASTEROIDE;

bool asteroide_choco(nave_t *nave,lista_t *l_shot, asteroide_t *asteroide){
	//CHEQUEO CON LA NAVE
	if(distancia(asteroide,nave->posicion_x,nave->posicion_y) <=asteroide->radio)
		nave->vida=0;//destruyo la nave.

	struct nodo *aux;
	aux= l_shot->prim;
	while(aux!=NULL){
		if(distancia(asteroide,
			((disparo_t*)aux->dato)->posicion_x,
			((disparo_t*)aux->dato)->posicion_y)<=asteroide->radio){
			
			((disparo_t*)aux->dato)->tiempo_vida=0.0;//elimina los disparos.
			return true;
			}
		aux=aux->sig;
	}
	return false;
}

void lista_asteroide_choco(lista_t *l_rock,nave_t *nave,lista_t *l_shot,int *score ){

	struct nodo *aux;
	aux= l_rock->prim;
	while(aux!=NULL){
		if(asteroide_choco(nave,l_shot,((asteroide_t*)aux->dato))){
			
			if(((asteroide_t*)aux->dato)->radio == ASTEROIDE_RADIO_CHICO){
				lista_estructura_borrar(l_rock,
					((asteroide_t*)aux->dato));
				*score+=100;
			}

			else if(((asteroide_t*)aux->dato)->radio == ASTEROIDE_RADIO_MEDIANO){
				if(cargar_asteroides_lista(l_rock,
					((asteroide_t*)aux->dato)->posicion_x,
					((asteroide_t*)aux->dato)->posicion_y,
					ASTEROIDE_RADIO_CHICO)){
					if(cargar_asteroides_lista(l_rock,
					((asteroide_t*)aux->dato)->posicion_x,
					((asteroide_t*)aux->dato)->posicion_y,
					ASTEROIDE_RADIO_CHICO));
						lista_estructura_borrar(l_rock,
						((asteroide_t*)aux->dato));
					*score+=50;
				}				
			}//crea asteroides chicos

			else if(((asteroide_t*)aux->dato)->radio == ASTEROIDE_RADIO_GRANDE){
				if(cargar_asteroides_lista(l_rock,
					((asteroide_t*)aux->dato)->posicion_x,
					((asteroide_t*)aux->dato)->posicion_y,
					ASTEROIDE_RADIO_MEDIANO)){
					if(cargar_asteroides_lista(l_rock,
					((asteroide_t*)aux->dato)->posicion_x,
					((asteroide_t*)aux->dato)->posicion_y,
					ASTEROIDE_RADIO_MEDIANO))
						lista_estructura_borrar(l_rock,
						((asteroide_t*)aux->dato));
					*score+=20;
					}
			}//crea asteroides medianos 
		}
		aux=aux->sig;
	}
}

bool revivir_nave(lista_t *l_rock,nave_t* nave,int *vidas_nave){
	struct nodo *aux;
	aux= l_rock->prim;
	while(aux!=NULL){
		if(distancia(((asteroide_t*)aux->dato),NAVE_X_INICIAL,NAVE_Y_INICIAL) <=((asteroide_t*)aux->dato)->radio)
			return false;

		aux=aux->sig;
	}

	*nave=nave_crear();
	*vidas_nave -= 1;
	nave->vida = *vidas_nave;
	return true;
}