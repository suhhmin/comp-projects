/*
	Andre Allan Ponce
	a_ponce1@u.pacific.edu
	PlayerList class (wrapper for Player array)
*/


#include <string>
#include <sstream>
#include "player.h"
#include "playerlist.h"

using namespace std;

// @author Andre Allan Ponce
PlayerList::PlayerList() : numberOfPlayers(0), fileName(""), players(NULL){
	// constructors should be empty, yo
}

// @author Andre Allan Ponce
PlayerList::PlayerList(int playerCount, string fName) : numberOfPlayers(playerCount), fileName(fName), players(new Player[playerCount]){
	// constructors should be empty, yo
}

// @author Andre Allan Ponce
void PlayerList::addPlayer(Player *pl){
	players[numberOfPlayers++] = *pl;
}

// @author Andre Allan Ponce
void PlayerList::createArray(int size){
	players = new Player[size];
}

// @author Andre Allan Ponce
void PlayerList::deleteArray(){
	if(numberOfPlayers > 0){
		// cout << "zeroing test";
		delete [] players; // delete the list iff there is stuff in it
	}
}

// @author Andre Allan Ponce
bool PlayerList::doesFileExist(){
	if(fileName == ""){
		return false;
	}
	return true;
}

// @author Andre Allan Ponce
int PlayerList::findPlayer(string name){
	for(int i = 0; i < numberOfPlayers; i++){
		if(players[i].getName() == name){
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

// Steve Suh
Player* PlayerList::getPlayer(int num)
{
	return &players[num];
}

// @author Andre Allan Ponce
string PlayerList::printPlayers(){
	string thePlayers = "Printing:\n\n";
	for(int i = 0; i < numberOfPlayers; i++){
		thePlayers += players[i].print() +"\n";
	}
	return thePlayers;
}

// @author Andre Allan Ponce
void PlayerList::setFileName(string name){
	fileName = name;
}