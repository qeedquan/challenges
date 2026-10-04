#include <cstdio>

void exgcd(int x, int y, int &g, int &a, int &b)
{
	if (y == 0)
	{
		g = x;
		a = 1;
		b = 0;
		return;
	}

	exgcd(y, x % y, g, b, a);
	b -= (x / y) * a;
}

void print_step(int n, int x)
{
	if (x == 0)
		printf("%d liter(s) not needed\n", n);
	else if (x < 0)
		printf("%d liter(s) withdrawn %d times\n", n, -x);
	else
		printf("%d liter(s) poured %d times\n", n, x);
}

void solve(int n, int m)
{
	int g, a, b;
	exgcd(n, m, g, a, b);

	printf("minimum volume: %d liter(s)\n", g);
	print_step(n, a);
	print_step(m, b);
	printf("\n");
}

int main()
{
	solve(3240, 1376);
	solve(2607, 79);

	return 0;
}
