#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
using namespace std;

/*
 * Coin flip simulator. Сauses the random number generator which returns true or false
 * until it randomly gives three times in a row the value true that would mean heads.
 * At the end it displays a message about the number of flips that are needed to achieve results.
 */
int main() {
    int consecutiveHeads = 3; //the required count of consecutive heads for finishing the game;
    int countOfHeads = 0;
    int countOfFlips = 0;
    while(countOfHeads < consecutiveHeads) {
        if(randomBool()){ //if true then we assume that it is heads
            cout << "heads" <<endl;
            ++countOfHeads;
        }
        else {
            cout << "tails" <<endl;
            countOfHeads = 0;
        }
        ++countOfFlips;
    }
    cout << "It took " << countOfFlips << " to get "
         << consecutiveHeads << " consecutive heads." << endl;
    return 0;
}
