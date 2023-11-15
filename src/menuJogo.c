#include "menuJogo.h"
#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define tamanhoMaximo 30


Cobra* criaCobra(){
	Cobra *cobra = (Cobra*)malloc(sizeof(Cobra));
	cobra->segmento = (Segmento*)malloc(tamanhoMaximo*sizeof(Segmento));
	
	cobra->segmento[0].x = 450;
	cobra->segmento[0].y = 355;
	
	cobra->segmento[1].x = 398;
	cobra->segmento[1].y = 355;
	
	cobra->segmento[2].x = 346;
	cobra->segmento[2].y = 355;
	
	cobra->tamanho = 3;
	cobra->direcao = 'D';
	
	return cobra;
}

Segmento* criaFruta(Cobra *cobra){
	Segmento *fruta = (Segmento*)malloc(sizeof(Segmento));
	gerarFruta(fruta, cobra);
	return fruta;
}

void desenhaCobra(Cobra *cobra){
	char caminho[100];
	
	switch(cobra->direcao){
		case 'D':
			strcpy(caminho, "assets/images/cabecaDireita.png");
			break;
				
		case 'E':
			strcpy(caminho, "assets/images/cabecaEsquerda.png");
			break;
				
		case 'C':
			strcpy(caminho, "assets/images/cabecaCima.png");
			break;
					
		case 'B':
			strcpy(caminho, "assets/images/cabecaBaixo.png");
			break;
		
	}
	
	desenha_imagem(cobra->segmento[0].x, cobra->segmento[0].y, caminho);

	for(int c = 1; c < cobra->tamanho; ++c){
		desenha_imagem(cobra->segmento[c].x, cobra->segmento[c].y, "assets/images/corpo.png");
		
	}
}

void trocaDirecao(Cobra *cobra, char novaDirecao){
	
	if(novaDirecao != cobra->direcao){
		switch(novaDirecao){
		case 'D':
			if(cobra->direcao != 'E'){
				cobra->direcao = novaDirecao;
			}
			break;
			
		case 'E':
			if(cobra->direcao != 'D'){
				cobra->direcao = novaDirecao;
			}
			break;
			
		case 'C':
			if(cobra->direcao != 'B'){
				cobra->direcao = novaDirecao;
			}
			break;
			
		case 'B':
			if(cobra->direcao != 'C'){
				cobra->direcao = novaDirecao;
			}
			break;
		}
		
	}
}

void moverCobra(Cobra *cobra){
	int x1 = 0,x2 = 0;
	int y1 = 0,y2 = 0;
	
	x1 = cobra->segmento[0].x;
	y1 = cobra->segmento[0].y;
	
	switch(cobra->direcao){
			
			case 'D':
				cobra->segmento[0].x += 52;
				break;
			
			case 'E':
				cobra->segmento[0].x -= 52;
				break;
			
			case 'C':
				cobra->segmento[0].y -= 43;
				break;
				
			case 'B':
				cobra->segmento[0].y += 43;
				break;
		}
	
	for(int c = 1; c < cobra->tamanho; ++c){
		if(c % 2 == 1){
			x2 = cobra->segmento[c].x;
			y2 = cobra->segmento[c].y;
		
			cobra->segmento[c].x = x1;
			cobra->segmento[c].y = y1;
			
		} else {
			x1 = cobra->segmento[c].x;
			y1 = cobra->segmento[c].y;
		
			cobra->segmento[c].x = x2;
			cobra->segmento[c].y = y2;
			
		}
		
	}
}

int checarCobra(Cobra *cobra){
	int x = cobra->segmento[0].x;
	int y = cobra->segmento[0].y;
	
	if( ((y < 200) || (y > 510)) || ((x < 50) || (x > 850)) ){
		return 1;
		
	}
	
	for(int c = 1; c < cobra->tamanho; ++c){
		if((x == cobra->segmento[c].x) && (y == cobra->segmento[c].y)){
			return 1;
			
		}
	}
	
	return 0;
	
}

void desenhaFruta(Segmento *fruta){
	desenha_imagem(fruta->x, fruta->y, "assets/images/bola.png");
	
}

void gerarFruta(Segmento *fruta, Cobra *cobra){
	int pontoValido = 1;
	
	while(pontoValido){
		fruta->x = 86 + (52 * (rand() % 14));
		fruta->y = 226 + (43 * (rand() % 6));

		for(int i = 0; i < cobra->tamanho; ++i){
			if( (cobra->segmento[i].x == fruta->x) && (cobra->segmento[i].y == fruta->y) ){
				break;
			}
			
			if(i == cobra->tamanho - 1){
				pontoValido = 0;
			}
		}
	}
	
}

void delay(int velocidade){
	int milisegundos = 1000 * velocidade;
	clock_t tempoInicial = clock();
	while(clock() < tempoInicial + milisegundos);
	
}

void freeTudo(Cobra *cobra, Segmento *fruta){
	free(cobra->segmento);
	free(cobra);
	free(fruta);
	
}

int carregarMenuJogo(int velocidade, int *pontuacao){
	desenha_imagem(450, 320, "assets/images/menuJogo.png");
	fonte("assets/fonts/Qatar2022Arabic-Bold.ttf", 60);
	
	toca_som_em_loop("assets/musics/Torcida.mp3");
	
	Cobra *cobra = criaCobra();
	Segmento *fruta = criaFruta(cobra);
	
	char pontuacaoVetor[5];
	
	int fimDeJogo = 0;
		  
	 while (janela_esta_aberta()) {

		desenha_imagem(450, 320, "assets/images/menuJogo.png");
		
		if( (cobra->segmento[0].x == fruta->x) && (cobra->segmento[0].y == fruta->y) ){
			++cobra->tamanho;
						
			if(cobra->tamanho == 30){
				break;
				
			}
						
			gerarFruta(fruta, cobra);
			*pontuacao += 100;
			
			toca_som("assets/musics/cobraComendo.mp3");
			
		}
		
		sprintf(pontuacaoVetor, "%d", *pontuacao);
		desenha_texto(715, 615, pontuacaoVetor);
			
		delay(velocidade);
			
		if(	tecla_acabou_de_ser_apertada(CIMA)){
			trocaDirecao(cobra, 'C');
		}
		if(tecla_acabou_de_ser_apertada(BAIXO)){
			trocaDirecao(cobra, 'B');
		}
		if(tecla_acabou_de_ser_apertada(ESQUERDA)){
			trocaDirecao(cobra, 'E');
		}
		if(tecla_acabou_de_ser_apertada(DIREITA)){
			trocaDirecao(cobra, 'D');
		}

		desenhaFruta(fruta);
			
		moverCobra(cobra);
			
		fimDeJogo = checarCobra(cobra);
			
		if(fimDeJogo){
			break;
				
		} else {
			desenhaCobra(cobra);	
				
		}
				
				
	}

	toca_som("assets/musics/TorcidaDesapontada.mp3");
	
	while (janela_esta_aberta()) {
		desenha_imagem(450, 320, "assets/images/menuMorte.png");
		
		if(tecla_acabou_de_ser_solta(GLFW_KEY_ENTER) || (botao_mouse_acabou_de_ser_solto(BOTAO_ESQUERDO)) ){
			toca_som("assets/musics/Click.mp3");
			break;
		}
	}
	
	freeTudo(cobra, fruta);
	return 3;
		

				
}

