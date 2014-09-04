/*
	Andre Allan Ponce
	a_ponce1@u.pacific.edu
	Player class
*/

#include <string>
#include <iostream>
#include "player.h"

using namespace std;

// @author Andre Allan Ponce
Player::Player(){
	name = "debug";
	age = -1;
	validPlayer = false;
}

// @author Andre Allan Ponce
Player::Player(string n, int a){
	name = n;
	age = a;
	validPlayer = true;
}

// @author Andre Allan Ponce
int Player::getAge(){
	return age;
}

// @author Andre Allan Ponce
string Player::getName(){
	return name;
}

// @author Andre Allan Ponce
bool Player::isValid(){
	return validPlayer;
}

// @author Andre Allan Ponce
void Player::print(){
	cout << "Name: " << name << "\n";
	cout << "Age: " << age << "\n";
}

// @author Andre Allan Ponce
void Player::reset(){
	name = "debug";
	age = -1;
	validPlayer = false;
}

// @author Andre Allan Ponce
void Player::setAge(int a){
	age = a;
}

// @author Andre Allan Ponce
void Player::setName(string n){
	name = n;
}

// @author Andre Allan Ponce
void Player::setValid(){
	validPlayer = true;
}