#include "stdafx.h"
#include "Leg.h"
#include"ID.h"
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;


Leg::Leg(){
	SquatRack = 0;
	LegPress = 0;
	LegCurl = 0;
	ID = "Leg";
}
Leg::Leg(int SquatRack, int LegPress, int LegCurl)
{
	setSquatRack(SquatRack);
	setLegPress(LegPress);
	setLegCurl(LegCurl);
}
void Leg::setLegCurl(int LegCurl)
{
	this->LegCurl = (LegCurl>0) ? LegCurl : 0;
}
void Leg::setLegPress(int LegPress)
{
	this->LegPress = (LegPress>0) ? LegPress : 0;
}
void Leg::setSquatRack(int SquatRack)
{
	this->SquatRack = (SquatRack>0) ? SquatRack : 0;
}
int Leg::getLegCurl(){ return LegCurl; }
int Leg::getLegPress(){ return LegPress; }
int Leg::getSquatRack(){ return SquatRack; }
void Leg::print(){
	cout << SquatRack << "\t";
	cout << LegPress << "\t";
	cout << LegCurl << "\t";
}
bool Leg::operator==(Leg leg)
{
	if (SquatRack == leg.getSquatRack() && LegPress == leg.getLegPress() && LegCurl == leg.getLegCurl())
		return true;
	else
		return false;
}
