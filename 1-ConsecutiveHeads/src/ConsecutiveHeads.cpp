#include <iostream>
#include <string>
#include <ctime>
#include "console.h"
#include "random.h"
using namespace std;

int main() {
    int flipsCounter = 0;
    int headsCounter = 0;
    // Generate new random generator seed.
    srand(time(0));
    while (headsCounter < 3) {
        if(rand() % 2) {
            // Is heads...
            headsCounter ++;
            cout << "heads" << endl;
        } else {
            // Is tails...
            headsCounter = 0;
            cout << "tails" << endl;
        }
        flipsCounter ++;
    }
    // Output resultson the console.
    cout << "It tooks " << flipsCounter << " to get 3 consecutive heads." << endl;
    return 0;
}
