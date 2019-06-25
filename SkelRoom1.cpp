/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the SkeletonRoom1 child class.
************************************************************************************/ 

#include "Space.hpp"
#include "SkelRoom1.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**********************
** Constructors
**********************/
//default
SkelRoom1::SkelRoom1()
{
	skeleFlag = false;
}

//Pointers passed in
SkelRoom1::SkelRoom1(Player *inPlay, Dungeon *inDun)
{
	skeleFlag = false;

	player = inPlay;
	crypt = inDun;
}

/******************************************************************************
** Function triggered when player chooses to examine the room.
** Prints description to screen.
** There is a skeleton in the room that needs to be defeated.
*******************************************************************************/
void SkelRoom1::description()
{
	cout << endl;

	cout << "It is a normal stone-walled room with a few symbols carved in the stone." << endl;
	cout << "There are passages to the north and east." << endl;

	if(skeleFlag == false)
	{
		cout << "You see a skeleton creaking around in the center of the room." << endl;
		cout << "You probably cannot pass if it is there." << endl;
	}

	if(skeleFlag == true)
	{
		cout << "The skeleton is nothing more than a heap of bones now." << endl;
	}

	cout << endl;
}

/********************************************************************************
** Function triggered when player interacts with room.
** Interactions will often trigger flags that affect other functions.
*********************************************************************************/
void SkelRoom1::interact()
{
	cout << endl;

	if(skeleFlag == true)
	{
		cout << "You poke around the pile of bones, but find nothing of note." << endl;
	}

	if(skeleFlag == false)
	{
		cout << "You try to sneak up and attack the skeleton." << endl;

		//see if player successfully attacks skeleton
		bool sneakAtk = player->attack();

		if(sneakAtk == false)
		{
			cout << "The skeleton saw you and swipes with its boney hand." << endl;
			cout << "You lose one health" << endl;
			cout << "If you do not try again, you will be unable to leave the room." << endl;

			player->damage();
		}

		else if(sneakAtk == true)
		{
			cout << "You successfully take out the skeleton." << endl;
			cout << "It falls to the ground in a bone heap." << endl;

			skeleFlag = true;
		}
		
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
Space* SkelRoom1::move(int inMov)
{

	if(skeleFlag == false)
	{
		if(crypt->getSneakFlag() == false)
		{
			cout << endl;

			cout << "The skeleton blocks your escape" << endl;

			cout << endl;

			return NULL;
		}

		else if(crypt->getSneakFlag() == true)
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

				cout << "You exit to the east" << endl;

				cout << endl;

				player->damage();

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
	}

	else if(skeleFlag == true)
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

			cout << "You exit to the east" << endl;

			cout << endl;

			player->damage();

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
}
