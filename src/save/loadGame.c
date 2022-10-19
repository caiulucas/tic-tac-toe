#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../types/Player.h"

void loadGame(int **board, int *turn, Player *players, char *filename) {
  FILE *save = fopen(filename, "r");
  char playersCount = fgetc(save);
  fgetc(save);
  strcpy(players[0].name, "");
  strcpy(players[1].name, "");

  players[0].isComputer = 0;
  fgets(players[0].name, 50, save);
  for(int i = 0; i < 50; i++) {
    if(players[0].name[i] == '\n') players[0].name[i] = '\0';
  }

  if(playersCount == '2') {
    players[1].isComputer = 0;

    fgets(players[1].name, 50, save);
    for(int i = 0; i < 50; i++) {
      if(players[1].name[i] == '\n') players[1].name[i] = '\0';
    }
  } else players[1].isComputer = 1;

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      char c = fgetc(save);

      switch(c) {
        case '-':
          board[i][j] = 0;
          break;
        case 'X':
          board[i][j] = 1;
          break;
        case 'O':
          board[i][j] = -1;
      }
    }
  }

  char turnChar = fgetc(save);
  if(turnChar == '1') *turn = 1;
  else *turn = 0;

  fclose(save);
}