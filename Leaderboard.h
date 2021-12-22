//CSCI 1300 Fall 2021
//Author: Jaskarn Kahlon/Ishan Gohil
//Recitation 200 - Pragna/  Spencer Paulissen
//Project 3 - Leaderboard header file

/*
The leaderboard header file sets and displays the rankings
*/


#ifndef LEADERBOARD_H //Preprocessor directive
#define LEADERBOARD_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Leaderboard
{

public:
    //default constructor 
    Leaderboard();

    //parameterized constructor
    Leaderboard(string playerName, int numWins, vector <int> rankings);

    //getters
    // string getPlayerName();
    int getNumWins();
    int getTotPlayers();
    string getPlayerName();
    // vector <string> getRankName();
    //setters
    void setPlayerName(string);
    void setNumWins(int numWins);
    void setTotPlayers(int totPlayers);
    void setRankName(string name1, string name2);

    private:
    string playerName;
    int numWins;
    int totPlayers;
    /*
    //we chose to use vectors because they don't have a fixed allocation of memory,
    this is useful in the ranking system because it will be constantly updating
    */
    vector <int> rankings;
    vector <string> rankName;
};

#endif