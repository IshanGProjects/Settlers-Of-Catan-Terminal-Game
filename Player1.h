//CSCI 1300 Fall 2021
//Author: Jaskarn Kahlon. Ishan Gohil
//Recitation 200 - Pragna/Spencer Paulissen
//Project 3 - Player1 header file

/*
The Player1 header file sets the amount of resources the player has and also sets the amount of victory points the player has
*/


#ifndef PLAYER1_H //Preprocessor directive
#define PLAYER1_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player1
{

public:
    //default constructor 
    Player1();
    void resetP1Data();    

    //getters
    int getResourceAt(int index);
    int getVicPoints();

    //setters
    bool setResourceAt(int index, int value);
    void setVicPoints(int vPoints);

    private:
    //Array of Resources
    static const int size_arrRes = 5;
    int arrRes[size_arrRes];
    //Amount of Victory Points
    int vicPoints;
};

#endif
