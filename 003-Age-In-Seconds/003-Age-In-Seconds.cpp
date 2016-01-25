//003 Calculate age in seconds
#include <stdio.h>
#include <iostream>
#include <ctime> 
#include <string>

using namespace std;

struct Date
{
	int year;
	int month;
	int day;
};

void start();
Date* parseDate(string date);
bool isLeap(int year);
int calcLeapYears(int curr, Date *b);
int daySinceYearBegin(Date *b);


int main()
{
	start();
	return 0;
}

void start()
{
	string birthday;

	printf("Enter your birthday in day/month/year format,\n e.g February 3rd, 1975 03/02/1975: ");
	cin >> birthday;

	time_t now = time(0);
	tm *today = localtime(&now);
	int currYear = today->tm_year + 1900;

	Date* birthDate = parseDate(birthday);

	int daysPassed = 0;
	daysPassed += (currYear - birthDate->year) * 365;
	daysPassed += calcLeapYears(currYear, birthDate);
	daysPassed += today->tm_yday;
	if(birthDate->month == 1 && birthDate->day == 1) daysPassed += 1;
	daysPassed -= daySinceYearBegin(birthDate);
	int seconds = daysPassed*24*60*60;
	printf("Your age in seconds is: %d \n", seconds);
}

Date* parseDate(string date)
{
	Date* d = new Date;
	string tmpStr = date.substr(0,2);
	d->day = stoi(tmpStr);
	tmpStr = date.substr(3,5);
	d->month = stoi(tmpStr);
	tmpStr = date.substr(6,10);
	d->year = stoi(tmpStr);
	return d;
}

bool isLeap(int year)
{
	return ((year%4 == 0 && year%100 != 0) || (year%400 == 0));
}

int calcLeapYears(int curr, Date *b)
{
	int days = 0;
	int leapYears = (curr - b->year)/4;
	if (b->month > 2 && isLeap(b->year)) leapYears--;
	days += leapYears;
	return days;
}

int daySinceYearBegin(Date *b)
{
	int days_in_months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sum = 0;
	if(b->month > 1)
	{
		for(int i = 0; i < b->month-1; i++)
		{
			sum += days_in_months[i];
		}
	}
	sum+= b->day;
	cout << sum << endl;
	return sum;
}