
#include <string>
#include <iostream>
#include <locale>
#include "player.h"
#include "menutext.h"

using namespace std;

Player createNewPlayer(int loc);
int menuChoice(string displayText);
void menuOne();
void menuTwo();

int promptAge(int loc);
int promptChoice();
int promptIndex(int enteredPlayers);
string promptName(string prompt);
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

int menuChoice(string displayText){
	cout << displayText << "Select option: ";
	int choice;
	cin >> choice;
	return choice;
}

void menuOne(){
	bool invalid = false;
	int choice;
	do{
		choice = menuChoice(MenuText::MENU_ONE);
		if(choice < 1 || choice > 3){
			invalid = true;
			cout << MenuText::INVALID_MENU_CHOICE;
		}
	}while(invalid);
	switch(choice){
	case 1 : menuTwo();
	case 2 : 
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

string promptName(string prompt){
	cout << prompt;
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
