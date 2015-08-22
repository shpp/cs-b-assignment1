#include <iostream>
#include <string>
#include "console.h"
using namespace std;

// Function prototypes
string intToString(int n);
int stringToInt(string str);

string intToString(int n){
    if(n<0){
        return "-"+intToString(-n);
    }
    if(n<10){
        return string()+char(n+'0');
    }
    return intToString(n/10)+char(n%10+'0');
}


int stringToInt(string str){
    if(str[0]=='-')
        return -stringToInt(str.substr(1,str.length()-1));

    int lastN=char(str[str.length()-1]-'0');

    if(str.length()==1)
        return lastN;

    return lastN+10*stringToInt(str.substr(0,str.length()-1));
}

int main() {
    int n=1234;
    string res=intToString(n);
    cout<<res<<" "<<res.length()<<endl;

    n=-1234;
    res=intToString(n);
    cout<<res<<" "<<res.length()<<endl;

    n=0;
    res=intToString(n);
    cout<<res<<" "<<res.length()<<endl;

    string tsts="1234";
    int res2=stringToInt(tsts);
    cout<<res2<<endl;

    tsts="-1234";
    res2=stringToInt(tsts);
    cout<<res2<<endl;

    return 0;
}
