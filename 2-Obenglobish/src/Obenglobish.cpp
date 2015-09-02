#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

bool isVowel(char letter);
string obenglobish(string word);

int main() {
   while(true){
       string word = getLine("Enter a word: ");
       if(word == "")break;
       string translation = obenglobish(word);
       cout<< word<<" -> "<<translation<<endl;
   }

   return 0;
}

/*Check whether it is a vowel letters.
 * If so it returns true if not returns false*/
bool isVowel(char letter){
    if(letter =='a'||letter =='u'||letter =='i'||letter =='o'|| letter == 'e')
        return true;
    else return false;
}


/***Implementing functions using recursion***/
//Each subsequent recursive call function divides
//the string that the user enters and performs
//actions with each individual Elements line.
string obenglobish(string wordLine){
    string str;
    string word = toLowerCase(wordLine);
    if(word.length()>0){
        if(word[0]=='e'&& word.length()==1){
            str +=word[0];
        }
        else if(isVowel(word[0])&&isVowel(word[1])){
            str = str+string("ob")+word[0] + word[1] + obenglobish(word.substr(2,word.length()-2));
        }
        else if(isVowel(word[0])&&!isVowel(word[1])){
            str = str+string("ob")+ word[0] + obenglobish(word.substr(1,word.length()-1));
        }

        else if(!isVowel(word[0])&& word.length() != 1){
            str +=word[0] + obenglobish(word.substr(1,word.length()-1));
        }
        else{
            str +=word[0];
        }
    }
    else{
        str="";
    }
    return str;
}
