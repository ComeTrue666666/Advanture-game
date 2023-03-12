#include "Node.h"

using namespace std;

Node::Node(scoreBoard d) {
	data = d;
}

Node* Node::getLeft() {
	return left;
}

Node* Node::getRight() {
	return right;
}

Node* Node::getPrev() {
	return prev;
}

scoreBoard Node::getData() {
	return data;
}

void Node::setLeft(Node* left) {
	this->left = left;
}

void Node::setRight(Node* right) {
	this->right = right;
}

void Node::setPrev(Node* prev) {
	this->prev = prev;
}
