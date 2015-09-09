#include <iostream>
#include <string>
#include "console.h"
using namespace std;

// Function prototypes
string intToString(int n);
int stringToInt(string str);



int main() {
   // TODO: fill in the code

    int tests[] = {
            0, 100, -5, 10, 5, 1729
        };

        const int B = 6;
        for (int i=0; i<B; i++)
        {
            cout << "Converting the integer "<< tests[i] <<" to string: ";
            cout << intToString(tests[i]) << endl;
        }


   return 0;
}
int stringToInt(string str){
    int resultInt = 0;
    return resultInt;
}

string intToString(int n){
    string resultString;
    static bool recursive_call = false; //is this a recursive call?
    if(!recursive_call) {
        if(!n) return "0"; //deal with zero
        else if(n < 0) { //account for negative numbers
                    n *= -1;
                    resultString += '-';
            }
        recursive_call = true; //get ready for recursive calls
        }
        else if(!n) { //conversion is complete, reset function for future calls
            recursive_call = false;
            return "";
        }

        char appendCh = n % 10 + '0'; //convert to a character
        return resultString + intToString(n / 10) + appendCh; //append the characters in the correct order
}

