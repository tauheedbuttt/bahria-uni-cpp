#pragma once
#include "Member.h"
#include "Name.h"
#include "Date.h"
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class StandardMember :public Member{
protected:
	string type;
public:
	StandardMember(){}
	StandardMember(Name, int, int, Date);
	void write();
	bool login(int, int);
	void signUp(Name, int, int, int, Date);
	void print();
};


