#include <stdio.h>
#include "../types/Player.h"

void saveGame(int **board, int turn, Player *players) {
  FILE *save = fopen("game.sav", "w");

  if(!players[1].isComputer) {
    fprintf(save, "2\n");
    fprintf(save, "%s\n%s\n", players[0].name, players[1].name);
  }
  else {
    fprintf(save, "1\n");
    fprintf(save, "%s\n", players[0].name);
  }

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      char c = '-';
      switch(board[i][j]) {
        case 1:
          c = 'X';
          break;
        case -1:
          c = 'O';
      }

      fprintf(save, "%c", c);
    }
    fprintf(save, "\n");
  }

  if(turn == 1) fprintf(save, "1");
  else fprintf(save, "2");

  fclose(save);
}