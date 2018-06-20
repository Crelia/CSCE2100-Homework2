//Jefferson Crelia
#ifndef island_h
#define island_h

using namespace std;

class island {
	private:
		int		isID; //island ID
		int		isPop; //island population
		island *	next; //next node
	public:
		island();
		island(int, int); //constructor
		int		getID(); //gets ID of island
                void		setID(int id); //sets ID to island
		int		getPop(); //gets pop of  island
		void		setPop(int pop); //sets island pop to pop
                island *        getNext(); //gets next node
                void            setNext(island*); //sets next bucket

};
#endif /*island_h*/

