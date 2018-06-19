#include "stdafx.h"
#include "dateType.h"
#include <iostream>

using namespace std;

dateType::dateType()
{
	day = 0;
	month = 0;
	year = 0;
}

// Used to set the day
void dateType::setDayToValue() {
	cout << "Please enter the current day: ";
	cin >> day;
}

// Used to set the month
void dateType::setMonth() {
	cout << "Please enter the current month (1-12): ";
	cin >> month;
}

// Used to set the year
void dateType::setYear() {
	cout << "Please enter the current year (1000 A.D. - 2018): ";
	cin >> year;
}

// Used to check if the year is a leap year
bool dateType::isLeapYear() {
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
void dateType::printDate() {
	cout << month << "-" << day << "-" << year << endl;
}

// Used to check if the date entered is valid for the provided month
bool dateType::checkDay() {
	bool dateCheck = false;

	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day > 31 || day < 1)) {
		cout << "Please enter a day (1-31) for the provided month..." << endl;
		dateCheck = true;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30 || day < 1)) {
		cout << "Please enter a day (1-30) for the provided month.." << endl;
		dateCheck = true;
	}
	else if ((month == 2) && (isLeapYear() == true) && (day >29 || day < 1)) {
		cout << "Please enter a day (1-29) for the provided month and year..." << endl;
		dateCheck = true;
	}
	else if ((month == 2) && (isLeapYear() == false) && (day > 28 || day < 1)) {
		cout << "Please enter a day (1-28) for the provided month and year..." << endl;
		dateCheck = true;
	}
	else
		dateCheck = false;

	// Sets the value of checkDay() to true if the date is invalid, or false if the date is valid
	return dateCheck;
}

// Used to return the number of days that have already passed in the year
int dateType::returnDaysPassed() {
	// Total days in the months prior to the current month
	int totalDays = 0;

	// January
	if (month == 1) {
		totalDays = 0;
		return totalDays + day;
	}
	// February
	else if (month == 2) {
		totalDays = 31;
		return totalDays + day;
	}
	// March
	else if (month == 3) {
		if (isLeapYear() == true) {
			totalDays = 60;
		}
		else
			totalDays = 59;
		return totalDays + day;
	}
	// April
	else if (month == 4) {
		if (isLeapYear() == true) {
			totalDays = 91;
		}
		else
			totalDays = 90;
		return totalDays + day;
	}
	// May
	else if (month == 5) {
		if (isLeapYear() == true) {
			totalDays = 121;
		}
		else
			totalDays = 120;
		return totalDays + day;
	}
	// June
	else if (month == 6) {
		if (isLeapYear() == true) {
			totalDays = 152;
		}
		else
			totalDays = 151;
		return totalDays + day;
	}
	// July
	else if (month == 7) {
		if (isLeapYear() == true) {
			totalDays = 182;
		}
		else
			totalDays = 181;
		return totalDays + day;
	}
	// August
	else if (month == 8) {
		if (isLeapYear() == true) {
			totalDays = 213;
		}
		else
			totalDays = 212;
		return totalDays + day;
	}
	// September
	else if (month == 9) {
		if (isLeapYear() == true) {
			totalDays = 244;
		}
		else
			totalDays = 243;
		return totalDays + day;
	}
	// October
	else if (month == 10) {
		if (isLeapYear() == true) {
			totalDays = 274;
		}
		else
			totalDays = 273;
		return totalDays + day;
	}
	// November
	else if (month == 11) {
		if (isLeapYear() == true) {
			totalDays = 305;
		}
		else
			totalDays = 304;
		return totalDays + day;
	}
	// December
	else if (month == 12) {
		if (isLeapYear() == true) {
			totalDays = 335;
		}
		else
			totalDays = 334;
		return totalDays + day;
	}
	else
		return 0;
}

// Used to return the number of days remaining in the year
int dateType::returnDaysRemaining() {
	if (isLeapYear() == true) {
		return 366 - returnDaysPassed();
	}
	else
		return 365 - returnDaysPassed();

}
