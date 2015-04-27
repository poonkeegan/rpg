#ifndef CREATURE_H
#define CREATURE_H

using namespace std;


class Creature
{
	protected:
    int att;
    int cHP;
	int mHP;
    int cMP;
	int mMP;
    int spd;
    int def;
	int attMode;
	vector<Attacks> attList;
    string name;
    Element elm;
    public:
	bool Alive();
	bool canAttack();
	virtual int getAtt();
	virtual int getSpd();
	virtual int getDef();
	virtual int getElm();
	virtual int getCHP(); //current hp
	virtual int getMHP(); //maximum hp
	virtual int getCMP(); //current mp
	virtual int getMMP(); //maximum mp
	string getName();
	void fight(Creature & c);
	virtual void takeDmg(int damage, Element element);
	virtual void useMP(int amount);
	virtual void list();
    Creature();
};

Creature::Creature(){
	att = 1;
	mHP = 1;
	cHP = mHP;
	mMP = 0;
	cMP = mMP;
	spd = 0;
	def = 0;
	attMode = 0;
	attList.push_back(Attack());
	elm = REGULAR;
	name = "kelp";
}

void Creature::takeDmg(int damage, Element element){
	if(damage > 0){
		int temp = damage - getDef();
		cHP -= temp;
		if(getCHP() < 0)
			cHP = 0;
		cout << name << " takes " << temp << " damage " << endl
			<< name << " is at " << getCHP() << " health " << endl;
	}
}
bool Creature::canAttack(){
	if(cMP < attList[attMode].mpCost)
		return false;
	return true;
}

void Creature::useMP(int amount){
	cMP -= amount;
	if(cMP < 0)
		cMP = 0;
}

void Creature::fight (Creature & c){
	cout << name << " attacks " << c.name << endl;
	c.takeDmg(getAtt(), elm);
	takeDmg(attList[attMode].hpCost, REGULAR);
	useMP(attList[attMode].mpCost);
}

void Creature::list (){
	cout <<"NAME:" << name << endl 
		<<"HP:" << getCHP() << "/" << getMHP() << endl
		<<"ATT:" << att << endl
		<<"DEF:" << def << endl
		<<"SPD:" << spd << endl
		<<"ELM:";
		switch(elm){
			case 0:
				cout << "REGULAR";
				break;
			case 1:
				cout << "FIRE";
				break;
			case 2:
				cout << "WATER";
				break;
			case 3:
				cout << "EARTH";
				break;
		}
		cout << endl;
}

//Accessors
string Creature::getName(){
	return name;
}
int Creature::getAtt(){
	int attackPower = 0;
	if(attList[attMode].magic != true)
		attackPower = att + attList[attMode].power;
	else
		attackPower = attList[attMode].power;
	return attackPower;
}
int Creature::getSpd(){
	return spd;
}
int Creature::getDef(){
	return def;
}
int Creature::getElm(){
	return elm;
}
int Creature::getCHP(){
	return cHP;
}
int Creature::getMHP(){
	return mHP;
}
int Creature::getCMP(){
	return cMP;
}
int Creature::getMMP(){
	return mMP;
}
bool Creature::Alive(){
	if(getCHP() > 0)
		return true;
	else
		return false;
}


#endif