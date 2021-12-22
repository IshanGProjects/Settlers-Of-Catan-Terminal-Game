#include "scMap.h"
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

//Default constructor
scMap::scMap()
{
    resetMap();
}

//reset the map and all its stuctures to defualt layout
void scMap::resetMap()
{
    randomize = false;
    //Player 1
    numRoads1 = 0;
    numSettlement1 = 0;
    numCity1 = 0;
    //Resetting the position for the number of roads
    roadXCor1.resize(0);
    roadYCor1.resize(0);
    //Resetting the position for the number of settlements
    settlementXCor1.resize(0);
    settlementYCor1.resize(0);
    //Resetting the position for the number of Cities
    cityXCor1.resize(0);
    cityYCor1.resize(0);

    //Player2
    numRoads2 = 0;
    numSettlement2 = 0;
    numCity2 = 0;
    //Resetting the position for the number of roads
    roadXCor2.resize(0);
    roadYCor2.resize(0);
    //Resetting the position for the number of settlements
    settlementXCor2.resize(0);
    settlementYCor2.resize(0);
    //Resetting the position for the number of Cities
    cityXCor2.resize(0);
    cityYCor2.resize(0);
    //---------------------------------------------------------------------------------------------------------------------------
    //Restting the position of the robber
    for (int i = 0; i < 1; i++)
    {
        robPos[0] = -1;
        robPos[1] = -1;
    }
    //Resetting Map Graphical Data;
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            mapData[j][i] = " - ";
        }
    }
}

//Getting the Dimensions of Map
int scMap::getNumRows()
{
    return num_rows;
}
int scMap::getNumCols()
{
    return num_cols;
}

//Player 1-------------------------------------------------------------------------------------------------------------------

//Getting Values of Structures
int scMap::getNumRoads1()
{
    return numRoads1;
}
int scMap::getNumSettlement1()
{
    return numSettlement1;
}
int scMap::getNumCity1()
{
    return numCity1;
}

//Setting the value of structures
void scMap::setNumRoads1(int r)
{
    numRoads1 = r;
}
void scMap::setNumSettlement1(int s)
{
    numSettlement1 = s;
}
void scMap::setNumCity1(int c)
{
    numCity1 = c;
}
//Setting the position vectors
void scMap::setRoadXCor1(int rxc)
{
    roadXCor1.push_back(rxc);
}

void scMap::setRoadYCor1(int yxc)
{
    roadYCor1.push_back(yxc);
}

void scMap::setSettlementXCor1(int sxc)
{
    settlementXCor1.push_back(sxc);
}

void scMap::setSettlementYCor1(int syc)
{
    settlementYCor1.push_back(syc);
}

void scMap::setCityXCor1(int cxc)
{
    cityXCor1.push_back(cxc);
}

void scMap::setCityYCor1(int cyc)
{
    cityYCor1.push_back(cyc);
}

//Structures Getters
//Road
int scMap::getRoadAtXCor1(int index)
{
    if (index >= 0 && index < roadXCor1.size())
    {
        return roadXCor1.at(index);
    }
    else
    {
        return -1;
    }
}
int scMap::getRoadAtYCor1(int index)
{
    if (index >= 0 && index <= roadYCor1.size())
    {
        return roadYCor1.at(index);
    }
    else
    {
        return -1;
    }
}

//Settlement
int scMap::getSettlementAtXCor1(int index)
{
    if (index >= 0 && index < roadXCor1.size())
    {
        return settlementXCor1.at(index);
    }
    else
    {
        return -1;
    }
}
int scMap::getSettlementAtYCor1(int index)
{
    if (index >= 0 && index <= roadYCor1.size())
    {
        return settlementYCor1.at(index);
    }
    else
    {
        return -1;
    }
}

//City 
int scMap::getCityAtXCor1(int index)
{
    if (index >= 0 && index < cityXCor1.size())
    {
        return cityXCor1.at(index);
    }
    else
    {
        return -1;
    }
}
int scMap::getCityAtYCor1(int index)
{
    if (index >= 0 && index <= cityYCor1.size())
    {
        return cityYCor1.at(index);
    }
    else
    {
        return -1;
    }
}

//Getting the total size of the vectors
int scMap::getRoadXCorSize1()
{
    return roadXCor1.size();
}
int scMap::getRoadYCorSize1()
{
    return roadYCor1.size();
}

int scMap::getSettlementXCorSize1()
{
    return settlementXCor1.size();
}
int scMap::getSettlementYCorSize1()
{
    return settlementYCor1.size();
}

int scMap::getCityXCorSize1()
{
    return cityXCor1.size();
}
int scMap::getCityYCorSize1()
{
    return cityYCor1.size();
}

