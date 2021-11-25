#include "stdafx.h"
#include "Date.h"
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

Date::Date(int day, int month, int year){ setDate(day, month, year); }
void Date::setDate(int day, int month, int year)
{
	setDay(day); setMonth(month); setYear(year);
}
void Date::setDay(int day){
	this->day = (day>0 && day <= 31) ? day : 0;
}
void Date::setMonth(int month){
	this->month = (month>0 && month <= 12) ? month : 0;
}
void Date::setYear(int year){
	this->year = (year>0) ? year : 0;
}
int Date::getDay(){ return this->day; }
int Date::getMonth(){ return this->month; }
int Date::getYear(){ return this->year; }
void Date::print(){
	cout << this->day << "/";
	cout << this->month << "/";
	cout << this->year;
}
