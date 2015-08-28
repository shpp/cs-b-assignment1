#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "console.h"
#include "strlib.h"
#include "tokenscanner.h"
using namespace std;


/*
 * Prompts the user for a filename and tries to open file. If an unsuccessful attempt
 * to open a file again prompts the user for a filename. Otherwise returns a filename.
 */
string requestForFileName(ifstream &);

/*
 * Calculates the complexity of the reading text by the formula:
 * C_0 + C_1*(numWords)/numSentences) + C_2*(numSyllables)/numWords)
 * where C_0, C_1, C_2 are constants.
 */
double fleschKincaidGradeLevelTest(ifstream &);

/*
 * Checks whether an apostrophe is a part of the contraction of words.
 * @param string takes a token and checks it.
 * @param TokenScanner allows to read the following token.
 * @params int takes a number of words by reference for counting.
 */
void checkForContractionOfWords(TokenScanner &, string &, int &);

/*
 * Makes calculations the approximate number of the syllables in the word.
 * @param string takes the token in which which counted the syllables.
 * @params int takes a number of syllables by reference for counting.
 */
void countingSyllables(string &, int &);

/*
 * Checks whether there is a vowel before the letter.
 * @param string takes a token where cheks belonging vowel to one syllable.
 * @param int takes a possition of the letter in the token which is cheked.
 */
bool isOneVowel(string &, int);

/*
 * Takes a character as a parameter and checks it for belonging to vowel.
 */
bool isVowel(char);


/*
 * Checks: is this the end of the sentence or not by checking
 * whether a token is such punctuation mark which indicate the end of a sentence.
 * @param string takes a token and checks it.
 * @param TokenScanner allows to read the following token.
 * @params int takes a number of sentences by reference for counting.
 */
void countingSentences(TokenScanner &, string &, int &);

/*
 * Checks whether a token is such punctuation mark which indicate the end of a sentence.
 * @param string takes a token which is a punctuation mark and
 * compares it with punctuation marks that indicate the end of a sentence.
 */
bool isTheEndOfSentenceChar(string &);


/*
 * Creats object for reading file. Prompts the user for a filename and opens it.
 * Displays result of calculation the complexity of the text from open file.
 */
int main() {
    ifstream readFile;
    requestForFileName(readFile);
    cout << "Grade level of this text = " <<  setprecision(2)
         << fleschKincaidGradeLevelTest(readFile) << endl;
    return 0;
}


string requestForFileName(ifstream & readFile){
    while (true){
        string fileName = "";
        cout << "Please, enter file name: " << endl;
        cin >> fileName;
        readFile.open(fileName.c_str()); //leads a string to a c-style to open a file
        if(readFile){
            return fileName;
        }
        readFile.clear(); // resets the status indecator in the stream for reuse it.
        cout << "The file can not be found. Check the correctness of the file name." << endl;
    }
}


double fleschKincaidGradeLevelTest(ifstream & readFile){
    double C_0 = -15.59, C_1 = 0.39, C_2 = 11.8; // constants for calculation the complexity of the text
    int numWords = 0, numSentences = 0, numSyllables = 0;
    TokenScanner scanner(readFile); //Initializes a scanner object to read from file by tokens.
    while (scanner.hasMoreTokens()) {
        scanner.ignoreWhitespace(); //skip whitespace characters.
        string token = scanner.nextToken();
        if(isalpha(token[0])){
            countingSyllables(token, numSyllables);
            ++numWords;
        }
        if(ispunct(token[0])){
            checkForContractionOfWords(scanner, token, numWords);
            countingSentences(scanner, token, numSentences);
        }
    }
    readFile.close();

    if (numWords < 1){
        numWords = 1; // to avoid division by zero equate number of words to one
    }
    if (numSentences < 1){
        numSentences = 1; // to avoid division by zero equate number of sentences to one
    }

    // displays the results counting of syllables, words and sentences
    cout << "Number of syllables = " << numSyllables << endl;
    cout << "Number of words = " <<numWords << endl;
    cout << "Number of sentences = " << numSentences << endl;

    //return the result of calculation complexity of the text by the given formula
    return C_0 + C_1*(((double)numWords)/numSentences) + C_2*(((double)numSyllables)/numWords);
}


void countingSyllables(string &token, int &numSyllables){
    int numSyllablesInWord = 0; //for counting number of syllables in one word
    if(isVowel(tolower(token[0]))){ // checks whether the first letter is a vowel
        ++numSyllables;
        ++numSyllablesInWord;
    }
    if(token.length() > 1){ // if length of the token more than one then check the rest of the charecters
        for(int i = 1; i < token.length(); ++i){
            if(isOneVowel(token, i)){
                ++numSyllables;
                ++numSyllablesInWord;
            }
        }
        /*
         * Reduced the total number of syllables by one in next cases:
         * - if the last character is a letter 'e' and the previous character is a consonant
         *   moreover the number of syllables in this token more than one;
         * - if a token is a part of a contraction of the words, such as "..'ve" or "..'re"
         */
        if(((tolower(token[token.length() - 1]) == 'e') && (!isVowel(token[token.length() - 2])) && (numSyllablesInWord > 1))
                || ((toLowerCase(token) == "re") || (toLowerCase(token) == "ve"))){
            --numSyllables;
        }
    }
    return;
}



//Checks whether a vowel before another vowel
bool isOneVowel(string & line, int possition){
    return ((isVowel(tolower(line[possition]))) && (!isVowel(tolower(line[possition - 1]))));
}


bool isVowel(char letter){
    string vowels = "aeiouy"; // a list of vowels and plus charecter 'y'
    for (char vowel : vowels){
        if (letter == vowel){
            return true;
        }
    }
    return false;
}


void checkForContractionOfWords(TokenScanner & scanner, string &token, int &numWords){
    /*
     * If the token is an apostrophe then check whether the next token (if it exists)
     * is a part of a contraction of the words. To do this, read the next token and
     * check it for compliance with the following conditions:
     *  - a token is a single letter and it is a consonant (to exclude the following contraction: "..'s", "..'t", "..'d" and etc);
     *  - a token is a such contraction of the words as "..'ve", "..'re" or "..'ll".
     *  if one of these conditions is true then reduce the number of words by one.
     */
    if((token == "'") && (scanner.hasMoreTokens())){
        string nextToken = scanner.nextToken();
        if(((nextToken.length() == 1) && (tolower(!isVowel(nextToken[0]))))
                || (toLowerCase(nextToken) == "re")
                        || (toLowerCase(nextToken) == "ve")
                                || (toLowerCase(nextToken) == "ll")){
                --numWords;
            }
        scanner.saveToken(nextToken); // read token put back
    }
}


void countingSentences(TokenScanner &scanner, string &token, int &numSentences){
    /*
     * If the token is one of the punctuation marks which indicate the end of a sentence
     * then read the next token (if it exists) and check it for the same.
     * If the next token is not a punctuation mark which indicate the end of a sentence
     * then increase the number of sentences by one. If passed token was the last one
     * then also increase the number of sentences by one.
     */
    if(isTheEndOfSentenceChar(token)){
        if(scanner.hasMoreTokens()){
            string nextToken = scanner.nextToken();
            if(!isTheEndOfSentenceChar(nextToken)){
                scanner.saveToken(nextToken);  // read token put back
                ++numSentences;
            }
        }
        else{
            ++numSentences;
        }
    }
}


bool isTheEndOfSentenceChar(string & token){
    string punctuationMarks = ".?!"; //punctuation at the end of the sentence
    //return true if passed token was found in the list otherwise retutn false
    return (punctuationMarks.find(token) != string::npos);
}
