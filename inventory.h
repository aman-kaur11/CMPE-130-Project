/*
 * pantry.h
 *
 *  Created on: Apr 29, 2020
 *      Author: AJoy
 */

#ifndef INVENTORY_H_
#define INVENTORY_H_
#include <string>
#include "item.h"
using namespace std;

class inventory {
public:
	int numItem;
	item db[100];
	inventory();
	void insertItem(char itemName[], int itemQuantity, int itemShelflife);
	void deleteItem(char itemName[]);
	void updateItem(char itemName[], int itemQuantity, int itemShelflife);
	item * searchi(char itemName[]);
	void printItems();
	//sort()



};



#endif /* INVENTORY_H_ */
