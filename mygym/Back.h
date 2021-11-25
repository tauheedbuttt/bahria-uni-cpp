#pragma once
#include"ID.h"
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

class Back :public id
{
protected:
	int LatPullDown;
	int TBarRow;
	int MachineRow;
public:
	friend istream& operator>>(istream& s, Back& n);
	Back();
	Back(int, int, int);
	void setLatPullDown(int);
	void setTBarRow(int);
	void setMachineRow(int);
	int getLatPullDown();
	int getTBarRow();
	int getMachineRow();
	void print();
	bool operator==(Back);
	friend ostream& operator<<(ostream& s, Back& b);
};




