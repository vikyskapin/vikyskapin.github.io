#include "herramientas.h"
#include "modulo.h"
#include "nave.h"
#include "disparos.h"
#include "asteroides.h"

int main(void) {
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;

	SDL_CreateWindowAndRenderer(VENTANA_ANCHO, VENTANA_ALTO, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "Asteroids");

	int dormir = 0;

	// BEGIN código del alumno
	
	srand(time(NULL));
	graficador_inicializar("sprites.bin");

	int flag = 0;
	int score = 0;
	int best_score = 0;
	int cantidad_asteroides = CANT_INICIAL_ASTEROIDES;
	int vidas_nave = NAVE_VIDAS_INICIALES;

	
	lista_t *l_shot = lista_crear();
	lista_t *l_rock = lista_crear();
	nave_t nave = nave_crear();
	
	if(crear_asteroides_iniciales(cantidad_asteroides, l_rock));
	
	//nave_t nave = nave_crear();
	//funcion que se llama cuando hay que crear asteroides de 0

	// END código del alumno

	unsigned int ticks = SDL_GetTicks();
	while(1) {
		if(SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				break;
	    		if (event.type == SDL_KEYDOWN) {
				// BEGIN código del alumno
				switch(event.key.keysym.sym) 
				{
					case SDLK_UP:
						if(nave.potencia < NAVE_POTENCIA_PASO)
							nave.potencia += NAVE_POTENCIA_PASO;
						break;

					case SDLK_SPACE:
						if (!flag)
							flag=1;
						
						else if(nave.vida)
							if(cargar_disparos(
								l_shot,nave.posicion_x,
								nave.posicion_y,
								nave.angulo_rotacion));
						break;

					case SDLK_RIGHT:	
							(nave.angulo_rotacion) -= NAVE_ROTACION_PASO;
						break;
					
					case SDLK_LEFT:
							(nave.angulo_rotacion) += NAVE_ROTACION_PASO;
						break;
				}
				// END código del alumno
			}
			continue;
		}
        	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        	SDL_RenderClear(renderer);
        	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);


		// BEGIN código del alumno
		
		if(flag){

			lista_asteroide_choco(l_rock,&nave,l_shot,&score);

			nave_mover(&nave, DT, nave.potencia);
			mover_lista_disparos(l_shot,DT);
			mover_lista_asteroides(l_rock,DT);

			datos_en_pantalla(renderer,score,best_score,vidas_nave);


			if(!nave.vida){
				if(revivir_nave(l_rock,&nave,&vidas_nave))
					dormir = 1000;
				else
					dormir = DT;

				if(!vidas_nave){//caso que no queden mas vidas
					best_score = bestscore(best_score,score);
					dormir = 3000;
					mensajes_finde_partida(renderer,score);
					vidas_nave = NAVE_VIDAS_INICIALES;
					nave.vida=vidas_nave;
					score = 0;
					flag = 0;
				}
			}
		}
		if(!flag){
			mensaje_iniciode_partida(renderer);
		}
	
		//verifico si quedan asteroides 
		if(lista_es_vacia(l_rock)){
			cantidad_asteroides+=CANT_EXTRA_ASTEROIDES;
			if(crear_asteroides_iniciales(cantidad_asteroides, l_rock));
		}

		if(dibujar_lista_asteroides(l_rock,renderer))
			;//dibujo cada elemento de la lista
		if(dibujar_lista_disparos(l_shot,renderer))
			;
		if(nave.vida)
			if((nave_dibujar(&nave, renderer))==false)
				break;
		

		
		// END código del alumno


        SDL_RenderPresent(renderer);
		ticks = SDL_GetTicks() - ticks;
		if(dormir) {
			SDL_Delay(dormir);
			dormir = 0;
		}
		else if(ticks < 1000 / JUEGO_FPS)
			SDL_Delay(1000 / JUEGO_FPS - ticks);
		ticks = SDL_GetTicks();
	}

	// BEGIN código del alumno
	lista_destruir(l_rock,asteroide_destruir);
	lista_destruir(l_shot,disparo_destruir);
	graficador_finalizar();
	// END código del alumno

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}