/*

This is a cake:

_========_
|        |
+________+
|        |
+________+
|        |
+________+
It is 8 wide, 3 tall, and 1 deep.

You must write a program that makes a cake from 3 inputs. The first input controls how many underscores there are in the middle and =s on the top. Here's the first cake with a width of 10 instead of 8:

_==========_
|          |
+__________+
|          |
+__________+
|          |
+__________+
The second input controls how tall the cake is. Here's the second cake with a height of 4 instead of 3:

_==========_
|          |
+__________+
|          |
+__________+
|          |
+__________+
|          |
+__________+
Note the repetition of the layers.

The third input controls how deep it is. That just how many |      |s to include on the top. Here's the third cake with a depth of 2 instead of 1:

_==========_
|          |
|          |
+__________+
|          |
+__________+
|          |
+__________+
|          |
+__________+
You can print trailing whitespace. Test cases:

Input: 3, 3, 3

Output:

_===_
|   |
|   |
|   |
+___+
|   |
+___+
|   |
+___+
(I hope I never get this cake)

Input: 3, 2, 1

Output:

_===_
|   |
+___+
|   |
+___+
Input: 5, 5, 5

Output:

_=====_
|     |
|     |
|     |
|     |
|     |
+_____+
|     |
+_____+
|     |
+_____+
|     |
+_____+
|     |
+_____+

*/

#include <stdio.h>
#include <stdarg.h>

void
linef(const char *fmt, ...)
{
	va_list ap;
	int c, i, n;

	va_start(ap, fmt);
	for (; *fmt; fmt++) {
		c = *fmt;
		switch (c) {
		case '_':
		case '=':
		case ' ':
			n = va_arg(ap, int);
			for (i = 0; i < n; i++)
				putchar(c);
			break;

		case '-':
			putchar('_');
			break;

		default:
			putchar(c);
			break;
		}
	}
	va_end(ap);
	putchar('\n');
}

void
cake(int w, int h, int d)
{
	int i, j, n;

	printf("w=%d h=%d d=%d\n", w, h, d);
	linef("-=-", w);
	for (i = 0; i < h; i++) {
		n = (!i) ? d : 1;
		for (j = 0; j < n; j++)
			linef("| |", w);
		linef("+_+", w);
	}
	putchar('\n');
}

int
main()
{
	cake(8, 3, 1);
	cake(10, 3, 1);
	cake(8, 4, 1);
	cake(3, 3, 3);
	cake(3, 2, 1);
	cake(5, 5, 5);

	return 0;
}
