#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "attacks.h"
#include "creature.h"
#include "player.h"
#include "slime.h"
void attackPhase(Creature & first, Creature & second){
	if(first.Alive())
		first.fight(second);
	if(second.Alive())
		second.fight(first);
}

void battle(Creature & a, Creature & b){
	cout << b.getName() << " has appeared!" << endl;
	do{
		if(a.getSpd() > b.getSpd())
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
	}while(a.Alive() && b.Alive());
	
	if(a.Alive()){
		cout << a.getName() << " has defeated " << b.getName() << endl;
	}else if(b.Alive()){
		cout << b.getName() << " has defeated " << a.getName() << endl;
	}
}


using namespace std;
bool between(int x, int y, int z){
	if(y <= x && x < z)
		return true;
	else
		return false;
}
int main()
{
	string input;
    cout << "What is your name" << endl;
    getline (cin, input);
	cout << "Hello " << input << "!" << endl;
	Player player (input);
	cout << "Press Enter to start your quest into the depths of Orbis Tower" << endl;
		cin.ignore();
	int floor = 0;
	while(floor < 10){
		int chance = rand() % 100;
		if(between(chance, 0, 90)){
			Slime slime;
			battle(player, slime);
		}
		if(between(chance, 90, 100)){
			cout << "You made it past a floor" << endl;
			floor++;
		}
		if(!player.Alive()){
			cout << "Game Over! Press Enter to exit" << endl;
			cin.ignore();
			return 0;
		}
		cout << "Press Enter to continue forward" << endl;
		cin.ignore();
	}
	cout << "Congratulations! You have made it through the tower!" << endl;
    return 0;
}

