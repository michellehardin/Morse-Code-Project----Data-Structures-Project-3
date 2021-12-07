#pragma once

#include "Node.h"

using namespace std; 


class BST {
public:
	Node* root;
	bool insert(char Val, int _data);
	bool remove();
	bool search(int _data);
	int constructTree(int _data); 
	void traversal(char data); 
	void inOrder();
	void preOrder();
	void postOrder();

	BST() {
		root = nullptr;
	};

	~BST() {};


private:
	
	bool insert(Node* &node, char Val, int _data);
	bool remove(Node* &node);
	bool search(Node*& node, int _data);
	void traversal(Node* node, char data);
	void inOrder(Node* node);
	void preOrder(Node* node);
	void postOrder(Node* node);
};
