#include "prototipos.h"

void menu() {
	int opcao;

	do{
		system("cls");
		puts("\t\t----------------------------");
		puts("\t\t\t===MENU===");
		puts("\t\t----------------------------\n");
		puts("\t\t\t0 >> Sair");
		puts("\t\t\t1 >> Jogar\n");
		printf("\t\t     Escolha uma opção\n");
		printf("\t\t\t >> ");
		scanf("%d", &opcao);

		if (opcao == 1)
			jogar();
		else
			if (opcao != 0 ) {
				puts("\n\t      --------------------------------");
				puts("\t      Opção Inválida, tente novamente.");
				puts("\t      --------------------------------\n");
				system("pause");
			}
	} while(opcao != 0);

	puts("\n\t     ------------------------------------");
	printf("\t       O programa está sendo encerrrado\n");
	puts("\t     ------------------------------------\n");

}

int calculaJogador() {
	static int vez = 0;

	if (vez%2 == 0){
		vez++;
		return 1;
	}
	else{
		vez++;
		return 2;
	}
}

void zeraTabuleiro(int tabuleiro[][TAM]) {
	int linha;
	int coluna;

	for (linha = 0; linha < TAM; linha ++)
	for (coluna = 0; coluna < TAM; coluna++)
		tabuleiro[linha][coluna] = 0;
}

void imprimeTabuleiro(int tabuleiro[][TAM]) {
	int linha;
	int coluna;

	for(linha = 0; linha < TAM; linha++) {
        printf("\t\t         ");
        for(coluna = 0; coluna < TAM; coluna++) {
            if(tabuleiro[linha][coluna] == 0)
                printf("   ");
            else
                if(tabuleiro[linha][coluna] == 1)
                    printf(" X ");
                else
                    if (tabuleiro[linha][coluna] == -1)
                    printf(" O ");

            if(coluna < (TAM-1))
                printf("|");
        }
        if (linha < TAM-1){
			putchar('\n');
			printf("\t\t         -----------");
			putchar('\n');
        }
    }
    putchar('\n');
}

int verificaEmpate(int tabuleiro[][TAM]) {
	int i, j;

	for (i = 0; i < TAM; i++)
        for (j = 0; j < TAM; j++)
			if (tabuleiro[i][j] == 0)   // se for igual a 0 quer dizer que ainda há jogadas a serem feitas
				return 0;
	return 1;
}

int verificaVencedor(int tabuleiro[][TAM]) {
    int i, j;
    int somal = 0;
    int somac = 0;
    int somadp = 0;
    int somads = 0;
    int empate; // soma linha, coluna, diagonal principal e secundária

    for (i = 0; i < TAM; i++){                        // verifica vencedor pela linha e coluna
        for (j = 0; j < TAM; j++){
            somal += tabuleiro[i][j];
            somac += tabuleiro[j][i];
        }
        if (somal == TAM || somal == (-1)*TAM || somac == TAM || somac == (-1)*TAM)
            return 1;
        somal = 0;
        somac = 0;
    }

    for (i = 0, j = 0; i< TAM; i++, j++)     // verifica diagonal principal
		somadp += tabuleiro[i][j];

	if (somadp == TAM || somadp == (-1)*TAM)
		return 1;
    somadp = 0;

    for (i = 0, j = TAM-1; i<TAM; i++, j--)                        // verifica diagonal secundaria
		somads += tabuleiro[i][j];

	if (somads == TAM || somads == (-1)*TAM)
		return 1;
	somads = 0;

	empate = verificaEmpate(tabuleiro);
		if (empate == 1) // verifica empate
			return 2;
	return 0;
}

void jogar() {
	int vez = 0;
	int vencedor = 0;
    int rodada = 1;
	int tabuleiro[TAM][TAM];

    zeraTabuleiro(tabuleiro);

	do {
        system("cls");
        vez = calculaJogador();
        jogada(tabuleiro, vez, rodada);
		rodada++;
        system("cls");
        vencedor = verificaVencedor(tabuleiro);
	}while(vencedor == 0);

	puts("\t\t------------------------------");
	printf("\t\t         ===ACABOU===        \n");
	puts("\t\t------------------------------\n");
    imprimeTabuleiro(tabuleiro);
	if (vencedor == 1){
		  puts("\t\t------------------------------");
		printf("\t\t      O jogador %d venceu\n", vez);
		  puts("\t\t------------------------------\n");
	}
	else if (vencedor == 2){
		puts("\t\t------------------------------");
		printf("\t\tEmpate, nenhum jogador venceu.\n");
		puts("\t\t------------------------------\n");
	}
	system("pause");
	vez = 0;
	rodada = 1;
}

int verificaTabuleiro(int tabuleiro[][TAM], int linha, int coluna) {
	if (linha < 0 || linha > TAM-1 || coluna < 0 || coluna > TAM-1 || tabuleiro[linha][coluna] != 0)
		return 0;
	else
		return 1;
}

void marcarJogada(int tabuleiro[][TAM], int linha, int coluna, int vez) {
	if (vez == 1)
		tabuleiro[linha][coluna] = 1;
	else
		tabuleiro[linha][coluna] = -1;
}

void jogada(int tabuleiro[][TAM], int vez, int rodada) {
	int linha;
	int coluna;
	int livre;

	do {
		puts("\t\t------------------------------");
		printf("\t\t        ===RODADA %d===\n", rodada);
        printf("\t\t        ===PLAYER %d===\n", vez);
		puts("\t\t------------------------------\n");
        imprimeTabuleiro(tabuleiro);
		puts("\n\t\t------------------------------\n");
		printf("\t\t       Informe a linha\n");
		printf("\t\t\t   >> ");
		scanf("%d", &linha);
		linha--;
		printf("\t\t       Informe a coluna\n");
		printf("\t\t\t   >> ");
		scanf("%d", &coluna);
		coluna--;
		livre = verificaTabuleiro(tabuleiro, linha, coluna);
		if(livre == 0){
			puts("\n\t       ---------------------------------");
			puts("\t       Jogada Inválida. Tente novamente.");
			puts("\t       ---------------------------------\n");
			system("pause");
			system("cls");
		}
	} while(livre == 0);
	marcarJogada(tabuleiro, linha, coluna, vez);
}
