/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the Dungeon class.
************************************************************************************/ 

#include "Player.hpp"

#include "Space.hpp"
#include "Entrance.hpp"
#include "GuardianHall.hpp"
#include "Hallway1.hpp"
#include "Hallway2.hpp"
#include "SkelRoom1.hpp"
#include "SkelRoom2.hpp"
#include "SkelRoom3.hpp"
#include "RiddleRoom.hpp"
#include "BoomerangRoom.hpp"
#include "EggRoom.hpp"
#include "CloakRoom.hpp"
#include "Statue.hpp"
#include "SquidRoom.hpp"
#include "SwitchRoom.hpp"
#include "OldMan.hpp"
#include "BossRoom.hpp"
#include "Exit.hpp"

#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

/**********************
** Constructors
**********************/
//default
Dungeon::Dungeon()
{
	endingFlag = false;
	waterFlag = false;
	sneakFlag = false;
}

//if pointer passed in
Dungeon::Dungeon(Player *inPlay)
{
	endingFlag = false;
	waterFlag = false;
	sneakFlag = false;

	player = inPlay;
}

/***************************
** Get and Set Functions
***************************/
Space* Dungeon::getURHere()
{
	return URHere;
}

Player* Dungeon::getPlayer()
{
	return player;
}

bool Dungeon::getEndingFlag()
{
	return endingFlag;
}

bool Dungeon::getWaterFlag()
{
	return waterFlag;
}

bool Dungeon::getSneakFlag()
{
	return sneakFlag;
}

void Dungeon::setURHere(Space *inPtr)
{
	URHere = inPtr;
}

void Dungeon::setPlayer(Player *inPtr)
{
	player = inPtr;
}

void Dungeon::setEndingFlag(bool inVal)
{
	endingFlag = inVal;
}

void Dungeon::setWaterFlag(bool inVal)
{
	waterFlag = inVal;
}

void Dungeon::setSneakFlag(bool inVal)
{
	sneakFlag = inVal;
}

/*******************************************************
** Function to display opening story and set up scene.
********************************************************/
void Dungeon::openScene()
{
	cout << "[;P]-----------------------------------------------------------------------------------------[<3]" << endl;

	cout << endl;

	cout << "You open your eyes and rub dust off your face." << endl;
	cout << "Your body aches all over as the smell of mildew and earth fills your nose." << endl;
	cout << "You are a bit disoriented and try to recall what you were just doing..." << endl << endl;

	cout << "You remember you were running... and you think there was shouting..." << endl << endl;

	cout << "Oh yeah! The guards! That's right, you were running from the city guards." << endl;
	cout << "You check your pack, and feel a tinge of pain in your arm." << endl;
	cout << "Nothing you cannot handle." << endl;
	cout << "Rummaging around, you are glad to see it is still there." << endl;
	cout << "The trinket you stole." << endl;
	cout << "It was the auction house's fault they didn't guard it better." << endl;
	cout << "You still have your treasure, but where are you?" << endl << endl;

	cout << "You were running from the guards through the forest, and then what?" << endl;
	cout << "You think back on it a moment and remember your legs suddenly giving out." << endl;
	cout << "Wait, not your legs, the ground!" << endl;
	cout << "The ground collapsed and you must have fallen through the hole." << endl;
	cout << "You look up and see some sunlight shining in." << endl;
	cout << "The hole is mostly closed back up from the collapse, and it is too high up, anyway." << endl;
	cout << "You will have to find some other exit." << endl << endl;

	cout << "You get to your feet, a bit of an ache accompanying it." << endl;
	cout << "You did just fall a good ways, but luckily nothing seems to be broken." << endl;
	cout << "You look to be in a small earthern, natural room." << endl;
	cout << "There are some jars and such around, but not much else." << endl;

	cout << endl;

	cout << "[<3]-----------------------------------------------------------------------------------------[;P]" << endl;
}

