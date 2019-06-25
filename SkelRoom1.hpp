/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The class declaration for the SkeletonRoom1 child class.
************************************************************************************/ 

#ifndef SKELROOM1_H
#define SKELROOM1_H

#include "Space.hpp"
#include "Player.hpp"
#include "Dungeon.hpp"

class SkelRoom1:public Space
{
private:
	//is skeleton undead or dead-dead
	bool skeleFlag;

	//pointer to dungeon
	Dungeon *crypt;

	
public:
	/**********************
	** Constructors
	**********************/
	//default
	SkelRoom1();

	//Pointers passed in
	SkelRoom1(Player *inPlay, Dungeon *inDun);

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