/*

Many digital clocks display the time using simplified digits comprised of only seven different lights that are either on or off:

https://i.stack.imgur.com/kfYal.png

When mirrored horizontally, the digits 018 don't change because they are symmetrical. Also, the digits 2 and 5 get swapped, 2 becoming 5 and vice versa. All the other digits become invalid when mirrored.

Thus, given a 24-hour digital clock, there are many clock readings such that the mirrored image of the digital display is also a valid clock reading. Your task is to output all such clock readings along with the mirrored readings.

For example, 22:21 becomes 15:55, and 00:15 becomes 21:00. On the other hand, 12:34 or 16:27 are no longer valid when mirrored (digits 34679 become invalid), and neither are 22:22 or 18:21, because, as there are only 24 hours in a day and 60 minutes in an hour, no sane clock would display 55:55 or 12:81.

Task
Write a program or a function that takes no input and outputs all valid pairs in ascending order as shown below:

00:00 - 00:00
00:01 - 10:00
00:05 - 20:00
00:10 - 01:00
00:11 - 11:00
00:15 - 21:00
00:20 - 05:00
00:21 - 15:00
00:50 - 02:00
00:51 - 12:00
00:55 - 22:00
01:00 - 00:10
01:01 - 10:10
01:05 - 20:10
01:10 - 01:10
01:11 - 11:10
01:15 - 21:10
01:20 - 05:10
01:21 - 15:10
01:50 - 02:10
01:51 - 12:10
01:55 - 22:10
02:00 - 00:50
02:01 - 10:50
02:05 - 20:50
02:10 - 01:50
02:11 - 11:50
02:15 - 21:50
02:20 - 05:50
02:21 - 15:50
02:50 - 02:50
02:51 - 12:50
02:55 - 22:50
05:00 - 00:20
05:01 - 10:20
05:05 - 20:20
05:10 - 01:20
05:11 - 11:20
05:15 - 21:20
05:20 - 05:20
05:21 - 15:20
05:50 - 02:20
05:51 - 12:20
05:55 - 22:20
10:00 - 00:01
10:01 - 10:01
10:05 - 20:01
10:10 - 01:01
10:11 - 11:01
10:15 - 21:01
10:20 - 05:01
10:21 - 15:01
10:50 - 02:01
10:51 - 12:01
10:55 - 22:01
11:00 - 00:11
11:01 - 10:11
11:05 - 20:11
11:10 - 01:11
11:11 - 11:11
11:15 - 21:11
11:20 - 05:11
11:21 - 15:11
11:50 - 02:11
11:51 - 12:11
11:55 - 22:11
12:00 - 00:51
12:01 - 10:51
12:05 - 20:51
12:10 - 01:51
12:11 - 11:51
12:15 - 21:51
12:20 - 05:51
12:21 - 15:51
12:50 - 02:51
12:51 - 12:51
12:55 - 22:51
15:00 - 00:21
15:01 - 10:21
15:05 - 20:21
15:10 - 01:21
15:11 - 11:21
15:15 - 21:21
15:20 - 05:21
15:21 - 15:21
15:50 - 02:21
15:51 - 12:21
15:55 - 22:21
20:00 - 00:05
20:01 - 10:05
20:05 - 20:05
20:10 - 01:05
20:11 - 11:05
20:15 - 21:05
20:20 - 05:05
20:21 - 15:05
20:50 - 02:05
20:51 - 12:05
20:55 - 22:05
21:00 - 00:15
21:01 - 10:15
21:05 - 20:15
21:10 - 01:15
21:11 - 11:15
21:15 - 21:15
21:20 - 05:15
21:21 - 15:15
21:50 - 02:15
21:51 - 12:15
21:55 - 22:15
22:00 - 00:55
22:01 - 10:55
22:05 - 20:55
22:10 - 01:55
22:11 - 11:55
22:15 - 21:55
22:20 - 05:55
22:21 - 15:55
22:50 - 02:55
22:51 - 12:55
22:55 - 22:55
A trailing or a leading newline is allowed. Having a few spaces directly before a linefeed is also allowed. The times must be in format hh:mm, padded with zeros when necessary.

This is code-golf, so the shortest answer in bytes wins. As usual, standard loopholes are disallowed.

*/

#include <stdio.h>

void
swapc(char *x, char *y)
{
	char t;

	t = *y;
	*y = *x;
	*x = t;
}

char *
mirror(const char *s, char *b)
{
	int i, n;

	n = sprintf(b, "%s", s);
	if (n != 5)
		return NULL;

	for (i = 0; i < n / 2; i++)
		swapc(&b[i], &b[n - i - 1]);

	for (i = 0; i < n; i++) {
		switch (b[i]) {
		case '2':
			b[i] = '5';
			break;
		case '5':
			b[i] = '2';
			break;
		case ':':
		case '0':
		case '1':
		case '8':
			break;
		default:
			return NULL;
		}
	}
	return b;
}

int
valid(const char *s)
{
	int h, m;

	if (sscanf(s, "%02d:%02d", &h, &m) != 2)
		return 0;
	return (0 <= h && h <= 23) && (0 <= m && m <= 59);
}

void
output(void)
{
	char s[8], t[8];
	int i;

	for (i = 0; i < 1440; i++) {
		snprintf(s, sizeof(s), "%02d:%02d", i / 60, i % 60);
		if (mirror(s, t) && valid(t))
			printf("%s - %s\n", s, t);
	}
}

int
main(void)
{
	output();
	return 0;
}
