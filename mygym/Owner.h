#pragma once
#include "Name.h"
#include "Date.h"
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class Owner
{
protected:
	Date joining;
	Name n;
	int ID;
	int password;

public:
	Owner()
	{
		ID = 0;
		password = 0;
	}
	Owner(Name n, int ID, Date joining)
	{
		setName(n);
		setID(ID);
		setJoining(joining);
	}
	void setName(Name n) { this->n = n; }
	void setID(int ID) { this->ID = (ID > 0) ? ID : 0; }
	void setJoining(Date joining) { this->joining = joining; }
	void setPassword(int password)
	{
		this->password = (password > 0) ? password : 0;
	}
	Name getName() { return n; }
	int getID() { return ID; }
	int getPassword() { return password; }
	Date getJoining() { return joining; }
	void signup(Name n, int ID, int password, Date joining)
	{
		setName(n);
		setID(ID);
		setPassword(password);
		setJoining(joining);
		ofstream f("Owner.dat", ios::app | ios::binary);
		f.write((char*)this, sizeof(*this));
		f.close();
	}
	bool login(int ID, int password)
	{
		Owner temp; bool flag;
		ifstream f("Owner.dat", ios::binary);
		//Counting objects in file
		f.seekg(0, ios::end);
		int len = f.tellg() / sizeof(Owner);
		f.seekg(0, ios::beg);
		for (int i = 0; i<len; i++)
		{
			f.read((char*)&temp, sizeof(temp));
			if (temp.getID() == ID)
			{
				if (temp.getPassword() == password)
				{
					flag = true;
					break;
				}
				else flag = false;
			}
			else flag = false;
		}
		cout << flag;
		f.close();
		return flag;
	}
	virtual void print()
	{
		cout << ID << "\t";
		n.print(); cout << "\t";
		joining.print(); cout << "\t";
	}
};






