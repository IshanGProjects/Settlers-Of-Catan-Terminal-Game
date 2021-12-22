#include "diceRoll.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

Dice::Dice() {
    dice1 = 0;
    dice2 = 0;
    totalScore = 0;
}
void Dice::Roll(){
     dice1 = (rand() % 6) + 1;
     dice2 = (rand() % 6) + 1;
     totalScore = dice1 + dice2;
}
int Dice::getRoll(){
        return totalScore;
}
void Dice::Display(){
     if(totalScore == 6) {
             cout << "Your last roll was:" << "\x1b[32m 6 \x1b[0m" << endl;
     }
     else if(totalScore == 8) {
             cout << "Your last roll was:" << "\x1b[32m 8 \x1b[0m" << endl;
     }
     else if(totalScore == 7) {
             cout << "Your last roll was:" << "\x1b[35m 7 \x1b[0m" << endl;
     }
     else {
     cout << "Your last roll was: " << totalScore << endl;
     }
}
void Dice::Reset(){
    dice1 = 0;
    dice2 = 0;
    totalScore = 0;
}


// int main(){ 
//    srand(time(NULL));
//    Dice myDice;
//     myDice.Roll();
//     myDice.Display();

// }