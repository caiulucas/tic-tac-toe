#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../types/Player.h"

void loadGame(int **board, int *turn, Player *players) {
  FILE *save = fopen("game.sav", "r");
  char playersCount = fgetc(save);
  fgetc(save);
  strcpy(players[0].name, "");
  strcpy(players[1].name, "");

  players[0].isComputer = 0;
  while(!feof(save)) {
    char c[2];
    c[1] = '\0';
    c[0] = fgetc(save);
    if(c[0] != '\n') strcat(players[0].name, c);
    else break;
  }

  if(playersCount == '2') {
    players[1].isComputer = 0;
    while(!feof(save)) {
      char c[2];
      c[1] = '\0';
      c[0] = fgetc(save);
      if(c[0] != '\n') strcat(players[1].name, c);
      else break;
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