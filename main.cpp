/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
#include "inventory.h"
#include "item.h"
using namespace std;

void readFromFile(inventory& A, string fileName){
	ifstream fin(fileName);
	item element;
		while(!fin.eof()){
			fin >> element;
			cout << "Inserting " << element.name << endl;
			A.insert(element);
		}


}

int main() {
	inventory sto, Atest;
	char name[30];
	int quantity, shelfLife, choice;

	do
	{
		cout << "<--------Your Food Pantry---------->" << endl;
		cout << "<---------------Menu--------------->" << endl;
		cout << "(1) Insert an item to my Pantry." << endl;
		cout << "(2) Delete an item from my Pantry." << endl;
		cout << "(3) Search for an item." << endl;
		cout << "(4) Update my Pantry." << endl;
		cout << "(5) What is in my Pantry?" << endl;
		cout << "(6) Prioritize my Pantry." << endl;
		cout << "(7) Upload list." << endl;
		cout << "(8) Exit from my Pantry." << endl;
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
					break;
				
		case 6:    	cout << "Shortest Lifespan First:" << endl;
               			sto.heapsort();
                		sto.printArray();
                   		break;
				
		case 7 :	string fileName = "Test.txt";
					readFromFile(Atest, "Test.txt");
					Atest.printItems();


								}
	} while(choice != 8);

	return 0;
}

