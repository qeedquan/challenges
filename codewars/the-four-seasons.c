/*

I highly recommend listening Vivaldi's Four Seasons as an inspiration to solve this Kata :)

In the UK, winter begins on 21 December and ends on 20 March. Spring begins on 21 March and ends on 20 June. Summer begins on 21 June and ends on 20 September. Autumn begins on 21 September and ends on 20 December.

Given a date day from 1 (January 1st) to 365 (December 31th) your task is to return the season of the year that corresponds to that day. If the number given is greater than 365, return "The year flew by!".

Note: We are not considering leap years.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
season(int day)
{
	if (day < 0)
		return NULL;
	if (day < 80 || (day > 354 && day < 366))
		return "Winter Season";
	if (day < 172)
		return "Spring Season";
	if (day < 264)
		return "Summer Season";
	if (day < 355)
		return "Autumn Season";
	return "The year flew by!";
}

int
main()
{
	assert(!strcmp(season(236), "Summer Season"));
	assert(!strcmp(season(109), "Spring Season"));
	assert(!strcmp(season(312), "Autumn Season"));
	assert(!strcmp(season(1), "Winter Season"));
	assert(!strcmp(season(356), "Winter Season"));
	assert(!strcmp(season(400), "The year flew by!"));

	return 0;
}
