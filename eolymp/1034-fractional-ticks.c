/*

A boy named Serhii really wants to learn how to juggle and perform tricks.
Recently, his friend showed him a trick: he asked Serhii to imagine a certain positive fraction,
then named its denominator and two fractions p1/q1 and p2/q2 such that p1/q1 < a/b < p2/q2,
and there is no smaller fraction between them with the same denominator as Serhii's imagined fraction.
After that, his friend guessed the numerator of the fraction Serhii was thinking of.

Now Serhii wants to learn how to perform this trick himself.
Help him by writing a program that finds the numerator of the hidden fraction.

Input
Three fractions are given in three separate lines in the format numerator / denominator (p1/q1, a/b, p2/q2),
where a is replaced by a question mark "?".
All numerators and denominators are positive integers not exceeding 1000.

Output
Print the minimal numerator a such that p1/q1 < a/b < p2/q2. If no such fraction exists, print "-1".

Examples

Input #1
1/2
?/8
3/4

Answer #1
5/8

Input #2
3/20
?/2
4/10

Answer #2
-1

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef long long vlong;

typedef struct {
	vlong n, d;
} Rat;

vlong
multiple(vlong n, vlong m)
{
	return ((n + (m / 2)) / m) * m;
}

int
ratparse(Rat *r, const char *s)
{
	r->n = r->d = 0;
	if (sscanf(s, "?/%lld", &r->d) == 1)
		return 1;
	if (sscanf(s, "%lld/%lld", &r->n, &r->d) == 2)
		return 1;
	return 0;
}

Rat
ratscale(Rat r, vlong s)
{
	r.n *= s;
	r.d *= s;
	return r;
}

void
solve(const char *s1, const char *s2, const char *s3, char *b)
{
	Rat t1, t2, t3;
	Rat r1, r2, r3;
	vlong m;

	sprintf(b, "-1");
	if (!ratparse(&t1, s1) || !ratparse(&t2, s2) || !ratparse(&t3, s3))
		return;

	r1 = ratscale(t1, t2.d * t3.d);
	r2 = ratscale(t2, t1.d * t3.d);
	r3 = ratscale(t3, t1.d * t2.d);
	if (r1.d == 0 || r2.d == 0 || r3.d == 0)
		return;

	m = t1.d * t3.d;
	r2.n = multiple(r1.n, m) + m;
	r2.d = t2.d;
	if (!(r1.n < r2.n && r2.n < r3.n))
		return;

	sprintf(b, "%lld/%lld", r2.n / m, r2.d);
}

void
test(const char *s1, const char *s2, const char *s3, const char *r)
{
	char b[128];

	solve(s1, s2, s3, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("1/2", "?/8", "3/4", "5/8");
	test("3/20", "?/2", "4/10", "-1");
	test("3/20", "?/20", "10/20", "4/20");

	return 0;
}
