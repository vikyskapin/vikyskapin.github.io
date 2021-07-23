#include "lista.h"

struct nodo *nodo_crear(void *d) 
{
	struct nodo *n = malloc(sizeof(struct nodo)); //creo el nodo
	if(n == NULL)
		return NULL;

	n->sig = NULL;//como va a ser el ultimo, el siguiente lo apunto a null
	n->dato = d;//le asigno a dato la informacion de "d"

	return n;
}

lista_t *lista_crear() {
	lista_t *l = malloc(sizeof(lista_t));//pido memoria para una lista
	
	if(l == NULL)
		return NULL;

	l->prim = NULL;//primer nodo a null, lista vacia
	return l;
}


void lista_destruir(lista_t *l, void (*destruir_dato)(void *d)){

	struct nodo *n = l->prim;
	while(n != NULL) {
	struct	nodo *sig = n->sig; 

		if(destruir_dato != NULL)
			destruir_dato(n->dato);

		free(n);//libero el nodo n

		n = sig;//paso al siguiente nodo con el nodo auxiliar sig.
	}
	free(l);//libero la lista.
}

bool lista_es_vacia(const lista_t *l) {
	return l->prim == NULL;
}

bool lista_insertar_comienzo(lista_t *l, void *d){

	struct nodo *n = nodo_crear(d);
	if(n == NULL)
		return false;

	n->sig = l->prim;
	l->prim = n;

	return true;
}

void lista_estructura_borrar(lista_t *l, void *estructura){
   // Borro al principio:
	if(l->prim==NULL)
		return;

   while(l->prim->dato == estructura) 
   {
      struct nodo *aux = l->prim->sig;
      free(l->prim->dato);
      l->prim = aux;
      if(l->prim==NULL)
      	break;
   }

   // Borro del resto:
   struct nodo *ant = l->prim; 
   if(ant == NULL)
   		return;
   struct nodo *actual;

   while(ant->sig != NULL) 
   {
      actual = ant->sig;
      if(actual->dato == estructura) 
      {
         ant->sig = actual->sig;
         free(actual->dato);
      }
      else
          ant = actual;
   }
}
