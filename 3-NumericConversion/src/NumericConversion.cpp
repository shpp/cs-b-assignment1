#include <iostream>
#include <string>
#include "console.h"
using namespace std;

// Function prototypes
string intToString(int n);
int stringToInt(string str);

int main() {
    int test1=0;
    int test2=-89;
    int test3=2340;
    cout<<"intToString("<<test1<<") = "<<intToString(test1)<<endl;
    cout<<"intToString("<<test2<<") = "<<intToString(test2)<<endl;
    cout<<"intToString("<<test3<<") = "<<intToString(test3)<<endl;

    cout<<"stringToInt("<<test1<<") = "<<stringToInt(test1)<<endl;
    cout<<"stringToInt("<<test2<<") = "<<stringToInt(test2)<<endl;
    cout<<"stringToInt("<<test3<<") = "<<stringToInt(test3)<<endl;

    return 0;
}

/* intToString: This function takes an integer as parameter and returns
 * its string equivalent
 */
string intToString(int n){
    if(n >= 0){
        if ( n / 10  == 0 ){
            return char(n % 10 + '0') + string();
        } else {
            return intToString(n / 10) + intToString(n % 10);
        }
    }
    else {
        return string("-") + intToString(-n);
    }
}

/* stringToInt: This function takes a string as parameter and returns
 * its integer equivalent
 */
int stringToInt(string str){
    if( (str[0] - '0' > 9) ||(str[0] - '0' < 0) ){
        return 0 - stringToInt(str.substr(1));
    }else{
        if(str.length() == 1){
            return int(str[0] - '0');
        } else {
            return stringToInt(str.substr(0,str.length() - 1)) * 10 + stringToInt(str.substr(str.length() - 1));
        }
    }
}
