/*

The face of analog clock has two hands and is proportionally divided by 12 marks. The shorter hour hand makes the whole turn (360 degrees) in 12 hours, while the longer minute hand makes the whole circle each hour. See Clock Face on wiki for more details.

Suppose, the Cartesian Coordinate System (i.e. ordinary rectangular coordinate grid) is placed upon the clock face so that the center of the face has coordinates 10, 10 and Y axis is directed upwards while X axis is directed to the right (i.e. at 3:00 minute hand is parallel to Y axis and hour hand is parallel to X axis).

Assuming the length of the minute hand be 9 and the length of the hour hand be 6 you are to find coordinates of the hand ends for each given time - e.g. (16 10) and (10 19) for the time 3:00.

Input data contain the number of test cases.
Following line contains the testcases themselves in form 03:15, 21:44 etc.
Answer should contain four real numbers for each test case - X and Y coordinates for hour hand, then X and Y coordinate for minute hand. All values should be simply separated with spaces.

Real values should have accuracy of 1e-7 or better. Time is specified as a value from 0:00 to 23:59.

Example:

input data:
3
12:00 15:00 09:30

answer:
10.0 16.0 10.0 19.0 16.0 10.0 10.0 19.0 4.20444504 11.55291427 10.0 1.0

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

#define deg2rad(x) ((x) * M_PI / 180)

int
solve(const char *s)
{
	int hh, mm;
	double th, tm;
	double xh, yh;
	double xm, ym;

	if (sscanf(s, "%d:%d", &hh, &mm) != 2)
		return -1;

	hh %= 12;
	tm = mm * 6;
	th = (hh * 30) + (mm * 0.5);

	tm = deg2rad(90 - tm);
	th = deg2rad(90 - th);

	xh = 10 + (6 * cos(th));
	yh = 10 + (6 * sin(th));

	xm = 10 + (9 * cos(tm));
	ym = 10 + (9 * sin(tm));

	printf("%.7f %.7f %.7f %.7f\n", xh, yh, xm, ym);
	return 0;
}

int
main()
{
	solve("12:00");
	solve("15:00");
	solve("09:30");

	return 0;
}
