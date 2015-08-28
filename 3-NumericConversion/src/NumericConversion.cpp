#include <iostream>
#include <string>
#include "console.h"
#include <cmath>
using namespace std;

// Function prototypes
/*
 * Takes an integer as a parameter and returns a string identical
 * to the passed number (takes into account the negative sign).
 */
string intToString(int n);

/*
 * Takes a string, which may contain only a sign ('+' or '-') and
 * digits of the number, as a parameter and returns an integer identical
 * to the passed string (takes into account the negative or positive sign).
 */
int stringToInt(string str);


/*
 * Asks the user to enter two numbers that are put into variables
 * of type string. Converts strings to integers and displays the result
 * of the mathematical addition. After that, converts the integers
 * back to strings and displays the result of a string concatenation.
 */
int main() {
   string firstNumber = "";
   string secondNumber = "";
   cout <<  "Enter a first number: ";
   cin >> firstNumber;

   cout << "Enter a second number: ";
   cin >> secondNumber;

   int a = stringToInt(firstNumber);
   int b = stringToInt(secondNumber);

   cout << "Mathematical addition of two entered numbers: "
        << firstNumber << " + " << secondNumber << " = "
        << (a + b)  << endl;

   cout << "Adding the digits of the first number to the end of the second one: "
        << firstNumber << " and " << secondNumber << " -> "
        << (intToString(a) + intToString(b)) << endl;

   return 0;
}

int stringToInt(string digits){
    if(digits.length() == 1){
        return (digits[0] - '0');
    }
    if((digits[0] == '-') || (digits[0] == '+')){
        char sign = digits[0]; // memorize the sign
        digits = digits.substr(1); // and delete the sign
        if(sign == '-'){
            if  (digits.length() == 1){ // conversion for negative single-digit numbers
                return -1*(digits[0] - '0');
            }
            else return -1*((digits[0] - '0')*pow(10, (digits.length()-1)) + stringToInt(digits.substr(1)));
        }
        else return (digits[0] - '0'); //conversion for positive single-digit numbers
    }
    return (digits[0] - '0')*pow(10, (digits.length()-1)) + stringToInt(digits.substr(1));
}


string intToString(int number){
    string sign = ""; // accept that there is no sign
    if (number < 0){
        sign = "-"; // if the number is negative then memorize the negative sign
        number *= -1; // convert the number into a positive
    }
    if (number/10 == 0){
        return (sign + char(number + '0'));
    }
    // if the passed number was negative then convert it back into the negative for pass recursively
    return  intToString((sign == "-" ? -1*number : number)/10) + char(number % 10 + '0');
}
