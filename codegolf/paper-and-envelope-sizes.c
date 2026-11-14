/*

Task

Given a letter (A, B, C), and a number (0-10), output the size of the matching standard paper size (Series A and B) or the matching standard envelope size (C series) in millimetres in the format aaaa x bbbb where aaaa and bbbb are the width and height measurements in millimetres as per ISO216 (Series A & B) or ISO296 (Series C)

To make things easier I will quote from Wikipedia's table of Paper Sizes

ISO paper sizes in portrait view
Format  A series    B series    C series
Size     mm × mm      mm × mm    mm × mm
0       841 × 1189  1000 × 1414 917 × 1297
1       594 × 841    707 × 1000 648 × 917
2       420 × 594    500 × 707  458 × 648
3       297 × 420    353 × 500  324 × 458
4       210 × 297    250 × 353  229 × 324
5       148 × 210    176 × 250  162 × 229
6       105 × 148    125 × 176  114 × 162
7        74 × 105     88 × 125   81 × 114
8        52 × 74      62 × 88    57 × 81
9        37 × 52      44 × 62    40 × 57
10       26 × 37      31 × 44    28 × 40
So examples of input and output:

**Test case 1**
Input: A4
Output: 210 x 297

**Test Case 2**
Input: B6
Output: 125 x 176

**Test Case 3**
Input: C2
Output: 458 x 648
Things to note:

The format "210 x 297" or "1000 x 1414" etc. While this is the preferable format, You can choose to omit the " x " from your output, i.e. in the form of an array or two numbers or whatever tickles your fancy as long as the width measurement is outputted before the height.
The ratio between the height and the width is roughly equivalent to the square root of 2, so in the calculation of the heights, the width is multiplied by sqrt(2), and then rounded up or down to the nearest millimetre, thus resulting in the measurements in the table above. This may help golf down your code.
In successive sizes for a series as you go down the table, the width for one size becomes the height for the next. This may also help you golf down your code.
Rules:

This is code-golf. Standard rules apply as a result. The score will be based on byte count. Lowest count will win.
No silly loopholes, we've been there before... We shan't go through this again.
If you can code it, then please also consider attaching a link to a working instance of your code so that other programmers and golfers can learn how your code works. This is not mandatory, but I'd like to encourage others to do this so we can all learn off one another. I certainly would love to learn more about other golfer's languages where possible.
Best of luck.

*/

#include <assert.h>
#include <stdio.h>

int
papersize(const char *s, int *w, int *h)
{
	static const int tab[][3][2] = {
	    {{841, 1189}, {1000, 1414}, {917, 1297}},
	    {{594, 841}, {707, 1000}, {648, 917}},
	    {{420, 594}, {500, 707}, {458, 648}},
	    {{297, 420}, {353, 500}, {324, 458}},
	    {{210, 297}, {250, 353}, {229, 324}},
	    {{148, 210}, {176, 250}, {162, 229}},
	    {{105, 148}, {125, 176}, {114, 162}},
	    {{74, 105}, {88, 125}, {81, 114}},
	    {{52, 74}, {62, 88}, {57, 81}},
	    {{37, 52}, {44, 62}, {40, 57}},
	    {{26, 37}, {31, 44}, {28, 40}},
	};

	int a, b;

	if (!s[0] || !s[1])
		return -1;

	a = s[0] - 'A';
	b = s[1] - '0';
	if (!(0 <= a && a <= 2) || !(0 <= b && b <= 10))
		return -1;

	*w = tab[b][a][0];
	*h = tab[b][a][1];
	return 0;
}

void
test(const char *s, int rw, int rh)
{
	int w, h;

	assert(papersize(s, &w, &h) >= 0);
	printf("%d %d\n", w, h);
	assert(w == rw && h == rh);
}

int
main(void)
{
	test("A4", 210, 297);
	test("B6", 125, 176);
	test("C2", 458, 648);

	return 0;
}
