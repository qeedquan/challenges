/*

Complete the function so that it returns the number of seconds that have elapsed between the start and end times given.

Tips:
The start/end times are given as Date (JS/CoffeeScript), DateTime (C#), Time (Nim), datetime(Python) and Time (Ruby) instances.
The start time will always be before the end time.

*/

#include <stdio.h>
#include <time.h>

int
main()
{
	printf("%f\n", difftime(time(NULL), 0));
	return 0;
}
