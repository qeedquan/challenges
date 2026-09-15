/*

Given

- a semi-inclusive interval I = [l, u) (l is in interval I but u is not)
  l and u being floating numbers (0 <= l < u),

- an integer n (n > 0)
- a function f: x (float number) -> f(x) (float number)

we want to return as a list the n values:

f(l), f(l + 1 * d), ..., f(u -d) where d = (u - l) / n

or as a string (Bash, Nim):

"f(l), f(l + 1 * d), ..., f(u -d)" where d = (u - l) / n

Call this function interp:

interp(f, l, u, n) -> [f(l), f(l + 1 * d), ..., f(u - d)]

The n resulting values f(l), f(l + 1 * d), ..., f(u - d) will be **floored** to two decimals (
except Shell and Nim: see below).

For that you can use: floor(y * 100.0) / 100.0.

Examples:
interp(x -> x, 0.0, 0.9, 3) -> [0.0; 0.3; 0.6]
interp(x -> x, 0.0, 0.9, 4) -> [0.0; 0.22; 0.45; 0.67]
interp(x -> x, 0.0, 1.0, 4) -> [0.0; 0.25; 0.5; 0.75]
interp(x -> sin x, 0.0, 0.9, 3)  -> [0.0; 0.29; 0.56]

*/

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef double (*fn)(double);

double identity(double x)
{
	return x;
}

vector<double> interp(fn f, double l, double u, int n)
{
	vector<double> r;
	for (auto i = 0; i < n; i++)
	{
		auto x = floor(100 * f((i * (u - l) / n) + l)) / 100;
		r.push_back(x);
	}
	return r;
}

void test(fn f, double l, double u, int n)
{
	auto r = interp(f, l, u, n);
	for (auto v : r)
		cout << v << " ";
	cout << endl;
}

int main()
{
	test(::identity, 0, 9, 4);
	test(cos, 0, 21, 7);
	test(::identity, 0, 15, 9);
	test(sin, 0, 21, 10);
	test(sin, 0, 18, 12);
	test(cos, 0, 15, 12);

	return 0;
}
