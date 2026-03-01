/*

Your challenge is simple: write a program or function which appears to print the first ten numbers of any integer sequence (on OEIS, the answerer may choose which sequence), but instead prints the exact text:

Happy April Fool's Day!
if and only if it is run on April 1st of any year. Run on any other day should make it output its original output. (Unfortunately, I was a little late posting this challenge). Answers should be voted up for clever hiding of the April fools part.

This is a popularity-contest, so the answer with the most votes on May 8th wins!

*/

#include <stdio.h>
#include <time.h>

// https://oeis.org/A005843
char *
f(int n)
{
	static char b[128];
	struct tm tm;
	time_t t;

	t = time(NULL);
	localtime_r(&t, &tm);
	if (tm.tm_mon == 3 && tm.tm_mday == 1)
		snprintf(b, sizeof(b), "Happy April Fool's Day!");
	else
		snprintf(b, sizeof(b), "%d", n * 2);
	return b;
}

int
main()
{
	int i;

	for (i = 0; i < 10; i++)
		printf("%s\n", f(i));
	return 0;
}
