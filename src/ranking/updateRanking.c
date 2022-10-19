#include <stdio.h>
#include "getRankedPlayers.h"

void updateRanking(RankedPlayer *rankedPlayers, int n) {
  remove("velha.ini");
  FILE *ranking = fopen("velha.ini", "w");
  fprintf(ranking, "%d\n", n);

  for(int i = 0; i < n; i++) {
    RankedPlayer aux;

    for(int j = 1; j < n; j++) {
      if(rankedPlayers[j - 1].wins < rankedPlayers[j].wins) {
        aux = rankedPlayers[j];
        rankedPlayers[j] = rankedPlayers[j - 1];
        rankedPlayers[j - 1] = aux;
      }
    }

    fprintf(ranking, "%s\n", rankedPlayers[i].name);
    fprintf(ranking, "%d %d %d\n", rankedPlayers[i].wins, rankedPlayers[i].draws, rankedPlayers[i].loses);
  }
  
  fclose(ranking);
}