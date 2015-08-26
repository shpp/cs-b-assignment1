#include <iostream>
#include <string>
#include "console.h"
using namespace std;

// Function prototypes
string intToString(int n);
int stringToInt(string str);
string reverseString(string src);


int main() {
    string r = intToString(-1234567);
    //print in console converted integer and show first symbol of string
    cout << "This is string " << r << ". First element of string - " << r[0] << endl;

    string st = "457";
    int t = stringToInt(st);
    //print in console converted string. and to prove it what it number multiple on 2
    cout << "Number is - " << t << ". Make it double - " << t * 2 << endl;
    return 0;
}
//transforms string into integer with help of recursion
int stringToInt(string str){
    int res = 0;
    int minus = 0;
    //if we got minus
    if(str[0] == char(45)){
        cout << "stroka do - " << str << endl;
        str = str.substr(1, str.length()-1);
        cout << "stroka posle - " << str << endl;
        minus = 1;
    }

    if(str.length() == 1){
        char a = str[0];
        int b =((int) a) - 48;
        return res = b;
    }

    res =(((int) str[str.length()-1]) - 48) + 10 * stringToInt(str = str.substr(0,str.length() - 1)) ;
    if(minus == 1){
        res = res * (-1);
    }
    return res;
}

//transforms integer to string with help of recursion
string intToString(int n){
    string res;
    int minus = 0;
    //if we got minus
    if(n < 0 ){
        //cout << "chislo do - " << n << endl;
        n = n * (-1);
        //cout << "chislo posle - " << n << endl;
        minus = 1;
}
   if(n < 10){
   return res = char(n + 48);
}
    res = (intToString(n / 10)+char((n % 10) + 48));           //48
    if(minus == 1){
        res =char(45) + res;
    }
    return res;
}

//reverse string with help of recursion
//string reverseString(string src){
//    if(src == ""){
//        return src;
//    }
//     return (src[src.length() - 1]) + reverseString(src.substr(0, src.length() - 1));
//}
