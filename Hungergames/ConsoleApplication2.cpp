

#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>	// Sleep(1000)
#include <iomanip>		// till setw(10)
#include <sstream>		// stringstream(variabel)
#include "game.h"
using namespace std;



int main()
{
	setlocale(LC_ALL, "");
	game player1;

	
	cout << " Welcome.. Enter your name: ";
	string name;
	getline(cin, name);
	cout << " Hello there " << name << ". You have now entered The Hunger games.\n Please wait.." << endl; 

	Sleep(3000);
	cout << "\n The Hunger Games universe is a dystopia set in Panem,\n a country consisting of the wealthy Capitol and 12 districts in varying states of poverty." << endl;
	cout << " Every year, people from the districts are selected to participate in a compulsory battle royale death match.\n Now it is up to you " << name << ". " << endl;
	Sleep(3000);
	cout << "\n Du kan endast ha ett vapen åt gången!\n Du ska döda 3 motståndare!\n Vart vill du springa? " << endl;
	


	player1.spelet();


	return 0;
  
}






