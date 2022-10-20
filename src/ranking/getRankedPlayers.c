#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../types/RankedPlayer.h"

RankedPlayer* getRankedPlayers(int *n) {
  FILE *ranking = fopen("velha.ini", "r");
  fscanf(ranking, "%d", n);

  RankedPlayer *rankedPlayers = malloc(*n * sizeof(RankedPlayer));
  fgetc(ranking);

  for(int i = 0; i < *n; i++) {
    fgets(rankedPlayers[i].name, 50, ranking);

    for(int j = 0; j < 50; j++) {
      if(rankedPlayers[i].name[j] == '\n') rankedPlayers[i].name[j] = '\0';
    }

    fscanf(ranking, "%d %d %d", &rankedPlayers[i].wins, &rankedPlayers[i].draws, &rankedPlayers[i].loses);
    fgetc(ranking);
  }

  fclose(ranking);
  return rankedPlayers;
}