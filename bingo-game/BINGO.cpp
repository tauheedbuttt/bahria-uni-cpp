#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;
const int size=5;
int user[size][size],pc[size][size];					// user stores USER SHEET, pc stores PC SHEET
bool gameOver;											// gameover used to decide when game ends and valid used to decide whether input is invalid or not
bool userC[size][size]={false};							// in Setup(), used to check whether same combinatoin of X and Y for USER have been used or not
int userX[size]={0}, userY[size]={0};					// in Setup(), used as counter for USER
bool pcC[size][size]={false};							// in Setup(), used to check whether same combinatoin of X and Y for PC have been used or not
int pcX[size]={0}, pcY[size]={0};						// in Setup(), used as counter for PC
int randX, randY;										// in Setup(), used as to generater random X and Y coordinates
int random, enter;										// random generates number for PC sheet, enter takes iinput from user
int usertotal,userHtotal,userVtotal,userDtotal;			// calculate how many lines horizontaly and vertically have been selected on USER SHEET
int pctotal,pcHtotal,pcVtotal,pcDtotal;					// calculate how many lines horizontaly and vertically have been selected on PC SHEET
bool ucheckH[size]={false},ucheckV[size]={false};		// 
bool ucheckD1=false,ucheckD2=false;						// used in decision making of whether crossed out line is being checked again or not in USER SHEET
bool pccheckD1=false,pccheckD2=false;					// used in decision making of whether crossed out line is being checked again or not in PC SHEET
bool pccheckH[size]={false},pccheckV[size]={false};		//
string result;											// stores result of the game

void Setup();											//
void pcdisplay();										//
void userdisplay();										//
void pcinput();											// Declaration of functions
void userinput();										//
void assignvalues();									//
void userCheck();										//
void pcCheck();											//

