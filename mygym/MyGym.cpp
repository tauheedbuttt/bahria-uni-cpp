// MyGym.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ID.h"
#include "Name.h"
#include "Date.h"
#include "Chest.h"
#include "Back.h"
#include "Leg.h"
#include "Cardio.h"
#include "Machine.h"
#include "Member.h"
#include "StandardMember.h"
#include "PremiumMember.h"
#include "Owner.h"
#include "BasicGym.h"

#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

//Stream operators overloaded functions
ostream& operator<<(ostream &s, Date &d)
{
	d.print();
	return s;
}
ostream& operator<<(ostream &s, Name &n)
{
	n.print();
	return s;
}
istream& operator>>(istream& s, Chest& c){
	cout << "Enter (BenchPress CrossCable MachinePress): ";
	cin >> c.benchPress >> c.crossCable >> c.machinePress;
	return s;
}
istream& operator>>(istream& s, Back& b){
	cout << "Enter (LatPullDown MachineRow TBarRow): ";
	cin >> b.LatPullDown >> b.MachineRow >> b.TBarRow;
	return s;
}
istream& operator>>(istream& s, Leg& l){
	cout << "Enter (SquatRack LegCurl LegPress): ";
	cin >> l.SquatRack >> l.LegCurl >> l.LegPress;
	return s;
}
istream& operator>>(istream& s, Cardio& c){
	cout << "Enter (Treadmill StandCycle SitCycle): ";
	cin >> c.treadmill >> c.standCycle >> c.sitCycle;
	return s;
}
ostream& operator<<(ostream& s, Chest& c)
{
	c.print(); return s;
}

ostream& operator<<(ostream& s, Back& b)
{
	b.print(); return s;
}
ostream& operator<<(ostream& s, Leg& l)
{
	l.print(); return s;
}
ostream& operator<<(ostream& s, Cardio& c)
{
	c.print(); return s;
}
ostream& operator<<(ostream &s, Owner &o)
{
	o.print();
	return s;
}

