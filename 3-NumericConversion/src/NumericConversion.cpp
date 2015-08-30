/* File: NumericConverion.cpp
 * -------------------------------------------------------------------------
 *
 * This program is a recursive implementation of two functions:
 *
 * 1. intToString - Convert ingeger number to its string equivalent
 * 2. stringToInt - Convert string number to it integer equivalent
 *
 * This program in an infinite loop asks the user for integer
 * number, convert it to the string and print the result. Then convert
 * the result back into the integer and print it.
 *
 *
 */
#include <iostream>
#include <string>
#include "console.h"
using namespace std;

// Function prototypes
string intToString(int n);
int stringToInt(string str);

/* Main program*/
int main() {

    int intNumber = 0;

    while (true){
        cout << "Enter integer: ";
        cin >> intNumber;
        cout << "Number: " << intNumber << endl;
        string strNumber = intToString(intNumber);
        cout << "Integer like string: " << strNumber <<endl;
        cout << "String like integer: " << stringToInt(strNumber) << endl;
    }
    return 0;
}

/* Function: intToString
 * Usage: string strNumber = intToString(intNumber);
 * --------------------------------------------------------------------------
 *
 * This function converts an integer to its string equivalent
 * using a recursive implementation.
 * It cuts the last digit and converts it to ASCII symbol by adding '0', then
 * converts it to the string and calls itself without this digit.
 *
 * @param n Integer number, that will be converted
 * @return Converted number in the string format
 */
string intToString(int n){
    string result = "";

    if (n < 0){
        n *= -1;
        result += "-" + intToString(n / 10) + (string() + char(n%10 + '0'));
    } else if (n >0) {
        result += intToString(n / 10) + (string() + char(n%10 + '0'));
    } else {
        result = "0";
    }

    /* Get rid of zero at the begining if positive number*/
    if (result.length() > 1 && result[0] == '0'){
        result = result.erase(0, 1);
    }

    /* Get rid of zero at the begining if negtive number*/
    if(result[0] == '-' && result[1] == '0'){
        result = result.erase(1, 1);
    }
    return result;
}

/* Function: stringToInt
 * Usage: cout << "String like integer: " << stringToInt(strNumber) << endl;
 * ------------------------------------------------------------------------
 *
 * This function converts a string to its
 * integer number equivalent using a recursive implementation.
 * It cuts the last character of the string and converts it to the integer by
 * removing from it '0', then calls itself without this character.
 *
 * @param str String number that will be converted to the integer number
 * @return Converted number in the integer format
 */
int stringToInt(string str){
    int result = 0;

    /*Stop recursion at the last or alone character*/
    if (str.length() == 1){
        return str[0] - '0';
    }

    /*Removes '-' symbol and make result negative*/
    if (str[0] == '-'){
        return  -stringToInt(str.erase(0,1));
    }

    result = (stringToInt(str.substr(0, str.length()-1)) * 10) + (str[str.length() - 1] - '0');


    return result;

}
