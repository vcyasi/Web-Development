/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the OldMan'sRoom child class.
************************************************************************************/ 

#include "Space.hpp"
#include "OldMan.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**********************
** Constructors
**********************/
//default
OldMan::OldMan()
{

}

//if player passed in
OldMan::OldMan(Player *inPtr)
{
	player = inPtr;
}

/******************************************************************************
** Function triggered when player chooses to examine the room.
** Prints description to screen.
*******************************************************************************/
void OldMan::description()
{
	cout << endl;

	cout << "You see a well-crafted stone walled room." << endl;
	cout << "There are many symbols carved into the walls." << endl;
	cout << "The room is also filled with many gravestones and small cairns." << endl;
	cout << "In the center of the room you see a shabby man, seemingly in meditation." << endl;
	cout << "The only exit is to the east." << endl;

	cout << endl;
}

/********************************************************************************
** Function triggered when player interacts with room.
** Interactions will often trigger flags that affect other functions.
*********************************************************************************/
void OldMan::interact()
{
	cout << endl;

	cout << "You walk up to the shabby man, and are taken aback." << endl;
	cout << "He is a corpse!" << endl;
	cout << "Or no, wait, a zombie!" << endl;
	cout << "You jump back before he can attack, but he does not." << endl;
	cout << "The zombie just opens his eyes and greets you:" << endl;
	cout << "'Well, hello there, friend. Don't often see the living here." << endl;
	cout << "But, I'm a bit busy, so bug off.'" << endl;
	cout << "He closes his eyes again and seems to return to meditation." << endl;
	cout << "You find that a bit rude, but turn to leave." << endl;
	cout << "You hear the man talk again, though:" << endl;
	cout << "'Wait, I'm an NPC, aren't I? I should probably give you some" << endl;
	cout << "knowledge or something. Umm, how about something like <One's highest goal" << endl;
	cout << "is achievable with a little piece of wood>?" << endl;
	cout << "Yeah, that sounds good...'" << endl;
	cout << "The zombie then goes back to his meditation." << endl;

	cout << endl;
}

/********************************************************************************
** Function to move player to adjacent rooms.
** Takes in 1, 2, 3, or 4 to denote which direction player wants to move.
** (1 - North, 2 - East, 3 - East, 4 - West)
** Function called by Dungeon class.
** Returns pointer to new player location.
*********************************************************************************/
Space* OldMan::move(int inMov)
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