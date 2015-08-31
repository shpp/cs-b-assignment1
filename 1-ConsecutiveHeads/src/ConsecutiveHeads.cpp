#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
using namespace std;

string get_side_coin();

int main() {
    const int doubling = 3; // count consecutive values to stop flipping

    string value = ""; // result of curent flipping

    int num_iter = 0, tails = 0, heads = 0; // number of iteration, seria of tails and heads respectively

    while(heads != doubling && tails != doubling){
        ++num_iter;
        value = get_side_coin();
        if (value == "heads"){
            ++heads;
            tails = 0;
        } else {
            ++tails;
            heads = 0;
        }
        cout << "Flip: " << num_iter
             << ", value: " << value << endl;
    }
    cout << "It took " << num_iter << " flips to get 3 consecutive " << value << "." << endl;
    return 0;
}

// imitation coin flip
string get_side_coin(){
    bool rndm = randomBool();
    string coin_side = "";
    if (rndm){
        coin_side = "heads";
    } else {
        coin_side = "tails";
    }
    return coin_side;
}
