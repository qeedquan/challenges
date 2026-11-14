/*

Output (or print) each of the 11 times, one per line, in the POSIX %I:%M:%S format, at which the hour and minute hands of a 12-hour clock are antiparallel. Here %I is the two digit hour with 12 in place of 0; %M is the two digit minute, and %S is the truncated seconds value.

The output should be exactly the following:

12:32:43
01:38:10
02:43:38
03:49:05
04:54:32
06:00:00
07:05:27
08:10:54
09:16:21
10:21:49
11:27:16
Please note that the seconds values are not rounded, but rather truncated. For example, while the first actual time meeting the condition is 12:32:43.63636363... which rounds up to 12:32:44, we require that the truncated number of seconds is truncated to 43.

This is a code golf: the answer with the smallest number of bytes wins.

The program has no input. Output can be either (1) a sequence (list or array) of strings returned from a function, or (2) simply written to standard output, one per line. If you chose the latter, a newline after the final string is required.

(This does not appear to be an exact duplicate of any of the few dozen analog clock problems on this site, but hopefully it is distinct enough from the others to be a viable challenge.)

*/

#include <stdio.h>

void
output()
{
	static const char *times[] = {
		"12:32:43",
		"01:38:10",
		"02:43:38",
		"03:49:05",
		"04:54:32",
		"06:00:00",
		"07:05:27",
		"08:10:54",
		"09:16:21",
		"10:21:49",
		"11:27:16",
		NULL,
	};

	size_t i;

	for (i = 0; times[i]; i++)
		puts(times[i]);
}

int
main()
{
	output();
	return 0;
}
