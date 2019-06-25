/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the EasterEggRoom child class.
************************************************************************************/ 

#include "Space.hpp"
#include "EggRoom.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**********************
** Constructors
**********************/
//default
EasterEggRoom::EasterEggRoom()
{

}

//if player passed
EasterEggRoom::EasterEggRoom(Player *inPtr)
{
	player = inPtr;
}

/******************************************************************************
** Function triggered when player chooses to examine the room.
** Prints description to screen.
*******************************************************************************/
void EasterEggRoom::description()
{
	cout << endl;

	cout << "The room is even smaller than the last." << endl;
	cout << "It is rather plain and rough-hewn." << endl;
	cout << "The only feature of the room is a moderate-sized stone egg sitting on a pedestal." << endl;
	cout << "The only exit seems to be to the south, where you entered." << endl;

	cout << endl;
}

/********************************************************************************
** Function triggered when player interacts with room.
** Interactions will often trigger flags that affect other functions.
*********************************************************************************/
void EasterEggRoom::interact()
{
	cout << endl;

	cout << "You can see a single word carved into the egg." << endl;
	cout << "It says: EASTER" << endl;
	cout << "What is an Easter?" << endl;

	cout << endl;
}

/********************************************************************************
** Function to move player to adjacent rooms.
** Takes in 1, 2, 3, or 4 to denote which direction player wants to move.
** (1 - North, 2 - East, 3 - East, 4 - West)
** Function called by Dungeon class.
** Returns pointer to new player location.
*********************************************************************************/
Space* EasterEggRoom::move(int inMov)
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

		cout << "There is no exit this way" << endl;

		cout << endl;

		return NULL;
	}

	else if(inMov == 3)
	{
		cout << endl;

		cout << "You exit through the secret passage to the south" << endl;

		cout << endl;

		player->damage();

		return south;
	}

	else if(inMov == 4)
	{
		cout << endl;

		cout << "There is no exit this way" << endl;

		cout << endl;

		return NULL;		
	}

}
