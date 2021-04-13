#include<iostream>
#include<conio.h>
#include<ctime>
#include<Windows.h>
using namespace std;

void heading(char ch, int i)
{
	int j;
	for (j = 0; j <= i; j++)
	cout << ch;
}

class calender
{
	private:
		int date, month,year;
		public:
		calender(int d = 1, int m = 1, int y = 1900)
		{
			date = d;
			month = m;
			year = y;
		}
		void day(int);
		void monthcal(int,int); 
		bool leapyear(int); 
		int DaysInMonth(int,int); 
		int DayNumber(int,int,int); 
};

bool calender :: leapyear(int y)
{
	bool Leap;
	if ((y % 4 == 0) && ((y % 100 != 0) || (y % 400 == 0)))
	Leap = true;
	else
	Leap = false;
	return Leap;
}

int calender :: DaysInMonth(int m, int y)
{
switch (m)
{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: return 31;
	case 2: if (leapyear(y))
	return 29;
	else
	return 28;
	default: return 30;
}
}

int calender :: DayNumber(int d, int m, int y)
{
	int i;
	int dow = 6;
	for (i = 1583; i<y; i++)
	{
		dow += (leapyear(i)) ? 2 : 1;
		dow+=364;
	}
	for (i = 1; i<m; i++)
	dow += DaysInMonth(i, y);
	dow += d;
	return dow;
}

void calender::day(int a)
{
switch (a)
{
	case 1:
	cout << "MONDAY";
	break;
	case 2:
	cout << "TUESDAY";
	break;
	case 3:
	cout << "WEDNESDAY";
	break;
	case 4:
	cout << "THURSDAY";
	break;
	case 5:
	cout << "FRIDAY";
	break;
	case 6:
	cout << "SATURDAY";
	break;
	case 0:
	cout << "SUNDAY";
	break;
	default:
	cout << "\a\a\a\n\nERROR!!!";
}
}

void calender::monthcal(int month, int year)
{
	int j, mon, c;
	j = 0;
	for (j = 0; j <= 6; j++) // For printing 7 days of week
	{
		day(j);
		cout << " ";
	}
	j = 1;
	c = DayNumber(--j, month, year);
	c=c%7;
	cout << "\n";
	switch (c)
	{
		case 0:
		break;
		case 1:
		cout << "\t";
		break;
		case 2:
		cout << "\t\t";
		break;
		case 3:
		cout << "\t\t\t";
		break;
		case 4:
		cout << "\t\t\t\t";
		break;
		case 5:
		cout << "\t\t\t\t\t";
		break;
		case 6:
		cout << "\t\t\t\t\t\t";
	}
	mon = DaysInMonth(month, year);
	for (j = 1; j <= mon; j++) //Printing the month's calendar
	{
		cout << " " << j << "\t";
		c++;
		if (!(c % 7))
	cout << "\n";
	}
}

int main()
{
 int x,y,z;
 char ch; char t = '\xCD';
 
 do
 { 
	system("cls");
	int i, date, year, month;
	cout << "\n\t\t\t\t                    CALENDER";
	cout << "\n\t\t\t\t -----------------------------------------------";
	cout << "\n\t\t\t\t Press 1: The day of a specific date.\n\t\t\t\t Press 2: View the calendar of any given month.\n\t\t\t\t Press 3: Exit. ";
	cout << "\n\t\t\t\t -----------------------------------------------";
	cout << endl << endl << "\n\t\t\t\t Press your choice: ";
	cin >> i;
	if (i == 1) 
	{
		cout << "\n\t\t\t\t Enter date:(dd)";
		cin >> date;
		if (date>31 || date<1)
		{
			cout << "\n\t\t\t\t Please provide valid date.\t\t\t\t Press any key";
			getch();
			system("cls");
			main();
		}
		month:
		cout << "\t\t\t\t Enter month:(mm)";
		cin >> month;
		if (month>12 || month<1)
		{
			cout << "\n\t\t\t\t Please provide valid month.\t\t\t\t Press any key";
			getch();
			goto month;
		}
		year:
		cout << "\t\t\t\t Enter year:(yyyy)";
		cin >> year;
		if (year>2400 || year<1900)
		{
			getch();
			goto year;
		}
		calender obj(date, month, year);
		i = obj.DayNumber(--date, month, year);
		cout << "\n\t\t\t\t" << ++date << "/" << month << "/" << year << " is ";
		i=i%7;
		obj.day(i);
	}
	else if (i == 2) 
	{
	cout << "\n\t\t\t\t Enter month:(mm)";
	cin >> month;
	month2:
	if (month>12 || month<1) 
	{
		cout << "\n\t\t\t\t Please provide valid month.\t\t\t\t Press any key";
		getch();
		goto month2;
	}
	cout << "\t\t\t\t Enter year:(yyyy)";
	cin >> year;
	year2:
	if (year>2400 || year<1900) 
	{
		getch();
		goto year2;
	}
	calender obj;
	obj.monthcal(month, year);
	}
	else if (i == 3)
	{	
		exit(0);
	}
	cout << "\n\n\t\t\t\t Would you like to try again (y/n)";
	ch = _getch();
} 
while (ch == 'y' || ch == 'Y');
return 0;
}
