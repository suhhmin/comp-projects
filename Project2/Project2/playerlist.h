/*
	Andre Allan Ponce
	a_ponce1@u.pacific.edu
	static class wrapper for an array of Player
*/
#include <string>

using namespace std;

class PlayerList{
private:
	static int numberOfPlayers; // should never go above 20, unless we start using vectors 
	static string fileName; // this isn't like global variables, right?
	static Player players[];

public:
	static void init(); // customary for me to create init(iation) methods for static classes

	static void addPlayer(Player pl);
	static int findPlayer(string name);

	static string getFileName();
	static int getNumberOfPlayers();

	static void modifyPlayer(int loc, int newAge);		// for either option, yo
	static void modifyPlayer(int loc, string newName);	// since I try to keep all I/O in main (or in a File wrapper class)
	static void printPlayers();							// this is an exception to my I/O rule though, since Player must have a void print method

	static void setFileName(string name);
};