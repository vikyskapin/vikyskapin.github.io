#ifndef _LISTA_H_
#define _LISTA_H_

struct nodo{
	struct nodo *sig;
	void *dato;
};

typedef struct {
	struct nodo *prim;
}lista_t;

#include "herramientas.h"

struct nodo *nodo_crear(void *d);
lista_t *lista_crear();
void lista_destruir(lista_t *l, void (*destruir_dato)(void *d));
bool lista_es_vacia(const lista_t *l);
bool lista_insertar_comienzo(lista_t *l, void *d);
void lista_estructura_borrar(lista_t *l, void *estructura);

#endif

