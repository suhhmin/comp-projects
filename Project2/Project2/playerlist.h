
#include <string>
#include "player.h"
using namespace std;

class PlayerList{
private:
	int numberOfPlayers; // should never go above 19, unless we start using vectors
	string fileName;
	Player players[];

public:
	PlayerList();

	void addPlayer(Player pl);
	int findPlayer(string name);
	void modifyPlayer(int loc, int newAge);
	void modifyPlayer(int loc, string newName);
	void printPlayers();
};