#include <iostream>
#include "Enemy.h"
#include <string>
#include <iomanip>

using namespace std;

enemy::enemy() {
	enemyName = "Goblin 1";
	enemyMaxHP = 5;
	enemyHP = 5;
	enemyDMG = 2;
	enemyLevel = 1;
	bounty = 5;
}

enemy::enemy(string name, int maxHP, int damage, int level, int Bounty) {
	enemyName = name;
	enemyMaxHP = maxHP;
	enemyHP = maxHP;
	enemyDMG = damage;
	enemyLevel = level;
	bounty = Bounty;
}

void enemy::setEnemyName(string name) {
	enemyName = name;
}

void enemy::setEnemyMaxHP(int HP) {
	enemyMaxHP = HP;
}

void enemy::setEnemyHP(int HP) {
	enemyHP = HP;
}

void enemy::setEnemyDMG(int damage) {
	enemyDMG = damage;
}

void enemy::setLvl(int lvl) {
	enemyLevel = lvl;
}

void enemy::setBounty(int value) {
	bounty = value;
}

string enemy::getEnemyName() {
	return enemyName;
}

int enemy::getEnemyMaxHP() {
	return enemyMaxHP;
}

int enemy::getEnemyDMG() {
	return enemyDMG;
}

int enemy::getEnemyHP() {
	return enemyHP;
}

int enemy::getLvl() {
	return enemyLevel;
}

void enemy::modifyEnemyHP(int HP) {
	enemyHP += HP;
}

void enemy::modifyEnemyDMG(int damage) {
	enemyDMG += damage;
}

int enemy::getBounty() {
	return bounty;
}

void enemy::printEnemy() {
	cout << "Enemy name:  " << enemyName << endl;
	cout << "Enemy Maximum HP:  " << enemyMaxHP << endl;
	cout << "Current HP:  " << enemyHP << endl;
	cout << "Enemy Attack damage:  " << enemyDMG << endl;
	cout << "Bounty:  " << bounty << endl << endl;
}


void operator <<(ostream& os, const enemy& e) {
	os << e.enemyName << endl;
	os << e.enemyMaxHP << endl;
	os << e.enemyHP << endl;
	os << e.enemyDMG << endl;
	os << e.enemyLevel << endl;
	os << e.bounty << endl;
}

void enemy::operator << (stack<enemy>& defeated) {
	stack<enemy> temp;
	temp = defeated;
	while (!temp.empty()) {
		cout << setw(20) << left << temp.top().getEnemyName() << left << setw(20) << temp.top().getLvl() << endl;
		temp.pop();
	}
}