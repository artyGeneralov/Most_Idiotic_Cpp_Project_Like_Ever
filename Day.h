#pragma warning(disable : 4996)
#ifndef DAY_H
#define DAY_H
#include "Date.h";
#define DEFAULT_MESSAGE "This is default!"

class Day : public Date {
private:
	char* comment; 

public:

	// Constructors/Destructors:
	Day(char* comment, int day = DEFAULT_DAY, int month = DEFAULT_MONTH, int year = DEFAULT_YEAR);
	Day(int day = DEFAULT_DAY, int month = DEFAULT_MONTH, int year = DEFAULT_YEAR);
	Day(const Day&);
	~Day();

	// Setters:
	void setComment(const char*);

	// Operators overloading
	Day operator=(Day);
	// Increments
	virtual Date& operator++();//prefix ++a 
	virtual Date operator++(int);// postfix  
	// Binary
	virtual Date operator+=(int days); 
	virtual bool operator>(const Date&) const;
	virtual bool operator<(const Date&) const;
	virtual bool operator==(const Date&) const;

	// I/O operators
	friend std::ostream& operator<<(std::ostream&, const Day&); 
	friend std::istream& operator>>(std::istream&, Day&);
	virtual void outFunc(std::ostream&) const override; // helper for operator<< (output)
};







#endif
