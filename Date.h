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
	
	Date(int day = DEFAULT_DAY, int month = DEFAULT_MONTH, int year = DEFAULT_YEAR);
	virtual ~Date() {};

	// cout << (Date) << '\n\' << (Date);
	friend std::ostream& operator<<(std::ostream&, const Date&);//DONE
	friend std::istream& operator>>(std::istream&, Date&);//DONE

	Date& operator++();//prefix ++a DONE
	Date operator++(int);// postfix DONE
	Date operator+=(int days); // DONE
	Date& operator=(Date&);
	bool operator>(const Date&) const;// DONE
	bool operator<(const Date&) const;// DONE
	bool operator==(const Date&) const;// DONE


	virtual void outFunc(std::ostream& output) const {};

	const int getDay() const { return day; }
	const int getMonth() const { return month; }
	const int getYear() const { return year; }
};



#endif