/*
	Andre Allan Ponce
	a_ponce1@u.pacific.edu
	Header for Player class
*/
#ifndef _PLAYER_H_INCLUDED_
#define _PLAYER_H_INCLUDED_

#include <string>

using namespace std;

class Player{
private:
	string name;
	static const int INVENTORY_MAX;

public:
	Player();
	Player(string n, int a);

	int getAge();
	string getName();

	string print(); // return string, so we dont have include iostream everywhere

	void setAge(int a);
	void setName(string n);
};

#endif