//CSCI 1300 Fall 2021
//Author: Jaskarn Kahlon/ Ishan Gohil
//Recitation 200 - Pragna
//Project 3 - Player 2 implementation file

#include "Player2.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


//constructors

//default constructor
Player2::Player2()
{
    resetP2Data();
}

 void Player2::resetP2Data()
{
    //Initaizlizing all the indexes of the resource array to zero
    for(int i = 0; i < size_arrRes; i++)
    {
        arrRes[i] = 0;
    } 
    //Setting default victory points to zero
    vicPoints = 0;
}

//Getters
//Get Number of resources at
int Player2::getResourceAt(int index){ 
    if (index >= 0 && index < size_arrRes){
        return arrRes[index];
    }
    else{
        return -1;
    }
}
//Get vic Points
int Player2::getVicPoints(){
    return vicPoints;
}

//Setters
//Set the amount of resouces in the array
bool Player2::setResourceAt(int index, int value)
{
    if(index >=0 && index < size_arrRes){
        arrRes[index] = value;
        return 1;
    }
    else{
        return 0;
    }
}
//set Victory Points
void Player2::setVicPoints(int vPoints){
    vicPoints = vPoints;
}

