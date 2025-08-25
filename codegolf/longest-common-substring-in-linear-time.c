/*

This challenge is about writing code to solve the following problem.

Given two strings A and B, your code should output the start and end indices of a substring of A with the following properties.

The substring of A should also match some substring of B.
There should be no longer substring of A that satisfies the first property.
For example:

A = xxxappleyyyyyyy

B = zapplezzz
The substring apple with indices 4 8 (indexing from 1) would be a valid output.

Functionality

You can assume the input will be on standard in or in a file in the local directory, that is your choice. The file format will simply be two strings, separated by a new line. The answer should be a full program and not just a function.

I would eventually like to test your code on two substrings taken from the strings in http://hgdownload.cse.ucsc.edu/goldenPath/hg38/chromosomes/ .

Score

This is code-golf with a twist. Your code must be run in O(n) time, where n is the total length of the input.

Languages and libraries

You can use any language which has a freely available compiler/interpreter/etc. for Linux. You should only use standard open source libraries not designed to solve this task. In case of dispute, I will count this as any library which either comes as standard with your language or one that you can install in a default ubuntu machine from a default repository.

Useful information

There are at least two ways to solve this problem in linear time. One is to first compute the suffix tree and the second is to first compute the suffix array and the LCP array.

Here is a full and (perhaps over-)detailed explanation of linear time suffix tree construction (it turns out some of the figures are messed up unfortunately).
http://web.stanford.edu/~mjkay/gusfield.pdf

There is also a very nice SO answer about linear time suffix tree construction at https://stackoverflow.com/questions/9452701/ukkonens-suffix-tree-algorithm-in-plain-english.
It includes a link to source code too.

Another detailed explanation can be found here, this time giving a full solution in C.
https://programmerspatch.blogspot.com/2013/02/ukkonens-suffix-tree-algorithm.html

Section 2 of http://www.cs.cmu.edu/~guyb/realworld/papersS04/KaSa03.pdf gives a linear time suffix array construction algorithm and Appendix A has C++ source code.

This answer tells you how then to compute the longest common substring
https://cs.stackexchange.com/questions/9555/computing-the-longest-common-substring-of-two-strings-using-suffix-arrays .

Section 5 of
https://courses.csail.mit.edu/6.851/spring12/scribe/lec16.pdf which also has an associated video lecture
https://courses.csail.mit.edu/6.851/spring12/lectures/L16.html also explains the same algorithm starting at 1:16:00.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define mid(a, b, c) max(min(a, b), min(max(a, b), c))

int
cmps(const void *a, const void *b)
{
	const char *s, *t;

	s = *(const char **)a;
	t = *(const char **)b;
	return strcmp(s, t);
}

int *
sfabf(const char *s, int n)
{
	const char **p;
	int *sa, i;

	sa = calloc(n, sizeof(*sa));
	p = calloc(n, sizeof(*p));
	if (!sa || !p)
		goto error;

	for (i = 0; i < n; i++)
		p[i] = s + i;

	qsort(p, n, sizeof(*p), cmps);

	for (i = 0; i < n; i++)
		sa[i] = p[i] - s;

	if (0) {
	error:
		free(sa);
		sa = NULL;
	}

	free(p);
	return sa;
}

bool
leq2(int a1, int a2, int b1, int b2)
{
	return a1 < b1 || (a1 == b1 && a2 <= b2);
}

bool
leq3(int a1, int a2, int a3, int b1, int b2, int b3)
{
	return a1 < b1 || (a1 == b1 && leq2(a2, a3, b2, b3));
}

void
radixpass(int *a, int *b, int *c, int *r, int n, int K)
{
	int i, s, t;

	memset(c, 0, sizeof(*c) * (K + 1));
	for (i = 0; i < n; i++)
		c[r[a[i]]]++;

	s = 0;
	for (i = 0; i <= K; i++) {
		t = c[i];
		c[i] = s;
		s += t;
	}
	for (i = 0; i < n; i++)
		b[c[r[a[i]]]++] = a[i];
}

int
construct(int *s, int *SA, int n, int K)
{
	int *s0, *s12;
	int *SA0, *SA12;
	int *c;
	int n0, n1, n2, n02;
	int name, c0, c1, c2;
	int i, j, k, p, t;
	int r;
	bool b;

	r = 0;
	n0 = (n + 2) / 3;
	n1 = (n + 1) / 3;
	n2 = n / 3;
	n02 = n0 + n2;
	s12 = calloc(n02 + 3, sizeof(*s12));
	SA12 = calloc(n02 + 3, sizeof(*SA12));
	s0 = calloc(n0, sizeof(*s0));
	SA0 = calloc(n0, sizeof(*SA0));
	c = calloc(K + 1, sizeof(*c));

	if (!s12 || !SA12 || !s0 || !SA0 || !c)
		goto error;

	for (i = j = 0; i < n + (n0 - n1); i++) {
		if (i % 3)
			s12[j++] = i;
	}

	radixpass(s12, SA12, c, s + 2, n02, K);
	radixpass(SA12, s12, c, s + 1, n02, K);
	radixpass(s12, SA12, c, s, n02, K);

	name = 0;
	c0 = c1 = c2 = -1;
	for (i = 0; i < n02; i++) {
		if (s[SA12[i]] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2) {
			name++;
			c0 = s[SA12[i]];
			c1 = s[SA12[i] + 1];
			c2 = s[SA12[i] + 2];
		}
		if (SA12[i] % 3 == 1) {
			s12[SA12[i] / 3] = name;
		} else {
			s12[SA12[i] / 3 + n0] = name;
		}
	}
	if (name < n02) {
		construct(s12, SA12, n02, name);
		for (i = 0; i < n02; i++)
			s12[SA12[i]] = i + 1;
	} else {
		for (i = 0; i < n02; i++)
			SA12[s12[i] - 1] = i;
	}
	for (i = j = 0; i < n02; i++) {
		if (SA12[i] < n0)
			s0[j++] = 3 * SA12[i];
	}
	radixpass(s0, SA0, c, s, n0, K);

	t = n0 - n1;
	for (p = k = 0; k < n; k++) {
		i = (SA12[t] < n0) ? (SA12[t] * 3 + 1) : ((SA12[t] - n0) * 3 + 2);
		j = SA0[p];

		if (SA12[t] < n0)
			b = leq2(s[i], s12[SA12[t] + n0], s[j], s12[j / 3]);
		else
			b = leq3(s[i], s[i + 1], s12[SA12[t] - n0 + 1], s[j], s[j + 1], s12[(j / 3) + n0]);

		if (b) {
			SA[k] = i;
			t++;
			if (t == n02)
				for (k++; p < n0; p++, k++)
					SA[k] = SA0[p];
		} else {
			SA[k] = j;
			p++;
			if (p == n0) {
				for (k++; t < n02; t++, k++)
					SA[k] = (SA12[t] < n0) ? (SA12[t] * 3 + 1) : ((SA12[t] - n0) * 3 + 2);
			}
		}
	}

	if (0) {
	error:
		r = -errno;
	}

	free(s12);
	free(SA12);
	free(SA0);
	free(s0);
	free(c);

	return r;
}

// https://users.cs.fiu.edu/~weiss/dsaa_c++4/code/SuffixArray.cpp
// http://www.cs.cmu.edu/~guyb/realworld/papersS04/KaSa03.pdf
int *
sfa(const char *s, int n)
{
	int *sa;
	int *ss;
	int i;

	sa = calloc(n + 3, sizeof(*sa));
	ss = calloc(n + 3, sizeof(*ss));
	if (!sa || !ss)
		goto error;

	for (i = 0; i < n; i++)
		ss[i] = s[i];

	if (construct(ss, sa, n, 256) < 0)
		goto error;

	if (0) {
	error:
		free(sa);
		sa = NULL;
	}
	free(ss);

	return sa;
}

/*


@Mitch Schwartz

This uses the skew algorithm described in "Simple Linear Work Suffix Array Construction" by Kärkkäinen and Sanders. The C++ implementation included in that paper already feels a little "golfy", but there is still plenty of room for making it shorter. For example, we can recurse until arriving at an array of length one, instead of short circuiting as in the paper, without violating the O(n) requirement.

For the LCP part, I followed "Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its Applications" by Kasai et al.

*/

