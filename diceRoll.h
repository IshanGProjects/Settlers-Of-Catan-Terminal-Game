#ifndef DICE_H //Preprocessor directive
#define DICE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Dice {
    public:
    Dice();
    void Roll();
    int getRoll();
    void Display();
    void Reset();

    private:
    int dice1;
    int dice2;
    int totalScore;
};
#endif