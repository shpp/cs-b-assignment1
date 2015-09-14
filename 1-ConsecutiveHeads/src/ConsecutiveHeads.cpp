#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
using namespace std;

int main() {
   // TODO: fill in the code
   int countFlips = 0;
   int countFlipsToWin = 0;
   while (countFlipsToWin < 3){
       if (randomBool()) {
           cout<<"heads"<<endl;
           countFlipsToWin++;
       } else{
           cout<<"tails"<<endl;
           countFlipsToWin=0;
       }
       countFlips++;
   }
   cout<<"It took "<<countFlips<<" flips to get 3 consecutive heads."<<endl;
   return 0;
}
