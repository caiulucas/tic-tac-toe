#include "../types/RankedPlayer.h"

void updateRankedPlayer(RankedPlayer *rankedPlayer, int status) {
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