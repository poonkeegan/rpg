#ifndef METHODS_H
#define METHODS_H

using namespace std;


bool between(int x, int y, int z){
	if(y <= x && x < z)
		return true;
	else
		return false;
}

char getFirstChar(){
	string input;
	getline(cin, input);
	if(input.size() > 0)
		return(tolower(input.at(0)));
	else
		return(' ');
}


#endif