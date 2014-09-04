/*
	Andre Allan Ponce
	a_ponce1@u.pacific.edu
	PlayerList class (wrapper for Player array)
*/


#include <string>
#include <iostream>
#include "playerlist.h"
#include "player.h"

using namespace std;

// @author Andre Allan Ponce
void PlayerList::init(){
	numberOfPlayers = 0;
}

// @author Andre Allan Ponce
void PlayerList::addPlayer(Player pl){
	players[numberOfPlayers++] = pl;
}

// @author Andre Allan Ponce
int PlayerList::findPlayer(string name){
	for(int i = 0; i < numberOfPlayers; i++){
		if(players[i].isValid() && players[i].getName() == name){
			return i;
		}
	}
	return -1;
}

// @author Andre Allan Ponce
string PlayerList::getFileName(){
	return fileName;
}

// @author Andre Allan Ponce
int PlayerList::getNumberOfPlayers(){
	return numberOfPlayers;
}

// @author Andre Allan Ponce
void PlayerList::modifyPlayer(int loc, int newAge){
	players[loc].setAge(newAge);
}

// @author Andre Allan Ponce
void PlayerList::modifyPlayer(int loc, string newName){
	players[loc].setName(newName);
}

// @author Andre Allan Ponce
void PlayerList::printPlayers(){
	cout << "Printing:\n";
	for(int i = 0; i < numberOfPlayers; i++){
		if(players[i].isValid()){
			players[i].print();
			cout << "\n";
		}
	}
}

// @author Andre Allan Ponce
void PlayerList::setFileName(string name){
	fileName = name;
}