/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the BoomerangRoom child class.
************************************************************************************/ 

#include "Space.hpp"
#include "BoomerangRoom.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**********************
** Constructors
**********************/
//default
BoomerangRoom::BoomerangRoom()
{
	chestFlag = false;
	eggFlag = false;
}

//if player passed in
BoomerangRoom::BoomerangRoom(Player *inPtr)
{
	chestFlag = false;
	eggFlag = false;

	player = inPtr;
}

/******************************************************************************
** Function triggered when player chooses to examine the room.
** Prints description to screen.
*******************************************************************************/
void BoomerangRoom::description()
{
	cout << endl;

	cout << "The room is small, though has a series of murals depicting scenes from" << endl;
	cout << "a great battle between man and beast." << endl;
	cout << "The man is wielding a curved something or other." << endl;

	if(chestFlag == false)
	{
		cout << "There is a chest sitting on a dais in the center of the room." << endl;
	}

	if(chestFlag == true)
	{
		cout << "The chest sits open, its prize claimed." << endl;
	}

	cout << "The only passage out seems to be to the south." << endl;

	cout << endl;
}

/********************************************************************************
** Function triggered when player interacts with room.
** Interactions will often trigger flags that affect other functions.
*********************************************************************************/
void BoomerangRoom::interact()
{
	cout << endl;

	if(chestFlag == true)
	{
		if(eggFlag == true)
		{
			cout << "The room seems to have no new secrets." << endl;
		}

		else if(eggFlag == false)
		{
			cout << "You think you see a well-hidden button also in the chest."  << endl;
			cout << "You press it and the wall panel to the north slides away, revealing a new passage." << endl;

			eggFlag = true;
		}
	}

	else if(chestFlag == false)
	{
		cout << "You walk to the chest and open it, cautious of traps." << endl;
		cout << "None spring, and you find a curved piece of wood, similar to the one on the wall." << endl << endl;

		cout << "You found a BOOMERANG" << endl;
		cout << "You can probably use it to hit out of reach things." << endl << endl;

		cout << "You pick up the boomerang." << endl;

		chestFlag = true;

		//add boomerang to player inventory
		player->addItem(1);
		player->setBoomerangFlag(true);
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
Space* BoomerangRoom::move(int inMov)
{
	if(inMov == 1)
	{
		if(eggFlag == false)
		{
			cout << endl;

			cout << "There is no exit this way" << endl;

			cout << endl;

			return NULL;
		}

		else if(eggFlag == true)
		{
			cout << endl;

			cout << "You exit through the secret passage to the north" << endl;

			cout << endl;

			player->damage();

			return north;
		}
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

		cout << "You exit to the south" << endl;

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