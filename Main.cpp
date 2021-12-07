/*
Student Name: Michelle Hardin
Student NetID: amh800
Compiler Used: Visual Studio
Program Description:
This program takes user input and converts it to Morse code.
*/

#include "BST.h"
#include "Tokenizer.h"
#include <iostream>
#include <fstream>

using namespace std; 

bool processFile(istream& is, bool interactive = true)
{
	string line;
	string command;
	string arg1;
	int depth;
	Tokenizer tkn; 
	BST test; 
	cout.precision(2);

	while (true)
	{
		if (!interactive)
		{
			if (is.eof())
				return true;
		}
		else
		{
			cout << "Enter Command >> ";
		}

		//gets line from input stream
		getline(is, line);
		tkn.setString(line);

		//first word in stream should always be a command
		tkn.readWord(command);

		//Below we start checking if the command is recognized

		if (command == "exit")
		{
			cout << "Exiting ...." << endl;
			return false;
		}

		if (command == "load")
		{
			// load expects a filename .. so read one more word
			if (!tkn.readWord(arg1))
			{
				cout << "Missing file name" << endl;
				continue; // skip back to the top of the read loop
			}

			//Attempts to read input file
			ifstream fin;
			bool status = true;
			fin.open(arg1);
			if (fin.is_open())
			{
				status = processFile(fin, false);
			}
			else
			{
				cout << "Failed to open the file" << endl;
			}
			fin.close();
			if (!status)
				return false;
		}

		//This function construct the binary search tree by taking in an integer for the depth
		if (command == "constructTree")
		{
			if (tkn.readInteger(depth)) {
				test.constructTree(depth);
			}
		}

		//This converts the input string into the morse value
		if (command == "convert")
		{
			if (tkn.readLine(line)) {	
				char CVal;

				//This function seperates the string and evaluates each character
				for (int i = 0; i < line.length(); i++) {
					CVal = line.at(i);
					if (islower(CVal)) {		//This function makes any lowercase in the input string capital so that it can properly convert it to morse (per the MorseTree array)
						CVal = CVal - 32; 
					}
					test.traversal(CVal); 
				}

			}
			cout << endl; 

		}

		//If the user wants to see the BST's inOrderTraversal
		if (command == "inOrderTraversal")
		{
			test.inOrder(); 
			cout << endl; 
		}

		//If the user wants to see the BST's preOrderTraversal
		if (command == "preOrderTraversal")
		{
			test.preOrder(); 
			cout << endl; 
		}

		//If the user wants to see the BST's postOrderTraversal
		if (command == "postOrderTraversal")
		{
			test.postOrder(); 
			cout << endl; 
		}

		//This function clears the constructed BST tree 
		if (command == "clear")
		{
			test.remove(); 
		}



		//This ensures that the command input is valid. 
		if (command != "constructTree" && command != "convert" && command != "inOrderTraversal" && command != "preOrderTraversal" && command != "postOrderTraversal" && command != "clear" && command != "load" && command != "exit")
			cout << "Invalid Input" << endl;
	}

};



int main()
{
	cout << "Welcome. The following commands are supported: " << endl;

	cout << "load <filename>.txt" << endl;
	cout << "constructTree <int>" << endl;
	cout << "inOrderTraversal" << endl;
	cout << "preOrderTraversal" << endl;
	cout << "postOrderTraversal" << endl;
	cout << "convert <String>" << endl;
	cout << "clear" << endl;
	cout << "exit" << endl;

	processFile(cin);

};

/*

BST test;

	int a = 15;
	int b = 10;
	int c = 9;
	int d = 30;
	int e = 12;
	int f = 27;
	int g = 33;

	test.insert(a);
	test.insert(b);
	test.insert(c);
	test.insert(d);
	test.insert(e);
	test.insert(f);
	test.insert(g);

	cout << "In Order: ";
	test.inOrder();
	cout << endl << "Pre Order: ";
	test.preOrder();
	cout << endl << "Post Order: ";
	test.postOrder();
	cout << endl;


	bool trial1 = test.search(8);
	if (trial1 == false)
		cout << "TRIAL 1: Node not found" << endl;
	if (trial1 == true)
		cout << "TRIAL 1: Node found" << endl;

	bool trial2 = test.search(27);
	if (trial2 == false)
		cout << "TRIAL 2: Node not found" << endl;
	if (trial2 == true)
		cout << "TRIAL 2: Node found" << endl;

	test.remove(89);
	test.remove(12);
	cout << "In Order After Removal: ";
	test.inOrder();



*/