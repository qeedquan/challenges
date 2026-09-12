/*

Consider the following sequence:

0 1 3 2 5 4 8 6 7 12 9 10 11 17 13 14 15 16 23 ...
Looks pretty pattern-less, right? Here's how it works. Starting with 0, jump up n integers, with n starting at 1. That's the next number in the sequence. Then, append any numbers "skipped" and that haven't been seen yet in ascending order. Then, increment n and jump from the last number appended. Repeat this pattern.

So, for example, when we reach 11, we're at n=5. We increment n to be n=6, jump up to 17, then append 13 14 15 16 since those haven't been seen yet. Our next jump is n=7, so the next element in the sequence is 23.

The Challenge
Given input x, output the xth term of this sequence, the first x terms of the sequence, or build an infinite list of the terms of the sequence. You can choose 0- or 1-indexing.

I/O and Rules
The input and output can be given by any convenient method.
The input and output can be assumed to fit in your language's native number type.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

@Doorknob

Defines a function f that takes 0-indexed n and produces the nth number in the sequence.

We can analyze the sequence as follows:

f(n)  = n   where n = 0, 1

f(2)  = 3   // 2 and 3 are swapped
f(3)  = 2

f(4)  = 5   // (+2,+3)
f(6)  = 8   // (+3,+4)
f(9)  = 12  // (+4,+5)
f(13) = 17  // (...)
...

f(n)  = n-1 // for all cases not yet covered
First we handle the middle section:

for(t=4,d=2;d<x;t+=d++)x-t||(d+=x+=d);
Note that the arguments on the left (4, 6, 9, 13, ...) follow a pattern: first add two, then add three, then add four, and so on. We start at t=4 and add d (which starts at 2) each iteration of the loop, incrementing d in the process.

The body of the loop is more interesting. Remember that we want to map 4 to 5, 6 to 8, 9 to 12, etc.; that's just adding d-1 if x is t. However, this logic comes before the last case, f(n) = n - 1, so we know we're going to subtract 1 at the end. Therefore, we can simply add d if x == t (x-t||(x+=d)). However, we will also need to break out of the loop immediately after this -- so we add that to d to get the absurd-looking d+=x+=d, which will always make the d<x condition fail.

This covers everything except for the first four values. Looking at them in binary, we get:

00 -> 00
01 -> 01
10 -> 11
11 -> 10
So, we want to flip the last bit if 2 <= x < 4. This is accomplished with x^x/2. x/2 gives the second least significant bit, so XORing this with the original number flips the last bit if the number is 2 or 3.

*/

int
jumpup(int n)
{
	int i, j;

	if (n < 0)
		return 0;

	j = 4;
	for (i = 2; i < n; i++) {
		if (n == j) {
			n += i;
			i += n;
		}
		j += i;
	}

	if (n < 4)
		return n ^ (n >> 1);
	return n - 1;
}

int
main(void)
{
	static const int tab[] = {0, 1, 3, 2, 5, 4, 8, 6, 7, 12, 9, 10, 11, 17, 13, 14, 15, 16, 23, 18, 19, 20, 21, 22, 30, 24, 25, 26, 27, 28, 29};
	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(jumpup(i) == tab[i]);

	return 0;
}
