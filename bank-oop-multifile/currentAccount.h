#pragma once
#include "account.h"
#include <iostream>
#include <string>
using namespace std;
class current :public account{
public:
	current(){}
	current(int a, string b, int c) :account(a, b, c){}
	int credit(int);
	int debit(int);
};
