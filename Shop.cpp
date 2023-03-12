#include "Shop.h"
#include <iostream>
#include <iomanip>

ShopNode::ShopNode() {
	prev = NULL;
	next = NULL;
}

ShopNode::ShopNode(weapon w) {
	//Weapon.setWName(name);
	//Weapon.setDamage(damage);
	//Weapon.setUses(use);
	//Weapon.setCosts(cost);
	this->Weapon = w;
}

void ShopNode::setNext(ShopNode* nxt) {
	this->next = nxt;
}

void ShopNode::setPrev(ShopNode* prv) {
	this->prev = prv;
}

ShopNode* ShopNode::getNext() {
	return next;
}

ShopNode* ShopNode::getPrev() {
	return prev;
}

string ShopNode::getWN() {
	return Weapon.getWName();
}

weapon ShopNode::getWeapon() {
	return Weapon;
}

void ShopNode::print() {
	cout << setw(20) << left << Weapon.getWName() << setw(20) << left << Weapon.getDamage() << setw(20) << left << Weapon.getCosts() << endl;
	}


Shop::Shop() {
	head = NULL;
	tail = NULL;
}

void Shop::addWeapon(ShopNode* node) {
	if (head == NULL) {
		head = tail = node;
	}

	else {
		tail->setNext(node);
		node->setPrev(tail);
		tail = node;
	
	}//addWeapon to the Shop
}

void Shop::removeWeapon(weapon w) {
	ShopNode* s;
	ShopNode* temp;
	s = head;
	bool remove_flag = false;
	while (s != NULL) {
		if (s->getWN() == w.getWName()) {
			remove_flag = true;
			if (s == head) {
				head = s->getNext();
				s->getNext()->setPrev(NULL);
			}
			else if (s == tail) {
				tail = s->getPrev();
				s->getPrev()->setNext(NULL);
			}
			else {
				s->getPrev()->setNext(s->getNext());
				s->getNext()->setPrev(s->getPrev());
			}
			break;
		}//if
		else {
			s = s->getNext();
			continue;
		}
	}//while
	if (remove_flag == false)
		cout << "The weapon is not found or the list is empty." << endl << endl;
	else
		cout << "Weapon is removed successfully!" << endl << endl;
}//removeWeapon

void Shop::printAll() {
	ShopNode* s;
	s = head;
	while (s != NULL) {
		s->print();
		s = s->getNext();
	}//while
}

void Shop::clearShop() {
	ShopNode* s;
	s = head;
	while (s != NULL) {
		s->setPrev(NULL);
		s->setNext(NULL);
		s = s->getNext();

	}
	head = NULL;
	tail = NULL;
}

weapon Shop::searchWeapon(string weaponName) {
	ShopNode* node;
	node = head;
	bool exit_flag = false;
	while (node != NULL) {
		if (node->getWN() == weaponName) {
			exit_flag = true;
			return node->getWeapon();
		}
		else
			node = node->getNext();
	}//while
	if (exit_flag == false)
		cout << "The weapon is not found" << endl << endl;
}

