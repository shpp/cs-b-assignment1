#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

// Function prototypes
string obenglobish (string word);
bool isVowel (char ch);
bool isFollowingVowel(int i, string word);
bool isFinalE(char ch, int i, string word);
string prependOb(string sub);

int main() {
    while (true) {
        string word = getLine("Please enter a word: ");
        if (word == "") break;
        string trans = obenglobish(word);
        cout << word << " -> " << trans << endl;
    }
    return 0;
}

/* This function translates a word from English
 * to Obenglobish, according to the rules
 * specified in the assignment. The translated
 * word is returned as the value of the function.
 */
string obenglobish (string word) {
    string trans = "";
    for (int i = 0; i < word.length(); i ++) { // steps through the word
        char ch = word.at(i);
        if (isVowel(c)){ // standard obenglobish requirement
            if (i == 0){
                cout<<"test";
                result = result + "ob" + c; // if it's the first letter, it can't
                                            // violate either of the two exceptions
            }
            else if (isVowel(word[i-1])){ // rule #1
                result = result + c;
            }
            else if (c == 'e' && i == word.length()-1){	//rule #2
                result = result + c;
            }
            else{
                result = result + "ob" + c;	//meets requirements
            }
        }
        else{
            result = result + c;
        }
    }
    return result;
}

/* Vowel checker
 * Note: 'Y' is not considered a vowel in this implementation.
 */
bool isVowel(char ch){
    if (ch == 'a' ||
        ch == 'e' ||
        ch == 'i' ||
        ch == 'o' ||
        ch == 'u'){
        return true;
    }
    return false;
}
