#pragma once
#include "Member.h"
#include "Name.h"
#include "Date.h"
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

class PremiumMember :public Member{
protected:
	string type;
	int wallet;
public:
	PremiumMember();
	PremiumMember(Name, int, int, Date);
	void setWallet(int);
	int getWallet();
	void write();
	bool login(int, int);
	void signUp(Name, int, int, int,int, Date);
	void print();
};

