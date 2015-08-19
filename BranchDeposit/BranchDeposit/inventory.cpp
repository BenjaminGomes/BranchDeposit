/*
	*********************************************************************************************
	*																							*
	*		Programmer:					Ben Gomes												*
	*		Instructor:					David Wilke												*
	*		Programming Assignment:		B & C Inventory Menu									*
	*		Date:						14 February 2014										*					
	*																							*
	*		This program prompts for a munu selection of 1 or 2. Number 2 is not used in the	*
	*		program at this time. Menu selection 1 will prompt the user for the deposits of the	*
	*		company's three branches (St. Louis, Chicago, and Jacksonvill). Upon entering each	*
	*		branches' total deposit, the user is then able to view the toal deposit getting		*
	*		sent to corporate. The program then prompts the current branch's deposit,			*
	*		corporates total deposit, and the branches deposit less fees. The program cycels	*
	*		through all three branches and then teh user is prompted if they wish to return to	*
	*		the main menu or if they wish to exit.												*
	*																							*
	*********************************************************************************************
*/

/*
							*********************************************
							*											*
							*			Preprocessor Directives			*
							*											*
							*********************************************
*/

#include<iomanip>
#include<iostream>

#include"CorpDeposit.h"
#include"BranchChicago.h"
#include"BranchJacksonville.h"
#include"BranchStLouis.h"

/*
							*********************************************
							*											*
							*				Namespace					*
							*											*
							*********************************************
*/

using namespace std;

/*
							*********************************************
							*											*
							*			Function Prototypes				*
							*											*
							*********************************************
*/

void DisplayMenu();
void InputChoice(int *);
void ErrorChoice(int *);
void ReturnMenu(char *);
void SwitchChoice(int *);
void UpdateInventory();
void BranchName(int);
void BranchUpdate(int);
void ReviewCorporateReprot();

/*
							*********************************************
							*											*
							*			Contant Variable				*
							*											*
							*********************************************
*/

const int NUMBER_OF_BRANCHES = 3;

/*
							*********************************************
							*											*
							*	Allocating the Static Double Variables	*
							*	  of the CorpDeposit Class via Scope	*
							*			 Resolution Operator			*
							*											*
							*********************************************
*/

double CorpDeposit::TotalCorpDeposit = 0.0;
double CorpDeposit::BranchDeposit = 0.0;

/*
	*********************************************************************************************
	*																							*
	*										Main Class											*
	*																							*
	*********************************************************************************************
*/

void main()
{
	/*
							*********************************************
							*											*
							*			Declaring Variables				*
							*											*
							*********************************************
	*/

	char Enter = ' ',
		 ReturnMenuChoice = ' ';

	int Choice = 0;

	/*
							*********************************************
							*											*
							*				Setting Precision			*
							*											*
							*********************************************
	*/

	cout << setprecision(2) << showpoint << fixed;

	/*
							*********************************************
							*											*
							*	Created Do-WHile Loop That Error Checks	*
							*		the Return To Main Menu Input		*
							*											*
							*********************************************
	*/

	do
	{
		/*
							*********************************************
							*											*
							*				Calling Functions			*
							*											*
							*********************************************
		*/

		DisplayMenu();
		InputChoice(&Choice);
		ErrorChoice(&Choice);
		SwitchChoice(&Choice);
		ReturnMenuChoice = ' ';
		ReturnMenu(&ReturnMenuChoice);
	}
	while(ReturnMenuChoice == 'Y');

	cin.ignore();
	cin.get(Enter);
}

/*
	*********************************************************************************************
	*																							*
	*								Display Menu Function Header								*
	*																							*
	*********************************************************************************************
*/

void DisplayMenu()
{
	system("CLS");
	cout << "\n";
	cout << setw(35) << " " << "B & C Inventory Menu\n";
	cout << setw(35) << " " << "INVENTORY SELECTION\n\n\n";
	cout << setw(25) << " " << "Main Menu\n\n\n";
	cout << setw(13) << " " << "1. Update Inventory Cost by Division\n\n";
	cout << setw(13) << " " << "2. Review Total Deposit to Corporate\n\n";
	cout << setw(13) << " " << " Numerical Choice ==> ";
}

/*
	*********************************************************************************************
	*																							*
	*							Input Menu Choice Function Header								*
	*																							*
	*********************************************************************************************
*/

void InputChoice(int *pChoice)
{
	/*
							*********************************************
							*											*
							*			Initializing Pointer			*
							*											*
							*********************************************
	*/

	cin >> *pChoice;
}	

/*
	*********************************************************************************************
	*																							*
	*							Error Check Menu Choice Function Header							*
	*																							*
	*********************************************************************************************
*/

