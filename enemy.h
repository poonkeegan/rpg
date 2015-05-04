#ifndef ENEMY_H
#define ENEMY_H

using namespace std;

class Slime: public Creature
{
	public:
	Slime(){
		name = "Slime";
		att = 3;
		def = 1;
		mHP = 5;
		cHP = mHP;
		mMP = 0;
		cMP = mMP;
		spd = 2;
		elm = EARTH;
		xp = 3;
	}
};
class MetalSlime: public Slime
{
	public:
	MetalSlime(){
		name = "Metal Slime";
		att = 2;
		def = 1;
		mHP = 3;
		cHP = mHP;
		mMP = 0;
		cMP = mMP;
		spd = 2;
		elm = EARTH;
		xp = 15;
	}
};
class Boar: public Creature
{
	
	public:
	Boar(){
		name = "Boar";
		att = 7;
		def = 2;
		mHP = 15;
		cHP = mHP;
		mMP = 0;
		cMP = mMP;
		spd = 10;
		elm = REGULAR;
		xp = 7;
	}
};
class FireBoar: public Creature
{
	
	public:
	FireBoar(){
		name = "Fire Boar";
		att = 10;
		def = 2;
		mHP = 23;
		cHP = mHP;
		mMP = 10;
		cMP = mMP;
		spd = 10;
		elm = FIRE;
		xp = 8;
	}
};
class Zakum: public Creature
{
	public:
	Zakum(){
		name = "Zakum";
		att = 20;
		def = 10;
		mHP = 10;
		cHP = mHP;
		mMP = 120;
		cMP = mMP;
		spd = 14;
		elm = EARTH;
		xp = 100;
	}
};
#endif