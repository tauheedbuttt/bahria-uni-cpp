#pragma once
#include"ID.h"
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

class Cardio : public id
{
protected:
	int treadmill;
	int sitCycle;
	int standCycle;

public:
	friend istream& operator>>(istream& s, Cardio& c);
	Cardio();
	Cardio(int, int, int);
	void setTreadmill(int);
	void setSitCycle(int);
	void setStandCycle(int);
	int getTreadmill();
	int getSitCycle();
	int getStandCycle();
	void print();
	bool operator==(Cardio);
	friend istream& operator>>(istream& s, Cardio& c);
	friend ostream& operator<<(ostream& s, Cardio& c);
};


