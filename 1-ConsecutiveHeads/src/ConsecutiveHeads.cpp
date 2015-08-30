/*File ConsecutiveHeads.cpp
 * ------------------------------------------------------
 *
 * This program simulates a coin toss until heads fall three
 * consecutive times.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "random.h"

using namespace std;


/* Main program*/
int main() {

    const int NUM_OF_HEADS = 3;

    int counter = 0;
    int counterFlips = 0;

    while (counter < NUM_OF_HEADS){
        if(randomBool()){
            counter++;
            counterFlips++;
            cout << "heads" << endl;
        }
        else {
            counter = 0;
            counterFlips++;
            cout << "tails" << endl;
        }
    }
    cout << endl << "It took " << counterFlips << " flips to get " << NUM_OF_HEADS << " consecutive heads.";
    return 0;
}


