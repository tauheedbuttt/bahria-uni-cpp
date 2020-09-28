#pragma once
#include "account.h"
#include <iostream>
#include <string>
using namespace std;
class saving:public account{
protected:
	static const int minimum;
public:
	saving(){}
	saving(int a, string b, int c) :account(a, b, (c>minimum)?c:0){}
	int credit(int);
	int debit(int);
};
const int saving::minimum = 100000;

