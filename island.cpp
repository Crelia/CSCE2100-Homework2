//Jefferson Crelia
#include <iostream>
#include "island.h"

using namespace std;

island::island() {
	isID = 0;
	isPop = 0;
	next = NULL;
} //set all values to 0/NULL

island::island(int id, int pop) {isID = id; isPop = pop;} //constructor

int island::getID() {return isID;} //return the ID of node

void island::setID(int id) {isID = id;} //set ID of node

int island::getPop() {return isPop;} //return pop of island

void island::setPop(int pop) {isPop = pop;} //set pop of island

island* island::getNext() {return next;} //gets next node

void island::setNext(island* ni) {next = ni;} //assign next node


