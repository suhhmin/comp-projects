
#include <string>
#include <iostream>
#include <locale>
#include "player.h"

using namespace std;

string const MENU_ONE = "1) New File\n2) Open File\n3) Quit\n";
string const MENU_TWO = "1) Print all Players\n2) Create a new Player";

Player createNewPlayer(int loc);
void menuOne();
void menuTwo();
void modifyPlayer(Player pls[], int enteredPlayers, string name);
void printPlayers(Player pls[], int enteredPlayers);
int promptAge(int loc);
int promptChoice();
int promptIndex(int enteredPlayers);
string promptName();
string promptName(int loc);

int main(){
	/*Player players[NUMBER_OF_PLAYERS];
	int index = promptIndex();
	players[index] = createNewPlayer(index);
	modifyPlayer(players, promptName());
	printPlayers(players, NUMBER_OF_PLAYERS);*/
	return 0;
}

Player createNewPlayer(int loc){
	Player pl;
	pl.setName(promptName(loc));
	pl.setAge(promptAge(loc));
	return pl;
}

void modifyPlayer(Player pls[], int enteredPlayers, string name){
	for(int i = 0; i < enteredPlayers; i++){
		if(pls[i].getName() == name){
			// choice = 0 -> edit name
			// choice = 1 -> edit age
			int choice = promptChoice();
			if(choice == 0){
				pls[i].setName(promptName(i));
			}
			else if(choice == 1){
				pls[i].setAge(promptAge(i));
			}
			return;
		}
	}
	cout << "This player does not exist\n";
}

void printPlayers(Player pls[], int enteredPlayers){
	cout << "Printing:\n";
	for(int i = 0; i < enteredPlayers; i++){
		pls[i].print();
		cout << "\n";
	}
}

int promptAge(int loc){
	cout << "Enter player " << loc << "'s age: ";
	int age;
	cin >> age;
	return age;
}

/*
	prompt user for choice
	@return 0 if editing name, 1 if editing age
*/
int promptChoice(){
	bool invalid;
	do{
		cout << "Which value to edit? (N/a): ";
		char input;
		cin >> input;
		input = toupper(input);
		if(input == 'N'){
			return 0;
		}
		else if(input == 'A'){
			return 1;
		}
		else{
			invalid = true;
			cout << "Input invalid, type 'N' for Name, 'a' for age.\n";
		}
	}while(invalid);
	return -1; // we shouldnt be going here
}

int promptIndex(int enteredPlayers){
	int index;
	bool invalid;
	do{
		cout << "Choose an index to create a player [0," << enteredPlayers-1 << "]: ";
		cin >> index;
		if(index < 0 || index >= enteredPlayers){
			invalid = true;
			cout << "Invalid index, try again.\n";
		}
		else{
			invalid = false;
		}
	}while(invalid);
	return index;
}

string promptName(){
	cout << "Enter a player's name: ";
	string name;
	cin >> name;
	return name;
}

string promptName(int loc){
	cout << "Enter player " << loc << "'s name: ";
	string name;
	cin >> name;
	return name;
}
