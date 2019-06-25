/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the RiddleRoom child class.
************************************************************************************/ 

#include "Space.hpp"
#include "RiddleRoom.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**********************
** Constructors
**********************/
//default
RiddleRoom::RiddleRoom()
{
	riddleFlag = false;
}

//if player passed in
RiddleRoom::RiddleRoom(Player *inPtr)
{
	riddleFlag = false;

	player = inPtr;
}


/******************************************************************************
** Function triggered when player chooses to examine the room.
** Prints description to screen.
*******************************************************************************/
void RiddleRoom::description()
{
	cout << endl;

	cout <<	"The room is covered all over with colorful murals depicting animals and landscape scenes." << endl;
	cout << "They are a bit odd, as they seem to display a number of strange places." << endl;
	cout << "There is a snow-covered plain with little black and white birds fighting clouds." << endl;
	cout << "There is a large floating eye shooting lazerbeams into an icecream cone." << endl;
	cout << "There is a large, hairy ape banging on some bongos and flying through the air in a jetpack." << endl;
	cout << "All very weird." << endl;

	if(riddleFlag == true)
	{
		cout << "The northern wall has slid away to reveal a passage to the north." << endl;
	}

	else if(riddleFlag == false)
	{
		cout << "On the northern wall there are three large buttons made of stone." << endl;
		cout << "Above each is a carving of a creature." << endl;
		cout << "There looks to be a pig, an emu, and an azu." << endl;
	}

	cout << "There is a passage to the west." << endl;

	cout << endl;
}

/********************************************************************************
** Function triggered when player interacts with room.
** Interactions will often trigger flags that affect other functions.
*********************************************************************************/
void RiddleRoom::interact()
{
	//player's choice
	int choice = 0;

	cout << endl;

	if(riddleFlag == true)
	{
		cout << "You search around where the wall slide away, but see no new secrets." << endl;
	}

	else if(riddleFlag == false)
	{
		cout << "You decide to examine the northern wall." << endl;
		cout << "It looks like you can press the buttons on the wall." << endl;
		cout << "Which do you press?:" << endl << endl;
		cout << "(1) PIG" << endl;
		cout << "(2) EMU" << endl;
		cout << "(3) AZU" << endl;

		cin >> choice;

		cin.clear();
    	cin.ignore(256,'\n');

	    while(choice < 1 || choice > 3)
	    {
	    	cout << "There are only three buttons:" << endl << endl;

	    	cout << "(1) PIG" << endl;
			cout << "(2) EMU" << endl;
			cout << "(3) AZU" << endl;

			cin >> choice;
			cin.clear();
			cin.ignore(256, '\n');
	    }

	    if(choice == 1)
	    {
	    	cout << "You press in the PIG button." << endl;
	    	cout << "You hear a click and the wall begins to rumble." << endl;
	    	cout << "As you take a step back, the wall slides away and reveals a new passage." << endl;

	    	riddleFlag = true;
	    }

	    else if(choice == 2)
	    {
	    	cout << "You press in the EMU button." << endl;
	    	cout << "It sticks in for a moment, but then pops back out." << endl;
	    	cout << "Nothing special seems to have happened." << endl;
	    }

	    else if(choice == 3)
	    {
	    	cout << "You press in the AZU button." << endl;
	    	cout << "It sticks in for a moment, but then pops back out." << endl;
	    	cout << "Nothing special seems to have happened." << endl;
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
Space* RiddleRoom::move(int inMov)
{
	if(inMov == 1)
	{
		
		if(riddleFlag == true)
		{
			cout << endl;

			cout << "You exit through the secret passage to the north" << endl;

			cout << endl;

			player->damage();

			return north;	
		}

		else if(riddleFlag == false)
		{
			cout << endl;

			cout << "There is no exit this way" << endl;

			cout << endl;

			return NULL;
		}
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

		cout << "There is no exit this way" << endl;

		cout << endl;

		return NULL;
	}

	else if(inMov == 4)
	{
		cout << endl;

		cout << "You exit to the west" << endl;

		cout << endl;

		player->damage();

		return west;		
	}

}
