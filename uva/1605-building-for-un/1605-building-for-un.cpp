#include <cstdio>

void solve(int n)
{
	printf("2 %d %d\n", n, n);
	for (auto j = 0; j < n; j++)
	{
		for (auto i = 0; i < n; i++)
		{
			auto c = (j < 26) ? (j + 'A') : (j - 26 + 'a');
			printf("%c", c);
		}
		printf("\n");
	}
	printf("\n");

	for (auto j = 0; j < n; j++)
	{
		for (auto i = 0; i < n; i++)
		{
			auto c = (i < 26) ? (i + 'A') : (i - 26 + 'a');
			printf("%c", c);
		}
		printf("\n");
	}
}

int main()
{
	solve(4);
	return 0;
}
