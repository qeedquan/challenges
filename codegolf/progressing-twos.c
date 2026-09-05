/*

Given an positive integer n (including 0 if you decide to support it), output all numbers in the generated sequence up to the index n. For the current test cases of the current challenge numbers are one-indexed. Feel free to submit 0-indexed answers though.

Base sequence
We start from this sequence (NOT, but quite similar to, A160242):

1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, ...
This sequence should be more understandable after formatting:

1,       2,       1,
1,    2, 2, 2,    1,
1, 2, 2, 2, 2, 2, 1,
and so on ...
However, our point is not to output this sequence. See the below procedure.

Adding the sequence
Here's an example of adding the sequence. Here, our sequence starts with 0:

We collect all intermediate results into the sequence.
  The sequence
    |     Output sequence: [0]
    v
0 + 1 = 1 Output sequence: [0, 1]
1 + 2 = 3 Output sequence: [0, 1, 3]
3 + 1 = 4 Output sequence: [0, 1, 3, 4]
4 + 1 = 5 Output sequence: [0, 1, 3, 4, 5]
...

Our generated sequence is therefore

0, 1, 3, 4, ...

Test cases
Here is a sample program outputting the sequence up to the input.

3 -> [0, 1, 3]
10 -> [0, 1, 3, 4, 5, 7, 9, 11, 12, 13]

def f8(seq):
    seen = set()
    return [x for x in seq if x not in seen and not seen.add(x)]

def evolve(old,new):
    return new[len(old):]

startWith = eval(input())
out = []
i=1
while True:
    out += [i,(i**2-1)//2,(i**2-1)//2+1]
    out.sort()
    out = f8(out)
    if len(out) >= 2*startWith:
        print(out[:startWith])
        break
    i += 2

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

@xnor

f(n) = 2*n + 1 - floor(sqrt(n)) - floor(sqrt(n + 1))

This can also be split up as

f(n) = Sum[k in {n, n+1}] (k - floor(sqrt(k)))

Note that k - sqrt(k) is the number of non-squares from 1 to inclusive.

*/

int
twosp(int n)
{
	if (n < 0)
		return 0;

	return (2 * n) + 1 - floor(sqrt(n)) - floor(sqrt(n + 1));
}

int
main(void)
{
	static const int tab[] = {0, 1, 3, 4, 5, 7, 9, 11, 12, 13};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(twosp(i) == tab[i]);

	return 0;
}
