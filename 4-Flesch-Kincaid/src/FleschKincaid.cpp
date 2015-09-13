#include <iostream>
#include "console.h"
#include <fstream>
#include "tokenscanner.h"
using namespace std;


int separatedFileIntoTokens(ifstream myFile){
    TokenScanner scanner(myFile);
    while (scanner.hasMoreTokens()) {
          string token = scanner.nextToken();
          cout<<token<<endl;
       }
    return 0;
}

int main() {
    // TODO: fill in the code
    string fileName;
    ifstream myFile;
    int result;
    while (true) {
        cout<<"Enter file name pls:";
        cin>>fileName;
        myFile.open(fileName);
        if (myFile.is_open()){
         cout<<"FILE IS OPEN"   <<endl;
         TokenScanner scanner(myFile);
         scanner.ignoreWhitespace();
         while (scanner.hasMoreTokens()) {
               string token = scanner.nextToken();
               cout<<token<<endl;
            }
        }
        myFile.close();
    }
    return 0;
}
