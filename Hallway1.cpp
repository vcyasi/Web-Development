/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the Hallway1 child class.
************************************************************************************/ 

#include "Space.hpp"
#include "Hallway1.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**********************
** Constructors
**********************/
//default
Hallway1::Hallway1()
{

}

//if player passed
Hallway1::Hallway1(Player *inPtr)
{
	player = inPtr;
}

/******************************************************************************
** Function triggered when player chooses to examine the room.
** Prints description to screen.
*******************************************************************************/
void Hallway1::description()
{
	cout << endl;

	cout << "You find yourself in a normal hallway, laid out in a T shape." << endl;
	cout << "There are passages to the north, south, and west."  << endl;

	cout << endl;
}

/********************************************************************************
** Function triggered when player interacts with room.
** Interactions will often trigger flags that affect other functions.
*********************************************************************************/
void Hallway1::interact()
{
	cout << endl;

	cout << "The walls are well-crafted stone, and your hand glides nicely over them." << endl;

	cout << endl;
}

/********************************************************************************
** Function to move player to adjacent rooms.
** Takes in 1, 2, 3, or 4 to denote which direction player wants to move.
** (1 - North, 2 - East, 3 - East, 4 - West)
** Function called by Dungeon class.
** Returns pointer to new player location.
*********************************************************************************/
Space* Hallway1::move(int inMov)
{
	if(inMov == 1)
	{
		cout << endl;

		cout << "You exit to the north" << endl;

		cout << endl;

		player->damage();

		return north;
	}

	else if(inMov == 2)
	{
		cout << endl;

		cout << "There is no exit that way" << endl;

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

		cout << "You exit to the west" << endl;

		cout << endl;

		player->damage();

		return west;		
	}
}