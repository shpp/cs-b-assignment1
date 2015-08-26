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
    int syllsumary =0; //count syllables
    int words =0;      //count words
    int sentences = 0; //count sentences
    while (getline(infile,line)){
      //cout<<line<<endl;
      syllsumary += syllableCount(line);
      words += wordCount(line);
      sentences+=sentenceCount(line);
    }
    double testRes = (-15.59)+(0.39*(words/sentences))+11.8*(syllsumary/words);
    cout<<"Number of sylables in text is - "<<syllsumary<<endl;
    cout<<"Number of words in text is - "<<words<<endl;
    cout<<"Number of sentences in text is - "<<sentences<<endl;
    cout<<"text is good for understaiding for pupils of - "<<testRes<<" class."<<endl;




    return 0;
}

int syllableCount(string line){
    int countSyll = 0;
    int numToken = 0;
    int e = 0;
    line = toLowerCase(line);
    TokenScanner scanner(line);
       while (scanner.hasMoreTokens()) {
          scanner.ignoreWhitespace();               //we ignore whitespace - " ".
          string token = scanner.nextToken();
          //check if string "token" not equals ",.!?"
          //if not equals then we can counr syllables
          if(commaCheck(token)==false){
               numToken = syllableCountHelp(token);
               countSyll+=numToken;
          }
       }
    return countSyll;
}

int wordCount(string line){
    int res = 0;
    line = toLowerCase(line);
    TokenScanner scanner(line);
       while (scanner.hasMoreTokens()) {
          scanner.ignoreWhitespace();               //we ignore whitespace - " ".
          string token = scanner.nextToken();
          if(wordCheck(token)==true){
               res++;
          }
       }
    return res;
}

int sentenceCount(string line){
    int res = 0;
    line = toLowerCase(line);
    TokenScanner scanner(line);
       while (scanner.hasMoreTokens()) {
          scanner.ignoreWhitespace();               //we ignore whitespace - " ".
          string token = scanner.nextToken();
          if(sentenceCheck(token)==true){
               res++;
//               cout<<"word token is - "<< token << endl;
//               cout<< "res is  = "<< res<<endl;
          }
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

bool vowelCheck(char i){
    bool res;
    string vowelLetter = "aiouey";
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
    string commaSigns = ",.!? ";
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
    int res =0;
    int sumSyl = 0;
    int wLen = token.length();
    char last = token[wLen-1];
    //check if entered word end with "e", if true - set cheking = 1;
    if(last == char(101)){
        token = token.substr(0,token.length()-1); //delete last letter "e"
        }
    //start change entered word.
    //compare entered word with vowelletter char by char
    for(int i = 0; i<token.length();i++){
        if(i!=0){
            if(vowelCheck(token[i])==true && vowelCheck(token[i-1])==false ){
                res++;
            }
            if(res==0){res=1;}
        }
    }
    sumSyl =res;
 //   cout<< token <<" - token has - "<<res<<" syllabels."<<endl; //to view result of counting
    return sumSyl;

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
