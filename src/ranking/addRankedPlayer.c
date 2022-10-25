// @Author Caio Lucas Pereira da Silva 22.1.4006

// status: 0 = draw, 1 = win, -1 = lose
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../types/Player.h"
#include  "../types/RankedPlayer.h"
#include "getRankedPlayers.h"
#include "updateRankedPlayer.h"
#include "../ranking/updateRanking.h"

int addRankedPlayer(Player player, int status) {
  // Valida número de jogadores
  int n;
  RankedPlayer *rankedPlayers = getRankedPlayers(&n);

  // Atualiza o ranking
  for(int i = 0; i < n; i++) { 
    if(!strcmp(player.name, rankedPlayers[i].name)) {
      updateRankedPlayer(&rankedPlayers[i], status);
      updateRanking(rankedPlayers, n);
      free(rankedPlayers);
      return 1;
    }
  }

  // Adiciona novo jogador caso possível
  if(n <= 9) {
    RankedPlayer *newRankedPlayers = malloc((n + 1) * sizeof(RankedPlayer));
    strcpy(newRankedPlayers[n].name, player.name);
    newRankedPlayers[n].wins = 0;
    newRankedPlayers[n].draws = 0;
    newRankedPlayers[n].loses = 0;

    for(int i = 0; i < n; i++) {
      strcpy(newRankedPlayers[i].name, rankedPlayers[i].name);
      newRankedPlayers[i].wins = rankedPlayers[i].wins;
      newRankedPlayers[i].draws = rankedPlayers[i].draws;
      newRankedPlayers[i].loses = rankedPlayers[i].loses;
    }

    updateRankedPlayer(&newRankedPlayers[n], status);
    updateRanking(newRankedPlayers, n + 1);
    free(newRankedPlayers);
    free(rankedPlayers);
    return 1;
  }
  
  free(rankedPlayers);
  return 0;
}