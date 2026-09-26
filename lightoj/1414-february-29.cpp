/*

It is 2012, and it's a leap year. So there is a "February 29" in this year, which is called leap day. Interesting thing is the infant who will born in this February 29, will get his/her birthday again in 2016, which is another leap year. So February 29 only exists in leap years. Does leap year comes in every 4 years? Years that are divisible by 4 are leap years, but years that are divisible by 100 are not leap years, unless they are divisible by 400 in which case they are leap years.

In this problem, you will be given two different date. You have to find the number of leap days in between them.

Input
Input starts with an integer T (≤ 550), denoting the number of test cases.

Each of the test cases will have two lines. First line represents the first date and second line represents the second date. Note that, the second date will not represent a date which arrives earlier than the first date. The dates will be in this format - "month day, year", See sample input for exact format. You are guaranteed that dates will be valid and the year will be in between 2 * 103 to 2 * 109. For your convenience, the month list and the number of days per months are given below. You can assume that all the given dates will be a valid date.

Output
For each case, print the case number and the number of leap days in between two given dates (inclusive).

Sample
Input	Output
4
January 12, 2012
March 19, 2012
August 12, 2899
August 12, 2901
August 12, 2000
August 12, 2005
February 29, 2004
February 29, 2012

Case 1: 1
Case 2: 0
Case 3: 1
Case 4: 3

Notes
The names of the months are {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}.
The numbers of days for the months are {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} respectively in a non-leap year.
In a leap year, number of days for February is 29 days; others are same as shown in previous line.

*/

#include <cassert>
#include <string>

using namespace std;

struct Date
{
	string month;
	int day;
	int year;
};

int solve(Date start, Date end)
{
	if (!(start.month == "January" || start.month == "February"))
		start.year += 1;

	if (end.month == "January" || (end.month == "February" && end.day < 29))
		end.year -= 1;

	auto mul_of_4 = (end.year / 4) - (start.year - 1) / 4;
	auto mul_of_400 = (end.year / 400) - (start.year - 1) / 400;
	auto mul_of_100 = (end.year / 100) - (start.year - 1) / 100;
	return mul_of_4 + mul_of_400 - mul_of_100;
}

int main()
{
	assert(solve({ "January", 12, 2012 }, { "March", 19, 2012 }) == 1);
	assert(solve({ "August", 12, 2899 }, { "August", 12, 2901 }) == 0);
	assert(solve({ "August", 12, 2000 }, { "August", 12, 2005 }) == 1);
	assert(solve({ "February", 29, 2004 }, { "February", 29, 2012 }) == 3);

	return 0;
}
