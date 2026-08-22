/*

Given a year between 1985 and 2025 (inclusive), write a function (or a whole program) that outputs the name of the latest major "Home" version of Windows available to the public by the end of that year.

(1985, 1986)                         -> Windows 1.0
(1987, 1988, 1989)                   -> Windows 2.0
(1990, 1991)                         -> Windows 3.0
(1992, 1993, 1994)                   -> Windows 3.1
(1995, 1996, 1997)                   -> Windows 95
(1998, 1999)                         -> Windows 98
(2000)                               -> Windows Me
(2001, 2002, 2003, 2004, 2005, 2006) -> Windows XP
(2007, 2008)                         -> Windows Vista
(2009, 2010, 2011)                   -> Windows 7
(2012)                               -> Windows 8
(2013, 2014)                         -> Windows 8.1
(2015, 2016, 2017, 2018, 2019, 2020) -> Windows 10
(2021, 2022, 2023, 2024, 2025)       -> Windows 11
Rules:
This is code-golf, so the shortest solution in bytes wins.
The output must be written exactly like in the examples
No standard loopholes
Not allowed: using an external source such as a website, as well as any libraries or APIs
Allowed: if a language happens to natively have a built-in function that helps with this task, you can use it
Notes:
The inputs and outputs are based on this page: https://en.wikipedia.org/wiki/List_of_Microsoft_Windows_versions
There isn't Windows 2000 in this challenge because apparently it was a "Business" release.
Also, the timeline on the page contains mistakes regarding the release year of Windows 8.1 which is 2013, and the naming of Windows ME which officially is Windows Me.

*/

#include <stdio.h>

const char *
windows(int year)
{
	if (year < 1985)
		return NULL;
	if (year <= 1986)
		return "Windows 1.0";
	if (year <= 1989)
		return "Windows 2.0";
	if (year <= 1991)
		return "Windows 3.0";
	if (year <= 1994)
		return "Windows 3.1";
	if (year <= 1997)
		return "Windows 95";
	if (year <= 1999)
		return "Windows 98";
	if (year <= 2000)
		return "Windows ME";
	if (year <= 2006)
		return "Windows XP";
	if (year <= 2008)
		return "Windows Vista";
	if (year <= 2011)
		return "Windows 7";
	if (year <= 2012)
		return "Windows 8";
	if (year <= 2014)
		return "Windows 8.1";
	if (year <= 2020)
		return "Windows 10";
	if (year <= 2025)
		return "Windows 11";
	return NULL;
}

int
main()
{
	int year;

	for (year = 1985; year <= 2025; year++)
		printf("%d: %s\n", year, windows(year));

	return 0;
}
