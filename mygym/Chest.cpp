#include "stdafx.h"
#include "Chest.h"
#include"ID.h"
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;


Chest::Chest(){
	benchPress = 0;
	crossCable = 0;
	machinePress = 0;
	ID = "Chest";
}
Chest::Chest(int benchPress, int crossCable, int machinePress)
{
	setBenchPress(benchPress);
	setCrossCable(crossCable);
	setMachinePress(machinePress);

}
void Chest::setBenchPress(int benchPress)
{
	this->benchPress = (benchPress>0) ? benchPress : 0;
}
void Chest::setCrossCable(int crossCable)
{
	this->crossCable = (crossCable>0) ? crossCable : 0;
}
void Chest::setMachinePress(int machinePress)
{
	this->machinePress = (machinePress>0) ? machinePress : 0;
}
int Chest::getBenchPress(){ return benchPress; }
int Chest::getCrossCable(){ return crossCable; }
int Chest::getMachinePress(){ return machinePress; }
void Chest::print(){
	cout << benchPress << "\t";
	cout << crossCable << "\t";
	cout << machinePress << "\t";
}
bool Chest::operator==(Chest chest)
{
	if (benchPress == chest.getBenchPress() && crossCable == chest.getCrossCable() && machinePress == chest.getMachinePress())
		return true;
	else
		return false;
}

