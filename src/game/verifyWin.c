// @Author Caio Lucas Pereira da Silva 22.1.4006

char verifyWin(int **board) {
  int sumFirstDiagonal = 0;
  int sumLastDiagonal = 0;
  int tieSum = 0;

  // O tabuleiro é preenchido com 0 se a casa for vazia, 1 se for X e -1 se for O
  // Soma-se as 3 direções possíveis e retorna o vencedor caso alguma das somas chegue a 3
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

  // Caso dê empate, retorna 't' de 'tie'
  if(tieSum == 9) return 't';

  return ' ';
}