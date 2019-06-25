/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  The member functions for the Inventory class.
**               Is rather stripped down from most linked-lists, as no items need
**               to be removed from inventory in dungeon, so those functions not needed.
**               Has functions to add new nodes to head and to print inventory.
************************************************************************************/ 

/************************************************************************
** Is a rather simple inventory system, and I would like to make a more
** robust one in the future. This one only stores the name of the item.
** I would like one that stores descriptions and has more interaction
** with the rest of the game, but this project didn't really call for
** a more complicated system, so I kept it simpler and focused on
** other parts of project.
************************************************************************/

#include "Inventory.hpp"

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
//player always starts with a Stolen Trinket item
Inventory::Inventory()
{
	head = new ItemNode("Stolen Trinket");

	tail = head;
}

/**************************
** Get and Set Functions
**************************/
ItemNode* Inventory::getHead()
{
	return head;
}

ItemNode* Inventory::getTail()
{
	return tail;
}

void Inventory::setHead(ItemNode *inHead)
{
	head = inHead;
}

void Inventory::setTail(ItemNode *inTail)
{
	tail = inTail;
}


/****************************************************************************
** Function to add a node to the head of the list.
** Sets temp to address pointed to by head (current head Node of list) to
** store it, uses head to create new Node with passed value, sets next ptr of
** new Node to temp (thus pointing to now second Node in list), sets prev ptr
** of second Node (via head) to new Node, sets prev ptr of new Node to nullptr,
** and sets temp to nullptr to reset it.
** Takes in string for item of new node.
****************************************************************************/
void Inventory::addNodetoHead(string inItem)
{
	//make temporary pointer
	ItemNode *temp;

	//save head pointing to temp
	temp = head;

	//make new Node and add to head of list
	head = new ItemNode(inItem);

	//set prev ptr of new Node to second Node
	head->setPrev(temp);

	//check temp is not pointing to nullptr
	//if is, second node is nullptr and does not need to be set to first node
	if(temp)
	{
		//set next ptr of second Node to first Node
		temp->setNext(head);
	}

	//set next ptr of new head Node to nullptr
	head->setNext(NULL);

	//check if tail is pointing to nullptr (list was empty)
	//if so, point it to the new Node
	if(!tail)
	{
		tail = head;
	}
}

/***************************************************************************************************
** Function to print all values stored in Nodes from head to tail, in a similar fashion to
** the tail-to-head function.
** Prints val stored in Node pointed to by Head, then val stored in Node pointed to by next ptr,
** and so on until it reaches a nullptr, which is the tail Node.
** Uses a recursive function, with nullptr as base case.
** This function is only called as part of adding or deleting Nodes.
** Takes in a pointer to the Node to be printed.
*****************************************************************************************************/
void Inventory::forwardPrint(ItemNode *inPtr)
{
	//create print pointer
	ItemNode *print;

	print = inPtr;

	//base case
	if(print == NULL)
	{
		cout << endl << endl;
	}

	else
	{
		cout << print->getItem() << "  ";
		//call function again, with next Node in list passed in
		forwardPrint(print->getPrev());
	}
}

/********************************************************************
** Deconstructor
** Deallocates any Nodes left when object ends
*******************************************************************/
Inventory::~Inventory()
{
	ItemNode *temp;

	if(head)
	{
		do{
			temp = head->getPrev();
			delete head;
			head = temp;

		} 
		while(temp);
	}
}
