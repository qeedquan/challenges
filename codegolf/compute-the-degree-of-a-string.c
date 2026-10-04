/*

The input is a string made of the letters a,b,c only. The output is an integer representing the degree of the sequence. The degree of a sequence is computed as follows:

Assume that each of the letters a,b,c is the vertex of a triangle.
Assume that you start a walk on the first letter, and keep walking towards the next letter, until the end of the sequence.
The degree is the net number of times that you surrounds the center of the triangle clockwise.
To clarify the definition, here are some examples:

abca -> 1: single round clockwise. Similarly, bcab->1 and cabc->1.
accbbbaa -> -1: single round counter-clockwise.
abcacba -> 0: one round clockwise and one round counter-clockwise (1-1=0).
abcabcab -> 2: two complete rounds clockwise (plus one partial round which does not count).
abababababababcababababababab -> 1: many partial rounds, but only one complete round.
abcbca -> 1: a complete round, even though there are moves back and forth along the way.
abcabcacb -> 1: two rounds and then two steps back, which leaves us with less than two complete rounds.

The shortest code in byte wins. Please explain your solutions.

*/

#include <assert.h>
#include <stdio.h>

/*

ported from @Arnauld solution

Method
Move types are identified by computing the concatenation of the ASCII codes of the previous and current characters and reducing it modulo 80 and modulo 3, resulting in 0 for counter-clockwise, 1 for no move and 2 for clockwise.

previous char.	current char.	concat. of ASCII codes	mod 80	mod 3	move type
a	a	9797	37	1	no move
a	b	9798	38	2	clockwise
a	c	9799	39	0	counter-clockwise
b	a	9897	57	0	counter-clockwise
b	b	9898	58	1	no move
b	c	9899	59	2	clockwise
c	a	9997	77	2	clockwise
c	b	9998	78	0	counter-clockwise
c	c	9999	79	1	no move

Search code
let A = [ 97, 98, 99 ];
for(let m0 = 1; m0 < 1000; m0++) {
  for(let m1 = 1; m1 <= m0; m1++) {
    if(A.every(p =>
      A.every(c => {
        let r = p - c ? c == p + 1 || c == 97 && p == 99 ? 1 : -1 : 0;
        let v = (p + [c]) % m0 % m1 - 1;
        return v == r;
      })
    )) {
      console.log(m0, m1);
    }
  }
}

*/

int
degree(const char *s)
{
	int a, b, r;
	size_t i;

	r = 0;
	for (i = 0; s[i]; i++) {
		a = s[i];
		b = (s[i + 1]) ? s[i + 1] : s[0];
		r += ((100 * a + b) % 80 % 3) - 1;
	}
	return r / 3;
}

int
main()
{
	assert(degree("abca") == 1);
	assert(degree("bcab") == 1);
	assert(degree("cabc") == 1);
	assert(degree("accbbbaa") == -1);
	assert(degree("abcacba") == 0);
	assert(degree("abcabcab") == 2);
	assert(degree("abababababababcababababababab") == 1);
	assert(degree("abcbca") == 1);
	assert(degree("abcabcacb") == 1);

	return 0;
}
