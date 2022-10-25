// @Author Caio Lucas Pereira da Silva 22.1.4006

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../utils/clear.h"
#include "startGameRoute.h"
#include "../save/loadGame.h"
#include "../ranking/showRanking.h"
#include "../utils/clearGame.h"
#include "../utils/printTitle.h"

void initialRoute() {
  // Valores iniciais
  char option;
  int **board = malloc(3 * sizeof(int*));

  for(int i = 0; i < 3; i++) {
    board[i] = (int*) calloc(3, sizeof(int));
  }
  
  int turn = 0; 
  Player players[2];
  strcpy(players[0].name, "");
  strcpy(players[1].name, "");

  // Começa o jogo num loop infinito
  while(1) {
    printTitle();

    printf("\nEscolha a opção: ");
    scanf("%c", &option);

    // Para o jogo
    if(option == '0') break;

    // Opções
    switch(option) {
      case '1':
        clear();
        clearGame(board, &turn, players);
        startGameRoute(board, &turn, players, 0);
        break;
      case '2':
        clear();
        char filename[50];

        printf("Digite o nome do arquivo: ");
        scanf("%s", filename);

        loadGame(board, &turn, players, filename);
        startGameRoute(board, &turn, players, 1);
        break;
      case '3':
        clear();
        if(!strcmp(players[0].name, "")) printf("Opção inválida!");
        else startGameRoute(board, &turn, players, 1);
        
        break;
      case '4':
        clear();
        showRanking();
        char buffer;
        
        printf("\nDigite qualquer tecla pra voltar...\n");
        scanf(" %c", &buffer);
        clear();
        break;
      default:
        clear();
        printf("Opção inválida.");
    }
  }

  // Limpa as alocações 
  for(int i = 0; i < 3; i++) free(board[i]);
  free(board); 
}