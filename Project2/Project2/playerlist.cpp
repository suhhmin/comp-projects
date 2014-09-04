
#include <string>
#include <iostream>
#include "playerlist.h"
#include "player.h"


using namespace std;

PlayerList::PlayerList(){
	Player players[20];
	numberOfPlayers = 0;
}

void PlayerList::addPlayer(Player pl){
	players[numberOfPlayers++] = pl;
}

int PlayerList::findPlayer(string name){
	for(int i = 0; i < numberOfPlayers; i++){
		if(players[i].isValid() && players[i].getName() == name){
			return i;
		}
	}
	return -1;
}

void PlayerList::modifyPlayer(int loc, int newAge){
	players[loc].setAge(newAge);
}

void PlayerList::modifyPlayer(int loc, string newName){
	players[loc].setName(newName);
}

void PlayerList::printPlayers(){
	cout << "Printing:\n";
	for(int i = 0; i < numberOfPlayers; i++){
		if(players[i].isValid()){
			players[i].print();
			cout << "\n";
		}
	}
}