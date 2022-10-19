#include <stdio.h>
#include <stdlib.h>
#include "../types/RankedPlayer.h"
#include "getRankedPlayers.h"

void showRanking() {  
  printf("┏");
  for(int i = 0; i < 76; i++) printf("━");
  printf("┓\n┃");
  printf(" %7s   ", "Posição");
  printf("%30s   ", "Nome");
  printf("%8s   ", "Vitórias");
  printf("%7s   ", "Empates");
  printf("%8s   ", "Derrotas");
  printf("┃\n┣");
  for(int i = 0; i < 76; i++) printf("━");
  printf("┫\n");

  int n;
  RankedPlayer *rankedPlayers = getRankedPlayers(&n);

  for(int i = 0; i < n; i++) {
    printf("┃");
    printf(" %7d   ", i + 1);
    printf("%30s   ", rankedPlayers[i].name);
    printf("%8d   ", rankedPlayers[i].wins);
    printf("%7d   ", rankedPlayers[i].draws);
    printf("%8d   ", rankedPlayers[i].loses);
    printf("┃" "\n");
  }

  printf("┗");
  for(int i = 0; i < 76; i++) printf("━");
  printf("┛");
}