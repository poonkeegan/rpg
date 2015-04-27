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
	int manaCost;
	bool magic;
	Element elm;
	string name;
};
struct Attack: public Attacks
{
	Attack(){
		power = 0;
		hpCost = 0;
		manaCost = 0;
		elm = REGULAR;
		magic = false;
	}
};
struct PowerStrike: public Attacks
{
	PowerStrike(){
		power = 7;
		hpCost = 0;
		manaCost = 3;
		elm = REGULAR;
		magic = false;
	}
};
struct SlashBlast: public Attacks
{
	SlashBlast(){
		power = 8;
		hpCost = 3;
		manaCost = 2;
		elm = REGULAR;
		magic = false;
	}
};
struct EnergyBolt: public Attacks
{
	EnergyBolt(){
		power = 10;
		hpCost = 0;
		manaCost = 2;
		elm = REGULAR;
		magic = true;
	}
};
struct MagicClaw: public Attacks
{
	MagicClaw(){
		power = 18;
		hpCost = 0;
		manaCost = 5;
		elm = REGULAR;
		magic = true;
	}
};
struct DragonFury: public Attacks
{
	DragonFury(){
		power = 35;
		hpCost = 12;
		manaCost = 5;
		elm = REGULAR;
		magic = false;
	}
};
struct Genesis: public Attacks
{
	Genesis(){
		power = 40;
		hpCost = 0;
		manaCost = 12;
		elm = REGULAR;
		magic = true;
	}
};
struct Blizzard: public Attacks
{
	Blizzard(){
		power = 35;
		hpCost = 0;
		manaCost = 12;
		elm = WATER;
		magic = true;
	}
};
struct MeteorShower: public Attacks
{
	MeteorShower(){
		power = 35;
		hpCost = 0;
		manaCost = 12;
		elm = EARTH;
		magic = true;
	}
};
struct FlameGear: public Attacks
{
	FlameGear(){
		power = 35;
		hpCost = 0;
		manaCost = 12;
		elm = FIRE;
		magic = true;
	}
};
#endif