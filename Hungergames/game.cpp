#include "pch.h"
#include "game.h"
#include <iostream>
#include <string>
#include <Windows.h>	
#include <iomanip>		
#include <sstream>	
#include <cstdlib>

using namespace std;

// MENY
void game::spelet() 
{
	
	while (spel) {

		if (hp <= 0)
		{
			cout << "\n Du blev skadad och hade inte tillräckligt med hp, du dog.\n GAME OVER! \n\n" << endl;
			spel = false;

		}
		else if (kills == 3)
		{
			cout << "\n Du har nu dödat 3 motståndare, GRATTIS!! DU VANN SPELET! \n\n" << endl;
			spel = false;

		}
		else if (hp > 100)
		{
			while (hp > 100)
			{
				hp = hp - 1;
			}
		}
		else 
		{ 

		cout << endl << " [1] --> SKOGEN\n" << " [2] --> SJÖN\n" << " [3] --> BERGEN\n" << endl << " [4] --> INVENTORY\n" << " [5] --> EXIT GAME\n" << endl;
		cin >> SvarRum;

			switch (SvarRum)
			{
			case forest:
			{
				placeForest();
			
				break;
			}
			case lake:
			{
				placeLake();
			
				break;
			}
			case mountains:
			{
				placeMountains();
			
				break;
			}
			case inventory:
			{
				inventoryList();
				break;
			}
			case getOut:
			{
				cout << "Spelet avslutas" << endl;
				spel = false;
				break;
			}

			default:
			{
				cout << "Försök igen.. TIPS, skriv en siffra mellan 1-5" << endl;

			}
			}
		}

	
	}
	


}

// MOUNTAINS

void game::placeMountains()
{
	mountainSpel = true;
	do {
	cout << "\n Du är högt uppe i bergen, du står oskyddad.\n Göm dig någonstans!\n " << endl;
	cout << " [1] Gå in i grottan norr om dig \n [2] Gå in i grottan söder om dig\n [3] Gå tillbaka till start\n\n ---> " << endl << endl;
	cin >> svarMountains1;

	switch (svarMountains1)
	{
	case northCave:
	{
		northCavePlace();
		mountainSpel = false;
		break;
	}
	case southCave:
	{
		
		southCavePlace();
		mountainSpel = false;
		break;
	}
	case Back:
	{
		spelet();
		mountainSpel = false;
		break;
	}
	default:
		cout << " Försök igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
	}

	} while (mountainSpel);
}

void game::northCavePlace()
{
	do {
	cout << " Du är inne i den norra grottan.. det är mörkt och kallt.\n Vill du gå längre in?\n" << endl;
	cout << " [1] Ja, gå längre in\n [2] Nej, stanna här\n\n ---> ";
	cin >> svarNorthCave;

	switch (svarNorthCave)
	{
	case '1':
	{
		goInNorthCave();
		mountainCaveNorth = false;
		break;
		
	}
	case '2':
	{		
		stayNorthCave();
		mountainCaveNorth = false;
		break;

	}
	default:
		cout << " Försök igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
		
	}
	} while (mountainCaveNorth);

}

void game::goInNorthCave()
{
	do {
	cout << " Längre in i grottan hittar du en öppning som ser ut att gå till sjön (Under konstruktion)" << endl;
	cout << " [1] Gå längre in, till sjön\n [2] Gå tillbaka till bergen\n ---> ";
	cin >> svarUnderProgress;
	switch (svarUnderProgress)
	{
	case '1':
	{
		placeLake();
		mountainGoInNorthCave = false;
		break;
	}
	case '2':
	{
		placeMountains();
		mountainGoInNorthCave = false;
		break;
	}
	default:
		cout << " Försök igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;

	}

	} while (mountainGoInNorthCave);
}

void game::stayNorthCave()
{
	do {
	srand(time(NULL));
	int hinder = rand() % 3;

	if (hinder < 1)
	{
		hinder1 = "Varg";
	}
	else if (hinder > 0 && hinder < 2)
	{
		hinder1 = "Björn";
	}
	else
	{
		hinder1 = "Människa";
	}

	cout << " Du stannar kvar..\n du somnar.. Zzz.. Zz.. \n Plötsligt dyker det upp en " << hinder1 << "!! Vad gör du?? " << endl;
	cout << "\n [1] Använd ditt vapen [ " << weapon << " ]" << "\n [2] Spring till sjön\n ---> ";
	cin >> svarUnderProgress;
	switch (svarUnderProgress)
	{
	case '1':
	{
		northCaveFight();
		mountainStayNorthCave = false;
		break;
	}
	case '2':
	{
		placeLake();
		mountainStayNorthCave = false;
		break;
	}
	default:
		cout << " Försök igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
		
	}

	} while (mountainStayNorthCave);

}

