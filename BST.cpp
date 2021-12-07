#include "BST.h"
#include "Morse.h"
#include <iostream>
using namespace std; 


//This following function is the public insert function. 
bool BST::insert(char Val, int input_data) {	//Takes in a character value and a position value

	Node* temp = new Node(Val, input_data);		//Inserts this data into a new Node

	if (root == nullptr) {						//If root is null, make the incoming data the root node.
		root = temp;							
		root->left = nullptr;	
		root->right = nullptr;
		//The below lines of code can be uncommented if you want to see what the root node contains
//		cout << "Inserted Root: " << root->data << endl;
//		cout << "Inserted Root Char: " << root->morseChar << endl;
		return true;
	}


	if (input_data < (root->data)) {					//If the INTEGER incoming/input data is less than the root's stored integer data, look left.
		return insert(root->left, Val, input_data);
	}
	if (input_data > (root->data)) {					//If the integer incoming/input data is greather than the root's stored integer data, look right 
		return insert(root->right, Val, input_data);
	}

}

//This function is the private insert function called in the public insert function.
bool BST::insert(Node*& node, char Val, int inputdata) {		

	if (node == nullptr) {								//If the node is null, we will insert the char and position into the node.
		node = new Node(Val, inputdata);
		node->left = nullptr;
		node->right = nullptr;
		//The below lines of code can be uncommented if you want to see what the inserted node contains
//		cout << "Inserted Node: " << node->data << endl;
//		cout << "Inserted Node Char: " << node->morseChar << endl;  
		return true;
	}

	//If the node is not null, the following functions recursively go until it finds a null value.
	if (inputdata < (node->data)) {						
		return insert(node->left, Val, inputdata);
	}
	if (inputdata > (node->data)) {
		return insert(node->right, Val, inputdata);
	}

	return false;

}


//The public remove function is called when the user command is clear.
bool BST::remove() {
	if (root == nullptr) return false;		//If the tree has already been cleared, it returns false.

	bool value = remove(root);				//Sends the root node to the private remove function.

	root = nullptr;							//Finally sets the root pointer to null
	return true; 
}

//This is the private remove function.
bool BST::remove(Node*& node) {
	
	if (node->left != nullptr) remove(node->left);		//follows left until it hits a nullptr
	if (node->right != nullptr) remove(node->right);	//follows right until it hits a nullptr

	delete node;		//deletes node
	return false; 
}

//This is the public search function. 
bool BST::search(int _data) {		//Takes in a integer value (aka the rowElement in the array) 

	bool retrieval = search(root, _data);	//Recursively passes it to the private search function

	if (retrieval == false)
		return false; 

	if (retrieval == true)
		return true; 

}

//This is the private search function
bool BST::search(Node* &node, int inputdata) {
	if (node == nullptr) return false;		//Starting at the root, if the node is null, return false

	if (node->data == inputdata) return true;	//If the integer data inside the incoming node (starts at root) is the same as the input data, then return true.

	if (inputdata > node->data) {			//If the position is greater than the incoming node, output a dash, and recursively call the node's right pointer  until the input data matches.
		cout << "-"; 
		return search(node->right, inputdata);
	}

	if (inputdata < node->data) {			//If the position is less than the incoming node, output a dot, and recursively call the node's left pointer until the input data matches.
		cout << ".";
		return search(node->left, inputdata);
	}

	return false; 
}

//This is the public function that traverses the BST to match the character (from the convertString function)
void BST::traversal(char cdata) {
	
	traversal(root, cdata);

}

//This is the private function that traverses the BST to match the character (from the convertString function) 
void BST::traversal(Node* node, char cdata) {  

	if (node == nullptr) return;	//If node is empty, return false

	if (node->morseChar == cdata) {		//if the input character matches the node's Char, it calls the search function find the data and to output the morse dots and dashes
		search(node->data);	
		cout << " ";					//This adds a space after each letter because the morse translator that I was using required a space after each letter. Can be removed if you want a morse sequence without a space.
	}

	traversal(node->left, cdata);		//Recursively traverses left or right until the character is found or find a nullptr
	traversal(node->right, cdata);
}


//Public inOrder traversal function
void BST::inOrder() {
	inOrder(root);
}

//Private inOrder traversal function per class slides
void BST::inOrder(Node* node) {
	if (node == nullptr) return;
	inOrder(node->left);
	cout << node->data << " ";
	inOrder(node->right);
}

//Public preOrder traversal function
void BST::preOrder() {
	preOrder(root);
}

//private preOrder traversal function
void BST::preOrder(Node* node) {
	if (node == nullptr) return;
	cout << node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}

//Public postOrder traversal function
void BST::postOrder() {
	postOrder(root);
}

//private postOrder traversal function
void BST::postOrder(Node* node) {
	if (node == nullptr) return;
	postOrder(node->left);
	postOrder(node->right);
	cout << node->data << " ";
}

//This function construct the tree per the constructTree guidelines
int BST::constructTree(int depth) {		//intakes an integer to determine the depth of the tree

	int arrCount = 0;		//This uses the aforementioned algorithm -- given in project guidelines

	for (int rowCount = 0; rowCount <= depth; rowCount++)
	{
		int rowElementCount = pow(2, rowCount);

		int rowElement = pow(2, (depth - rowCount));

		int rowElementCounter = pow(2, (depth - rowCount + 1));

		for (int j = 0; j < rowElementCount; j++, rowElement += rowElementCounter)
		{
			insert(MorseTree[arrCount], rowElement);		//This adds the node information based on the MorseTree character, and the rowElement
			arrCount++;
		}

	}

	return depth; 
}
