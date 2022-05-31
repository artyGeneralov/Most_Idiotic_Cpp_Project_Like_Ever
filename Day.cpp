#include "Day.h"
#include <cassert>

// Constructors/Destructors:
Day::Day(char* comment, int day, int month, int year) : Date(day, month, year)
{
	setComment(comment);
}

Day::Day(int day, int month, int year) : Date(day, month, year) {
	setComment(" dfdsf");
}

Day::Day(const Day& otherDay)
{
	this->day = otherDay.day;
	this->month = otherDay.month;
	this->year = otherDay.year;
	this->setComment(otherDay.comment);
}

Day::~Day() {
	if (comment)
		delete[] comment;
	comment = NULL;
}

// Setters:
void Day::setComment(const char* comment) 
{
	if (this->comment)
		delete[] this->comment;
	this->comment = new char[strlen(comment) + 1];
	assert(comment != 0);
	strcpy(this->comment, comment);
}


// Operators overloading
Day Day::operator=(Day otherDay)
{
	Date::operator=(otherDay);
	this->setComment(comment);
	return *this;
}

// Increments
Date& Day::operator++() {
	Date::operator++();
	return *this;
}

Date Day::operator++(int x) {
	Day d(*this);
	Date::operator++();
	return d;
}

// Binary
Date Day::operator+=(int days) {
	Date::operator+=(days);
	return *this;
}

bool Day::operator>(const Date& other) const
{
	return Date::operator>(other);
}

bool Day::operator<(const Date& other) const
{
	return Date::operator<(other);
}

bool Day::operator==(const Date& other) const
{
	return Date::operator==(other);
}

// I/O operators
std::ostream& operator<<(std::ostream& output, const Day& day)
{
	output << (Date&)day << " comment: " << day.comment;
	return output;
}

std::istream& operator>>(std::istream& input, Day& day)
{
	input >> (Date&)day;
	return input;
}

void Day::outFunc(std::ostream& output) const
{
	output << comment;
}







