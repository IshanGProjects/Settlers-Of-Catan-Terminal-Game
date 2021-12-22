#ifndef SCMAP_H
#define SCMAP_H

#include <fstream>
#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std; 


class scMap
{
    private:
        //BOTH PLAYERS
            //Flag to stop the randomization of the resource map
            bool randomize = false;
            //Structures Map Dimensions
            static const int num_rows = 10;
            static const int num_cols = 18;
            //Desribing the robber position
            int robPos[2];
            string mapData[num_cols][num_rows];
            //resource map 
            string resMapData[num_cols][num_rows];
            //resource rollNum data
            int resRollNumData[num_cols][num_rows];   
        //PLAYER 1
            //Amount of Structures
                int numRoads1;
                int numSettlement1;
                int numCity1;
            //Describing the variables that define the system in place to specify the coordinates of the various structures
                //Road
                vector <int> roadXCor1;
                vector <int> roadYCor1;
                //Settlement
                vector <int> settlementXCor1;
                vector <int> settlementYCor1;
                //City
                vector <int> cityXCor1;
                vector <int> cityYCor1;
            //Total size of each of the vectors
                //ROAD
                int roadXCorSize1;
                int roadYCorSize1;
                //Settlement
                int settlementXCorSize1;
                int settlementroadYCorSize1;
                //City
                int cityXCorSize1;
                int cityYCorSize1;
        //PLAYER 2
            //Amount of Structures
                int numRoads2;
                int numSettlement2;
                int numCity2;
            //Describing the variables that define the system in place to specify the coordinates of the various structures
                //Road
                vector <int> roadXCor2;
                vector <int> roadYCor2;
                //Settlement
                vector <int> settlementXCor2;
                vector <int> settlementYCor2;
                //City
                vector <int> cityXCor2;
                vector <int> cityYCor2;
            //Total size of each of the vectors
                //Road
                int roadXCorSize2;
                int roadYCorSize2;
                //Settlement
                int settlementXCorSize2;
                int settlementroadYCorSize2;
                //City
                int cityXCorSize2;
                int cityYCorSize2;
//--------------------------------------------------------------------------------------------------------------------------------
    public:
    //BOTH PLAYERS
        //Randomize Setter
        void setRandomize(bool r){
            randomize = r;
        }
        //Randomize Getter
        bool getRandomize(){
            return randomize;
        }
        //Getting the dimensions of the map
        int getNumRows();
        int getNumCols();
        //spawning the robber
        void spawnRob();
        //Getting
        int getRobPosAt(int index);
        //resetting the robber
        void resetRobPos();
        //Resource getters 
        int getResNumAtPos(int j, int i);
        string getResAtPos(int j, int i);
        //Map Data Getter
        string getMapDataCharAt(int j, int i);
        void setMapDataCharAt(string ch, int j, int i);
        //Constructor
        scMap();
    //PLAYER 1
        //GETTERS
            //Getting the amount of Structures there are
            int getNumRoads1();
            int getNumSettlement1();
            int getNumCity1();

            //Getting the position vectors
                //Road
                int getRoadAtXCor1(int);
                int getRoadAtYCor1(int);

                //Settlement
                int getSettlementAtXCor1(int);
                int getSettlementAtYCor1(int);
                
                //City
                int getCityAtXCor1(int);
                int getCityAtYCor1(int);

            //Getting the total size of the vectors
            int getRoadXCorSize1();
            int getRoadYCorSize1();
            int getSettlementXCorSize1();
            int getSettlementYCorSize1();
            int getCityXCorSize1();
            int getCityYCorSize1();
            
            //Getting the complete vector
            vector <int> getRoadXCorVect1();
            vector <int> getRoadYCorVect1();

            vector <int> getSettlementXCorVect1();
            vector <int> getSettlementYCorVect1();

            vector <int> getCityXCorVect1();
            vector <int> getCityYCorVect1();

        //SETTERS
            void resetMap();
            //Setting the number of structure
                void setNumRoads1(int);
                void setNumSettlement1(int);
                void setNumCity1(int);
            //Setting the position vectors
                void setRoadXCor1(int);
                void setRoadYCor1(int);
                void setSettlementXCor1(int);
                void setSettlementYCor1(int);
                void setCityXCor1(int);
                void setCityYCor1(int);
            //spawning 
                //spawining roads
                int spawnRoads1(int);

                //spawining the settlement
                int spawnSettlement1(int);

                //spawning city
                int spawnCity1(int);

                //Display the map
                void displayMap();

                //Display the resource map 
                void displayResMap();
                
//-------------------------------------------------------------------------------------------------------------------------------
    
    //PLAYER 2
        //GETTERS
            //Getting the amount of Structures there are
            int getNumRoads2();
            int getNumSettlement2();
            int getNumCity2();

            //Getting the position vectors
                //Road
                int getRoadAtXCor2(int);
                int getRoadAtYCor2(int);

                //Settlement
                int getSettlementAtXCor2(int);
                int getSettlementAtYCor2(int);

                //City
                int getCityAtXCor2(int);
                int getCityAtYCor2(int);
                

            //Getting the total size of the vectors
            int getRoadXCorSize2();
            int getRoadYCorSize2();
            int getSettlementXCorSize2();
            int getSettlementYCorSize2();
            int getCityXCorSize2();
            int getCityYCorSize2();
            
            //Getting the complete vector
            vector <int> getRoadXCorVect2();
            vector <int> getRoadYCorVect2();

            vector <int> getSettlementXCorVect2();
            vector <int> getSettlementYCorVect2();

            vector <int> getCityXCorVect2();
            vector <int> getCityYCorVect2();

        //SETTERS
            //Setting the number of structure
                void setNumRoads2(int);
                void setNumSettlement2(int);
                void setNumCity2(int);
            //Setting the position vectors
                void setRoadXCor2(int);
                void setRoadYCor2(int);
                void setSettlementXCor2(int);
                void setSettlementYCor2(int);
                void setCityXCor2(int);
                void setCityYCor2(int);
            //spawning 
                // //spawning the robber
                // bool spawnRob(int);

                //spawining roads
                int spawnRoads2(int);

                //spawining the settlement
                int spawnSettlement2(int);

                //spawning city
                int spawnCity2(int);

};
#endif
