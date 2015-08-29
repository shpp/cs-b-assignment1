#include <iostream>
#include <string>
#include "console.h"

using namespace std;

/* Task functions prototypes
 *  */
string intToString(int n);
int stringToInt(string str);
// Service functions prototypes
string recursiveIntToString(int n, string result);
int recursiveStrToInt(int index, string str, int result);
int rise10ToPower(int power);
// Console settings
void consoleSettings();
const double chance = 0.5;
const string programTitle = "NumericConversion";
const bool consoleEcho = false;

int main() {
   consoleSettings();

   cout << "Process STRING TO INT" << endl;
   cout << stringToInt("2505") << endl;
   cout << stringToInt("2") << endl;
   cout << stringToInt("-252") << endl;
   cout << stringToInt("0") << endl;   

   cout << endl;

   cout << "Process INT TO STRING" << endl;
   cout << intToString(-3956) << endl;
   cout << intToString(-0) << endl;
   cout << intToString(826) << endl;

   return 0;
}

/* Converts integer to string */
string intToString(int n){
    string result = "";
    if(n < 0){
        /* Solve negative values */
        return string("-") + recursiveIntToString(-1 * n, result);
    }else{
        /* Main recursive loop */
        return recursiveIntToString(n, result);
    }
}

/* Recursive loop process */
string recursiveIntToString(int intValue, string result){
    /* Divide input value in two parts - n/10 and n%10 */
    int nextValue = intValue/10;
    if(nextValue == 0){
        /* Returns string value of integer */
        return ((char)(intValue + '0') + result);
    }else{
        /* finds remain of n%10 process and concantenate it to result  */
        int remain = intValue % 10;
        char remainChar = (char)(remain + '0');
        result = remainChar + result;
        return recursiveIntToString(nextValue, result);
    }
}

/* Converts string to integer
 * Only if str is not object of integer (no comas or wrong input chars)  */
int stringToInt(string str){
    int startIndex = (str.length() - 1);
    int result = 0;
    /* Main conversion loop */
    return recursiveStrToInt(startIndex, str, result);
}

/* Main conversion process */
int recursiveStrToInt(int index, string str, int result){
    if(index < 0){
        /* If function processed all chars in str */
        return result;
    }
    else{
        /* If str stores negative value */
        if((index == 0) && (str[index] == '-')){
            return -1* result;
        }else{
            /* Converts each char into integer */
            int digit = str[index] - '0';
            /* Defines decamical capacity of such integer value */
            int power = (str.length() - 1) - index;
            /* Sums result with current integer decamical value */
            result += digit * rise10ToPower(power);
            /* Prepares to get next char in string */
            index--;
            /* Recursive loop */
            return recursiveStrToInt(index, str, result);
        }
    }
}

/* Rise 10 to power  */
int rise10ToPower(int power){
    if(power <= 0){
        return 1;
    }else{
        return 10 * rise10ToPower(power - 1);
    }
}

void consoleSettings(){
    setConsoleWindowTitle(programTitle);
    setConsoleEcho(consoleEcho);
}
