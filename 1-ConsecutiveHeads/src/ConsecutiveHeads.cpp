#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
using namespace std;

#define FINAL_COUNT 3

/*
    simulate one flip
    return heads/tails

*/
string flip(){
    if(randomInteger(0,2) == 0){
        return "heads";
    }
    else{
        return "tails";
    }
}

void game(){
    int tempCountHeads = 0, /* for count heads on each loop*/
        countLoops = 0;
    string rez;
    while(tempCountHeads != FINAL_COUNT){
        rez = flip();
        if(rez == "heads"){
            tempCountHeads += 1;
            cout << rez + to_string( tempCountHeads)<< endl;
        }
        else{
            tempCountHeads = 0;
            cout << rez << endl;
        }
        countLoops++;
    }
    cout << "It look " + to_string(countLoops) + "flips to get 3  consecutive heads." << endl;

}

int main() {
   game();
   return 0;
}
