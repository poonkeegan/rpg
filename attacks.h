#ifndef ATTACKS_H
#define ATTACKS_H
using namespace std;
enum Element {REGULAR	= 0,
				FIRE	= 1,
				WATER	= 2, 
				EARTH	= 3};
struct Attacks
{
	public:
	int power;
	int hpCost;
	int mpCost;
	bool magic;
	Element elm;
	string name;
};
struct Attack: public Attacks
{
	Attack(){
		power = 0;
		hpCost = 0;
		mpCost = 0;
		elm = REGULAR;
		magic = false;
		name = "Regular Attack";
	}
};
struct PowerStrike: public Attacks
{
	PowerStrike(){
		power = 7;
		hpCost = 0;
		mpCost = 3;
		elm = REGULAR;
		magic = false;
		name = "Power Strike";
	}
};
struct SlashBlast: public Attacks
{
	SlashBlast(){
		power = 8;
		hpCost = 3;
		mpCost = 2;
		elm = REGULAR;
		magic = false;
		name = "Slash Blast";
	}
};
struct EnergyBolt: public Attacks
{
	EnergyBolt(){
		power = 10;
		hpCost = 0;
		mpCost = 2;
		elm = REGULAR;
		magic = true;
		name = "Energy Bolt";
	}
};
struct MagicClaw: public Attacks
{
	MagicClaw(){
		power = 18;
		hpCost = 0;
		mpCost = 5;
		elm = REGULAR;
		magic = true;
		name = "Magic Claw";
	}
};
struct DragonFury: public Attacks
{
	DragonFury(){
		power = 35;
		hpCost = 12;
		mpCost = 5;
		elm = REGULAR;
		magic = false;
		name = "Dragon Fury";
	}
};
struct Genesis: public Attacks
{
	Genesis(){
		power = 40;
		hpCost = 0;
		mpCost = 12;
		elm = REGULAR;
		magic = true;
		name = "Genesis";
	}
};
struct Blizzard: public Attacks
{
	Blizzard(){
		power = 35;
		hpCost = 0;
		mpCost = 12;
		elm = WATER;
		magic = true;
		name = "Blizzard";
	}
};
struct MeteorShower: public Attacks
{
	MeteorShower(){
		power = 35;
		hpCost = 0;
		mpCost = 12;
		elm = EARTH;
		magic = true;
		name = "Meteor Shower";
	}
};
struct FlameGear: public Attacks
{
	FlameGear(){
		power = 35;
		hpCost = 0;
		mpCost = 12;
		elm = FIRE;
		magic = true;
		name = "Flame Gear";
	}
};
#endif