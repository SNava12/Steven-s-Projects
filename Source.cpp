#include <iostream>
#include <string>
#include <list>
#include "Customers.h"
#include "Manager.h"
#include "Sales.h"
#include "SalesList.h"
#include "Items.h"
#include "Employee.h"
#include "ItemsList.h"
#include "EmpSales.h"


using namespace std;
int ItemName;
int ItemExpirationDate;


int main()
{
	int Customers = 1;
	int Manager = 2;
	int Employee = 3;
	int Choice;
	
	cout << "Welcome to Restaraunt Name " << endl;
	cout << "Are you a 1.Customer or 2. Manager or 3. Employee?" << endl;
	cout << "Enter a Number" << endl;

	cin >> Choice;
	

	if ( Choice == 1) // If the User Chooses Customer 
	{
		class Customers Customers;
		Customers.pressEnter();
	}
	 if (Choice == 2) // If user Chooses Manager
	{
		 class Manager Manager;
		 Manager.pressEnter();
		 return 0; // If Manager Enters Wrong Password the Program Ends

		 class Sales Sales; // Manager Update Sales Goal
		 Sales.pressEnter();


	}
	 if (Choice == 3)
	 {
		 class Employee Employee; // If the User chooses Employee
		 Employee.pressEnter();
		 cin >> Choice;
		 
		 if (Choice == 1) 
		 {
			 int Items = 1;
		     int Sales = 2;

			 cout << "Welcome would you like to 1. Add items or 2. Check items" << endl;
			 cin >> Choice;

			 if (Choice == 1)
			 {
				 class Items Items; // Employee Add Items
				 Items.pressEnter();

				 class ItemsList ItemsList; // An ItemsList to check and store Item Data
				 ItemsList.pressEnter();
			 }
			 else if (Choice ==2 )
			 {
				 cout << "Here are the items!" << endl;
				 
				 class ItemsList ItemsList; 
				 ItemsList.pressEnter();

				 return 0;
			 }

		 }
		 if (Choice ==2)
		 {
			 int AddSales = 1;
			 int CheckSales = 2;

			 cout << "Welcome would you like to 1. Add sales or 2. Check sales." << endl;
			 cin >> Choice;

			 if (Choice == 1) 
			 {
				 class EmpSales EmpSales; // Employee Adding into Sales
				 EmpSales.pressEnter();
			 }
			 else if (Choice == 2)
			 {
				 class SalesList SalesList; // Employees checking the sales goal
				 SalesList.pressEnter();
			 }
		 }
	 }
}