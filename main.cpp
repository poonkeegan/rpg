#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <ctime>
#include "attacks.h"
#include "creature.h"
#include "player.h"
#include "slime.h"
#include "methods.h"
using namespace std;

int main()
{
	srand(time(0));
	string input;
    cout << "What is your name" << endl;
    getline (cin, input);
	cout << "Hello " << input << "!" << endl;
	Player player (input);
	cout << "Press Enter to start your quest into the depths of Orbis Tower" << endl;
	cin.ignore();
	int floor = 0;
	bool floorFound = false;
	while(floor < 10){
		cout	<< "Would you like to:" << endl
				<< "Open inventory 		-i" << endl
				<< "List your stats		-l" << endl
				<< "Continue Exploring 	-e" << endl;
		if(floorFound){
		cout	<< "Go down a floor		-f" << endl;
		}
		char command = getFirstChar();
		switch(command){
			case 'e':{
				int chance = rand() % 100;
				if(between(chance, 0, 90)){
					Slime slime;
					battle(player, slime);
				}
				else if(between(chance, 90, 100)){
					cout << "You found the staircase" << endl;
					floorFound = true;
				}
			}break;
			case 'l':
				player.list();
				break;
			case 'x':
				return 0;
				break;
			case 'f':
				if(floorFound){
					floor++;
					floorFound = false;
					if(floor < 10)
						cout << "You are now on floor " << floor+1 << endl;
					break;
				}
			
			default:
				cout << "Invalid command" << endl;
			
		}
		
		if(!player.Alive()){
			cout << "Game Over! Press Enter to exit" << endl;
			cin.ignore();
			return 0;
		}
		cout << "Press Enter to continue" << endl;
		cin.ignore();
	}
	cout << "Congratulations! You have made it through the tower!" << endl;
    return 0;
}

