/*

Input:

2 numbers, x and y.

Output:

Output a text block where x is the width of the text block and y is the height of the text block. Then there will be a straight line going from the top left to the bottom right and to show it, there should be a # where the line should cross.

The # should be generated using the straight line equation, y = mx + c where m is the gradient of the line which can be retrieved through making m as y divided by x. x is the current line index. c is the height intercept and can be found by multiplying the gradient by the x value and adding the y value. So, in short, it would be (y/x) * lineIndex + (y/x * x + h). This would all be rounded to the nearest position in the current line.

Rules:

there can only be 1 # per line
it has to be in the form of a string/whatever the equivalent in your language of choice. This has to be able to cover multiple lines as well.
in text block, after the # there does not need to be more spaces. Just initial ones to offset the #
Examples:

(don't mind the |, they are where the lines start and stop)

Where x is 9 and y is 1:

|        #|
Where x is 1 and y is 5:

|#|
|#|
|#|
|#|
|#|
where x is 9 and y is 5:

| #       |
|   #     |
|    #    |
|      #  |
|        #|
where x is 5 and y is 9:

|#    |
|#    |
| #   |
| #   |
|  #  |
|  #  |
|   # |
|   # |
|    #|
where x is 9 and y is 2:

|   #     |
|        #|
where x is 9 and y is 3:

|  #      |
|     #   |
|        #|

*/

#include <stdio.h>
#include <math.h>

int
max(int a, int b)
{
	return (a > b) ? a : b;
}

int
offset(int h, int x, int y)
{
	return round((h - y) / (-y * 1.0 / x));
}

void
straightline_text(int x, int y)
{
	int i, l;
	int w, h;

	printf("x=%d y=%d\n", x, y);

	w = 0;
	for (h = y - 1; h >= 0; h--)
		w = max(w, offset(h, x, y));

	for (h = y - 1; h >= 0; h--) {
		l = offset(h, x, y);

		putchar('|');
		for (i = 0; i < l - 1; i++)
			putchar(' ');
		putchar('#');
		for (; i < w - 1; i++)
			putchar(' ');
		puts("|");
	}
	puts("");
}

int
main(void)
{
	straightline_text(9, 1);
	straightline_text(1, 5);
	straightline_text(9, 5);
	straightline_text(5, 9);
	straightline_text(9, 2);
	straightline_text(9, 3);

	return 0;
}
