/*
Welcome to the Door Game.

Objective:
The objective of this game is to be able to kill 4 bosses and get to the end. After choosing a door
you have to be able to kill the boss that you are up against, by attacking your opponent. Once you
attack, you opponent will also attack back.


Thought process:
The idea is the game is being selected at complete random. Attacks/HP/name selection is all by 
random. Just a fun quick little with some seperate functions that can be chosen.

*/

#include "pch.h"
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

using namespace std;

//function to select a random damage output to any attack
int attack(int target, string targetname) {
	srand(time(NULL));
		int att_val = rand() % 50;
			target -= att_val;
				cout << targetname << " was hit for " << att_val << endl;
				cout << targetname << " now has " << target << " HP." << endl;
	return target;
}

//function to randomly select a bosses name.
string randombossname() {
	string nameselect[5] = { "Mikey Mike" ,  "Weird Schaults",  "Biggy Bossman Rob" , "Scary Terry" ,  "The Hardest Worker" };
		srand(time(NULL));
			int ranselect = rand() % 5;
	return nameselect[ranselect];
}

//function to give a boss an hp in between 100 and 150 ** no longer being used **
int randomHP() {
	srand(time(NULL));
		int hpselect = rand() % 150 + 100;
	return hpselect;
}

//main function
int main()
{
	//var
	string playername;
	string bossname;
	int bossHP = 100;
	int hp = 100;
	int door;
	int input;
	int bosscount = 0;
	int attacking;

	//intro
	cout << "Please enter your name." << " ";
	cin >> playername;
	cout << "Hello, " << playername << ". Sorry to do this to you but you are now in a battle" << endl;
	cout << "for your life, choose a door and you will be given a random boss, defeat each boss" << endl;
	cout << "until the final 4th door to survive this game. Good luck" << endl << endl;
	
	//loop with HP condition. If one of them is met, then its game over.
	while (hp >= 0 || bosscount >= 4)
	{
			cout << "\n Pick a door." << endl;
			cout << "1. Door 1" << endl;
			cout << "2. Door 2" << endl;
			cin >> door;
			//door selection loop
			if (door == 1 || door == 2)
			{
				cout << "\nYou choose door " << door << endl;
				bossname = randombossname();
				cout << "\n\nA wild " << bossname << " appears!" << endl;
				cout << "His HP is " << bossHP << endl;
				attacking = 1;
				//attacking loop
					while (attacking == 1)
					{
						
							cout << "\n Attack him!." << endl;
							cout << "1. Attack" << endl;
							cin >> input;
							//hp difference condition
								if (input == 1)
								{
									srand(time(NULL));
									bossHP = attack(bossHP, bossname);
									hp = attack(hp, playername);
								}
								//break condition
									if (hp <= 0)
									{
										attacking = 0;
									}
									if (bossHP <= 0)
									{
										bosscount++;
										attacking = 0;
										bossHP = 100;
										hp = 100;
									}
					}
			}
			//condition for loss and win
			if (hp <= 0)
			{
				cout << "\nYou lost!" << endl;
			}
			else if (bosscount >= 4)
			{
				cout << "\nYou win!" << endl;
			}
	}

	//gg
	cout << "\n\n\n Game over..." << endl;
	return 0;
}