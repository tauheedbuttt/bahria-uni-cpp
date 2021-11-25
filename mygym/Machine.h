#pragma once
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


class Machines{
protected:
	Chest chest;
	Leg leg;
	Cardio cardio;
	Back back;
public:
	Machines(){}
	Machines(Chest, Leg, Back, Cardio);
	void setChest(Chest);
	void setLeg(Leg);
	void setBack(Back);
	void setCardio(Cardio);
	Chest getChest();
	Leg getLeg();
	Back getBack();
	Cardio getCardio();
	void write();
	bool check();
	void print();
};


