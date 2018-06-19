#pragma once
class dateType
{
public:
	int day;
	int year;
	int month;

	dateType();
	void setDayToValue();
	void setMonth();
	void setYear();
	bool isLeapYear();
	void printDate();
	bool checkDay();
	int returnDaysRemaining();
	int returnDaysPassed();
};

