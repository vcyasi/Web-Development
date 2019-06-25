/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The class declaration for the Dungeon class.
************************************************************************************/ 

#ifndef DUNGEON_H
#define DUNGEON_H

#include "Space.hpp"
#include "Player.hpp"

class Dungeon
{
private:
	//pointer to current room
	//very important, as serves as basis for what happens when menu functions called
	Space *URHere;

	//pointer to player
	Player *player;

	//flag denoting if Player escaped crypt
	bool endingFlag;
	//flag denoting if water activated
	bool waterFlag;
	//flag denoting if sneak cloak obtained
	bool sneakFlag;

public:
	/**********************
	** Constructors
	**********************/
	//default
	Dungeon();

	//if pointer passed in
	Dungeon(Player *inPlay);

	/***************************
	** Get and Set Functions
	***************************/
	Space* getURHere();
	Player* getPlayer();
	bool getEndingFlag();
	bool getWaterFlag();
	bool getSneakFlag();
	void setURHere(Space *inPtr);
	void setPlayer(Player *inPtr);
	void setEndingFlag(bool inVal);
	void setWaterFlag(bool inVal);
	void setSneakFlag(bool inVal);

	/*******************************************************
	** Function to display opening story and set up scene.
	********************************************************/
	void openScene();

	/**************************************************************************
	** Function to handle submenu of Move.
	** Called by explore()
	** Asks user for which direction they want to move and validates input.
	** Passes int to Room move function.
	**************************************************************************/
	void moveMenu();

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
	void explore();

	/******************************************************************************************
	** Function to display ending screen.
	** Various parts activated/deactivated based on if ending reached by running out of HP,
	** or by exiting the crypyt.
	** Uses endingFlag and getHP() to check these conditions.
	*******************************************************************************************/
	void ending();
	

};

#endif