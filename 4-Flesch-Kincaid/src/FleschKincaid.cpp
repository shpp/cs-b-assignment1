#include <iostream>
#include <fstream>
#include "simpio.h"
#include "filelib.h"
#include "console.h"
#include "tokenscanner.h"


using namespace std;

/* Functions prototypes */
string fileInput(string line);
void readFileProcess(istream & infile, string fileName);
void scanCPlusPlusTokens(TokenScanner & scanner);
bool isEndSentenceCharacter(string word);
void simpleTokenProcess(string word, int & syllablesCounter,
                                     int & wordsCounter,
                                     int & sentencesCounter);
int syllablesCountProcess(int index, string word, int result);
bool isVowel (char letter);
const bool showDebug = false;
/* FleschKincaid equation constatnts */
const double C0 = -15.59;
const double C1 = 0.39;
const double C2 = 11.8;
/* Console settings */
void consoleSettings();
const double chance = 0.5;
const string programTitle = "FleschKincaid";
const bool consoleEcho = false;

int main() {
    /* Adjust concole settings for programm */
    consoleSettings();
    /* User enters name of file from project directory */
    string fileName = fileInput("Enter file name: ");

    /* Prepare main input stream object   */
    ifstream infile;
    /* Lunch stream of file reading   */
    infile.open(fileName.c_str());
    /* Main program process */
    readFileProcess(infile, fileName);
    /* If whole file is read program closes stream */
    infile.close();

    return 0;
}

/* Makes file reading and shows results of process  */
void readFileProcess(istream & infile, string fileName){
        if (infile.fail()){
            /* Informs about problems at start of file reading */
            cout << "FAIL" << endl;
        }else{
            /* Main process
             * Scans input stream by  TokenScanner object  */
            TokenScanner scanner;
            scanner.setInput(infile);
            /* Settings of scanner */
            scanCPlusPlusTokens(scanner);
            /* Main results counters */
            int syllablesCnt = 0;
            int wordsCnt = 0;
            int sentencesCnt = 0;
            /* Main process loop */
            while (scanner.hasMoreTokens()) {
                /* Take next token from scanner */
                string token = scanner.nextToken();
                /* Main sorting and counters incrementing */
                simpleTokenProcess(token, syllablesCnt, wordsCnt, sentencesCnt);
            }
            /* End of file detection */
            if(infile.fail()){
                if(infile.eof()){
                    /* Case of empty file have return some results */
                    if(sentencesCnt == 0){
                        sentencesCnt++;
                    }
                    if(wordsCnt == 0){
                        wordsCnt++;
                    }
                }
            }
            /* Process results printing to user */
            cout << "IN FILE: " << fileName << endl;
            cout << "WORDS = " << wordsCnt << endl;
            cout << "SYLLABLES = " << syllablesCnt << endl;
            cout << "SENTENCES = " << sentencesCnt << endl;
            /* Result equation */
            double result = 0;
            result += C0;
            result += (C1* wordsCnt/ sentencesCnt);
            result += (C2* syllablesCnt / wordsCnt);
            /* Result printing */
            cout << "GRADE LEVEL = " << result;
    }
}

/* Shows this word syllables
 * @word is recognized as valid word yet  */
int syllablesCountProcess(int index, string word, int result){
    bool lastLetterIndex = (index == (word.length() - 1));
    bool noVowelsBefore = !isVowel(word[index-1]);
    bool endECase = ((word[index] == 'e') && (lastLetterIndex));

    if(index > (word.length() - 1)){
            return result;
    }else{
        if(isVowel(word[index])){
            if(noVowelsBefore){
                if(!endECase){
                     result++;
                }else{
                    /* For cases like "me", "be" words - approve 1 syllable */
                    if(result == 0){
                        result++;
                    }
                }
            }
        }else{
            /* For cases like "txt", "str" words - approve 1 syllable */
            if(lastLetterIndex && (result == 0)){
                result++;
            }
        }
        /* Turn function to next letter to analize */
        index++;
        /* Recursive loop of function */
        return syllablesCountProcess(index, word, result);
    }
}

/* Defines if current char is vowel  */
bool isVowel (char letter){
    letter = tolower(letter);
    string alphabetVowels = "aeiouy";
    bool isVowel = (alphabetVowels.find(letter) != std::string::npos);
    return isVowel;
}

/* Sort tokens and count program parameters -
 * syllables, words, sentences.
 * Supose that every token which starts from letter is word
 * Supose that every symbol like "." "!" or "?" is end of sentencse marker */
void simpleTokenProcess(string token, int & syllablesCounter,
                                      int & wordsCounter,
                                      int & sentencesCounter){
    /* Tokens sorting */
    if(isalpha(token[0])){
        /* Words detection */
        int syllables = syllablesCountProcess(0, token, 0);
        syllablesCounter += syllables;
        wordsCounter++;
        if(showDebug){
            cout << wordsCounter << " " << token << " = " << syllables << endl;
        }
    }
    else if ((token.length() > 1) && (token[0] == '\'') && (isalpha(token[1]))){
        /* Case of quotes "'word" tokens counts as word */
        if(showDebug){
            cout <<  token << endl;
        }
        int syllables = syllablesCountProcess(1, token, 0);
        syllablesCounter += syllables;
        wordsCounter++;
    }
    else if ((token.length() > 2) && (token[0] == '-') && (isalpha(token[2]))){
        /* Case of "--ab" tokens counts as word */
        if(showDebug){
            cout <<  token << endl;
        }
        int syllables = syllablesCountProcess(1, token, 0);
        syllablesCounter += syllables;
        wordsCounter++;
    }
    else if (isEndSentenceCharacter(token)){
        /* Sentences detection */
        sentencesCounter++;
        if(showDebug){
            cout <<  token << " ---------- end symbol " << sentencesCounter << endl;
        }
    }else{
        if(!(ispunct(token[0]))){
            if(showDebug){
                cout << token << " --------------------------- SOMETHING "  << endl;
            }
            if(isdigit(token[0])){
                wordsCounter++;
            }
        }
    }
}

/* Recognize if this token is end of sentence symbol  */
bool isEndSentenceCharacter(string token){
    if(token == "..."){
        return true;
    }else if(token == "."){
        return true;
    }else if(token == "!"){
        return true;
    }else if(token == "?"){
        return true;
    }else{
        return false;
    }
}

/* Sets token scanner features */
void scanCPlusPlusTokens(TokenScanner & scanner) {
    scanner.ignoreWhitespace();
    /* To recognize words like "isn't" */
    scanner.addWordCharacters("'");
    /* Don't recognize words like "two-way" */
    //scanner.addWordCharacters("-");
    /* To recognize symbol "..." like end of sentence */
    scanner.addOperator("...");

    /* Don't return strings with quotations */
    //scanner.scanStrings();
    /* Don't return numbers */
    //scanner.scanNumbers();
}

/* User input function
 * Defines if this file exist in project directory */
string fileInput(string enterText){
    while(true){
        string result = getLine(enterText);
        if(fileExists(result)){
            return result;
            break;
        }else{
            cout << "Unfortunately your input is failed" << endl;
        }
    }
}

/* Make console output window more convenient */
void consoleSettings(){
    setConsoleWindowTitle(programTitle);
    setConsoleEcho(consoleEcho);
}
