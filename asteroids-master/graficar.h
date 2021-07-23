#ifndef _GRAFICAR_H_
#define _GRAFICAR_H_

#include "herramientas.h"

#include "caracteres.h"

void dibujar_letra (const int (*vect_dir)[2], int n_dic, SDL_Renderer *renderer, float desplazamiento, float posicion_y,float escala);
void dibujar_string(char string[MAX_STRING], const caracteres_t dicc[CANT_CARACTERES], size_t n_string, SDL_Renderer *renderer, float desplazamiento, float posicion_y,float escala);
void datos_en_pantalla(SDL_Renderer *renderer,int score,int best_score, int vida_nave);
void mensajes_finde_partida(SDL_Renderer *renderer,int score);
void mensaje_iniciode_partida(SDL_Renderer *renderer);

#endif

