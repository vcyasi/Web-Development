/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the BoosRoom child class.
************************************************************************************/ 

#include "Space.hpp"
#include "BossRoom.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**********************
** Constructors
**********************/
//default
BossRoom::BossRoom()
{
	bossFlag = false;

	choice = 0;
}

//if player passed in
BossRoom::BossRoom(Player *inPtr)
{
	bossFlag = false;
	choice = 0;

	player = inPtr;
}

/******************************************************************************
** Function triggered when player chooses to examine the room.
** Prints description to screen.
*******************************************************************************/
void BossRoom::description()
{
	cout << endl;

	cout << "You see a large, ornately-carved room, which looks as if it once held a great purpose." << endl;
	cout << "Its luxury has since faded a bit, but is still in great condition." << endl;
	cout << "You see a great altar or shrine in the center, and gather this was once a holy site." << endl;

	if(bossFlag == false)
	{
		cout << "You see the being which stole your soul in the center of the room near the shrine." << endl;
		cout << "It eyes you menacingly, as if it knew you would come." << endl;
		cout << "The glowing mass it pulled from your chest swirls in its boney claw." << endl;
	}

	else if(bossFlag == true)
	{
		cout << "The whole room is eeriely calm..." << endl;
	}

	cout << "There is an exit to the south and to the north." << endl;

	if(bossFlag == false)
	{
		cout << "Though, you feel the being will not let you pass to the north..." << endl;
	}

	cout << endl;
}

/********************************************************************************
** Function triggered when player interacts with room.
** Interactions will often trigger flags that affect other functions.
*********************************************************************************/
void BossRoom::interact()
{
	cout << endl;

	if(bossFlag == true)
	{
		cout << "There seems naught else to do in the room." << endl;
	}

	else if(bossFlag == false)
	{
		cout << "With some hesitance, you walk up to the being in the center of the room." << endl;
		cout << "You both stare at each other, its burning eyes seeing deep within you." << endl;
		cout << "What do you do?:" << endl << endl;
		cout << "(1) Punch the being with all your fury" << endl;
		cout << "(2) Drop to your knees and beg forgiveness" << endl;
		cout << "(3) Use the boomerang" << endl;
		cout << "(4) Do a backflip" << endl;

		cin >> choice;

		cin.clear();
    	cin.ignore(256,'\n');

	    if(choice < 1 || choice > 4)
	    {
	    	cout << "You decide to go against the fates and choose somethinge else." << endl;
	    	cout << "The fates are not happy and give you one more chance:" << endl << endl;

	    	cout << "(1) Punch the being with all your fury" << endl;
			cout << "(2) Drop to your knees and beg forgiveness" << endl;
			cout << "(3) Use the boomerang" << endl;
			cout << "(4) Do a backflip" << endl;

			cin >> choice;
			cin.clear();
			cin.ignore(256, '\n');

			if(choice < 1 || choice > 4)
		    {
		    	cout << "The fates warned you..." << endl;

		    	player->setHP(0);
		    }
	    }

	    else if(choice == 1)
	    {
	    	cout << "You well up all your remaining strength and deliver a powerful punch at the being." << endl;
	    	cout << "Your fist connects with its bony chest, but the being seems unfazed." << endl;
	    	cout << "It is like punching a wall." << endl;
	    	cout << "The being raises its boney hand and effortlessly knocks you across the room." << endl;
	    	cout << "You hit the wall and lose five health." << endl;

	    	for(int i = 0; i < 5; i++)
	    	{
	    		player->damage();
	    	}
	    }

	    else if(choice == 2)
	    {
	    	cout << "You are a defeated person at this point, and the crypt has taken its toll." << endl;
	    	cout << "You drop to your knees before the being and beg for its forgiveness." << endl;
	    	cout << "You apologize for your thieving ways and vow to be a better person." << endl;
	    	cout << "The being seems unmoved." << endl;
	    	cout << "Its burning eyes continue to judge you unworthy." << endl;
	    }

	    else if(choice == 3)
	    {
	    	cout << "You reach down and take out the boomerang." << endl;
	    	cout << "It has gotten you out of one pickle so far." << endl;
	    	cout << "Maybe it will help again." << endl;
	    	cout << "You look the being dead in the eyes and hurl the boomerang with all your skill." << endl;
	    	cout << "It flies far to the left and totally misses the being." << endl;
	    	cout << "You lose your balance from the vigorous throw and fall backwards, hitting your head." << endl;
	    	cout << "You lose one health" << endl;
	    	cout << "You really do suck with that boomerang." << endl;

	    	player->damage();
	    }

	    else if(choice == 4)
	    {
	    	cout << "You are a bit crazed at this point, and all you can think of to do is a backflip for some reason." << endl;
	    	cout << "The being watches as you squat down, and spring back up, flinging yourself into the air." << endl;
	    	cout << "You pull off two complete backflips in midair, landing firmly back on your feet." << endl;
	    	cout << "With your fatigue from these crypts, you are amazed you could do that." << endl;
	    	cout << "The being is amazed too, and gives you a hearty applause." << endl;
	    	cout << "It tells you those were some sick moves, and says you can have your soul back." << endl;
	    	cout << "You are a cool bro after all." << endl;
	    	cout << "With that, it places the swirling mass back in your chest and the warmth of life returns." << endl;
	    	cout << "The being dissolves back into a mist, leaving only the gaze of its firey eyes behind, which" << endl;
	    	cout << "also soon disappear." << endl << endl;

	    	cout << "You are whole again!" << endl;

	    	bossFlag = true;
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
Space* BossRoom::move(int inMov)
{
	if(bossFlag == false)
	{
		cout << endl;

		cout << "The being will not let you pass." << endl;

		cout << endl;

		return NULL;
	}

	if(bossFlag == true)
	{
		if(inMov == 1)
		{
			cout << endl;

			cout << "You exit to the north" << endl;
			cout << "You see sunlight." << endl;

			cout << endl;

			return north;
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

			cout << "Why would you want to go back into the crypt?" << endl;

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