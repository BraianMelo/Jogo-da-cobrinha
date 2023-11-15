#include "menuDificuldade.h"
#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int carregarMenuDificuldade(int *dificuldade){
	
	while(janela_esta_aberta()){
	
		desenha_imagem(450, 320, "assets/images/menuDificuldade.png");
	
		
		if(botao_mouse_acabou_de_ser_solto(BOTAO_ESQUERDO)){
						
			if((mouse_y > 295) && (mouse_y < 435)){
							
				if((mouse_x > 30) && (mouse_x < 280)){
					*dificuldade = 700;
					
				}
								
				if((mouse_x > 325) && (mouse_x < 575)){
					*dificuldade = 500;
					
				}
								
				if((mouse_x > 620) && (mouse_x < 870)){
					*dificuldade = 300;
					
				}
				
				toca_som("assets/musics/Click.mp3");
				return 3;
								
			}

		}
		
		if(tecla_acabou_de_ser_solta(GLFW_KEY_F1)){
			*dificuldade = 700;
			toca_som("assets/musics/Click.mp3");
			return 3;
		}
		if(tecla_acabou_de_ser_solta(GLFW_KEY_F2)){
			*dificuldade = 500;
			toca_som("assets/musics/Click.mp3");
			return 3;
		}
		if(tecla_acabou_de_ser_solta(GLFW_KEY_F3)){
			*dificuldade = 300;
			toca_som("assets/musics/Click.mp3");
			return 3;
		}
	}
}
