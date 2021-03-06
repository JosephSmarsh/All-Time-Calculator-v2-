// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "dateType.h"

using namespace std;

int main()
{
	dateType dateTypeObject;				//Creating the object to acces the dateType class
	
	dateTypeObject.setMonth();				//Set the month

	// Checks if the month is valid, if it is not the loop will repeat
	if (dateTypeObject.month > 12 || dateTypeObject.month < 1) {
		do {
			cout << "Please enter a valid month (1-12)..." << endl;	
			dateTypeObject.setMonth();
		} while (dateTypeObject.month > 12 || dateTypeObject.month < 1);
	}

	dateTypeObject.setYear();				// Set the year

	// Check if the year is valid, if not the year input will run through the loop until it is valid.
	if (dateTypeObject.year > 2018 || dateTypeObject.year < 1000) {
		do {
			cout << "Please enter a valid year (1000-2018)..." << endl;	
			dateTypeObject.setYear();
		} while (dateTypeObject.year > 2018 || dateTypeObject.year < 1000);
	}

	dateTypeObject.setDayToValue();			// Set the day

	// Runs the date through the checkDay() function to determine if it is valid
	if (dateTypeObject.checkDay() == true) {
		do {
			dateTypeObject.setDayToValue();
		} while (dateTypeObject.checkDay() == true);
	}

	// Prints the current date
	cout << "The selected date is: " << endl;
	dateTypeObject.printDate();

	// Returns the total days that have passed for the given year.
	cout << "The total days that have passed are: " << endl;
	cout << dateTypeObject.returnDaysPassed() << endl;

	// Returns the total days that are remaining for the given year.
	cout << "The total days that are remaining in the year are: " << endl;
	cout << dateTypeObject.returnDaysRemaining() << endl;

	// Pauses the console to keep it open
	system("pause");
    return 0;
}

