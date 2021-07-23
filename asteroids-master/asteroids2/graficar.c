#include "graficador.h"
#include "herramientas.h"
#include "graficar.h"
#include "config.h"

#define COLUMNA_1 150
#define COLUMNA_2 470
#define Y_GAMEOVER 200
#define X_GAMEOVER 270

void dibujar_letra (const int (*vect_dir)[2],int n_dic,float desplazamiento,float posicion_y,float escala){
	int i;

	for( i = 0; i < n_dic-1 ; i++){

		SDL_RenderDrawLine(
			renderer,
			vect_dir[i][0]*escala + desplazamiento,
			-vect_dir[i][1]*escala + posicion_y,
			vect_dir[i+1][0]*escala + desplazamiento,
			-vect_dir[i+1][1]*escala + posicion_y);
	}
}

//funcion que dibuja la string que se le cargue en una posicion x= desplazamiento y una posicion en y especificadas 
void dibujar_string(char string[MAX_STRING],const caracteres_t dicc[CANT_CARACTERES],size_t n_string,float desplazamiento,float posicion_y,float escala){
	int j;
	int i;

	for( i=0;i<n_string;i++){

		for( j=0;string[i]!=dicc[j].caracter;j++){
		}

		dibujar_letra(dicc[j].vect_dir,dicc[j].longitud,desplazamiento,posicion_y,escala);

		desplazamiento+=escala*CARACTER_ANCHO; 
	}

}

//funcion que imprime los datos que recibe por pantalla junto con sus respectivas etiquetas
void datos_en_pantalla(int score,int best_score, int vida_nave){

	size_t n_string;
	char string[MAX_STRING] ;
	float desplazamiento;
	float posicion_y;
	float escala;
	int i;
	
	posicion_y=30;//renglon 1

	//score
	n_string = (sprintf(string,"%03i",best_score));
	desplazamiento=COLUMNA_1;
	escala=3;
	dibujar_string(string,DICCIONARIO,n_string,desplazamiento,posicion_y,escala);

	posicion_y+=30;//renglon 2

	desplazamiento=COLUMNA_1;
	escala=1;
	sprintf(string,"%s","SHIP");
	for(i=0;i<vida_nave;i++){
		graficador_dibujar(string, escala, desplazamiento, posicion_y,NAVE_ANGULO_INICIAL);
		desplazamiento+=20;
	}
	
	n_string = (sprintf(string,"%02i",score));
	desplazamiento=COLUMNA_2;
	escala=2;
	posicion_y = 40;
	dibujar_string(string,DICCIONARIO,n_string,desplazamiento,posicion_y,escala);
		
	

}

void mensajes_finde_partida(int score){

	size_t n_string;
	char string [MAX_STRING];
	float desplazamiento;
	float posicion_y;
	float escala = 9;
	
	posicion_y = Y_GAMEOVER;
	desplazamiento = X_GAMEOVER;

	n_string = (sprintf(string,"%s","game over"));
	dibujar_string(string,DICCIONARIO,n_string,desplazamiento,posicion_y,escala);

	posicion_y += 50;
	escala = 5;
	desplazamiento += 15;

	n_string = (sprintf(string,"%s","final score "));
	dibujar_string(string,DICCIONARIO,n_string,desplazamiento,posicion_y,escala);

	desplazamiento += 320;

	n_string = (sprintf(string,"%03i",score));
	dibujar_string(string,DICCIONARIO,n_string,desplazamiento,posicion_y,escala);
	
}

void mensaje_iniciode_partida(void){
	size_t n_string;
	char string [MAX_STRING];
	float desplazamiento=X_GAMEOVER;
	float posicion_y=650;
	float escala = 4;

	n_string = (sprintf(string,"%s","press space to start"));
	dibujar_string(string,DICCIONARIO,n_string,desplazamiento,posicion_y,escala);
}