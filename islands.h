//Jefferson Crelia
#ifndef islands_h
#define islands_h

class islands {
	private:
		int	cnt;
		island* tail;
		island* head;
	public:
		islands() {cnt = 0;}
		island* getTail();//gets tail node
                island* getHead();//gets head node
                void setTail(island*);//sewt tail
                void setHead(island*);//set head
                void addIsland(int);//add an island
};
#endif /*islands_h*/
