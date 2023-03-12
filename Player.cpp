#include <iostream>
#include "Player.h"
#include <string>

using namespace std;

Player::Player() {
	playerName = "New Player";
	MaxHP = 50;
	HP = 50;
	attackDMG = 10;
	currency = 0;
}

void Player::setName(string name) {
	playerName = name;
}

void Player::setMaxHP(int health) {
	MaxHP = health;
}

void Player::setHP(int health) {
	HP = health;
}

void Player::setDMG(int damage) {
	attackDMG = damage;
}

void Player::setCurrency(int gold) {
	currency = gold;
}

string Player::getName() {
	return playerName;
}

int Player::getMaxHP() {
	return MaxHP;
}

int Player::getHP() {
	return HP;
}

int Player::getDMG() {
	return attackDMG;
}

int Player::getCurrency() {
	return currency;
}

void Player::modifyHP(int health) {
	HP = HP + health;
}

void Player::modifyDMG(int damage) {
	attackDMG = attackDMG + damage;
}

void Player::modifyCurrency(int gold) {
	currency = currency + gold;
}

void Player::print()
{
	cout << "Player name:  " << playerName << endl;
	cout << "Maximum HP:  " << MaxHP << endl;
	cout << "Current HP:  " << HP << endl;
	cout << "Attack damage:  " << attackDMG << endl;
	cout << "Currency:  " << currency << endl << endl;
}

void operator << (ostream& os, const Player& p) {
	os << p.playerName << endl;
	os << p.MaxHP << endl;
	os << p.HP << endl;
	os << p.attackDMG << endl;
	os << p.currency << endl;
}


