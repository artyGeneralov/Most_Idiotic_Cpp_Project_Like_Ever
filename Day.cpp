#include "Day.h"
#include <cassert>
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
}

Day::~Day() {
	if (comment)
		delete[] comment;
	comment = NULL;
}

void Day::setComment(const char* comment) 
{
	if (this->comment)
		delete[] this->comment;
	this->comment = new char[strlen(comment) + 1];
	assert(comment != 0);
	strcpy(this->comment, comment);
}

void Day::outFunc(std::ostream& output) const
{
	output << comment;
}

Day Day::operator=(Day otherDay)
{
	Date::operator=(otherDay);
	this->setComment(comment);
	return *this;
}

std::ostream& operator<<(std::ostream& output, const Day& day)
{
	output << (Date&)day << " comment: " << day.comment;
	return output;
}
