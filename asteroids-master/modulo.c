#include "modulo.h"
#include <string.h>

bool graficador_inicializar(const char *fn){
	
	FILE *fp;
	fp=fopen(fn,"rb"); 
	if (fp==NULL)
		return false;

	for(int k=0;k<MAX_SPRITES;k++){

		fread(&(sprite[k].nombre),sizeof(char),10,fp);//cargo el nombre
		fread(&(sprite[k].n),sizeof(uint16_t),1,fp);//cargo el n
		
		sprite[k].cords=malloc(sizeof(float*)*sprite[k].n*2);//pido memoria para la matriz dinamica de 2 columnas
		if(sprite[k].cords==NULL)
			return false;

		for(int j=0;j<(int)sprite[k].n;j++){
			fread(&sprite[k].cords[j],sizeof(float),2,fp);//cargo la matriz
		}
	}	
	fclose(fp);

	return true;
}


bool graficador_dibujar(SDL_Renderer *r,const char *nombre, float escala, float x, float y, float angulo){

	int i,j;

	for(i=0; i<MAX_SPRITES; i++){
		if(!strcmp(sprite[i].nombre, nombre))
			break;
	}
	
	//cargo las coordenadas que quiero graficar rotadas en el angulo correspondiente en una nueva matriz auxiliar para no modificar los datos iniciales. 
	float **rotada;
	rotada = matriz_a_vector(sprite[i].cords, sprite[i].n);
	if (rotada==NULL)
		return false;
	rotar(rotada, sprite[i].n, angulo);	
	
	for(j = 0; j < sprite[i].n -1 ; j++){//grafico la matriz rotada, desplazada en x e y; 
		SDL_RenderDrawLine(
			r,
			rotada[j][0] * escala + x,
			-rotada[j][1] * escala + y,
			rotada[j+1][0] * escala + x,
			-rotada[j+1][1] * escala + y 
		);
	}	

	destruir_vector(rotada,sprite[i].n);

	return true;
}

void graficador_finalizar() 
{
	for(int i=0; i<MAX_SPRITES; i++)
		free(sprite[i].cords);
}


