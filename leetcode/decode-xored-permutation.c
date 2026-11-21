/*

There is an integer array perm that is a permutation of the first n positive integers, where n is always odd.

It was encoded into another integer array encoded of length n - 1, such that encoded[i] = perm[i] XOR perm[i + 1]. For example, if perm = [1,3,2], then encoded = [2,1].

Given the encoded array, return the original array perm. It is guaranteed that the answer exists and is unique.

Example 1:

Input: encoded = [3,1]
Output: [1,2,3]
Explanation: If perm = [1,2,3], then encoded = [1 XOR 2,2 XOR 3] = [3,1]

Example 2:

Input: encoded = [6,5,4,6]
Output: [2,4,1,5,3]


Constraints:

3 <= n < 10^5
n is odd.
encoded.length == n - 1

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

XOR Basic Rules
---------------

x^x = 0
0^x = x
with the rule 1 and 2 , we can have: x^x^y = y. the element occurs twice would be removed.
if x^y = z , then x = y^z and y = x^z

XOR from 1 to n
---------------
Suppose f(n) = 1^2^3^4^5 .... ^n .
If n is an odd number, then we can observe the following things:

f(1) = 1
f(3) = 1^2^3 = 0
f(5) = 1^2^3^4^5 = 1
f(7) = 1^2^3^4^5^6^7 = 0
f(9) = 1^2^3^4^5^6^7^8^9 = 1
... ...
so, f(n) = [ (n-1)/2 + 1 ] % 2 - (n is odd number)

Solution
--------
Encode = { (p1^p2), (p2^p3), (p3^p4), ... } - p is the permutation array

so, if xor the odd index of encoded[] array,

encoded[1] = p2 ^ p3;
encoded[3] = p4 ^ p5;
encoded[5] = p6 ^ p7;
......
we can get: f(m) = p2 ^ p3 ^ p4 ...pn, without the p1

with the XOR rule 3, we know

p1 = f(n) ^ f(m)

with the XOR rule 4, we know encoded[0] = p1^p2 then
p2 = p1 ^ encoded[0]

So,

p[i+1] = p[i] ^ encoded[i]

*/

size_t
decode(int *a, size_t n, int *r)
{
	size_t i;
	int x, y;

	if (n == 0)
		return 0;

	if (n == 1) {
		r[0] = a[0];
		return 1;
	}

	x = ((n / 2) + 1) % 2;
	y = a[1];
	for (i = 3; i < n; i += 2)
		y ^= a[i];
	x ^= y;

	r[0] = x;
	for (i = 0; i < n; i++) {
		x ^= a[i];
		r[i + 1] = x;
	}

	return n + 1;
}

void
test(int *a, size_t n, int *r, size_t nr)
{
	int p[16];
	size_t np;

	np = decode(a, n, p);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main()
{
	int a1[] = { 3, 1 };
	int a2[] = { 6, 5, 4, 6 };

	int r1[] = { 1, 2, 3 };
	int r2[] = { 2, 4, 1, 5, 3 };

	test(a1, nelem(a1), r1, nelem(r1));
	test(a2, nelem(a2), r2, nelem(r2));

	return 0;
}
