#include <iostream>
#include <fstream>
#include "console.h"
#include <stdio.h>
#include "tokenscanner.h"
#include <cctype>


const double C0= -15.59, C1 = 0.39, C2 = 11.8;




using namespace std;


bool ifEndOfSentence(string token);
bool ifWord(string token);
int syllablesIn(string word);
int checkTwoVowel(string word, string vowel);
bool checkLastE(string word);


int main() {
    string filename = " ";
    cout << "Enter input file name: " ;
    cin >> filename;
    ifstream file(filename);
    TokenScanner scanner(file);

    int countWords = 0;
    int countSenten = 0;
    int countSyllabels = 0;

    while (scanner.hasMoreTokens()) {
          string token = scanner.nextToken();
          if(token == " " || token == "\n") continue;

          cout << "Token: " << "[" << token << "]" ;

          //count sent
          if (ifEndOfSentence(token)){
              cout << " (end of sentence)" << endl;
              countSenten++;
              continue;
          }

          //count words
          if (ifWord(token)){
              cout << "(word; " + to_string(countSyllabels += syllablesIn(token)) + " syllables)" << endl;
              countWords++;
              continue;
          }
          //check for ' ' or '
          if (token == "'"){
              string wordInBrackets = scanner.nextToken();
              string lastBracket = scanner.nextToken();
              //show word in brackets
               if (lastBracket == "'"){
                    cout << " + " << "[" << wordInBrackets<< "]" << "(word; " + to_string(countSyllabels += syllablesIn(wordInBrackets)) + " syllables)" << " + " <<"[" << lastBracket << "]" << endl;
                    countWords++;
                    continue;
                }
                // if token has ' and it is last word in sentence
                if (ifEndOfSentence(lastBracket)){
                    countSenten++;
                    cout << " (end of sentence)" << endl;
                    continue;
                }


                cout << " + " << wordInBrackets;

          }

          cout << endl;


    }

    //show information about text
    cout << "Words: " << countWords << endl;
    cout << "Sentences: " << countSenten << endl;
    cout << "Syllabels: " << countSyllabels << endl;
    int grade = C0 + C1*(countWords/countSenten) + C2*(countSyllabels/countWords);
    cout << "Grade level: " << grade << endl;

    return 0;

}

//check end of sentence
bool ifEndOfSentence(string token){
    if(token == "." || token == "!" || token == "?"){
        return true;
    }
    return false;
}

//check if token is word
bool ifWord(string token){
    if(isalpha(tolower(token[0]))) return true;
    return false;
}


int syllablesIn(string word) {
            int syllable = 0;
            string wordVowel = "aeiouy";

            //How many vowel letters in the word
            for (int i = 0; i < word.size(); i++) {
                for (int j = 0; j < wordVowel.size(); j++) {
                    if (word.at(i) == wordVowel.at(j))
                        syllable++;
                }
            }

            // minus vovel pairs
            syllable -= checkTwoVowel(word, wordVowel);

            //minus
            if (checkLastE(word))
                syllable--;

            if (syllable == 0)
                return 1;

            return syllable;
        }

    //Search vowel letter in the word and check her with next.
    //Return the number of pairs
int checkTwoVowel(string word, string vowel) {
        int count = 0;
        for (int i = 0; i < word.size()-1; i++) {
            for (int j = 0; j < vowel.size()-1; j++) {
                if (word.at(i) == vowel.at(j)){
                    for (int k = 0; k < vowel.length()-1; k++) {
                        if (word.at(i+1) == vowel.at(k) && i != word.size()-1)
                            count++;

                    }
                }
            }
        }

        return count;
    }

//This method check is the last letter "e"
bool checkLastE(string word) {
        if (word.at(word.size()-1) == 'e')
            return true;

        return false;
    }

