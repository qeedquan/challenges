#include <cassert>

int sod(int n)
{
	int r;
	for (r = 0; n > 0; n /= 10)
		r += n % 10;
	return r;
}

int fun(int a, int b)
{
	int ans = 0;
	int i, j, cnt;
	for (i = a; i <= b; i++)
	{
		cnt = 0;
		for (j = 1; j <= i; j++)
		{
			if (j + sod(j) == i)
				cnt++;
		}
		if (cnt == 0)
			ans++;
	}
	return ans;
}

int fun(int a)
{
	int i;
	for (i = 1; i <= a; i++)
	{
		if (i + sod(i) == a)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	assert(fun(101) == 91);
	assert(fun(1, 9) == 5);
	assert(fun(20) == -1);

	return 0;
}
