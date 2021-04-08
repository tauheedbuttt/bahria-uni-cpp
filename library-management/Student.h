#pragma once
#include "Date.h"
#include <string>
class Student{
	protected:
		string name;
		Date dob;
		int ID;
	public:
		Student();
		Student(string,Date,int);
		void setName(string);
		void setDob(Date);
		void setID(int);
		string getName();
		Date getDob();
		int getID();
		void print();
}; 


