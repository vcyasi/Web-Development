/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the Item Node class.
**               Is only get/set functions
**               for the name of the item it stores.
**               Used with Inventory linked-list class and Tomb of Ancients program.
************************************************************************************/ 

#include "ItemNode.hpp"

#include <string>

using std::string;

/**********************
** Constructors
**********************/
//default
ItemNode::ItemNode()
{
	next = NULL;
	prev = NULL;

	item = "BLANK ITEM";
}

//if name passed in
ItemNode::ItemNode(string inItem)
{
	next = NULL;
	prev = NULL;
	
	item = inItem;
}

/***************************
** Get and Set Functions
***************************/
ItemNode* ItemNode::getPrev()
{
	return prev;
}

ItemNode* ItemNode::getNext()
{
	return next;
}

string ItemNode::getItem()
{
	return item;
}

void ItemNode::setPrev(ItemNode *inPrev)
{
	prev = inPrev;
}

void ItemNode::setNext(ItemNode *inNext)
{
	next = inNext;
}

void ItemNode::setItem(string inItem)
{
	item = inItem;
}