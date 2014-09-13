/*
	Andre Allan Ponce
	a_ponce1@u.pacific.edu
	Item class, for all the items
*/
#ifndef _ITEM_H_INCLUDED_
#define _ITEM_H_INCLUDED

#include <string>

class Item{
protected:
	std::string name;

public:
	Item();

	virtual void action() = 0;

	std::string getItemName();

	void setItemName(std::string n);
};


#endif
