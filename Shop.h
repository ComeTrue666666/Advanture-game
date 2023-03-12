#include "weapon.h"
#include <iostream>
#include <string>

using namespace std;

class ShopNode {
private:
	weapon Weapon;
	ShopNode* prev;
	ShopNode* next;
public:
	ShopNode();
	ShopNode(weapon);
	void setNext(ShopNode* nxt);
	void setPrev(ShopNode* prv);
	ShopNode* getNext();
	ShopNode* getPrev();
	string getWN();
	weapon getWeapon();
	void print();
};


class Shop {

private:
	typedef ShopNode* ShopNodePtr;
	ShopNodePtr head, tail;
	bool flag = true;

public:
	Shop();
	void addWeapon(ShopNode*);
	void removeWeapon(weapon);
	void printAll();
	void clearShop();
	weapon searchWeapon(string);
};