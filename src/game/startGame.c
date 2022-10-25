#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../utils/clear.h"
#include "../types/Player.h"
#include "fillBoard.h"
#include "printBoard.h"
#include "verifyWin.h"
#include "minimax.h"
#include "../save/saveGame.h"
#define STR_SIZE 50

char startGame(int **board, int *turn, Player *players) { 
  char winner = ' ';

  // Loop de uma partida em si
  while(1) {
    printBoard(board);

    // Verifica se o jogador é computador
    if(!players[*turn].isComputer) {
      char command[6];
      int pos = 0;

      // Lê o comando digitado
      printf("%s, digite o comando: ", players[*turn].name);
      scanf("%s", command);

      if(!strcmp(command, "marcar")) scanf("%d", &pos);
      else if(!strcmp(command, "salvar")) {
        char filename[STR_SIZE];
        scanf("%s", filename);
        saveGame(board, *turn, players, filename);
        continue;
      }else if(!strcmp(command, "voltar")) break;
      else {
        clear();
        printf("Comando inválido!\n");
        continue;
      }

      if(!pos) continue;

      int xPos = pos / 10 - 1;
      int yPos = pos % 10 - 1;
      
      int play = *turn ? -1 : 1; // Se turn = 0, jogada = 1 (X), se não, jogada = -1 (O)
      int hasFilled = fillBoard(board, play, xPos, yPos);

      // Verifica se a posição é ou não válida
      if(hasFilled == -1) {
        clear();
        printf("Jogada inválida!\n");
        continue;
      } 

      if(!hasFilled) {
        clear();
        printf("Posição já ocupada!\n");
        continue;
      }

      if(hasFilled) {
        *turn = !*turn;
        winner = verifyWin(board);
      }  
    } else {
      // Jogada da I.A.
      bestPlay(board);
      winner = verifyWin(board);
      *turn = !*turn;
    }

    // Termina partida
    if(winner != ' ') break;
  }

  return winner;
}