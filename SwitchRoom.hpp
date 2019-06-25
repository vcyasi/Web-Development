/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The class declaration for the SluiceSwitchRoom child class.
************************************************************************************/ 

#ifndef SWITCHROOM_H
#define SWITCHROOM_H

#include "Space.hpp"
#include "Dungeon.hpp"

class SwitchRoom:public Space
{
private:
	//pointer to the dungeon
	Dungeon *crypt;

	
public:
	/**********************
	** Constructors
	**********************/
	//default
	SwitchRoom();

	//if pointers passed in
	SwitchRoom(Player *inPlay, Dungeon *inDun);


	/******************************************************************************
	** Function triggered when player chooses to examine the room.
	** Prints description to screen.
	*******************************************************************************/
	void description();

	/********************************************************************************
	** Function triggered when player interacts with room.
	** Interactions will often trigger flags that affect other functions.
	*********************************************************************************/
	void interact();

	/********************************************************************************
	** Function to move player to adjacent rooms.
	** Takes in 1, 2, 3, or 4 to denote which direction player wants to move.
	** (1 - North, 2 - East, 3 - East, 4 - West)
	** Function called by Dungeon class.
	** Returns pointer to new player location.
	*********************************************************************************/
	Space* move(int inMov);

};

#endif