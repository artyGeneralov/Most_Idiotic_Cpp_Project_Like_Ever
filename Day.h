#pragma warning(disable : 4996)
#ifndef DAY_H
#define DAY_H
#include "Date.h";
#define DEFAULT_MESSAGE "This is default!"

class Day : public Date {
private:
	char* comment;
	// Day d("Go to work", 1, 2, 2020);


	// Date d1(1,2,2020);
public:
	Day(char* comment, int day = DEFAULT_DAY, int month = DEFAULT_MONTH, int year = DEFAULT_YEAR); //DONE
	Day(int day = DEFAULT_DAY, int month = DEFAULT_MONTH, int year = DEFAULT_YEAR); //DONE
	Day(const Day&); //DONE
	~Day();//DONE

	Day operator=(Day);//DONE
	void setComment(const char*);//DONE

	virtual void outFunc(std::ostream&) const override;

	//friend std::ostream& operator<<(std::ostream&, const Date&);
	friend std::ostream& operator<<(std::ostream&, const Day&);
	//friend std::istream& operator>>(std::istream&, Day&);


	// ++(post), ++(pre), +=, >, <, ==

};







#endif
