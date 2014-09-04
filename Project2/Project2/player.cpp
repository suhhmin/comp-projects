
#include <string>
#include <iostream>
#include "player.h"

using namespace std;

Player::Player(){
	name = "debug";
	age = -1;
	validPlayer = false;
}

Player::Player(string n, int a){
	name = n;
	age = a;
	validPlayer = true;
}

int Player::getAge(){
	return age;
}

string Player::getName(){
	return name;
}

bool Player::isValid(){
	return validPlayer;
}

void Player::print(){
	cout << "Name: " << name << "\n";
	cout << "Age: " << age << "\n";
}

void Player::reset(){
	name = "debug";
	age = -1;
	validPlayer = false;
}

void Player::setAge(int a){
	age = a;
}

void Player::setName(string n){
	name = n;
}

void Player::setValid(){
	validPlayer = true;
}