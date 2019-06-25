/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the HealingStatueRoom child class.
************************************************************************************/ 

#include "Space.hpp"
#include "Statue.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**********************
** Constructors
**********************/
//default
StatueRoom::StatueRoom()
{

}

//if player passed in
StatueRoom::StatueRoom(Player *inPtr)
{
	player = inPtr;
}


/******************************************************************************
** Function triggered when player chooses to examine the room.
** Prints description to screen.
*******************************************************************************/
void StatueRoom::description()
{
	cout << endl;

	cout << "You see a small stone room with many murals and carvings on the wall." << endl;
	cout << "The murals and carvings seem religious in nature, but you do not recognize them." << endl;
	cout << "In the center of the room is a statue of a woman, weeping streams of tears that pool at her feet." << endl;
	cout << "The only exit is to the east." << endl;

	cout << endl;
}

/********************************************************************************
** Function triggered when player interacts with room.
** Interactions will often trigger flags that affect other functions.
*********************************************************************************/
void StatueRoom::interact()
{
	cout << endl;

	cout << "You kneel down at the statue's feet and drink some water." << endl;
	cout << "You feel much better (though the emptiness remains)." << endl;
	cout << "You heal 10 health" << endl;

	//I am aware that a player can activate this infinitely
	//That is on purpose, as this is not a serious game
	//If I wanted to, I could put a cap on number of activations
	//I am also aware player can technically overflow int storing HP, though that would take a long time, and so did not guard against
	player->heal(10);

	cout << endl;
}

/********************************************************************************
** Function to move player to adjacent rooms.
** Takes in 1, 2, 3, or 4 to denote which direction player wants to move.
** (1 - North, 2 - East, 3 - East, 4 - West)
** Function called by Dungeon class.
** Returns pointer to new player location.
*********************************************************************************/
Space* StatueRoom::move(int inMov)
{
	if(inMov == 1)
	{
		cout << endl;

		cout << "There is no exit this way" << endl;

		cout << endl;

		return NULL;
	}

	else if(inMov == 2)
	{
		cout << endl;

		cout << "You exit to the east" << endl;

		cout << endl;

		return east;
	}

	else if(inMov == 3)
	{
		cout << endl;

		cout << "There is no exit this way" << endl;

		cout << endl;

		return NULL;
	}

	else if(inMov == 4)
	{
		cout << endl;

		cout << "There is no exit this way" << endl;

		cout << endl;	

		return NULL;	
	}

}