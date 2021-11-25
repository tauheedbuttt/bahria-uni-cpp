#pragma once
#include"ID.h"
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

class Chest :public id
{
protected:
	int benchPress;
	int crossCable;
	int machinePress;
public:
	Chest();
	Chest(int, int, int);
	void setBenchPress(int);
	void setCrossCable(int);
	void setMachinePress(int);
	int getBenchPress();
	int getCrossCable();
	int getMachinePress();
	void print();
	bool operator==(Chest chest);
	friend istream& operator>>(istream& s, Chest& c);
	friend ostream& operator<<(ostream& s, Chest& c);
};




