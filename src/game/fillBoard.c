int fillBoard(int **board, int play, int xPos, int yPos) {
  if(xPos > 2 || xPos < 0 || yPos > 2 || yPos < 0) return -1;
  
  if(board[xPos][yPos] == 0) {
    board[xPos][yPos] = play;
    return 1;
  }

  return 0;
}