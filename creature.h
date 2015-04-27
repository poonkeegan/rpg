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
	vector<Attacks> attList;
    string name;
    Element elm;
    public:
	virtual bool Alive();
	virtual int getAtt();
	virtual int getSpd();
	virtual int getDef();
	virtual int getElm();
	virtual int getCHP(); //current hp
	virtual int getMHP(); //maximum hp
	virtual int getCMP(); //current mp
	virtual int getMMP(); //maximum mp
	virtual string getName();
	virtual void fight(Creature & c);
	virtual void takeDmg(int damage, Element element);
	virtual void list();
    
};

void Creature::takeDmg(int damage, Element element){
	int temp = damage - getDef();
	cHP -= temp;
	if(getCHP() < 0)
		cHP = 0;
	cout << name << " takes " << temp << " damage " << endl
		<< name << " is at " << getCHP() << " health " << endl;
	
}

void Creature::fight (Creature & c){
	cout << name << " attacks " << c.name << endl;
	c.takeDmg(getAtt(), elm);
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
	return att;
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