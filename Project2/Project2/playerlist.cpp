/*
	Andre Allan Ponce
	a_ponce1@u.pacific.edu
	PlayerList class (wrapper for Player array)
*/


#include <string>
#include <sstream>
#include <iostream>
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
PlayerList::~PlayerList(){
	if(numberOfPlayers > 0){
		delete [] players; // delete the list iff there is stuff in it
	}
}

// @author Andre Allan Ponce
void PlayerList::addPlayer(Player *pl){
	players[numberOfPlayers] = pl[0];
	numberOfPlayers++;
}

// @author Andre Allan Ponce
void PlayerList::createArray(int size){
	players = new Player[size];
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
Player PlayerList::getPlayer(int num)
{
	return players[num];
}


// @author Andre Allan Ponce
void PlayerList::modifyPlayer(int loc, int newAge){
	players[loc].setAge(newAge);
}

// @author Andre Allan Ponce
void PlayerList::modifyPlayer(int loc, string newName){
	players[loc].setName(newName);
}

// Steve Suh
void PlayerList::modifyPlayer(string playerName)
{

	if (findPlayer(playerName)!=-1)
	{
			int x= findPlayer(playerName);
			players[x].print();

			cout<< "Modify this player's name if necessary:";
			string newName;
			cin >> newName;
			players[x].setName(newName);

			cout<< "\nModify this player's age if necessary:";
			int newAge;
			cin >> newAge;
			players[x].setAge(newAge);

	}
	else
		cout << "Invalid player name";
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