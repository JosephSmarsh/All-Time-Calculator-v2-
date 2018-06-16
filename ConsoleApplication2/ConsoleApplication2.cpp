// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class dateType {
public:

	// Used to set default values to the variables
	dateType() {
		day = 0;
		month = 0;
		year = 0;
	}

	// Used to set the day
	void setDayToValue() {
		cout << "Please enter the current day: ";
		cin >> day;
	}

	// Used to set the month
	void setMonth() {
		cout << "Please enter the current month (1-12): ";
		cin >> month;
	}

	// Used to set the year
	void setYear() {
		cout << "Please enter the current year (1000 A.D. - 2018): ";
		cin >> year;
	}

	// Used to check if the year is a leap year
	bool isLeapYear() {
		bool leapYear = false;
		if (year % 4 == 0) {
			leapYear = true;
		}
		if (year % 100 == 0) {
			leapYear = false;
		}
		if (year % 400 == 0) {
			leapYear = true;
		}
		return leapYear;
	}

	// Used to print the complete date
	void printDate() {
		cout << month << "-" << day << "-" << year << endl;
	}

	// Used to check if the date entered is valid for the provided month.
	bool checkDay() {
		bool dateCheck = false;

		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day > 31 || day < 1)) {
			cout << "Please enter a day (1-31) for the provided month..." << endl;
			dateCheck = true;
		}
		else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30 || day < 1)) {
			cout << "Please enter a day (1-30) for the provided month.." << endl;
			dateCheck = true;
		}
		else if ((month == 2) && (isLeapYear() == true) && ( day >29 || day < 1)) {
			cout << "Please enter a day (1-29) for the provided month and year..." << endl;
			dateCheck = true;
		}
		else if ((month ==2) && (isLeapYear() == false) && ( day > 28 || day < 1)) {
			cout << "Please enter a day (1-28) for the provided month and year..." << endl;
			dateCheck = true;
		}
		else
			dateCheck = false;

		// Sets the value of checkDay() to true if the date is invalid, or false if the date is valid
		return dateCheck;
	}

	// Used to return the number of days that have passed in the year
	int returnDaysPassed() {
		// Total days in the months prior to the current month
		int totalDays = 0;

		// January
		if (month == 1) {
			totalDays = 0;
			return totalDays + day;
		}
		// February
		else if ( month == 2 ) {
			totalDays = 31;	
			return totalDays + day;
		}
		// March
		else if (month == 3) {
			if (isLeapYear() == true) {
				totalDays = 31 + 29;
			}
			else
				totalDays = 31 + 28;
			return totalDays + day;
		}
		// April
		else if (month == 4) {
			if (isLeapYear() == true) {
				totalDays = 31 + 29 + 31;
			}
			else
				totalDays = 31 + 28 + 31;
			return totalDays + day;
		}
		// May
		else if (month == 5) {
			if (isLeapYear() == true) {
				totalDays = 31 + 29 + 31 + 30;
			}
			else
				totalDays = 31 + 28 + 31 + 30;
			return totalDays + day;
		}
		// June
		else if (month == 6) {
			if (isLeapYear() == true) {
				totalDays = 31 + 29 + 31 + 30 + 31;
			}
			else
				totalDays = 31 + 28 + 31 + 30 + 31;
			return totalDays + day;
		}
		// July
		else if (month == 7) {
			if (isLeapYear() == true) {
				totalDays = 31 + 29 + 31 + 30 + 31 + 30;
			}
			else
				totalDays = 31 + 28 + 31 + 30 + 31 + 30;
			return totalDays + day;
		}
		else
			return 0;
	}

	// Variables, needs to be made private
	int day;
	int month;
	int year;
};


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

	// Pauses the console to keep it open
	system("pause");
    return 0;
}

