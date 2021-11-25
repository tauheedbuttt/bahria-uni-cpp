#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class Name{
protected:
	string first;
	string last;
public:
	Name(){}
	Name(string ,string);
	void setName(string, string);
	void setFirst(string);
	void setLast(string);
	string getFirst();
	string getLast();
	void print();
};



