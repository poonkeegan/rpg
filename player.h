#ifndef PLAYER_H
#define PLAYER_H
using namespace std;
class Player: public Creature 
{
	protected:
	int cExp;	//current exp
	int rExp;	//required exp for level
	int level;
    public:
    Player(string n);
};

Player::Player (string n){
    name = n;
    att = 5;
    def = 1;
    mHP = 20;
	cHP = mHP;
	mMP = 20;
	cMP = mMP;
    spd = 3;
	elm = REGULAR;
}

#endif