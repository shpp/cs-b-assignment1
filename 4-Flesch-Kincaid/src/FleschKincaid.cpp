#include <iostream>
#include <fstream>
#include <ctype.h>
#include "console.h"
#include "tokenscanner.h"
#include "filelib.h"
#include "string.h"
#include "simpio.h"

using namespace std;

bool isVowel(char letter);
bool isEndOfSentence(char letter);
int countSyllables (string str);
double countGrade(int words, int syllables, int sentences);

int main() {
    ifstream filestream;
    string filename;

    while(filename == ""){
        filename = getLine("Type name of the file: ");
        filestream.open(filename.c_str());
        if(filestream.fail()) {
            cout << "wrong filename" << endl;
            filestream.clear();
            filename = "";
        }
    }

    TokenScanner scanner(filestream);
    scanner.addWordCharacters("'");
    scanner.addWordCharacters("-");
    scanner.ignoreWhitespace();

    int sentence = 0;
    int words = 0;
    int syllables = 0;

    while (scanner.hasMoreTokens()) {
        string token = scanner.nextToken();
        char firstChar = token[0];
        if(isEndOfSentence(firstChar)) {
            sentence++;
        }
        else if(isalpha(firstChar)) {
            words++;
            syllables += countSyllables(token);
        }
    }

    filestream.close();

    cout << "words: " << words << endl;
    cout << "syllables: " << syllables<< endl;
    cout << "sentences: " << sentence << endl;

    double grade = countGrade(words, syllables, sentence);

    cout << "grade level: " << grade << endl;

    return 0;
}

int countSyllables (string str) {
    int currentSyllables = 0;
    for(char ch : str) {
        if(isVowel(ch)) {
            currentSyllables++;
        }
    }
    if(str[str.length() - 1] == 'e') {
        currentSyllables--;
    }
    if(! currentSyllables > 0) {
        currentSyllables = 1;
    }
    return currentSyllables;
}

double countGrade(int words, int syllables, int sentences) {
    const double const0 = -15.59;
    const double const1 = 0.39;
    const double const2 = 11.8;

    double grade = const0 + const1 * (words / sentences) + const2 *  (syllables / words);

    return grade;
}

bool isVowel(char letter) {
    char vowels[6] = {'a','e','i','o','u','y'};
    for (char vowel: vowels) {
        if(letter == vowel)
            return true;
    }
    return false;
}

bool isEndOfSentence(char letter) {
    char sentenceLastChar[] = {'.','!','?'};
    for (char ch: sentenceLastChar) {
        if(letter == ch)
            return true;
    }
    return false;
}

