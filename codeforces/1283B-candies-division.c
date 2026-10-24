/*

Santa has n candies and he wants to gift them to k kids. He wants to divide as many candies as possible between all k kids. Santa can't divide one candy into parts but he is allowed to not use some candies at all.

Suppose the kid who recieves the minimum number of candies has a candies and the kid who recieves the maximum number of candies has b candies. Then Santa will be satisfied, if the both conditions are met at the same time:

b−a≤1 (it means b=a or b=a+1); the number of kids who has a+1 candies (note that a+1 not necessarily equals b) does not exceed ⌊k/2⌋ (less than or equal to ⌊k/2⌋).
⌊k/2⌋ is k divided by 2 and rounded down to the nearest integer. For example, if k=5 then ⌊k/2⌋=⌊5/2⌋=2.

Your task is to find the maximum number of candies Santa can give to kids so that he will be satisfied.

You have to answer t
 independent test cases.

Input
The first line of the input contains one integer t (1≤t≤5⋅10^4) — the number of test cases.

The next t lines describe test cases. The i-th test case contains two integers n and k (1≤n,k≤10^9) — the number of candies and the number of kids.

Output
For each test case print the answer on it — the maximum number of candies Santa can give to kids so that he will be satisfied.

Example
input
5
5 2
19 4
12 7
6 2
100000 50010

output
5
18
10
6
75015

Note
In the first test case, Santa can give 3 and 2 candies to kids. There a=2,b=3,a+1=3.

In the second test case, Santa can give 5,5,4 and 4 candies. There a=4,b=5,a+1=5. The answer cannot be greater because then the number of kids with 5 candies will be 3.

In the third test case, Santa can distribute candies in the following way: [1,2,2,1,1,2,1]. There a=1,b=2,a+1=2. He cannot distribute two remaining candies in a way to be satisfied.

In the fourth test case, Santa can distribute candies in the following way: [3,3]. There a=3,b=3,a+1=4. Santa distributed all 6 candies.

*/

#include <assert.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

long
candies(long n, long k)
{
	if (k == 0)
		return 0;
	if (n % k == 0)
		return n;
	return min(n, ((n / k) * k) + (k / 2));
}

int
main(void)
{
	assert(candies(5, 2) == 5);
	assert(candies(19, 4) == 18);
	assert(candies(12, 7) == 10);
	assert(candies(6, 2) == 6);
	assert(candies(100000L, 50010L) == 75015L);

	return 0;
}
