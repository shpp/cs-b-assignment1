#include <iostream>
#include <string>
#include <typeinfo>
#include "console.h"
using namespace std;

// Function prototypes
string intToString(int n);
int stringToInt(string str);

int main() {

    int testValuesInt[5] = {0, 1, -1, 1234567890, -1234567890};

    for(int i=0; i<(sizeof(testValuesInt)/sizeof(testValuesInt[0])); i++){
        string resStr = intToString(testValuesInt[i]);
        cout << "My test 'resStr' variable has value: " << resStr << ", and type: " << typeid(resStr).name() << endl;
    }

    string testValuesStr[5]={"0", "1", "-1", "1234567890", "-1234567890"};

    for(int i=0;i<(sizeof(testValuesStr)/sizeof(testValuesStr[0]));i++){
        int resInt = stringToInt(testValuesStr[i]);
        cout << "My test 'resInt' variable has value: " << resInt << ", and type: " << typeid(resInt).name() << endl;
    }

    return 0;
}
// Converts an integer into the corresponding string of digits.
string intToString(int n){
    string res = "";

    if(n == 0){
        return "0";
    }
    // If negative number - add a sign "-".
    if(n<0){
        n = n*(-1);
        res += ("-" + string());
    }

    if(n/10 == 0){
        return res += string()+char(n%10+'0')  ;
    }

    res += intToString(n/10)+(string()+char(n%10+'0'));

    return res;
}
// Converts a string of digits into an integer.
int stringToInt(string str){
    int res = 0;

    if(str[0] == '-'){
        res = (stringToInt(str.substr(1,str.length()-1)))*(-1);
        return res;
    }

    int latestSymbol = char(str[str.length()-1]-'0');

    if(str.length()==1){
        return latestSymbol;
    }

    res = latestSymbol+10*stringToInt(str.substr(0,str.length()-1));

    return res;
 }
