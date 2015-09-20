#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
//#include "strlib.h"
using namespace std;

string obenglobish(string word);

int main() {
   while (true) {
       string word = getLine("Enter a word: ");
       if (word == "") continue;
       string translation = obenglobish(word);
       cout << word << " -> " << translation << endl;
   }
   return 0;
}

string obenglobish(string word) {
    string vowels = "aeiou";
    if (word == "e" || word == "") return word; //skip silence 'e'
    if (vowels.find(word[0]) != string::npos) { //if char is vowel
            if (vowels.find(word[1]) != string::npos) {
                // skip next vowel
                return string("ob") + word[0] + word[1] + obenglobish(word.substr(2));
            } else return string("ob") + word[0] + obenglobish(word.substr(1));
    } else return word[0] + obenglobish(word.substr(1));
}
