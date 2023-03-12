#include <string>
#include <iostream>
#include "weapon.h"
#include <math.h>

using namespace std;



weapon::weapon() {
	weaponName = "Fist";
	Wdamage = 10;
	weaponUses = 1;
	weaponCost = 0;
}

weapon::weapon(string name, int DMG, int uses, int cost) {
	weaponName = name;
	Wdamage = DMG;
	weaponCost = cost;
	weaponUses = uses;
}

void weapon::setWName(string name) {
	weaponName = name;
}

void weapon::setDamage(int DMG) {
	Wdamage = DMG;
}

void weapon::setUses(int use) {
	weaponUses = use;
}

void weapon::setCosts(int cost) {
	weaponCost = cost;
}

string weapon::getWName() {
	return weaponName;
}

int weapon::getDamage() {
	return Wdamage;
}

int weapon::getUses() {
	return weaponUses;
}

int weapon::getCosts() {
	return weaponCost;
}