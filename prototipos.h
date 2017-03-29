#define TAM 3

void menu();
void jogar();
int calculaJogador();
void zeraTabuleiro(int tabuleiro[][TAM]);
void imprimeTabuleiro(int tabuleiro[][TAM]);
void jogada(int tabuleiro[][TAM], int vez, int rodada);
int verificaTabuleiro(int tabuleiro[][TAM], int linha, int coluna);
void marcarJogada(int tabuleiro[][TAM], int linha, int coluna, int vez);
int verificaEmpate(int tabuleiro[][TAM]);
int verificaVencedor(int tabuleiro[][TAM]);

