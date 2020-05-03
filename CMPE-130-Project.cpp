//============================================================================
// Name        : CMPE-130-Project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "inventory.h"
#include "item.h"
using namespace std;

int main() {
	inventory sto;
	char name[30];
	int quantity, shelfLife, choice;

	do
	{
		cout << "<--------Your Food Pantry---------->" << endl;
		cout << "<--------Menu----------->" << endl;
		cout << "(1) Insert an item to my Pantry." << endl;
		cout << "(2) Delete an item from my Pantry." << endl;
		cout << "(3) Search for an item." << endl;
		cout << "(4) Update my Pantry" << endl;
		cout << "(5) What is in my Pantry?" << endl;
		cout << "(6) Exit from my Pantry" << endl;
		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch (choice) {
		case 1 :	cin.getline(name,80);
					cout << "Enter name of item: " << endl;
					cin.getline(name,80);
					cout << "Enter the quantity of item: " << endl;
					cin >> quantity;
					cout << "Enter the shelf life in days of item: " << endl;
					cin >> shelfLife;
					sto.insertItem(name, quantity, shelfLife);
					break;
		case 2 : 	cin.getline(name,80);
					cout << "Enter name of item: " << endl;
					cin.getline(name, 80);
					sto.deleteItem(name);
					break;
		case 3 :	cin.getline(name,80);
					cout << "Enter name of item: " << endl;
					cin.getline(name, 80);
					item *test;
					test = sto.searchi(name);
					if(test != NULL) {
						cout << "<------Searching Result-------->" << endl;
						cout << "ITEM FOUND: " << test->name << test->quantity << test->shelfLife << endl;
					} else {
						cout << "ITEM NOT FOUND" << endl;
					}
					break;
		case 4 : 	cout << "Enter details of item for update: " << endl;
		cin.getline(name,80);
					cout << "Enter name of item: " << endl;
					cin.getline(name, 80);
					cout << "Enter new quantity: " << endl;
					cin >> quantity;
					cout << "Enter new shelf life in days: " << endl;
					cin >> shelfLife;
					sto.updateItem(name, quantity, shelfLife);
					break;
		case 5 : 	sto.printItems();

		}
	} while(choice != 6);

	return 0;
}