void game::northCaveFight()
{

	if (weapon == "pilbåge" || weapon == "yxa")
	{
		if (hinder1 == "Björn" || hinder1 == "Varg")
		{ 
			cout << "\n Bra jobbat! Du klarade dig och dödade " << hinder1  << "en "<< endl;
			hp = hp - 40;

		}
		else if (hinder1 == "Människa")
		{
			cout << "\n Bra jobbat! Du klarade dig och dödade en motståndare! "<< endl;
			kills = kills + 1;
			hp = hp - 40;
			cout << " Kills = " << kills << endl;

		}

		cout << " Men du blev skadad.." << endl;
		cout << " HP = " << hp << endl;
		cout << " Du borde gömma dig.. \n Vart springer du nu? " << endl;
		spelet();
	}
	else
	{
		cout << "\n Du borde nog hitta ett vapen först.. SPRING NÅGONSTANS!\n" << endl;
		spelet();
	}

}

void game::southCavePlace()
{
	do {

		cout << " Du är inne i den södra grottan.. här är det varmt och skönt.\n Du kanske ska passa på att sova lite?\n" << endl;
		cout << " [1] Ja, sov en stund och återhämta dig\n [2] Nej, var vaken\n\n ---> ";
		cin >> svarSouthCave;

		switch (svarSouthCave)
		{
		case sleep:
		{
			cout << " Zzzz... zz.. ZZz.." << endl;
			cout << " Du är nu utvilad och pigg! + 20hp <3 " << endl;
			hp = hp + 20;
			HpKollen();
			cout << " HP = " << hp << endl;
			tunnelPlace();
			mountainCaveSouth = false;
			break;
		}
		case notSleep:
		{
			cout << " Ok, glöm inte att vila ibland.." << endl;
			tunnelPlace();
			mountainCaveSouth = false;
			break;
		}
		default:
			cout << " Försök igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;

		}
	} while (mountainCaveSouth);
}

void game::tunnelPlace()
{
	do {
		cout << " Det ser ut att finnas en tunnel till den norra grottan lite längre in\n" << endl;
		cout << " [1] Gå in i tunneln \n [2] Gå tillbaka till bergen\n ---> ";
		cin >> svarSleep;
		switch (svarSleep)
		{
		case goTunnel:
		{
			cout << " Du är några meter in i tunneln\n Här börjar det bli kallare och kallare\n Du närmar dig den norra grottan" << endl;
			cout << " Du ser in i den norra grottan, du går in.. (Under konstruktion)\n " << endl;
			northCavePlace();
			mountainSouthTunnel = false;
			break;
		}
		case goBack:
		{
			placeMountains();
			mountainSouthTunnel = false;
			break;
		}

		default:
			cout << " Försök igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
			

		}
	} while (mountainSouthTunnel);
}

// LAKE
void game::placeLake() 
{	
	do {
	cout << "\n Du står någon meter från sjön, inga faror i sikte. " << endl; 
	cout << " [1] Stanna kvar på denna sidan av sjön \n [2] Gå till andra sidan\n---> ";
	cin >> svarUnderProgress;
	switch (svarUnderProgress)
	{
	case '1':
	{
		LakeTake1();
		lakeSpel = false;
		break;
	}
	case '2':
	{

		LakeTake2();
		lakeSpel = false;
		break;
	}
	default:
		cout << " Försök igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
	
	}
	} while (lakeSpel);

}

void game::LakeTake1()
{
	do {
		cout << " Det ligger en något nere vid sjökanten, vill du ta något?" << endl;
		cout << "\n\n [1] Ta pilbåge \n [2] Ta yxa\n [3] Gör ingenting\n\n ---> ";
		cin >> svarLake1;

		
		switch (svarLake1)
		{
		case vapen1:
		{
			weapon = "pilbåge";
			cout << " Bra val! Den ligger i din inventory." << endl;
			Sleep(1000);
			cout << " Pssst.. ";
			Sleep(1000);
			cout << " Du borde nog gömma dig. Vart vill du gå ? " << endl;
			Sleep(1000);
			spelet();
			lakeTakeOne = false;
			break;
		}
		case vapen2:
		{
			weapon = "yxa";
			cout << " Bra val! Den ligger i din inventory." << endl;
			Sleep(1000);
			cout << " Pssst.. ";
			Sleep(1000);
			cout << " Du borde nog gömma dig. Vart vill du gå ? " << endl;
			Sleep(1000);
			spelet();
			lakeTakeOne = false;
			break;

		}
		case nothing:
		{
			cout << " Ok, skyll dig själv" << endl;
			Sleep(1000);
			cout << " Pssst.. ";
			Sleep(1000);
			cout << " Du borde nog gömma dig. Vart vill du gå ? " << endl;
			Sleep(1000);
			spelet();
			lakeTakeOne = false;
			break;
		}
		default:
			cout << " Försök igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
			
		}


	} while (lakeTakeOne);
}

