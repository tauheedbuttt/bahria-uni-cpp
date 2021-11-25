#include "stdafx.h"
#include "Member.h"
#include "Name.h"
#include "Date.h"
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

Member::Member(){ 
	ID = 0; fees = 0;
}
Member::Member(Name n, int ID, int fees, Date registration){
	setName(n); setID(ID);
	setRegistration(registration);
	setFees(fees);
	setLastDate(registration);
}
void Member::setName(Name n){ this->n = n; }
void Member::setID(int ID){ this->ID = (ID>0) ? ID : 0; }
void Member::setRegistration(Date registration){ this->registration = registration; }
void Member::setLastDate(Date last){ 
	this->last = last;
	Date temp = last;
	if (temp.getMonth() + 1>12){
		temp.setYear(temp.getYear() + 1);
		temp.setMonth(1);
		setDueDate(temp);
	}
	else{
		temp.setMonth(temp.getMonth() + 1);
		setDueDate(temp);
	}
}
void Member::setDueDate(Date due){ this->due = due; }
void Member::setFees(int fees){ this->fees = (fees>0) ? fees : 0; }
void Member::setPassword(int password)
{
	this->password = (password > 0) ? password : 0;
}
Name Member::getName(){ return n; }
int Member::getID(){ return ID; }
int Member::getFees(){ return fees; }
int Member::getPassword(){ return password; }
Date Member::getRegistration(){ return registration; }
Date Member::getLastDate(){ return last; }
Date Member::getDueDate(){ return due; }
void Member::print(){
	cout << ID << "\t";
	n.print(); cout << "\t";
	cout << fees << "\t";
	registration.print(); cout << "\t";
	due.print(); cout << "\t";
	last.print();
}
