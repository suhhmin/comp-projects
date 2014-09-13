/*
	Andre Allan Ponce
	a_ponce1@u.pacific.edu
	Player class
*/

#include <string>
//#include <sstream> // converting ints to strings takes some work
#include "player.h"


// @author Andre Allan Ponce
Player::Player() : name("debug"){
	// constructors should be empty, yo
}

// @author Andre Allan Ponce
Player::Player(std::string n) : name(n){
	// constructors should be empty, yo
}

// @author Andre Allan Ponce
std::string Player::getName(){
	return name;
}

// @author Andre Allan Ponce
std::string Player::print(){
	return "Name: "+name+"\n";
		//"Age: "+temp.str()+"\n";
}

// @author Andre Allan Ponce
void Player::setName(std::string n){
	name = n;
}