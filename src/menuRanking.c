#include "menuRanking.h"
#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


Jogador *criaJogador(){
	Jogador *jogador = (Jogador*)malloc(5*sizeof(Jogador));
	return jogador;
}

void adicionarJogador(char nickname[30], int pontuacao, int dificuldade){
	
	if(dificuldade == 700){
		pontuacao /= 3;
	}
	if(dificuldade == 500){
		pontuacao /= 2;
	}


	Jogador *jogador = lerArquivo();
	
	
	int trocou = 0;

	if(pontuacao > jogador[4].pontuacao){
		++trocou;
		
		int i;
		for(i = 0; i < 5; ++i){
			if(pontuacao > jogador[i].pontuacao){
				break;
			}
		}
		
		int guardaPontuacao;
		char guardaNickname[30];
		
		for(int c = 4; c >= i; --c){
			if(c == i){
				jogador[c].pontuacao = pontuacao;
				strcpy(jogador[c].nickname, nickname);
				
			} else {
				jogador[c].pontuacao = jogador[c-1].pontuacao;
				strcpy(jogador[c].nickname, jogador[c-1].nickname);
				
			}
			
		}
		
	}
	
	if(trocou){	
		escreverRanking(jogador);
		
	}
	freeJogador(jogador);

}

void escreverRanking(Jogador *jogador){
	FILE *arquivo;
	arquivo = fopen("assets/ranking.txt", "w");
	
	if(arquivo == NULL){
		exit(1);
	} 
	
	for(int i = 0; i < 5; ++i){
		fputs(jogador[i].nickname, arquivo);
		fputc(',', arquivo);
		
		char pontuacaoVetor[5];
		sprintf(pontuacaoVetor, "%d", jogador[i].pontuacao);

		fputs(pontuacaoVetor, arquivo);
		fputc('\n', arquivo);
	}
	
	fclose(arquivo);
}


Jogador *lerArquivo(){
	FILE *arquivo;
	arquivo = fopen("assets/ranking.txt", "r");
	if(arquivo == NULL){
		exit(1);
	} 
	
	Jogador *jogador = criaJogador();
	char linha[37];
	
	fgets(linha, 37, arquivo);
	
	int i = 0;

	while(!feof(arquivo)){
		strcpy(jogador[i].nickname, strtok(linha, ","));
		jogador[i].pontuacao = atoi(strtok(NULL, ","));
		
		++i;
		fgets(linha, 37, arquivo);
	}
	
	fclose(arquivo);

	return jogador;
	
}

void freeJogador(Jogador *jogador){
	free(jogador);
}


int carregarMenuRanking(){

	 Jogador* jogador = lerArquivo();
	
	 fonte("assets/fonts/Qatar2022Arabic-Bold.ttf", 60);
	
	 while (janela_esta_aberta()) {
		  desenha_imagem(450, 320, "assets/images/menuRanking.png");
		  char linha[100], numero[5];
		  
		  for(int i = 0; i < 5; ++i){
			  if(jogador[i].pontuacao != 0){
				  
				  sprintf(linha, "%d", i+1);
				  strcat(linha, ". ");
				  
				  strcat(linha, jogador[i].nickname);
				  strcat(linha, " - ");
				  
				  sprintf(numero, "%d", jogador[i].pontuacao);
				  
				  strcat(linha, numero);
				  
				  desenha_texto(200, 350 + (i*60), linha);
				  
				  
			  }
		  }
		  
		  if( (tecla_acabou_de_ser_solta(GLFW_KEY_ENTER)) || (botao_mouse_acabou_de_ser_solto(BOTAO_ESQUERDO)) ){
			  toca_som("assets/musics/Click.mp3");
			  freeJogador(jogador);
			  return 3;
		  }
		  
		  if(tecla_acabou_de_ser_solta(ESPACO)){
			  toca_som("assets/musics/Click.mp3");
			  freeJogador(jogador);
			  return 5;
		  }
	}
	

}
