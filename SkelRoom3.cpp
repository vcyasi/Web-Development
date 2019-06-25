/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the SkeletonRoom3 child class.
************************************************************************************/ 

#include "Space.hpp"
#include "SkelRoom3.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**********************
** Constructors
**********************/
//default
SkelRoom3::SkelRoom3()
{
	skeleFlag = false;
	counter = 0;
}

//if player passed in
SkelRoom3::SkelRoom3(Player *inPlay, Dungeon *inDun)
{
	skeleFlag = false;
	counter = 0;

	player = inPlay;
	crypt = inDun;
}


/******************************************************************************
** Function triggered when player chooses to examine the room.
** Prints description to screen.
*******************************************************************************/
void SkelRoom3::description()
{
	cout << endl;

	cout << "It is a normal stone-walled room with a few symbols carved in the stone." << endl;
	cout << "There is a passage to the south." << endl;

	if(crypt->getWaterFlag() == false)
	{
		cout << "There is a shallow trench to the north." << endl;
		cout << "There is a grate in the left of the trench and a gate to the right." << endl;
	}

	else if(crypt->getWaterFlag() == true)
	{
		cout << "The northern trench is full of water." << endl;
		cout << "The gate to the east is open." << endl;
	}


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
void SkelRoom3::interact()
{
	cout << endl;

	if(skeleFlag == true)
	{
		if(counter >= 5)
		{
			cout << "Okay, that is probably enough teeth." << endl;
			cout << "I mean, there are more (somehow), but having so many in your pockets" << endl;
			cout << "is starting to make a weird odor. Not bad, just weird..." << endl;
		}

		else if(counter > 0 && counter < 5)
		{
			cout << "You poke around some more and find another gold tooth." << endl;
			cout << "How many did it have?" << endl;

			//add tooth to inventory
			player->addItem(3);

			counter++;
		}

		else if(counter == 0)
		{
			cout << "You poke around the pile of bones, and find a cool gold tooth." << endl;

			//add tooth to inventory
			player->addItem(3);

			counter++;
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
Space* SkelRoom3::move(int inMov)
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

				cout << "There is no exit this way" << endl;

				cout << endl;

				return NULL;
			}

			else if(inMov == 2)
			{
				if(crypt->getWaterFlag() == false)
				{
					cout << endl;

					cout << "There is a gate this way, but it is closed" << endl;

					cout << endl;

					return NULL;
				}

				else if(crypt->getWaterFlag() == true)
				{
					cout << endl;

					cout << "You exit through the gate to the east" << endl;

					cout << endl;

					player->damage();

					return east;
				}
			}

			else if(inMov == 3)
			{
				cout << endl;

				cout << "You exit to the south" << endl;

				cout << endl;

				player->damage();

				return south;
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

				cout << "There is no exit this way" << endl;

				cout << endl;

				return NULL;
			}

			else if(inMov == 2)
			{
				if(crypt->getWaterFlag() == false)
				{
					cout << endl;

					cout << "There is a gate this way, but it is closed" << endl;

					cout << endl;

					return NULL;
				}

				else if(crypt->getWaterFlag() == true)
				{
					cout << endl;

					cout << "You exit through the gate to the east" << endl;

					cout << endl;

					player->damage();

					return east;
				}
			}

			else if(inMov == 3)
			{
				cout << endl;

				cout << "You exit to the south" << endl;

				cout << endl;

				player->damage();

				return south;
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