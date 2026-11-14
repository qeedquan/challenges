/*

There are n cages in the zoo, arranged in a row.
Among the inhabitants are two monkeys, Khem and Sem. Khem and Sem used to be close friends and always sat in neighboring cages,
but now they have quarreled and do not want to see each other.
The zookeeper wants to resettle them according to their wishes but faces a problem.
Khem and Sem are intelligent monkeys (each has finished eight grades!),
and they want to know how many ways there are to place them so that their cages are not adjacent, with each in a different cage.
Assume all n cages are available, and the other animals are willing to move anywhere.

The zookeeper tried to count the possibilities but lost track somewhere near the hippos. Clearly, without your help, he will not manage!

Input
The first line contains the number of cages n (2≤n≤100).

Output
Print the number of ways to assign Khem and Sem to different, non-adjacent cages.

Examples

Input #1
3

Answer #1
2

Input #2
4

Answer #2
6

*/

#include <assert.h>

int
solve(int n)
{
	if (n < 1)
		return 0;
	return (n - 2) * (n - 1);
}

int
main()
{
	assert(solve(3) == 2);
	assert(solve(4) == 6);

	return 0;
}
