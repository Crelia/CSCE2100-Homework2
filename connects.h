//Jefferson Crelia
#pragma once
#include "connect.h"

using namespace std;

class people {
	private:
		int cnt; //count
		person* tail; //node tail
		person* head; //node head
	public:
		people() {cnt = 0;}; //constructor
		person* getTail(); //return tail
		person* getHead(); //return head
		int	 getCnt();
		void	setTail(person*); //set tail
		void	setHead(person*); //set head
		void	addPerson(int, int); //add person
		void	editPerson(int); //edit person by ID
		void	changeLoc(int, int); //change location of patron
		void	changeStat(int, int); //change status by ID, and code for stat
		void	conPer(int, int, int); //run through all contacts in a day
		void	checkDate(int, int);
		void	changeranLoc(int, int); //have random people move between islands
		void	setnewLoc(int, int);
		void	prtInfo(ifstream&, ofstream&);
		void	cleanUp(); //clean up nodes
};

class connects: public people {
        private:
                int cnt;
                connect* tail;
                connect* head;
        public:
                connects() {cnt = 0;}
                connect*        getTail();
                connect*        getHead();
                int             getCount();
                void            setTail(connect*);
                void            incCount();
                void            setHead(connect*);
                void            addCon(int, ifstream&, ofstream&);
                void            prtList();
                virtual void            checkLoc(int, int, int);
};
