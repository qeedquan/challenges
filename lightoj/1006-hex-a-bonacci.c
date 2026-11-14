/*

Given a code (not optimized and might have overflow problems), and necessary inputs, you have to find the output of the code. The code is as follows:

int a, b, c, d, e, f;
int fn(int n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    return fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6);
}
int main() {
    int n, cases;
    scanf("%d", &cases);
    for (int caseno = 1; caseno <= cases; ++caseno) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", caseno, fn(n) % 10000007);
    }
    return 0;
}
Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case contains seven integers a, b, c, d, e, f and n. All integers will be non-negative and 0 ≤ n ≤ 10000 and others will fit into 32-bit integers.

Output
For each case, print the output of the given code. The given code may have integer overflow problem in the compiler, so be careful.

Sample
Input	Output
6
0 1 2 3 4 5 20
1 2 3 4 5 6 10000
3 2 1 5 0 1 9
4 12 9 4 5 6 15
9 8 7 6 5 4 3
3 4 3 2 54 5 4

Case 1: 216339
Case 2: 5333347
Case 3: 79
Case 4: 16636
Case 5: 6
Case 6: 54

*/

#include <assert.h>
#include <stdlib.h>

typedef long long vlong;

vlong *
build(vlong a, vlong b, vlong c, vlong d, vlong e, vlong f, vlong n)
{
	static const vlong mod = 10000007;

	vlong *p;
	vlong i;

	if (n < 0)
		return NULL;

	p = calloc(n + 7, sizeof(*p));
	if (!p)
		return NULL;

	p[0] = a;
	p[1] = b;
	p[2] = c;
	p[3] = d;
	p[4] = e;
	p[5] = f;
	for (i = 6; i <= n; i++)
		p[i] = (p[i - 1] + p[i - 2] + p[i - 3] + p[i - 4] + p[i - 5] + p[i - 6]) % mod;

	return p;
}

void
test(vlong a, vlong b, vlong c, vlong d, vlong e, vlong f, vlong n, vlong r)
{
	vlong *p;

	p = build(a, b, c, d, e, f, n);
	assert(p);
	assert(p[n] == r);
	free(p);
}

int
main()
{
	test(0, 1, 2, 3, 4, 5, 20, 216339);
	test(1, 2, 3, 4, 5, 6, 10000, 5333347);
	test(3, 2, 1, 5, 0, 1, 9, 79);
	test(4, 12, 9, 4, 5, 6, 15, 16636);
	test(9, 8, 7, 6, 5, 4, 3, 6);
	test(3, 4, 3, 2, 54, 5, 4, 54);

	return 0;
}
