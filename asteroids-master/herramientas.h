#ifndef _HERRAMIENTAS_H_
#define _HERRAMIENTAS_H_

#include <SDL2/SDL.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#include "config.h"
#include "caracteres.h"
#include "graficar.h"
#include "modulo.h"
#include "lista.h"

float generar_aleatorio(float superior, float inferior);

float **crear_vector(size_t filas, size_t columnas);

void destruir_vector(float **v,size_t n);

float **matriz_a_vector(float (*m)[MAX_COORDENADAS], size_t n);

void rotar(float **coordenadas, int n, double rad);

double computar_posicion(double pi, double vi, double dt);

int bestscore(int best_score,int score);

#endif

