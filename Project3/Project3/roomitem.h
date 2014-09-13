/*
	Andre Allan Ponce
	a_ponce1@u.pacific.edu
	room items, like furniture and stuff.
*/
#ifndef _ROOMITEM_H_INCLUDED_
#define _ROOMITEM_H_INCLUDED_

#include <string>

class RoomItem{
private:
	std::string name;

public:
	RoomItem();

	virtual void action();


};
#endif