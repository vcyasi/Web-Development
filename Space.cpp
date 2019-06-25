/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the Space parent class.
**               Has get/set functions for each pointer.
**               Parent class to individual rooms.
************************************************************************************/ 

#include "Space.hpp"

/**********************
** Constructors
**********************/
//default
Space::Space()
{
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
}

/****************************
** Get and Set Functions
****************************/
Space* Space::getNorth()
{
	return north;
}

Space* Space::getEast()
{
	return east;
}

Space* Space::getSouth()
{
	return south;
}

Space* Space::getWest()
{
	return west;
}

void Space::setNorth(Space *inPtr)
{
	north = inPtr;
}

void Space::setEast(Space *inPtr)
{
	east = inPtr;
}

void Space::setSouth(Space *inPtr)
{
	south = inPtr;
}

void Space::setWest(Space *inPtr)
{
	west = inPtr;
}