//Getting the Complete vector
//Road
vector<int> scMap::getRoadXCorVect1()
{
    return roadXCor1;
}
vector<int> scMap::getRoadYCorVect1()
{
    return roadYCor1;
}

//Settlement
vector<int> scMap::getSettlementXCorVect1()
{
    return settlementXCor1;
}
vector<int> scMap::getSettlementYCorVect1()
{
    return settlementYCor1;
}

//City
vector<int> scMap::getCityXCorVect1()
{
    return cityXCor1;
}
vector<int> scMap::getCityYCorVect1()
{
    return cityYCor1;
}

// add road to map
int scMap::spawnRoads1(int roadIndex)
{
    int col = roadXCor1[roadIndex - 1];
    int row = roadYCor1[roadIndex - 1];
    // // out of map bounds
    // if (!(row > 0 && row <= num_rows && col > 0 && col <= num_cols))
    // {
    //     cout << "Invalid Input" << endl;
    //     return -1;
    // }

    if (numRoads1 > 0)
    {
        for (int i = 1; i <= roadXCor1.size(); i++)
        {
            for (int j = 1; j <= roadYCor1.size(); j++)
            {
                // cout << "I: " << i << "J: " << j << endl;
                if (i == roadIndex && j == roadIndex)
                {
                    mapData[(roadXCor1.at(i - 1)) - 1][(roadYCor1.at(j - 1)) - 1] = "\x1b[31m - \x1b[0m";
                    cout << "X Coordinate for roads: " << roadXCor1.at(i - 1) << endl;
                    cout << "Y Coordinate for roads: " << roadYCor1.at(i - 1) << endl;
                }
            }
        }
        return 1;
    }
    return -1;
}

//add settlement to map:
int scMap::spawnSettlement1(int settlementIndex)
{
    int col = settlementXCor1[settlementIndex - 1];
    int row = settlementYCor1[settlementIndex - 1];
    // out of map bounds
    if (!(row > 0 && row <= num_rows && col > 0 && col <= num_cols))
    {
        cout << "Invalid Input" << endl;
        return -1;
    }

    if (numSettlement1 > 0)
    {
        for (int i = 1; i <= settlementXCor1.size(); i++)
        {
            for (int j = 1; j <= settlementYCor1.size(); j++)
            {
                // cout << "I: " << i << "J: " << j << endl;
                if (i == settlementIndex && j == settlementIndex)
                {
                    mapData[(settlementXCor1.at(i - 1)) - 1][(settlementYCor1.at(j - 1)) - 1] = "\x1b[31m ^ \x1b[0m";
                    cout << "X Coordinate for settlements: " << settlementXCor1.at(i - 1) << endl;
                    cout << "Y Coordinate for settlements: " << settlementYCor1.at(i - 1) << endl;
                }
            }
        }
        return 1;
    }
    return -1;
}

//add City to map:
int scMap::spawnCity1(int cityIndex)
{
    int col = cityXCor1[cityIndex - 1];
    int row = cityYCor1[cityIndex - 1];
    // out of map bounds
    if (!(row > 0 && row <= num_rows && col > 0 && col <= num_cols))
    {
        cout << "Invalid Input" << endl;
        return -1;
    }

    if (numCity1 > 0)
    {
        for (int i = 1; i <= cityXCor1.size(); i++)
        {
            for (int j = 1; j <= cityYCor1.size(); j++)
            {
                // cout << "I: " << i << "J: " << j << endl;
                if (i == cityIndex && j == cityIndex)
                {
                    mapData[(cityXCor1.at(i - 1)) - 1][(cityYCor1.at(j - 1)) - 1] = "\x1b[31m # \x1b[0m";
                    cout << "X Coordinate for cities: " << cityXCor1.at(i - 1) << endl;
                    cout << "Y Coordinate for cities: " << cityYCor1.at(i - 1) << endl;
                }
            }
        }
        return 1;
    }
    return -1;
}

//------------------------------------------------------------------------------------------------------------------------------

//Player 2-------------------------------------------------------------------------------------------------------------------

//Getting Values of Structures
int scMap::getNumRoads2()
{
    return numRoads2;
}
int scMap::getNumSettlement2()
{
    return numSettlement2;
}
int scMap::getNumCity2()
{
    return numCity2;
}

//Setting the value of structures
void scMap::setNumRoads2(int r)
{
    numRoads2 = r;
}
void scMap::setNumSettlement2(int s)
{
    numSettlement2 = s;
}
void scMap::setNumCity2(int c)
{
    numCity2 = c;
}
//Setting the position vectors
void scMap::setRoadXCor2(int rxc)
{
    roadXCor2
        .push_back(rxc);
}

