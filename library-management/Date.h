#pragma once
class Date{
	protected:
		int month;
		int day;
		int year;
	public:
		Date();
		Date(int,int,int);
		void setMonth(int);
		void setDay(int);
		void setYear(int);
		int getMonth();
		int getDay();
		int getYear();
		void print();
};


