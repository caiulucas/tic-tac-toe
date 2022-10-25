// @Author Caio Lucas Pereira da Silva 22.1.4006

#include <stdio.h>
#include "../utils/colors.h" 

// Imprime o tabuleiro formatado
void printBoard(int **board) {
  printf("\n");
  printf("┏━━━┳━━━┳━━━┳━━━┓\n");
  printf("┃   ┃ 1 ┃ 2 ┃ 3 ┃\n");
  printf("┣━━━╋━━━╋━━━╋━━━┫\n");
  for(int i = 0; i < 3; i++) {
    printf("┃ %d ┃", i + 1);
    for(int j = 0; j < 3; j++) {
      switch(board[i][j]) {
        case 1:
          printf(" " GREEN("X") " ");
          break;
        case -1:
          printf(" " RED("O") " ");
          break;
        case 0:
          printf("   ");
      }
      if(j != 2) {
        printf("┃");
      }
    }
    printf("┃\n");
    if(i != 2) {
      printf("┣━━━╋━━━╋━━━╋━━━┫\n");
    }
  }

  printf("┗━━━┻━━━┻━━━┻━━━┛\n");
}
