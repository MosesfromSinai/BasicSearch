#include <iostream>
#include <string>
using namespace std;

int GetNumOfNonWSCharacters(const string usrStr) {
  int counter;
  unsigned i; 
  counter = 0; 
   for (i = 0; i < usrStr.size(); ++i) { 
        if (usrStr.at(i) != ' ' ) { 
            counter++; 
        } 
    }  
  return counter;  
} 

int GetNumOfWords(const string usrStr) {
    int counter = 1;  
    for (int i = 0; i < usrStr.size(); ++i) { 
        if (usrStr.at(i) == ' ' && usrStr.at(i - 1) != ' ') { 
            counter += 1; 
        }
    }  
  return counter; 
} 

int FindText(string toFind, string usrStr) {
  int counter = 0;
    for(int i = 0; i < usrStr.size(); i++) {
     int j; 
     for(j = 0; j < toFind.size(); j++) {
       if(usrStr[i + j] != toFind[j]) {
         break;
       }
     }
         if(j == toFind.size()) {
         counter++;
       }
   }

   return counter;
}

  
/* size_t where = usrStr.find(toFind);
  while (where != string::npos) {
    counter++;
    where = usrStr.find(toFind, where + 1);
    } */ 
  
void ReplaceExclamation(string& usrStr) {
   unsigned int i;
   for (i = 0; i < usrStr.size(); ++i) {
        if (usrStr.at(i) == '!' ) {
            usrStr.at(i) = '.';
        } 
    } 
  cout << usrStr;
} 

void ShortenSpace(string& usrStr) {
   unsigned i;
   string tmp;

   for (i = 1; i < usrStr.size(); ++i) {
      if (!(isspace(usrStr.at(i)) && isspace(usrStr.at(i - 1)))) {
         tmp = tmp + usrStr.at(i - 1);
      }
      if (i == usrStr.size() - 1) {
         tmp = tmp + usrStr.at(i);
      }
   }
   usrStr = tmp;
   return;
}

void PrintMenu() {
cout << endl; 
cout << "MENU" << endl; 
cout << "c - Number of non-whitespace characters" << endl;
cout << "w - Number of words" << endl;
cout << "f - Find text" << endl;
cout << "r - Replace all !'s" << endl;
cout << "s - Shorten spaces" << endl; 
cout << "q - Quit" << endl; 
cout << endl; 
}

void ExecuteMenu(char option, string usrStr) {
   string toFind;
   int numFinds;
  
/* if(option == 'c') {
            cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(usrStr) << endl; 
  }
  else if (option == 'w') {
            cout << "Number of words: " << GetNumOfWords(usrStr) << endl; 
  }
  else if(option == 'f'){
    cin.ignore();
            cout << "Enter a word or phrase to be found:";
            getline(cin, toFind);
            cout << " " << toFind << " " << "counter: " << FindText(toFind, usrStr) << endl; 
  }
  else if(option == 'r'){
    ReplaceExclamation(usrStr);
            cout << "Edited text: " << usrStr << endl; 
  }
  else if(option =='s'){
    ShortenSpace(usrStr);
            cout << "Edited text: " << usrStr << endl; */
  
    switch (option) {
      case 'c':
            cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(usrStr) << endl; 
          break;

        case 'w':
            cout << "Number of words: " << GetNumOfWords(usrStr) << endl; 
          break;

        case 'f':
            cin.ignore();
            cout << "Enter a word or phrase to be found:";
            getline(cin, toFind);
            cout << " " << toFind << " " << "counter: " << FindText(toFind, usrStr) << endl; 
          break;

        case 'r':
          ReplaceExclamation(usrStr);
            cout << "Edited text: " << usrStr << endl; 
          break;

         case 's':
           ShortenSpace(usrStr);
            cout << "Edited text: " << usrStr << endl; 
          break;
      }
  }
  
int main() {
   string usrString;
   char menuChoice;

   cout << "Enter a sample text:" << endl;
   getline(cin, usrString);
   cout << endl;

   cout << "You entered: " << usrString << endl << endl;
   
   PrintMenu();

   menuChoice = ' ';
   while (menuChoice != 'q') {
      cout << "Choose an option:" << endl;
      cin >> menuChoice;
      if (menuChoice == 'c' || menuChoice == 'w' || menuChoice == 'f' ||
          menuChoice == 'r' || menuChoice == 's' || menuChoice == 'o') {
         ExecuteMenu(menuChoice, usrString);
         PrintMenu();
      }
   }

   return 0;
}