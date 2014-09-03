
#include <string>
#include <iostream>
#include "player.h"

using namespace std;

Player::Player(){
	name = "debug";
	age = -1;
}

int Player::getAge(){
	return age;
}

string Player::getName(){
	return name;
}

void Player::print(){
	cout << "Name: " << name << "\n";
	cout << "Age: " << age << "\n";
}

void Player::setAge(int a){
	age = a;
}

void Player::setName(string n){
	name = n;
}