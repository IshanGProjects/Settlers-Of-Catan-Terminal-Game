//CSCI 1300 Fall 2021
//Author: Jaskarn Kahlon/ Ishan Gohil
//Recitation 200 - Pragna/ Spencer Paulissen
//Project 3 - Stuctures Implementation File

#include "Structures.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//constructors

//default constructor
Structures::Structures()
{
    //Initalzing Default Constructor for Player 1
    road1 = 0;
    settlement1 = 0;
    cities1 = 0;
    //Initalzing Default Constructor for Player 2
    road2 = 0;
    settlement2 = 0;
    cities2 = 0;
}

//parameterized constructor
Structures::Structures(int r1, int s1, int c1, int r2, int s2, int c2){
     //Initalzing Parameterized Constructor for Player 1
    road1 = r1;
    settlement1 = s1;
    cities1 = c1;
    //Initalzing Parameterized Constructor for Player 2
    road2 = r2;
    settlement2 = s2;
    cities2 = c2;
}

//Getters For Player 1
    //Getter for Roads
    int Structures::getNumRoad1(){
        return road1;
    }
    //Getter for Settlement
    int Structures::getNumSettlement1(){
        return settlement1;
    }
    //Getter for Cities
    int Structures::getNumCities1(){
        return cities1;
    }
//Getters For Player 2
    //Getter for Roads
    int Structures::getNumRoad2(){
        return road2;
    }
    //Getter for Settlement
    int Structures::getNumSettlement2(){
        return settlement2;
    }
    //Getter for Cities
    int Structures::getNumCities2(){
        return cities2;
    }

//Setters For Player 1 
    //Setter for Road
    void Structures::setNumRoad1(int r1){
        road1 = r1;    
    }
    //Setter for Settlement
    void Structures::setNumSettlement1(int s1){
        settlement1 = s1;
    }
    //Setter for Cities
    void Structures::setNumCities1(int c1){
        cities1 = c1;
    }

//Setters For Player 2
    //Setter for Road
    void Structures::setNumRoad2(int r2){
        road2 = r2;    
    }
    //Setter for Settlement
    void Structures::setNumSettlement2(int s2){
        settlement2 = s2;
    }
    //Setter for Cities
    void Structures::setNumCities2(int c2){
        cities2 = c2;
    }
