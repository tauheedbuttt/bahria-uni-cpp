#pragma once
#include "Date.h"
#include <string>
class Book{
	protected:
		string titleName;
		string aurthorName;
		Date issueDate;
		Date returnDate;
		string genre;
		int issueCount;
	public:
		Book();
		Book(string,string,Date,Date,string);
		void setTitle(string);
		void setAurthor(string);
		void setIssueDate(Date);
		void setReturnDate(Date);
		void setGenre(string);
		void setIssueCount(int);
		string getTitle();
		string getAurthor();
		Date getIssueDate();
		Date getReturnDate();
		string getGenre();
		int getIssueCount();
		
		string rating();
		void print();
};
