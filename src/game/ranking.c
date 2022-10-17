#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct {
  char name[200];
  int wins;
  int draws;
  int loses;
} RankedPlayer;

void showRanking() {
  FILE *ranking = fopen("velha.ini", "r");

  int n = fgetc(ranking) - '0';

  printf("%.*s", 50, TAB_HOR);
  printf(TAB_TR "\n");

  printf("     " TAB_VER "  Nome  " TAB_VER " Vitórias " TAB_VER " Empates " TAB_VER " Derrotas \n");
  printf("\n");

  RankedPlayer *rankedPlayers = malloc(n * sizeof(RankedPlayer));

  fgetc(ranking);

  for(int i = 0; i < n; i++) {
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