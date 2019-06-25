/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the Player class.
************************************************************************************/ 

#include "Player.hpp"

#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

#include <cstdlib>
#include <ctime>

/**********************
** Constructors
**********************/
//default
Player::Player()
{
	HP = 30;
	boomerangFlag = false;
	//starts at 1, as Player starts with "Stolen Trinket"
	itemCount = 1;
}

//if inventory passed in
Player::Player(Inventory *inInv)
{
	HP = 30;
	boomerangFlag = false;
	//starts at 1, as Player starts with "Stolen Trinket"
	itemCount = 1;

	inventory = inInv;
}

/***************************
** Get and Set Functions
***************************/
int Player::getHP()
{
	return HP;
}

bool Player::getBoomerangFlag()
{
	return boomerangFlag;
}

void Player::setHP(int inHP)
{
	HP = inHP;
}

void Player::setBoomerangFlag(bool inVal)
{
	boomerangFlag = inVal;
}

/**********************************************
** Function to add item to inventory.
** Uses Inventory addNodetoHead().
** Uses int to pass particular item name.
** Called by Rooms to add items to inventory.
***********************************************/
void Player::addItem(int inVal)
{
	//inventory limit of 10
	if(itemCount > 10)
	{
		cout << endl;

		cout << "INVENTORY FULL" << endl;
		cout << "Item Discarded" << endl;
		cout << "     (T^T)" << endl;

		cout << endl;
	}

	else
	{
		//add boomerang
		if(inVal == 1)
		{
			inventory->addNodetoHead("Boomerang");

			itemCount++;
		}
		//add sneak cloak
		else if(inVal == 2)
		{
			inventory->addNodetoHead("Sneak Cloak");

			itemCount++;
		}
		//add gold tooth
		else if(inVal == 3)
		{
			inventory->addNodetoHead("Gold Tooth");

			itemCount++;
		}
		//add Vegemite Sandwich
		else if(inVal == 4)
		{
			inventory->addNodetoHead("Vegemite Sandwich");

			itemCount++;
		}
	}
}

/*******************************************************************
** Function to damage player by one health.
** Used whenever player changes rooms or
** other strenous tasks.
** Only damages by one because damage only ever taken one at time.
** Future version can take in amount damaged.
********************************************************************/
void Player::damage()
{
	HP = HP - 1;
}

/***************************************************
** Function to heal player HP by certain amount.
** Takes in int to heal.
** Adds int to HP value.
***************************************************/
void Player::heal(int inHeal)
{
	HP = HP + inHeal;
}

/**********************************************************
** Function to calculate effectiveness of sneak attacks.
** Generates a random number between 1 and 100.
** Normally, on a 33 or better, sneak attack succeeds.
** Boomerang actually gives shadow boost of 25 or better.
** Returns a bool indicating attack succeeds (true)
** or fails (false).
** Used by Rooms to attack skeletons.
**********************************************************/
bool Player::attack()
{
	//attack strength
	int effective;

	//get random integer within range of 1 and 100
	effective = ((rand() % 100) + 1);

	if(boomerangFlag == false)
	{
		if(effective >= 33)
		{
			return true;
		}
		else if(effective < 33)
		{
			return false;
		}
	}

	else if(boomerangFlag == true)
	{
		if(effective >= 25)
		{
			return true;
		}
		else if(effective < 25)
		{
			return false;
		}
	}
}

/********************************************************
** Function to print out items in inventory.
** Calls Inventory.forwardPrint()
********************************************************/
void Player::printInventory()
{
	cout << "You check your pack." << endl;
	cout << "You seem to have:" << endl << endl;

	inventory->forwardPrint(inventory->getHead());

	cout << endl;
}