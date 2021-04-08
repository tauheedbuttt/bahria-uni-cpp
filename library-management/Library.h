#pragma once
#include "Book.h"
#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

class Library{
	protected:
		Book B[];
		Student S[];
		string section;
	public:
		Library();
		Library(string,Student,Book);
		void setBook(Book);
		void setStudent(Student);
		void setSection();
		Book[] getBook();
		Student[] getStudent();
		string getSection();
};