int
solve(const char *s1, const char *s2, int p[2])
{
	int *sa, *ia;
	int n1, n2, n;
	int i, j;
	int h, m;
	char *s;
	int r;

	p[0] = p[1] = 0;
	r = 0;

	n1 = strlen(s1);
	n2 = strlen(s2);
	n = n1 + n2 + 2;
	s = calloc(n + 1, sizeof(*s));
	ia = calloc(n, sizeof(*ia));
	if (!s || !ia)
		goto error;

	sprintf(s, "%s!%s#", s1, s2);

	sa = sfa(s, n);
	if (!sa)
		goto error;

	for (i = 0; i < n; i++)
		ia[sa[i]] = i;

	for (i = h = m = 0; i < n; i++) {
		if (!ia[i])
			continue;

		j = sa[ia[i] - 1];
		while (s[i + h] == s[j + h])
			h += 1;

		if (h > m && n1 == mid(i, j, n1)) {
			m = h;
			p[0] = min(i, j);
			p[1] = p[0] + h;
		}

		if (h > 0)
			h -= 1;
	}
	if (p[0] && p[1])
		p[0] += 1;

	if (0) {
	error:
		r = -errno;
	}

	free(sa);
	free(ia);
	free(s);
	return r;
}

void
test(const char *s1, const char *s2, int p0, int p1)
{
	int p[2];

	assert(solve(s1, s2, p) >= 0);
	printf("%d %d\n", p[0], p[1]);
	assert(p[0] == p0);
	assert(p[1] == p1);
}

int
main()
{
	test("xxxappleyyyyyyy", "zapplezzz", 4, 8);
	test("abc", "def", 0, 0);
	return 0;
}
