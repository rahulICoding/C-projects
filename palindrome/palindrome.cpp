//Rahul Iyer
//9/13/2022
//Palindrome
//Type a word that is 80 characters and the program will check if its a palindrome

#include <iostream>
#include <cstring>

using namespace std;

int main() {
  //creating all the char arrays that are going to be used
  char str[80];
  char str2[80];
  char str3[80];
  
  cout << "What is your input?" << endl;
  cin.get(str, 80);
  cin.get();

  //cout << str << endl;
  //cout << strlen(str) << endl;
  
  int count = 0;
  for (int i = 0; i < strlen(str); i++) { //gets rid of all non characters
    if (isalpha(str[i])) {
      str2[count] = tolower(str[i]); //makes the char array all lowercase one char at a time
      count++; //adds to count
    }
  }
  str2[count] = 0; // Ensure that the string is null terminated

  int count2 = 0;
  for (int i = 0; i < strlen(str2); i++) { //reverse str2 into str3 so that it can be compared in the next for loop
    str3[count2] = str2[strlen(str2) - 1 - i]; //adding last letter to first 
    count2++; //adds to count
  }
  str3[count2] = 0; //ensure that the string is null terminated

  //cout << str2 << endl;
  //cout << str3 << endl;

  int result = strcmp(str2, str3); //result holds the comparing of str2 and str3
  if (result == 0) { //is a palindrome or not a palindrome
    cout << "Palindrome" << endl;
  }
  else {
    cout << "Not a Palindrome" << endl;
  }
  
}