int main()				//main function
{
	srand(time(NULL));
	random=1+rand()%24;
	Setup();
	assignvalues();
	while(gameOver != true)
	{
		userdisplay();
		userinput();
		userCheck();
		if(gameOver==true)
			break;
		pcinput();
		pcCheck();
	}
	system("CLS");
	if(result=="PC BINGO!")								// displays result according to how game ended
	{
		cout<<"Better Luck Next Time. PC completed his BINGO."<<endl;
	}
	else
	{
		cout<<result<<" You Won!"<<endl;
	}
	cout<<"This was PC's Sheet: \n";					// displays PC sheet
	pcdisplay();
	cout<<endl;
	system("pause");
}
void Setup()			//creates matrix sheet for both users; using arrays
{
	gameOver=false;
	for(int i=0,a=1;i<size*size;i++,a++)
	{
		Point5:
		randX=rand()%5;
		userX[randX]++;
		if(userX[randX]>size)
		{
			userX[randX]--;
			goto Point5;
		}
		Point6:
		randY=rand()%5;
		userY[randY]++;
		if(userY[randY]>size)
		{
			userY[randY]--;
			goto Point6;
		}
		if(userC[randX][randY]!=true)
		{
			user[randX][randY]=a;
			userC[randX][randY]=true;	
		}
		else
		{
			userX[randX]--;
			userY[randY]--;
			goto Point5;
		}
	}
	for(int i=0,a=1;i<size*size;i++,a++)
	{
		Point7:
		randX=rand()%5;
		pcX[randX]++;
		if(pcX[randX]>size)
		{
			pcX[randX]--;
			goto Point7;
		}
		Point8:
		randY=rand()%5;
		pcY[randY]++;
		if(pcY[randY]>size)
		{
			pcY[randY]--;
			goto Point8;
		}
		if(pcC[randX][randY]!=true)
		{
			pc[randX][randY]=a;
			pcC[randX][randY]=true;	
		}
		else
		{
			pcX[randX]--;
			pcY[randY]--;
			goto Point7;
		}
	}
}
void pcdisplay()		//displays the bingo sheet of PC
{
	for(int i=0; i<22;i++)
	{
		cout<<"#";										// # used to define border
	}
	cout<<endl;
	for(int i=0 ;i<size; i++)
	{
		for(int j=0 ;j<=size; j++)
		{
			if(j==0 || j==size)
			{
				cout<<"#";
			}
			if (j<size)
			{
				if(pc[i][j]==0)
				cout<<" -- ";							// displaying selected cell from the SHEET
				else if(pc[i][j]<10)
				cout<<" 0"<<pc[i][j]<<" ";
				else
				cout<<" "<<pc[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	for(int i=0; i<22;i++)
	{
		cout<<"#";
	}
}
void userdisplay()		//displays the bingo sheet of user
{
	system("CLS");
	for(int i=0; i<17+size;i++)
	{
		cout<<"#";
	}
	cout<<endl;
	for(int i=0 ;i<size; i++)
	{
		for(int j=0 ;j<=size; j++)
		{
			if(j==0 || j==size)
			{
				cout<<"#";
			}
			if (j<size)
			{
				if(user[i][j]==0)
				cout<<" -- ";
				else if(user[i][j]<10)
				cout<<" 0"<<user[i][j]<<" ";
				else
				cout<<" "<<user[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	for(int i=0; i<17+size;i++)
	{
		cout<<"#";
	}
	cout<<endl;
	cout<<"PC chose: "<<random<<endl;
}
void pcinput()			//generates random input from pc
{
	int x;
	do
	{
		random=1+rand()%24;
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				if(pc[i][j]==random)
				x=1;
			}
		}	
	}while(x!=1);
	assignvalues();
}
void userinput()		//takes input from user
{
	cout<<"Enter Your Choice: ";
	cin>>enter;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(enter==random||enter>25||enter<=0)
			{
					cout<<"INVALID INPUT!";
					getch();
					userdisplay();
					userinput();
			}
		}
	}
	assignvalues();
}
void assignvalues()		//allocates data in arrays according to the input from user and pc
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(user[i][j]==random||user[i][j]==enter)	// adds 0 in USER array where input is made
			{
				user[i][j]=0;
			}
			if(pc[i][j]==random||pc[i][j]==enter)		// adds 0 in PC array where input is made
			{
				pc[i][j]=0;
			}
		}
	}
	
}
void userCheck()		//checks whether user finished his game or not
{
		for(int i=0;i<size;i++)
		{
			for(int j=0,a=0;j<size;j++)
			{
				if(user[i][j]==0 && ucheckH[i]!=true)
				{
					a++;
					if(a==size)
					{
						ucheckH[i]=true;					// stating that row "i" has been checked, dont check twice
						userHtotal++;						// adding up the number of row that have been checked
					}
					
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0,a=0;j<size;j++)
			{
				if(user[j][i]==0 && ucheckV[i]!=true)
				{
					a++;
					if(a==size)
					{
						ucheckV[i]=true;					// stating that row "i" has been checked, dont check twice
						userVtotal++;						// adding up the number of coloumns that have been checked
					}
				}
			}
		}
		for(int i=0,j=0,a=1;i<size;i++,j++)
		{
			if(user[i][j]==0 && ucheckD1!=true)
			{
				a++;
				if(a==size)
				{
					ucheckD1=true;
					userDtotal++;							// adding the right to left diagnol check of the sheet
				}
			}
		}
		for(int i=0,j=4,a=1;i<size;i++,j--)
		{
			if(user[i][j]==0 && ucheckD2!=true)
			{
				a++;
				if(a==size)
				{
					ucheckD2=true;
					userDtotal++;							// adding the left to right diagnol check of the sheet
				}
			}
		}
		usertotal=userHtotal+userVtotal+userDtotal;
		if(usertotal>=size)
		{
			gameOver=true;
			result="BINGO!";
		}	
}
void pcCheck()			//checks whether pc finished his game or not
{
		for(int i=0;i<size;i++)
		{
			for(int j=0,a=0;j<size;j++)
			{
				if(pc[i][j]==0 && pccheckH[i]!=true)
				{
					a++;
					if(a==size)
					{
						pccheckH[i]=true;
						pcHtotal++;
					}
					
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0,a=0;j<size;j++)
			{
				if(pc[j][i]==0 && pccheckV[i]!=true)
				{
					a++;
					if(a==size)
					{
						pccheckV[i]=true;
						pcVtotal++;
					}
				}
			}
		}
		for(int i=0,j=0,a=1;i<size;i++,j++)
		{
			if(pc[i][j]==0 && pccheckD1!=true)
			{
				a++;
				if(a==size)
				{
					pccheckD1=true;
					pcDtotal++;
				}
			}
		}
		for(int i=0,j=4,a=1;i<size;i++,j--)
		{
			if(pc[i][j]==0 && pccheckD2!=true)
			{
				a++;
				if(a==size)
				{
					pccheckD2=true;
					pcDtotal++;
				}
			}
		}
		pctotal=pcHtotal+pcVtotal;
		if(pctotal>=size)
		{
			gameOver=true;
			result="PC BINGO!";
		}
}
