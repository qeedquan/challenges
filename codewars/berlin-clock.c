/*

The "Berlin Clock" is the first public clock in the world that tells the time by means of illuminated, coloured fields, for which it entered the Guinness Book of Records upon its installation on 17 June 1975.

The clock is read from the top row to the bottom. The top row of four red fields denote five full hours each, alongside the second row, also of four red fields, which denote one full hour each, displaying the hour value in 24-hour format. The third row consists of eleven yellow-and-red fields, which denote five full minutes each (the red ones also denoting 15, 30 and 45 minutes past), and the bottom row has another four yellow fields, which mark one full minute each. The round yellow light on top blinks to denote even- (when lit) or odd-numbered (when unlit) seconds.

Example: Two fields are lit in the first row (five hours multiplied by two, i.e. ten hours), but no fields are lit in the second row; therefore the hour value is 10.
Six fields are lit in the third row (five minutes multiplied by six, i.e. thirty minutes), while the bottom row has one field on (plus one minute). Hence, the lights of the clock altogether tell the time as 10:31. (Source: Wikipedia)

Task: Write a function that takes in a particular time as 24h format ('hh:mm:ss') and outputs a string that reproduces the Berlin Clock. The parameters should be as follows:

“O” = Light off
“R” = Red light
“Y” = Yellow light

Example Test Case:
Input String:
12:56:01

Output String:
O
RROO
RROO
YYRYYRYYRYY
YOOO

*/

#include <stdio.h>
#include <stdarg.h>

void
linef(const char *fmt, ...)
{
	va_list ap;
	int i, n;

	va_start(ap, fmt);
	for (; *fmt; fmt++) {
		switch (*fmt) {
		case 'S':
			n = va_arg(ap, int);
			if (n % 2)
				printf("O");
			else
				printf("Y");
			break;

		case 'R':
		case 'O':
		case 'Y':
			n = va_arg(ap, int);
			for (i = 0; i < n; i++)
				printf("%c", *fmt);
			break;

		case 'P':
			n = va_arg(ap, int);
			for (i = 0; i < 11; i++) {
				if (i + 1 > n / 5)
					printf("O");
				else if (((i + 1) % 3))
					printf("Y");
				else
					printf("R");
			}
			break;
		}
	}
	puts("");
	va_end(ap);
}

int
berlinclock(const char *t)
{
	int h, m, s;

	if (sscanf(t, "%d:%d:%d", &h, &m, &s) != 3)
		return -1;

	puts(t);
	linef("S", s);
	linef("RO", h / 5, 4 - (h / 5));
	linef("RO", h % 5, 4 - (h % 5));
	linef("P", m);
	linef("YO", m % 5, 4 - (m % 5));
	puts("");

	return 0;
}

int
main()
{
	berlinclock("12:56:01");
	berlinclock("00:00:00");
	berlinclock("22:32:45");

	return 0;
}
