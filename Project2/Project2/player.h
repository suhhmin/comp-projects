
#include <string>

using namespace std;

class Player{
private:
	string name;
	int age;
	bool validPlayer;

public:
	Player();
	Player(string n, int a);

	int getAge();
	string getName();

	bool isValid();

	void print();
	void reset();

	void setAge(int a);
	void setName(string n);
	void setValid();
};