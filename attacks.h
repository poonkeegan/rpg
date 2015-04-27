#ifndef ATTACKS_H
#define ATTACKS_H

using namespace std;

class Attack
{
	protected:
	int power;
	Element elm;
	string name;
	public:
	int getPower();
	string getName();
	element elm();
}

#endif