#include <string>
#include <stack>
#include "Player.h"

using namespace std;

class enemy: public Player{
private:
	string enemyName;
	int enemyMaxHP;
	int	enemyHP;
	int enemyDMG;
	int enemyLevel;
	int bounty;

public:
	enemy();
	enemy(string, int, int, int, int);
	void setEnemyName(string);
	void setEnemyMaxHP(int);
	void setEnemyHP(int);
	void setEnemyDMG(int);
	void setLvl(int);
	void setBounty(int);
	string getEnemyName();
	int getEnemyMaxHP();
	int getEnemyDMG();
	int getEnemyHP();
	int getLvl();
	int getBounty();
	void modifyEnemyHP(int);
	void modifyEnemyDMG(int);
	void printEnemy();
	friend void operator << (ostream&, const enemy&);
	void operator << (stack<enemy>&);

};