// @Author Caio Lucas Pereira da Silva 22.1.4006

#include <string.h>
#include <stdio.h>
#include "../game/startGame.h"
#include "../utils/clearGame.h"
#include "../ranking/addRankedPlayer.h"
#include "../types/Player.h"

void startGameRoute(int **board, int *turn, Player *players, int playersCount) {
  // Valida input
  while(!playersCount) {
    printf("\nDigite o número de jogadores (1 ou 2): ");
    scanf("%d", &playersCount);

    if(playersCount > 2 || playersCount < 1) {
      printf("\nValor inválido!");
      playersCount = 0;
    }
  }

  // Verifica se há jogador
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

  // Verifica vencedor
  char winner = startGame(board, turn, players);
  int status[2];

  switch(winner) {
    case 'x':
      printf("%s ganhou!", players[0].name);
      status[0] = 1;
      status[1] = -1;
      break;
    case 'o':
      printf("%s ganhou!", players[1].name);
      status[0] = -1;
      status[1] = 1;
      break;
    case 't':
      status[0] = 0;
      status[1] = 0;
      printf("Empate!");
  }

  // Termina jogo
  if(winner != ' ') {
    addRankedPlayer(players[0], status[0]);
    addRankedPlayer(players[1], status[1]);
    clearGame(board, turn, players);
  }
}