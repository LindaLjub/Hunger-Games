
#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
using namespace std;


class game
{
public:
	// Variabeldeklarationer.

	string weapon; 
	string hinder1, mat1;
	int kills = 0;
	int hp = 100;
	
	char SvarRum, svarUnderProgress;
	char svarForest1, svarForest2;
	char svarLake1;
	char svarMountains1, svarSouthCave, svarNorthCave, svarSleep;

	bool spel;
	bool forestSpel, forestLookSpel, forestHideSpel;
	bool mountainSpel, mountainCaveNorth, mountainGoInNorthCave, mountainStayNorthCave;
	bool mountainCaveSouth, mountainSouthTunnel;
	bool lakeSpel, lakeTakeOne, lakeTakeTwo;


	enum rum { forest = '1', lake = '2', mountains = '3', inventory = '4', getOut = '5' };
	enum forest2 { fight = '1', run = '2' };
	enum forest { look = '1', hide = '2' };
	enum lake { vapen1 = '1', vapen2 = '2', nothing = '3' };
	enum mountain { northCave = '1', southCave = '2', Back = '3' };
	enum northcave { sleep = '1', notSleep = '2'};
	enum tunnel { goTunnel = '1', goBack = '2' };

	//funktioner
	
	void spelet();
	void inventoryList();
	void HpKollen();
	//void regler();

	void placeMountains();
		void northCavePlace();
			void goInNorthCave();
			void stayNorthCave();
				void northCaveFight();
		void southCavePlace();
			void tunnelPlace();

	void placeLake();
		void LakeTake1();
		void LakeTake2();

	void placeForest();
		void forestLook();
			void forestFight();
		void forestHide();

		

	game();
	~game();

};

