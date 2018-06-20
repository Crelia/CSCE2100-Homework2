//Jefferson Crelia
#include "connects.h"
#include <iostream>
#include <fstream>

using namespace std;

connect* connects::getTail() {return tail;}

connect* connects::getHead() {return head;}

int connects::getCount() {return cnt;}

void connects::incCount() {cnt++;}

void connects::setTail(connect* ct) {tail = ct;}

void connects::setHead(connect* ch) {head = ch;}

void connects::addCon(int iscon, ifstream& in_s, ofstream& out_s) {

	int isfrom[iscon], isto[iscon], pnum[iscon];

	for (int i = 0; i < iscon; i++) {
		in_s >> isfrom[i] >> isto[i] >> pnum[i];

		int from = isfrom[i];
		int to = isto[i];
		int num = pnum[i];

		connect *temp = new connect();

		temp->setFrom(from);
		temp->setTo(to);
		temp->setNum(num);

		if(cnt == 0) {head = tail = temp;}
		else {
			tail->setNext(temp);
			tail = temp;
		} //set head and tail node
		incCount();
	}

	connect *temp2;
	temp2 = head;
	while (temp2 != NULL) {
		connect *temp3;
		temp3 = temp2->getNext();
		cout << temp2->getFrom() << endl;
		temp2 = temp3;
	}

	return;
}

void connects::checkLoc(int loc, int id, int iscon) {
/*	connect *temp;

	temp = head;
	while (temp != NULL) {
		connect *temp2;
		temp2 = temp->getNext();
		cout << temp->getFrom() << endl;
		temp = temp2;
	}

	people peeps;


	while (temp != NULL) {
		if(temp->getFrom() == loc) {

			cout << "TEST: IT IS GETTING TO SETNEWLOC" << endl;
			int newloc = temp->getTo();
			peeps.setnewLoc(newloc, id);
			break;
		}
		else {
			cout << "NOT EVEN GETTING HERE" << endl;

			connect *temp2;
			temp2 = temp->getNext();
			temp = temp2;
		}
	}
*/}

void connects::prtList() {
	connect *temp;

	temp = head;

	while(temp != NULL) {
		connect *temp2;
		temp2 = temp->getNext();
		cout << temp->getFrom() << endl;
		temp = temp2;
	}
}
