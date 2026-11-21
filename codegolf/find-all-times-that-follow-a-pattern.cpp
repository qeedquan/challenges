/*

Your job is write a program that prints all times (in the format HH:MM, 24 hours) that follow any of the following patterns:

Hours equal to minutes, e.g. 22:22,01:01
Hours equal to reverse minutes, e.g. 10:01, 01:10, 22:22
Sequences, that match H:MM, or HH:MM, always printed with HH:MM. E.g. 00:12, 01:23, 23:45, 03:45, etc (always a single step between digits)
Rules:

You may choose any language you like
You cannot print repeated times
One time per line, following the order of the day
The winner will be chosen in February 5.
PS: this is my first question, it might have some inconsistencies. Feel free to edit.

PS2: Here is the expected 44 solutions (already presented by Josh and primo, Thanks!)

00:00
00:12
01:01
01:10
01:23
02:02
02:20
02:34
03:03
03:30
03:45
04:04
04:40
04:56
05:05
05:50
06:06
07:07
08:08
09:09
10:01
10:10
11:11
12:12
12:21
12:34
13:13
13:31
14:14
14:41
15:15
15:51
16:16
17:17
18:18
19:19
20:02
20:20
21:12
21:21
22:22
23:23
23:32
23:45

*/

#include <cstdio>

bool check(int h, int m)
{
	if (h == m)
		return true;

	auto mr = (m / 10) + ((m % 10) * 10);
	if (h == mr)
		return true;

	auto h0 = h / 10;
	auto h1 = h % 10;
	auto m0 = m / 10;
	auto m1 = m % 10;
	if ((h0 == 0 || h0 + 1 == h1) && h1 + 1 == m0 && m0 + 1 == m1)
		return true;

	return false;
}

void times()
{
	for (auto h = 0; h < 24; h++)
	{
		for (auto m = 0; m < 60; m++)
		{
			if (check(h, m))
				printf("%02d:%02d\n", h, m);
		}
	}
}

int main()
{
	times();
	return 0;
}
