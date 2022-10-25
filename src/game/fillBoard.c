// @Author Caio Lucas Pereira da Silva 22.1.4006

int fillBoard(int **board, int play, int xPos, int yPos) {
  // Valida posição
  if(xPos > 2 || xPos < 0 || yPos > 2 || yPos < 0) return -1;

  // Marca posição
  if(board[xPos][yPos] == 0) {
    board[xPos][yPos] = play;
    return 1;
  }

  return 0;
}