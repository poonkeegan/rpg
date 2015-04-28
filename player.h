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
	void gainXP(int amount);
	void list() override;
	//int getAtt() override; Create when weapons system is implemented
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
	level = 1;
	cExp = 0;
	rExp = pow(2,((level+30)/6))-25;
	elm = REGULAR;
	attList.push_back(PowerStrike());
	attList.push_back(EnergyBolt());
}

void Player::gainXP(int amount){
	cExp += amount;
	cout << "You have gained " << amount << " experience points!" << endl; 
	if(cExp >= rExp){
		level++;
		cExp -= rExp;
		cout << rExp << endl;
		rExp = pow(2.0,((level+30)/6.0))-25;
		cout << rExp << "Congratulations "<< name << "! You have leveled up!"<< endl;
		int temp = rand() % 10;
		mHP += temp;
		cout << "Your Max HP has gone up by " << temp << endl;
		temp = rand() % 10;
		mMP += temp;
		cout << "Your Max MP has gone up by " << temp << endl;
		temp = rand() % 4;
		att += temp;
		cout << "Your Attack has gone up by " << temp << endl;
		temp = rand() % 2;
		def += temp;
		cout << "Your Defense has gone up by " << temp << endl;
		temp = rand() % 3;
		spd += temp;
		cout << "Your Speed has gone up by " << temp << endl;
		cHP = mHP;
		cMP = mMP;
	}
}

void Player::list (){
	cout <<"NAME:" << name << endl 
		<<"LEVEL:"<< level << endl
		<<"HP:" << getCHP() << "/" << getMHP() << endl
		<<"MP:" << getCMP() << "/" << getMMP() << endl
		<<"XP:" << cExp << "/" << rExp << endl
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

#endif