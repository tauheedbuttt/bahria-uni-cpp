#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class Date{
protected:
	int day;
	int month;
	int year;
public:
	Date(){}
	Date(int, int, int);
	void setDate(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay();
	int getMonth();
	int getYear();
	void print();
};



