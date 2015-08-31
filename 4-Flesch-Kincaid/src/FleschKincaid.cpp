#include <iostream>
#include "console.h"
#include <fstream>
#include "tokenscanner.h"
using namespace std;

// Prototype functions
void getTextAnalysis();
void performTextAnalysis(ifstream &infile);
int numOfSillables(string word);
bool isVovel(char ch);
double calculateGradeLevel(int words,int sentens,int syllables);

int main() {
    
    getTextAnalysis();
    
    return 0;
}

/* This function takes the user name of a text file and sends it to the handler text "performTextAnalysis".
 * Then again it calls itself to perform well. Or in the case of an incorrect input file name.
 */
void getTextAnalysis(){
    string fileName;
    cout << "Enter the file name as (name.txt): ";
    if(cin >> fileName){
        ifstream infile(fileName,ios::in);
        if(infile.is_open()){
            performTextAnalysis(infile);
            cout << endl;
            getTextAnalysis();
          }
        else{
            cout << "File with the same name could not be found. Please try again." << endl;
            getTextAnalysis();
        }
    }
}

/* This function derived from the text analysis file link using class TokenScanner. */
void performTextAnalysis(ifstream &infile){

    TokenScanner scanner(infile);
    // Ignore spaces and '
    scanner.ignoreWhitespace();
    scanner.addWordCharacters("\'");

    int words = 0;
    int sentens = 0;
    int syllables = 0;

    /* Read and analize text token by token. */
    while (scanner.hasMoreTokens()) {
       string token = scanner.nextToken();
       if(isalpha(token[0])){
           syllables += numOfSillables(token);
           words++;
       }
       else if(token[0]=='.'||token[0]=='!'||token[0]== '?'){
           sentens++;
       }
    }

    if(words == 0 && sentens == 0){
        words = 1;
        sentens = 1;
    }

    cout << "Words: " << words << endl;
    cout << "Syllables: " << syllables << endl;
    cout << "Sentences: " << sentens << endl;
    cout << "Grade Level: " << calculateGradeLevel(words,sentens,syllables) << endl;
}

/* Calculate Grade Level formula with pre-defined constants */
double calculateGradeLevel(int words,int sentens,int syllables){

    double res = 0;
    double const c0 = -15.59;
    double const c1 = 0.39;
    double const c2 = 11.8;

    res = c0+c1*((double)words/sentens)+c2*((double)syllables/words);

    return res;
}

/* Calculate number of sillables in token */
int numOfSillables(string word) {

    int res = 0;

    for (int i = 0; i < word.length(); i++) {
        char ch = tolower(word[i]);
        if (isVovel(ch)) {
            if (i == 0) {
                res++;
            } else if (ch == 'e' && i != word.length() - 1 && !isVovel(word[i - 1])) {
                res++;
            } else if (i > 0) {
                if (ch != 'e' && !isVovel(word[i - 1])) {
                    res++;
                }
            }

        }
    }

    if (res == 0) {
        res = 1;
    }

    return res;
}

/* Check symbol is vovel */
bool isVovel(char ch){

    bool res = false;

    switch (ch) {
        case 'a': case 'e': case 'y': case 'i': case 'o':  case 'u':
            res = true;
            break;
        default:
            res = false;
            break;
    }

    return res;
}
