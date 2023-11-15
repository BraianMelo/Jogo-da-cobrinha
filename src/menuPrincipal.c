#include "menuPrincipal.h"
#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int carregarMenuPrincipal(){
	
	while(janela_esta_aberta()){
		
		desenha_imagem(450, 320, "assets/images/menuPrincipal.png");
	
		if(botao_mouse_acabou_de_ser_solto(BOTAO_ESQUERDO)){
			
			if((mouse_y > 470) && (mouse_y < 610)){
				
				if((mouse_x > 30) && (mouse_x < 280)){
					toca_som("assets/musics/Click.mp3");
					return 2;
					
				}
								
				if((mouse_x > 325) && (mouse_x < 575)){
					toca_som("assets/musics/Click.mp3");
					return -1;
					
				}
								
				if((mouse_x > 620) && (mouse_x < 870)){
					toca_som("assets/musics/Click.mp3");
					return 4;
					
				}
				
			} 
			
			if((mouse_y > 75) && (mouse_y < 435)){
				if((mouse_x > 34) && (mouse_x < 865)){
					toca_som("assets/musics/Click.mp3");
					return 5;
					
				}
			}
			
		}
		
		if(tecla_acabou_de_ser_solta(GLFW_KEY_F1)){
			toca_som("assets/musics/Click.mp3");
			return 2;
		}
		
		if(tecla_acabou_de_ser_solta(GLFW_KEY_F2)){
			toca_som("assets/musics/Click.mp3");
			return -1;
		}
		
		if(tecla_acabou_de_ser_solta(GLFW_KEY_F3)){
			toca_som("assets/musics/Click.mp3");
			return 4;
		}
		
		if(tecla_acabou_de_ser_solta(GLFW_KEY_ENTER)){
			toca_som("assets/musics/Click.mp3");
			return 5;
		}
	}
}
