#include <iostream>
using namespace std;
#include "scoreBoard.h"

class Node {
private:
	scoreBoard data;
	Node* left;
	Node* right;
	Node* prev;
public:
	Node(scoreBoard d);
	Node* getLeft();
	Node* getRight();
	Node* getPrev();
	scoreBoard getData();
	void setLeft(Node* left);
	void setRight(Node* right);
	void setPrev(Node* prev);
};