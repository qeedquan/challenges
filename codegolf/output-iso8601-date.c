/*

The Task
Given the positive value of unix timestamp output any of two valid ISO 8601 time formats:

YYYY-MM-DDTHH:mm:SS or, alternatively,
YYYY-MM-DD HH:mm:SS
You may ignore any leap seconds, if you wish, as well as the timezone part of the date.

Also, ignore the year 2038 problem.

Rules
You must not use any built-in date functions,
You may not use any string formatting functions (like printf), however sorting, reversing, changing case etc. is allowed,
Your program may not contain any numbers (ie. characters 0, 1, 2, ... 9) and letters which mean hexadecimal number (A, a, B, b, ... f), if used in context of hexadecimal number,
The only exception are line numbers (or labels and goto statements), if your language requires them,
You may use any function or method that returns a number, but only once (each) in your program:
For example, you can use something like zero = length(''); to have number 0, but then you can't use one = length('a'); because you would use the length() function twice, so you can consider using one = cos(zero);

The same applies to built-in constants or variables
You may use built-in constants like __LINE__ etc., but only once for each value (for example, __FILE__ is "really" constant in a file, so you can use it only once in a file, but __LINE__ varies for each line, so you can use it once per line).

If a function or a constant is used in a loop that has a chance to be executed more than once, it is considered to be used more than once and this is forbidden,
All loopholes are forbidden (especially, loading the result from another site or executing an external program to do the calculations).
Any errors, compiler warnings are allowed, however the ISO 8601 string must be valid (no error messages within the output string)
Testing
Your code must return a valid value which will be tested with the site http://www.unixtimestamp.com/.

Notes
This question is a popularity contest, so the highest scored answer wins (not earlier than at Midnight on Monday, September 7th UTC). The main idea is to show your skills when limited to not use numbers. When voting, please consider how numbers are represented by the author and what tricks they use. In my opinion such constructions like

 eighty_six_thousand_four_hundred = one;
 eighty_six_thousand_four_hundred++;
 eighty_six_thousand_four_hundred++;
 //... 86399 times
or

// 86399 empty lines
...
$eighty_six_thousand_four_hundred = __LINE__;
should be avoided.

I also kindly ask that you provide an online version of your program, so everyone can test it (the program must not be limited to your environment).

*/

#include <stdio.h>
#include <time.h>

char *
iso8601(time_t t, char *b, size_t n)
{
	struct tm tm;

	localtime_r(&t, &tm);
	strftime(b, n, "%Y-%m-%d %H:%M:%S", &tm);
	return b;
}

int
main(void)
{
	char b[80];

	printf("%s\n", iso8601(time(NULL), b, sizeof(b)));
	return 0;
}
