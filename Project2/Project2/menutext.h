
#include <string>

using namespace std;

class MenuText{
public:
	static const string INVALID_MENU_CHOICE;
	static const string MENU_ONE;
	static const string MENU_TWO;
	static const string PROMPT_FILE_NAME;
	static const string PROMPT_PLAYER_NAME;
private:
	static string fileName;
	static int playerCount;
};