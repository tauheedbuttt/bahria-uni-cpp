#pragma once
#include"ID.h"
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

class Leg : public id
{
protected:
	int SquatRack;
	int LegPress;
	int LegCurl;
public:
	friend istream& operator>>(istream& s, Leg& l);
	Leg();
	Leg(int, int, int);
	void setLegCurl(int);
	void setLegPress(int);
	void setSquatRack(int);
	int getLegCurl();
	int getLegPress();
	int getSquatRack();
	void print();
	bool operator==(Leg); 
	friend ostream& operator<<(ostream& s, Leg& l);
};




