#include <iostream>
#include <string>
#include "console.h"
#include <ctype.h>
using namespace std;

// Function prototypes
string intToString(int n);
int stringToInt(string str);


int main() {
/****Testing functions intToString****/
    const int N = 10;
    int numTest[N] = {2565,-2565,505,-505,50,-50,1,-1,0,0};
    for(int i=0;i<N;i++){
        string res = intToString(numTest[i]);
        cout<<res<<endl;
    }
/****Testing functions stringToInt****/
    string stringTest[6]={"1234","-1234","234","-234","0","0"};
    for(int i=0;i<6;i++){
        cout<<stringToInt(stringTest[i])<<endl;
    }
   return 0;
}


/*The function takes a number and divides it with the help of recursion into tenths hundredths,
and so on. And hildren number converted to a string with one character
and adds them to the result string.And thus returns the number of characters in a string.*/
 string intToString(int n){
    string res;
        if(n == 0){
            return "0";
        }
        if(n<0){
            n = -n;
            res +=(string()+ '-');
        }
        if(n/10 == 0){
            return res += string()+char(n%10  + '0')  ;
        }
        res +=intToString(n/10)+(string()+char(n%10  + '0'));
        return res;
 }

/* The function receives the string.It takes the last character of
 a string and converts it to a number and adds to it the result
 of recursively caused by the same function multiplied by the parameter 10.
 Recursive function gets the input string but less than one character.*/
 int stringToInt(string str){
        int res = 0;
        if(str[0]=='-'){
            res = -1*(stringToInt(str.substr(1,str.length()-1)));
            return res;
        }
        int lastNumbe = char(str[str.length()-1]-'0');
        if(str.length()==1){
            return lastNumbe;
        }
        res = lastNumbe+10*stringToInt(str.substr(0,str.length()-1));
        return res;
 }

// *****Implementation of the function to convert a string to a number using the cycle*****

  /*  int stringToInt(string str){
        int s=0;
        int iMin=0;
            int al=str.length();
            if(str[0]=='-'){
                al--;
                iMin = 1;
            }
            int k=1;
            for(int i=0;i<al-1;i++)
            {
                k*=10;
            }
            for(int i=iMin;i<str.length();i++)
            {
                s+=(str[i]-'0')*k;
                k/=10;
            }
            if(iMin == 1){
                return -s;
            }
            return s;
    }
    */
