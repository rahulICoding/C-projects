#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  srand(time(NULL));
  
  while(true) {
    int num = rand() % 101;
    bool stillPlaying = true;
    int guessNum = 0;
    int count = 0;
    char playAgain;
    cout << "This is guessing game. Guess the number." << endl;
    while (stillPlaying == true) {
      cin >> guessNum;
      if (guessNum > num) {
	cout << "Your guess is too high" << endl;
	count++;
      }
      if (num > guessNum) {
	cout << "Your guess is too low" << endl;
	count++;
      }
      if (num == guessNum) {
	cout << "You guessed correctly and it took you ";
	cout << count;
	cout << " guesses" << endl;
	stillPlaying = false;
      }
    }
    cout << "Type y if you want to play again or type n if you dont want to play again" << endl;
    cin >> playAgain;
    if (playAgain == 'y') {
      cout << "Your game has restarted" << endl; 
    }
    if (playAgain == 'n') {
      cout << "Game over";
      break;
    }
  }
  return 0;
}
