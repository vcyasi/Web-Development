/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The class declaration for the Space parent class.
**               Has pointers to north, south, east, and west adjacent rooms.
**               Has get/set functions for each pointer.
**               Parent class to individual rooms.
************************************************************************************/ 

#ifndef SPACE_H
#define SPACE_H

#include "Player.hpp"

class Space
{
protected:
	//pointers to the rooms to the North, South, East, and West of this room
	//are the top, right, left, and right pointers from the assignment
	Space *north;
	Space *east;
	Space *south;
	Space *west;

	//pointer to the Player object
	Player *player;


	
public:
	/**********************
	** Constructors
	**********************/
	//default
	Space();

	/****************************
	** Get and Set Functions
	****************************/
	Space* getNorth();
	Space* getEast();
	Space* getSouth();
	Space* getWest();

	void setNorth(Space *inPtr);
	void setEast(Space *inPtr);
	void setSouth(Space *inPtr);
	void setWest(Space *inPtr);

	/******************************************************************************
	** Virtual function triggered when player chooses to examine the room.
	** Each child object has a specialized description printed via this function.
	** Multiple descriptions can be used with use of flags.
	*******************************************************************************/
	virtual void description() = 0;

	/********************************************************************************
	** Virtual function triggered when player interacts with room.
	** Each child object has specialized interacts.
	** Interactions will often trigger flags that affect other functions.
	*********************************************************************************/
	virtual void interact() = 0;

	/********************************************************************************
	** Virtual function to move player to adjacent rooms.
	** Takes in 1, 2, 3, or 4 to denote which direction player wants to move.
	** (1 - North, 2 - East, 3 - East, 4 - West)
	** Function called by Dungeon class.
	** Returns pointer to new player location.
	*********************************************************************************/
	virtual Space* move(int inMov) = 0;

	



};

#endif