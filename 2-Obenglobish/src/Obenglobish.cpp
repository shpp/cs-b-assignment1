#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;



//check last letter in word
int checkLastLetter(string word){
    int posLastLett = word.size()-1;
    if(word.at(posLastLett) == 'e')
        return -1;
    return 0;
}

//this function +before volar letters - "ob"
string obenglobish(string word){
    int sizeWord = word.size()+checkLastLetter(word);
    for (int i = 0; i < sizeWord; i++) {
        if (word.at(i) == 'a' || word.at(i) == 'e' || word.at(i) == 'i' || word.at(i) == 'o' || word.at(i) == 'u' ) {
            word.insert(i, "ob");
            sizeWord = word.size()+ checkLastLetter(word);
            i++;
            i++;
        }
    }
    return word;
}


int main() {
    while (true) {
        string word = getLine("Enter a word: ");

        if (word == "") break;

        string translation = obenglobish(word);
        cout << word << " -> " << translation << endl;
    }
   return 0;
}
