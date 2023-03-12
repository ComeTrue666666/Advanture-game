#include <string>
#include "Player.h"
#include "scoreBoard.h"
#include "weapon.h"
#include <fstream>
#include <vector>

using namespace std;


class fileOperation {
private:
	string SB_file_name = "scoreboard.txt";
	//holds the name of the scoreboard file
	fstream SBFile;
	//opens the scoreboard file
	string P_file_name;
	//holds the name of the player file
	fstream PFile;
	//opens the player file


public:

	void Save2File(Player&);
	//Function Saves player progress into a file
	void Save2File(scoreBoard&);
	//Function Saves scoreboard progress into a file
	void ChooseFile(scoreBoard&, Player&);
	//Function that asks the user to select the file to use
	void CloseFile();
	//Function to close the files
	void ScoreRank();
	//Function to output scores from all the scoreboards


};