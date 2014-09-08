/*
	Andre Allan Ponce
	a_ponce1@u.pacific.edu
	PlayerList class (wrapper for Player array)
*/


#include <string>
#include <iostream>
#include "player.h"
#include "playerlist.h"

using namespace std;

// static variables have to be initialized
// these are private, so they not global
// @author Andre Allan Ponce
int PlayerList::numberOfPlayers = 0;
string PlayerList::fileName = "";
Player PlayerList::players[20];

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
	cout << "Printing:\n\n";
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