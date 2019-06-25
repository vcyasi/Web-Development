/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the SneakCloakRoom child class.
************************************************************************************/ 

#include "Space.hpp"
#include "CloakRoom.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**********************
** Constructors
**********************/
//default
CloakRoom::CloakRoom()
{
	cloakFlag == false;
}

//if pointers passed in
CloakRoom::CloakRoom(Player *inPlay, Dungeon *inDun)
{
	cloakFlag == false;

	player = inPlay;
	crypt = inDun;

}


/******************************************************************************
** Function triggered when player chooses to examine the room.
** Prints description to screen.
*******************************************************************************/
void CloakRoom::description()
{
	cout << endl;

	cout << "This seems to be a small passage that allows water to flow out." << endl;

	if(cloakFlag == false)
	{
		cout << "You see an old corpse of an unfortunate soul." << endl;
	}

	cout << "The passage used to continue on further to the east, but it has since collapsed." << endl;
	cout << "You don't think you can move the rubble." << endl;
	cout << "The only exit is back to the west." << endl;

	cout << endl;
}

/********************************************************************************
** Function triggered when player interacts with room.
** Interactions will often trigger flags that affect other functions.
*********************************************************************************/
void CloakRoom::interact()
{
	cout << endl;

	if(cloakFlag == true)
	{
		cout << "You check the collapsed passage, but it cannot be cleared." << endl;
	}

	else if(cloakFlag == false)
	{
		cout << "You check the corpse and find a cloak still in good condition." << endl;
		cout << "You found a SNEAK CLOAK" << endl;
		cout << "It should let you be sneakier and maybe sneak pass enemies." << endl;

		player->addItem(2);
		crypt->setSneakFlag(true);
		cloakFlag = true;
	}

	cout << endl;
}

/********************************************************************************
** Function to move player to adjacent rooms.
** Takes in 1, 2, 3, or 4 to denote which direction player wants to move.
** (1 - North, 2 - East, 3 - East, 4 - West)
** Function called by Dungeon class.
** Returns pointer to new player location.
*********************************************************************************/
Space* CloakRoom::move(int inMov)
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

		cout << "There is no exit this way" << endl;

		cout << endl;

		return NULL;
	}

	else if(inMov == 4)
	{
		cout << endl;

		cout << "You exit to the west" << endl;

		cout << endl;

		player->damage();

		return west;		
	}
}