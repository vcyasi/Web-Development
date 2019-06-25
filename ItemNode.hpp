/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The class declaration for the Item Node class.
**               Contains pointers to node before after after it, and get/set functions
**               for the name of the item it stores.
**               Used with Inventory linked-list class and Tomb of Ancients program.
************************************************************************************/ 

#ifndef ITEMNODE_H
#define ITEMNODE_H

#include <string>

using std::string;

class ItemNode
{
private:
	//pointers to Node before and after this one
	ItemNode *prev;
	ItemNode *next;

	//value stored in node
	string item;

public:
	/**********************
	** Constructors
	**********************/
	//default
	ItemNode();

	//if name passed in
	ItemNode(string inItem);

	/***************************
	** Get and Set Functions
	***************************/
	ItemNode* getPrev();
	ItemNode* getNext();
	string getItem();

	void setPrev(ItemNode *inPrev);
	void setNext(ItemNode *inNext);
	void setItem(string inItem);


};

#endif