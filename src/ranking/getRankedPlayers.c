#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../types/RankedPlayer.h"

RankedPlayer* getRankedPlayers(int *n) {
  FILE *ranking = fopen("velha.ini", "r");
  *n = fgetc(ranking) - '0';

  RankedPlayer *rankedPlayers = malloc(*n * sizeof(RankedPlayer));
  fgetc(ranking);

  for(int i = 0; i < *n; i++) {
    while(!feof(ranking)) {
      char c[2];
      c[1] = '\0';
      c[0] = fgetc(ranking);

      if(c[0] != '\n') strcat(rankedPlayers[i].name, c);
      else break;
    }

    rankedPlayers[i].wins = fgetc(ranking) - '0';
    fgetc(ranking);
    rankedPlayers[i].draws = fgetc(ranking) - '0';
    fgetc(ranking);
    rankedPlayers[i].loses = fgetc(ranking) - '0';
    fgetc(ranking);
  }

  fclose(ranking);

  return rankedPlayers;
}