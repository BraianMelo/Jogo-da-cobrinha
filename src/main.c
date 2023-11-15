#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "menuNickname.h"
#include "menuDificuldade.h"
#include "menuPrincipal.h" 
#include "menuJogo.h"
#include "menuRanking.h"

char nickname[30]; int posicao = 0; int tela = 1; int pontuacao = 0;

int main() {
	
	int dificuldade;

    abre_janela(900, 640);
    toca_som_em_loop("assets/musics/mixMusicas.mp3");

    while (janela_esta_aberta()) {
		
		switch(tela){
			case 1:
				carregarNicknameMenu(nickname, &posicao, &tela);
				break;
				
			case 2: 
				tela = carregarMenuDificuldade(&dificuldade);
				break;
				
			case 3:
				tela = carregarMenuPrincipal();
				break;
				
			case 4:
				tela = carregarMenuRanking();
				break;
				
			case 5: 
				pontuacao = 0;
				tela = carregarMenuJogo(dificuldade, &pontuacao);
				adicionarJogador(nickname, pontuacao, dificuldade);
				break;
				
			default:
				carregarNicknameMenu(nickname, &posicao, &tela);
				
		}
		
	}
	
    fecha_janela();

}
