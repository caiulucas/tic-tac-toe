// @Author Caio Lucas Pereira da Silva 22.1.4006

#include "../types/RankedPlayer.h"

void updateRankedPlayer(RankedPlayer *rankedPlayer, int status) {
  // Atualiza um jogador a partir do status
  switch(status) {
    case -1:
      rankedPlayer->loses++;
      break;
    case 0:
      rankedPlayer->draws++;
      break;
    case 1:
      rankedPlayer->wins++;
  }
}