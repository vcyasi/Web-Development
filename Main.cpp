/************************************************************************************
** Author:       Vincent Yasi 
** Date:         5-28-2019 
** Description:  Main function for the Final Project.
**               Mostly creates needed objects, knits all rooms together, and then hands off
**               control to Dungeon functions.
**
**               If included makefile used, creates executable "Crypt"
************************************************************************************/ 

#include "Player.hpp"
#include "Dungeon.hpp"
#include "Inventory.hpp"

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

#include <cstdlib>
#include <ctime>


int main()
{
	//set random seed using Unix time
	srand(time(0));

	//create Inventory
	Inventory PlayerInv;
	//create pointer to Inventory
	Inventory *invPtr = &PlayerInv;

	//create Player (passing in invPtr)
	Player You(invPtr);
	//create pointer to Player
	Player *player = &You;

	//create Dungeon
	Dungeon Crypt(player);

	//create pointer to Dungeon
	Dungeon *tomb = &Crypt;

/*********************************************************************************************************************/

	/***************************************************************
	** The next section is a bit messy.
	** I create each room object, and then
	** I knit all of thier connecting pointers together.
	** I wanted to use a subfunction or something, but
	** I ran into scope issues.
	** This was easiest.
	** Luckily, I just need to pass one pointer (to the entrance)
	** to the Dungeon at end.
	***************************************************************/
	Entrance entrance(player);
	GuardianHall guardhall(player, tomb);
	Hallway1 hall1(player);
	Hallway2 hall2(player);
	SkelRoom1 skeleton1(player, tomb);
	SkelRoom2 skeleton2(player, tomb);
	SkelRoom3 skeleton3(player, tomb);
	RiddleRoom riddle(player);
	BoomerangRoom boomRoom(player);
	EasterEggRoom egg(player);
	CloakRoom cloak(player, tomb);
	StatueRoom healer(player);
	SquidRoom squid(player);
	SwitchRoom waterSwitch(player, tomb);
	OldMan oldie(player);
	BossRoom boss(player);
	Exit exitOut(player, tomb);

	//create pointers to easily connect rooms
	//simple names make work below easier with copy/paste
	Entrance *ptr1 =  &entrance;
	GuardianHall *ptr2 =  &guardhall;
	Hallway1 *ptr3 =  &hall1;
	Hallway2 *ptr4 =  &hall2;
	SkelRoom1 *ptr5 =  &skeleton1;
	SkelRoom2 *ptr6 =  &skeleton2;
	SkelRoom3 *ptr7 =  &skeleton3;
	RiddleRoom *ptr8 =  &riddle;
	BoomerangRoom *ptr9 =  &boomRoom;
	EasterEggRoom *ptrA =  &egg;
	CloakRoom *ptrB =  &cloak;
	StatueRoom *ptrC =  &healer;
	SquidRoom *ptrD =  &squid;
	SwitchRoom *ptrE =  &waterSwitch;
	OldMan *ptrF =  &oldie;
	BossRoom *ptrG =  &boss;
	Exit *ptrH =  &exitOut;

	//pass pointers to correct locations
	entrance.setNorth(ptr2);

	guardhall.setNorth(ptrG);
	guardhall.setEast(ptr3);
	guardhall.setWest(ptr6);

	hall1.setNorth(ptr7);
	hall1.setSouth(ptr5);
	hall1.setWest(ptr2);

	hall2.setNorth(ptrE);
	hall2.setEast(ptrD);
	hall2.setWest(ptrF);

	skeleton1.setNorth(ptr3);
	skeleton1.setEast(ptr8);

	skeleton2.setNorth(ptrD);
	skeleton2.setEast(ptr2);
	skeleton2.setWest(ptrC);

	skeleton3.setEast(ptrB);
	skeleton3.setSouth(ptr3);

	riddle.setNorth(ptr9);
	riddle.setWest(ptr5);

	boomRoom.setNorth(ptrA);
	boomRoom.setSouth(ptr8);

	egg.setSouth(ptr9);

	cloak.setWest(ptr7);

	healer.setEast(ptr6);

	squid.setSouth(ptr6);
	squid.setWest(ptr4);

	waterSwitch.setSouth(ptr4);

	oldie.setEast(ptr4);

	boss.setSouth(ptr2);
	boss.setNorth(ptrH);

	exitOut.setSouth(ptrG);

	//pointer to the first room
	Space *start = &entrance;

/*********************************************************************************************************************/

	//set Dungeon start to entrance
	Crypt.setURHere(start);

	//display opening story
	Crypt.openScene();

	//run actual game
	//goes in constant loop until HP = 0 or exit reached
	Crypt.explore();

	//the ending scene
	//depends on if HP = 0 or not
	Crypt.ending();

	return 0;
}

/**********************************************************************
** Function to connect rooms together, and reduce clutter of main().
**********************************************************************/

void connect()
{
}