#pragma once
#include "Name.h"
#include "Date.h"
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class Member{
protected:
	Date registration;
	Date due;
	Date last;
	int fees;
	Name n;
	int ID;
	int password;
public:
	Member();
	Member(Name, int, int, Date);
	void setName(Name);
	void setID(int);
	void setRegistration(Date);
	void setLastDate(Date);
	void setDueDate(Date);
	void setFees(int);
	void setPassword(int);
	Name getName();
	int getID();
	int getFees();
	int getPassword();
	Date getRegistration();
	Date getLastDate();
	Date getDueDate();
	virtual void print();
	virtual bool login(int ID, int password) = 0;
	virtual void signUp(Name n, int ID, int password, int fees, Date registration){}
	virtual void signUp(Name n, int ID, int password, int fees, int wallet, Date registration){}
	virtual void write() = 0;
	virtual void setWallet(int wallet){}
};


