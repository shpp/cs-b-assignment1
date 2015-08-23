#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

void obenglobish(string word, string & obWord);
void addLetterToNewWord(char letter, string & obWord, bool vowel);

int NOMBER_OF_LETTERS=6;

int main() {
    string obWord=""; //new word

    while (true) {
        string word = getLine("Enter a word: ");
        //TODO: rewrite previouse line to  cin>>
        //cout<<"enter a word";
        //cin>>word;

        if (word == "") break;

        //string translation = obenglobish(word);
        obenglobish(word, obWord);
        cout << word << " -> " << obWord << endl;
        obWord="";
    }

   return 0;
}


void obenglobish(string word, string & obWord){
    char letters[NOMBER_OF_LETTERS]={'a','e','y','u','i','o'}; //array of cowels
//    string obWord=""; //new word
    bool vowel;

    int temp=word.length();

    for (int i=0; i<=temp-1; i++){
        vowel=false;

        //cheak if it's the last letter in the word
        if (i==temp-1){
            addLetterToNewWord(word[i],obWord, vowel);
            break;
        }

        //is the current letter is vowel
        //if true - add "ob" to new word
        //but not in case if before this letter is vowel too
        for (int j=0; j<=NOMBER_OF_LETTERS; j++){
              if (word[i]==letters[j]){
                  vowel=true;
                  break;
              }
        }
        addLetterToNewWord(word[i], obWord, vowel);
    }
    //rerurn obWord;
}

void addLetterToNewWord(char letter, string & obWord, bool vowel){
    if (vowel)
        obWord=obWord+"ob";
    obWord=obWord+letter;
}
