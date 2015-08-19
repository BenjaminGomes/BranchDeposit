/*
							*********************************************
							*											*
							*				Include Guards				*
							*											*
							*********************************************
*/

#ifndef CORPDEPOSIT_H
#define CORPDEPOSIT_H

/*
							*********************************************
							*											*
							*			Preprocessor Directives			*
							*											*
							*********************************************
*/

#include<iomanip>
#include<iostream>
#include<string>

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
							*			  CorpDeposit Class				*
							*											*
							*********************************************
*/

class CorpDeposit
{
	/*
							*********************************************
							*											*
							*			  Private Subheading			*
							*											*
							*********************************************
	*/

	private:

		/*
							*********************************************
							*											*
							*	Creating Two Static Double Variables	*
							*			of the CorDeposit Class			*
							*											*
							*********************************************
		*/

		static double TotalCorpDeposit;
		static double BranchDeposit;

		/*
							*********************************************
							*											*
							*	Creating the Friendships of the Branch	*
							*	  Functions and the CorpDeposit Class	*
							*											*
							*********************************************
		*/

		friend void StLouis(CorpDeposit &D);
		friend void Jacksonville(CorpDeposit &D);
		friend void Chicago(CorpDeposit &D);

	/*
							*********************************************
							*											*
							*			Public Subheading				*
							*											*
							*********************************************
	*/

	public:

		/*
							*********************************************
							*											*
							*					Accessor				*
							*											*
							*********************************************
		*/

		void AddDeposit(double Deposit)
		{
			cout << "\n\n";
			BranchDeposit = Deposit;
			TotalCorpDeposit += Deposit;
			cout << setw(17) << " " << "Total Deposit to Corporate => $" << TotalCorpDeposit << "\n\n";
			cout << setw(17) << " ";
			system("Pause");
		}
};

/*
	*********************************************************************************************
	*																							*
	*								St. Louis Function Header									*
	*																							*
	*********************************************************************************************
*/

void StLouis(CorpDeposit &D)
{
	double AfterMaint = 0.0;

	system("CLS");
	cout << "\n\n";
	cout << setw(41) << " " << "St. Louis Brach Deposit\n\n\n\n";
	cout << setw(13) << " " << "Saint Louis Branch Deposit $" << D.BranchDeposit << "\n";
	cout << setw(13) << " " << "Corporate Deposit from all reporting Branches $" << D.TotalCorpDeposit << "\n";
	AfterMaint = D.BranchDeposit - (STL_MAINTENENCE_FEE + STL_USAGE_FEE);
	cout << setw(13) << " " << "St. Louis Deposit after Reduction fees $" << AfterMaint << "\n\n\n\n";
	cout << setw(13) << " ";
	system("Pause");
}

/*
	*********************************************************************************************
	*																							*
	*									Chicago Function Header									*
	*																							*
	*********************************************************************************************
*/

void Chicago(CorpDeposit &D)
{
	double AfterMaint = 0.0;

	system("CLS");
	cout << "\n\n";
	cout << setw(41) << " " << "Chicago Brach Deposit\n\n\n\n";
	cout << setw(13) << " " << "Chicago Branch Deposit $" << D.BranchDeposit << "\n";
	cout << setw(13) << " " << "Corporate Deposit from all reporting Branches $" << D.TotalCorpDeposit << "\n";
	AfterMaint = D.BranchDeposit - (CHI_MAINTENENCE_FEE + CHI_USAGE_FEE);
	cout << setw(13) << " " << "Chicago Deposit after Reduction fees $" << AfterMaint << "\n\n\n\n";
	cout << setw(13) << " ";
	system("Pause");
}

/*
	*********************************************************************************************
	*																							*
	*								Jacksonville Function Header								*
	*																							*
	*********************************************************************************************
*/

void Jacksonville(CorpDeposit &D)
{
	double AfterMaint = 0.0;

	system("CLS");
	cout << "\n\n";
	cout << setw(41) << " " << "Jacksonville Brach Deposit\n\n\n\n";
	cout << setw(13) << " " << "Jacksonville Branch Deposit $" << D.BranchDeposit << "\n";
	cout << setw(13) << " " << "Corporate Deposit from all reporting Branches $" << D.TotalCorpDeposit << "\n";
	AfterMaint = D.BranchDeposit - (JAX_MAINTENENCE_FEE + JAX_USAGE_FEE);
	cout << setw(13) << " " << "Jacksonville Deposit after Reduction fees $" << AfterMaint << "\n\n\n\n";
	cout << setw(13) << " ";
	system("Pause");
}

#endif