typedef struct{
	int x;
	int y;
} Segmento;

typedef struct{
	Segmento *segmento;
	int tamanho;
	char direcao;
} Cobra;

Cobra* criaCobra();
Segmento* criaFruta(Cobra *cobra);
int carregarMenuJogo(int velocidade, int *pontuacao);
void desenhaCobra(Cobra *cobra);
void trocaDirecao(Cobra *cobra, char novaDirecao);
void moverCobra(Cobra *cobra);
int checarCobra(Cobra *cobra);
void desenhaFruta(Segmento *fruta);
void gerarFruta(Segmento *fruta, Cobra *cobra);
void delay(int velocidade);
void freeTudo(Cobra *cobra, Segmento *fruta);

