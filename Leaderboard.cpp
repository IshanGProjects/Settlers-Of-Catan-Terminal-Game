//CSCI 1300 Fall 2021
//Author: Jaskarn Kahlon/Ishan Gohil
//Recitation 200 - Pragna
//Project 3 - Leaderboard implementation file

#include "Leaderboard.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

//constructors

//default constructor
Leaderboard::Leaderboard()
{
    playerName = "";
    numWins = 0;
    vector <int> rankings;
    // (totPlayers,0);
}

//parameterized constructor
Leaderboard::Leaderboard(string name, int wins, vector <int> r)
{
    playerName = name;
    numWins = wins;

    for(int i = 0; i < totPlayers; i++)
    {
       r[i] = rankings.at(i);
    }

}

//Getters


int Leaderboard::getNumWins()
{
    return numWins;
}



string Leaderboard::getPlayerName(){
    return playerName;
}

//Settters



void Leaderboard::setPlayerName(string name) {
    playerName = name;
}

void Leaderboard::setNumWins(int wins) {
    numWins = wins;
}
