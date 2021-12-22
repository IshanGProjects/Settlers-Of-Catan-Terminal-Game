//CSCI 1300 Fall 2021
//Author: Jaskarn Kahlon/ Ishan Gohil
//Recitation 200 - Pragna
//Project 3 - DevCard implementation file

#include "Dev.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//constructors
Dev::Dev()
{
  devReset(); 
}

// //parameterized
// Dev::Dev( int numCards1, int numCards2, int arr[], int arrSize)
// {
//     numDevCards1 = numCards1;
//     numDevCards2 = numCards2;
//     arrSize = 5;
//     for (int i = 0; i < arrSize; i++)
//     {
//         arr[i] = outcomes[i];
//     }
// }

void Dev::devReset()
{
    numDevCards1 = 0;
    numDevCards2 = 0;
    for( int i = 0; i < size; i++)
    {
        outcomes[i] = 0;
    }
}

// setters
void Dev::setNumDevCards1(int numCards1)
{
    numDevCards1 = numCards1;
}
void Dev::setNumDevCards2(int numCards2)
{
    numDevCards2 = numCards2;
}
void Dev::setNumSoldiersP1(int s1)
{
    soldiersP1 = s1;
}
void Dev::setNumSoldiersP2(int s2)
{
    soldiersP2 = s2;
}




// getters
int Dev::getNumDevCards1()
{
    return numDevCards1;
}
int Dev::getNumDevCards2()
{
    return numDevCards2;
}
int Dev::getNumSoldiersP1()
{
    return soldiersP1;
}
int Dev::getNumSoldiersP2()
{
    return soldiersP2;
}
