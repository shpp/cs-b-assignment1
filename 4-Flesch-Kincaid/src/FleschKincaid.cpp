#include <iostream>
#include <fstream>
#include "strlib.h"
#include "console.h"
#include "tokenscanner.h"
using namespace std;

/**
 * Request file name and open file if name is valid.
 *
 * @param inputFile - File for open.
 */
void openFile(ifstream &inputFile) {
    string fileName;
    while (true) {
        cout << "Enter a file name: ";
        cin >> fileName;
        inputFile.open(fileName);
        if (inputFile.is_open())
            break;
        cout << "File name is incorrect." << endl;
    }
    cout << "File is opened." << endl;
}

/**
 * Define the letter is the vowel.
 *
 * @param letter - Current letter.
 * @return true if the letter is vowel or return false in other case.
 */
bool isVowel(char letter) {
    return ((letter == 'a') || (letter == 'e') || (letter == 'i') ||
                (letter == 'o') || (letter == 'u') || (letter == 'y'));
}

/**
 * Define the token is the word.
 *
 * @param token - Token for check.
 * @return - 1 if the token is the word or return 0 in other case.
 */
int addWords(string token) {
    return ((isalpha(token[0])) || ((token[0] == '\'') && (token.length() != 1))) ? 1 : 0;
}

/**
 * Define the token is the end of the sentence punkt.
 *
 * @param token - Token to check.
 * @return - 1 if the token is the end of the sentence punkt or return 0 in other case
 */
int addSentences(string token) {
    return ((token[0] == '.') || (token[0] == '?') || (token[0] == '!')) ? 1 : 0;
}

/**
 * Define count of the syllables in the token.
 *
 * @param token - Token to check.
 * @return - Count of the syllables in the token.
 */
int addSyllables(string token) {
    int numSyllables = 0;
    token = toLowerCase(token);
    for (int i = 0; i < token.length(); i ++) {
        // Keep out consonants letters.
        if (!isVowel(token[i]))
            continue;
        // Keep out last "e" letter.
        if ((i == token.length() - 1) && (token[i] == 'e'))
            continue;
        // Keep out double vowel letter.
        if ((i != 0) && (isVowel(token[i - 1])))
            continue;
        numSyllables ++;
    }
    // Word must contain at least one syllable.
    return ((numSyllables == 0) && (token.length() != 1)) ? 1 : numSyllables;
}

/**
 * Read file by tokens and calculate grade of the text.
 *
 * @param inputFile - File for read.
 * @return - Calculated grade of the text.
 */
double getGrade(ifstream &inputFile) {
    const double c0 = -15.59, c1 = 0.39, c2 = 11.8;
    int numWords = 0, numSentences = 0, numSyllables = 0;
    TokenScanner scanner(inputFile);
    // Ignore white space tokens.
    scanner.ignoreWhitespace();
    // Set the "'" symbol like the part of the word.
    scanner.addWordCharacters("'");
    cout << "Do file processing..." << endl;
    // Read file by tokens.
    while (scanner.hasMoreTokens()) {
          string token = scanner.nextToken();
          numWords += addWords(token);
          numSentences += addSentences(token);
          numSyllables += addSyllables(token);
          // For show debugging information uncomment folow line.
          //cout << token << " w: " << addWords(token) << " sen: " << addSentences(token) << " syl: " << addSyllables(token) << endl;
    }
    cout << "Found " << numWords << " words, " << numSentences << " sentences and " << numSyllables <<
            " syllables." << endl;
    return c0 + c1 * numWords / numSentences + c2 * numSyllables / numWords;
}

/**
 * Close file.
 *
 * @param inputFile - File for close.
 */
void closeFile(ifstream &inputFile) {
    inputFile.close();
    cout << "File is closed." << endl;
}

int main() {
    ifstream inputFile;
    openFile(inputFile);
    double grade = getGrade(inputFile);
    closeFile(inputFile);
    cout << "Calculated grade of this text is " << grade << "." << endl;
    return 0;
}
