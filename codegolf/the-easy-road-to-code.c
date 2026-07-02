/*

Input:
An integer n, which is guaranteed to be ≥3.
An integer d, which is one of [-1,0,1].

Output:
A road of size n, which will be in a north-west direction if d=-1; a north direction if d=0; or a north-east direction if d=1.
The road will always be three spaces wide (or five in general if we'd include the outer borders).
In addition, there will be a road separator line on the bottom section, and after that alternating while going upwards.

Some examples:

Input: n=7,d=1

Output:

      / / /
     /   /
    / / /
   /   /
  / / /
 /   /
/ / /
Input: n=4,d=−1

Output:

\   \
 \ \ \
  \   \
   \ \ \

Challenge rules:
Any amount of leading/trailing spaces and/or newlines are acceptable, as long as it prints the required road somewhere on the screen.
Instead of the options [-1,0,1] you are also allowed to use the options [0,1,2] or [1,2,3] instead.
Also, you can choose which of the three options map to which of the three directions.
(Make sure to mention which options you've used if it differs from the [-1,0,1] for [north-west, north, north-east] respectively that is used in this challenge description!)
Any reasonable output format is acceptable. The most common is of course to print it to STDOUT, but returning it as a string or 2D character list is fine as well.

General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer with default I/O rules, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code (i.e. TIO).
Also, adding an explanation for your answer is highly recommended.

Test cases:
The two examples above, and:

Input: n=10,d=0

Output:

|   |
| | |
|   |
| | |
|   |
| | |
|   |
| | |
|   |
| | |

*/

#include <stdio.h>

void
road(int n, int d)
{
	static const char sym[] = "\\|/";

	int c, nc;
	int i, p;

	printf("n=%d d=%d\n", n, d);
	c = sym[d + 1];
	for (i = n - 1; i >= 0; i--) {
		if (d > 0)
			p = i + 1;
		else if (d < 0)
			p = n - i;
		else
			p = 0;

		nc = (i & 1) ? ' ' : c;
		printf("%*c %c %c\n", p, c, nc, c);
	}
	printf("\n");
}

int
main()
{
	road(7, 1);
	road(4, -1);
	road(10, 0);

	return 0;
}
