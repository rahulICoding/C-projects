//Rahul Iyer
//9/13/2022
//Palindrome
//Type a word that is 80 characters and the program will check if its a palindrome

#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char str[80];
  int count = 0;
  cout << "What is your input?" << endl;
  cin >> str;
  char str2[80];
  char str3[80];
  strcpy(str2, str);
  cout << str2 << endl;
  cout << str << endl;
  cout << strlen(str) << endl;
  for (int i = 0; i < strlen(str); i++) {
    if (isalpha(str[i]) == true) {
      str[i] = str3[i];
      tolower(str3[i]);
      cout << str3[i] << endl;
    }
  }
  cout << str3 << endl;
  
}
