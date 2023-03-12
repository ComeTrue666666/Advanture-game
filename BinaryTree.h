#include "Node.h"

class BinaryTree {
private:
	Node* current;
	Node* head;
	bool flag = true;
	int depth = 0;
	int maxD = 0;
public:
	BinaryTree();
	BinaryTree(Node* node);
	void addLeftChild(Node* node);
	void addRightChild(Node* node);
	void loadTree();
	void print();
	void moveBackward();
	void moveToLeft();
	void moveToRight();
	Node* getHead();
	void printAllPreOrder(Node* node);
	void printAllInOrder(Node* node);
	void printAllPostOrder(Node* node);
};