void ErrorChoice(int *pChoice)
{
	/*
							*********************************************
							*											*
							*		Create a While Loop to Error Check	*
							*				Menu Selection				*
							*											*
							*********************************************
	*/

	while(*pChoice < 1 && *pChoice > 2)
	{
		system("CLS");
		cout << "\n";
		cout << setw(31) << " " << "B & C Inventory Menu\n";
		cout << setw(31) << " " << "INVENTORY SELECTION\n\n\n";
		cout << setw(21) << " " << "Error Menu\n\n\n";
		cout << setw(18) << " " << "You have made an Error with the Choice being " << *pChoice << "\n";
		cout << setw(13) << " " << "Enter in a nmber from 1 to 2 for your menu Choice ==> ";
		cin >> *pChoice;
	}
}

/*
	*********************************************************************************************
	*																							*
	*							Swtich Using Menu Choice Function Header						*
	*																							*
	*********************************************************************************************
*/

void SwitchChoice(int *pChoice)
{
	switch(*pChoice)
	{
		case 1:
			system("CLS");
			UpdateInventory();
		break;

		case 2:
			system("CLS");
			cout << "\n\n" << setw(18) << " " << "You chose the second menu option\n";
			cout << setw(18) << " ";
			system("Pause");
		break;
	}
}

/*
	*********************************************************************************************
	*																							*
	*							Return To Main Menu Function Header								*
	*																							*
	*********************************************************************************************
*/

void ReturnMenu(char *pReturnMenuChoice)
{
	/*
							*********************************************
							*											*
							*	Create a While Loop to Error Check		*
							*	   Return To Main Menu Selection		*
							*											*
							*********************************************
	*/

	while(*pReturnMenuChoice != 'Y' && *pReturnMenuChoice != 'N')
	{
		system("CLS");
		cout << "\n";
		cout << setw(36) << " " << "B & C INventory Menu\n";
		cout << setw(36) << " " << "INVENTORY SELECTION\n\n\n";
		cout << setw(26) << " " << "Return Menu\n\n\n";
		cout << setw(18) << " " << "Would you like to return to the Main Menu\n";
		cout << setw(20) << " " << "Answer 'Y' for YES and 'N' for NO ==> ";
		cin >> *pReturnMenuChoice;
		*pReturnMenuChoice = toupper(*pReturnMenuChoice);
		system("CLS");
	}
}

/*
	*********************************************************************************************
	*																							*
	*						Calculate / Update Branch Deposit Function Header					*
	*																							*
	*********************************************************************************************
*/

void UpdateInventory()
{
	double BranchDeposit = 0.0;

	/*
							*********************************************
							*											*
							*	Creating Object TotalCorpDeposit[3] 	*
							*		Using the CorpDeposit Class			*
							*											*
							*********************************************
	*/

	CorpDeposit TotalCorpDeposit[NUMBER_OF_BRANCHES];

	/*
							*********************************************
							*											*
							*	Using a For Loop to Input Deposit For	*
							*			All Three Branches				*
							*											*
							*********************************************
	*/

	for(int Count = 0; Count < NUMBER_OF_BRANCHES; Count++)
	{
		system("CLS");
		cout << "\n";
		cout << setw(31) << " " << "Branch Deposit Menu\n\n";
		cout << setw(13) << " " << "End of Month Branch Deposit for ";
		BranchName(Count + 1);
		cin >> BranchDeposit;

		/*
							*********************************************
							*											*
							*		  Setting the Values of Each		*
							*	  TotalCorpDeposit Array Element and	*	
							*	  Using Dot Operator To Send Deposit	*
							*	Information to the AddDeposit Function	*
							*			of the CorpDeposit Class		*
							*											*
							*********************************************
		*/

		TotalCorpDeposit[Count].AddDeposit(BranchDeposit);
		BranchUpdate(Count + 1);
	}
}

/*
	*********************************************************************************************
	*																							*
	*							Display Branch Name Function Header								*
	*																							*
	*********************************************************************************************
*/

void BranchName(int Count)
{
	if(Count == 1)
		cout << "St. Louis";
	else if(Count == 2)
		cout << "Chicago";
	else
	{
		cout << "Jacksonville";
	}
	cout << " ==> $";
}

/*
	*********************************************************************************************
	*																							*
	*						Display Branch Final Deposit Function Header						*
	*																							*
	*********************************************************************************************
*/

void BranchUpdate(int Count)
{
	/*
							*********************************************
							*											*
							*	Creating an Object For the CorpDeposit	*
							*  Class That Will b Used With the St Louis *
							*	  Function For There Was a Friendship	*
							*		Created Between the Two Elements	*
							*											*
							*********************************************
	*/

	if(Count == 1)
	{
		CorpDeposit TotDep;
		StLouis(TotDep);
	}
	else if (Count == 2)
	{
		CorpDeposit TotDep;
		Chicago(TotDep);
	}
	else
	{
		CorpDeposit TotDep;
		Jacksonville(TotDep);
	}
}