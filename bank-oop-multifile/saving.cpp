#include "stdafx.h"
#include "saving.h"


int saving::credit(int a)
{
	balance += (a > 0) ? a : 0;
	return balance;
}
int saving::debit(int a)
{
	balance -= (a > 0 && a < balance) ? a : 0;
	return balance;
}
float saving::interest(float k)
{
	float temp=balance*(k/100);
	balance+=temp;
	return temp;
}
saving saving::operator--()
{
	saving temp;
	temp.name=name;
	temp.acc=acc;
	balance*=0.025;
	temp.balance=balance;
	return temp;
}
void saving::print()
{
	account::print();
	cout<<"\tSaving";)
}