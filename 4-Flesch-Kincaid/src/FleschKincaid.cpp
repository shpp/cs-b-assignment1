#include <iostream>
#include "console.h"
#include <fstream>
#include "tokenscanner.h"
using namespace std;

//Function prototypes
void settingFile();
void fleschKincaid(ifstream &infile);
int syllablesIn(string word);
bool checkVowels(char letter);
double grade(int words,int sentens,int syllables);


int main() {
settingFile();
    return 0;
}

/*The function prompts the user for a filename.
Checks whether there is such a file.
If there is the object -ifstream infile-(The object read from the stream file) creates the file and
passes it to the function fleschKincaid */
void settingFile(){
    string s;
    cout<<"Enter input file name: ";
    if(cin>>s){
        ifstream infile(s,ios::in);
        if(infile.is_open()){
            fleschKincaid(infile);
          }
        else{
            cout<<"This file does not exist"<<endl;
            settingFile();
        }
    }
}

/*The function takes an object by reference,
and creates for him an object TokenScanner scanner*/
void  fleschKincaid(ifstream &infile){

    TokenScanner scanner(infile);
//Definitions of symbols are ignored when scanning
    scanner.ignoreWhitespace();
    scanner.addWordCharacters("\'");

/*Create a variable to store the number of words,
sentences and syllables.*/
    int words = 0;
    int sentens = 0;
    int syllables = 0;

    /*Reading the file using a TokenScanner. Finding token.
    Determination of the number of words and syllables therein.
    As well as determining the number of sentences.*/
       while (scanner.hasMoreTokens()) {
          string token = scanner.nextToken();
          if(isalpha(token[0])){
              syllables += syllablesIn(token);
              words++;        
          }
          else if(token[0]=='.'||token[0]=='!'||token[0]== '?'){
              sentens++;            
          }
       }

       if(words == 0 && sentens == 0){
           words = 1;
           sentens =1;
       }
/*Displays the number of words, sentences, syllables and Grade Level.*/
       cout<<"Words: "<<words<<endl;
       cout<<"Syllables: "<<syllables<<endl;
       cout<<"Sentences: "<<sentens<<endl;
       double gradeLevel = grade(words,sentens,syllables);
       cout<<"Grade Level: "<<gradeLevel<<endl;
}


//Determination of the number of syllables
 int syllablesIn(string word) {
      int countWSyllables = 0;
      for (int i = 0; i < word.length(); i++) {
          char letter = tolower(word[i]);
          if (checkVowels(letter)) {
              if (i == 0) {
                  countWSyllables++;                 
              } else if (letter == 'e' && i != word.length() - 1 && !checkVowels(word[i - 1])) {
                  countWSyllables++;                  
              } else if (i > 0) {
                  if (letter != 'e' && !checkVowels(word[i - 1])) {
                      countWSyllables++;
                  }
              }

          }
      }
      if (countWSyllables == 0) {
          countWSyllables = 1;
      }
      return countWSyllables;
  }

//Determination of whether the letter is a vowel
  bool checkVowels(char letter) {
       if (letter == 'a' || letter == 'e' || letter == 'y'
               || letter == 'i' || letter == 'u' || letter == 'o') {
           return true;
       }
       return false;
   }

//Calculation Grade Level formula with pre-defined constants.
  double grade(int words,int sentens,int syllables){
    double grade=0;
    double const c0=-15.59;
    double const c1=0.39;
    double const c2=11.8;
    grade = c0+c1*((double)words/sentens)+c2*((double)syllables/words);
    return grade;
  }
