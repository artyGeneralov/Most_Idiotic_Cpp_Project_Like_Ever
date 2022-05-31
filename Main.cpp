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
	int answer;
	while (true)
	{
		cout << "\nWhat do you want to do ?\n";
		cin >> answer;
		switch (answer) {
		case 1: // Print
		{
			cout << *date1;
		}
		break;
		case 2: // Change date
		{
			cout << "Enter a new date:\n";
			cin >> *date1;
		}
		break;
		case 3: // Increment prefix (prints incremented)
		{
			cout << ++(*date1);
		}
		break;
		case 4: // Increment postfix (prints previous)
		{
			cout << (*date1)++;
		}
		break;
		case 5: // Add days to date
		{
		cout << "Enter days to add:\n";
		int daysToAdd;
		cin >> daysToAdd;
		(*date1) += daysToAdd;
		}
			break;
		case 6: // Is new date larger then original?
		{
			Date* date2 = new Date();
			cout << "Enter another date:\n";
			cin >> *date2;
			cout << (*date1 > *date2);
		}
			break;
		case 7: // Is new date smaller then original?
		{
			Date* date3 = new Date();
			cout << "Enter another date:\n";
			cin >> *date3;
			cout << (*date1 < *date3);
		}
			break;
		case 8: // Dates equallity
		{
			Date* date4 = new Date();
			cout << "Enter another date:\n";
			cin >> *date4;
			cout << (*date1 == *date4);
		}
			break;
		case 9: // Change the comment
		{
			cout << "Enter a new comment:\n";
			cin.ignore();
			cin.get(comment, 100);
			static_cast<Day*>(date1)->setComment(comment);
		}
			break;
		case -1: // End
		{
			cout << "Later!";
			cin.ignore();
			exit(0);
		}
			break;
		default:
			break;
		}

	}



}