#include "stdafx.h"
#include "StandardMember.h"
#include "Name.h"
#include "Date.h"
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

StandardMember::StandardMember(Name n, int ID, int fees, Date registration) :Member(n, ID, fees, registration){}
void StandardMember::write()
{
	ofstream f("StandardM.dat", ios::binary || ios::app);
	f.write((char*)this, sizeof(*this));
	f.close();
}
bool StandardMember::login(int ID, int password)
{
	StandardMember temp; bool flag;
	ifstream f("StandardM.dat", ios::binary);
	//Counting objects in file
	f.seekg(0, ios::end);
	int len = f.tellg() / sizeof(StandardMember);
	f.seekg(0, ios::beg);
	for (int i = 0; i<len; i++)
	{
		f.read((char*)&temp, sizeof(temp));
		if (temp.getID() == ID)
		{
			if (temp.getPassword() == password)
			{
				flag = true; f.close(); break;
			}
			else flag = false;
		}
		else flag = false;
	}
	return flag;
}
void StandardMember::signUp(Name n, int ID, int password, int fees, Date registration)
{
	ofstream f("StandardM.dat", ios::binary | ios::app);
	setName(n);
	setID(ID); setPassword(password);
	setFees(fees);
	setRegistration(registration);
	setLastDate(registration);
	Date temp = last;
	if (temp.getMonth() + 1>12){
		temp.setYear(temp.getYear() + 1);
		temp.setMonth(1);
		setDueDate(temp);
	}
	else{
		temp.setMonth(temp.getMonth() + 1);
		setDueDate(temp);
	}
	f.write((char*)this, sizeof(*this));
	f.close();
}
void StandardMember::print()
{
	Member::print();
	cout << "\t" << type;
}
