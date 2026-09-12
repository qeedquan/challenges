/*

Find an NP-complete problem that covers all finite ASCII strings, and present a solver for the problem in the programming language of your choice.

By the definition, if there is a finite ASCII string input that yields an output that is neither truthy nor falsy, your submission is invalid. This prevents trivial solutions like Python-esque exec.

Our policy about what's truthy and what's falsy applies.

This is a code-golf; the solver with the fewest bytes wins.

This is not a restricted-complexity; the solver may use an arbitrarily long time and an arbitrarily big space.

Your submission must include a proof that the problem in question is indeed NP-complete.

*/

#include <assert.h>
#include <stdio.h>

/*

@Lucenaposition

Deciding whether there exists some x such that x^2 ≡ a mod b with 0 ≤ x < y ∧ x ∈ Z is NP-complete.
See https://www.sciencedirect.com/science/article/pii/0022000078900442 for more details.
Note that this uses 0 ≤ x ≤ y ∧ x ∈ Z which is merely a trivial change as it is equivalent to 0 ≤ x < y + 1 ∧ x ∈ Z.

*/

int
solve(const char *s)
{
	int a, b;
	int x, y;

	a = 0;
	b = 1;
	y = 0;
	for (; *s; s++) {
		switch (*s) {
		case 'x':
			a++;
			break;
		case 'y':
			b++;
			break;
		case 'z':
			y++;
			break;
		}
	}

	for (x = 0; x < y; x++) {
		if (((x * x) % b) == a)
			return x;
	}
	return -1;
}

int
main()
{
	printf("%d\n", solve("yyzzz"));
	return 0;
}
