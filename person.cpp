//Jefferson Crelia
#include <iostream>
#include "connect.h"

using namespace std;

person::person() {
	perID = 0;
	perStat = 0;
	perLoc = 0;
	next = NULL;
}; //set all values to 0/NULL

person::person(int id, int stat, int loc, int date) {perID = id; perStat = stat; perLoc = loc; perDate = date;}

int person::getID() {return perID;} //returns ID of individual

void person::setID(int id) {perID = id;} //sets id = perID

int person::getStat() {return perStat;} //returns health status of individual

void person::setStat(int stat) {perStat = stat;} //sets stat = perStat

int person::getLoc() {return perLoc;} //returns location of individual

void person::setLoc(int loc) {perLoc = loc;}

int person::getDate() {return perDate;}

void person::setDate(int date) {perDate = date;}

person* person::getNext() {return next;} //gives next node

void person::setNext(person* np) {next = np;} //assign next node
