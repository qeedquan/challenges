/*

Write a fixed point combinator in as few characters as possible, in the language of your choice.

free form (i.e., whatever's shortest): whole program, actual function, code snippet
you may not use your standard library's if it has one
you may however extract it from other high-level functions it you'd rather do that than construct it from the bases
Please include a recursive factorial or Fibonacci that uses it as a demo.

In this question, self-reference is acceptable, the aim is solely to remove it from the recursive function it will apply to.

*/

#include <cstdio>
#include <functional>

using namespace std;

// https://rosettacode.org/wiki/Y_combinator
int main()
{
	auto Y = ([](auto f) {
		return ([](auto x) {
			return x(x);
		}([=](auto y) -> function<int(int)> {
			return f([=](auto a) {
				return (y(y))(a);
			});
		}));
	});

	auto ufib = [](auto f) { return [=](auto n) { return n < 2 ? 1 : f(n - 1) + f(n - 2); }; };
	auto ufac = [](auto f) { return [=](auto n) { return n <= 1 ? n : n * f(n - 1); }; };
	auto usum = [](auto f) { return [=](auto n) { return n <= 0 ? 0 : n + f(n - 1); }; };

	auto fib = Y(ufib);
	auto fac = Y(ufac);
	auto sum = Y(usum);

	for (auto i = 0; i <= 10; i++)
		printf("%d %d %d %d\n", i, fib(i), fac(i), sum(i));

	return 0;
}
