//Jefferson Crelia
#include "connects.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

using namespace std;

person* people::getTail() {return tail;} //returns tail node

person* people::getHead() {return head;} //returns head node

void people::setTail(person* pt) {tail = pt;} //sets tail node

void people::setHead(person* ph) {head = ph;} //sets head node

int people::getCnt() {return cnt;}

//add person
void people::addPerson(int pop, int id) {

	person *temp = new person(); //pointer to new person node

	temp->setID(id++); //set persons id
	temp->setStat(1); //set status to healthy

	if(cnt == 0) {
		head = tail = temp;
	}

	else {
		tail->setNext(temp); //if not set thenext node as temp
		tail = temp;
	}

	cnt++; //add to count
	return;
}

void people::changeLoc(int i, int j) {
	person *temp, *temp2; //pointer to island

	temp2 = head; //temp2 is at start
    	temp = head->getNext(); //temp is the nextnode

    	while (temp != tail) //while the head isnt the tail
    	{
		//if ID is equal to counter
        	if (temp->getID() == i)
        	{
			temp->setLoc(j); //set their location to j counter
                	return; //exit
        	}

        	else
        	{
                	temp2 = temp; //if not equal get next
                	temp = temp->getNext();//get the next patron to check
        	}
    	}

}

void people::changeStat(int k, int l) {
	person *temp, *temp2; //pointers to person nodes

	temp2 = head; //temp2 is start
	temp = head->getNext(); //temp is next

	//while the node isnt at the end
	while (temp != tail) {
		//if ID=counter
		if(temp->getID() == k) {
			temp->setStat(l); //set status to infecteous
			return;
		}

		else {
			temp2 = temp;//if not equal get next node
			temp = temp->getNext();
		}
	}
}

void people::conPer(int transprob, int maxcons, int date) {
	person *temp, *temp2; //pointer to persons

	temp = head;


	int randomt;//random transmission
	int randomper; //random per
	srand(time(NULL)); //random seeder

	//while there is a node
	while (temp != NULL) {

		temp2 = head;
		bool leave1 = false;

		//if the nodes status is infected
		if (temp->getStat() == 3) {
			//forthe counter is less than the max contacts
			for (int i = 0; i < maxcons; i++) {
				randomper = rand() % cnt +1;
				//while the second node is not NULL
				while (temp2 != NULL) {

					//randomper = rand() % cnt + 1;
					//cout << randomper << endl << endl << endl << endl;



					//If the ID = the random number
					if (temp2->getID() == randomper) {
						//if the location is  the same as the other nodes
						if (temp2->getLoc() == temp->getLoc()) {
							//srand(time(NULL));
							randomt = (rand() % 100) < transprob; //a transprob% chance of being infctd

							//if the random number is < the probablility
							if (randomt < transprob) {
								temp2->setStat(3); //set status of contacted person to infctous
								temp2->setDate(date);//set date

								leave1 = true;
								break; //quit
							}
							else {
							cout << "prob didnt work" << endl;
								leave1 = true;
								break; //if the number isnt < prob quit
							}

						}
						else {
						cout << "diff loc" << endl;
							leave1 = true;
							break; //if the locations are different
						}

					}
					else {
						person* temp4;
						temp4 = temp2->getNext(); //if the random number isnt the ID, getnext node
						temp2 = temp;
					}
				}
			if(leave1)break;
			}
			//if(leave1)break;

		}

		person* temp3;
		temp3 = temp->getNext();
		temp = temp3;
	}

}

void people::changeranLoc(int date, int iscon) {
	connects cons;

	person *temp;

	temp = head;

	bool leave = false;

	for(int i = 0; i < (cnt/4); i++) {
		int randper = rand() % cnt + 1;
		while (temp != NULL) {
			if(temp->getID() == randper) {
				int loc = temp->getLoc();
				int id = temp->getID();
				cons.checkLoc(loc, id, iscon);
				break;
			}
			else {
				person* temp2;
				temp2 = temp->getNext();
				temp = temp2;
			}
		}
		if(leave)break;
	}
}

void people::setnewLoc(int newloc, int id) {
	person *temp;

	temp = head;

	while (temp != NULL) {
		if(temp->getID() == id) {
			temp->setLoc(newloc);
			break;
		}
		else {

			cout << newloc << endl << temp->getLoc();

			person *temp2;
			temp2 = temp->getNext();
			temp = temp2;
		}
	}
}


void people::checkDate(int usperiod, int edperiod) {
	person *temp;

	temp = head;

	while (temp != NULL) {
		if(temp->getStat() == 3) {
			if(temp->getDate() > usperiod) {
				temp->setStat(2);
			}
		}

		if(temp->getStat() == 2) {
			if(temp->getDate() > edperiod) {
				temp->setStat(4);
			}
		}

		temp = temp->getNext();
	}
}


void people::prtInfo(ifstream& in_s, ofstream& out_s) {
	person *temp;
	temp = head;
	while (temp != NULL) {
		person *temp2;
		temp2 = temp->getNext();

		out_s << "ID: " << temp->getID() << "\t\tStatus: ";

		if (temp->getStat() == 1) {out_s << "Healthy\t";}
		if (temp->getStat() == 3) {out_s << "Infectious";}
		if (temp->getStat() == 2) {out_s << "Infected\t";}
		if (temp->getStat() == 4) {out_s << "Recovered";}

		out_s << "\t\tLocation: " << temp->getLoc() << endl << endl;

		temp = temp2;
	}
}
