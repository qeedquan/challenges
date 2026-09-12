/*

Paul is an excellent coder and sits high on the CW leaderboard. He solves kata like a banshee but would also like to lead a normal life, with other activities. But he just can't stop solving all the kata!!

Given an array (x) you need to calculate the Paul Misery Score. The values are worth the following points:

kata = 5
Petes kata = 10
life = 0
eating = 1
The Misery Score is the total points gained from the array. Once you have the total, return as follows:

< 40 = 'Super happy!'
< 70 >= 40 = 'Happy!'
< 100 >= 70 = 'Sad!'
> 100 = 'Miserable!'

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
paul(const char **s, size_t n)
{
	size_t i;
	int v;

	v = 0;
	for (i = 0; i < n; i++) {
		if (!strcmp(s[i], "kata"))
			v += 5;
		else if (!strcmp(s[i], "Petes kata"))
			v += 10;
		else if (!strcmp(s[i], "eating"))
			v += 1;
	}
	if (v < 40)
		return "Super happy!";
	if (40 <= v && v < 70)
		return "Happy!";
	if (v < 100)
		return "Sad!";
	return "Miserable!";
}

void
test(const char **s, size_t n, const char *r)
{
	const char *p;

	p = paul(s, n);
	puts(p);
	assert(!strcmp(p, r));
}

int
main()
{
	const char *s1[] = {"life", "eating", "life"};
	const char *s2[] = {"life", "Petes kata", "Petes kata", "Petes kata", "eating"};
	const char *s3[] = {"Petes kata", "Petes kata", "eating", "Petes kata", "Petes kata", "eating"};
	const char *s4[] = {"Petes kata", "Petes kata", "Petes kata", "Petes kata", "Petes kata", "Petes kata", "Petes kata"};
	const char *s5[] = {"Petes kata", "Petes kata", "Petes kata", "Petes kata", "Petes kata", "Petes kata", "Petes kata", "Petes kata", "Petes kata", "Petes kata"};

	test(s1, nelem(s1), "Super happy!");
	test(s2, nelem(s2), "Super happy!");
	test(s3, nelem(s3), "Happy!");
	test(s4, nelem(s4), "Sad!");
	test(s5, nelem(s5), "Miserable!");
	return 0;
}
