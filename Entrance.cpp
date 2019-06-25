/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the Entrance child class.
************************************************************************************/ 

#include "Space.hpp"
#include "Entrance.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**********************
** Constructors
**********************/
//default
Entrance::Entrance()
{
	/***********************************
	** Nothing to initialize
	** Pointers set after construction
	***********************************/
}

//if player passed
Entrance::Entrance(Player *inPtr)
{
	player = inPtr;
}

/******************************************************************************
** Function triggered when player chooses to examine the room.
** Prints description to screen.
*******************************************************************************/
void Entrance::description()
{
	cout << endl;

	cout << "The room has natural, unworked walls made of dirt and stone." << endl;
	cout << "It looks as if the room was carved from the earth." << endl;
	cout << "Looking around, you see an assortment of earthen jars, old and some broken." << endl;
	cout << "Looking up, you see the hole you fell through, but it is too high to leave through there." << endl;
	cout << "To the north, you see a passage to another room." << endl;

	cout << endl;
}

/********************************************************************************
** Function triggered when player interacts with room.
** Interactions will often trigger flags that affect other functions.
*********************************************************************************/
void Entrance::interact()
{
	cout << endl;

	cout << "You check the few intact jars, but most are empty or contain long rotted mystery items." << endl;

	cout << endl;
}

/********************************************************************************
** Function to move player to adjacent rooms.
** Takes in 1, 2, 3, or 4 to denote which direction player wants to move.
** (1 - North, 2 - East, 3 - East, 4 - West)
** Function called by Dungeon class.
** Returns pointer to new player location.
*********************************************************************************/
Space* Entrance::move(int inMov)
{
	if(inMov == 1)
	{
		cout << endl;

		cout << "You leave through the north." << endl;
		cout << "As you near the next room, you hear a rumbling above you." << endl;
		cout << "You roll forward into the next room just as the passage collapses behind you." << endl;
		cout << "As the dust settles, you see you are in a much larger well-crafted stone room."  << endl;
		cout << "Before you can take in the full room, a swirling mass of multicolored smoke condenses before you." << endl;
		cout << "From the smoke emerges a floating, skeletal being, dressed in tattered black robes." << endl;
		cout << "You are fixated on the bright, blue, piercing points of light burning in the not-quite human eye sockets" << endl;
		cout << "of its not-quite human skull as the being silently glides toward you." << endl << endl;
		cout << "'Trespasser in the sacred crypt'" << endl;
		cout << "    'Judgement now shall be wrought'" << endl;
		cout << "         'Judge the soul'" << endl;
		cout << "     'Due rewards to the man'" << endl << endl;
		cout << "The being then shoves a boney hand into your chest, and you can feel a coldness radiate from the impact." << endl;
		cout << "After a few moments, the eyes of the being turn from blue to darkest black." << endl;
		cout << "'Unworthy'" << endl;
		cout << "At this word, the being violently pulls out its hand, and you can see a glowing mass leave with the hand, as you feel" << endl;
		cout << "a sudden emptiness in your chest." << endl;
		cout << "The being clenches its hand shut and the glow disappears, as you grab at your chest, trying in vain to do something to" << endl;
		cout << "fill the emptiness left behind." << endl;
		cout << "The being turns from you and flies away out the northern passage of the room." << endl;
		cout << "You are powerless to stop it as the emptiness spreads through your body." << endl;
		cout << "The room around you grows darker and darker as you lose conciousness." << endl << endl;
		cout << "You wake up some time later (you know not how long it has been), the emptiness still present in your body." << endl;
		cout << "With all your strength, you get back to your feet." << endl;
		cout << "Whatever that being did, you must fix it.  You can feel the strength drain from your body." << endl;
		cout << "You do not know how long you can go on as you are." << endl;
		cout << "Perhaps this is karma for the thieving life you have led?" << endl;
		cout << "You feel each time you move to a new room or do certain things, you will lose health." << endl;
		cout << "Better find a way out quickly..." << endl;

		cout << endl;

		return north;
	}

	if(inMov == 2 || inMov == 3 || inMov == 4)
	{
		cout << endl;

		cout << "There is no exit in this direction" << endl;

		cout << endl;

		return NULL;
	}
}