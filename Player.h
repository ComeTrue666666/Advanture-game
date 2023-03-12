#pragma once
#include <string>

using namespace std;

class Player {

private:
	string playerName;
	int MaxHP;
	int HP;
	int attackDMG;
	int currency;

public:
	Player();
	void setName (string name);
	void setMaxHP (int health);
	void setHP (int health);
	void setDMG (int damage);
	void setCurrency (int gold);
	string getName ();
	int getMaxHP ();
	int getHP();
	int getDMG();
	int getCurrency();
	void modifyHP(int health);
	void modifyDMG(int damage);
	void modifyCurrency(int gold);
	void print();
	friend void operator << (ostream& os, const Player& p);

};