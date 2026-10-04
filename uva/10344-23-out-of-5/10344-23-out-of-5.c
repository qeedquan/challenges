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
