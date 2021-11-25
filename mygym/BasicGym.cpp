#include "stdafx.h"
#include "BasicGym.h"


float BasicGym::bmi(int height, int weight)
{
	float result;
	result = weight / height;
	if (result <= 18)
		cout << "You Need to gain weight\n";
	if (result >= 18 && result <= 24)
		cout << "Athelete!\n";
	if (result >= 25 && result <= 29)
		cout << "You are fit!\n";
	if (result >= 30 && result <= 39)
		cout << "You Need to loose weight\n";
	if (result >= 39)
		cout << "Obese\n";
	return result;
}
void BasicGym::macros(int height, int weight, int age)
{
	int calories, carbs, protien, fat;
	calories = (10 * weight) + (6.25*height) - ((5 * age) - 5);
	carbs = (calories*0.4) / 4;
	protien = (calories*0.3) / 4;
	fat = (calories*0.3) / 9;
	cout << "Calories\tCarbs\tProtien\tFat\n";
	cout << calories << "\t\t" << carbs << "\t" << protien << "\t" << fat << "\n";
}
