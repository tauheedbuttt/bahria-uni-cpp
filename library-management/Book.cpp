#include "Book.h"
#include "Date.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

Book::Book()
{
	Date temp(0,0,0);
	setTitle(" "); setAurthor(" ");
	setIssueDate(temp); setReturnDate(temp);
	setGenre(" ");
}
Book::Book(string a,string b,Date c,Date d,string e)
{
	setTitle(a); setAurthor(b);
	setIssueDate(c); setReturnDate(d);
	setGenre(e);
}
void Book::setTitle(string a)
{
	titleName=a;
}
void Book::setAurthor(string a)
{
	aurthorName=a;
}
void Book::setIssueDate(Date a)
{
	issueDate=a
}
void Book::setReturnDate(Date a)
{
	returnDate=a;
}
void Book::setGenre(string a)
{
	genre=a;
}
void Book::setIssueCount(int a)
{
	issuedCount=(a>0)?a:0;
}
string Book::getTitle()
{
	return titleName;
}
string Book::getAurthor()
{
	return aurthorName;
}
Date Book::getIssueDate()
{
	return issueDate;
}
Date Book::getReturnDate()
{
	return returnDate;
}
string Book::getGenre()
{
	return genre;
}
int Book::getIssueCount()
{
	return issuedCount;
}
string Book::rating()
{
	if(issueCount>=10)
	{
		return "*;
	}
	else if(issueCount>10&&issueCount<=20)
	{
		return "**";
	}
	else if(issueCount>20&&issueCount<=30)
	{
		return "***";
	}
	else if(issueCount>30&&issueCount<=40)
	{
		return "****";
	}
	else if(issueCount>40)
	{
		return "*****";
	}
}
void Book::print()
{
	cout<<titleName<<", by"<<aurthorName;
	cout<<"\nRated: "<<rating();
	cout<<"\nLasr Issued: "<<issueDate;
	cout<<"\nLast Returned: "<<returnDate;
	cout<<"\nGenre: "<<genre;
}
