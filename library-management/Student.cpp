#include "Student.h"
#include "Date.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

Student::Student()
{
	Date temp(0,0,0);
	setName(" ");setID(0);setDob(temp);
}
Student::Student(string a, Date b, int c)
{
	setName(a); setDob(b); setID(c);
}
void Student::setName(string a)
{
	name=a;	
}
void Student::setDob(Date a)
{
	dob=a;
}
void Student::setID(int a)
{
	ID=a;
}
string Student::getName()
{
	return name;
}
Date Student::getDob()
{
	return dob;
}
int Student::getID()
{
	return ID;
}
void Student::print()
{
	cout<<"Name: "<<name<<endl;
	cout<<"Date of Birth: "; dob.print();
	cout<<"\nID: "<<ID<<endl;
}


