// Samuel Sandoval Section 17

#include <iostream>
#include <ctime>

using namespace std;

const int ROWS = 6;
const int COLUMNS = 7;
const char SPACE  = ' ';
const char PLAYER_PIECE = 'X';
const char COMPUTER_PIECE = 'O';
const string PLAYER_WINS = "You win!";
const string COMPUTER_WINS = "You lose";
const string DRAW = "It is a draw";
const string NOT_DONE = "The game is not finished.";


void Print(char board[ROWS][COLUMNS]) {
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLUMNS; j++) {
      if (j < COLUMNS-1) {
        if(board[i][j] != PLAYER_PIECE && board[i][j] != COMPUTER_PIECE) {
          cout << "|" << SPACE;
        }
        else {
          if(board[i][j] == PLAYER_PIECE) {
            cout << "|" << PLAYER_PIECE;
          }
          else if(board[i][j] == COMPUTER_PIECE) {
            cout << "|"<<COMPUTER_PIECE;
          }
        }
      }
      else {
        if(board[i][j] != PLAYER_PIECE && board[i][j] != COMPUTER_PIECE) {
          cout << "|" << SPACE;
        }
        else {
          if(board[i][j] == PLAYER_PIECE) {
            cout << "|"<< PLAYER_PIECE;
          }
          else if(board[i][j] == COMPUTER_PIECE) {
            cout << "|" << COMPUTER_PIECE;
          }
        }
      }
    }
    cout << "|" << endl;
  }
  cout << endl;
}
void SetPlayerMove(char board[ROWS][COLUMNS]) {
  int column;
  cout << "Choose a column for X: ";
  cin >> column;
  if(column > 7 && column < 0) {
    SetPlayerMove(board);
  }
  int row = ROWS - 1;
  while(board[row][column] == PLAYER_PIECE || board[row][column] == COMPUTER_PIECE) {
    if (row == 0) {
      SetPlayerMove(board);
    }
    row -= 1;
  }
    board[row][column] = PLAYER_PIECE;
}

void SetComputerMove(char board[ROWS][COLUMNS]){
  int column = rand() % 7;
  int row = ROWS - 1;
  while(board[row][column] == PLAYER_PIECE || board[row][column] == COMPUTER_PIECE) {
    if (row == 0) {
      column = rand() % 7;
      row = ROWS - 1;
    }
    else {
      row -= 1;
    }
  }
    board[row][column] = COMPUTER_PIECE;
}

bool CheckRows(char board[ROWS][COLUMNS], char piece) {
  int counter;
  for (int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLUMNS; j++){
      if (counter == 4) {
        return true;
      }
      if(board[i][j] == piece){
        counter++;
        }
      else {
        counter = 0;
      }
    }
  }
  return false;
}

bool CheckColumns(char board[ROWS][COLUMNS], char piece){
  int counter;
  for (int col = 0; col < COLUMNS; col++) {
    for(int row = 0; row < ROWS; row++) {
      if (counter == 4) {
        return true;
      }
      if(board[col][row] == piece){
        counter++;
        }
      else {
        counter = 0;
      }
    }
  }
  return false;
}

bool CheckDiagonals(char board[ROWS][COLUMNS], char piece) {

  for (int row = 0; row < 3; row++) {
    for(int col = 0; col < 4; col++) {
      if(board[row][col] == piece && board[row+1][col+1] == piece &&  board[row+2][col+2] == piece && board[row+3][col+3] == piece) {
        return true;
      }
    }
  }
  for (int row = 0; row < 3; row++) {
    for(int col = 6; col > 2  && col <= 6; col--) {
      if(board[row][col] == piece && board[row+1][col-1] == piece &&  board[row+2][col-2] == piece && board[row+3][col-3] == piece) {
        return true;
      }
    }
  }
  return false;
}

bool IsWinner(char board[ROWS][COLUMNS], char piece){
  if(CheckDiagonals(board, piece) == true) {
    return true;
  }
  else if(CheckColumns(board, piece) == true) {
    return true;
  }
  else if(CheckRows(board, piece) == true) {
    return true;
  }
  else {
    return false;
  }
}

bool IsBoardFull(char board[ROWS][COLUMNS]) {
  int row = 0;
  for(int column = 0; column < COLUMNS; column++) {
    if(board[row][column] != PLAYER_PIECE && board[row][column] != COMPUTER_PIECE) {
      return false;
    }
  }
  return true;
}

string DetermineBoardState(char board[ROWS][COLUMNS]) {
  if(IsWinner(board, PLAYER_PIECE) == true) {
    return PLAYER_WINS;
  }
  else if (IsWinner(board, COMPUTER_PIECE) == true) {
    return COMPUTER_WINS;
  }
  if (IsBoardFull(board) == true) {
    return DRAW;
  }
  else {
    return NOT_DONE;
  }
}

int main(int argc, char* argv[]) {
  srand(time(0));
  char board[ROWS][COLUMNS];
  Print(board);

  do{
    SetPlayerMove(board);
    SetComputerMove(board);
    Print(board);
  } while(DetermineBoardState(board) == NOT_DONE);
  cout << DetermineBoardState(board) << endl;

  return 0;
}
