#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;


/*
 * Makes translation from english to obenglobish "language" by adding
 * "ob" before each spoken vowel (if before vowel is not a vowel,
 * exept 'e' at the end of the word excluding words with single syllable).
 * Takes a string as a parameter to be translated and returns "translation" of this string.
 */
string obenglobish(string);

/*
 * Checks whether there is a vowel before the letter.
 * @param string takes the line by reference where checks belonging vowel to one syllable
 * by checking a previous letter to belong to vowel.
 * @param int takes a position of a letter in the word which is checked.
 */
bool isOneVowel(const string &, int);

/*
 * Takes a character as a parameter and checks whether a character is a vowel.
 */
bool isVowel(char);


/*
 * Adds subword to the text.
 * @ param string& the text passed by reference in which is inserted the subword
 * @ param string the subword which is inserted.
 * @param int the position where to insert the word
 */
void addSubwordToTheWord(string &, string, int);


/*
 * Reads an input line and outputs an entered data with its translation.
 */
int main() {
    while(true){
        string text = getLine("Enter a text for translation: ");
        if (text == "") {
            break;
        }
        string translation = obenglobish(text);
        cout << text << " -> " << translation << endl;
    }
    return 0;
}

string obenglobish (string text){
    text += " "; //add one space to the end of the string for simpler control of the last character
    string subword = "ob"; //declare a string that to be inserted before vowels
    int countOfSyllables = 0; //declare a variable for counts of syllables
    int i = 0;
    if(isVowel(text[i])){
        addSubwordToTheWord(text, subword, i);
        /* iterator moves to the right by the length of the inserted substring plus one for move
         * to the next character after vowel*/
        i += (subword.length() + 1);
        ++countOfSyllables;
    }
    while(i < text.length() - 1){
        if(isOneVowel(text, i)){
            if((tolower(text[i]) == 'e') && (!isalpha(text[i+1])) && (countOfSyllables > 0)) {
                ++i;
            }
            else {
                addSubwordToTheWord(text, subword, i);
                ++countOfSyllables;
                i += (subword.length());//iterator moves to the right by the length of the inserted substring
            }
        }
        if(text[i] == ' '){
            countOfSyllables = 0; // resets the counter to zero when finds a spase (after the space starts a new word)
        }
        ++i;
    }
    return text.substr(0, text.length() - 1); // remove the extra space from the end of the line
}


bool isOneVowel(const string &text, int position){
    return ((isVowel(tolower(text[position]))) && (!isVowel(tolower(text[position - 1]))));
}

bool isVowel(char letter){
    string vowels = "aeiou";
    for(char vowel : vowels){
        if(letter == vowel){
            return true;
        }
    }
    return false;
}


void addSubwordToTheWord(string &text, string subword, int possition){
    text = text.insert(possition, subword);
}


