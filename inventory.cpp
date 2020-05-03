/*
 * inventory.cpp
 *
 *  Created on: May 2, 2020
 *      Author: AJoy
 */

#include "inventory.h"

#include <iostream>
#include <string>
#include "item.h"
using namespace std;

inventory::inventory() {
	numItem = 0;
}

void inventory::insertItem(char itemName[], int itemQuantity, int itemShelflife) {
	strcpy(db[numItem].name, itemName);
	db[numItem].quantity = itemQuantity;
	db[numItem].shelfLife = itemShelflife;
	cout << "ITEM INSERTED SUCCESFULLY" << endl;
	numItem++;

}

void inventory::deleteItem(char itemName[]) {
	for(int i = 0; i < numItem; i++) {
		if(strcmp(itemName, db[i].name) == 0) {
			db[i].quantity--;
			cout << "ITEM DELETED SUCCESFULLY" << endl;
			return;
		}
	}
	cout << "ITEM NOT FOUND" << endl;
}

item *inventory::searchi(char itemName[]) {
	for(int i = 0; i < numItem; i++) {
		if(strcmp(itemName, db[i].name)==0) {
			return &db[i];
		}
	}
	return NULL;
}

void inventory::updateItem(char itemName[], int itemQuantity, int itemShelflife) {
	item *i = searchi(itemName);
	if(i == NULL) {
		cout << "ITEM NOT FOUND" << endl;
		return;
	}
	i->quantity = itemQuantity;
	i->shelfLife = itemShelflife;
}

void inventory::printItems() {
	if(numItem == 0) {
		cout << "There is nothing in your Pantry." << endl;
	} else {
		for(int i = 0; i < numItem; i++) {
		cout << i+1 << ". " << "Name: " << db[i].name << "\t\tQuantity: " << db[i].quantity << "\tShelf life: " << db[i].shelfLife << " days"<< endl;
		}
	}
}


