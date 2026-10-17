/*

In a secret lab corridor, there are emitters and gates: A number represents a laser emitter with a certain frequency, a 0 represents an inactive gate. If two emitters of the same frequency face each other with only inactive gates (0) in between, their beams meet and activate the entire stretch of gates in between. But if any other emitter is in the way, the beam is blocked.

Your task
Write a program that simulates the beam activation.

Input
A list/array of nonnegative integers.

Output
The transformed list/array, with activated gates.

Winning Criteria
The shortest correct program (measured in bytes) wins. In the event of a tie, the earliest posted answer wins.

Sample data
Example 1 (Simple case)

[0,2,0,0,2]
→ [0,2,2,2,2]
Example 2 (Gate between emitters)

[0,2,0,1,0,2]
→ [0,2,0,1,0,2]
Example 3 (A more complex example)

[0,2,0,2,5,0,0,5,1]
→ [0,2,2,2,5,5,5,5,1]
Example 4 (Consecutive emitters)

[3,0,0,3,0,3]
→ [3,3,3,3,3,3]

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

/*

@Adamátor

We left scan the array with the reversed logical OR function, causing all zeros to be replaced with the previous non-zero element:

[0,2,0,1,0,2,0,0,2,0]
[0,2,2,1,1,2,2,2,2,2]
Next we do the same thing, but in reverse:

[0,2,0,1,0,2,0,0,2,0]
[2,2,1,1,2,2,2,2,2,0]
Out of the two resulting arrays, we take equal elements and set all other elements to 0:

[0,2,2,1,1,2,2,2,2,2]
[2,2,1,1,2,2,2,2,2,0]
[0,2,0,1,0,2,2,2,2,0]

*/

void
activate(int *a, size_t n, int *r)
{
	size_t i, j;
	int *l, m[2];

	m[0] = 0;
	m[1] = 0;
	l = r + n;
	for (i = 0; i < n; i++) {
		j = n - i - 1;
		l[i] = a[i];
		r[j] = a[j];

		if (!l[i])
			l[i] = m[0];
		else
			m[0] = a[i];

		if (!r[j])
			r[j] = m[1];
		else
			m[1] = a[j];
	}

	for (i = 0; i < n; i++) {
		if (r[i] != l[i])
			r[i] = 0;
	}
}

void
test(int *a, size_t n, int *r)
{
	int x[32];

	activate(a, n, x);
	print(x, n);
	assert(!memcmp(x, r, sizeof(*r) * n));
}

int
main()
{
	int a1[] = { 0, 2, 0, 0, 2 };
	int a2[] = { 0, 2, 0, 1, 0, 2 };
	int a3[] = { 0, 2, 0, 2, 5, 0, 0, 5, 1 };
	int a4[] = { 3, 0, 0, 3, 0, 3 };
	int a5[] = { 0, 2, 0, 1, 0, 2, 0, 0, 2, 0 };

	int r1[] = { 0, 2, 2, 2, 2 };
	int r2[] = { 0, 2, 0, 1, 0, 2 };
	int r3[] = { 0, 2, 2, 2, 5, 5, 5, 5, 1 };
	int r4[] = { 3, 3, 3, 3, 3, 3 };
	int r5[] = { 0, 2, 0, 1, 0, 2, 2, 2, 2, 0 };

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);
	test(a5, nelem(a5), r5);

	return 0;
}
