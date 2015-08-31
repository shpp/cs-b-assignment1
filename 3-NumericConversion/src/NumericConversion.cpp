#include <iostream>
#include <string>
#include "console.h"
#include "math.h"
using namespace std;

// Function prototypes
string intToString(int n);
int stringToInt(string str);

int main() {

   int inputData = 0;
   cout << "Input number: ";
   cin >> inputData;
   cout << "Int to string:";
   cout << intToString(inputData) << endl;

   cout << "String to int:" ;
   cout << stringToInt(to_string(inputData));
   return 0;
}

string intToString(int n) {
    bool flag = false;
    if (n < 0) {
        flag = true;
        n *= -1;
    }
    // get last digit of integer and transform it into char
    int lastDigit = n%10;
    char lastSymbol = lastDigit + '0';

    // digging into recursion
    string recoursiveFeedback = "";
    if (n >= 10) {
        recoursiveFeedback = intToString(n/10);
    }
    recoursiveFeedback.push_back(lastSymbol);
    if (flag) recoursiveFeedback.insert(0,"-");
    return recoursiveFeedback;
}

//recursion make string as int
    int stringToInt(string str){
        bool minusFlag = false;
        int tempRez = 0;
        int firstDigit = 0;

        switch (str.at(str.size()-1)) {
            case '1':
                firstDigit = 1;
                break;
            case '2':
                firstDigit = 2;
                break;
            case '3':
                firstDigit = 3;
                break;
            case '4':
                firstDigit = 4;
                break;
            case '5':
                firstDigit = 5;
                break;
            case '6':
                firstDigit = 6;
                break;
            case '7':
                firstDigit = 7;
                break;
            case '8':
                firstDigit = 8;
                break;
            case '9':
                firstDigit = 9;
                break;
            case '0':
                firstDigit = 0;
                break;
            case '-':
                minusFlag = true;
                break;

        default:
                break;
            }


        if (str.size() > 1) {
            tempRez = stringToInt(str.substr(0,str.size()-1));
            tempRez = tempRez * 10 + firstDigit ;
        }
        else{
            tempRez = firstDigit;
        }

        if (minusFlag) tempRez *= -1;

        return tempRez;
    }
