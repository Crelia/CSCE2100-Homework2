//Jefferson Crelia
#include <iostream>
#include "island.h"
#include "islands.h"

using namespace std;


island* islands::getTail() {return tail;}

island* islands::getHead() {return head;}

void islands::setTail(island* it) {tail = it;}

void islands::setHead(island* ih) {head = ih;}

void islands::addIsland(int isnum) {
        int id;

	island *temp = new island();

	while (cnt < isnum) {
        	//island *temp = new person();

        	id == cnt;

        	temp->setID(id);

        	if(cnt == 0) {head = tail = temp;}
        	else {
                	tail->setNext(temp);
                	tail = temp;
        	} //set head and tail nodes
        	cnt++;
	}
	return;
}

