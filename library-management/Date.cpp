#include "Date.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

Date::Date()
{
year = 0; month = 0; day = 0;
}
Date::Date(int a = 0, int b = 0, int c = 0)
{
setYear(c); setMonth(b); setDay(a);
}
void Date::setYear(int a)
{
year = a;
}
void Date::setMonth(int a)
{
month = (a > 0 && a <= 12) ? a : 0;
}
void Date::setDay(int a)
{
day = (a > 0 && a <= 31) ? a : 0;
}
int Date::getYear()
{
return year;
}
int Date::getMonth()
{
return month;
}
int Date::getDay()
{
return day;
}
void Date::print()
{
	cout<<day<<"/"<<month<<"/"<<year;
}