void game::LakeTake2()
{
	do {
	cout << " På andra sidan sjön ligger det små tygpåsar med mat på gräset" << endl;
	cout << " Du är hungrig.. Vill du försöka ta en påse?" << endl;
	cout << "\n [1] Ja, ta en påse och spring \n [2] Jag vågar inte.. jag springer iväg\n ---> ";
	cin >> svarUnderProgress;

	switch (svarUnderProgress)
	{
	case '1':
	{
		srand(time(NULL));
		int mat = rand() % 3;

		if (mat < 1)
		{
			mat1 = "en klase bananer";
		}
		else if (mat > 0 && mat < 2)
		{
			mat1 = "3 äpplen";
		}
		else
		{
			mat1 = "5 apelsiner";
		}
		cout << "\n Bra jobbat, du fick tag på en tygpåse utan att någon såg dig!! " << endl;
		cout << " Din påse innehöll " << mat1 << ". Du var så hungrig att du åt det direkt. + 50hp" << endl;
		hp = hp + 50;

		HpKollen();
		cout << " HP = " << hp << endl;
		Sleep(1000);
		cout << " Pssst.. ";
		Sleep(1000);
		cout << " Du borde nog gömma dig. Vart vill du gå ? " << endl;
		spelet();
		lakeTakeTwo = false;
		break;
	}
	case '2':
	{
		cout << " Din fegis..";
		Sleep(1000);
		cout << "\n Vart springer du ? " << endl;
		spelet();
		lakeTakeTwo = false;
		break;
	}
	default:
		cout << " Försök igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
		
	}

	} while (lakeTakeTwo);
}


// FOREST - Alla loopar OK

void game::placeForest() {

	
do {
	cout << "\n Du har nu kommit en bit in i skogen.\n Du hör något som rör sig, det är en bit framför dig.\n";
		cout << "\n [1] gå fram och se vad det är\n [2] Göm dig bakom en sten\n\n ---> ";
	cin >> svarForest1;

		switch (svarForest1)
		{
		case look:
		{
			forestLook();
			forestSpel = false;
			break;
		}

		case hide:
		{
			forestHide();
			forestSpel = false;
			break;
		}
		default:
			cout << " Försök igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
			

		}
	} while (forestSpel);
} 

void game::forestLook()
{
	

	do {
	cout << "\n Du går fram en bit.. lite till.." << "Det var en människa! Vad gör nu nu?\n";
	cout << "\n [1] Använd ditt vapen [ " << weapon << " ]"<< "\n [2] Spring till bergen\n\n ---> ";
	cin >> svarForest2;

	switch (svarForest2)
	{
	case fight:
	{
		forestFight();
		forestLookSpel = false;
		break;
	}
	case run:
	{
		placeMountains();
		forestLookSpel = false;
		break;
	}
	default:
		cout << " Försök igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
		

	}
	} while (forestLookSpel);
} 

void game::forestHide()
{
	

	do {
	cout << "\n Du har gömt dig (Under konstruktion)\n";
	cout << " 1 Gå till bergen\n 2 Gå till sjön ";
	cin >> svarUnderProgress;
	switch (svarUnderProgress)
	{
	case '1':
	{
		placeMountains();
		forestHideSpel = false;
		break;
	}
	case '2':
	{
		placeLake();
		forestHideSpel = false;
		break;
	}

	default:
		cout << " Försök igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;	
	}
	
	} while (forestHideSpel);
}

void game::forestFight()
{

	if (weapon == "pilbåge" || weapon == "yxa")
	{
		cout << "\n Bra jobbat! Du klarade dig och dödade en motståndare." << endl;
		kills = kills + 1;
		hp = hp - 40;
		cout << " Men du blev skadad.." << endl;
		cout << " Kills = " << kills << endl;
		cout << " HP = " << hp << endl;
		cout << " Du borde gömma dig.. \n Vart springer du nu? " << endl;
		spelet();

	}
	else
		cout << "\n Du borde nog hitta ett vapen först.. SPRING!\n" << endl;
		spelet();

}

// INVENTORY
void game::inventoryList() {
	cout << "--------------------------------" << "\n Bag:\n" << "--------------------------------" << endl;
	cout << " HP: " << setw(10) << hp << " / 100\n" << endl;
	cout << " Weapon: " << setw(10) << weapon <<endl;
	cout << " Kills: " << setw(10) << kills  << endl;
	cout << "--------------------------------" << endl << endl;

}

void game::HpKollen(){

	if (hp > 100)
	{
		while (hp > 100)
		{
		hp = hp - 1;
		}
	}

}


game::game()
{
}


game::~game()
{
}
