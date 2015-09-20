#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
//#include "strlib.h"
using namespace std;

// Function prototypes
string intToString(int n);
int stringToInt(string str);


int main() {
   while (true) {
       string str = getLine("Enter a string: ");
       int number = stringToInt(str);
       cout << str << " -> " << number << endl;
       int num = getInteger("Enter a number (add a trailing space at the end): ");
       string string = intToString(num);
       cout << num << " -> " << string << endl;
   }
   return 0;
}

int stringToInt(string str) {
    int sign = 1;
    if (str[0] == '-') {
        sign = -1; //transform into negative int
        str = str.substr(1);
    }
    if (str == "") return 0;
    else {
        // Going from the end
        return sign*((static_cast<int>(str[str.length()-1]) - static_cast<int>('0'))
                + stringToInt(str.substr(0, str.length()-1))*10);
    }
}

string intToString(int n) {
    string str;
    if (n < 0) {
        str = "-"; // add negative sign and transform absolute value
        n *= -1;
    }
    if (n == 0) return "0";
    if (n%10 != 0 & n/10 == 0) return str + char(n%10 + '0');
    else return str + intToString(n/10) + char(n%10 + '0');
}
