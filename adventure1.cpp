#include <iostream>
#include <math.h>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	// /welcome the player
	cout << "Welcome to The Adventure of ... Well, you name it!\n";
	string adventureName;
	cin >> adventureName;
	bool debug = false;
	if(adventureName == "debug") debug = true;
	cout << "Oh hey, The Adventure of " << adventureName << " doesn't sound so bad.\n";

	//set up the game
	cout << "Setting up the game.\n";
	int health = 10, attack, block, iterator = 0;
	bool playerAlive = true;
	cout << "Basically what I just did BTS is made your health 10. If your health drop down to 0, you are out!\n";
	srand(time(NULL));
	int randomNumber = rand();
	cout << "Generating random turn number from 4 to 8...\n";
	int gameTurn = (randomNumber % 5) + 4;
	cout << "Number of turn adventure end: " << gameTurn << endl << endl;

	//start the loop
	cout << "The game begins!\n";
	while(playerAlive == true && iterator++ < gameTurn)
	{
		cout << "Turn " << iterator << ".\n";
		cout << "The monster attack!\n";
		attack = rand() % 5;
		block = rand() % 5;
		if(debug == true)
		{
			cout << "Attack: " << attack << endl << "Block: " << block << endl;
		}
		if(attack <= block)
		{
			cout << "You successfully blocked an attack!\n\n";
		}
		if(attack > block)
		{
			cout << "You failed to block an attack!\n";
			health = health - attack;
			cout << "You have " << health << " health left.\n\n";
			if(health <= 0) playerAlive = false;
		}
	}
	if(playerAlive == false) cout << "You really need to go see the doctor... But dead people don't go to the doctor...\n";
	cout << "Congratulation! You defeated the adventure!\n";
}