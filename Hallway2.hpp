/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The class declaration for the Hallway2 child class.
************************************************************************************/ 

#ifndef HALLWAY2_H
#define HALLWAY2_H

#include "Space.hpp"

class Hallway2:public Space
{
private:


	
public:
	/**********************
	** Constructors
	**********************/
	//default
	Hallway2();

	//if player passed
	Hallway2(Player *inPtr);


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