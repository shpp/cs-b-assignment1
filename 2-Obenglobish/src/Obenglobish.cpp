#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

string obenglobish(string word);
bool isVovel(char ch);

int main() {
    while (true) {
        string word = getLine("Enter a word:" );
        if (word == "") break;
        string translation = obenglobish(word);
        cout << word << " -> " << translation << endl;
    }
    return 0;
}

string obenglobish(string word){
    // character-oriented search on the word and replacing vowels
    for (int i=0; i < word.length()-1; i++){
        if(!isVovel(word[i-1])){
            if(isVovel(word[i])){
                word.insert(i, "ob");
                i+=2;
            }
        }
    }
    return word;
}

// Function checks a symbol of belonging to a vowel
bool isVovel(char ch){
    bool res = false;
    switch (ch) {
        case 'a': case 'e': case 'i': case 'o':  case 'u':
            res = true;
            break;
        default:
            res = false;
            break;
    }
    return res;
}
