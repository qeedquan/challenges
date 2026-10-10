/*

In a now deleted stackoverflow question, someone posted the following:

Write a program or function to print alternating patterns in * and # based on a given integer n. Some examples:

Input: n=1
Output:

*
Input n=5
Output:

*####
###**
***##
###**
*####
Input: n=8
Output:

*#######
######**
***#####
####****
****####
#####***
**######
#######*
Since it looked like a pretty cool code-golfing challenge, here it is.

How are these patterns build?

The first line starts with a single *, followed by n-1 amount of trailing #.
The second line then contains two *, with n-2 amount of leading #.
The third line starts with three *, followed by n-3 amount of trailing #.
etc.

Once we've reached the middle (n/2), we count back again with the amount of *, which can be seen in the examples above.

NOTE that for odd input numbers the inversed pair of lines (so first and last; second and next to last; etc.) are exactly the same. In the n=5 example the first and last lines are *####; the second and next to last lines are ###**.
For even input numbers however the inversed pair of lines are reversed. In the n=8 example the first and last lines are *####### and #######*; the second and next to last lines are ######** and **######; etc.

Challenge rules:
You can use any two distinct printable characters instead of * and #. You can use A and B; 3 and 7; < and >; etc. Please state in your answers what you've used.
You can assume n will be a positive integer (>= 1)
You are allowed to output a list/array of strings for each line or a 2D matrix of characters, instead of printing them to STDOUT.
General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, adding an explanation for your answer is highly recommended.
Test cases (first n=1 through n=10)
*

*#
#*

*##
#**
*##

*###
##**
**##
###*

*####
###**
***##
###**
*####

*#####
####**
***###
###***
**####
#####*

*######
#####**
***####
###****
***####
#####**
*######

*#######
######**
***#####
####****
****####
#####***
**######
#######*

*########
#######**
***######
#####****
*****####
#####****
***######
#######**
*########

*#########
########**
***#######
######****
*****#####
#####*****
****######
#######***
**########
#########*

*/

#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

void
rep(int c, int n)
{
	int i;

	for (i = 0; i < n; i++)
		putchar(c);
}

/*

@lynn

lambda n:["%*s"%(i%2*2*n-n,"x"*min(i+1,n-i))for i in range(n)]

Uses x and space.

The rows are computed like this:

"%-5s" % "x"      == "x    "
"%5s"  % "xx"     == "   xx"
"%-5s" % "xxx"    == "xxx  "
"%5s"  % "xx"     == "   xx"
"%-5s" % "x"      == "x    "
Using the %*s specifier to choose between n and -n.

*/

void
alt(int n)
{
	int i, x, y;

	printf("n=%d\n", n);
	for (i = 0; i < n; i++) {
		x = ((i % 2) * 2 * n) - n;
		y = min(i + 1, n - i);
		rep('#', x - y);
		rep('*', y);
		rep('#', -x - y);
		putchar('\n');
	}
	putchar('\n');
}

int
main()
{
	int i;

	for (i = 1; i <= 10; i++)
		alt(i);
	return 0;
}
