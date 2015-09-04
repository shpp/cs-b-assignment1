#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

string obenglobish(string word);

int main() {
   while(true) {
       string word = toLowerCase(getLine("Enter a word: "));

       if(word == "")
           break;
       string translation = obenglobish(word);
       cout << word << " -> " << translation << endl;
   }
   return 0;
}

bool isVowel(char letter) {
    char vowels[6] = {'a','e','i','o','u'};
    for (char vowel: vowels) {
        if(letter == vowel)
            return true;
    }
    return false;
}

string obenglobish(string word) {
    string result;
    char prevLetter = NULL;
    for(int i = 0; i < word.length(); i++) {
        char letter = word[i];
        if(isVowel(letter) && (prevLetter == NULL || !isVowel(prevLetter))) {
            if (!(i == word.length() - 1 && letter == 'e'))
                result += "ob";
        }
        result += letter;
        prevLetter = letter;
    }
    return result;
}


