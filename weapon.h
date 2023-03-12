#pragma once
#include <string>

using namespace std;

class weapon {

private:
	string weaponName;
	int Wdamage;
	int weaponUses;
	int weaponCost;

public:
	weapon();
	weapon(string, int, int, int);
	void setWName(string);
	void setDamage(int);
	void setUses(int);
	void setCosts(int);
	string getWName();
	int getDamage();
	int getUses();
	int getCosts();

};