/**************************************************************************
** Function to handle submenu of Move.
** Called by explore()
** Asks user for which direction they want to move and validates input.
** Passes int to Room move function.
**************************************************************************/
void Dungeon::moveMenu()
{
	int direction = 0;

	cout << endl;

	cout << "Which direction would you like to move?:" << endl << endl;

	cout << "        (1) North" << endl;
	cout << "(4) West          (2) East" << endl;
	cout << "        (3) South" << endl;

	cin >> direction;

	cin.clear();
	cin.ignore(256,'\n');

    while(direction < 1 || direction > 4)
    {
    	cout << "There are only four directions." << endl;
    	cout << "This is a 2D text-based crawler." << endl;
    	cout << "Not one of them fancy next-gen 3D platformers:" << endl << endl;

    	cout << "        (1) North" << endl;
		cout << "(4) West          (2) East" << endl;
		cout << "        (3) South" << endl;

		cin >> direction;
		cin.clear();
		cin.ignore(256, '\n');
    }

    cout << endl;

    //temporary holder pointer for returned
    Space *temp;

    temp = URHere->move(direction);

    //check temp is good
    if(temp == NULL)
    {
    	//is bad, so do not set to URHere
    	return;
    }
    //all good and URHere can be updated
    else
    {
    	URHere = temp;
    }
}

/***********************************************************************
** Function to run the actual game.
** Uses a while loop regulated by Player HP and endingFlag.
** Each cycle it displays a menu to user with various options:
** (Look Around) (Interact) (Move) (Check Inventory) (Check Health)
** Each option calls subfunctions to complete task.
** Look Around, Interact, and Move call specific versions of
** functions based on room URHere is pointing to.
** Move changes the room URHere points to.
************************************************************************/
void Dungeon::explore()
{
	//checks ending has not been reached and checks HP is still above 0
	while(endingFlag == false && player->getHP() > 0)
	{	
		//player's choice
		int menu = 0;

		cout << "[T^T]--------------------------------------------------------------------------------------[T^T]" << endl << endl;

		cout << "~~~Player Menu~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "  [1](Look Around)        [4](Inventory)" << endl;
		cout << "  [2](Interact)           [5](Check Health]" << endl;
		cout << "  [3](Move)" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		cin >> menu;

		cin.clear();
		cin.ignore(256,'\n');

	    while(menu < 1 || menu > 5)
	    {
	    	cout << "I'm afraid I cannot let you do that" << endl;

			cin >> menu;
			cin.clear();
			cin.ignore(256, '\n');
	    }
	    //looking around room
	    if(menu == 1)
	    {
	    	URHere->description();
	    }
	    //interacting with room thing(s)
	    else if(menu == 2)
	    {
	    	URHere->interact();
	    }
	    //move to new room
	    else if(menu == 3)
	    {
	    	moveMenu();
	    }
	    //check what is in inventory
	    else if(menu == 4)
	    {
	    	player->printInventory();
	    }
	    //check health
	    else if(menu == 5)
	    {
	    	cout << endl;

	    	cout << "You think you have about " << player->getHP() << " HP left" << endl;

	    	cout << endl;
	    }

	    cout << "[T^T]--------------------------------------------------------------------------------------[T^T]" << endl;
	}


}

/******************************************************************************************
** Function to display ending screen.
** Various parts activated/deactivated based on if ending reached by running out of HP,
** or by exiting the crypyt.
** Uses endingFlag and getHP() to check these conditions.
*******************************************************************************************/
void Dungeon::ending()
{
	if(player->getHP() <= 0)
	{
		cout << endl;

		cout << "[X]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[X]" << endl;
		cout << "         You feel the last of the life drain from your body." << endl;
		cout << "         Everything goes dark..." << endl;
		cout << "             YOU DIED" << endl;
		cout << "[X]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[X]" << endl;

		cout << endl;
	}

	else if(endingFlag == true)
	{
		cout << endl;

		cout << "[^_^]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[^_^]" << endl;
		cout << "         You escaped the crypt!" << endl;
		cout << "             CONGRATULATIONS" << endl;
		cout << "             A WINNER IS YOU" << endl;
		cout << "[^_^]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[^_^]" << endl;

		cout << endl;
	}

	cout << endl;

	cout << "ENDING CREDITS MUSIC" << endl << endl;

	cout << "~The Tomb of the Ancients~" << endl << endl;
	cout << "Coded by Vincent Yasi" << endl;
	cout << "In collaboration with Yasi Game Studios" << endl;
	cout << "Produced by 'A Dog I Gave A Ham Sandwich To'" << endl;
	cout << "In my defense, he was a smart dog." << endl;
	cout << "He is actually suing for merchandising rights from this game." << endl;
	cout << "Curse you, Sir Spottington, curse you!" << endl << endl << endl << endl;

	cout << "THE END" << endl;
	cout << "Or is it?" << endl << endl;

	cout << "It is. I finished the homework." << endl;
	cout << "I have Assembly to do now..." << endl << endl;
}