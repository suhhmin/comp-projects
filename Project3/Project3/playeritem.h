/*
	Andre Allan Ponce
	a_ponce1@u.pacific.edu
	Item class, for the player's items
*/
#ifndef _PLAYERITEM_H_INCLUDED_
#define _PLAYERITEM_H_INCLUDED_
#include <string>

class PlayerItem{
private:
	std::string name;

public:
	PlayerItem();

	virtual void action() = 0;

	std::string getItemName();

	void setItemName(std::string n);
};
#endif