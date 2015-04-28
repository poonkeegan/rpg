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
	int xp; //awarded xp on kill
	int attMode;
	bool defending;
	vector<Attacks> attList;
    string name;
    Element elm;
    public:
	bool Alive();
	bool canAttack();
	vector<Attacks> attacks();
	virtual int getAtt();
	virtual int getSpd();
	virtual int getDef();
	virtual int getElm();
	virtual int getCHP(); //current hp
	virtual int getMHP(); //maximum hp
	virtual int getCMP(); //current mp
	virtual int getMMP(); //maximum mp
	string getName();
	int getXP();
	void fight(Creature & c);
	void setDef(bool defense);
	bool isDefending();
	bool setAttMode(int i);
	virtual void takeDmg(int damage, Element element, bool magic);
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
	defending = false;
}

void Creature::takeDmg(int damage, Element element, bool magic){
	if(damage > 0){
		int temp = damage;
		if(!magic)
			temp -= getDef();
		if(temp < 0)
			temp = 0;
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
	if(amount > 0){
		cMP -= amount;
		cout << name << " used " << amount << " MP " << endl
			<< name << " is at " << getCMP() << " MP " << endl;
		if(cMP < 0)
			cMP = 0;
	}
}

void Creature::fight (Creature & c){
	if(!defending){
		if(c.isDefending()){
			cout<< c.getName() << " guards" << endl;
		}
		cout << name << " attacks " << c.name << endl;
		c.takeDmg(getAtt(), elm, attList[attMode].magic);
		takeDmg(attList[attMode].hpCost, REGULAR, true);
		useMP(attList[attMode].mpCost);
	}
}

void Creature::list (){
	cout <<"NAME:" << name << endl 
		<<"HP:" << getCHP() << "/" << getMHP() << endl
		<<"MP:" << getCMP() << "/" << getMMP() << endl
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
//Mutators
void Creature::setDef(bool defense){
	defending = defense;
}
bool Creature::setAttMode(int i){
	if(0 < i && i <= attList.size()){
		attMode = i - 1;
		return true;
	}
	return false;
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
	int defense = def;
	if(defending)
		defense += 5;
	return defense;
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
int Creature::getXP(){
	return xp;
}
vector<Attacks> Creature::attacks(){
	return attList;
}
bool Creature::isDefending(){
	return defending;
}
bool Creature::Alive(){
	if(getCHP() > 0)
		return true;
	else
		return false;
}


#endif