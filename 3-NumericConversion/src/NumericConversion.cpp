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
    string tests2[] = {"0", "100", "-5", "123456", "-123456", "733"};
        const int B = 6;
        for (int i=0; i<B; i++)
        {
            cout << "Converting the integer "<< tests[i] <<" to string: ";
            cout << intToString(tests[i]) << endl;
            cout << "Converting the string "<< tests2[i] <<" to integer: ";
            cout << stringToInt(tests2[i]) << endl<< endl;
        }
//    cout <<  "Converting the string "<< " * -123465 " <<" to integer: " << stringToInt("-123456");

   return 0;
}
/*function converts a string to a integer only from the positive numbers
 * param str = row in which only digits shall be;
   return = converted string into a integer
*/
int positiveStringToInt(string str){
    if (str[0] == '\0') return 0;
    char lastDigit = str[str.length()-1];
    if (str.length()-1 == 0)  return (lastDigit - '0');
    return stringToInt(str.substr(0,str.length()-1)) * 10 +  lastDigit - '0';;

}

/*function converts a string to a integer
 * param str = string which should be a digit, the first character could be "-" indicates that the number is less than zero
   return = converted string into a integer
*/
int stringToInt(string str){
    int resultInt = 0;
    if (str[0] == '-'){
        str = str.substr(1,str.length()-1);
        resultInt = 0 - positiveStringToInt(str);
    } else
        resultInt = positiveStringToInt(str);
    return resultInt;
}


/*function converts a integer to a string
 * param number = the number that you want to convert into a string
   return = string that contains a specified number
*/

string intToString(int number){
    string resultString;
    static bool recursive_call = false; //is this a recursive call?
    if(!recursive_call) {
        if(!number) return "0"; //deal with zero
        else if(number < 0) { //account for negative numbers
                    number *= -1;
                    resultString += '-';
            }
        recursive_call = true; //get ready for recursive calls
        }
        else if(!number) { //conversion is complete, reset function for future calls
            recursive_call = false;
            return "";
        }

        char appendCh = number % 10 + '0'; //convert to a character
        return resultString + intToString(number / 10) + appendCh; //append the characters in the correct order
}

