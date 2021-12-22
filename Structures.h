//CSCI 1300 Fall 2021
//Author: Jaskarn Kahlon/Ishan Gohil
//Recitation 200 - Pragna/ Spencer Paulissen
//Project 3 - Structures Header File

/*
The structures header file is responisble for stroring the amoount of built structures 
*/

#ifndef STRUCTURES_H //Preprocessor directive
#define STRUCTURES_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Structures
{
    public:
        //default constructor 
        Structures();
        
        //Parameterized constructor
        Structures(int road1, int road2, int settlement1, int settlement2, int cities1, int cities2);

        //getters
        //Player 1 Getters
        int getNumRoad1();
        int getNumSettlement1();
        int getNumCities1();

        //Player 2 Getters
        int getNumSettlement2();
        int getNumRoad2();
        int getNumCities2();

        //Setters
        //Player 1 Setters
        void setNumRoad1(int r1);
        void setNumSettlement1(int s1);
        void setNumCities1(int c1);
        //Player 2 Sstters
        void setNumRoad2(int r2);
        void setNumSettlement2(int s2);
        void setNumCities2(int c2);

    private:
        //Player 1 Private Variables
        int road1;
        int settlement1;
        int cities1;
        //Player 2 Private Variables
        int road2;
        int settlement2;
        int cities2;

};

#endif