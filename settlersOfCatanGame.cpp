//Classes To Include
#include "scMap.h"
#include "Player1.h"
#include "Player2.h"
#include "Structures.h"
#include "Dev.h"
#include "Leaderboard.h"
#include "diceRoll.h"
//Libraries To Include
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

//checking to see if the map is full
bool mapFull (scMap* scMap){
   int num_cols = scMap->getNumCols();
   int num_rows = scMap->getNumRows();
   int total = num_cols * num_rows;
   int count = 0;

    for (int i = 0; i < num_cols; i++)
    {
        for (int j = 0; j < num_rows; j++)
        {
           if(scMap ->getMapDataCharAt(j,i) != " - "){
               count ++;
               if(count == total){
               return true;
               }
           }
           
        }
    }
    return false;
}

//Checking to see if input is integer function
bool is_integer(float k)
{
return floor(k) == k;
}
//Instructions
void displayInstructions(){
cout << "You will begin your turn by rolling both dice. The sum of the dice corresponds to a coordinate on the map, \n and each coordinate corresponds to a resource.  If you have a settlement built on the coordinate,\n you will gain 1 of the corresponding resource. " << endl;
cout << "—----------------------------------------------------------------------------------------------------------------------------" << endl;
cout << "The objective of the game is to be the first person to reach 11 victory points \nHow to get victory points? \n -Largest army \n  You can purchase Development cards from the menu, with the chance of pulling a Soldier card. Whoever has the most soldiers at the end of the game gains 1 victory point. \n -Settlements \n  For every additional settlement you build, you gain 1 victory point \n -City \n  You cannot build a city directly, you can only upgrade an existing settlement to a city, Every city is worth 2 victory points." << endl;
cout << "—----------------------------------------------------------------------------------------------------------------------------" << endl;
cout << " Purchasing- \n You may purchase items on your turn after you have rolled. To an item purchase, you must turn \n in the specified amount of resources. You may purchase as many items as you like, as long as \n you have enough resources to pay for them." << endl;
cout << " Placing Items-" << endl;
cout<< "  To place an item, you must first have it in your inventory. You can check your inventory during" << endl;
cout << "  your turn by clicking option" << " 3 " << "." << endl;
cout << "  To place a settlement, it must be surrounded by 2 roads.   - - ^ | | ^ - - | | -   | | ^ " << endl;
cout << "									         -       - " << endl;
cout << "								                 ^       - " << endl;
cout << "—----------------------------------------------------------------------------------------------------------------------------" << endl;
cout << "Every time you purchase a development card, you have the chance of pulling a fortune or misfortune card \n There are 5 different kinds of development cards. \n -Three of them are fortune cards: +1 soldier, +2 sheep, +2 roads. \n -Two are misfortune cards: -1 wheat, and a card that wipes all of your sheep." << endl;
cout << endl;
cout << endl;
cout << endl;
}
//checking to see if name has a colon
bool colonFound (string playerName){
    size_t colonInd = playerName.find(':');
    if(colonInd <= 0 && colonInd > playerName.length()){
        cout<< "Invalid Input. Please do not enter" << ":" << endl;
        return 1;
    }
    return 0;
}

//display end image funcions
void displayEnd(string playerName)
{
    cout << "                                                                           .                                                    " << endl;
    cout << "                                                       *                  ,*                                                      " << endl;
    cout << "                                                       **                ,*,                                                      " << endl;
    cout << "                                                       *,,.             ***,                                                      " << endl;
    cout << "                                    ,                  ,***.           ****,                 ,                                    " << endl;
    cout << "                                      ,*               *,***,         **,**,              **,                                     " << endl;
    cout << "                                       *,**.           *,*****      .******,           ****.                                      " << endl;
    cout << "                                        ******.        *******,    ,*******.        ******                                        " << endl;
    cout << "                                         ,*******,     ,*****,*,  ,*,******.     *******,                                         " << endl;
    cout << "                                          .,********,  .                   .  *********,                                          " << endl;
    cout << "                                            *******    ,****************,**.   .,****,,                                           " << endl;
    cout << "                          *****,.            ***   ,************,**************.  .*,             ,***,,,                         " << endl;
    cout << "                             **********,**,     ,********************************,     .*************.                            " << endl;
    cout << "                                ,***********  ,*,***************,***************,***  .***********                                " << endl;
    cout << "                                   ,******,  ****************************************,  *******                                   " << endl;
    cout << "                                      .**,  ********************,*********************,  ***                                      " << endl;
    cout << "                                           ********************************************,                                          " << endl;
    cout << "                                          ********************************************,                                           " << endl;
    cout << "                                .,******  .*********************,**********************,  ,****,*,.                               " << endl;
    cout << "                                .,******  .*********************,**********************,  ,****,*,.                               " << endl;
    cout << "                     .,***,*************  ,*********************************************  ,*************,*,*,,                    " << endl;
    cout << endl;
    cout << "                                                      CONGRATULATIONS " << playerName << "                                   " << endl; 
    cout <<"                                                                   YOU WIN                                                   " << endl;
}

