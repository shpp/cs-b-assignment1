#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"

using namespace std;

/**
 * @brief isVowel - function to check, if char is vowel
 * @param letterToCheck
 * @return true if vowel
 */
bool isVowel(char letterToCheck){
    char ch=letterToCheck;
    if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch =='o' || ch=='O' ||
        ch == 'u' || ch == 'U'){
        return true;
    }
    return false;
}

/**
 * @brief obenglobish function translates word to ob-language
 * @param word to translate
 * @return translated word as string
 */
string obenglobish(string word){
    string res="";

    bool lastCharIsVowel=false;

    for(int i=0;i<word.length();i++){

        char currentChar=word[i];

        string prefix="";

        if(isVowel(currentChar)){
            if(!lastCharIsVowel){
                if(!(((currentChar=='e')||(currentChar=='E'))&&(i==word.length()-1)))
                    prefix="ob";
            }
            lastCharIsVowel=true;
        }else{
            lastCharIsVowel=false;
        }

        res+=prefix+currentChar;
    }
    return res;
}

int main() {
    while(true){
        string word=getLine("Enter a word");
        if (word=="")
            break;
        string translation=obenglobish(word);
        cout << word << " -> " << translation << endl;
    }
    return 0;
}
