/*
	Andre Allan Ponce
	a_ponce1@u.pacific.edu
	From what I've learned from FRC coding, Game modding, and general Ease of access, 
	putting all (or most) constant text output in one class (or file) allows for easier 
	later modifications of programs. (though in practice, it's better to use Enums 
	for constants and put all string text in plain text file to be read and parsed on start up.)
	-> this block of text is for you, Steve. 
*/

#include <string>
#include "menutext.h"

/* 
	Error for menu choice 
	@author Andre Allan Ponce
*/
const string INVALID_MENU_CHOICE = "Invalid choice.\n";

/* 
	Menu Text 
	@author Andre Allan Ponce
*/
const string MENU_ONE = "\
						1) New File\n\
						2) Open File\n\
						3) Quit\n";
const string MENU_TWO = "\
						1) Print all Players\n\
						2) Create a new Player\n\
						3) Randomly generate a new Player\n\
						4) Modify a Player\n\
						5) Save Player list\n\
						6) Close File\n";

/* 
	Prompt text
	@author Andre Allan Ponce
*/
const string PROMPT_FILE_NAME = "Enter a filename: ";
const string PROMPT_PLAYER_NAME = "Enter a player's name: ";

/* 
	Error Messages
	@author Andre Allan Ponce
*/
const string ERROR_FILE_NAME = "Cannot read file\n";
const string ERROR_FILE_CONTENTS = "File corrupted\n";