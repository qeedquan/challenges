/*

Objective
There are seven monoids with three elements, up to isomorphism.
Give implementations to all of them, such that their domains are all the same, and that they have the same identity element.

Mathematical explanation
A monoid is a set M endowed with a binary operator ∗:M×M→M, that satisfies the following criteria:

For every x,y,z∈M (no need to be pairwise distinct), it holds that (x∗y)∗z=x∗(y∗z). This property is called associativity.
There exists an element e∈M such that, for every x∈M, it holds that e∗x=x∗e=x.
Then e is called the identity element.
Note that an existence of the identity element implies its uniqueness, for if e and f both are identity elements, it holds that e=e∗f=f.

Two monoids M (endowed with ∗) and N (endowed with ⋆) are said to be isomorphic if,
there exists a bijection ϕ:M→N that satisfies the following criteria:

For every x,y∈M (again, no need to be distinct), it holds that ϕ(x∗y)=ϕ(x)⋆ϕ(y).

Provided that e is the identity element of M, ϕ(e) is the identity element of N.

Up to isomorphism, there exist seven monoids with three elements. Their "operation tables" are given as follows:

 |eAB    |eAB    |eAB    |eAB    |eAB    |eAB    |eAB
-----   -----   -----   -----   -----   -----   -----
e|eAB   e|eAB   e|eAB   e|eAB   e|eAB   e|eAB   e|eAB
A|ABe   A|AAA   A|AAB   A|AAA   A|AAB   A|AAA   A|AAB
B|BeA   B|BAe   B|BBA   B|BAA   B|BBB   B|BBB   B|BAB

Note that the last two examples are not symmetric by the main diagonal (or in mathematical terms, not commutative).

I/O format
To re-phrase the rules specified in the objective, all the implementations of the seven monoids shall have the same choices of the three valid input values,
and one of the three chosen valid input values shall consistently act as the identity element of each monoid.

Though this challenge asks for seven functions, it is a valid format to give one function that outputs a tuple of the seven outputs from the seven monoids.
In this case, you can freely order the contents of the outputted tuple, but please specify how they correspond to the operation tables above.

Otherwise flexible. In particular, for each monoid, you may have the roles of the two non-identity elements swapped.

Ungolfed solution (Haskell)
Here, the three valid input values are Nothing, Just False, and Just True. Nothing acts as the identity element throughout.

Though this one isn't particularly golfed in any means, I hope that this gives a hint for how to golf them.

import Data.Bits
import Data.Semigroup
import Data.Coerce

f1, f2, f3, f4, f5, f6, f7 :: Maybe Bool -> Maybe Bool -> Maybe Bool

-- f1: Cyclic group with 3 elements
f1 (Just x) (Just y) = if x == y then Just (not x) else Nothing
f1 x@(Just _) _ = x
f1 _ y = y

-- f2: {1, 0, -1} under multiplication
f2 (Just True) (Just True) = Nothing
f2 (Just _) (Just _) = Just False
f2 x@(Just _) _ = x
f2 _ y = y

-- f3: Extension of cyclic group with 2 elements
f3 = coerce ((<>) :: Maybe (Xor Bool) -> Maybe (Xor Bool) -> Maybe (Xor Bool))

-- f4: Extension of zero semigroup with 2 elements
f4 (Just _) (Just _) = Just False
f4 x@(Just _) _ = x
f4 _ y = y

-- f5: Chain with 3 elements
f5 = max

-- f6: Extension of left zero semigroup with 2 elements
f6 = coerce ((<>) :: Maybe (First Bool) -> Maybe (First Bool) -> Maybe (First Bool))

-- f7: Extension of right zero semigroup with 2 elements
f7 = coerce ((<>) :: Maybe (Last Bool) -> Maybe (Last Bool) -> Maybe (Last Bool))

*/

#include <stdio.h>

/*

@Arnauld

eAB mapped to 0, 1, 2.

Returns a tuple of 7 entries in the order provided in the challenge, except for the 2nd and 3rd ones which are swapped.

Trivial cases
Three cases are dealt with immediately with 1, y and x. The reduction modulo 3 has no effect on them.

This includes the two non-commutative cases. From this point on, we are free to use commutative operations.

Non-trivial cases
The first one uses the sum.

x       y       x+y   mod3
1 (A)	1 (A)	2	  2 (B)
1 (A)	2 (B)	3	  0 (e)
2 (B)	1 (A)	3	  0 (e)
2 (B)	2 (B)	4	  1 (A)
The 3 other ones are based on the product.

x       y       p=x×y  mod3
1 (A)	1 (A)	1	   1 (A)
1 (A)	2 (B)	2	   2 (B)
2 (B)	1 (A)	2	   2 (B)
2 (B)	2 (B)	4	   1 (A)

x       y       p   p<4     mod3
1 (A)	1 (A)	1	true	1 (A)
1 (A)	2 (B)	2	true	1 (A)
2 (B)	1 (A)	2	true	1 (A)
2 (B)	2 (B)	4	false	0 (e)

x       y       p   p xor 12   mod3
1 (A)	1 (A)	1	13	       1 (A)
1 (A)	2 (B)	2	14	       2 (B)
2 (B)	1 (A)	2	14	       2 (B)
2 (B)	2 (B)	4	8	       2 (B)

*/

void
f(int x, int y, int r[7])
{
	int i, p;

	p = x * y;
	r[0] = x + y;
	r[1] = p;
	r[2] = p < 4;
	r[3] = 1;
	r[4] = p ^ 12;
	r[5] = y;
	r[6] = x;
	for (i = 0; i < 7; i++) {
		if (p)
			r[i] = r[i] % 3;
		else
			r[i] = x | y;
	}
}

void
repeat(const char *s, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%s", s);
	printf("\n");
}

void
table()
{
	static const char sym[] = "eAB";

	int i, x, y, r[3][7];

	repeat(" |eAB  ", 7);
	repeat("-+---  ", 7);
	for (y = 0; y <= 2; y++) {
		for (x = 0; x < 3; x++)
			f(x, y, r[x]);

		for (i = 0; i < 7; i++)
			printf("%c|%c%c%c  ", sym[y], sym[r[0][i]], sym[r[1][i]], sym[r[2][i]]);
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	table();
	return 0;
}
