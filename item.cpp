/*
 * item.cpp
 *
 *  Created on: May 2, 2020
 *      Author: AJoy
 */

#include <iostream>
#include <string>
#include "item.h"
using namespace std;

item::item() {
	quantity = 0;
	shelfLife = 0;
}

item::item(int q, char n[], int SL)
{
	quantity = q;
	shelfLife = SL;
}

bool item::operator >(const item & other) {
	return ((this->quantity) > (other.quantity));
}

bool item::operator >=(const item & other) {
	return ((this->quantity) >= (other.quantity));
}

bool item::operator <(const item & other) {
	return ((this->quantity) < (other.quantity));
}

bool item::operator <=(const item & other) {
	return ((this->quantity) <= (other.quantity));
}

bool item::operator ==(const item & other) {
	return ((this->quantity) == (other.quantity));
}

bool item::operator >(const int & otherSL) {
	return ((this->shelfLife) > (otherSL));
}

bool item::operator >=(const int & otherSL) {
	return ((this->shelfLife) >= (otherSL));
}

bool item::operator <(const int & otherSL) {
	return ((this->shelfLife) < (otherSL));
}

bool item::operator <=(const int & otherSL) {
	return ((this->shelfLife) <= (otherSL));
}

bool item::operator ==(const int & otherSL) {
	return ((this->shelfLife) == (otherSL));
}

ostream& operator <<(ostream& os, const item& item) {
	os << "name" << item.name << ", " << "Quantity: " << item.quantity << ", " << "Shelflife: " << item.shelfLife;
	return os;
}

istream& operator >>(istream& is, item& item) {
	char temp_char; //Read ','
	is >> skipws >> item.quantity >> temp_char >> skipws >> item.name >> temp_char >> skipws >> item.shelfLife;
	if(temp_char != ','){
		throw "Input is not formatted correctly";
	}
	return is;
}
