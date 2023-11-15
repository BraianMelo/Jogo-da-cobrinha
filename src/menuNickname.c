#include "menuNickname.h"
#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int tela;

void lerNickname(char L, char nickname[30], int *posicao){
	if(L == '-'){
		if(*posicao > 0){
			--*posicao;
			nickname[*posicao] = 0; 
		}		
		
	} else {
		if(*posicao < 30){
			nickname[*posicao] = L;
			++*posicao;
			
		}
	}
}

void carregarNicknameMenu(char v[30], int *posicao, int *tela){
	
	  while (janela_esta_aberta()) {
		  desenha_imagem(450, 320, "assets/images/menuNickname.png");
			
			fonte("assets/fonts/Qatar2022Arabic-Bold.ttf", 40); 
			desenha_texto(80, 432, v);
	
			if(tecla_acabou_de_ser_solta(GLFW_KEY_A))
				lerNickname('A', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_B))
				lerNickname('B', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_C))
				lerNickname('C', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_D))
				lerNickname('D', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_E))
				lerNickname('E', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_F))
				lerNickname('F', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_G))
				lerNickname('G', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_H))
				lerNickname('H', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_I))
				lerNickname('I', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_J))
				lerNickname('J', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_K))
				lerNickname('K', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_L))
				lerNickname('L', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_M))
				lerNickname('M', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_N))
				lerNickname('N', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_O))
				lerNickname('O', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_P))
				lerNickname('P', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_Q))
				lerNickname('Q', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_R))
				lerNickname('R', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_S))
				lerNickname('S', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_T))
				lerNickname('T', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_U))
				lerNickname('U', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_V))
				lerNickname('V', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_W))
				lerNickname('W', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_X))
				lerNickname('X', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_Y))
				lerNickname('Y', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_Z))
				lerNickname('Z', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_SPACE))
				lerNickname(' ', v, posicao);
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_ENTER)){
				v[*posicao] = '\0';
				
				toca_som("assets/musics/Click.mp3");
				
				if(*tela == 1){
					*tela = 2;
					
				} else {
					*tela = 3;
					
				}
				
				break;
			}
			
			if(tecla_acabou_de_ser_solta(GLFW_KEY_BACKSPACE))
				lerNickname('-', v, posicao);
			
	  }
	
}
