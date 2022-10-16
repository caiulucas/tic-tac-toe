#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../utils/clear.h"
#include "../types/Player.h"
#include "fillBoard.h"
#include "printBoard.h"
#include "verifyWin.h"
#include "minimax.h"
#include "saveGame.h"
#define STR_SIZE 50

int startGame(int board[3][3], int *turn, Player players[2]) { 
  char winner = ' ';

  while(1) {
    if(!players[*turn].isComputer) {
      char command[30];
      int pos = 0;
      printf("%s, digite o comando: ", players[*turn].name);
      scanf("%s", command);

      if(!strcmp(command, "marcar")) scanf("%d", &pos);
      else if(!strcmp(command, "salvar")) {
        saveGame(board, *turn, players);
        break;
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
      bestPlay(board);
      winner = verifyWin(board);
      *turn = !*turn;
    }

    printBoard(board);
    if(winner != ' ') break;
  }

  if(winner == 'x') return 1;
  if(winner == 'o') return -1;
  return 0;
}