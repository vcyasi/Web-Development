/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the SluiceSwitchRoom child class.
************************************************************************************/ 

#include "Space.hpp"
#include "SwitchRoom.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**********************
** Constructors
**********************/
//default
SwitchRoom::SwitchRoom()
{

}

//if pointers passed in
SwitchRoom::SwitchRoom(Player *inPlay, Dungeon *inDun)
{
	player = inPlay;
	crypt = inDun;
}


/******************************************************************************
** Function triggered when player chooses to examine the room.
** Prints description to screen.
*******************************************************************************/
void SwitchRoom::description()
{
	cout << endl;

	cout << "You see a small stone room, with rather moist walls." << endl;
	cout << "It smells very moldy." << endl;

	if(crypt->getWaterFlag() == false)
	{
		cout << "After a moment, you notice some writing on the north wall." << endl;
		cout << "You cannot read the writing, but there is an arrow symbol pointing up." << endl;
		cout << "Looking up, you see a button on the ceiling." << endl;
	}

	else if(crypt->getWaterFlag() == true)
	{
		cout << "The button seems stuck pressed." << endl;
		cout << "You also hear running water echoing from the rest of the crypt." << endl;
	}

	cout << "The only exit seems to be to the south." << endl;

	cout << endl;
}

/********************************************************************************
** Function triggered when player interacts with room.
** Interactions will often trigger flags that affect other functions.
*********************************************************************************/
void SwitchRoom::interact()
{
	cout << endl;

	if(crypt->getWaterFlag() == true)
	{
		cout << "With the button pressed, there doesn't seem to be anything else to do." << endl;
		cout << "You touch the walls." << endl;
		cout << "Slimy..." << endl;
	}

	else if(crypt->getWaterFlag() == false)
	{
		if(player->getBoomerangFlag() == false)
		{
			cout << "You try to reach the button on the roof." << endl;
			cout << "But, it is too high up..." << endl;
		}

		else if(player->getBoomerangFlag() == true)
		{
			cout << "You try to reach the button on the roof." << endl;
			cout << "You then remember the boomerang you found." << endl;
			cout << "Taking it in hand, you throw it hard at the button on the ceiling." << endl;
			cout << "You miss..." << endl;
			cout << "You pick the boomerang back up and try again." << endl;
			cout << "And miss again..." << endl;
			cout << "You are rather embarassed, but try yet again." << endl;
			cout << "Third time was the charm." << endl;
			cout << "You hit the button squarely and it pushes in." << endl;
			cout << "Nothing happens in the room, but you hear sliding metal and rushing" << endl;
			cout << "water echo from farther off in the crypt." << endl;

			crypt->setWaterFlag(true);
		}
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
Space* SwitchRoom::move(int inMov)
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

		cout << "You exit to the south" << endl;

		cout << endl;

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