void scMap::setRoadYCor2(int yxc)
{
    roadYCor2.push_back(yxc);
}

void scMap::setSettlementXCor2(int sxc)
{
    settlementXCor2.push_back(sxc);
}

void scMap::setSettlementYCor2(int syc)
{
    settlementYCor2.push_back(syc);
}

void scMap::setCityXCor2(int cxc)
{
    cityXCor2.push_back(cxc);
}

void scMap::setCityYCor2(int cyc)
{
    cityYCor2.push_back(cyc);
}

//Structures Getters
//Road
int scMap::getRoadAtXCor2(int index)
{
    if (index >= 0 && index < roadXCor2.size())
    {
        return roadXCor2.at(index);
    }
    else
    {
        return -1;
    }
}
int scMap::getRoadAtYCor2(int index)
{
    if (index >= 0 && index <= roadYCor2.size())
    {
        return roadYCor2.at(index);
    }
    else
    {
        return -1;
    }
}

//Settlement
int scMap::getSettlementAtXCor2(int index)
{
    if (index >= 0 && index < roadXCor2.size())
    {
        return settlementXCor2.at(index);
    }
    else
    {
        return -1;
    }
}
int scMap::getSettlementAtYCor2(int index)
{
    if (index >= 0 && index <= roadYCor2.size())
    {
        return settlementYCor2.at(index);
    }
    else
    {
        return -1;
    }
}

//City 
int scMap::getCityAtXCor2(int index)
{
    if (index >= 0 && index < cityXCor2.size())
    {
        return cityXCor2.at(index);
    }
    else
    {
        return -1;
    }
}
int scMap::getCityAtYCor2(int index)
{
    if (index >= 0 && index <= cityYCor2.size())
    {
        return cityYCor2.at(index);
    }
    else
    {
        return -1;
    }
}

//Getting the total size of the vectors
int scMap::getRoadXCorSize2()
{
    return roadXCor2.size();
}
int scMap::getRoadYCorSize2()
{
    return roadYCor2.size();
}

int scMap::getSettlementXCorSize2()
{
    return settlementXCor2.size();
}
int scMap::getSettlementYCorSize2()
{
    return settlementYCor2.size();
}

int scMap::getCityXCorSize2()
{
    return cityXCor2.size();
}
int scMap::getCityYCorSize2()
{
    return cityYCor2.size();
}

//Getting the Complete vector
//Road
vector<int> scMap::getRoadXCorVect2()
{
    return roadXCor2;
}
vector<int> scMap::getRoadYCorVect2()
{
    return roadYCor2;
}

//Settlement
vector<int> scMap::getSettlementXCorVect2()
{
    return settlementXCor2;
}
vector<int> scMap::getSettlementYCorVect2()
{
    return settlementYCor2;
}

//City
vector<int> scMap::getCityXCorVect2()
{
    return cityXCor2;
}
vector<int> scMap::getCityYCorVect2()
{
    return cityYCor2;
}

// add road to map
int scMap::spawnRoads2(int roadIndex)
{
    int col = roadXCor2[roadIndex - 1];
    int row = roadYCor2[roadIndex - 1];
    // out of map bounds
    if (!(row > 0 && row <= num_rows && col > 0 && col <= num_cols))
    {
        cout << "Invalid Input" << endl;
        return -1;
    }

    if (numRoads2 > 0)
    {
        for (int i = 1; i <= roadXCor2.size(); i++)
        {
            for (int j = 1; j <= roadYCor2.size(); j++)
            {
                // cout << "I: " << i << "J: " << j << endl;
                if (i == roadIndex && j == roadIndex)
                {
                    mapData[(roadXCor2.at(i - 1)) - 1][(roadYCor2.at(j - 1)) - 1] = "\x1b[36m - \x1b[0m";
                    cout << "X Coordinate for roads: " << roadXCor2.at(i - 1) << endl;
                    cout << "Y Coordinate for roads: " << roadYCor2.at(i - 1) << endl;
                }
            }
        }
        return 1;
    }
    return -1;
}

