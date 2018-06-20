//Jefferson Crelia
//CSCE 2100-001

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "connect.h"
#include "connects.h"
#include "island.h"
#include "islands.h"
#include "functions.h"

using namespace std;

int main() {
	ofstream out_s;
	ifstream in_s;

	people peeps;
	islands is;
	connects cons;

	get_stream(in_s, out_s);

	int transprob; //transmission probability
	int edperiod; //infected period
	int usperiod; //infectious period
	int maxcon; //maximum number of contacts in a day
	int iscon; //island connections
	int pop; //population
	int isnum; //number of islands
	int infnum; //number of infected

	in_s >> transprob;
	in_s >> edperiod;
	in_s >> usperiod;
	in_s >> maxcon;
	in_s >> iscon;
	in_s >> pop;
	in_s >> isnum;
	in_s >> infnum;


	out_s << transprob << endl << edperiod << endl << usperiod << endl << maxcon << endl << iscon << endl;
	out_s << pop << endl << isnum << endl << infnum << endl;

	cons.addCon(iscon, in_s, out_s);

	for(int id = 0; id < pop; id++) {
		peeps.addPerson(pop, id); //add people based on the population size
	}

	is.addIsland(isnum); //add islands based on the given number

	int j = 0; //dummy variable
	j = isnum; //set j to equal the number of islands


	//for i < population
	for (int i = 0; i < pop; i++) {
		//while the island number is not 0
		if (j != 0) {
			peeps.changeLoc(i, j); //change the location of the person to the island number
			j--; //go to the next island
		}

		if (j == 0) {j = isnum;} //when you are out of islands, cirle back to hihgest isnum and repeat until all people are given a location
	}

	int l = 3; //dummy variable

	//while the counter is less than the intitial infecteous number
	for (int k = 0; k < infnum; k++) {
		int ran;
		//srand(time(NULL)); //seed the random num
		ran = (rand() % infnum - 1) + 1; //random num between 1 and the num of people
		peeps.changeStat(ran, l); //change their status to infecteous
	}

	//Day cycle -  each loops is one day
	for (int date = 0; date < (edperiod * 7); date++) {
		out_s << string(100, '=') << endl << "Day: " << date+1 << endl << string(100, '=') << endl;

		peeps.changeranLoc(date, iscon); //change random persons locations
		peeps.conPer(transprob, maxcon, date); //have people make contacts
		peeps.checkDate(usperiod, edperiod); //check for how long person has been infctd, infctous
		peeps.prtInfo(in_s, out_s);
	}

//	cons.prtList();
//	cons.checkLoc(1, 1, iscon);

	return 0;
}
