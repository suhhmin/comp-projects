/*
	Andre Allan Ponce
	a_ponce1@u.pacific.edu
	Item class, for the player's items
*/

#include <string>
#include "item.h"
#include "playeritem.h"

// @author Andre Allan Ponce
PlayerItem::PlayerItem() : Item(), id(-1){
	// empty
}

// @author Andre Allan Ponce
PlayerItem::PlayerItem(std::string n, int idNumber) : Item(n), id(idNumber){
	// empty
}

// @author Andre Allan Ponce
int PlayerItem::getID(){
	return id;
}

// @author Andre Allan Ponce
void PlayerItem::setID(int idNumber){
	id = idNumber;
}