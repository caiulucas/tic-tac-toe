#include <string.h>
#include <stdio.h>
#include "../game/startGame.h"
#include "../game/clearGame.h"
#include "../types/Player.h"

void startGameRoute(int **board, int *turn, Player *players, int playersCount) {
  while(!playersCount) {
    printf("\nDigite o número de jogadores (1 ou 2): ");
    scanf("%d", &playersCount);

    if(playersCount > 2 || playersCount < 1) {
      printf("\nValor inválido!");
      playersCount = 0;
    }
  }

  if(!strcmp(players[0].name, "")) {
    printf("\nDigite o nome do jogador 1: ");
    scanf("%s", players[0].name);
    players[0].isComputer = 0;

    if(playersCount == 2 && !strcmp(players[1].name, "")) {
      printf("\nDigite o nome do jogador 2: ");
      scanf("%s", players[1].name);
      players[1].isComputer = 0;
    } else {
      strcpy(players[1].name, "Computador");
      players[1].isComputer = 1;
    }
  }

  int winner = startGame(board, turn, players);

  switch(winner) {
    case 'x':
      printf("%s ganhou!", players[0].name);
      clearGame(board, turn, players);
      break;
    case 'o':
      printf("%s ganhou!", players[1].name);
      clearGame(board, turn, players);
      break;
    case 't':
      clearGame(board, turn, players);
      printf("Empate!");
  }
}