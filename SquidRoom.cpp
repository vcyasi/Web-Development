/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the SquidRoom child class.
************************************************************************************/ 

#include "Space.hpp"
#include "SquidRoom.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**********************
** Constructors
**********************/
//default
SquidRoom::SquidRoom()
{
	counter = 0;
}

//if player passed in
SquidRoom::SquidRoom(Player *inPtr)
{
	player = inPtr;

	counter = 0;
}


/******************************************************************************
** Function triggered when player chooses to examine the room.
** Prints description to screen.
*******************************************************************************/
void SquidRoom::description()
{
	cout << endl;

	cout << "You see a pretty normal room." << endl;
	cout << "There isn't really anything too interesting about it." << endl;
	cout << "There is an exit to the south and to the west." << endl;

	cout << endl;
}

/********************************************************************************
** Function triggered when player interacts with room.
** Interactions will often trigger flags that affect other functions.
*********************************************************************************/
void SquidRoom::interact()
{
	cout << endl;

	if(counter >= 5)
	{
		cout << "Oops, some soul leaked out..." << endl;
		cout << "You lose one health" << endl;

		player->damage();
	}

	else if(counter == 4)
	{
		cout << "If you wait here too long, your soul will start leaking out..." << endl;

		counter++;
	}

	else if(counter == 3)
	{
		cout << "I mean, there is a moldy smell, but nothing more." << endl;

		counter++;
	}

	else if(counter == 2)
	{
		cout << "Wait, what is that?!  Oh, nothing..." << endl;

		counter++;
	}

	else if(counter == 1)
	{
		cout << "I told you, there is nothing here..." << endl;

		counter++;
	}

	else if(counter == 0)
	{
		cout << "There is nothing here." << endl;

		counter++;
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
Space* SquidRoom::move(int inMov)
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

		cout << "You exit to the west" << endl;

		cout << endl;

		return west;		
	}
}