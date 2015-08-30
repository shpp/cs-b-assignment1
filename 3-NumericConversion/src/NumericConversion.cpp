#include <iostream>
#include <string>
#include "console.h"
using namespace std;

/**
 * Define the sign of the int number and return it in the string format.
 *
 * @param n - Int format number.
 * @return - String format of the numbers sign.
 */
string defineSign(int &n){
    if (n < 0) {
        n *= -1;
        return "-";
    } else
        return "";
}

/**
 * Define the sign of the string number and return it in the int format.
 *
 * @param str - String format number.
 * @return - Int format of the numbers sign.
 */
int defineSign(string &str){
    if (str[0] == '-') {
        str.erase(0, 1);
        return -1;
    } else
        return 1;
}

/**
 * Logic of the recursion convertion numbers int to string format.
 *
 * @param n - Int format number.
 * @return - String format number.
 */
string doRecursionIntToString(int n){
    if (n < 10)
        return string() + char(n + '0');
    else
        return doRecursionIntToString(n / 10) + (string() + char(n % 10 + '0'));
}

/**
 * Convert numbers int to string format with sign.
 *
 * @param n - Int format number.
 * @return - String format number.
 */
string intToString(int n) {
    string sign = defineSign(n);
    return sign + doRecursionIntToString(n);
}

/**
 * Logic of the recursion convertion numbers string to int format.
 *
 * @param str - String format number.
 * @return - Int format number.
 */
int doRecursionStringToInt(string str) {
    if (str.length() == 1)
        return int(str[0] - '0');
    else
        return doRecursionStringToInt(str.substr(0, str.length() - 1)) * 10
                + int(str[str.length() - 1] - '0');
}

/**
 * Convert numbers string to int format with sign.
 *
 * @param str - String format number.
 * @return - Int format number.
 */
int stringToInt(string str) {
    int sign = defineSign(str);
    return sign * doRecursionStringToInt(str);
}

int main() {
    cout << "Testing stringToInt function:" << endl;
    cout << "String = \"0\" -> int = " << stringToInt("0") << endl;
    cout << "String = \"123\" -> int = " << stringToInt("123") << endl;
    cout << "String = \"-456\" -> int = " << stringToInt("-456") << endl;
    cout << endl;
    cout << "Testing intToString function:" << endl;
    cout << "Int = 0 -> string = \"" << intToString(0) << "\"" << endl;
    cout << "Int = 123 -> string = \"" << intToString(123) << "\"" << endl;
    cout << "Int = -456 -> string = \"" << intToString(-456) << "\"" << endl;

    return 0;
}
