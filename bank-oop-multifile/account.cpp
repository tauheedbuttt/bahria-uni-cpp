#include "stdafx.h"
#include "account.h"


account::account()
{
	setAcc(0);
	setName(" ");
	setBal(0);
}
account::account(int a, string b, int c)
{
	setAcc(a);
	setName(b);
	setBal(c);
}
void account::setAcc(int a){ acc = a; }
void account::setBal(int a){ balance = a; }
void account::setName(string a){ name = a; }
int account::getAcc(){ return acc; }
int account::getBal(){ return balance; }
string account::getName(){ return name; }
void account::print()
{
	cout << acc << "\t";
	cout << name << "\t";
	cout << balance << "\t";
}
