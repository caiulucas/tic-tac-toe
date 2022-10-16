char verifyWin(int **board) {
  int sumFirstDiagonal = 0;
  int sumLastDiagonal = 0;
  int tieSum = 0;

  for(int i = 0; i < 3; i++) {
    int sumHorizontal = 0;
    int sumVertical = 0;

    for(int j = 0; j < 3; j++) {
      sumHorizontal += board[i][j];
      sumVertical += board[j][i];

      if(board[i][j] == 1 || board[i][j] == -1) tieSum++;
    }
    
    sumLastDiagonal += board[2 - i][i];
    sumFirstDiagonal += board[i][i];

    if(
      sumHorizontal == 3 || 
      sumVertical == 3 || 
      sumFirstDiagonal == 3 || 
      sumLastDiagonal == 3
    ) return 'x';
  
    if(
      sumHorizontal == -3 || 
      sumVertical == -3 || 
      sumFirstDiagonal == -3 || 
      sumLastDiagonal == -3
    ) return 'o';
  }

  if(tieSum == 9) return 't';

  return ' ';
}