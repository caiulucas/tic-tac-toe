// @Author Caio Lucas Pereira da Silva 22.1.4006

#include "verifyWin.h"
#include "fillBoard.h"

// Algorítimo da I.A.
int minimax(int **board, int isMaximizing) {
  char result = verifyWin(board);
  
  if(result == 'x') return 10;
  if(result == 'o') return -10;
  if(result == 't') return 0;

  // Verifica se deve jogar como maximizador ou minimizador
  if(isMaximizing) {
    int bestScore = 2000000;

    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        if(board[i][j] == 0) {
          board[i][j] = -1;

          // Recursividade
          int score = minimax(board, 0);
          board[i][j] = 0;
          if(score < bestScore) bestScore = score;
        }
      }
    }
    return bestScore;
  } else {
    int bestScore = -2000000;

    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        if(board[i][j] == 0) {
          board[i][j] = 1;

          // Recursividade
          int score = minimax(board, 1);
          board[i][j] = 0;
          if(score > bestScore) bestScore = score;
        }
      }
    }
    return bestScore;
  }
}

// Verifica a melhor posição, chamando o algoritmo
void bestPlay(int **board) {
  int bestScore = 2000000;
  int xPos = 0;
  int yPos = 0;

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(board[i][j] == 0) {
        board[i][j] = -1;
        int score = minimax(board, 0);
        board[i][j] = 0;

        if(score < bestScore) {
          bestScore = score;
          xPos = i;
          yPos = j;
        }
      }
    }
  }

  // Preenche a posição
  fillBoard(board, -1, xPos, yPos);
}
