#include <iostream>
#include <fstream>
#include <ctype.h>
#include "tokenscanner.h"
#include "simpio.h"
#include "console.h"
using namespace std;

// Flesch-Kincaid constants
const double C0 = -15.59;
const double C1 = 0.39;
const double C2 = 11.8;

int main() {
    ifstream input;
    string filename;
    int word = 0, sentence = 0, syllable = 0;
    string vowels = "aeoiuyAEOIYU";

    while(true){
        filename = getLine("Enter the filename to be read: ");
        input.open(filename.c_str());
        if(input.fail()) {
            cout << "ERROR: file can't open!" << endl;
            input.clear();
        } else break;
    }

    // Set up tokenscanner
    TokenScanner scanner(input);
    scanner.addWordCharacters("'"); // "He's", "I'm" and etc. are tokens
    scanner.addWordCharacters("-"); // "A-1" is a token
    scanner.ignoreWhitespace();

    // Scanning using the suggested pattern
    while (scanner.hasMoreTokens()) {
        int localSyllable = 0;
        TokenType type = WORD;
        string token = scanner.nextToken();

        if (type == scanner.getTokenType(token) && isalpha(token[0])) {
            word++;
            if (vowels.find(token[0]) != string::npos) localSyllable++; {
                for (int i = 1; i < token.length(); i++) {
                    if (vowels.find(token[i-1]) == string::npos && vowels.find(token[i]) != string::npos) {
                        localSyllable++;
                    }
                }
                if (token[token.length() - 1] == 'e') {
                    localSyllable--;
                }
                if (localSyllable == 0) {
                    localSyllable = 1;
                }
                syllable += localSyllable;
            }
        }

        /* Periods, exclamation points, and question marks
         * delimit end of sentences
         */
        else if (token == "." || token == "!" || token == "?") {
            sentence++;
        }
    }

    if (word == 0) word = 1;
    if (sentence == 0) sentence = 1;

    /* The resulting number gives an estimate of the grade level
     * necessary to understand a text
     */
    double grade = C0 + C1*(double(word)/sentence) + C2*(double(syllable)/word);

    cout << "Words: " << word << endl;
    cout << "Sentences: " << sentence << endl;
    cout << "Syllables: " << syllable << endl;
    cout << "Grade: " << grade << endl;

    return 0;
}
