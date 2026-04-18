/*

Mr. Anderson is in a relationship with a very suspicious and jealous girlfriend. She is always checking
Anderson’s phone logs and texts to find out he is up to. Feeling that his private space is getting
violated, he decided to put a pattern locker on his phone.
This pattern locker comes with a 9 dots arranged on a 3x3 square grid by default. One has to
drag through several dots to record a pattern. Then to unlock the phone, one needs to replicate the
same pattern recorded before. If we assume that each dot is assigned a unique number then a pattern
is nothing more than a sequence of digits. The pattern locker requires that no digit appears in the
sequence more than once.
Here is an example of such a pattern locker and some valid and invalid recorded pattern:

Even after recording a hard to crack pattern, Mr. Anderson doesn’t feel quite comfortable. He is
worried that his girlfriend might try all possible sequences to break his pattern. He wants to know how
many different pattern sequences are possible for a given grid size, minimum and maximum numbers
of dots recorded in patterns.
You have to help Mr. Anderson in counting the number of possible such sequences.

Input
The first line of the input will give the number of test cases, T (1 ≤ T ≤ 10000). Then T test cases
follow in separate lines. Each test case consists of three numbers L, M, N separated by a single space
in between two numbers. The first number L (1 < L ≤ 100) denotes the number of rows and columns
in the grid. The second number M (1 ≤ M ≤ L ∗ L) denotes minimum number of dots to be included
in a pattern and the third number N (M ≤ N ≤ L ∗ L) denotes the maximum number of dots to be
included in the pattern.

Output
For each test case, you need to print the test case number X in the format ‘Case X: ’. This will be
followed by the count of possible sequences for the given grid size, minimum and maximum number of
dots in a sequence. Since the count can be pretty big, you need to print the value of the count modulo
10000000000007 (1 followed by 12 zeros followed by 7). There is no new-line between cases.

Sample Input
2
3 4 9
3 1 9

Sample Output
Case 1: 985824
Case 2: 986409

*/

#include <assert.h>

typedef long long vlong;

vlong
solve(vlong L, vlong M, vlong N)
{
	static const vlong mod = 10000000000007LL;

	vlong L2, i, r, w;

	r = 0;
	w = 1;
	L2 = L * L;
	for (i = 1; i < M; i++) {
		w *= (L2 - i + 1);
		w %= mod;
	}
	for (i = M; i <= N; i++) {
		w *= (L2 - i + 1);
		w %= mod;
		r += w;
		r %= mod;
	}
	return r;
}

int
main()
{
	assert(solve(3, 4, 9) == 985824);
	assert(solve(3, 1, 9) == 986409);

	return 0;
}
