#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

//Function checks if a given character a vowel
//Param letter - a symbol that you want to analyze
//return - true if the character is a vowel
bool isVowel(char letter){
    char vowelSymbols[] = "AEIOUYaeiouy";

   for(int i = 0; vowelSymbols[i] != '\0'; i++){
       if(letter == vowelSymbols[i])
           return true;
   }

   return false;
}

//Function converts the string in obengoblish form
//Param line - the string to be translated
//return string line in form obenglobish
string obengoblish(string line){
    if (line == "") return line;
    string result;
    string modifier = "ob";
    char cheklastLetter = 'e';
    int lineLastLetterIndex = line.length()-1;

    for (int i=0; line[i] != '\0'; i++){

        if (isVowel(line[i]) & !isVowel(line[i+1]))  {

            if ((line[i] == cheklastLetter) & (i == lineLastLetterIndex) || ( isVowel(line[i-1]))){
                 result += line[i];
                 continue;
            }
            result += modifier + line[i];

        } else result += line[i];

    }
    return result;
}

int main() {
   // TODO: fill in the code
    while (true) {
        string line = getLine("Enter a word: ");
        if (line == "") break;

        cout << line << " -> " << obengoblish(line)<< endl;
    }

   return 0;
}
