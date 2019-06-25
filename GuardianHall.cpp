/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the GuardianHall child class.
************************************************************************************/ 

#include "Space.hpp"
#include "GuardianHall.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**********************
** Constructors
**********************/
//default
GuardianHall::GuardianHall()
{

}

//if player passed
GuardianHall::GuardianHall(Player *inPtr, Dungeon *inDun)
{
	player = inPtr;
	crypt = inDun;

}

/******************************************************************************
** Function triggered when player chooses to examine the room.
** Prints description to screen.
*******************************************************************************/
void GuardianHall::description()
{
	cout << endl;

	cout << "The room looks to have been made with great care, with well-crafted stone walls." << endl;
	cout << "You see a number of crypts, littered with symbols you do not recognize." << endl;
	cout << "The walls are also covered in a number of murals, depicting many different scenes." << endl;
	cout << "To the south, the passage seems to have collapsed and is unpassable." << endl;
	cout << "To the east and west are passages to other rooms." << endl;

	if(crypt->getWaterFlag() == false)
	{
		cout << "To the north is the passage the being left through, but it rests on the other side of a deep trench." << endl;
		cout << "To either side of the trench, you can see doors or gates." << endl;
	}

	if(crypt->getWaterFlag() == true)
	{
		cout << "To the north, the gates have opened, allowing water to flow in." << endl;
		cout << "The trench to the north is full, and you can swim across and enter the passage to the next room." << endl;
	}

	cout << endl;
}

/********************************************************************************
** Function triggered when player interacts with room.
** Interactions will often trigger flags that affect other functions.
*********************************************************************************/
void GuardianHall::interact()
{
	cout << endl;

	cout << "You figure disturbing the crypts is not a good idea..." << endl;

	if(crypt->getWaterFlag() == false)
	{
		cout << "You walk up to the trench, but it is too deep to cross." << endl;
		cout << "The doors to either side are closed tight, but might be activated elsewhere." << endl;
		cout << "A slight bit of moisture seems to be leaking from the bottom of the west gate..." << endl;
	}

	if(crypt->getWaterFlag() == true)
	{
		cout << "You put a hand in the water, and it seems safe enough." << endl;
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
Space* GuardianHall::move(int inMov)
{
	if(inMov == 1)
	{
		cout << endl;

		if(crypt->getWaterFlag() == false)
		{
			cout << "The passage north is blocked by a deep, empty trench" << endl;

			return NULL;
		}

		if(crypt->getWaterFlag() == true)
		{
			cout << "You swim across the trench and exit through the north passage." << endl;
			cout << "Time to find the being and a way out..." << endl;

			player->damage();
			return north;
		}

		cout << endl;
	}

	else if(inMov == 2)
	{
		cout << endl;

		cout << "You exit to the east" << endl;

		cout << endl;

		player->damage();

		return east;
	}

	else if(inMov == 3)
	{
		cout << endl;

		cout << "The way is blocked to the south, and you don't think you can dig it out" << endl;

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