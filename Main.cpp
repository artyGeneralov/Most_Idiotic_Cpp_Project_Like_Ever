#include <iostream>
#include "Date.h"
#include "Day.h"
using namespace std;

int main()
{
	char comment[100];
	Date* date1 = new Day();
	cout << "Enter a date: " << endl;
	cin >> *date1;
	cin.ignore();
	cout << "Enter a comment: " << endl;
	cin.get(comment, 100);

	static_cast<Day*>(date1)->setComment(comment);

	cout << *date1;

	cout << endl;

	cout << "What do you want to do ?\n";
	int answer;
	cin >> answer;
	while (true)
	{
		switch (answer) {
		case 1:
		{
			cout << *date1;
		}
		break;
		case 2:
		{
			cout << "Enter a new date:\n";
			cin >> *date1;
		}
		break;
		case 3:
		{
			++date1;
			cin.ignore();
			cout << *date1;
		}
		break;
		case 4:
		{
			//date1 = date1->operator++(1);
			date1++;
			cout << *date1;
		}
		break;
		case 5:
		{
		cout << "Enter days to add:\n";
		int daysToAdd;
		cin >> daysToAdd;
		(*date1) += daysToAdd;
		}
			break;
		case 6:
		{
			Date* date2 = new Date();
			cout << "Enter another date:\n";
			cin >> *date2;
			cout << (date1 > date2);
		}
			break;
		case 7:
		{
			Date* date3 = new Date();
			cout << "Enter another date:\n";
			cin >> *date3;
			cout << (date1 < date3);
		}
			break;
		case 8:
		{
			Date* date4 = new Date();
			cout << "Enter another date:\n";
			cin >> *date4;
			cout << (date1 == date4);
		}
			break;
		case 9:
		{
			cout << "Enter a new comment:\n";
			cin.get(comment, 100);
			static_cast<Day*>(date1)->setComment(comment);
		}
			break;
		case -1:
		{
			cout << "Later!";
			exit(0);
		}
			break;
		default:
			break;
		}
		cout << "\nWhat do you want to do ?\n";
		cin >> answer;
	}



}