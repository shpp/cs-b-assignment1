#include <iostream>
#include "console.h"
#include "random.h"
using namespace std;

int consecutiveHeads(int nheads);
const int NHEADS = 3;

int main() {
    int result = consecutiveHeads(NHEADS);
    std::cout << "It took " << result << " flips to get " << NHEADS << " consecutive heads." << endl;
    return 0;
}

int consecutiveHeads(int nheads) {
    if (nheads == 0) return 0;
    int i = randomInteger(0, 1);
    std::cout << ((i == 1) ? "heads" : "tails") << endl;
    if (i == 1) return 1 +  consecutiveHeads(nheads-1); // decrease required heads
    else return 1 + consecutiveHeads(NHEADS);
}
