#include <assert.h>

void
dfs(int x, int y, int k, int n, int m, int *r)
{
	if (k == 0)
		return;
	if (x - k <= n && x + k >= n && y - k <= m && y + k >= m)
		*r += 1;
	dfs(x + k, y + k, k / 2, n, m, r);
	dfs(x + k, y - k, k / 2, n, m, r);
	dfs(x - k, y + k, k / 2, n, m, r);
	dfs(x - k, y - k, k / 2, n, m, r);
}

int
solve(int k, int n, int m)
{
	int r;

	r = 0;
	dfs(1024, 1024, k, n, m, &r);
	return r;
}

int
main()
{
	assert(solve(500, 113, 941) == 5);

	return 0;
}
