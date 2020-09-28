#pragma once
#include <iostream>
#include <string>
using namespace std;
class account{
protected:
	int acc;
	int balance;
	string name;
public:
	account();
	account(int, string, int);
	void setYear(int);
	void setAcc(int);
	void setBal(int);
	void setName(string);
	int getAcc();
	int getBal();
	string getName();
	void print();
	virtual int credit(int) = 0{}
	virtual int debit(int) = 0{}
};