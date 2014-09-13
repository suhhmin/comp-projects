/*
	Andre Allan Ponce
	a_ponce1@u.pacific.edu
	no longer static class wrapper for an array of Player
	Steve Suh
*/
class Player; // foward declaration: http://www.cplusplus.com/forum/articles/10627/#msg49679

using namespace std;

class PlayerList
{
private:
	int numberOfPlayers; // now it can go above 20
	string fileName; 
	Player *players;

public:
	PlayerList();
	PlayerList(int playerCount, string fName); // unused right now

	void addPlayer(Player *pl);
	void createArray(int size);
	void deleteArray();
	bool doesFileExist();
	int findPlayer(string name);

	string getFileName();
	int getNumberOfPlayers();
	Player* getPlayer(int num);

	string printPlayers(); // return string, so we dont have include iostream everywhere				

	void setFileName(string name);
};