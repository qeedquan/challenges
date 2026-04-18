/*

Your task is to write a program that can decide whether you can find an arithmetic expression consisting
of five given numbers ai (1 ≤ i ≤ 5) that will yield the value 23.
For this problem we will only consider arithmetic expressions of the following from:
(((aπ(1) o1 aπ(2)) o2 aπ(3)) o3 aπ(4)) o4 aπ(5)
where π : {1, 2, 3, 4, 5} → {1, 2, 3, 4, 5} is a bijective function and oi ∈ {+, −, ∗}(1 ≤ i ≤ 4)

Input
The Input consists of 5-Tupels of positive Integers, each between 1 and 50.
Input is terminated by a line containing five zero’s. This line should not be processed. Input file
will have no more than 25 lines.

Output
For each 5-Tupel print ‘Possible’ (without quotes) if their exists an arithmetic expression (as described
above) that yields 23. Otherwise print ‘Impossible’.

Sample Input
1 1 1 1 1
1 2 3 4 5
2 3 5 7 11
0 0 0 0 0

Sample Output
Impossible
Possible
Possible

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

bool
dfs(int nums[5], int cur, bool use[5], bool first)
{
	bool eos;
	int i;

	eos = true;
	for (i = 0; i < 5; i++) {
		if (use[i])
			continue;

		eos = false;
		use[i] = true;

		if (dfs(nums, cur + nums[i], use, false))
			return true;
		if (!first && dfs(nums, cur - nums[i], use, false))
			return true;
		if (!first && dfs(nums, cur * nums[i], use, false))
			return true;

		use[i] = false;
	}

	if (eos)
		return cur == 23;
	return false;
}

bool
solve(int a, int b, int c, int d, int e)
{
	int nums[5] = { a, b, c, d, e };
	bool use[5] = {};
	return dfs(nums, 0, use, true);
}

int
main()
{
	assert(solve(1, 1, 1, 1, 1) == false);
	assert(solve(1, 2, 3, 4, 5) == true);
	assert(solve(2, 3, 5, 7, 11) == true);

	return 0;
}
