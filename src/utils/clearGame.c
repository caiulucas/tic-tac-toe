// @Author Caio Lucas Pereira da Silva 22.1.4006

#include <string.h>
#include "../types/Player.h"

void clearGame(int **board, int *turn, Player *players) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      board[i][j] = 0;
    }
  }

  *turn = 0;
  strcpy(players[0].name, "");
  strcpy(players[1].name, "");
}