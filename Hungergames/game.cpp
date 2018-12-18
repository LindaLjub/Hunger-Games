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
			cout << "\n Du blev skadad och hade inte tillr�ckligt med hp, du dog.\n GAME OVER! \n\n" << endl;
			spel = false;

		}
		else if (kills == 3)
		{
			cout << "\n Du har nu d�dat 3 motst�ndare, GRATTIS!! DU VANN SPELET! \n\n" << endl;
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

		cout << endl << " [1] --> SKOGEN\n" << " [2] --> SJ�N\n" << " [3] --> BERGEN\n" << endl << " [4] --> INVENTORY\n" << " [5] --> EXIT GAME\n" << endl;
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
				cout << "F�rs�k igen.. TIPS, skriv en siffra mellan 1-5" << endl;

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
	cout << "\n Du �r h�gt uppe i bergen, du st�r oskyddad.\n G�m dig n�gonstans!\n " << endl;
	cout << " [1] G� in i grottan norr om dig \n [2] G� in i grottan s�der om dig\n [3] G� tillbaka till start\n\n ---> " << endl << endl;
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
		cout << " F�rs�k igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
	}

	} while (mountainSpel);
}

void game::northCavePlace()
{
	do {
	cout << " Du �r inne i den norra grottan.. det �r m�rkt och kallt.\n Vill du g� l�ngre in?\n" << endl;
	cout << " [1] Ja, g� l�ngre in\n [2] Nej, stanna h�r\n\n ---> ";
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
		cout << " F�rs�k igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
		
	}
	} while (mountainCaveNorth);

}

void game::goInNorthCave()
{
	do {
	cout << " L�ngre in i grottan hittar du en �ppning som ser ut att g� till sj�n (Under konstruktion)" << endl;
	cout << " [1] G� l�ngre in, till sj�n\n [2] G� tillbaka till bergen\n ---> ";
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
		cout << " F�rs�k igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;

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
		hinder1 = "Bj�rn";
	}
	else
	{
		hinder1 = "M�nniska";
	}

	cout << " Du stannar kvar..\n du somnar.. Zzz.. Zz.. \n Pl�tsligt dyker det upp en " << hinder1 << "!! Vad g�r du?? " << endl;
	cout << "\n [1] Anv�nd ditt vapen [ " << weapon << " ]" << "\n [2] Spring till sj�n\n ---> ";
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
		cout << " F�rs�k igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
		
	}

	} while (mountainStayNorthCave);

}

void game::northCaveFight()
{

	if (weapon == "pilb�ge" || weapon == "yxa")
	{
		if (hinder1 == "Bj�rn" || hinder1 == "Varg")
		{ 
			cout << "\n Bra jobbat! Du klarade dig och d�dade " << hinder1  << "en "<< endl;
			hp = hp - 40;

		}
		else if (hinder1 == "M�nniska")
		{
			cout << "\n Bra jobbat! Du klarade dig och d�dade en motst�ndare! "<< endl;
			kills = kills + 1;
			hp = hp - 40;
			cout << " Kills = " << kills << endl;

		}

		cout << " Men du blev skadad.." << endl;
		cout << " HP = " << hp << endl;
		cout << " Du borde g�mma dig.. \n Vart springer du nu? " << endl;
		spelet();
	}
	else
	{
		cout << "\n Du borde nog hitta ett vapen f�rst.. SPRING N�GONSTANS!\n" << endl;
		spelet();
	}

}

void game::southCavePlace()
{
	do {

		cout << " Du �r inne i den s�dra grottan.. h�r �r det varmt och sk�nt.\n Du kanske ska passa p� att sova lite?\n" << endl;
		cout << " [1] Ja, sov en stund och �terh�mta dig\n [2] Nej, var vaken\n\n ---> ";
		cin >> svarSouthCave;

		switch (svarSouthCave)
		{
		case sleep:
		{
			cout << " Zzzz... zz.. ZZz.." << endl;
			cout << " Du �r nu utvilad och pigg! + 20hp <3 " << endl;
			hp = hp + 20;
			HpKollen();
			cout << " HP = " << hp << endl;
			tunnelPlace();
			mountainCaveSouth = false;
			break;
		}
		case notSleep:
		{
			cout << " Ok, gl�m inte att vila ibland.." << endl;
			tunnelPlace();
			mountainCaveSouth = false;
			break;
		}
		default:
			cout << " F�rs�k igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;

		}
	} while (mountainCaveSouth);
}

