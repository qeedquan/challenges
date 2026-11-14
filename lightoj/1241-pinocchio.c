/*

You must have heard the name of Pinocchio. If you never heard of him, don't panic; I am here to help you. But why am I introducing you to Pinocchio? Cause there is an interesting (and also quite strange) fact about him. Pinocchio is a boy who lives in a certain village. He is a little boy, who is prone to telling lies, fabricating stories, and exaggerating or creating tall tales for various reasons. But the strange fact is, when he does this, his nose gets longer. But when he tells the truth his nose gets back to the normal size which is 2 cm. Usually, when he wakes up in the morning his nose gets back to normal size. When he tells a lie, his nose grows at least 1 cm and at most 5 cm.

https://static.lightoj.com/images/problem-1241/pino1-1603774598064.jpg?style=haveborder

There is a common paradox related to him. What if he says, "My nose grows now." You may wonder why the simple-looking statement leads to a paradox. The result of this deadly statement is noted below:

Assume that this sentence is true:

Which means that Pinocchio's nose grows now because he truthfully says it is, but then
Pinocchio's nose does not grow now because it grows only as Pinocchio lies, but then
Pinocchio's nose grows now because Pinocchio's nose does not grow now, and Pinocchio trustfully says it grows now, and it is false, that makes Pinocchio's sentence to be false, but then
Pinocchio's nose does not grow now because Pinocchio's nose grows now, and Pinocchio trustfully says it grows now, and it is true that makes Pinocchio's sentence to be true, but then
And so on ad infinitum.
Now assume that the sentence is false:

Which means that Pinocchio's nose does not grow now because he falsely says it is, but then
Pinocchio's nose grows now because it grows only as Pinocchio lies, but then
Pinocchio's nose does not grow now because Pinocchio's nose grows now, and Pinocchio falsely says it grows now, and it is false that makes Pinocchio's sentence to be true, but then
Pinocchio's nose grows now because Pinocchio's nose does not grow now, and Pinocchio falsely says it grows now, and it is true, that makes Pinocchio's sentence to be false, but then
And so on ad infinitum.
Now you are given some sizes of his nose in a day. Assume that he hasn't told any truth in that day and the sizes are reported in increasing order of time. You have to find the minimum number of lies he has told on that day such that the report of the sizes is true.

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case starts with a line containing an integer n (1 ≤ n ≤ 10), where n denotes the total number of reports of his nose in a certain day. The next line contains n space separated integers: a1, a2 ... an denoting the sizes of his nose in that day. You can assume that (2 ≤ a1 ≤ a2 ≤ ... ≤ an ≤ 50).

Output
For each case, print the case number and the minimum number of lies Pinocchio has told in that day. See the samples for the output format.

Sample
Input	Output
2
5
2 3 3 3 4
4
2 3 4 5

Case 1: 2
Case 2: 3

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
solve(int *a, size_t n)
{
	size_t i;
	int p, r;

	r = 0;
	p = 2;
	for (i = 0; i < n; i++) {
		r += (a[i] - p + 4) / 5;
		p = a[i];
	}
	return r;
}

int
main()
{
	int a1[] = { 2, 3, 3, 3, 4 };
	int a2[] = { 2, 3, 4, 5 };

	assert(solve(a1, nelem(a1)) == 2);
	assert(solve(a2, nelem(a2)) == 3);

	return 0;
}
