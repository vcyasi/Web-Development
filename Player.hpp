/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The class declaration for the Player class.
************************************************************************************/ 

#ifndef PLAYER_H
#define PLAYER_H

#include "Inventory.hpp"

class Player
{
private:
	//stores players HP
	//starts with 30
	//no actual cap to HP (besides int size)
	int HP;
	//future version can include a function to check/set HP cap
	//but user will (probably) not reach cap as only current method
	//to increase HP is 10 at a time

	//pointer to player's inventory
	Inventory *inventory;

	//flag that denotes boomerang has been recieved
	bool boomerangFlag;

	//a counter to keep track of how many items in inventory
	//could be put in Inventory itself, but is easier to store in Player,
	//as called only by Player
	int itemCount;

public:
	/**********************
	** Constructors
	**********************/
	//default
	Player();

	//if inventory passed in
	Player(Inventory *inInv);

	/***************************
	** Get and Set Functions
	***************************/
	int getHP();
	bool getBoomerangFlag();
	void setHP(int inHP);
	void setBoomerangFlag(bool inVal);

	/**********************************************
	** Function to add item to inventory.
	** Uses Inventory addNodetoHead().
	** Uses int to pass particular item name.
	** Called by Rooms to add items to inventory.
	***********************************************/
	void addItem(int inVal);

	/*******************************************************************
	** Function to damage player by one health.
	** Used whenever player changes rooms or
	** other strenous tasks.
	** Only damages by one because damage only ever taken one at time.
	** Future version can take in amount damaged.
	********************************************************************/
	void damage();

	/***************************************************
	** Function to heal player HP by certain amount.
	** Takes in int to heal.
	** Adds int to HP value.
	***************************************************/
	void heal(int inHeal);

	/**********************************************************
	** Function to calculate effectiveness of sneak attacks.
	** Generates a random number between 1 and 100.
	** On a 33 or better, sneak attack succeeds.
	** Returns a bool indicating attack succeeds (true)
	** or fails (false).
	** Used by Rooms to attack skeletons.
	**********************************************************/
	bool attack();

	/********************************************************
	** Function to print out items in inventory.
	** Calls Inventory.forwardPrint()
	********************************************************/
	void printInventory();

};

#endif