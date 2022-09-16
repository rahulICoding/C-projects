//Rahul Iyer
//9/9/2022
//Guessing Game
//This game makes you guess a number and count how many times you guessed. Have fun!
//3 rules of C++
//1. No Global variables
//2. No strings. Not ever. (You can use cstrings/character arrays, and the cstring and cctype libraries are okay. In fact, I recommend using strcmp and strlen in your projects.)
//3. You should include <iostream>, not stdio. (This applies more to C programmers.)

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  srand(time(NULL)); //sets random seed
  
  while(true) { //while loop for restarting the game
    int num = rand() % 101; //putting a random number into a variable
    //initializing variables
    bool stillPlaying = true;
    int guessNum = 0;
    int count = 0;
    char playAgain;
    cout << "This is guessing game. Guess the number from 0-100" << endl;
    while (stillPlaying == true) { //actual guessing part of game
      cin >> guessNum; //taking in a number from input
      if (guessNum > num) { //comparing if too high
	cout << "Your guess is too high" << endl;
	count++;
      }
      if (num > guessNum) { //comparing if too low
	cout << "Your guess is too low" << endl;
	count++;
      }
      if (num == guessNum) { //when equal end game
	count++;
	cout << "You guessed correctly and it took you ";
	cout << count;
	cout << " guesses" << endl;
	stillPlaying = false;
      }
    }
    cout << "Type y if you want to play again or type n if you dont want to play again" << endl;
    cin >> playAgain;
    if (playAgain == 'y') { //want to play again or not
      cout << "Your game has restarted" << endl; 
    }
    if (playAgain == 'n') {
      cout << "Game over";
      break; //break out of loop
    }
  }
  return 0;
}
