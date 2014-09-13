/*
	Andre Allan Ponce
	a_ponce1@u.pacific.edu
	Header for Player class
*/
#ifndef _PLAYER_H_INCLUDED_
#define _PLAYER_H_INCLUDED_

class Player{
private:
	std::string name;
	static const int INVENTORY_MAX;

public:
	Player();
	Player(std::string n);

	std::string getName();

	std::string print(); // return string, so we dont have include iostream everywhere

	void setName(std::string n);
};

#endif