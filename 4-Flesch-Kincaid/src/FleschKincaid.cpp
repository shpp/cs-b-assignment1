#include <iostream>
#include "console.h"
#include <iostream>
#include <fstream>
#include <string>
#include "tokenscanner.h"

using namespace std;

string vowels="aeiouy";

/**
 * @brief getFName takes from user name of file to work.
 * @return filename as string
 */
string getFName(){
    string fname;
    while (true) {
        cout<<"Enter file name: ";
        getline(cin,fname);
        ifstream fileIn(fname,ios::in); //ios::nocreate
        if(fileIn.is_open()){
            break;
        } else {
            cout<<"Such file name is wrong." << endl;
        }
    }
    return fname;
}

/**
 * @brief countSyllables - count number of syllables in word
 * @param word - word, in which count syllables
 * @return number of syllables as int
 */
int countSyllables(string word){
    int res=0;

    bool lastCharVowel=false;

    for(int i=0;i<word.length();i++){

        char currentChar=tolower(word[i]);

        if (vowels.find(currentChar)!=string::npos){
            if(!lastCharVowel){
                if(!((currentChar=='e')&&(i==(word.length()-1)))){
                    res++;
                }
            }
            lastCharVowel=true;
        } else {
            lastCharVowel=false;
        }
    }
    if(res==0)res=1; // becouse all words have at least 1 syllable
    return res;
}

int main() {

    string fname=getFName();

    ifstream fileIn(fname,ios::in); //ios::nocreate

    TokenScanner scanner;
    scanner.setInput(fileIn);
    //scanner.ignoreWhitespace();
    string ignoringChars;
    ignoringChars= "\'";
    scanner.addWordCharacters(ignoringChars);

    int numWords=0, numCentences=0, numSyllabels=0;

    while (scanner.hasMoreTokens()) {
       string token = scanner.nextToken();
       cout << token;
       if(!isalpha(token[0])==0){
           numWords++;
           numSyllabels+=countSyllables(token);
       } else if ((token[0]=='.')||(token[0]=='!')||(token[0]=='?')){
           numCentences++;
       }
    }

    cout << "Syllables: " << numSyllabels << ", words: " << numWords << ", centences: " << numCentences << endl;

    double c0=-15.59, c1=0.39, c2=11.8;
    double k1=double(numWords)/numCentences;
    double k2=double(numSyllabels)/numWords;
    double grade=c0+c1*k1+c2*k2;

    cout <<"Grade: " << grade;

    return 0;
}
