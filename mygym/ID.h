#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

class id{
protected:
	string ID;
public:
	id(){ ID = " "; }
	id(string ID){ this->ID = ID; }
	void setID(string ID){ this->ID = ID; }
	string getID(){ return ID; }
	void print(){ cout << ID << "\t"; }
};



