//Jefferson Crelia
#pragma once
#include <string>
using namespace std;

class person {
	private:
		person *	next; //next node
		int		perID; //person ID
		int		perStat; //person status
		int		perLoc; //person location
		int		perDate; //date person was infected/infectious
	public:
		person();
		person(int, int, int, int); //constructor
		int		getID(); //gets ID
		void		setID(int id); //sets perID to id
		int		getStat(); //gets status of person
		void		setStat(int stat); //sets perStat to stat
		int		getLoc(); //gets perLoc
		void		setLoc(int loc); //sets perLoc to loc
		int		getDate();
		void		setDate(int date);
		person *	getNext(); //gets next node
		void		setNext(person*); //sets nextr bucket
};



class connect: public person {
        private:
                int             isFrom;
                int             isTo;
                int             pNum;
                connect *       next;
        public:
                connect();
                connect(int, int, int);
                int             getFrom();
                void            setFrom(int isfrom);
                int             getTo();
                void            setTo(int isto);
                int             getNum();
                void            setNum(int pnum);
                connect *       getNext();
                void            setNext(connect*);
};

