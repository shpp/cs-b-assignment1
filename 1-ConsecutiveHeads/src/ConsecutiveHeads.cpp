#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
using namespace std;

//initialization function prototype
int coinToss(int &numberOfMatches,int &count);


int main() {
//Initialization of variables: the number of matches
//and a variable number of attempts
    int numberOfMatches = 0;
    int count = 0;
    coinToss(numberOfMatches,count);
    cout<<"It took "<<count<<" flips to get "<<numberOfMatches<<" consecuteve heads"<<endl;
    return 0;
}

//The function receives the variable references are
//responsible for the number of matches and the number of attempts.
//At the beginning of the function is increased count++(Number of attempts).
//And then, depending on the function randomBool() result is an increase in the variable
//numberOfMatches or reset, and a recursive call to the original function until
//the variable numberOfMatches is not equal to three.

int coinToss(int &numberOfMatches,int &count){
    bool sideCoin = randomBool();
    count++;
    if(sideCoin == true){
        numberOfMatches++;
        cout<<"heads"<<endl;
        if(numberOfMatches==3){
            return 0;
        }
        coinToss(numberOfMatches,count);
    }
    else{
        cout<<"tails"<<endl;
        numberOfMatches=0;
        coinToss(numberOfMatches,count);
    }
    return 0;
}
