#include "stdafx.h"
#include "Machine.h"
#include "Chest.h"
#include "Back.h"
#include "Leg.h"
#include "Cardio.h"
#include"ID.h"
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;


Machines::Machines(Chest chest, Leg leg, Back back, Cardio cardio){
	setChest(chest);
	setLeg(leg);
	setCardio(cardio);
	setBack(back);
}
void Machines::setChest(Chest chest){ this->chest = chest; }
void Machines::setLeg(Leg leg){ this->leg = leg; }
void Machines::setBack(Back back){ this->back = back; }
void Machines::setCardio(Cardio cardio){ this->cardio = cardio; }
Chest Machines::getChest(){ return chest; }
Leg Machines::getLeg(){ return leg; }
Back Machines::getBack(){ return back; }
Cardio Machines::getCardio(){ return cardio; }
void Machines::write(){
	ofstream f("Machines.data", ios::binary | ios::trunc);
	f.write((char*)this, sizeof(*this));
	f.close();
}
bool Machines::check(){
	ifstream f("Machines.data");
	f.seekg(0, ios::end); int len = f.tellg() / sizeof(Machines); f.seekg(0, ios::beg);
	Machines temp;
	bool flag;
	Chest chest;
	for (int i = 0; i<len; i++)
	{
		f.read((char*)&temp, sizeof(Machines));
		if (temp.getChest() == this->chest&&temp.getLeg() == this->leg&&temp.getBack() == this->back&&temp.getCardio() == this->cardio)
		{
			flag = true; f.close(); break;
		}
		else flag = false;
	}
	return flag;
}
void Machines::print()
{
	cout << "BenchPress\tCrossCable\tMachinePress\n";
	cout << chest << endl;
	cout << "LatPullDown\tTBarRow\tMachineRow\n";
	cout << back << endl;
	cout << "SquatRack\tLegPress\tLegCurl\n";
	cout << leg << endl;
	cout << "Treadmill\tSitCycle\tStandCycle\n";
	cout << cardio << endl;
}



