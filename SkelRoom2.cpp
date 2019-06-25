/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the SkeletonRoom2 child class.
************************************************************************************/ 

#include "Space.hpp"
#include "SkelRoom2.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**********************
** Constructors
**********************/
//default
SkelRoom2::SkelRoom2()
{
	skeleFlag = false;
	rubbleFlag = false;
}

//if player passed in
SkelRoom2::SkelRoom2(Player *inPlay, Dungeon *inDun)
{
	skeleFlag = false;
	rubbleFlag = false;

	player = inPlay;
	crypt = inDun;
}

/******************************************************************************
** Function triggered when player chooses to examine the room.
** Prints description to screen.
*******************************************************************************/
void SkelRoom2::description()
{
	cout << endl;

	cout << "It is a normal stone-walled room with a few symbols carved in the stone." << endl;
	cout << "There are passages to the north and east." << endl;
	if(rubbleFlag == false)
	{
		cout << "There looks to have once been a passage to the west, as well." << endl;
		cout << "However, it has collapsed." << endl;
	}

	else if(rubbleFlag == true)
	{
		cout << "The passage to the west is cleared." << endl;
	}

	if(skeleFlag == false)
	{
		cout << "You see a skeleton creaking around in the center of the room." << endl;
		cout << "You probably cannot pass if it is there." << endl;
	}

	if(skeleFlag == true)
	{
		cout << "The skeleton is nothing more than a heap of bones now." << endl;

		if(rubbleFlag == false)
		{
			cout << "On second glance at the collapsed passage, you think you may be able to" << endl;
			cout << "move the rubble out of the way, though you may injure yourself." << endl;
		}
	}

	cout << endl;
}

/********************************************************************************
** Function triggered when player interacts with room.
** Interactions will often trigger flags that affect other functions.
*********************************************************************************/
void SkelRoom2::interact()
{
	cout << endl;

	if(skeleFlag == true)
	{
		cout << "You poke around the pile of bones, but find nothing of note." << endl;

		if(rubbleFlag == false)
		{
			cout << "You decide to try and clear the passage to the west." << endl;
			cout << "It takes a bit, but you get it cleared." << endl;
			cout << "However, it seems to have exacerbated your 'condition'." << endl;
			cout << "You lose one health" << endl;

			player->damage();
			rubbleFlag = true;
		}
	}

	else if(skeleFlag == false)
	{
		cout << "You try to sneak up and attack the skeleton." << endl;

		//see if player successfully attacks skeleton
		bool sneakAtk = player->attack();

		if(sneakAtk == true)
		{
			cout << "You successfully take out the skeleton." << endl;
			cout << "It falls to the ground in a bone heap." << endl;

			skeleFlag = true;
		}
		else if(sneakAtk == false)
		{
			cout << "The skeleton saw you and swipes with its boney hand." << endl;
			cout << "You lose one health" << endl;
			cout << "If you do not try again, you will be unable to leave the room." << endl;

			player->damage();
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
Space* SkelRoom2::move(int inMov)
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
				if(rubbleFlag == false)
				{
					cout << endl;

					cout << "The rubble blocks the way" << endl;

					cout << endl;

					return NULL;	
				}

				else if(rubbleFlag == true)
				{
					cout << endl;

					cout << "You exit through the cleared passage to the west" << endl;

					cout << endl;

					player->damage();

					return west;				
				}	
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
			if(rubbleFlag == false)
			{
				cout << endl;

				cout << "The rubble blocks the way" << endl;

				cout << endl;	

				return NULL;
			}

			else if(rubbleFlag == true)
			{
				cout << endl;

				cout << "You exit through the cleared passage to the west" << endl;

				cout << endl;

				player->damage();

				return west;				
			}	
		}
	}
}
