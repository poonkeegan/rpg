#ifndef SLIME_H
#define SLIME_H

using namespace std;

class Slime: public Creature
{
	public:
	Slime();
};

Slime::Slime(){
	name = "Slime";
    att = 2;
    def = 1;
    mHP = 5;
	cHP = mHP;
	mMP = 0;
	cMP = mMP;
    spd = 2;
	elm = EARTH;
	attList.push_back(Attack());
}

#endif