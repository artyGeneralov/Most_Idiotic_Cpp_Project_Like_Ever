#include "Date.h"
#define MAXDAY 30
#define MAXMONTH 12

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

bool Date::operator>(const Date& otherDate) const
{
	if (this->year > otherDate.getYear())
		return true;
	else if (this->year == otherDate.getYear())
		if (this->month > otherDate.getMonth())
			return true;
		else if (this->month == otherDate.getMonth())
			if (this->day > otherDate.getDay())
				return true;
	return false;
	
}

bool Date::operator<(const Date& otherDate) const
{
	if (this->year < otherDate.getYear())
		return true;
	else if (this->year == otherDate.getYear())
		if (this->month < otherDate.getMonth())
			return true;
		else if (this->month == otherDate.getMonth())
			if (this->day < otherDate.getDay())
				return true;
	return false;
}

bool Date::operator==(const Date& otherDate) const
{
	if (this->day == otherDate.getDay() &&
		this->month == otherDate.getMonth() &&
		this->year == otherDate.getYear())
		return true;
	return false;
}

//++d1;
Date& Date::operator++() {
	if (day != MAXDAY)
		day++;
	else
	{
		if (month != MAXMONTH)
		{
			day = 1;
			month++;
		}
		else // is the last month
		{
			month = day = 1;
			year++;
		}
	}
	return *this;
}


Date Date::operator++(int i) {
	Date newDate(*this);
	++* this;
	return newDate;
}

Date Date::operator+=(int days)
{
	if (this->day + days > MAXDAY)
	{
		if (this->month == MAXMONTH)
		{
			this->year++;
			this->month = 1;
		}
		else
			this->month++;
		this->day = ((this->day + days) % MAXDAY) + 1;
	}
	else
		this->day = this->day + days;
	return *this;
}

std::ostream& operator<<(std::ostream& output, const Date& date)
{
	output << date.day << '/' << date.month << '/' << date.year << '\n';
	date.outFunc(output);
	return output;
}

std::istream& operator>>(std::istream& input, Date& date)
{
	//  "03/11/1953"
	input >> std::setw(3) >> date.day;
	input.ignore(); // ignore '/'
	input >> std::setw(3) >> date.month;
	input.ignore(); // ignore second '/'
	input >> std::setw(5) >> date.year;
	return input;
}

Date& Date::operator=(Date& other) {
	if (&other != this) {
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
	}
	return *this;
}