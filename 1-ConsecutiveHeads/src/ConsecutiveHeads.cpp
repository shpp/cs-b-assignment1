#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
using namespace std;

int main() {
    int counterHeads = 0, counterFlips = 0;
    while (counterHeads < 3) {
        if (randomChance(0.5)){ // simulate coin flip
            counterHeads++;
            cout << "heads" << endl;
        } else {
            counterHeads = 0;
            cout << "tails" << endl;
        }
        counterFlips++;
    }

    cout << "It took " << counterFlips << " flips to get 3 consecutive heads." << endl;
    return 0;
}
