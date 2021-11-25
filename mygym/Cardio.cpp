#include "stdafx.h"
#include "Cardio.h"



Cardio::Cardio(){
	treadmill = 0;
	sitCycle = 0;
	standCycle = 0;
	ID = "Cardio";
}
Cardio::Cardio(int treadmill, int sitCycle, int standCycle)
{
	setTreadmill(treadmill);
	setSitCycle(sitCycle);
	setStandCycle(standCycle);
}
void Cardio::setTreadmill(int treadmill)
{
	this->treadmill = (treadmill>0) ? treadmill : 0;
}
void Cardio::setSitCycle(int sitCycle)
{
	this->sitCycle = (sitCycle>0) ? sitCycle : 0;
}
void Cardio::setStandCycle(int standCycle)
{
	this->standCycle = (standCycle>0) ? standCycle : 0;
}
int Cardio::getTreadmill(){ return treadmill; }
int Cardio::getSitCycle(){ return sitCycle; }
int Cardio::getStandCycle(){ return standCycle; }
void Cardio::print(){
	cout << treadmill << "\t";
	cout << sitCycle << "\t";
	cout << standCycle << "\t";
}
bool Cardio::operator==(Cardio cardio)
{
	if (treadmill == cardio.getTreadmill() && sitCycle == cardio.getSitCycle() && standCycle == cardio.getStandCycle())
		return true;
	else
		return false;
}
