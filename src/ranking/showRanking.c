#include <stdio.h>
#include <stdlib.h>
#include "../types/RankedPlayer.h"
#include "getRankedPlayers.h"

#define TAB_HOR "\u2501" // ━ (horizontal)
#define TAB_VER "\u2503" // ┃ (vertical)
#define TAB_TL  "\u250F" // ┏ (top-left)
#define TAB_ML  "\u2523" // ┣ (middle-left)
#define TAB_BL  "\u2517" // ┗ (bottom-left)
#define TAB_TJ  "\u2533" // ┳ (top-join)
#define TAB_MJ  "\u254B" // ╋ (middle-join)
#define TAB_BJ  "\u253B" // ┻ (bottom-join)
#define TAB_TR  "\u2513" // ┓ (top-right)
#define TAB_MR  "\u252B" // ┫ (middle-right)
#define TAB_BR  "\u251B" // ┛ (bottom-right)

void showRanking() {

  for(int i = 0; i < 50; i++) printf(TAB_HOR);

  printf("\n Nome\t\t\tVitórias\tEmpates\tDerrotas\n");

  int n;
  RankedPlayer *rankedPlayers = getRankedPlayers(&n);

  for(int i = 0; i < n; i++) {
    printf(" %d. ", i + 1);
    printf(TAB_VER);
    printf(" %s ", rankedPlayers[i].name);
    printf(TAB_VER);
    printf(" %d ", rankedPlayers[i].wins);
    printf(TAB_VER);
    printf(" %d ", rankedPlayers[i].draws);
    printf(TAB_VER);
    printf(" %d ", rankedPlayers[i].loses);
    printf("\n");
  }
}