//Rahul Iyer
//9/9/2022
//Guessing Game
//This game makes you guess a number and count how many times you guessed. Have fun!

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
    cout << "This is guessing game. Guess the number from 0-100." << endl;
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
}cd 
