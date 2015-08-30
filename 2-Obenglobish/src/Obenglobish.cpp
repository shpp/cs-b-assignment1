#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

/* Return obenglobish word */
string obenglobish(string word);
/* Main obenglobish process */
string wordProcess(int index, string word, string result, int vowelsSum);
/* Check if this char is vowel */
bool isVowel (char letter);
/* Sets console output */
void consoleSettings();
/* Program window title  */
const string programTitle = "Obenglobish";
/* Disable console dupplication */
const bool consoleEcho = false;

int main() {
   consoleSettings();

   /* Program asks user to enter words infinitely */
   while(true){
       string word = getLine("Enter a word: ");
       /* Empty string input isn't processing */
       if(word == ""){
           break;
       }
       /* Obenglobish translation */
       string translation = obenglobish(word);
       cout << word << "  -> " << translation << endl;
   }

   return 0;
}

/*Obenglobish translator:
 *syllable 'ob' add before all vowels - a,e,i,o,u,y - only if not:
 * - before this vowel is another vowel
 * - this vowel is e at end of word */
string obenglobish(string word){
    string result = "";
    int startAnalizeIndex = 0;
    int vowelsSum = 0;
    result = wordProcess(startAnalizeIndex, word, result, vowelsSum);

    return result;
}

/* Recursive loop word process */
string wordProcess(int index, string word, string result, int vowelsSum){
    bool lastLetterIndex = (index == (word.length() - 1));
    bool noVowelBefore = !isVowel(word[index-1]);
    bool endECase = ((word[index] == 'e') && (lastLetterIndex));

    if(index > (word.length() - 1)){
        /* If function analized all letters it returns result */
        return result;
    }else{
        if(isVowel(word[index])){
            /* If current char is vowel */
            if(noVowelBefore){
                /* And no vowels before */
                if(!endECase){
                    /* And this isn't "e" at the end */
                     result += "OB";
                     vowelsSum++;
                }else{
                    /* End "e" case - for "be" word example */
                    if(vowelsSum == 0){
                        result += "OB";
                    }
                }
            }
        }
        result += word[index];
        index++;
        /* Recursive loop */
        return wordProcess(index, word, result, vowelsSum);
    }
}

/* Checks if current char is vowel */
bool isVowel (char letter){
    letter = tolower(letter);
    string alphabetVowels = "aeiouy";
    bool isVowel = (alphabetVowels.find(letter) != std::string::npos);
    return isVowel;
}

void consoleSettings(){
    setConsoleWindowTitle(programTitle);
    setConsoleEcho(consoleEcho);
}
