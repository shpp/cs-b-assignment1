#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
using namespace std;

int main () {
    int heads = 0;
    int allFlips = 0;

    while (heads < 3) {
        allFlips++;
        if(randomBool()) {
            cout << "heads" << endl;
            heads++;
        }
        else {
            cout << "tails" << endl;
            heads = 0;
        }
    }
    cout << "It took " << allFlips << " flips to get 3 consecutive heads." << endl;
    return 0;
}
