#include "Date.h"
#define MAXDAY 30
#define MAXMONTH 12
#define MAXYEAR 2099
#define MINYEAR 1970


// Constructor:
Date::Date(int day, int month, int year) {
	setDate(day, month, year);
}
// Setters:
void Date::setDate(int day, int month, int year) {
	if (day > MAXDAY || day <= 0)
		std::cout << "Error day\n";
	else
		this->day = day;

	if (month > MAXMONTH || month <= 0)
		std::cout << "Error month\n";
	else
		this->month = month;
	if (year > MAXYEAR || year < MINYEAR)
		std::cout << "Error year\n";
	else
		this->year = year;
}
// Operator overloading:
Date& Date::operator=(Date& other) {
	if (&other != this) {
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
	}
	return *this;
}
// Increments
//prefix (returns modified value)
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

// postfix (returns the previous value, but modifies existing)
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
// Binary
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
// I/O
std::ostream& operator<<(std::ostream& output, const Date& date)
{
	output << date.day << '/' << date.month << '/' << date.year << '\n';
	date.outFunc(output);
	return output;
}

std::istream& operator>>(std::istream& input, Date& date)
{
	int day, month, year;
	input >> std::setw(3) >> day;
	input.ignore(); // ignore first '/'
	input >> std::setw(3) >> month;
	input.ignore(); // ignore second '/'
	input >> std::setw(5) >> year;
	date.setDate(day, month, year);
	return input;
}

