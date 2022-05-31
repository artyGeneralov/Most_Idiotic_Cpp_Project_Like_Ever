#ifndef DATE_H
#define DATE_H
#define DEFAULT_DAY 1
#define DEFAULT_MONTH 1
#define DEFAULT_YEAR 1970

#include <iostream>
#include <iomanip>


class Date {
protected:
	int day, month, year;

public:
	
	// Constructors / Destructors:
	Date(int day = DEFAULT_DAY, int month = DEFAULT_MONTH, int year = DEFAULT_YEAR);
	virtual ~Date() {};

	// Getters & Setters:
	const int getDay() const { return day; }
	const int getMonth() const { return month; }
	const int getYear() const { return year; }
	void setDate(int, int, int);

	// Operator overloading:
	Date& operator=(Date&);
	// Increments
	virtual Date& operator++();//prefix ++a 
	virtual Date operator++(int);//postfix 
	// Binary
	virtual Date operator+=(int days);
	virtual bool operator>(const Date&) const;
	virtual bool operator<(const Date&) const;
	virtual bool operator==(const Date&) const;
	// I/O
	friend std::ostream& operator<<(std::ostream&, const Date&);
	friend std::istream& operator>>(std::istream&, Date&);
	virtual void outFunc(std::ostream& output) const {};
};
#endif