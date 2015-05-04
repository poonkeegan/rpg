#ifndef BATTLE_H
#define BATTLE_H
void attackPhase(Creature & first, Creature & second){
	if(first.Alive())
		first.fight(second);
	if(second.Alive())
		second.fight(first);
}

void battle(Player & a, Creature & b){
	cout << b.getName() << " has appeared!" << endl;
	do{
		cout	<< "What would you like to do?" << endl;
		cout	<< "Attack				-a" << endl
				<< "Defend				-d" << endl
				<< "See your Stats			-s" << endl;
		char command = getFirstChar();
		switch(command){
			case 'a':{
				int temp = 1;
				do{
					if(!between(temp, 1, a.attacks().size() + 1))
						cout << "Invalid Command" << endl;
					if(!a.canAttack())
						cout << "Too little mana" << endl;
					cout << "Attack List" << endl;
					for(int i = 0; i < a.attacks().size(); i++){
						cout << i+1 <<". " <<  a.attacks()[i].name << endl;
					}
					cin >> temp;
					cin.ignore();
				}while(!a.setAttMode(temp) || !a.canAttack());
				
			}break;
			case 'd':
				a.setDef(true);
				break;
			case 's':
				a.list();
				continue;
				break;
			default:
				cout << "Invalid Command" << endl;
				continue;
				break;
		}
		if(a.isDefending() && b.isDefending())
			cout << "You both defend" << endl;
		else if(a.getSpd() > b.getSpd())
			attackPhase(a, b);
		else if(a.getSpd() < b.getSpd())
			attackPhase(b, a);
		else{
			int option = rand() % 2;
			if(option = 0)
				attackPhase(a, b);
			else
				attackPhase(b, a);
		}
		a.setDef(false);
		b.setDef(false);
	}while(a.Alive() && b.Alive());
	
	if(a.Alive()){
		cout << a.getName() << " has defeated " << b.getName() << endl;
		a.gainXP(b.getXP());
	}else if(b.Alive()){
		cout << b.getName() << " has defeated " << a.getName() << endl;
	}
}
#endif