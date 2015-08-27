#include <iostream>
#include "console.h"
#include <fstream>
#include "strlib.h"
#include "tokenscanner.h"
using namespace std;

string promptUserForFile(ifstream & infile, string prompt); //ask for input file
int syllableCount(string line); //Count syllables in line
int wordCount(string line);     //Count number of words in line
int sentenceCount(string line); //Count number of sentences in line
bool vowelCheck(char i);        //Check if char is vowel
bool commaCheck(string i);      //Check if char is comma or else signs
bool wordCheck(string i);       //Check if it is word not symbol
bool sentenceCheck(string i);   //Check if it end of sentence ("." "!" "?")
int syllableCountHelp(string token); //Count syllables in line ( to make syllableCount easy to read)

int main() {

    ifstream infile;
    promptUserForFile(infile, "Enter filename: ");
    //infile.open("RosesAreRed.txt");
    string line;
    double syllsumary =0; //count syllables
    double words =0;      //count words
    double sentences = 0; //count sentences
    while (getline(infile,line)){
        TokenScanner scanner(line);
        while (scanner.hasMoreTokens()) {
            scanner.ignoreWhitespace();               //we ignore whitespace - " ".
            string token = scanner.nextToken();
            //cout<<line<<endl;
            syllsumary += syllableCount(token);
            words += wordCount(token);
            sentences+=sentenceCount(token);
        }
    }
    float testRes = (-15.59)+( (words/sentences)*0.39) + (11.8 * (syllsumary/words));
    cout<<"Number of words in text is - "<<words<<endl;
    cout<<"Number of sylables in text is - "<<syllsumary<<endl;

    cout<<"Number of sentences in text is - "<<sentences<<endl;
    cout<<"Total grade - "<<testRes<<" class."<<endl;




    return 0;
}

int syllableCount(string line){
    int countSyll = 0;
    int numToken = 0;
    int e = 0;
    line = toLowerCase(line);
    //check if string "token" not equals ",.!?"
    //if not equals then we can counr syllables
    if(commaCheck(line)==false){
        numToken = syllableCountHelp(line);
        countSyll+=numToken;
    }
    return countSyll;
}

bool vowelCheck(char i){
    bool res;
    string vowelLetter = "eaiouy";
    for(int j = 0; j < vowelLetter.length();j++){
        if(i==vowelLetter[j]){
            res = true;
            break;
        }else{
            res = false;
        }
    }
    return res;
}

bool commaCheck(string i){
    bool res;
    string commaSigns = ",.!?1234567890 ";
    for(int j = 0; j < commaSigns.length();j++){
        if(i[0]==commaSigns[j]){
            res = true;
            break;
        }else{
            res = false;
        }
    }
    return res;
}

//count syllable in one token (word)
int syllableCountHelp(string token){
    int res = 0 ;
    string word = toLowerCase(token);
    int wLen = word.length();
    char last = word[wLen-1];
    int cheking = 0;            //need to check if word ends on "e" letter
    //check if entered word end with "e", if true - set cheking = 1;
    if(last == char(101)){
        cheking =1;
    }
    //start change entered word.
    //compare entered word with vowelletter char by char
    for(int i = 0; i<word.length();i++){
        if(i!=0){
            if(vowelCheck(word[i])==true && vowelCheck(word[i-1])==false ){
                res++;
            }
        }
    }
    if(cheking == 1){
        res--;
    }
    if(res<=0){
        res=1;
    }

    cout<< word <<" - token has - "<<res<<" syllabels."<<endl; //to view result of counting
    return res;

}

string promptUserForFile(ifstream & infile, string prompt ){
    while(true){
        cout<< prompt;
        string filename;
        getline(cin, filename);
        infile.open(filename.c_str());
        if(!infile.fail()) return filename;
        infile.clear();
        cout<<"UNABLE TO OPEN FILE! Try again."<<endl;
        if(prompt == ""){
            prompt = "Input filename: ";
        }
    }
}

int wordCount(string line){
    int res = 0;
    line = toLowerCase(line);
    if(wordCheck(line)==true){
        res++;
    }
    return res;
}

int sentenceCount(string line){
    int res = 0;
    line = toLowerCase(line);
    if(sentenceCheck(line)==true){
        res++;
        //               cout<<"word token is - "<< token << endl;
        //               cout<< "res is  = "<< res<<endl;
    }
    return res;
}

//Check if it end of sentence ("." "!" "?")
bool sentenceCheck(string i){
    bool res;
    char b = i[0];
    string alphabet = ".!?";
    for(int j = 0; j < alphabet.length();j++){
        if(b==alphabet[j]){
            res = true;
            break;
        }else{
            res = false;
        }
    }
    return res;
}

bool wordCheck(string i){
    bool res;
    char b = i[0];
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for(int j = 0; j < alphabet.length();j++){
        if(b==alphabet[j]){
            res = true;
            break;
        }else{
            res = false;
        }
    }
    return res;
}

