/*
	Andre Allan Ponce
	Steve (last name)
	a_ponce1@u.pacific.edu
	s_(lastname)(#)@u.pacific.edu
	Project2 main. Should be interactive with TWO menus
*/


#include <string>
#include <fstream>
#include <iostream>
#include <locale>
#include "player.h"
#include "playerlist.h"
#include "menutext.h"

using namespace std;

int convertStringToNum(string num);  
int menuChoice(string displayText);
void menuOne();
void menuTwo();
string promptName(string prompt);
void readInFile();

// these methods may be thrown out or modified extensively. do not use, yo
Player createNewPlayer(int loc);
int promptAge(int loc);
int promptChoice();
int promptIndex(int enteredPlayers);
string promptName(int loc);

int main(){
	PlayerList::init();
	/*Player players[NUMBER_OF_PLAYERS];
	int index = promptIndex();
	players[index] = createNewPlayer(index); // this was for lab2, yo
	modifyPlayer(players, promptName());
	printPlayers(players, NUMBER_OF_PLAYERS);*/
	return 0;
}

/*
	converts a string to an int
	@author Andre Allan Ponce
	@param num - the string to convert
	@returns the number as an int (NOTE, if NaN is before num, returns 0. if num is before NaN, returns num before NaN)
*/
int convertStringToNum(string num){
	int playerNum = atoi(num.c_str()); // so much easier to type than Integer.parseInt(String)
	return playerNum;
}

Player createNewPlayer(int loc){
	Player pl;
	pl.setName(promptName(loc));
	pl.setAge(promptAge(loc));
	return pl;
}

/*
	feed it menu text, it will prompt for option
	@author Andre Allan Ponce
	@param displayText - the text to display (should be one of the MenuText MENUs)
	@returns the choice the user made, which should be an int.
*/
int menuChoice(string displayText){
	cout << displayText << "Select option: ";
	string choice; 
	cin >> choice;
	return convertStringToNum(choice); // by doing this, we can say invalid input is 0! (if user puts in NaN...)
}

/*
	this is the first menu's interface
	@author Andre Allan Ponce
*/
void menuOne(){
	bool invalid = false; // assume the worst
	int choice;
	do{
		choice = menuChoice(MenuText::MENU_ONE);
		if(choice < 1 || choice > 3){
			invalid = true;
			cout << MenuText::INVALID_MENU_CHOICE;
		}
	}while(invalid);
	switch(choice){
	case 1 : menuTwo(); break;
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

/*
	Because we can prompt for filename or playername
	@author Andre Allan Ponce
	@param prompt - the prompt text
	@returns the response from user
*/
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

/*
	Reads in file by prompting user for filename, opening file, 
	getting the firstline (which should be number of players) and 
	reading until file ends or we have reached number of players
	@author Andre Allan Ponce
*/
void readInFile(){
	ifstream inFile;
	try{
		string fileName = promptName(MenuText::PROMPT_FILE_NAME);
		inFile.open(fileName.c_str()); // the book said to use cstrings for open() function
		string line;
		getline(inFile, line); 
		int playerNum = convertStringToNum(line);
		if(playerNum <= 0 || playerNum >= 20){ // 0 or less should be impossible; we are to assume that 20 is max players
			throw invalid_argument("First line of file is NaN"); // we can differientiate between I/O errors or bad file formatting
		}
		while(inFile.good()){ // good checks for eof, bad I/O or any other error with I/O
			getline(inFile, line);
			string name = line;
			getline(inFile, line);
			int age = convertStringToNum(line);
			Player pl(name, age); 
			PlayerList::addPlayer(pl); // can we put Player(name, age) in here instead of creating pl? 
		}
	}
	catch(invalid_argument& e){
		cout << MenuText::ERROR_FILE_CONTENTS << e.what() << "\n"; // first line is NaN
	}
	catch(ios_base::failure& e){
		cout << MenuText::ERROR_FILE_NAME; // I/O errors (like file no exist)
	}
}
