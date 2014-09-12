/*
	Andre Allan Ponce
	Steve Suh
	a_ponce1@u.pacific.edu
	h_suh@u.pacific.edu
	Project2 main. Should be interactive with TWO menus
*/


#include <string>
#include <fstream>
#include <iostream>
#include <locale>
#include <random>
#include "player.h"
#include "playerlist.h"
#include "menutext.h"

using namespace std;

int convertStringToNum(string num);  
int menuChoice(string displayText);
void menuOne();
void menuTwo(PlayerList* pList);
string promptName(string prompt);
bool readInFile(PlayerList* pList);

// these methods may be thrown out or modified extensively. do not use, yo
Player createNewPlayer(int loc);
int promptAge(int loc);
int promptChoice();
int promptIndex(int enteredPlayers);
string promptName(int loc);

int main(){
	
	// debug -------
	menuOne();

	// end debug -----
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

Player createNewPlayer(){
	Player *pl;
	pl->setName(promptName("Name: "));
	pl->setAge(promptAge("Age: "));
	return *pl;
}

Player createRandomPlayer()
{
	string playerNames[20] ={"Jason",
							"Jack",
							"John",
							"Joseph",
							"Job",

							"Jonathan",
							"James",
							"Jim",
							"Josh",
							"Jay",

							"Jose",
							"Johnson",
							"Jimmy",
							"Jake",
							"Jeff",

							"Jorge",
							"Joy",
							"JiaLingXu",
							"Jeremy",
							"Joshua"};

		random_device rd; //a random, large number like 32248906489
		Player *rdpl;
		int ranNum = rd()%20;	// a random number between 0~19
		rdpl->setName(playerNames[ranNum]);//setting the name randomly picked from an arbitrary list
		rdpl->setAge(10 + ranNum);//setting age randomly between 10~29
		cout<<"Generated a player."
			<<"\nName: " << playerNames[ranNum]
			<<"\nAge  : " << 10+ranNum;
		return *rdpl;
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
	while(true){
		int choice = menuChoice(MenuText::MENU_ONE);
		switch(choice){
		case 1 : { // New File
			PlayerList *pList = &PlayerList();
			menuTwo(pList);
			break;
		}
		case 2 : { // Open File
			PlayerList *pList = &PlayerList();
			if(readInFile(pList)){
				menuTwo(pList);
			}
			break;
		}
		case 3 : { // Exit
			exit(0);
			break;
		}
		default : { // Bad Menu choice
			cout << MenuText::INVALID_MENU_CHOICE;
			break;
		}
		}
	}
}

/*
	this is the second menu's interface
	@author Andre Allan Ponce
	Steve Suh
*/
void menuTwo(PlayerList* pList){
	bool isMenuTwo = true;
	while(isMenuTwo){
		int choice = menuChoice(MenuText::MENU_TWO);
		switch(choice){
		case 1 : { // Print all players
			cout << pList->printPlayers();
			break;
		}
		case 2 : { // Create a new player!
			pList->addPlayer(createNewPlayer()); 
			break;
		}
		case 3 : { // Generate a random player and add.
			pList->addPlayer(createRandomPlayer());  
			break;
		}
		case 4 : { // Modify a player's name/Age!
			pList->modifyPlayer(promptName("player name: ")); 
			break; 
		}
		case 5 : {

		}
		case 6 : { // Close File
			isMenuTwo = false;
			break;
		}
		default : { // bad menu choice
			cout << MenuText::INVALID_MENU_CHOICE;
			break;
		}
		}
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

	NOTES:
		- I swear, it seems that this block is rather lengthy and should be simplified, but I'm not sure how.

	@author Andre Allan Ponce
	@returns true if file was read perfectly, false if some error occured
*/
bool readInFile(PlayerList* pList){
	ifstream inFile;
	try{
		string fileName = promptName(MenuText::PROMPT_FILE_NAME);
		inFile.open(fileName.c_str()); // the book said to use cstrings for open() function
		if(!inFile.good()){ 
			throw MenuText::ERROR_FILE_NAME; // any starting I/O errors will be taken care of
		}
		// cout << "filenamecheckgood\n"; // debug
		string line;
		getline(inFile, line); 
		int playerNum = convertStringToNum(line);
		if(playerNum <= 0 || playerNum >= 20){ // 0 or less should be impossible; we are to assume that 20 is max players
			throw MenuText::ERROR_FILE_CONTENTS; // we can differientiate between I/O errors or bad file formatting
		}
		pList->createArray(playerNum);
		// cout << "filecontentsgood\n"; // debug
		while(!inFile.eof()){ // changed to eof because serious I/O errors should throw automatically
			getline(inFile, line);
			string name = line;
			getline(inFile, line);
			int age = convertStringToNum(line);
			pList->addPlayer(&Player(name, age)); // pointers, yo 
			// cout << "addingplayers\n"; // debug
		}
		pList->setFileName(fileName);
		return true;
	}
	catch(string text){
		cout << text; // will display custom error message text
	}
	catch(...){ // ... catches everything else, just in case
		cout << MenuText::ERROR_UNKNOWN; // we dont know what happened, yo
	}
	return false;
}
