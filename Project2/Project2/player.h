/*
	Andre Allan Ponce
	a_ponce1@u.pacific.edu
	Header for Player class
*/


#include <string>

using namespace std;

class Player{
private:
	string name;
	int age;
	bool validPlayer; // invalid players will have "debug" name and negative age. these players 'don't exist' until replaced with 'real' Player. (ArrayLists (or vectors, in this case) could solve this)

public:
	Player();
	Player(string n, int a);

	int getAge();
	string getName();

	bool isValid();

	void print();
	void reset(); // 'deletes' this player by setting name to "debug", age to -1, and validPlayer to false

	void setAge(int a);
	void setName(string n);
	void setValid();
};