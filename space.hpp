#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{
	protected:
		Space *up;
		Space *down;
		Space *left;
		Space *right;
		char *print;
		bool spawned {false};
		int type {0};
		int howMany {0};
		bool player {false};
	public:
		virtual void spawn() = 0;
		void setPrint(char &p);
		char getPrint();
		void pickUp();
		bool getPlayer();
		void setPlayer(bool sp);
		Space* getUp();
		void setUp(Space *u);
		Space* getDown();
		void setDown(Space *d);
		Space* getLeft();
		void setLeft(Space *l);
		Space* getRight();
		void setRight(Space *r);
		int getType();
		void setType(int t);
		int getHowMany();
		void setHowMany(int h);
		bool getSpawned();
		void setSpawned(bool s);
		virtual ~Space() {};
};
#endif

