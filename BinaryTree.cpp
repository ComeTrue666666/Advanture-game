#include "BinaryTree.h"
#include <iostream>
#include <iomanip>

using namespace std;


BinaryTree::BinaryTree() {
	current = NULL;
	head = NULL;
}

BinaryTree::BinaryTree(Node* node) {
	current = head = node;
}

void BinaryTree::addLeftChild(Node* node) {
	if (head == NULL) {
		current = head = node;		
	}

	else {
		if (current->getLeft() != NULL) {
			moveToLeft();
			/*current->setLeft(node);
			current->getLeft()->setPrev(current);
			current = node->getPrev();
			cout << "AL Current: " << current->getData() << endl;*/
			//cout << "The left Node is full. Need to move to the left first." << endl << endl;
		}

		current->setLeft(node);
		node->setPrev(current);
		/*if (current->getData() == head->getData()) {
			node->setPrev(head);
			head->setLeft(node);
		}*/
		current = node->getPrev();
	//	cout << "AL Current: " << current->getData() << endl;
	}

}

void BinaryTree::addRightChild(Node* node) {
	if (head == NULL) {
		current = head = node;
	}

	else {
		if (current->getRight() != NULL) {
			moveToRight();
			/*current->setRight(node);
			current->getRight()->setPrev(current);
			current = node->getPrev();
			cout << "AL Current: " << current->getData() << endl;*/
		}

		current->setRight(node);
		node->setPrev(current);
		/*if (current->getData() == head->getData()) {
			node->setPrev(head);
			head->setLeft(node);
		}*/
		current = node->getPrev();
		//cout << "AR Current: " << current->getData() << endl;
	}
}

void BinaryTree::print() {
	if (current == NULL) {
		cout << "There is no data stored in the child." << endl << endl;
	}

	else
	cout << "Player Name: " << current->getData().getName() << setw(30) << "Score: " << current->getData().getScore() << endl;
}

void BinaryTree::moveBackward() {
	if (current->getPrev() == NULL) {
		cout << "Cannot move backward because there is no previous child" << endl << endl;
	}
	else 
		current = current->getPrev();
	//cout << "B: Data in the Current Node: " << current->getData() << endl;
}

void BinaryTree::moveToLeft() {
	if (current->getLeft() == NULL) {
		cout << "Cannot move to left because the left child is empty" << endl << endl;
	}

	else
		current = current->getLeft();
	//cout << "L: Data in the Current Node: " << current->getData() << endl;
}

void BinaryTree::moveToRight() {
	if (current->getRight() == NULL) {
		cout << "Cannot move to right because the right child is empty" << endl << endl;
	}

	else
		current = current->getRight();
//	cout << "R: Data in the Current Node: " << current->getData() << endl;
}

Node* BinaryTree::getHead() {
	return head;
}

void BinaryTree::loadTree() {
	Node* n;
	char command = ' ';
	addLeftChild(new Node("Stony Brook University"));
	//cout << "Head: " << head->getData() << endl;
	//cout << "Current: " << current->getData() << endl;
	addLeftChild(new Node("College of Arts and Sciences"));
	addRightChild(new Node("College of Engineering and Applied Sciences"));
	//moveToLeft();
	addLeftChild(new Node("BUS"));
	//moveToLeft();
	addLeftChild(new Node("BUS115"));
	moveBackward();
	moveBackward();
	moveToRight();
	addLeftChild(new Node("AMS"));
	addRightChild(new Node("ESE"));
	moveToRight();
	addLeftChild(new Node("ESE224"));
	addRightChild(new Node("ESE271"));
	//moveToRight();
	//addRightChild(new Node("ESE272"));
	//moveBackward();
	moveBackward();
	moveBackward();

	cout << "Successfully loading!" << endl << endl;	
}//loadTree


void BinaryTree::printAllPreOrder(Node* node) {
	if (node == NULL)
		return;
	cout << node->getData() << endl;
	printAllPreOrder(node->getLeft());
	printAllPreOrder(node->getRight());

}


void BinaryTree::printAllInOrder(Node* node) {
	if (node == NULL)
		return;

	printAllInOrder(node->getLeft());
	cout << node->getData() << endl;
	printAllInOrder(node->getRight());
}

void BinaryTree::printAllPostOrder(Node* node) {
	if (node == NULL)
		return;

	printAllPostOrder(node->getLeft());
	printAllPostOrder(node->getRight());
	cout << node->getData() << endl;
}

