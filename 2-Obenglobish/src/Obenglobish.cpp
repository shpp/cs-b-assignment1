
/* File: Obenglobish.cpp
 * ---------------------------------------------------------
 *
 * This program asks the user for word in English and translate
 * it to Obenglobish dialect by folowing rule:
 *
 * Add text "od" before every vowel in the English word except
 * vowels that follow other vowels and "e" character that occurs
 * at the end of the word.
 *
 */


#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

/* Functions prototypes */
string obenglobish(string word);
bool isVowel(char ch);
string filterString(string word);
void capitalizeWord(string &word);

/* Main program*/
int main() {
    while (true) {
        string word = getLine("Enter a word: ");
        if (word != "") {
            word = filterString(word);
            cout << word << " -> " << obenglobish(word) << endl;
        }
    }
   return 0;
}

/* Function: obenglobish
 * Usage: cout << word << " -> " << obenglobish(word) << endl;
 * -----------------------------------------------------------
 *
 * Translates received word to Obenglobish using specified rules.
 * Check if the first letter if vowel and add's to result text "ob"
 * and this letter. Than check other letters and if current letter is
 * vowel and before this letter is not vowel add's text "ob" and this letter
 * to the result. Otherwise add's only current letter. Also check last letter
 * and if it "E" dont add's "ob" before it.
 *
 * @param word The word to translate into Obenglobish
 * @return Translated word
 */

string obenglobish(string word){

    const string OB = "ob"; //text to add before vowels

    string result = "";

    for(int i = 0; i < word.length(); i++){

        if(i == 0 ){ //for the first letter in word
            if(isVowel(word.at(i))){
                result += OB + word.at(i);
            }
            else {
                result += word.at(i);
            }

        } else if (i == word.length() - 1) { //for the last letter in word
            if (isVowel(word.at(i)) && word.at(i) != 'E' && word.at(i) != 'e' ){
               result += OB + word.at(i);
            } else {
                result += word.at(i);
            }

        } else { // for other letters
            if (isVowel(word.at(i)) && !isVowel(word.at(i - 1))){
                 result += OB + word.at(i);
            } else {
                result += word.at(i);
            }
        }


    }

    capitalizeWord(result);
    return result;
}


/* Function: filterString
 * Usage: word = filterString(word);
 * -----------------------------------------------------
 *
 * Return received string without non alphabetic symbols
 *
 * @param word The text for filtering
 * @return Filtered text
*/
string filterString(string word){
    string result = "";

    for (int i = 0; i < word.length(); i++ ){
        if(isalpha( word.at(i))){
            result += word.at(i);
        }

    }

    return result;
}

/* Function: isVowel
 * Usage: if(isVowel(word.at(i)))...
 * ----------------------------------------------------
 *
 * Return TRUE if received charecter is vowel
 * and FALSE if no.
 *
 * @param ch Character that will be checked
 * @return Boolean result of the check
 */
bool isVowel(char ch){

    switch (ch) {
    case 'a': case 'e': case 'i': case 'o': case 'u':
    case 'A': case 'E': case 'I': case 'O': case 'U':
        return true;


    default:
        return false;
    }
}

/* Function: capitalizeWord
 * Usage: capitalizeWord(result);
 * ---------------------------------------------------
 *
 * Change text received in link transforming first letter to uppercase
 * and other letters to lowercase
 *
 * @param word Link to string class object that will be capitalized
 */
void capitalizeWord(string &word){

    for(int i = 0; i < word.length(); i++){
        if(i == 0){
            word.at(i) = toupper(word.at(i));
        } else {
            word.at(i) = tolower(word.at(i));
        }
    }

}
