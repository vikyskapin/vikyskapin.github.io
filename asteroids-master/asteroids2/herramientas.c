#include "herramientas.h"


float generar_aleatorio(float superior, float inferior)
{
	return ((superior-inferior) * ((float)rand()/(float)RAND_MAX) + inferior );
}

float **crear_vector(size_t filas, size_t columnas)
{
    float **vector;
    size_t i;

	if((vector = malloc(filas*sizeof(float*)))==NULL)
		return NULL;
	for(i=0; i<filas; i++)
	    if((vector[i] = malloc(columnas*sizeof(float)))==NULL) 
		{
			destruir_vector(vector, filas);
	    	return NULL;
		}
	return vector;
}

void destruir_vector(float **v,size_t n){

	for(int i = 0;i < n;i++){

		free (v[i]);
	}
	free (v);
}


float **matriz_a_vector(float (*m)[MAX_COORDENADAS], size_t n)
{
	size_t i, j;
	float **vector;

	vector = crear_vector(n, MAX_COORDENADAS);

	for(i=0; i<n; i++)
		for(j=0; j<MAX_COORDENADAS; j++)
			vector[i][j] = m[i][j];

	return vector;
}


double computar_posicion(double pi, double vi, double dt)
{
	return dt*vi+pi;
}

double computar_velocidad(double vi, double aceleracion, double dt)
{
	return dt*aceleracion+vi;
}

void rotar(float **coordenadas, int n, double rad)
{
	int i;
    float coseno_rad = cos(rad);
    float seno_rad = sin(rad);
    float x_rotada, y_rotada;
    
	for(i=0; i<n; i++)
	{
		x_rotada = (coordenadas[i][0])*coseno_rad - (coordenadas[i][1])*seno_rad;
		y_rotada = (coordenadas[i][0])*seno_rad + (coordenadas[i][1])*coseno_rad;
		
		coordenadas[i][0] = x_rotada;
		coordenadas[i][1] = y_rotada;	
	}
}


int bestscore(int best_score,int score){
	if (score > best_score)
		return score;

	else return best_score;
}

size_t identificar_sprite(char nombre[10]){
	size_t n;

	for(n=0; n < sprites_size; n++){
		if(!strcmp(sprite[n]->nombre, nombre))
			break;
	}
	return n;
}