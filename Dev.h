//CSCI 1300 Fall 2021
//Author: Jaskarn Kahlon. Ishan Gohil
//Recitation 200 - Pragna
//Project 3 - Dev card header file

/*
sets the amount of devcards
randomizes the value of the devcard
*/


#ifndef DEV_H //Preprocessor directive
#define DEV_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Dev
{

public:
    //default constructor 
    Dev();  
    void devReset();

    
    // //parameterized constructor
    // Dev(int numDevCards1, int numDevCards2, int outcomes[], int size);

    //getters
    int getNumDevCards1();
    int getNumDevCards2();
    int getNumSoldiersP1();
    int getNumSoldiersP2();
    int getOutcomes();

    //setters
    void setNumDevCards1(int numDevCards);
    void setNumDevCards2(int numDevCards);
    void setNumSoldiersP1(int);
    void setNumSoldiersP2(int);


    private:
    int numDevCards1;
    int numDevCards2;
    static const int size = 5;
    int outcomes[size];
    int soldiersP1 = 0;
    int soldiersP2 = 0;
};

#endif

// different outcomes
// 1. Army card, we would use the total number of this card collected to award the victory points
// 2. Road building card. we would add 2 to the value of roads
// 3. Sheep card, someone gifted you 2 sheep
// 4. misfortune card- -1 victory point "settlement caught on fire"
// 5. misfortune card - disease wiped all of your sheep. numSheep = 0