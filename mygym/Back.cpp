#include "stdafx.h"
#include "Back.h"
#include"ID.h"
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;


Back::Back(){
	LatPullDown = 0;
	TBarRow = 0;
	MachineRow = 0;
	ID = "Back";
}
Back::Back(int LatPullDown, int TBarRow, int MachineRow)
{
	setLatPullDown(LatPullDown);
	setTBarRow(TBarRow);
	setMachineRow(MachineRow);
}
void Back::setLatPullDown(int LatPullDown)
{
	this->LatPullDown = (LatPullDown>0) ? LatPullDown : 0;
}
void Back::setTBarRow(int TBarRow)
{
	this->TBarRow = (TBarRow>0) ? TBarRow : 0;
}
void Back::setMachineRow(int MachineRow)
{
	this->MachineRow = (MachineRow>0) ? MachineRow : 0;
}
int Back::getLatPullDown(){ return LatPullDown; }
int Back::getTBarRow(){ return TBarRow; }
int Back::getMachineRow(){ return MachineRow; }
void Back::print(){
	cout << LatPullDown << "\t";
	cout << TBarRow << "\t";
	cout << MachineRow << "\t";
}
bool Back::operator==(Back back)
{
	if (LatPullDown == back.getLatPullDown() && TBarRow == back.getTBarRow() && MachineRow == back.getMachineRow())
		return true;
	else
		return false;
}
