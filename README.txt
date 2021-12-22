------------------------
HOW TO COMPILE AND RUN
------------------------
Compile: g++ -std=c++11 scMap.cpp Player1.cpp Player2.cpp Structures.cpp Dev.cpp Leaderboard.cpp diceRoll.cpp settlersOfCatanGame.cpp -osettlersOfCatan
Run: ./settlersOfCatan 
------------------------
DEPENDENCIES
------------------------
Dev.h, diceRoll.h, Leaderboard.h, Player1.h, Player2.h, scMap.h, Structures.h
must be in the same directory as the cpp files in order to compile.
------------------------
SUBMISSION INFORMATION
------------------------
CSCI1300 Fall 2021 Project 3: settlersOfCatanGame
Author: Ishan Gohil, Jaskarn Kahlon
Recitation: 123 - Spencer Paulissen
Date: November 2, 2021
------------------------
ABOUT THIS PROJECT
------------------------
Settlers of Catan is a strategy game where players collect resources and use them to build roads, settlements and cities on 
their way to victory.

Rule Book:
You will begin your turn by rolling both dice. The sum of the dice corresponds to a coordinate on the map, and each coordinate corresponds to a resource.  If you have a settlement built on the coordinate, you will gain 1 of the corresponding resource.
—----------------------------------------------------------------------------------------------------------------------------
The objective of the game is to be the first person to reach 11 victory points
How to get victory points?
-Largest army
	You can purchase Development cards from the menu, with the chance of pulling a Soldier card. Whoever has the most soldiers at the end of the game gains 1 victory point.

-Settlements
	For every additional settlement you build, you gain 1 victory point

-City
You cannot build a city directly, you can only upgrade an existing settlement to a city, Every city is worth 2 victory points.
—----------------------------------------------------------------------------------------------------------------------------
Purchasing-
You may purchase items on your turn after you have rolled. To an item purchase, you must turn in the specified amount of resources. You may purchase as many items as you like, as long as you have enough resources to pay for them.
—----------------------------------------------------------------------------------------------------------------------------
Placing Items-
To place an item, you must first have it in your inventory. You can check your inventory during your turn by clicking option “3”.
To place a settlement, it must be surrounded by 2 roads.   - - ^ | | ^ - - | |  -  | | ^
									          -        -
								                     ^       -
—----------------------------------------------------------------------------------------------------------------------------
Every time you purchase a development card, you have the chance of pulling a fortune or misfortune card
There are 5 different kinds of development cards. 
-Three of them are fortune cards: +1 soldier, +2 sheep, +2 roads.
-Two are misfortune cards: -1 wheat, and a card that wipes all of your sheep.