//Conditional Functions To Purchase 
    //Function To Test Purchasing
    bool condFuncToPurch( int choiceStruct , int brick, int wood, int grain, int sheep, int ore){
        //Can Purchase Road?
        if(choiceStruct == 1){
            if( brick >= 1 && wood >= 1){
                return true;
            }
            else
            {
                return false;
            }
        }
        //Can Purchase Settlement
        else if(choiceStruct == 2){
            if( brick >= 1 && wood >= 1 && grain >=1 && sheep >= 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        //Can Purchase City
        else if(choiceStruct == 3){
            if(grain >= 2 && ore >= 3)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        // Can Purchase Dev Card
        else if(choiceStruct == 4){
            if(grain >= 1 && sheep >= 1 && ore >=1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else{
            cout << "Invalid Input." << endl;
        }
        return false;
    }

void PurchStruct(int playerChoice, int choiceStruct, Structures* Structures, Dev* Dev, Player1* p1, Player2* p2)
{
        int currentAmntStruct1;
        int currentAmntRes1;
        int currentAmntStruct2;
        int currentAmntRes2;
    //Player 1
    if(playerChoice ==1)
    {
        //Road
        if(choiceStruct == 1)
        {
            currentAmntStruct1 = Structures->getNumRoad1();
            Structures->setNumRoad1(currentAmntStruct1 + 1);
            currentAmntRes1 = p1->getResourceAt(0);
            //subtracting resources for road
                //Subtracting 1 Brick
                currentAmntRes1 = p1->getResourceAt(0);
                p1->setResourceAt(0, currentAmntRes1-1);
                //Subtracting 1 Wood
                currentAmntRes1 = p1->getResourceAt(1);
                p1->setResourceAt(1, currentAmntRes1-1);
        }
        //Settlement
        else if(choiceStruct == 2)
        {
            currentAmntStruct1 = Structures->getNumSettlement1();
            Structures->setNumSettlement1(currentAmntStruct1 + 1);
            //subtracting resources for settlement
                //Subtracting 1 Brick
                currentAmntRes1 = p1->getResourceAt(0);
                p1->setResourceAt(0, currentAmntRes1-1);
                //Subtracting 1 Wood
                currentAmntRes1 = p1->getResourceAt(1);
                p1->setResourceAt(1, currentAmntRes1-1);
                //Subtracting 1 Grain
                currentAmntRes1 = p1->getResourceAt(2);
                p1->setResourceAt(2, currentAmntRes1-1);
                //Subtracting 1 Sheep
                currentAmntRes1 = p1->getResourceAt(3);
                p1->setResourceAt(3, currentAmntRes1-1);
        }
        //City
        else if(choiceStruct == 3)
        {
            currentAmntStruct1 = Structures->getNumCities1();
            Structures->setNumCities1(currentAmntStruct1 + 1);
            //subtracting resources for City
                //Subtracting 2 grain
                currentAmntRes1 = p1->getResourceAt(2);
                p1->setResourceAt(2, currentAmntRes1-2);
                //Subtracting 3 Ore
                currentAmntRes1 = p1->getResourceAt(4);
                p1->setResourceAt(4, currentAmntRes1-3);
        }
        //Dev Card
        else if(choiceStruct == 4)
        {
            currentAmntStruct1 = Dev->getNumDevCards1();
            Dev->setNumDevCards1(currentAmntStruct1 + 1);
            //subtracting resources for Dev Card
                //Subtracting 1 Grain
                currentAmntRes1 = p1->getResourceAt(2);
                p1->setResourceAt(2, currentAmntRes1-1);
                //Subtracting 1 Sheep
                currentAmntRes1 = p1->getResourceAt(3);
                p1->setResourceAt(3, currentAmntRes1-1);
                //Subtracting 1 Ore
                currentAmntRes1 = p1->getResourceAt(4);
                p1->setResourceAt(4, currentAmntRes1-1);  
        }
    }
    //Player 2
    else if(playerChoice ==2)
    {
        //Road
        if(choiceStruct == 1){
            currentAmntStruct2 = Structures->getNumRoad2();
            Structures->setNumRoad2(currentAmntStruct2 + 1);
            //subtracting resources for road
                //Subtracting 1 Brick
                currentAmntRes2 = p2->getResourceAt(0);
                p2->setResourceAt(0, currentAmntRes2-1);
                //Subtracting 1 Wood
                currentAmntRes2 = p2->getResourceAt(1);
                p2->setResourceAt(1, currentAmntRes2-1);
        }
        //Settlement
        else if(choiceStruct == 2){
            currentAmntStruct2 = Structures->getNumSettlement2();
            Structures->setNumSettlement2(currentAmntStruct2 + 1);
            //subtracting resources for settlement
                //Subtracting 1 Brick
                currentAmntRes2 = p2->getResourceAt(0);
                p2->setResourceAt(0, currentAmntRes2-1);
                //Subtracting 1 Wood
                currentAmntRes2 = p2->getResourceAt(1);
                p2->setResourceAt(1, currentAmntRes2-1);
                //Subtracting 1 Grain
                currentAmntRes2 = p2->getResourceAt(2);
                p2->setResourceAt(2, currentAmntRes2-1);
                //Subtracting 1 Sheep
                currentAmntRes2 = p2->getResourceAt(3);
                p2->setResourceAt(3, currentAmntRes2-1);
        }
        //City
        else if(choiceStruct == 3){
            currentAmntStruct2 = Structures->getNumCities2();
            Structures->setNumCities2(currentAmntStruct2 + 1);
            //subtracting resources for City
                //Subtracting 2 grain
                currentAmntRes2 = p2->getResourceAt(2);
                p2->setResourceAt(2, currentAmntRes2-2);
                //Subtracting 3 Ore
                currentAmntRes2 = p2->getResourceAt(4);
                p2->setResourceAt(4, currentAmntRes2-3);
        }
        //Dev Card
        else if(choiceStruct == 4){
            currentAmntStruct2 = Dev->getNumDevCards2();
            Dev->setNumDevCards2(currentAmntStruct2 + 1);
            //subtracting resources for Dev Card
                //Subtracting 1 Grain
                currentAmntRes2 = p2->getResourceAt(2);
                p2->setResourceAt(2, currentAmntRes2-1);
                //Subtracting 1 Sheep
                currentAmntRes2 = p2->getResourceAt(3);
                p2->setResourceAt(3, currentAmntRes2-1);
                //Subtracting 1 Ore
                currentAmntRes2 = p2->getResourceAt(4);
                p2->setResourceAt(4, currentAmntRes2-1);
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------------------

// CASE INSENSITVE FUNCTION
string toUpper(string str)
{
    int strLength = str.length();
    for (int i = 0; i < strLength; i++ )
    {
        if(str[i] >= 97 && str[i] < 122)
        {
            str[i] = str[i] - 32;
        }
    }
    return str;
}

//Display Building Costs Function
void displayBuildCosts()
{
    cout << "Building Costs:" << endl;
    cout << "---------------------" << endl;
    cout << "Road:" << endl;
    cout << "[\U0001F9F1]" << "[\U0001FAB5 ]" << "           " << "\x1b[32m-\x1b[0m" << endl;
    cout << "---------------------" << endl;
    cout << "Settlement:" << endl;
    cout << "[\U0001F9F1]" << "[\U0001FAB5 ]" << "[\U0001F33E]" << "[\U0001F40F]" << "   " << "\x1b[32m^\x1b[0m" << endl;
    cout << "---------------------" << endl;
    cout << "City:" << endl;
    cout << "[\U0001F33E]" << "[\U0001F33E]" << "[\U0001F33E]" << "[\U0001FAA8]" << "[\U0001FAA8]" " " << "\x1b[32m#\x1b[0m" << endl;
    cout << "---------------------" << endl;
    cout << "Development Card:" << endl;
    cout << "[\U0001F33E]" << "[\U0001F40F]" << "[\U0001FAA8]" << "       " << "[\U0001F0CF]" << endl;
}

//Conditional Function to Store Resources
void CondFuncStoreRec(int diceRoll, scMap* scMap, Player1* p1, Player2* p2 )
{  
    int num_cols = scMap->getNumCols();
    int num_rows = scMap->getNumRows();
    string gotRes = "";
    vector <int> dicePosX;
    vector <int> dicePosY;
    for(int i = 0; i < num_cols; i++)
    {
        for(int j = 0; j < num_rows; j++)
        {
            int resIndex;
           if(diceRoll == scMap->getResNumAtPos(j,i))
           {
               //Getting the Resource at that position
                gotRes = scMap->getResAtPos(j,i);
                //If GotRes = brick
                if(gotRes == "[\U0001F9F1]")
                {
                    resIndex = 0;
                }
                //If GotRes = Wood
                else if(gotRes == "[\U0001FAB5 ]")
                {
                    resIndex = 1;
                }
                //If GotRes = Grain
                else if(gotRes == "[\U0001F33E]")
                {
                    resIndex = 2;
                }
                //If GotRes = sheep
                else if(gotRes == "[\U0001F40F]"){
                    resIndex = 3;
                }
                //If GoRes = Ore
                else if(gotRes == "[\U0001FAA8 ]"){
                    resIndex = 4;
                }
                //Player 1
                if(scMap->getMapDataCharAt(j,i) == "\x1b[31m ^ \x1b[0m")
                {
                    int currAmount = p1->getResourceAt(resIndex);
                    p1->setResourceAt(resIndex, currAmount +1);
                }
                else if(scMap->getMapDataCharAt(j,i) == "\x1b[31m # \x1b[0m")
                {
                    int currAmount = p1->getResourceAt(resIndex);
                    p1->setResourceAt(resIndex,currAmount + 2);
                }
                //Player 2
                if(scMap->getMapDataCharAt(j,i) == "\x1b[36m ^ \x1b[0m")
                {
                    int currAmount = p2->getResourceAt(resIndex);
                    p2->setResourceAt(resIndex, currAmount +1);
                }
                else if(scMap->getMapDataCharAt(j,i) == "\x1b[36m # \x1b[0m")
                {
                    int currAmount = p2->getResourceAt(resIndex);
                    p2->setResourceAt(resIndex,currAmount + 2);
                }
            }
        }
    }
}

//Devcard Outcomes Function
void outcomeGenerator1(Dev *Dev, Structures *Structures, Player1 *p1)
{
    srand(time(NULL));
    int outcome = (rand() % 5) + 1;
    if (outcome == 1)
    {
        //adding 1 soldier
        int numSoldiers = Dev->getNumSoldiersP1();
        Dev->setNumSoldiersP1(numSoldiers + 1);
        cout << "Levi the ROTC kid is now your soldier." << endl;
        cout << "+1 Soldier" << endl;
    }
    if (outcome == 2)
    {
        //add 2 to the sheep
        int numSheep = p1->getResourceAt(3);
        p1->setResourceAt(3, numSheep + 2);
        cout << "Prabhnoor genetically engineered two sheep, enjoy!" << endl;
        cout << "+2 Sheep" << endl;
    }
    if (outcome == 3)
    {
        //adding 2 roads
        int numRoads = Structures->getNumRoad1();
        Structures->setNumRoad1(numRoads + 2);
        cout << "Nam the civil engineer made two extra roads for you, enjoy!" << endl;
        cout << "+2 Roads" << endl;
    }
    if (outcome == 4)
    {
        // -1 wheat
        // p1.setResourceAt(1, 3);
        int numWheat = p1->getResourceAt(1);
        if (numWheat > 0)
        {
            p1->setResourceAt(1, numWheat - 1);
            cout << "The Sheep named Vinny who had celiac diease ate your wheat... Hope he is okay." << endl;
            cout << "-1 Sheep" << endl;
        }
        else
        {
            cout << "Nothing happened! Tough Luck Loser!" << endl;
        }
    }
    if (outcome == 5)
    {
        // set numSheep to 0
        p1->setResourceAt(3, 0);
        cout << "A disease wiped out all your sheep." << endl;
    }
}
void outcomeGenerator2(Dev *Dev, Structures *Structures, Player2 *p2)
{
    srand(time(NULL));
    int outcome = (rand() % 5) + 1;
    if (outcome == 1)
    {
        //adding 1 soldier
        int numSoldiers = Dev->getNumSoldiersP2();
        Dev->setNumSoldiersP2(numSoldiers + 1);
        cout << "Levi the ROTC kid is now your soldier." << endl;
        cout << "+1 Soldier" << endl;
    }
    if (outcome == 2)
    {
        //add 2 to the sheep
        int numSheep = p2->getResourceAt(3);
        p2->setResourceAt(3, numSheep + 2);
        cout << "Prabhnoor genetically engineered two sheep, enjoy!" << endl;
        cout << "+2 Sheep" << endl;
    }
    if (outcome == 3)
    {
        //adding 2 roads
        int numRoads = Structures->getNumRoad2();
        Structures->setNumRoad2(numRoads + 2);
        cout << "Nam the civil engineer made two extra roads for you, enjoy!" << endl;
        cout << "+2 Roads" << endl;
    }
    if (outcome == 4)
    {
        // -1 wheat
        // p2.setResourceAt(1, 3);
        int numWheat = p2->getResourceAt(1);
        if (numWheat > 0)
        {
            p2->setResourceAt(1, numWheat - 1);
            cout << "The Sheep named Vinny who had celiac diease ate your wheat... Hope he is okay." << endl;
            cout << "-1 Sheep" << endl;
        }
        else
        {
            cout << "Nothing happened! Tough Luck Loser!" << endl;
        }
    }
    if (outcome == 5)
    {
        // set numSheep to 0

        p2->setResourceAt(3, 0);
        cout << "A disease wiped out all your sheep." << endl;
    }
}

//Conditional function to assign Victory Points to Players
void condFuncVicPoints(scMap* scMap, Player1* p1, Player2* p2, Dev* Dev){
    //If player places a settlement
        //Player 1
        int amntSettlementVP1 = scMap->getNumSettlement1();
        amntSettlementVP1 -= 2;  
        //Player 2
        int amntSettlementVP2 = scMap->getNumSettlement2();
        amntSettlementVP2 -= 2; 
    //If player places a city
        //Player1
        int amntCityVP1 = scMap->getNumCity1();
        int amntCityVP2 = scMap->getNumCity2();
        if(amntCityVP1 > 0){
            amntCityVP1 = amntCityVP1 * 2;
        }
        if(amntCityVP2 > 0){
            amntCityVP2 = amntCityVP2 * 2;
        }
    //Largest army
    int numSoldier1 = Dev->getNumSoldiersP1();
    int numSoldier2 = Dev->getNumSoldiersP2();
    int armyVP1 = 0;
    int armyVP2 = 0; 
    //If Player 1 has more soldiers
    if(numSoldier1 > numSoldier2){
       armyVP1 = 1; 
       armyVP2 = 0;
    }
    else if(numSoldier2 > numSoldier1 )
    {
        armyVP2 = 1;
        armyVP1 = 0;
    }

        int currentVicPoint1 = p1->getVicPoints();
        int currentVicPoint2 = p2->getVicPoints();
        p1->setVicPoints(amntSettlementVP1 + amntCityVP1 + armyVP1);
        p2->setVicPoints(amntSettlementVP2 + amntCityVP2 + armyVP2);
    
}

//---------------------------------------------------------------------------------------------------------------------------------
//Leaderboard Functions
//split function
int split(string line, char delim, string arr[], int size)
{
    //Intializing Variables
    int pos;
    int newPos = 0;
    int k = 0;
    int oldPos = 0;
    int index = 0;
    //Do-while Loop
    do
    {
        pos = line.find(delim, newPos);

        if (pos >= 0)
        {
            newPos = pos;
            arr[k] = line.substr(oldPos, newPos - oldPos);
            newPos++;
            oldPos = newPos;
            k++;
        }
    } while (pos >= 0);

    arr[k] = line.substr(oldPos, line.length());
    for (int i = 0; i < size; i++)
    {
        //cout << arr[i] << endl;
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != "")
        {
            index = index + 1;
        }
    }
    return index;
}
//-----------------------------------------------------------------------------------------------------------------------
int sortName(int count, Leaderboard names[])
{
    int numWins = 4;

    string line;
 
    int temp = 0;
    string tempName; 

    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {

            if (names[i].getNumWins() < names[j].getNumWins())
            {
                temp = names[i].getNumWins();
                names[i].setNumWins(names[j].getNumWins());
                names[j].setNumWins(temp);

                //sorting through the names
                tempName = names[i].getPlayerName();
                names[i].setPlayerName(names[j].getPlayerName());
                names[j].setPlayerName(tempName);
            }
        }
    }
    // myReadFile.close();
    fstream myReadFile;
    myReadFile.open("victoryLog.txt");
    for (int i = 0; i < count; i++)
    {
        myReadFile << names[i].getPlayerName() << ": " << names[i].getNumWins() << endl;
    }

return count;
}
string addName(int count, Leaderboard names[], string playerName)
{
    // we need to open the file and create the arrays, and read the files
    bool found = false;
    int index;
    // populating the text file
    int numWins = 0;
    int wins = 0;
    int newNumWins = 0;

    // Open File
    fstream myReadFile;
    myReadFile.open("victoryLog.txt", ofstream::app);

    // //checking for repeats
    // use a to upper function and compare the input name to the names in the array
    // if it matches, Don't add a new name, add the numWins to that name

    for (int i = 0; i < count; i++)
    {
        if (toUpper(names[i].getPlayerName()) == toUpper(playerName))
        {
            index = i;
            found = true;
            wins = names[i].getNumWins();
        }
    }

    if (found == false)
    {

        myReadFile << playerName << ": " << numWins << endl;

        
    }
    
   
    return playerName;

}

void displayLeaderboard(int count, Leaderboard names[])
{
    for (int i = 0; i < count; i++)
    {
        sortName(count,names);
        cout << names[i].getPlayerName() << ": " << names[i].getNumWins() << endl;
    }
}

void addWins(int count, Leaderboard names[], string playerName)
{

    // we need to open the file and create the arrays, and read the files
    int index;
    // populating the text file
    int numWins = 0;
    int wins = 0;
    int newNumWins = 0;

    // Open File
    fstream myReadFile;
    myReadFile.open("victoryLog.txt");

    // //checking for repeats
    // use a to upper function and compare the input name to the names in the array
    // if it matches, Don't add a new name, add the numWins to that name

    for (int i = 0; i < count; i++)
    {
        if (toUpper(names[i].getPlayerName()) == toUpper(playerName))
        {
            index = i;
            wins = names[i].getNumWins();
        }
    }

    // myReadFile << playerName << ": " << numWins << endl;

    // myReadFile << p2name << ": " << numWins << endl;

    newNumWins = wins + 1;
    names[index].setNumWins(newNumWins);
    //at "index", we want to write the new num wins to the array
    myReadFile.close();
    myReadFile.open("victoryLog.txt");
    for (int i = 0; i < count; i++)
    {
        myReadFile << names[i].getPlayerName() << ": " << names[i].getNumWins() << endl;
    }
}
//---------------------------------------------------------------------------------------------------------------------------------
//PLAYER 1 FUNCTIONS
    //Display Player 1 Inventory
    void displayPlayer1Inventory(Player1* p1)
    {
        cout << "\x1b[31m----------\x1b[0m" << "\x1b[31mPLAYER 1 Inventory\x1b[0m" << "\x1b[31m----------\x1b[0m" << endl;
        //Brick
        cout << "Number of " << "[\U0001F9F1] " << "is: " << p1->getResourceAt(0) << endl;
        //Wood
        cout << "Number of " << "[\U0001FAB5]" << "is: " << p1->getResourceAt(0) << endl;
        //Grain
        cout << "Number of " << "[\U0001F33E]" << "is: " << p1->getResourceAt(2) << endl;
        //Sheep
        cout << "Number of " << "[\U0001F40F]" << "is: " << p1->getResourceAt(3) << endl;
        //Ore
        cout << "Number of " << "[\U0001FAA8]" << "is:" << p1->getResourceAt(4) << endl;
    }
    //Display Player 1's Item Inventory
    void displayP1Item(Structures* Structures, Dev* Dev)
    {
        cout << "\x1b[31m----------\x1b[0m" << "\x1b[31mPLAYER 1 ITEMS Inventory\x1b[0m" << "\x1b[31m----------\x1b[0m" << endl;
        cout << "Number of Roads " << "\x1b[31m-\x1b[0m : "  << Structures->getNumRoad1() << endl;
        cout << "Number of Settlements " << "\x1b[31m^\x1b[0m : " << Structures->getNumSettlement1() << endl;
        cout << "Number of City " << "\x1b[31m#\x1b[0m : " << Structures->getNumCities1() << endl;
        cout << "Number of Dev Cards " << "\x1b[31m[\U0001F0CF]\x1b[0m: " << Dev->getNumDevCards1() << endl;
    }
    
    //Function to check whether there are two roads before the settlement either, above, below, to the left, or to the right
    bool twoRdsBefore1(int tempSettlementX, int tempSettlementY, scMap* scMap){
        bool rdsBefore = false;
        if(tempSettlementX > 0 && tempSettlementY <= 18)
        {
            //there are two roads before the settlement on the left side
            if(scMap->getMapDataCharAt(tempSettlementX-1, tempSettlementY) == "\x1b[31m - \x1b[0m" && scMap->getMapDataCharAt(tempSettlementX-2, tempSettlementY) == "\x1b[31m - \x1b[0m")
            {
                rdsBefore = true;
            }
            //there are two roads on the right side of the settlement
            else if(scMap->getMapDataCharAt(tempSettlementX+1, tempSettlementY) == "\x1b[31m - \x1b[0m" && scMap->getMapDataCharAt(tempSettlementX+2, tempSettlementY) == "\x1b[31m - \x1b[0m")
            {
            rdsBefore = true;
            }
            //there are two rs above the settlement
            else if(scMap->getMapDataCharAt(tempSettlementX, tempSettlementY+1) == "\x1b[31m - \x1b[0m" && scMap->getMapDataCharAt(tempSettlementX, tempSettlementY + 2) == "\x1b[31m - \x1b[0m")
            {
                rdsBefore = true;
            }
            //there are two roads below the settlement
            else if(scMap->getMapDataCharAt(tempSettlementX,tempSettlementY-1) == "\x1b[31m - \x1b[0m" && scMap->getMapDataCharAt(tempSettlementX, tempSettlementY-2) == "\x1b[31m - \x1b[0m")
            {
                rdsBefore = true;
            }
            else
            {
                rdsBefore = false;
            }
        }
        return rdsBefore;
    }
    //Structures
        void addingToMapRoad1(scMap* scMap, Structures* Structures){
            int tempRoadX1 = 0;
            int tempRoadY1 = 0;
            float x1 = 0;
            float y1 = 0;

            int roadPurch1 = scMap->getNumRoads1();
            int num_cols =scMap->getNumCols(); 
            int num_rows =scMap->getNumRows();
            if (roadPurch1 > 0)
            {
                for (int i = 0; i < roadPurch1; i++)
                {
                    while (true)
                    {
                        cout << "Enter an x coordinate of road " << i + 1 << endl;
                        cin >> x1;
                        if ((x1 > 0 && x1 <= num_cols) && (is_integer(x1) == true))
                        {
                            tempRoadX1 = int(x1);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Input for X coordinate." << endl;
                            cin.clear();
                            cin.ignore(80, '\n');
                        }
                        
                    }
                    while (true)
                    {
                        cout << "Enter an y coordinate of road " << i + 1 << endl;
                        cin >> y1;
                        if ((y1 > 0 && y1 <= num_cols) && (is_integer(y1) == true))
                        {
                            tempRoadY1 = int(y1);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Input for y coordinate." << endl;
                            cin.clear();
                            cin.ignore(80, '\n');
                        }
                    }
                    if(scMap->getMapDataCharAt(tempRoadX1, tempRoadY1) != " - "){
                        cout << "Structure already present." << endl;
                        i -= 1;
                    }
                    else
                    {
                        scMap->setRoadXCor1(tempRoadX1);
                        scMap->setRoadYCor1(tempRoadY1);
                        scMap->spawnRoads1(i+1);
                    }
                }
                scMap->displayMap();
                cout << endl;
                scMap->displayResMap();
            }
        }
        void addingToMapRoadCont1(scMap* scMap, Structures* Structures)
        {
            int tempRoadX1 = 0;
            int tempRoadY1 = 0;
            float x1 = 0;
            float y1 = 0;
            int roadPurchCont1 = Structures->getNumRoad1();
            int currAmountUpdateRd = 0;
            int num_cols =scMap->getNumCols(); 
            int num_rows =scMap->getNumRows();
            if (roadPurchCont1 > 0)
            {
                while (true)
                {   
                    while (true)
                    {
                        cout << "Enter an x coordinate of road " << endl;
                        cin >> x1;
                        if ((x1 > 0 && x1 <= num_cols) && (is_integer(x1) == true))
                        {
                            tempRoadX1 = int(x1);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Input for X coordinate." << endl;
                            cin.clear();
                            cin.ignore(80, '\n');
                        }
                    }
                    while (true)
                    {
                        cout << "Enter an y coordinate of road. "<< endl;
                        cin >> y1;
                        if (y1 > 0 && y1 <= num_rows && (is_integer(y1) == true))
                        {
                            tempRoadY1 = int(y1);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Input for y coordinate." << endl;
                            cin.clear();
                            cin.ignore(80, '\n');
                        }
                    }
                    if(scMap->getMapDataCharAt(tempRoadX1, tempRoadY1) != " - ")
                    {
                        cout << "Structure already present." << endl;
                    }
                    else
                    {
                        cout << "is Running" << endl;
                        scMap->setRoadXCor1(tempRoadX1);
                        scMap->setRoadYCor1(tempRoadY1);
                        scMap->spawnRoads1((scMap->getNumRoads1())+1);
                        currAmountUpdateRd = scMap ->getNumRoads1();
                        scMap->setNumRoads1(currAmountUpdateRd +1);
                        break;
                    }
                }
            }
            scMap->displayMap();
            cout << endl;
            scMap->displayResMap();
        }

        bool addingToMapSettlement1(scMap* scMap, Structures* Structures){
            int tempSettlementX1 = 0;
            int tempSettlementY1 = 0;
            float x1 = 0;
            float y1 = 0;
            int settlementPurch1 = scMap->getNumSettlement1();
            int num_cols =scMap->getNumCols(); 
            int num_rows =scMap->getNumRows();
            if (settlementPurch1 > 0)
            {
                for (int i = 0; i < settlementPurch1; i++)
                {
                    while (true)
                    {
                        cout << "Enter an x coordinate of settlement " << i + 1 << endl;
                        cin >> x1;
                        if ((x1 > 0 && x1 <= num_cols)  && (is_integer(x1) == true))
                        {
                            tempSettlementX1 = int(x1);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Input." << endl;
                            cin.clear();
                            cin.ignore(80, '\n');
                        }
                    }
                    while (true)
                    {
                        cout << "Enter an y coordinate of settlement " << i + 1 << endl;
                        cin >> y1;
                        if ((y1 > 0 && y1 <= num_rows) && (is_integer(y1) == true))
                        {
                            tempSettlementY1 = int(y1);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Input" << endl;
                            cin.clear();
                            cin.ignore(80, '\n');
                        }
                    }
                    cout << "Output Test: " << scMap->getMapDataCharAt(tempSettlementX1, tempSettlementY1) << endl;
                    if(scMap->getMapDataCharAt(tempSettlementX1, tempSettlementY1) != " - "){
                        cout << "Structure already present." << endl;
                        i -= 1;
                    }
                    //If there is not 2 roads to the left or right side or above or below the settlement do not place that settlement
                    else if( twoRdsBefore1(tempSettlementX1, tempSettlementY1, scMap) == false){
                        cout <<"You need two have two roads next to the settlement in order to place a settlement there." << endl;
                        bool rdsBStat1 = false;
                        rdsBStat1 = true;
                        return rdsBStat1; 
                        i -= 1;
                    }
                    else
                    {
                        scMap->setSettlementXCor1(tempSettlementX1);
                        scMap->setSettlementYCor1(tempSettlementY1);
                        scMap->spawnSettlement1(i+1);
                    }
                }
                scMap->displayMap();
                cout << endl;
                scMap->displayResMap();
            }
            return false;
        }

        void addingToMapSettlementCont1(scMap* scMap, Structures* Structures){
            int tempSettlementX1 = 0;
            int tempSettlementY1 = 0;
            float x1 = 0;
            float y1 = 0;
            int settlementPurchCont1 = Structures->getNumSettlement1();
            int currAmountUpdateRd = 0;
            int num_cols =scMap->getNumCols(); 
            int num_rows =scMap->getNumRows();
            if (settlementPurchCont1 > 0)
            {
                while(true)
                {
                    while (true)
                    {
                        cout << "Enter an x coordinate of settlement "<< endl;
                        cin >> x1;
                        if ((x1 > 0 && x1 <= num_cols) && (is_integer(x1) == true))
                        {
                            tempSettlementX1 = int(x1);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Input for X coordinate." << endl;
                            cin.clear();
                            cin.ignore(80, '\n');
                        }
                    }
                    while (true)
                    {
                        cout << "Enter an y coordinate of settlement. " << endl;
                        cin >> y1;
                        if ((y1 > 0 && y1 <= num_cols) && (is_integer(y1) == true))
                        {
                            tempSettlementY1 = int(y1);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Input for y coordinate." << endl;
                            cin.clear();
                            cin.ignore(80, '\n');
                        }
                    }
                    if(scMap->getMapDataCharAt(tempSettlementX1, tempSettlementY1) != " - "){
                        cout << "Structure already present." << endl;
                    }
                    else
                    {
                        scMap->setSettlementXCor1(tempSettlementX1);
                        scMap->setSettlementYCor1(tempSettlementY1);
                        scMap->spawnSettlement1((scMap->getNumSettlement1())+1);
                        currAmountUpdateRd = scMap ->getNumSettlement1();
                        scMap->setNumSettlement1(currAmountUpdateRd +1);
                        break;
                    }
                }
            scMap->displayMap();
            cout << endl;
            scMap->displayResMap();
            }
        }
        //Upgrading To City Function For Player 1
        void upgradeCity1(scMap* scMap, Structures* Structures, int tempCityXCor1, int tempCityYCor1)
        {
            if(scMap->getMapDataCharAt(tempCityXCor1, tempCityYCor1) == "\x1b[31m ^ \x1b[0m"){
                scMap->setMapDataCharAt("\x1b[31m # \x1b[0m", tempCityXCor1, tempCityYCor1);
                int currCity1 = scMap->getNumCity1();
                scMap->setNumCity1(currCity1 + 1);
            } 
            else 
            {
                cout << "There is no settlement at those coordinates." << endl;
            }
            scMap->displayMap();
            cout << endl;
            scMap->displayResMap();
        }
//------------------------------------------------------------------------------------------------------------------------------------

//PLAYER 2 FUNCTIONS
    //Display Player 2's Item Inventory
    void displayP2Item(Structures* Structures, Dev* Dev)
    {
        cout << "\x1b[36m----------\x1b[0m" << "\x1b[36mPLAYER 2 ITEMS Inventory\x1b[0m" << "\x1b[36m----------\x1b[0m" << endl;
        cout << "Number of Roads " << "\x1b[36m-\x1b[0m : "  << Structures->getNumRoad2() << endl;
        cout << "Number of Settlements " << "\x1b[36m^\x1b[0m : " << Structures->getNumSettlement2() << endl;
        cout << "Number of City " << "\x1b[36m#\x1b[0m : " << Structures->getNumCities2() << endl;
        cout << "Number of Dev Cards " << "\x1b[36m[\U0001F0CF]\x1b[0m: " << Dev->getNumDevCards2() << endl;
    }
    void displayPlayer2Inventory(Player2* p2){
        cout << "\x1b[36m----------\x1b[0m" << "\x1b[36mPLAYER 2 Inventory\x1b[0m" << "\x1b[36m----------\x1b[0m" << endl;
        //Brick
        cout << "Number of " << "[\U0001F9F1] " << "is: " << p2->getResourceAt(0) << endl;
        //Wood
        cout << "Number of " << "[\U0001FAB5]" << "is: " << p2->getResourceAt(0) << endl;
        //Grain
        cout << "Number of " << "[\U0001F33E]" << "is: " << p2->getResourceAt(2) << endl;
        //Sheep
        cout << "Number of " << "[\U0001F40F]" << "is: " << p2->getResourceAt(3) << endl;
        //Ore
        cout << "Number of " << "[\U0001FAA8]" << "is:" << p2->getResourceAt(4) << endl;
    }
    //Function to check whether there are two roads before the settlement either, above, below, to the left, or to the right
    bool twoRdsBefore2(int tempSettlementX, int tempSettlementY, scMap* scMap){
        bool rdsBefore = false;
        if(tempSettlementX > 0 && tempSettlementY <= 18)
        {
            //there are two roads before the settlement on the left side
            if(scMap->getMapDataCharAt(tempSettlementX-1, tempSettlementY) == "\x1b[36m - \x1b[0m" && scMap->getMapDataCharAt(tempSettlementX-2, tempSettlementY) == "\x1b[36m - \x1b[0m")
            {
                rdsBefore = true;
            }
            //there are two roads on the right side of the settlement
            else if(scMap->getMapDataCharAt(tempSettlementX+1, tempSettlementY) == "\x1b[36m - \x1b[0m" && scMap->getMapDataCharAt(tempSettlementX+2, tempSettlementY) == "\x1b[36m - \x1b[0m")
            {
                rdsBefore = true;
            }
            //there are two rs above the settlement
            else if(scMap->getMapDataCharAt(tempSettlementX, tempSettlementY+1) == "\x1b[36m - \x1b[0m" && scMap->getMapDataCharAt(tempSettlementX, tempSettlementY + 2) == "\x1b[36m - \x1b[0m")
            {
                rdsBefore = true;
            }
            //there are two roads below the settlement
            else if(scMap->getMapDataCharAt(tempSettlementX,tempSettlementY-1) == "\x1b[36m - \x1b[0m" && scMap->getMapDataCharAt(tempSettlementX, tempSettlementY-2) == "\x1b[36m - \x1b[0m")
            {
                rdsBefore = true;
            }
            else
            {
                rdsBefore = false;
            }
        }
    return rdsBefore;
    }
    //Structures
    void addingToMapRoad2(scMap* scMap, Structures* Structures){
        int tempRoadX2 = 0;
        int tempRoadY2 = 0;
        float x2 = 0;
        float y2 = 0;
        int roadPurch2 = scMap->getNumRoads2();
        int num_cols =scMap->getNumCols(); 
        int num_rows =scMap->getNumRows();
        if (roadPurch2 > 0)
        {
            for (int i = 0; i < roadPurch2; i++)
            {
                while (true)
                {
                    cout << "Enter an x coordinate of road " << i + 1 << endl;
                    cin >> x2;
                    if ((x2 > 0 && x2 <= num_cols) && (is_integer(x2) == true))
                    {
                        tempRoadX2 = int(x2);
                        break;
                    }
                    else
                    {
                        cout << "Invalid Input." << endl;
                        cin.clear();
                        cin.ignore(80, '\n');
                    }
                }
                while (true)
                {
                    cout << "Enter an y coordinate of road " << i + 1 << endl;
                    cin >> y2;
                    if ((y2 > 0 && y2 <= num_cols) && (is_integer(y2) == true))
                    {
                        tempRoadY2 = int(y2);
                        break;
                    }
                    else
                    {
                        cout << "Invalid Input" << endl;
                        cin.clear();
                        cin.ignore(80, '\n');
                    }
                }
                if(scMap->getMapDataCharAt(tempRoadX2, tempRoadY2) != " - "){
                    cout << "Structure already present." << endl;
                    i -= 1;
                }
                else
                {
                    scMap->setRoadXCor2(tempRoadX2);
                    scMap->setRoadYCor2(tempRoadY2);
                    scMap->spawnRoads2(i+1);
                }
                
            }
            cout << "Which road would you like to place: " << endl;
            for (int i = 0; i < roadPurch2; i++)
            {
                cout << "Road " << i + 1 << ": "
                    << "(" << scMap->getRoadAtXCor2(i) << ", " << scMap->getRoadAtYCor2(i) << ")" << endl;
            }
            scMap->displayMap();
            cout << endl;
            scMap->displayResMap();
        }
    }
    void addingToMapRoadCont2(scMap* scMap, Structures* Structures)
    {
        int tempRoadX2 = 0;
        int tempRoadY2 = 0;
        float x2 = 0;
        float y2 = 0;

        int roadPurchCont2 = Structures->getNumRoad2();
        int currAmountUpdateRd = 0;
        int num_cols =scMap->getNumCols(); 
        int num_rows =scMap->getNumRows();
        if (roadPurchCont2 > 0)
        {
            while(true)
            {
                while (true)
                {
                    cout << "Enter an x coordinate of road " << endl;
                    cin >> x2;
                    if ((x2 > 0 && x2 <= num_cols) && (is_integer(x2) == true))
                    {
                        tempRoadX2 = int(x2);
                        break;
                    }
                    else
                    {
                        cout << "Invalid Input for X coordinate." << endl;
                        cin.clear();
                        cin.ignore(80, '\n');
                    }
                }
                while (true)
                {
                    cout << "Enter an y coordinate of road. " << endl;
                    cin >> y2;
                    if ((y2 > 0 && y2 <= num_cols) && (is_integer(y2) == true))
                    {
                        tempRoadY2 = int(y2);
                        break;
                    }
                    else
                    {
                        cout << "Invalid Input for y coordinate." << endl;
                    cin.clear();
                    cin.ignore(80, '\n');
                    }
                }
            if(scMap->getMapDataCharAt(tempRoadX2, tempRoadY2) != " - "){
                cout << "Structure already present." << endl;
            }
            else
            {
                scMap->setRoadXCor2(tempRoadX2);
                scMap->setRoadYCor2(tempRoadY2);
                scMap->spawnRoads2((scMap->getNumRoads2())+1);
                currAmountUpdateRd = scMap ->getNumRoads2();
                scMap->setNumRoads2(currAmountUpdateRd +1);
                break;
            }
        }
        scMap->displayMap();
        cout << endl;
        scMap->displayResMap();
        }
    }
    bool addingToMapSettlement2(scMap* scMap, Structures* Structures){
        int tempSettlementX2 = 0;
        int tempSettlementY2 = 0;
        float x2 = 0;
        float y2 = 0;
        int settlementPurch2 = scMap->getNumSettlement2();
        int num_cols =scMap->getNumCols(); 
        int num_rows =scMap->getNumRows();
        if (settlementPurch2 > 0)
        {
            for (int i = 0; i < settlementPurch2; i++)
            {
                bool matchX = false;
                bool matchY = false;
                while (true)
                {
                    cout << "Enter an x coordinate of settlement " << i + 1 << endl;
                    cin >> x2;
                    if ((x2 > 0 && x2 <= num_cols) && (is_integer(x2) == true))
                    {
                        tempSettlementX2 = int(x2);
                        break;
                    }
                    else
                    {
                        cout << "Invalid Input." << endl;
                        cin.clear();
                        cin.ignore(80, '\n');
                    }
                }
                while (true)
                {
                    cout << "Enter an y coordinate of settlement " << i + 1 << endl;
                    cin >> y2;
                    if ((y2 > 0 && y2 <= num_cols) && (is_integer(y2) == true))
                    {
                        tempSettlementY2 = int(y2);
                        break;
                    }
                    else
                    {
                        cout << "Invalid Input" << endl;
                        cin.clear();
                        cin.ignore(80, '\n');
                    }
                }
                cout << "Output Test: " << scMap->getMapDataCharAt(tempSettlementX2, tempSettlementY2) << endl;
                if(scMap->getMapDataCharAt(tempSettlementX2, tempSettlementY2) != " - "){
                    cout << "Structure already present." << endl;
                    i -= 1;
                }
                //If there is not 2 roads to the left or right side or above or below the settlement do not place that settlement
                else if( twoRdsBefore2(tempSettlementX2, tempSettlementY2, scMap) == false)
                {
                        cout <<"You needed two have two roads next to the settlement in order to place a settlement there." << endl;
                        bool rdsBStat2 = false;
                        rdsBStat2 = true;
                        return rdsBStat2;
                        i -= 1;
                }
                else
                {
                    scMap->setSettlementXCor2(tempSettlementX2);
                    scMap->setSettlementYCor2(tempSettlementY2);
                    scMap->spawnSettlement2(i+1);
                }
            }
            cout << "Which Settlement would you like to place: " << endl;
            for (int i = 0; i < settlementPurch2; i++)
            {
                cout << "Settlement " << i + 1 << ": "
                    << "(" << scMap->getSettlementAtXCor2(i) << ", " << scMap->getSettlementAtYCor2(i) << ")" << endl;
            }
            scMap->displayMap();
            cout << endl;
            scMap->displayResMap();

        }
        return false;
    }
    void addingToMapSettlementCont2(scMap* scMap, Structures* Structures)
    {
        int tempSettlementX2 = 0;
        int tempSettlementY2 = 0;
        float x2 = 0;
        float y2 = 0;

        int settlementPurchCont2 = Structures->getNumSettlement2();
        int currAmountUpdateRd = 0;
        int num_cols =scMap->getNumCols(); 
        int num_rows =scMap->getNumRows();
        if (settlementPurchCont2 > 0)
        {
            while (true)
            {
                while (true)
                {
                    cout << "Enter an x coordinate of settlement " << endl;
                    cin >> x2;
                    if ((x2 > 0 && x2 <= num_cols) && (is_integer(x2) == true))
                    {
                        tempSettlementX2 = int(x2);
                        break;
                    }
                    else
                    {
                        cout << "Invalid Input for X coordinate." << endl;
                        cin.clear();
                        cin.ignore(80, '\n');
                    }
                }
                while (true)
                {
                    cout << "Enter an y coordinate of road. " << endl;
                    cin >> y2;
                    if ((y2 > 0 && y2 <= num_cols) && (is_integer(y2) == true))
                    {
                        tempSettlementY2 = int(y2);
                        break;
                    }
                    else
                    {
                        cout << "Invalid Input for y coordinate." << endl;
                        cin.clear();
                        cin.ignore(80, '\n');
                    }
                }
            if(scMap->getMapDataCharAt(tempSettlementX2, tempSettlementY2) != " - "){
                cout << "Structure already present." << endl;
            }
            else
            {
                scMap->setSettlementXCor2(tempSettlementX2);
                scMap->setSettlementYCor2(tempSettlementY2);
                scMap->spawnSettlement2((scMap->getNumSettlement2())+1);
                currAmountUpdateRd = scMap ->getNumSettlement2();
                scMap->setNumSettlement2(currAmountUpdateRd +1);
                break;
            }
        }
        scMap->displayMap();
        cout << endl;
        scMap->displayResMap();
        }
    }
     //Upgrading To City Function For Player 2
        void upgradeCity2(scMap* scMap, Structures* Structures, int tempCityXCor2, int tempCityYCor2)
        {
            if(scMap->getMapDataCharAt(tempCityXCor2, tempCityYCor2) == "\x1b[36m ^ \x1b[0m"){
                scMap->setMapDataCharAt("\x1b[36m # \x1b[0m", tempCityXCor2, tempCityYCor2);
                int currCity2 = scMap->getNumCity2();
                scMap->setNumCity2(currCity2 + 1);
            } 
            else 
            {
                cout << "There is no settlement at those coordinates." << endl;
            }
            scMap->displayMap();
            cout << endl;
            scMap->displayResMap();
        }
//---------------------------------------------------------------------------------------------------------------------------------

//Function to Display Title Card
void dislayTitleCard()
{
    cout << "             @ . ,,,,.    /          (##(       .,..,,,...,,...,,,..        ##@            .,...,,,       .,,,..,,.     " << endl;
    cout << "          &..,,,@.   %...,&            ,,       &  .,,,.   .,,,,,.  (      # ,,&            %     ,*,      *'  ,',      " << endl;
    cout << "        @,..,,,@      ...,%         ( ,,,/      &.,&   &  ,,,#   @,.(     @ ,,,,,            # ,,,,,,@       ,.,,       " << endl;
    cout << "       %...,,,*         &,@        @ ,,,,,&     @*#    &  .,,#    &,%    ( ,,,,,,            # ,,,,,,,,*     ,.,,       " << endl;
    cout << "      &,...,,,&                   #.,%,,,,,&           &...,,#           ..,,,.,,%           #.,#@,,,,,,&    ,.,,       " << endl;
    cout << "      (,,.,,,,@                  . .* @..,,,(          &...,,#         .(.,((...,,@          #.,#  *,,,,,,(  ,.,,       " << endl;
    cout << "      /,,,,,,,@                  /.,/  (..,,,          &...,,#         @.,@  @..,,,#         #.,#   &,,,,,,# *.,,       " << endl;
    cout << "      &,,,.,,,@                 @.,@////...,,(         &...,,#        #.,#////%..,,,,        #.,#     (,,,,,,*.,.       " << endl;
    cout << "      .,,,.,,,/         %.,(   %.*,,,,,,,,,,,,&        &...,,#       ...*,,,,,,,,,,,*        #.,#      #.,.,,,.,,       " << endl;
    cout << "       /,,,.,,,&       @.,,(  ..,,       @,,,,,&       &...,,#       /.,#      ,,,,,,%       #.,#        &....,,,       " << endl;
    cout << "         &,,,,,,%     @..,,,  *.*%        %,.,,,*      &.,.,,#      @,,&        &..,,,@      (.,%         *...,,,       " << endl;
    cout << "           %,,,.,,@#@,..,,@*&,.,,#&(    #&(...,,,@( /%&,,.,,,.@%, %(,,,*&#.   (%&...,,,## *&#,,,,&%,        @..,,       " << endl;
    cout << "                *&@@@@#.                                                                                     .&&.       " << endl;
    cout <<"                                          A PROJECT BY ISHAN GOHIL & JASKARN KAHLON                             " << endl;
    cout << endl;
    cout << "                                                   WELCOME TO CATAN                                                     " << endl; 
}

int main()
{
    //Creating Objects for all the classes;
        //Player Objects
        Player1 p1;
        Player2 p2;
        //Map Object
        scMap scMap;
        //Structures object
        Structures Structures;
        //Dev Card obejct
        Dev Dev;
        //Leaderboard Object
        // Leaderboard Leaderboard;
        //Dice roll object;
        Dice Dice;
    dislayTitleCard();
    string choice = "";
    //Select Menu Variables
    bool gameOver = false;
    int selectMenuChoice = 0;
    bool endTurn = false;

   // opening and filling up the names array
    int count = 0;
    string line;
    //creating an array
    string players[50];
    Leaderboard names[50];

    ifstream myReadFile;
    myReadFile.open("victoryLog.txt");

    //reading line by line and setting into the array
    if (myReadFile.fail())
    {
        cout << "couldn't open file" << endl;
    }
    else
    {
        while (getline(myReadFile, line))
        {
            if (line.length() > 1)
            {
                split(line, ':', players, 50);
            }
            names[count].setPlayerName(players[0]);
            names[count].setNumWins(stoi(players[1]));
            count++;
        }
        myReadFile.close();
        
    }


    while (true)
    {
    
        cout << "                                                  PRESS S TO CONTINUE                                                 " << endl;
        cout << "                                                    PRESS Q TO Quit                                                   " << endl;
        cin >> choice;
        if(toUpper(choice) == "S")
        {

            //Names of the Players
            string player1Name;
            string player2Name;
            string nameComf;
            bool nameLoop = true;
            bool correctNameLoop = true;
            cout << "Hello Player 1." << endl;
            cout << "Enter your name to begin your journey: " << endl;
            while(nameLoop == true)
            {
                cin >> player1Name;
                //checking if the player name has a colon
                int found = player1Name.find(':');
                int nameSize = player1Name.length();
                if (found >=0 && found < nameSize){
                    cout << "Invalid Input, please do not enter a colon" << endl;
                    cout << "Enter your name:" << endl;
                } 
                else 
                {
                    cout << "Is " << player1Name << " correct?" << endl;
                    correctNameLoop = true;
                    while(correctNameLoop == true)
                    {    
                        cout << "Enter Y for yes." << endl;
                        cout << "Enter N for no." << endl;
                        cin >> nameComf;
                        if(toUpper(nameComf) == "Y")
                        {
                        // calling the function to add name to text file
                        addName(count,names,player1Name);
                            nameLoop = false;
                            correctNameLoop = false;
                        }
                        else if(toUpper(nameComf) == "N")
                        {
                            cout << "Please enter the correct name: " << endl;
                            correctNameLoop = false;
                        }
                        else
                        {
                            cout << "Invalid Input. Please enter only Y/N." << endl;
                        }
                    } 
                }
            }
            bool nameLoop2 = true;
            bool correctNameLoop2 = true;
            cout << "Hello Player 2." << endl;
            cout << "Enter your name to begin your journey: " << endl;
            while(nameLoop2 == true)
            {
                cin >> player2Name;
                //checking if the player name has a colon
                int found = player2Name.find(':');
                int nameSize = player2Name.length();
                if (found >=0 && found < nameSize){
                    cout << "Invalid Input, please do not enter a colon" << endl;
                    cout << "Enter your name:" << endl;
                } 
                else 
                {
                    cout << "Is " << player2Name << " correct?" << endl;
                    correctNameLoop2 = true;
                    while(correctNameLoop2 == true)
                    {    
                        cout << "Enter Y for yes." << endl;
                        cout << "Enter N for no." << endl;
                        cin >> nameComf;
                        if(toUpper(nameComf) == "Y")
                        {
                        // calling the function to add name to text file
                        addName(count,names,player2Name);
                            nameLoop2 = false;
                            correctNameLoop2 = false;
                        }
                        else if(toUpper(nameComf) == "N")
                        {
                            cout << "Please enter the correct name: " << endl;
                            correctNameLoop2 = false;
                        }
                        else
                        {
                            cout << "Invalid Input. Please enter only Y/N." << endl;
                        }
                    } 
                }
            }
            //This is where the values will be set to the 4 roads and 2 settlement
                scMap.setNumRoads1(4);
                scMap.setNumRoads2(4);
                scMap.setNumSettlement1(2);
                scMap.setNumSettlement2(2);
                displayInstructions();
                scMap.displayMap();
                scMap.displayResMap();
            //Setting All Resource for players to 2
            //Player 1
                //Brick 10
                p1.setResourceAt(0,10);
                //Wood 10
                p1.setResourceAt(1,10);
                //Grain
                p1.setResourceAt(2,6);
                //Sheep
                p1.setResourceAt(3,6);
                //Ore
                p1.setResourceAt(4,8);
            //Player 2
                //Brick
                p2.setResourceAt(0,10);
                //Wood
                p2.setResourceAt(1,10);
                //Grain
                p2.setResourceAt(2,6);
                //Sheep
                p2.setResourceAt(3,6);
                //Ore
                p2.setResourceAt(4,8);
            //---------------------------------------------------------------------
                //STARTING SETUP
                cout << "In order to start the game " << player1Name << ", you must place 4 roads and 2 settlements." << endl;
                cout << "Make sure you have two roads before your settlements!" << endl;
                cout << "\x1b[31mONCE YOU PLACE YOUR ROADS YOU WILL NOT BE ABLE TO EDIT THEM \x1b[0m" << endl;
                addingToMapRoad1(&scMap, &Structures);
                bool rdBStat1 = addingToMapSettlement1(&scMap, &Structures);
                cout << "Last but not least it's " << player2Name << "'s " << "turn." << endl;
                cout << "Place 4 roads and 2 settlement" << endl;
                cout << "Remember, make sure you have two roads before your settlement!" << endl;
                cout << "\x1b[31mONCE YOU PLACE YOUR ROADS YOU WILL NOT BE ABLE TO EDIT THEM \x1b[0m" << endl;
                addingToMapRoad2(&scMap, &Structures);
                bool rdBStat2 = addingToMapSettlement2(&scMap, &Structures);
                if(rdBStat1 == true || rdBStat2 == true)
                {
                    if(rdBStat1 == false){
                        cout << "\x1b[31mPlayer 1 Wins by default because Player 2 had invalid inputs, causing them not to be able to place their settlements.\x1b[0m" << endl;
                        return 0;
                    }
                    else if(rdBStat2 == false){
                        cout << "\x1b[36mPlayer 2 Wins by default because Player 1 had invalid inputs, causing them not to be able to place their settlements.\x1b[0m" << endl;
                        return 0;
                    }
                    else if(rdBStat1 == true && rdBStat2 == true)
                    {
                      cout << "\x1b[35mBOTH PLAYERS LOST by default because, both players causing them not to be able to place their settlements.\x1b[0m" << endl;
                      return 0;   
                    }
                }
                while(gameOver == false){
                    endTurn = false;
                    //PLAYER 1
                    while(endTurn == false)
                    {
                        cout << endl;
                        cout << "----------"<< "\x1b[31mPLAYER 1 MENU\x1b[0m" <<"----------" << endl;
                        cout << "Enter the corresponding number to make a menu selection." << endl;
                        cout << "1) End Turn" << endl;
                        cout << "2) Display Inventory" << endl;
                        cout << "3) Display Items Inventory" << endl;
                        cout << "4) Display Building Costs" << endl;
                        cout << "5) Purchase Items" << endl;
                        cout << "6) Place Structures" << endl;
                        cout << "7) Check Victory Points" << endl;
                        cout << "8) Check Leaderboard" << endl;
                        cout << "9) Use Development Card" << endl;
                        cout << "10) Quit the Game!" << endl;
                        cin >> selectMenuChoice;
                        //End turn
                        if(selectMenuChoice == 1)
                        {   
                            Dice.Roll();
                            Dice.Display();
                            int diceRoll = Dice.getRoll();
                            CondFuncStoreRec( diceRoll, &scMap, &p1, &p2);
                            condFuncVicPoints(&scMap, &p1, &p2, &Dev);
                            scMap.spawnRob();
                            //if Dice roll is 7 then move the position of the robber
                            if(scMap.getRobPosAt(0) != -1 && scMap.getRobPosAt(1) != -1){
                                cout << "X Robber Position: " << scMap.getRobPosAt(0) << endl;
                                cout << "Y Robber Position: " << scMap.getRobPosAt(1) << endl;
                                //Iterate through the placed roads to see if the position of the robber matches
                                for(int i = 0; i < scMap.getNumSettlement1(); i++){
                                    if(scMap.getSettlementAtXCor1(i) == scMap.getRobPosAt(0) && scMap.getSettlementAtYCor1(i) == scMap.getRobPosAt(1)){
                                        cout << "There is a robber at this settlement! " << "(" << scMap.getSettlementAtXCor1(i) << " , " << scMap.getSettlementAtYCor1(i) << ") " << endl;
                                        cout << "The robber stole " << scMap.getResAtPos(scMap.getSettlementAtXCor1(i), scMap.getSettlementAtYCor1(i)) << "." << endl;
                                        scMap.resetRobPos();
                                    }
                                }
                            }
                            //Checking to see if we can end the game (Player Has 7 points)
                            if(p1.getVicPoints() >= 11 || p2.getVicPoints() >= 11 || mapFull(&scMap)==true )
                            {
                                if(p1.getVicPoints() > p2.getVicPoints())
                                {
                                    addWins(count, names, player1Name);
                                    displayEnd(player1Name);
                                } else if (p1.getVicPoints() < p2.getVicPoints())
                                {
                                    addWins(count, names, player2Name);
                                    displayEnd(player2Name);
                                }

                                return 0;
                            }
                            endTurn = true;
                        }
                        //Displaying Inventory
                        if(selectMenuChoice == 2)
                        {
                            displayPlayer1Inventory(&p1);
                        }
                        //Display Items Inventory
                        if(selectMenuChoice == 3){
                            displayP1Item(&Structures, &Dev);
                        }
                        //Display Building Costs
                        else if(selectMenuChoice == 4)
                        {
                            displayBuildCosts();
                        }
                        //Purchase Items
                        else if(selectMenuChoice == 5)
                        {
                            while(true)
                            {
                                int purchaseChoice = 0;
                                cout << "\x1b[31m----------\x1b[0m " << player1Name << "'s" << " Purchasing Menu" << "\x1b[31m----------\x1b[0m" << endl;
                                cout << "Enter the corresponding menu number to purchase that specific structure." << endl;
                                cout << "1) Road:" << "---------------- " << "\x1b[31m-\x1b[0m" << endl;
                                cout << "2) Settlement:" << "---------- " <<  "\x1b[31m^\x1b[0m" << endl;
                                cout << "3) City:" << "---------------- " << "\x1b[31m#\x1b[0m" << endl;
                                cout << "4) Development Card: --- " << "\x1b[31m[\x1b[0m" << "\U0001F0CF" << "\x1b[31m]\x1b[0m" << endl;
                                cout << "5) QUIT" << endl;
                                cin >> purchaseChoice;
                                    //Road
                                    if(purchaseChoice == 1)
                                    {
                                        bool canBuy = condFuncToPurch(1,p1.getResourceAt(0), p1.getResourceAt(1), p1.getResourceAt(2), p1.getResourceAt(3), p1.getResourceAt(4));
                                        if(canBuy == true && mapFull(&scMap) ==false )
                                        {
                                                PurchStruct(1, 1, &Structures, &Dev, &p1, &p2);
                                                break;
                                        }
                                        else if(canBuy == false)
                                        {
                                            cout << "You do not have enough resources to purchase that structure." << endl;
                                        }
                                        else if(mapFull(&scMap) == true)
                                        {
                                            cout << "The map is full, you may not purchase a road" << endl;
                                        }  
                                    }
                                    //Settlement
                                    if(purchaseChoice == 2)
                                    {
                                        bool canBuy = condFuncToPurch(2,p1.getResourceAt(0), p1.getResourceAt(1), p1.getResourceAt(2), p1.getResourceAt(3), p1.getResourceAt(4));
                                        if(canBuy == true && mapFull(&scMap) ==false)
                                        {
                                                PurchStruct(1, 2, &Structures, &Dev, &p1, &p2);
                                                break;
                                        }
                                        else if(canBuy == false)
                                        {
                                            cout << "You do not have enough resources to purchase that structure." << endl;
                                        }  
                                         else if(mapFull(&scMap) == true)
                                        {
                                            cout << "The map is full, you may not purchase a settlement" << endl;
                                        }  
                                    }
                                    //City
                                    if(purchaseChoice == 3)
                                    {
                                        bool canBuy = condFuncToPurch(3,p1.getResourceAt(0), p1.getResourceAt(1), p1.getResourceAt(2), p1.getResourceAt(3), p1.getResourceAt(4));
                                        if(canBuy == true && mapFull(&scMap) ==false)
                                        {
                                                PurchStruct(1, 3, &Structures, &Dev, &p1, &p2);
                                                break;
                                        }
                                        else if(canBuy == false)
                                        {
                                            cout << "You do not have enough resources to purchase that structure." << endl;
                                        }  
                                         else if(mapFull(&scMap) == true)
                                        {
                                            cout << "The map is full, you may not purchase a city" << endl;
                                        }  
                                    }
                                    //Development Card
                                    if(purchaseChoice == 4)
                                    {
                                        bool canBuy = condFuncToPurch(4,p1.getResourceAt(0), p1.getResourceAt(1), p1.getResourceAt(2), p1.getResourceAt(3), p1.getResourceAt(4));
                                        if(canBuy == true)
                                        {
                                                PurchStruct(1, 4, &Structures, &Dev, &p1, &p2);
                                                break;
                                        }
                                        else if(canBuy == false)
                                        {
                                            cout << "You do not have enough resources to purchase that structure." << endl;
                                        }   
                                    }
                                    //Quit
                                    else if(purchaseChoice == 5){
                                        break;
                                    }
                                    else if(is_integer(purchaseChoice) == false)
                                    {
                                        cout << "Invalid purchasing input!" << endl;
                                        cin.clear();
                                        cin.ignore(80, '\n');
                                    }
                            }
                                
                        }
                        //Place Structures And Roll Dice
                        else if(selectMenuChoice == 6)
                        {
                            while(true)
                            {
                                int placeChoice = 0;
                                cout << "\x1b[31m----------\x1b[0m " << player1Name << "'s" << " Placing Menu" << "\x1b[31m ----------\x1b[0m" << endl;
                                cout << "Enter the corresponding menu number to place that specific structure." << endl;
                                cout << "1) Road:" << "---------------- " << "\x1b[31m-\x1b[0m" << endl;
                                cout << "2) Settlement:" << "---------- " <<  "\x1b[31m^\x1b[0m" << endl;
                                cout << "3) Upgrade to City:" << "----- " << "\x1b[31m#\x1b[0m" << endl;
                                cout << "4) QUIT" << endl;
                                cin >> placeChoice;
                                //Road
                                if(placeChoice ==1)
                                {
                                    if(Structures.getNumRoad1() > 0)
                                    {
                                        addingToMapRoadCont1(&scMap, &Structures);
                                        int currentRoad = Structures.getNumRoad1();
                                        Structures.setNumRoad1(currentRoad-1);
                                        break;
                                    }
                                    else
                                    {
                                        cout << "You have no roads to place." << endl;
                                    }
                                    
                                }
                                //Settlement
                                else if(placeChoice == 2)
                                {
                                    if(Structures.getNumSettlement1() > 0)
                                    {
                                        addingToMapSettlementCont1(&scMap, &Structures);
                                        int currenSettlement = Structures.getNumSettlement1();
                                        Structures.setNumSettlement1(currenSettlement -1);
                                        break;
                                    }
                                    else
                                    {
                                        cout << "You have no settlements to place." << endl;
                                    }
                                    
                                }
                                // Upgrade to City
                                else if(placeChoice == 3)
                                {
                                    if(Structures.getNumCities1() > 0)
                                    {
                                        int tempCityXCor1;
                                        int tempCityYCor1;
                                        while (true)
                                        {
                                            cout << "Enter an x coordinate of settlement you want to upgrade" << endl;
                                            cin >> tempCityXCor1;
                                            if (tempCityXCor1 > 0 && tempCityXCor1 <= scMap.getNumCols())
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Invalid Input." << endl;
                                                cin.clear();
                                                cin.ignore(80, '\n');
                                            }
                                        }
                                        while (true)
                                        {
                                            cout << "Enter an y coordinate of settlement you want to upgrade" << endl;
                                            cin >> tempCityYCor1;
                                            if (tempCityYCor1 > 0 && tempCityYCor1 <= scMap.getNumRows())
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Invalid Input" << endl;
                                                cin.clear();
                                                cin.ignore(80, '\n');
                                            }
                                        }
                                        upgradeCity1(&scMap, &Structures, tempCityXCor1, tempCityYCor1);
                                        int currentCity1 = Structures.getNumCities1();
                                        Structures.setNumCities1(currentCity1-1);
                                        break;
                                    }
                                    else
                                    {
                                        cout << "You have no settlements to place." << endl;
                                    }
                                }
                                else if(placeChoice == 4)
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid input for placing a structure." << endl;
                                    cin.clear();
                                    cin.ignore(80, '\n');
                                }
                            }
                        }
                        //check Victory Points
                        else if(selectMenuChoice == 7)
                        {
                            cout << player1Name << " you have " << p1.getVicPoints() << "." << endl;
                        }
                        //Check Leaderboard
                        else if(selectMenuChoice == 8)
                        {
                        count = 0;
                        // repopulating the arrays
                        myReadFile.open("victoryLog.txt");
                        if(myReadFile.is_open()){
                            cout << "file open" << endl;
                        }
                        while (getline(myReadFile, line))
                        {
                            if (line.length() > 1)
                            {
                                split(line, ':', players, 50);
                            }
                            names[count].setPlayerName(players[0]);
                            names[count].setNumWins(stoi(players[1]));
                            count++;
                        }
                        myReadFile.close();
                        cout << "----------Leaderboard----------" << endl;
                        displayLeaderboard(count, names);
                    }
                        //Use Development Card
                        else if(selectMenuChoice == 9)
                        {
                            int currentAmntDev = Dev.getNumDevCards1();
                            if(Dev.getNumDevCards1() > 0)
                            {
                                outcomeGenerator1(&Dev, &Structures, &p1);
                                Dev.setNumDevCards1(currentAmntDev -1);
                            }
                            else
                            {
                                cout << "You have no development cards to execute." << endl;
                            }
                        }
                        //Quit the game
                        else if(selectMenuChoice == 10){
                            cout << "Farewell " << player1Name << "." << endl;
                            return 0;
                        }
                        else if(selectMenuChoice > 10 || selectMenuChoice < 1)
                        {
                            cout << "Invalid Input!" << endl;
                            cin.clear();
                            cin.ignore(80, '\n');

                        }
                        else if(isdigit(selectMenuChoice) == false)
                        {
                            cin.clear();
                            cin.ignore(80, '\n');
                        }
                    }
                    endTurn = false;
                    //Player 2 MENU CYCLE
                    while(endTurn == false)
                    {
                        cout << endl;
                        cout << "----------"<< "\x1b[36mPLAYER 2 MENU\x1b[0m" <<"----------" << endl;
                        cout << "Enter the corresponding number to make a menu selection." << endl;
                        cout << "1) End Turn" << endl;
                        cout << "2) Display Inventory" << endl;
                        cout << "3) Display Items Inventory" << endl;
                        cout << "4) Display Building Costs" << endl;
                        cout << "5) Purchase Items" << endl;
                        cout << "6) Place Structures" << endl;
                        cout << "7) Check Victory Points" << endl;
                        cout << "8) Check Leaderboard" << endl;
                        cout << "9) Use Development Card" << endl;
                        cout << "10) Quit the Game!" << endl;
                        cin >> selectMenuChoice;
                        //End turn
                        if(selectMenuChoice == 1)
                        {
                            Dice.Roll();
                            Dice.Display();
                            int diceRoll = Dice.getRoll();
                            CondFuncStoreRec( diceRoll, &scMap, &p1, &p2);
                            condFuncVicPoints(&scMap, &p1, &p2, &Dev);
                            scMap.spawnRob();
                            //if Dice roll is 7 then move the position of the robber
                            if(scMap.getRobPosAt(0) != -1 && scMap.getRobPosAt(1) != -1){
                                cout << "X Robber Position: " << scMap.getRobPosAt(0) << endl;
                                cout << "Y Robber Position: " << scMap.getRobPosAt(1) << endl;
                                //Iterate through the placed roads to see if the position of the robber matches
                                for(int i = 0; i < scMap.getNumSettlement2(); i++){
                                    if(scMap.getSettlementAtXCor2(i) == scMap.getRobPosAt(0) && scMap.getSettlementAtYCor2(i) == scMap.getRobPosAt(1)){
                                        cout << "There is a robber at this settlement! " << "(" << scMap.getSettlementAtXCor2(i) << " , " << scMap.getSettlementAtYCor2(i) << ") " << endl;
                                        cout << "The robber stole " << scMap.getResAtPos(scMap.getSettlementAtXCor2(i), scMap.getSettlementAtYCor2(i)) << "." << endl;
                                        scMap.resetRobPos();
                                    }
                                }
                            }
                            //Checking to see if we can end the game (Player Has 11 points)
                            if(p1.getVicPoints() >= 11 || p2.getVicPoints() >= 11 || mapFull(&scMap) == true)
                            {
                                if(p1.getVicPoints() > p2.getVicPoints())
                                {
                                    addWins(count, names, player1Name);
                                    displayEnd(player1Name);
                                } else if (p1.getVicPoints() < p2.getVicPoints())
                                {
                                    addWins(count, names, player2Name);
                                    displayEnd(player2Name);
                                }

                                return 0;
                            }
                            endTurn = true;
                        }
                        //Displaying Inventory
                        if(selectMenuChoice == 2)
                        {
                            displayPlayer2Inventory(&p2);
                        }
                        //Display Items Inventory
                        else if(selectMenuChoice == 3)
                        {
                            displayP2Item(&Structures, &Dev);
                        }
                        //Display Building Costs
                        else if(selectMenuChoice == 4)
                        {
                            displayBuildCosts();
                        }
                        //Purchase Items
                        else if(selectMenuChoice ==5)
                        {
                            while(true){
                                int purchaseChoice = 0;
                                cout << "\x1b[36m----------\x1b[0m " << player2Name << "'s" << " Purchasing Menu" << "\x1b[36m ----------\x1b[0m" << endl;
                                cout << "Enter the corresponding menu number to purhcase that specific structure." << endl;
                                cout << "1) Road:" << "---------------- " << "\x1b[36m-\x1b[0m" << endl;
                                cout << "2) Settlement:" << "---------- " <<  "\x1b[36m^\x1b[0m" << endl;
                                cout << "3) City:" << "---------------- " << "\x1b[36m#\x1b[0m" << endl;
                                cout << "4) Development Card: --- " << "\x1b[36m[\x1b[0m" << "\U0001F0CF" << "\x1b[36m]\x1b[0m" << endl;
                                cout << "5) QUIT" << endl;
                                cin >> purchaseChoice;
                                    //Road
                                    if(purchaseChoice == 1 && mapFull(&scMap) ==false)
                                    {
                                        bool canBuy = condFuncToPurch(1,p2.getResourceAt(0), p2.getResourceAt(1), p2.getResourceAt(2), p2.getResourceAt(3), p2.getResourceAt(4));
                                        cout << "canBuy status: " << canBuy << endl;
                                        if(canBuy == true)
                                        {
                                                PurchStruct(2, 1, &Structures, &Dev, &p1, &p2);
                                                break;
                                        }
                                        else if(canBuy == false)
                                        {
                                            cout << "You do not have enough resources to purchase that structure." << endl;
                                        }  
                                        else if(mapFull(&scMap) == true)
                                        {
                                            cout << "The map is full, you may not purchase a road" << endl;
                                        }  
                                        
                                    }
                                    //Settlement
                                    if(purchaseChoice == 2 && mapFull(&scMap) ==false)
                                    {
                                        bool canBuy = condFuncToPurch(2,p2.getResourceAt(0), p2.getResourceAt(1), p2.getResourceAt(2), p2.getResourceAt(3), p2.getResourceAt(4));
                                        if(canBuy == true)
                                        {
                                                PurchStruct(2, 2, &Structures, &Dev, &p1, &p2);
                                                break;
                                        }
                                        else if(canBuy == false)
                                        {
                                            cout << "You do not have enough resources to purchase that structure." << endl;
                                        }  
                                        else if(mapFull(&scMap) == true)
                                        {
                                            cout << "The map is full, you may not purchase a settlement" << endl;
                                        }  
                                        
                                    }
                                    //City
                                    if(purchaseChoice == 3 && mapFull(&scMap) ==false)
                                    {
                                        bool canBuy = condFuncToPurch(3,p2.getResourceAt(0), p2.getResourceAt(1), p2.getResourceAt(2), p2.getResourceAt(3), p2.getResourceAt(4));
                                        if(canBuy == true)
                                        {
                                                PurchStruct(2, 3, &Structures, &Dev, &p1, &p2);
                                                break;
                                        }
                                        else if(canBuy == false)
                                        {
                                            cout << "You do not have enough resources to purchase that structure." << endl;
                                        }  
                                        else if(mapFull(&scMap) == true)
                                        {
                                            cout << "The map is full, you may not purchase a city" << endl;
                                        }  
                                        
                                    }
                                    //Development Card
                                    if(purchaseChoice == 4)
                                    {
                                        bool canBuy = condFuncToPurch(4,p2.getResourceAt(0), p2.getResourceAt(1), p2.getResourceAt(2), p2.getResourceAt(3), p2.getResourceAt(4));
                                        if(canBuy == true)
                                        {
                                                PurchStruct(2, 4, &Structures, &Dev, &p1, &p2);
                                                break;
                                        }
                                        else if(canBuy == false)
                                        {
                                            cout << "You do not have enough resources to purchase that structure." << endl;
                                        }  
                                    
                                    }
                                    else if(purchaseChoice == 5)
                                    {
                                        break;
                                    }
                                    else if((is_integer(purchaseChoice) == false))
                                    {
                                        cout << "Invalid purchasing input!" << endl;
                                        cin.clear();
                                        cin.ignore(80, '\n');
                                    }
                            }
                        }
                        //Place Structures and Roll Dice
                        else if(selectMenuChoice == 6)
                        {
                            while(true)
                            {
                                int placeChoice = 0;
                                cout << "\x1b[36m----------\x1b[0m " << player2Name << "'s" << " Placing Menu" << "\x1b[36m----------\x1b[0m" << endl;
                                cout << "Enter the corresponding menu number to place that specific structure." << endl;
                                cout << "1) Road:" << "---------------- " << "\x1b[36m-\x1b[0m" << endl;
                                cout << "2) Settlement:" << "---------- " <<  "\x1b[36m^\x1b[0m" << endl;
                                cout << "3) Upgrade to City:" << "----- " << "\x1b[36m#\x1b[0m" << endl;
                                cout << "4) QUIT" << endl;
                                cin >> placeChoice;
                                //Road
                                if(placeChoice ==1)
                                {
                                    if(Structures.getNumRoad2() > 0)
                                    {
                                    addingToMapRoadCont2(&scMap, &Structures);
                                    int currentRoad = Structures.getNumRoad2();
                                    Structures.setNumRoad2(currentRoad - 1);
                                    break;
                                    }
                                    else
                                    {
                                        cout << "You have no roads to place." << endl; 
                                    }
                                }
                                //Settlement
                                else if(placeChoice == 2)
                                {
                                    if(Structures.getNumSettlement2())
                                    {
                                        addingToMapSettlementCont2(&scMap, &Structures);
                                        int currenSettlement = Structures.getNumSettlement2();
                                        Structures.setNumSettlement2(currenSettlement - 1);
                                        break;
                                    }
                                    else
                                    {
                                        cout << "You have no settlements to place." << endl;
                                    }
                                    
                                }
                                // Upgrade to City
                                else if(placeChoice ==3)
                                {
                                    if(Structures.getNumCities2() > 0)
                                    {
                                        int tempCityXCor2;
                                        int tempCityYCor2;
                                        while (true)
                                        {
                                            cout << "Enter an x coordinate of settlement you want to upgrade" << endl;
                                            cin >> tempCityXCor2;
                                            if (tempCityXCor2 > 0 && tempCityXCor2 <= scMap.getNumCols())
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Invalid Input." << endl;
                                                cin.clear();
                                                cin.ignore(80, '\n');
                                            }
                                        }
                                        while (true)
                                        {
                                            cout << "Enter an y coordinate of settlement you want to upgrade" << endl;
                                            cin >> tempCityYCor2;
                                            if (tempCityYCor2 > 0 && tempCityYCor2 <= scMap.getNumRows())
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Invalid Input" << endl;
                                                cin.clear();
                                                cin.ignore(80, '\n');
                                            }
                                        }
                                        upgradeCity2(&scMap, &Structures, tempCityXCor2, tempCityYCor2);
                                        int currentCity2 = Structures.getNumCities2();
                                        Structures.setNumCities2(currentCity2 - 1);
                                        break;
                                    }
                                    else
                                    {
                                        cout << "You have no settlements to place." << endl;
                                    }
                                }
                                else if(placeChoice == 4){
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid input for placing a structure." << endl;
                                    cin.clear();
                                    cin.ignore(80, '\n');
                                }
                            }
                        }
                        //Check Victory Points
                        else if(selectMenuChoice == 7)
                        {
                            cout << player2Name << " you have " << p2.getVicPoints() << "." << endl;
                        }
                        //Check Leaderboard
                        else if(selectMenuChoice == 8)
                        {
                        count = 0;
                        // repopulating the arrays
                        myReadFile.open("victoryLog.txt");
                        if(myReadFile.is_open()){
                            cout << "file open" << endl;
                        }
                        while (getline(myReadFile, line))
                        {
                            if (line.length() > 1)
                            {
                                split(line, ':', players, 50);
                            }
                            names[count].setPlayerName(players[0]);
                            names[count].setNumWins(stoi(players[1]));
                            count++;
                        }
                        myReadFile.close();
                        cout << "----------Leaderboard----------" << endl;
                        cout << "----------" << endl;
                        displayLeaderboard(count, names);
                    }
                        //Use Development Card
                        else if(selectMenuChoice == 9)
                        {
                            int currentAmntDev = Dev.getNumDevCards2();
                            if(Dev.getNumDevCards2() > 0)
                            {
                                outcomeGenerator2(&Dev, &Structures, &p2);
                                Dev.setNumDevCards2(currentAmntDev -1);
                            }
                            else
                            {
                                cout << "You have no development cards to execute." << endl;
                            }
                        }
                        //Quit the game
                        else if(selectMenuChoice == 10){
                            cout << "Farewell " << player2Name << "." << endl;
                            return 0;
                        }
                        else if(selectMenuChoice > 10 || selectMenuChoice < 1)
                        {
                            cout << "Invalid Input!" << endl;
                            cin.clear();
                            cin.ignore(80, '\n');

                        }
                        else if(isdigit(selectMenuChoice) == false)
                        {
                            cin.clear();
                            cin.ignore(80, '\n');
                        }
                    }
                }
            
        }
        else if(toUpper(choice) == "Q")
        {
            return 0;
        }
        else
        {
            cout << "Invalid Input." << endl;
        }
    }
    return 0;
}