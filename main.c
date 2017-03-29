#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "prototipos.h"

int main(char argc, char* argv[]){
	setlocale(LC_ALL, "Portuguese");
	char a;
	do{
		puts("\t\t==BEM VINDO AO JOGO DA VELHA==\n\n");
		printf("\t\tPressione ENTER para continuar");
		a = getchar();
	}while(a != '\n');

	menu();

    return 0;
}
