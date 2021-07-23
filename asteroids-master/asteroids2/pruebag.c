#include <string.h>
#include <stdint.h>
#include <SDL2/SDL.h> 
#include "graficador.h"

SDL_Renderer *renderer;

int main (void){
	printf("sprites_size inicio : %d\n",sprites_size);
	if(!(graficador_inicializar("sprites.bin",renderer)))
		return 0;
	size_t num = 0; 
	printf("sprites_size fin : %d\n",sprites_size);
	
	printf ("nombre sprite 6: %s\n",sprite[num]->nombre);

	for (int i=0; i<sprite[num]->n;i++){
		printf("(%f;%f)\n",sprite[num]->cords[i][0], sprite[num]->cords[i][1]);
		}
	graficador_finalizar();
	return 0;
}

bool graficador_inicializar(const char *fn,SDL_Renderer *renderer){
	
	FILE *fp;
	fp=fopen(fn,"rb"); 
	if (fp==NULL)
		return false;
	
	int k=0;
	sprite = malloc(sizeof(sprite_t*)*sprites_size);//pido memoria para un numero inicial de sprites. 
	if(sprite==NULL)
		return false;

	while(!feof(fp)){
		
		if (k>sprites_size-1){
			sprite = realloc(sprite, sizeof(sprite_t*)*(sprites_size+1));
			if (sprite==NULL)
				return false;
			sprites_size +=1;
		}//si se lleno el espacio pedido al principio, pido mas memoria 

		sprite[k]=malloc(sizeof(sprite_t));

		fread(&(sprite[k]->nombre),sizeof(char),10,fp);//cargo el nombre
		fread(&(sprite[k]->n),sizeof(uint16_t),1,fp);//cargo el n
		
		sprite[k]->cords=malloc(sizeof(float*)*(sprite[k]->n*2));//pido memoria para la matriz dinamica de 2 columnas
		if(sprite[k]->cords==NULL)
			return false;

		fread(sprite[k]->cords,sizeof(float),2*sprite[k]->n,fp);//cargo la matriz
		
		k++;
	}	
	fclose(fp);

	return true;
}

bool graficador_dibujar(const char *nombre, float escala, float x, float y, float angulo){

	int i,j;

	for(i=0; i<sprites_size; i++){
		if(!strcmp(sprite[i]->nombre, nombre))
			break;
	}
	
	//cargo las coordenadas que quiero graficar rotadas en el angulo correspondiente en una nueva matriz auxiliar para no modificar los datos iniciales. 
	float **rotada;
	rotada = matriz_a_vector(sprite[i]->cords, sprite[i]->n);
	if (rotada==NULL)
		return false;
	rotar(rotada, sprite[i]->n, angulo);	
	
	for(j = 0; j < sprite[i]->n -1 ; j++){//grafico la matriz rotada, desplazada en x e y; 
		SDL_RenderDrawLine(
			renderer,
			rotada[j][0] * escala + x,
			-rotada[j][1] * escala + y,
			rotada[j+1][0] * escala + x,
			-rotada[j+1][1] * escala + y 
		);
	}	

	destruir_vector(rotada,sprite[i]->n);

	return true;
}

void graficador_finalizar() 
{
	for(int i=0; i<sprites_size; i++){
		free(sprite[i]->cords);
		free(sprite[i]);
	}
	free (sprite);
}


void graficador_ajustar_variables(float *x, float *y){

	if(*x < 0)
		*x = VENTANA_ANCHO;

    if(*x > VENTANA_ANCHO)
		*x = 0;

	if(*y < 0)
		*y = VENTANA_ALTO;

	if(*y > VENTANA_ALTO)
		*y = 0;
}