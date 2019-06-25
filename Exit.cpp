/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the Exit child class.
************************************************************************************/ 

#include "Space.hpp"
#include "Exit.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**********************
** Constructors
**********************/
//default
Exit::Exit()
{

}

//if pointers passed in
Exit::Exit(Player *inPlay, Dungeon *inDun)
{
	player = inPlay;
	crypt = inDun;
}

/******************************************************************************
** Function triggered when player chooses to examine the room.
** Prints description to screen.
*******************************************************************************/
void Exit::description()
{
	cout << endl;

	cout << "You see what appears to be an entrance chamber to the crypts below." << endl;
	cout << "You must have been exploring an ancient (and rather odd) burial place." << endl;
	cout << "That would explain the skeletons, symbols, and guardian." << endl;
	cout << "You can see crumbling stone stairs leading up to sunlight in the north." << endl;
	cout << "That must be the way out." << endl;

	cout << endl;
}

/********************************************************************************
** Function triggered when player interacts with room.
** Interactions will often trigger flags that affect other functions.
*********************************************************************************/
void Exit::interact()
{
	cout << endl;

	cout << "You sigh a breath of relief and walk up the stairs." << endl;
	cout << "You have made it out alive." << endl;
	cout << "And you still have your stolen trinket!" << endl;
	cout << "Hopefully the city guards chasing you have dispersed..." << endl;

	cout << endl;

	crypt->setEndingFlag(true);
}

/********************************************************************************
** Function to move player to adjacent rooms.
** Takes in 1, 2, 3, or 4 to denote which direction player wants to move.
** (1 - North, 2 - East, 3 - East, 4 - West)
** Function called by Dungeon class.
** Returns pointer to new player location.
*********************************************************************************/
Space* Exit::move(int inMov)
{
	if(inMov == 1)
	{
		cout << endl;

		cout << "You sigh a breath of relief and walk up the stairs." << endl;
		cout << "You have made it out alive." << endl;
		cout << "And you still have your stolen trinket!" << endl;
		cout << "Hopefully the city guards chasing you have dispersed..." << endl;

		cout << endl;

		crypt->setEndingFlag(true);
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

		cout << "The exit is right there, buddy..." << endl;
		cout << "Take the stairs." << endl;

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