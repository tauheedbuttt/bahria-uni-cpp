#include "stdafx.h"
#include "PremiumMember.h"


PremiumMember::PremiumMember(){ type = "Premium"; wallet = 100; }
PremiumMember::PremiumMember(Name n, int ID, int fees, Date registration) :Member(n, ID, fees, registration){}
void PremiumMember::setWallet(int wallet){ this->wallet = (wallet>0) ? wallet : 0; }
int PremiumMember::getWallet(){ return wallet; }
void PremiumMember::write()
{
	ofstream f("PremiumM.dat", ios::binary || ios::app);
	f.write((char*)this, sizeof(*this));
	f.close();
}
bool PremiumMember::login(int ID, int password)
{
	PremiumMember temp; bool flag=false;
	ifstream f("PremiumM.dat", ios::binary);
	//Counting objects in file
	f.seekg(0, ios::end);
	int len = f.tellg() / sizeof(PremiumMember);
	f.seekg(0, ios::beg);
	for (int i = 0; i<len; i++)
	{
		f.read((char*)&temp, sizeof(temp));
		if (temp.getID() == ID)
		{
			if (temp.getPassword() == password)
			{
				flag = true; f.close(); break;
			}
			else flag = false;
		}
		else flag = false;
	}
	return flag;
}
void PremiumMember::signUp(Name n, int ID, int password, int fees, int wallet, Date registration)
{
	ofstream f("PremiumM.dat", ios::binary | ios::app);
	setName(n);
	setID(ID); setPassword(password);
	setFees(fees);
	setWallet(wallet);
	setRegistration(registration);
	setLastDate(registration);
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
	f.write((char*)this, sizeof(*this));
	f.close();
}
void PremiumMember::print()
{
	Member::print();
	cout << "\t" << type;
}
