#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
using namespace std;

//make function throw coin
void throwCoin()
{
    int tryCounter = 0; //count the repetition of cycle
    int b = 0; //if b=3 it mean that we have 3 heads in a row if we have tails then we make b=0.
    while(b<3){
        int i = randomInteger(0,1);
        if(i == 1){
            cout << "heads" << endl;
            b += 1;
        }else{
            cout << "tails" << endl;
            b = 0;
        }
        tryCounter+=1;
    }
    cout << "It take " << tryCounter << " try to get 3 heads in row" << endl;
}
int main() {

    throwCoin();

    return 0;
}
