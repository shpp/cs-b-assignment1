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
/*****Implementing functions using a loop****/
//Function in a loop to iterate over all the
//letters of the string and if it finds a vowel,
//and in front of it is not worth another vowel confronts her line "ob".
//string obenglobish(string wordLine){
//    string str;
//    string word = toLowerCase(wordLine);
//    for(int i = 0;i<word.length();i++){
//        if(word[i]=='e'){
//            if((i != word.length()-1)&&(!isVowel(word[i-1]))){
//                str = str+string("ob")+word[i];
//            }
//            else{
//                str +=word[i];
//            }
//        }
//        else{
//            if(isVowel(word[i]) && !isVowel(word[i-1])){
//                str = str+string("ob")+word[i];
//            }
//            else{
//                str +=word[i];
//            }
//        }
//    }
//    return str;
//}

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
