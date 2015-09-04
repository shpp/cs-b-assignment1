#include <iostream>
#include <string>
#include "console.h"
#include "math.h"
using namespace std;

// Function prototypes
string intToString(int n);
int stringToInt(string str);


int main() {
    // some tests
    cout << intToString(0) << endl;
    cout << intToString(987) << endl;
    cout << intToString(-12345) << endl;
    cout << endl;
    cout << stringToInt("0") << endl;
    cout << stringToInt("987987") << endl;
    cout << stringToInt("-12345") << endl;
    return 0;
}

string intToString(int n) {
    if(n == 0) {
        return "0";
    }
    else if(n < 0) {
        return "-" + intToString(n * (-1));
    }
    else {
        char lastNum = char(n%10 + '0');
        if(n/10 == 0) {
            return string(1,lastNum);
        }
        else {
            return intToString(n/10) + lastNum;
        }
    }
}

int stringToInt(string str) {
    int negative = 1;
    if(str[0] == char('-')) {
        negative = -1;
        str = str.substr(1,str.length());
    }
    if(str.length() == 0) {
        return 0;
    }
    else {
        int lastNum = str[0] - '0';
        return negative * (lastNum * pow(10, str.length() - 1) + stringToInt(str.substr(1,str.length())));
    }
}
