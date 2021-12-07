#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ( ){
	int i, j, linha, coluna, contador;
	char matriz[3][3];

	setlocale(LC_ALL,"portuguese");

	for(i = 0; i < 3; i++){ //estrutura
		printf("\n");
		for(j = 0; j < 3; j++){
			printf("\t");
			matriz[i][j] = '.';
			printf("%c", matriz[i][j]);
		}
		printf("\n");
		printf("\n");
	}

	for (contador = 0; contador < 9; contador++){

		printf("\nEscolha a LINHA onde ficará seu símbolo:\n");
		scanf("%d", &linha);
		linha--;

		printf("Escolha a COLUNA onde ficará seu símbolo:\n");
		scanf("%d", &coluna);
		coluna--;


		printf("\n");
		if(matriz[linha][coluna] == '.'){

			if(contador%2){
				matriz[linha][coluna] = 'O';
			}
			else{
				matriz[linha][coluna] = 'X';
			}

			for(i = 0; i < 3; i++){    //apresentar o símbolo do jogador no espaço escolhido.
				printf("\n");
				for(j = 0; j < 3; j++){
					printf("\t");
					printf("%c", matriz[i][j]);
				}
				printf("\n");
				printf("\n");
			}

			if((matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2] && matriz[0][0] != '.')||
			   (matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2] && matriz[0][0] != '.')||
			   (matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0] && matriz[0][0] != '.')||
			   (matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1] && matriz[0][1] != '.')||
			   (matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2] && matriz[0][2] != '.')||
			   (matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2] && matriz[1][0] != '.')||
			   (matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2] && matriz[2][0] != '.')||
			   (matriz[2][0] == matriz[1][1] && matriz[2][0] == matriz[0][2] && matriz[2][0] != '.')){

				printf("\nJogador %d ganhou!", (contador%2) + 1);
				exit(0);
			}
		}
		else{
			printf("\nAQUI NÃO! Esse espaço já foi escolhido, viu. Escolha outro!\n");
			contador--;
		}
	}

	printf("\nQue chato! Ninguém ganhou :(");
	exit(0);
}
