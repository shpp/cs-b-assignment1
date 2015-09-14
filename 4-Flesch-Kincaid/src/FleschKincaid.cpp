#include <iostream>
#include "console.h"
#include <fstream>
#include "tokenscanner.h"
using namespace std;


bool checkIsPunctuation(string token){
    string punctuation = ".!?";
    for (int i=0; punctuation[i] != '\0'; i++){
        if (punctuation[i] == token[0]) return true;
    }
    return false;
}

//Function checks if a given character a vowel
//Param letter - a symbol that you want to analyze
//return - true if the character is a vowel
bool checkCharIsVowel(char letter){
    char vowelSymbols[] = "AEIOUYaeiouy";

   for(int i = 0; vowelSymbols[i] != '\0'; i++){
       if(letter == vowelSymbols[i])
           return true;
   }

   return false;
}

bool checkLastCharE(char c) {
    char leterE = 'e';
    if (c == leterE) return true;
    return false;
}

/*
  * Given a word, estimates the number of syllables in that word according to the
  * heuristic specified in the handout.
  *
  * @param token - A string containing a single word.
  * @return An estimate of the number of syllables in that word.
  */
int countSyllables(string token){
    int syllablesCounter = 0;

    for (int i=0; token[i] != '\0'; i++){

        if (checkCharIsVowel(token[i]) &
            !checkCharIsVowel(token[i - 1])){

            syllablesCounter++;
        }

    }
    if (checkLastCharE(token[token.length()-1]) &
        !checkCharIsVowel(token[token.length()-2])){

        syllablesCounter--;
    }

    if (syllablesCounter <= 0)  syllablesCounter = 1;

    return syllablesCounter;
}

void analiseFileToGradeLevel(ifstream & myFile){
    double gradeLevelResult = 0;

    double wordCounter = 0;

    double syllablesCounter = 0;

    double sentencesCounter = 0;

    const double cZero = -15.59;
    const double cOne = 0.39;
    const double cTwo = 11.8;

    TokenScanner scanner(myFile);
    scanner.ignoreWhitespace();
    scanner.addWordCharacters("'");

    while (scanner.hasMoreTokens()) {

          string token = scanner.nextToken();
          // count the number of words and syllables in each
          if (isalpha( token[0])) {
           wordCounter++;
           syllablesCounter +=countSyllables(token);

           //cout<<"word: ["<<token<<"] syllables in word: "<<countSyllables(token)<<endl;
          } //else cout<<"token: ["<<token<<"]"<<endl;

          // counting the number of sentence for punctuation
          if (checkIsPunctuation(token)) {
            sentencesCounter++;
            //cout<<"(end of sentence)"<<" sentencesCounter: "<<sentencesCounter<<endl;
          }

       }
    if (wordCounter == 0) wordCounter++;

    if (sentencesCounter == 0) sentencesCounter++;

    cout<<"wordCounter: "<<wordCounter<<endl;
    cout<<"syllablesCounter: "<<syllablesCounter<<endl;
    cout<<"sentencesCounter: "<<sentencesCounter<<endl;
    gradeLevelResult = cZero + cOne * ( wordCounter / sentencesCounter) + cTwo * (syllablesCounter / wordCounter);
    cout<<"Grade Level: "<<gradeLevelResult<<endl;

}

int main() {
    // TODO: fill in the code
    string fileName;
    ifstream myFile;
    while (true) {
        cout<<"Enter file name pls:";
        cin>>fileName;
        myFile.open(fileName);
        if (myFile.is_open()){

            cout<<"FILE IS OPEN"   <<endl;

            analiseFileToGradeLevel(myFile);

        } else cout<<"File not found :("<<endl;
        myFile.close();
    }
    return 0;
}
