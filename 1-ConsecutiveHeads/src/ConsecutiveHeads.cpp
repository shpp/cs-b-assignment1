#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
using namespace std;



//heads = true
//tails = false
void flipTheCoin();

void doTheGame(int & headsCounter, bool & result, int & flipsCounter);


int main() {
    int headsCounter=0;
    int flipsCounter=0;
    bool result; //the result of flipping coin

    doTheGame(headsCounter, result, flipsCounter);
    cout << "It took " << flipsCounter << "flips" << endl;
    return 0;
}


void flipTheCoin(bool & result){
    result = rand()%2;
    //return  x;
}

void doTheGame(int & headsCounter, bool & result, int & flipsCounter){
    if(headsCounter==3)
        return;
    else{
        flipTheCoin(result);
        flipsCounter++;
        if (result){
            cout << "heads" << endl;
            headsCounter++;
        }
        else{
            cout << "tails" << endl;
            headsCounter = 0;
        }

        doTheGame(headsCounter, result, flipsCounter);
    }

}
