//Rahul Iyer
//October 13, 2022
//TictacToe
//This program allows you to play tictactoe with another person or yourself if ur like that. It calculates the wins and ties throughout the games you play until you say you dont wanna play again.

#include <iostream>
#include <cstring>

using namespace std;

//function prototypes
void printBoard(char board[3][3]);
void clearBoard(char board[3][3]);
bool checkWin(char board[3][3], int player);
bool checkTie(char board[3][3]);
void playAgain(char board[3][3], bool& keepPlaying);

int main() {


  //variables defined
  char board[3][3];
  char spot[3];

  clearBoard(board);

  char X_MOVE = 'X';
  char O_MOVE = 'O';
  int X_TURN = 0;
  int O_TURN = 1;
  int turn = X_TURN;
  int X_WINS = 0;
  int O_WINS = 0;
  int TIES = 0;
  bool keepPlaying = true;

  while (keepPlaying == true) { //checks for playing again or not

    turn = X_TURN;

    while (checkWin(board, X_MOVE) == false && checkWin(board, O_MOVE) == false && checkTie(board) == false) { //plays only if checkwin and checktie is false
    if (turn == X_TURN) { // x turn
      cout << "X Turn" << endl;
    }
    else { // o turn
      cout << "O Turn" << endl;
    }

    printBoard(board);

    //taking in input
    cin.get(spot, 3);
    cin.get();

    //checking if the move is valid
    if (strlen(spot) != 2) {
      cout << "please enter valid move" << endl;
    }
    else if (spot[0] != 'a' && spot[0] != 'b' && spot[0] != 'c') {
      cout << "please enter valid move a,b,c" << endl;
    }
    else if (spot[1] != '1' && spot[1] != '2' && spot[1] != '3') {
      cout << "please enter valid move 1,2,3" << endl;
    }
    else { //placing the move onto the board
      int column = spot[0] - 'a';
      int row = spot[1] - '1';
      if (board[row][column] == ' ') { //checking if the spot is open
	if (turn == X_TURN) {
	  board[row][column] = X_MOVE;
	  turn = O_TURN;
	}
	else {
	  board[row][column] = O_MOVE;
	  turn = X_TURN;
	}
      }
      else {
	cout << "spot is already filled cannot enter here" << endl;
      }
    }

    if (checkWin(board, X_MOVE) == true) { //checking x win
      X_WINS++;
      cout << "X WIN" << endl;
      cout << "X WINS: " << X_WINS << endl;
      cout << "O WINS: " << O_WINS << endl;
      cout << "TIES: " << TIES << endl;
      playAgain(board, keepPlaying);
      break;
    }
    
    else if (checkWin(board, O_MOVE) == true) { //checking o win
      O_WINS++;
      cout << "O WIN" << endl;
      cout << "X WINS: " << X_WINS << endl;
      cout << "O WINS: " << O_WINS << endl;
      cout << "TIES: " << TIES << endl;
      playAgain(board, keepPlaying);
      break;
    }

    else if (checkTie(board) == true){ //checking tie
      TIES++;
      cout << "X WIN" << endl;
      cout << "X WINS: " << X_WINS << endl;
      cout << "O WINS: " << O_WINS << endl;
      cout << "TIES: " << TIES << endl;
      playAgain(board, keepPlaying);
      break;
    }
    
  
  }
  }
  
  return 0;
}

void printBoard(char board[3][3]) { //printing board

  cout << " 123" << endl;
  cout << 'a' << board[0][0] << board[1][0] << board[2][0] << endl;
  cout << 'b' << board[0][1] << board[1][1] << board[2][1] << endl;
  cout << 'c' << board[0][2] << board[1][2] << board[2][2] << endl;
    
}

void clearBoard(char board[3][3]) { //make board all empty spaces

  for(int row = 0; row < 3; row++) {
    for(int column = 0; column < 3; column++) {
      board[row][column] = ' ';
    }
  }
  
}

bool checkWin(char board[3][3], int player) { // checks the win for x or o
  
  if (board[0][0] == player && board[0][1] == player &&board[0][2] == player){
    return true;
  }
  if (board[1][0] == player && board[1][1] == player &&board[1][2] == player){
    return true;
  }
  if (board[2][0] == player && board[2][1] == player &&board[2][2] == player){
    return true;
  }
  if (board[0][0] == player && board[1][0] == player &&board[2][0] == player){
    return true;
  }
  if (board[0][1] == player && board[1][1] == player &&board[2][1] == player){
    return true;
  }
  if (board[0][2] == player && board[1][2] == player &&board[2][2] == player){
    return true;
  }
  if (board[0][0] == player && board[1][1] == player &&board[2][2] == player){
    return true;
  }
  if (board[0][2] == player && board[1][1] == player &&board[2][0] == player){
    return true;
  }
  return false;
}

bool checkTie(char board[3][3]) { //checks tie
  int count = 0;
  for(int row = 0; row < 3; row++) {
    for(int column = 0; column < 3; column++) {
      if((board[row][column] == 'X') || (board[row][column] == 'O')) {
	count++;
      }
    }
  }
  if (count == 9) {
    return true;
  }
  else {
    return false;
  }
}

void playAgain(char board[3][3], bool& keepPlaying) { //check if they want to play again or not
  
  char decision;

  cout << "---------" << endl << "do you want to play again - answer Y or N" << endl;
  cin.get(decision);
  cin.get();

  if ((decision = 'Y') || (decision = 'y')) {
    cout << "Next Game" << endl;
    clearBoard(board);
    
  }
  else {
    cout << "Good Game" << endl;
    keepPlaying = false;
  }
    
  
}
