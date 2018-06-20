//Jefferson Crelia
#include <iostream>
#include "connect.h"

using namespace std;

connect::connect() {
	isFrom = 0;
	isTo = 0;
	pNum = 0;
	next = NULL;
} //set all values to 0/NULL

connect::connect(int isfrom, int isto, int pnum) {isfrom = isFrom; isto = isTo; pnum = pNum;} //constructor

int connect::getFrom() {return isFrom;}

void connect::setFrom(int isfrom) {isFrom = isfrom;}

int connect::getTo() {return isTo;}

void connect::setTo(int isto) {isTo = isto;}

int connect::getNum() {return pNum;}

void connect::setNum(int pnum) {pNum = pnum;}

connect* connect::getNext() {return next;}

void connect::setNext(connect* nc) {next = nc;}
