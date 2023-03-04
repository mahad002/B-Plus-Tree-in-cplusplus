#include "Graph.h"
#include "BTree.h"
#include<iostream>
#include<string>

using namespace std;

void Menu()
{
	system("cls");

	cout << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "Welcome to Assignment 2 !!!" << endl;
	cout << "1-Question 1" << endl;
	cout << "2-Question 2" << endl;
	cout << "3-Ext" << endl;

	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	int op;
	cout << "Enter option: ";
	while (!(cin >> op && op <= 3 && op >= 1))
	{
		cout << "Enter valid integer: ";

		cin.clear();
		cin.ignore(1000, '\n');
	}

	if (op == 1)
	{
		Main();

		Menu();
	}
	else if (op == 2)
	{
		Graph_Menu();

		Menu();
	}

	else if (op == 3)
	{
		//exit(-1);
	}
}

int main()
{

	Menu();

	cout << endl;

	return 0;
}