#include <iostream>
#include <fstream>
#include <iomanip>
#include "console.h"
#include "strlib.h"
using namespace std;


/*
 * Prompts the user for a filename and tries to open file. In an unsuccessful attempt
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
 * Makes calculations of number of syllables, words and sentences in the passed string.
 * @param string takes the line where makes calculations.
 * @params int take a number of words, sentences and syllables in this sequence.
 */
void processingLine(string &, int &, int &, int &);

/*
 * Removes extra spaces between words in passed line.
 */
void removeExtraSpaces(string &);

/*
 * Checks: is this a single-character punctuation.
 * @param string takes a line where makes checking passed charecter
 * and also next and previous charecters.
 * @param int takes a possition of a checking character.
 */
bool isASingleCharacterPunctuation(string &, int);

/*
 * Checks whether there is a vowel before the letter.
 * @param string takes the line where cheks belonging vowel to one syllable.
 * @param int takes a possition of the letter in the line which is cheked.
 */
bool isOneVowel(string &, int);

/*
 * Takes a character as a parameter and checks it for belonging to vowel.
 */
bool isVowel(char);

/*
 * Checks: is this the end of the sentence or not.
 * @param string takes a line where makes checking passed charecter and next charecter.
 * @param int takes a possition of a checking character.
 */
bool isSentences(string &, int);


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
    string line = "";
    while (getline(readFile, line)) {
        if(line != ""){ // checks for empty string
            processingLine(line, numWords, numSentences, numSyllables);
        }
    }
    readFile.close();
    if (numWords < 1){
        numWords = 1; // to avoid division by zero equate number of words to one
    }
    if (numSentences < 1){
        numSentences = 1; // to avoid division by zero equate number of sentences to one
    }
    cout << numSyllables << " -> " << numWords << " -> " << numSentences << endl;
    return C_0 + C_1*(((double)numWords)/numSentences) + C_2*(((double)numSyllables)/numWords);
}


void processingLine(string &line, int &numWords, int &numSentences, int &numSyllables){
    int numSyllablesInWord = 0; //for counting number of syllables in one word
    removeExtraSpaces(line);
    line = " " + line; // add one space to the begining of the line for easier counting (to be within the string)
    for(int i = 1; i < line.length() - 1; ++i){ // loop iterates from the second to the penultimate character, because at the beginning and the end are the spaces
        if(isspace(line[i])){
            ++numWords;
            numSyllablesInWord = 0;
        }
        if (isASingleCharacterPunctuation(line, i)){
             --numWords;
        }
        if(isSentences(line, i)){
            ++numSentences;
        }
        if(isOneVowel(line, i)){
            if((tolower(line[i]) == 'e') && (!isalpha(line[i+1])) && (numSyllablesInWord > 0)){
                continue;
            }
            else {
                ++numSyllables;
                ++numSyllablesInWord;
            }
        }
    }
    ++numWords; // accept that the end of the line is the end of a word too and increase the number of words.
}


void removeExtraSpaces(string &line){
    line = trim(line) + " "; // add one space to the end of the line for easier checking (to be within the string)
    for(int i = 0; i < line.length() - 1; ++i){
        if(isspace(line[i]) && (isspace(line[i+1]))){
            line.erase(i, 1); //if there are two or more consecutive spaces that remove unwanted one
            --i; // return the iterator by one ago
        }
    }
}

//Checks whether a vowel before another vowel
bool isOneVowel(string & line, int possition){
    return ((isVowel(tolower(line[possition]))) && (!isVowel(tolower(line[possition - 1]))));
}


bool isVowel(char letter){
    string vowels = "aeiouy";
    for (char vowel : vowels){
        if (letter == vowel){
            return true;
        }
    }
    return false;
}


bool isASingleCharacterPunctuation(string &line, int possition){
    return ((ispunct(line[possition])) && (isspace(line[possition - 1])) && (isspace(line[possition + 1])));
}


bool isSentences(string & line, int possition){
    string punctuationMarks = ".?!"; //punctuation at the end of the sentence
    for (char mark : punctuationMarks){
        /*
         * checks whether a character is on a passed position of punctuation
         * from a predefined list and checks the next character whether it is a space
         * or quotes. Thus determine the approximate number of sentences.
         */
        if (((line[possition] == mark) && (isspace(line[possition + 1])))
                || ((line[possition] == mark) && (line[possition + 1] == '"'))){
            return true;
        }
    }
    return false;
}