void game::tunnelPlace()
{
	do {
		cout << " Det ser ut att finnas en tunnel till den norra grottan lite l�ngre in\n" << endl;
		cout << " [1] G� in i tunneln \n [2] G� tillbaka till bergen\n ---> ";
		cin >> svarSleep;
		switch (svarSleep)
		{
		case goTunnel:
		{
			cout << " Du �r n�gra meter in i tunneln\n H�r b�rjar det bli kallare och kallare\n Du n�rmar dig den norra grottan" << endl;
			cout << " Du ser in i den norra grottan, du g�r in.. (Under konstruktion)\n " << endl;
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
			cout << " F�rs�k igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
			

		}
	} while (mountainSouthTunnel);
}

// LAKE
void game::placeLake() 
{	
	do {
	cout << "\n Du st�r n�gon meter fr�n sj�n, inga faror i sikte. " << endl; 
	cout << " [1] Stanna kvar p� denna sidan av sj�n \n [2] G� till andra sidan\n---> ";
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
		cout << " F�rs�k igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
	
	}
	} while (lakeSpel);

}

void game::LakeTake1()
{
	do {
		cout << " Det ligger en n�got nere vid sj�kanten, vill du ta n�got?" << endl;
		cout << "\n\n [1] Ta pilb�ge \n [2] Ta yxa\n [3] G�r ingenting\n\n ---> ";
		cin >> svarLake1;

		
		switch (svarLake1)
		{
		case vapen1:
		{
			weapon = "pilb�ge";
			cout << " Bra val! Den ligger i din inventory." << endl;
			Sleep(1000);
			cout << " Pssst.. ";
			Sleep(1000);
			cout << " Du borde nog g�mma dig. Vart vill du g� ? " << endl;
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
			cout << " Du borde nog g�mma dig. Vart vill du g� ? " << endl;
			Sleep(1000);
			spelet();
			lakeTakeOne = false;
			break;

		}
		case nothing:
		{
			cout << " Ok, skyll dig sj�lv" << endl;
			Sleep(1000);
			cout << " Pssst.. ";
			Sleep(1000);
			cout << " Du borde nog g�mma dig. Vart vill du g� ? " << endl;
			Sleep(1000);
			spelet();
			lakeTakeOne = false;
			break;
		}
		default:
			cout << " F�rs�k igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
			
		}


	} while (lakeTakeOne);
}

void game::LakeTake2()
{
	do {
	cout << " P� andra sidan sj�n ligger det sm� tygp�sar med mat p� gr�set" << endl;
	cout << " Du �r hungrig.. Vill du f�rs�ka ta en p�se?" << endl;
	cout << "\n [1] Ja, ta en p�se och spring \n [2] Jag v�gar inte.. jag springer iv�g\n ---> ";
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
			mat1 = "3 �pplen";
		}
		else
		{
			mat1 = "5 apelsiner";
		}
		cout << "\n Bra jobbat, du fick tag p� en tygp�se utan att n�gon s�g dig!! " << endl;
		cout << " Din p�se inneh�ll " << mat1 << ". Du var s� hungrig att du �t det direkt. + 50hp" << endl;
		hp = hp + 50;

		HpKollen();
		cout << " HP = " << hp << endl;
		Sleep(1000);
		cout << " Pssst.. ";
		Sleep(1000);
		cout << " Du borde nog g�mma dig. Vart vill du g� ? " << endl;
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
		cout << " F�rs�k igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
		
	}

	} while (lakeTakeTwo);
}


// FOREST - Alla loopar OK

void game::placeForest() {

	
do {
	cout << "\n Du har nu kommit en bit in i skogen.\n Du h�r n�got som r�r sig, det �r en bit framf�r dig.\n";
		cout << "\n [1] g� fram och se vad det �r\n [2] G�m dig bakom en sten\n\n ---> ";
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
			cout << " F�rs�k igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
			

		}
	} while (forestSpel);
} 

void game::forestLook()
{
	

	do {
	cout << "\n Du g�r fram en bit.. lite till.." << "Det var en m�nniska! Vad g�r nu nu?\n";
	cout << "\n [1] Anv�nd ditt vapen [ " << weapon << " ]"<< "\n [2] Spring till bergen\n\n ---> ";
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
		cout << " F�rs�k igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;
		

	}
	} while (forestLookSpel);
} 

void game::forestHide()
{
	

	do {
	cout << "\n Du har g�mt dig (Under konstruktion)\n";
	cout << " 1 G� till bergen\n 2 G� till sj�n ";
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
		cout << " F�rs�k igen..TIPS, skriv en siffra mellan 1 - 2\n" << endl;	
	}
	
	} while (forestHideSpel);
}

void game::forestFight()
{

	if (weapon == "pilb�ge" || weapon == "yxa")
	{
		cout << "\n Bra jobbat! Du klarade dig och d�dade en motst�ndare." << endl;
		kills = kills + 1;
		hp = hp - 40;
		cout << " Men du blev skadad.." << endl;
		cout << " Kills = " << kills << endl;
		cout << " HP = " << hp << endl;
		cout << " Du borde g�mma dig.. \n Vart springer du nu? " << endl;
		spelet();

	}
	else
		cout << "\n Du borde nog hitta ett vapen f�rst.. SPRING!\n" << endl;
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
