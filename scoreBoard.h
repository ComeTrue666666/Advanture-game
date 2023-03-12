#include <string>

using namespace std;

class scoreBoard {

private:
	string SBName;
	int SBScore;
	string SBDifficulty;
	int difficultyMod;
	int SB_floor;

public:
	scoreBoard();
	scoreBoard(string, int);
	void setName(string);
	void setScore(int);
	void setDiff(string d);
	void setDiffMod(int);
	void setFloor(int);
	string getName();
	int getScore();
	string getDiff();
	int getDiffMod();
	int getFloor();
	void addScore(int);
	void SB_out();	
	//friend void operator << (ostream& os, const scoreBoard& p);
	bool operator < (const scoreBoard& s1);
	//bool operator() (const scoreBoard& player1, const scoreBoard& player2);
};