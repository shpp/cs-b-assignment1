#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

string obenglobish(string word);
bool vowelCheck(char i);
int main() {
    // TODO: fill in the code
    while(true){
        string word = getLine("Enter word: ");
        if(word == ""){
            break;
        }
        string translation = obenglobish(word);
        cout << word << " -> " << translation << endl;
    }
    return 0;
}

string obenglobish(string wordTmp){
    string res = "";
    string word = toLowerCase(wordTmp);
    int wLen = word.length();
    char last = word[wLen-1];
    int cheking = 0;            //need to check if word ends on "e" letter
    //check if entered word end with "e", if true - set cheking = 1;
    if(last == char(101)){
        word = word.substr(0,word.length()-1);
        cout << "trim word - " << word << endl;
        cheking = 1;
    }
    //start change entered word.
    //compare entered word with vowelletter char by char
    for(int i = 0; i<word.length(); i++){
        if(i != 0){
            if(vowelCheck(word[i]) == true && vowelCheck(word[i-1]) == false ){
                res += "ob";
            }
        }
        if(i == 0){
            if(vowelCheck(word[i]) == true){
                res += "ob";
            }
        }
        //if char is not vowel just add to res
        res += word[i];
    }
    //adding the "e" letter to res
    if(cheking == 1){
        res += "e";
    }
    return res;
}

//method check if char is vowel and return true or false
bool vowelCheck(char i){
    bool res;
    string vowelLetter = "aioue";
    for(int j = 0; j < vowelLetter.length(); j++){
        if(i == vowelLetter[j]){
            res = true;
            break;
        }else{
            res = false;
        }

    }
    return res;
}
