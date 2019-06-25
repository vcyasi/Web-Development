/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The class declaration for the Inventory class.
**               Has pointers to head and tail nodes.
**               Uses ItemNodes.
**               Is rather stripped down from most linked-lists, as no items need
**               to be removed from inventory in dungeon, so those functions not needed.
**               Has functions to add new nodes to head and to print inventory.
************************************************************************************/ 

#ifndef INVENTORY_H
#define INVENTORY_H


#include "ItemNode.hpp"

#include <string>

using std::string;

class Inventory
{
private:
	//points to beginning of list (first node)
	ItemNode *head;
	//points to end of list (last node)
	ItemNode *tail;


public:
	/**********************
	** Constructors
	**********************/
	//default
	Inventory();

	/**************************
	** Get and Set Functions
	**************************/
	ItemNode* getHead();
	ItemNode* getTail();

	void setHead(ItemNode *inHead);
	void setTail(ItemNode *inTail);


	/****************************************************************************
	** Function to add a node to the head of the list.
	** Sets temp to address pointed to by head (current head Node of list) to
	** store it, uses head to create new Node with passed value, sets next ptr of
	** new Node to temp (thus pointing to now second Node in list), sets prev ptr
	** of second Node (via head) to new Node, sets prev ptr of new Node to nullptr,
	** and sets temp to nullptr to reset it.
	** Takes in string for item of new node.
	****************************************************************************/
	void addNodetoHead(string inItem);

	/***************************************************************************************************
	** Function to print all values stored in Nodes from head to tail, in a similar fashion to
	** the tail-to-head function.
	** Prints val stored in Node pointed to by Head, then val stored in Node pointed to by next ptr,
	** and so on until it reaches a nullptr, which is the tail Node.
	** Uses a recursive function, with nullptr as base case.
	** This function is only called as part of adding or deleting Nodes.
	** Takes in a pointer to the Node to be printed.
	*****************************************************************************************************/
	void forwardPrint(ItemNode *inPtr);

	/********************************************************************
	** Deconstructor
	** Deallocates any Nodes left when object ends
	*******************************************************************/
	~Inventory();
};

#endif