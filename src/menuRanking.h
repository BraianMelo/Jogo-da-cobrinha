typedef struct{
	char nickname[30];
	int pontuacao;
} Jogador; 

int carregarMenuRanking();
Jogador *criaJogador();
void adicionarJogador(char nickname[30], int pontuacao, int dificuldade);
void escreverRanking(Jogador *jogador);
Jogador *lerArquivo();
void freeJogador(Jogador *jogador);