//add settlement to map:
int scMap::spawnSettlement2(int settlementIndex)
{
    int col = settlementXCor2[settlementIndex - 1];
    int row = settlementYCor2[settlementIndex - 1];
    // out of map bounds
    if (!(row > 0 && row <= num_rows && col > 0 && col <= num_cols))
    {
        cout << "Invalid Input" << endl;
        return -1;
    }

    if (numSettlement2 > 0)
    {
        for (int i = 1; i <= settlementXCor2.size(); i++)
        {
            for (int j = 1; j <= settlementYCor2.size(); j++)
            {
                // cout << "I: " << i << "J: " << j << endl;
                if (i == settlementIndex && j == settlementIndex)
                {
                    mapData[(settlementXCor2.at(i - 1)) - 1][(settlementYCor2.at(j - 1)) - 1] = "\x1b[36m ^ \x1b[0m";
                    cout << "X Coordinate for settlements: " << settlementXCor2.at(i - 1) << endl;
                    cout << "Y Coordinate for settlements: " << settlementYCor2.at(i - 1) << endl;
                }
            }
        }
        return 1;
    }
    return -1;
}

//add City to map:
int scMap::spawnCity2(int cityIndex)
{
    int col = cityXCor2[cityIndex - 1];
    int row = cityYCor2[cityIndex - 1];
    // out of map bounds
    if (!(row > 0 && row <= num_rows && col > 0 && col <= num_cols))
    {
        cout << "Invalid Input" << endl;
        return -1;
    }

    if (numCity2 > 0)
    {
        for (int i = 1; i <= cityXCor2.size(); i++)
        {
            for (int j = 1; j <= cityYCor2.size(); j++)
            {
                // cout << "I: " << i << "J: " << j << endl;
                if (i == cityIndex && j == cityIndex)
                {
                    mapData[(cityXCor2.at(i - 1)) - 1][(cityYCor2.at(j - 1)) - 1] = "\x1b[36m # \x1b[0m";
                    cout << "X Coordinate for cities: " << cityXCor2.at(i - 1) << endl;
                    cout << "Y Coordinate for cities: " << cityYCor2.at(i - 1) << endl;
                }
            }
        }
        return 1;
    }
    return -1;
}
//--------------------------------------------------------------------------------------------------------------------------------

//Robber Implementation
    //Spawning the robber
    void scMap::spawnRob(){

        srand(time(NULL));
        int randX = (rand() % num_cols) + 1;
        int randY = (rand() % num_rows) + 1;
        robPos[0] = randX;
        robPos[1] = randY;
       
    }
    //Getting the robber position
    int scMap::getRobPosAt(int index){
        return robPos[index];
    }
    //Resetting the robber position
    void scMap::resetRobPos(){
        robPos[0] = -1;
        robPos[1] = -1;
    }

void scMap::displayMap()
{
    string dash = " - ";
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            // cout << dash;
            if (numRoads1 > 0)
            {
                dash = mapData[j][i];
            }
            cout << dash;
        }
        cout << endl;
    }
}



void scMap::displayResMap()
{
    srand(time(NULL));
    string resString[5] = {"[\U0001F40F]","[\U0001FAA8 ]","[\U0001F33E]","[\U0001F9F1]","[\U0001FAB5 ]"};
    if(randomize == false){
        for (int i = 0; i < num_rows; i++)
        {
            for (int j = 0; j < num_cols; j++)
            {
                int rollNum = (rand() % 12) + 1;
                if(rollNum == 7){
                    int choice = (rand() % 2) +1;
                    if(choice ==1){
                        rollNum = 8;
                    }
                    else if(choice == 2){
                        rollNum = 6;
                    }
                }
                else if(rollNum == 1)
                {
                    rollNum = 2;
                }

                int randRes = (rand() % 5);
                // cout <<"random number is " <<  randRes;
                resMapData[i][j] = resString[randRes];
                resRollNumData[i][j] = rollNum;
                cout << setw(2) << setfill('0') <<  rollNum << resMapData[i][j] << " ";
                
            }
            cout << endl;
        }
        randomize = true;
    }
    else if(randomize == true){
        for (int i = 0; i < num_rows; i++)
        {
            for (int j = 0; j < num_cols; j++)
            {
                cout << setw(2) << setfill('0') <<  resRollNumData[i][j] << resMapData[i][j] << " ";
            }
            cout << endl;
        }
    }

    
}

//Getting map data infomation
string scMap::getMapDataCharAt(int j, int i){
     j = j - 1;
    i = i - 1;
    return mapData[j][i];
}
void scMap::setMapDataCharAt(string ch, int tempCityXCor1, int tempCityYCor1)
{
    for (int i = 0; i < num_rows; i++)
            {
                for (int j = 0; j < num_cols; j++)
                {
                    mapData[tempCityXCor1 - 1][tempCityYCor1 - 1] = ch;
                    
                }
            }
}

//getting resource information
string scMap::getResAtPos(int j, int i) {
    j = j - 1;
    i = i - 1;
    return resMapData[i][j];
}

int scMap::getResNumAtPos(int j, int i) {
    j = j - 1;
    i = i - 1;
    return resRollNumData[i][j];
}

