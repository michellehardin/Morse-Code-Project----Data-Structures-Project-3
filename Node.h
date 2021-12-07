#pragma once

class Node {
private:

public:
	int data;
	char morseChar;
	Node* left;
	Node* right; 

	Node(char cdata, int idata) : morseChar(cdata), data(idata), left(nullptr), right(nullptr) {}
	Node(char ch, int iVal, Node* left, Node* right): morseChar(ch), data(iVal), left(left), right(right) {}
};