#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
#include <simpio.h>
using namespace std;

/* Sets console output */
void consoleSettings();
/* Lunch proces program */
void consequtiveHeads();
/* Main process loop */
void dropCoin(int heads, int flips);
/* Sets chances parametr */
const double chance = 0.5;
/* Program window title  */
const string programTitle = "Consequtive heads";
/* Disable console dupplication */
const bool consoleEcho = false;

int main() {
   /*Adjust console window features*/
   consoleSettings();
   /* Programms starts and coins game begins
    * "heads" getting is monitored, and at 3-d consequtive head programm drops
    * message and stops  */
   consequtiveHeads();

   return 0;
}
/* Lunch game and main counters */
void consequtiveHeads(){
    int flipsCnt = 0;
    int headsCnt = 0;
    /* Coin is droped until game isn't finished */
    dropCoin(headsCnt, flipsCnt);
}

/* Recursion loop
 * After 3 consequtive heads print end message */
void dropCoin (int heads, int flips){
    bool head = false;

    if(heads > 2){
        /* End game message */
        cout << "It took " << flips << " flips to get 3 consecutive heads.";
    }else{
        /* Coin random result */
        head = randomChance(chance);
        flips++;

        if(head){
            cout << "heads" << endl;
            heads++;
        }else{
            cout << "tails" << endl;
            heads = 0;
        }
        /* Recursion loop */
        dropCoin(heads, flips);
    }
}

void consoleSettings(){
    setConsoleWindowTitle(programTitle);
    setConsoleEcho(consoleEcho);
}
