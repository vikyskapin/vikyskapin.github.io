#ifndef _CARACTERES_H_
#define _CARACTERES_H_

#include <stdio.h>
#include <stdlib.h>

#define CARACTER_ANCHO 5.5
#define CARACTER_ALTO 2
#define CANT_CARACTERES 41

#define MAX_STRING 1000


typedef struct chars_anscii
{	char caracter;
	const int (*vect_dir)[2];
	 int longitud;
}caracteres_t;


extern const int caracter_a[7][2];
extern const int caracter_b[12][2];
extern const int caracter_c[4][2];
extern const int caracter_d[7][2];
extern const int caracter_e[7][2];
extern const int caracter_f[6][2];
extern const int caracter_g[7][2];
extern const int caracter_h[6][2];
extern const int caracter_i[6][2];
extern const int caracter_j[4][2];
extern const int caracter_k[6][2];
extern const int caracter_l[3][2];
extern const int caracter_m[5][2];
extern const int caracter_n[4][2];
extern const int caracter_o[5][2];
extern const int caracter_p[5][2];
extern const int caracter_q[9][2];
extern const int caracter_r[7][2];
extern const int caracter_s[6][2];
extern const int caracter_t[4][2];
extern const int caracter_u[4][2];
extern const int caracter_v[3][2];
extern const int caracter_w[5][2];
extern const int caracter_x[5][2];
extern const int caracter_y[5][2];
extern const int caracter_z[4][2];

extern const int caracter_0[5][2];
extern const int caracter_1[2][2];
extern const int caracter_2[6][2];
extern const int caracter_3[7][2];
extern const int caracter_4[5][2];
extern const int caracter_5[6][2];
extern const int caracter_6[5][2];
extern const int caracter_7[3][2];
extern const int caracter_8[7][2];
extern const int caracter_9[5][2];

extern const int caracter_derecha[5][2];
extern const int caracter_izquierda[5][2];
extern const int caracter_arriba[5][2];
extern const int caracter_abajo[5][2];

extern const int caracter_espacio[1][2];

extern const caracteres_t DICCIONARIO[CANT_CARACTERES];

#endif // _LETRAS_H_
