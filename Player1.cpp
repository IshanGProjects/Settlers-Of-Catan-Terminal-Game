//CSCI 1300 Fall 2021
//Author: Jaskarn Kahlon/ Ishan Gohil
//Recitation 200 - Pragna/  Spencer Paulissen
//Project 3 - Player 1 implementation file

#include "Player1.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


//constructors

//default constructor
Player1::Player1()
{
    resetP1Data();
}

 void Player1::resetP1Data()
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
//Get Nuber of resources at
int Player1::getResourceAt(int index){ 
    if (index >= 0 && index < size_arrRes){
        return arrRes[index];
    }
    else{
        return -1;
    }
}
//Get vic Points
int Player1::getVicPoints(){
    return vicPoints;
}

//Setters
//Set the amount of resouces in the array
bool Player1::setResourceAt(int index, int value)
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
void Player1::setVicPoints(int vPoints){
    vicPoints = vPoints;
}