int main()
{
	Member * m;
	Machines M;
	Owner O;
	BasicGym g;
	//^^^^Objects to be tested on
	bool flag;
	int wallet;
	char c, ch, choice;//variable for choice inputs
	int ID, password;
	string first, last;
	int day, month, year;
	int temp, fees;
	int height, weight, age;
	//^^^Variables to take input
	cout << "\t     MyGym\n\n";
	cout << "\t**************\n";
	cout << "\t*            *\n";
	cout << "\t* (1)Member  *\n";
	cout << "\t*            *\n";
	cout << "\t**************\n\n";
	cout << "\t**************\n";
	cout << "\t*            *\n";
	cout << "\t*  (2)Owner  *\n";
	cout << "\t*            *\n";
	cout << "\t**************\n";
	cout << "\t Enter Choice: ";
	c = _getch();
	system("CLS");
	//MEMBER k lie
	if (c == '1')
	{
		cout << "\t\t Chose Member Type \n";
		cout << "\t\tStandard or Premium\n";
		cout << "\t\t   (S/P): ";
		choice = _getch();
		//STANDARD MEMBER K LIE
		if (choice == 's' || choice == 'S')
		{
			m = new StandardMember;
			system("CLS");
			cout << "Login or Signup? (L/S): ";
			ch = _getch();
			system("CLS");
			if (ch == 'L' || ch == 'l')
			{
			Login2:
				cout << "\t*****Login*****\n";
				do{
					cout << "Enter ID: "; cin >> ID;
					cout << "Enter Password: "; cin >> password;
					flag = m->login(ID, password);
					if (flag != true){
						cout << "Couldn't Find ID!"; _getch();
						system("CLS");
					}
				} while (flag != true);
				cout << "Login Successfull"; _getch();
				system("CLS");
			}
			else if (ch == 'S' || ch == 's')
			{
				cout << "\t*****SignUp*****\n";
				cout << "First Name: "; cin >> first;
				cout << "Last Name: "; cin >> last;
				Name n(first, last);
				cout << "Enter ID: "; cin >> ID;
				do{
					cout << "Enter Password: "; cin >> password;
					cout << "Enter Again for Comfirmation: "; cin >> temp;
					if (temp != password){
						cout << "Password Didnt Match"; _getch();
						system("CLS");
					}
				} while (temp != password);
				cout << "Enter Fees (2000): "; cin >> fees;
				cout << "Enter Date(DD MM YYYY): "; cin >> day >> month >> year;
				Date registration(day, month, year);
				m->signUp(n, ID, password, fees, registration);
				cout << "SignUp Successful!"; _getch;
				system("CLS");
				goto Login2;
			}
			do{
				cout << "\t\tMenu\n";
				cout << "\t**(1)Macros**\n";
				cout << "\t**(2)BMI**\n";
				cout << "\t**(3)Fee Submit**\n";
				cout << "\t**(4)Workout Ideas**\n";
				cout << "\t**(q)Quit Menu**\n";
				cout << "\t\tEnter: "; ch = _getch();
				if (ch == '1')
				{
					cout << "\nEnter (Height(cm) Weight(Kg) Age(Y)): ";
					cin >> height >> weight >> age;
					g.macros(height, weight, age);
					_getch();
					system("CLS");
				}
				else if (ch == '2')
				{
					cout << "\nEnter (Height(M) Weight(Kg)): ";
					cin >> height >> weight;
					g.bmi(height, weight);
					_getch();
					system("CLS");
				}
				else if (ch == '3')
				{
					cout << "Enter Todays Date (DD MM YYYY): ";
					cin >> day >> month >> year;
					Date last(day, month, year);
					m->setLastDate(last);
					m->write();
					_getch();
					system("CLS");
				}
				else if (ch == '4')
				{
					cout << "\nBro Workout(Single Muscle EveryDay\n";
					cout << "PushPull Workout(6 days a week, PushPullLegPushPullLeg)\n";
					cout << "Full Body Workout(3 days rest, 3 days workout)\n";
					_getch();
					system("CLS");
				}
			} while (ch != 'q');
		}
		//PREMIUM MEMBER K LIE
		else if (choice == 'p' || choice == 'P')
		{
			m = new PremiumMember;
			system("CLS");
			cout << "Login or Signup? (L/S): ";
			ch = _getch();
			system("CLS");
			if (ch == 'L' || ch == 'l')
			{
			Login1:
				cout << "\t*****Login*****\n";
				do{
					cout << "Enter ID: "; cin >> ID;
					cout << "Enter Password: "; cin >> password;
					flag = m->login(ID, password);
					if (flag != true){
						cout << "Couldn't Find ID!"; _getch();
						system("CLS");
					}
				} while (flag != true);
				cout << "Login Successful!"; _getch();
				system("CLS");
			}
			else if (ch == 'S' || ch == 's')
			{
				cout << "\t*****SignUp*****\n";
				cout << "First Name: "; cin >> first;
				cout << "Last Name: "; cin >> last;
				Name n(first, last);
				cout << "Enter ID: "; cin >> ID;
				do{
					cout << "Enter Password: "; cin >> password;
					cout << "Enter Again for Comfirmation: "; cin >> temp;
					if (temp != password){
						cout << "Password Didnt Match"; _getch();
						system("CLS");
					}
				} while (temp != password);
				cout << "Enter Fees (4000): "; cin >> fees;
				cout << "Enter Wallet Ammount: "; cin >> wallet;
				cout << "Enter Date(DD MM YYYY): "; cin >> day >> month >> year;
				Date registration(day, month, year);
				m->signUp(n, ID, password, fees, wallet, registration);
				cout << "SignUp Successful!"; _getch();
				system("CLS");
				goto Login1;
			}
			do{
				cout << "\t\tMenu\n";
				cout << "\t**(1)Macros**\n";
				cout << "\t**(2)BMI**\n";
				cout << "\t**(3)Fee Submit**\n";
				cout << "\t**(4)Workout Ideas**\n";
				cout << "\t**(5)Set Your Wallet**\n";
				cout << "\t**(q)Quit Menu**\n";
				cout << "\t\tEnter: "; ch = _getch();
				if (ch == '1')
				{
					cout << "\nEnter (Height(cm) Weight(Kg) Age(Y)): ";
					cin >> height >> weight >> age;
					cin.ignore();
					g.macros(height, weight, age);
					_getch();
					system("CLS");
				}
				else if (ch == '2')
				{
					cout << "\nEnter (Height(M) Weight(Kg)): ";
					cin >> height >> weight;
					g.bmi(height, weight);
					_getch();
					system("CLS");
				}
				else if (ch == '3')
				{
					cout << "\nEnter Todays Date (DD MM YYYY): ";
					cin >> day >> month >> year;
					Date last(day, month, year);
					m->setLastDate(last);
					m->write();
					cout << "Fees Submited!"; _getch();
					system("CLS");
				}
				else if (ch == '4')
				{
					cout << "\nBro Workout(Single Muscle EveryDay\n";
					cout << "PushPull Workout(6 days a week, PushPullLegPushPullLeg)\n";
					cout << "Full Body Workout(3 days rest, 3 days workout)\n";
					_getch(); system("CLS");
				}
				else if (choice == '5')
				{
					int temp;
					cout << "\nEnter Ammount You want in Your Wallet: ";
					cin >> temp;
					m->setWallet(temp);
					cout << "Successfully transfered!\n"; _getch();
					system("CLS");
				}
			} while (ch != 'q');
			system("CLS");
		}
	}//OWNER K LIE
	else if (c == '2')
	{
		cout << "Login or Signup? (L/S): ";
		ch = _getch();
		system("CLS");
		if (ch == 'L' || ch == 'l')
		{
		Login:
			cout << "\t*****Login*****\n";
			do{
				cout << "Enter ID: "; cin >> ID;
				cout << "Enter Password: "; cin >> password;
				flag = O.login(ID, password);
				if (flag != true){
					cout << "Couldn't Find ID!"; _getch();
					system("CLS");
				}
			} while (flag != true);
			cout << "Login Successfull!"; _getch();
			system("CLS");
		}
		else if (ch == 'S' || ch == 's')
		{
			cout << "\t*****SignUp*****\n";
			cout << "First Name: "; cin >> first;
			cout << "Last Name: "; cin >> last;
			Name n(first, last);
			cout << "Enter ID: "; cin >> ID;
			do{
				cout << "Enter Password: "; cin >> password;
				cout << "Enter Again for Comfirmation: "; cin >> temp;
				if (temp != password){
					cout << "Password didnt match"; _getch();
					system("CLS");
				}
			} while (temp != password);
			cout << "Enter Date(DD MM YYYY): "; cin >> day >> month >> year;
			Date join(day, month, year);
			O.signup(n, ID, password, join);
			cout << "SignUp Successfull!"; _getch();
			system("CLS");
			goto Login;
		}
		do{
			cout << "\t         Menu\n";
			cout << "\t**(1)Equipment Check**\n";
			cout << "\t**(2)Show Machines**\n";
			cout << "\t**(3)Enter Ammount of Equipment**\n";
			cout << "\t**(q)Quit Menu**\n";
			cout << "\t\tEnter: \n"; ch = _getch();
			if (ch == '1')
			{
				if (M.check())
					cout << "\All Equipment is Present!";
				else
					cout << "Some Equipment is Missing!";
				_getch();
				system("CLS");
			}
			else if (ch == '2')
			{
				M.print();
				_getch();
				system("CLS");
			}
			else if (ch == '3')
			{
				Chest chest; Back back; Leg leg; Cardio cardio;
				cout << "\nFor Chest Equipment: \n";
				cin >> chest; M.setChest(chest);
				cout << "\nFor Back Equipment: \n";
				cin >> back; M.setBack(back);
				cout << "\nFor Leg Equipment: \n";
				cin >> leg; M.setLeg(leg);
				cout << "\nFor Cardio Equipment: \n";
				cin >> cardio; M.setCardio(cardio);
				M.write();
				_getch();
				system("CLS");
			}
		} while (ch != 'q');
		system("CLS");
	}
	system("pause");
	return 0;
}




