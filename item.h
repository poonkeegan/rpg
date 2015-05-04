#ifndef ITEM_H
#define ITEM_H

using namespace std;

struct Item
{
	bool stackable;
	bool usable;
	int quantity;
	string name;
};

struct Potion: public Item
{
	int hp;
	int mana;
	Potion(int strength){
		usable = true;
		stackable = true;
	}
};

struct ManaPotion: public Potion
{
	
};

struct HealthPotion: public Potion
{
	
};

struct Equipment: public Item
{
	int hp;
	int mp;
	int att;
	int mAtt;
	int def;
	int spd;
	Element elm;
	Equipment(){
		usable = false;
		stackable = false;
		quantity = 1;
	}
};

struct Weapon: public Equipment
{
	
};

struct Armor: public Equipment
{
	
};

#endif