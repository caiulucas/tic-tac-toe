#include "../utils/printFile.h"
#include "../utils/clear.h"
#include "startGameRoute.h"
#include "../game/loadGame.h"

void initialRoute() {
  int option;
  int board[3][3] = {{ 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }};
  int turn = 0; 
  struct Player players[2];
  strcpy(players[0].name, "");
  strcpy(players[1].name, "");

  while(1) {
    printFile("assets/startRoute.txt");

    printf("\nEscolha a opção: ");
    scanf("%d", &option);

    if(!option) break;

    switch(option) {
      case 1:
        clear();
        startGameRoute(board, &turn, players, 0);
        break;
      case 2:
        clear();
        loadGame(board, &turn, players);
        startGameRoute(board, &turn, players, 1);
        break;
      case 3:
        startGameRoute(board, &turn, players, 1);
        break;
      case 4:
        break;
      default:
        clear();
        printf("Opção inválida.");
    }
    
  }
}