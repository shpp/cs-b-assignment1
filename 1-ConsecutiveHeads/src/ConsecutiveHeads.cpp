#include <iostream>
#include <string>
#include "console.h"
#include "random.h"

using namespace std;

string dropCoin(){
    string res="tails";
    if (randomChance(.5))
        res="heads";
    return res;
}

int main() {

    int headsCounter=0;

    while(true){
        string currentSide=dropCoin();

        cout << currentSide << endl;

        if(currentSide=="heads"){
            headsCounter++;
            if (headsCounter==3)
                break;
        } else {
            headsCounter=0;
        }
    }

   return 0;
}
