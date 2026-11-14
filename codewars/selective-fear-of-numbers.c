/*

I've got a crazy mental illness. I dislike numbers a lot.
But it's a little complicated: The number I'm afraid of depends on which day of the week it is... This is a concrete description of my mental illness:

Monday --> 12

Tuesday --> numbers greater than 95

Wednesday --> 34

Thursday --> 0

Friday --> numbers divisible by 2

Saturday --> 56

Sunday --> 666 or -666

Write a function which takes a string (day of the week) and an integer (number to be tested) so it tells the doctor if I'm afraid or not. (return a boolean)

*/

#include <assert.h>
#include <string.h>

bool
solve(const char *d, int n)
{
	if (!strcmp(d, "Monday"))
		return n == 12;
	if (!strcmp(d, "Tuesday"))
		return n > 95;
	if (!strcmp(d, "Wednesday"))
		return n == 34;
	if (!strcmp(d, "Thursday"))
		return n == 0;
	if (!strcmp(d, "Friday"))
		return (n % 2) == 0;
	if (!strcmp(d, "Saturday"))
		return n == 56;
	if (!strcmp(d, "Sunday"))
		return n == 666 || n == -666;
	return false;
}

int
main()
{
	assert(solve("Monday", 12) == true);
	assert(solve("Tuesday", 100) == true);
	assert(solve("Wednesday", 34) == true);
	assert(solve("Thursday", 0) == true);
	assert(solve("Friday", 2) == true);
	assert(solve("Saturday", 56) == true);
	assert(solve("Sunday", 666) == true);

	return 0;
}
