#include "stdafx.h"
#include "Name.h"
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

Name::Name(string first, string){setName(first, last);}
void Name::setName(string first, string last){setFirst(first); setLast(last);}
void Name::setFirst(string first){ this->first = first; }
void Name::setLast(string last){ this->last = last; }
string Name::getFirst(){ return this->first; }
string Name::getLast(){ return this->last; }
void Name::print(){
	cout << this->first << " ";
	cout << this->last;
}
