/*

For this challenge you need to implement two functions, f and g, on the integers, such that f ∘ g is a strictly decreasing function while g ∘ f is a strictly increasing function.
In other words, if you take any two integers a < b, then f(g(a)) > f(g(b)) and g(f(a)) < g(f(b)). There are no restrictions on f and g individually, except that they must each map one integer to another integer.

Please include a short description of f and g and an argument for why they have the required property.

Credit: This challenge was inspired by a problem in the 2011 Romanian Master of Mathematics competition (which asks the same thing but on the real numbers, instead of integers). If you really want spoilers, you now know what to search for.

Rules
The word "function" in this challenge should be taken in the mathematical sense of mapping one integer to another: you may either write two programs or two functions and use any of the standard methods of receiving input and providing output, as usual.
You may use string representations of integers instead of actual integer variables, but the types of input and output should be identical, so that the functions can be composed without manually converting types in between.
Remember that conceptually, f and g still need to be functions on ℤ, so you can't cheat by using two different string representations of the same number or anything like that.

Remember that functions may be unnamed, as long as their name isn't needed by itself or another function you define.
If you do name one or both of the functions, you may assume that they exist in the same program, so that they may refer to each other in their implementation (e.g def f(x): return -g(x) in Python).

The usual integer overflow rules apply: your solution must be able to work for arbitrarily large integers in a hypothetical (or perhaps real) version of your language in which all integers are unbounded by default,
but if your program fails in practice due to the implementation not supporting integers that large, that doesn't invalidate the solution.

You may use any programming language, but note that these loopholes are forbidden by default.

This is code-golf, so your score is the sum of the number of bytes of both functions and the shortest valid answer wins.

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

vlong
mod(vlong x, vlong m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

/*

@user1502040

f maps negative numbers to odd numbers and positive numbers to even numbers, and even numbers to positive numbers and odd numbers to negative numbers, with the output magnitude increasing strictly with the input magnitude.

g does the same, except it maps negative numbers to even numbers and positive numbers to odd numbers.

f ∘ g maps negative → even → positive and positive → odd → negative.
g ∘ f maps negative → odd → negative and positive → even → positive.

*/

vlong
f(vlong x)
{
	return (1 - mod(x, 2) * 2) * (2 * x * x + (x < 0));
}

vlong
g(vlong x)
{
	return (1 - mod(x, 2) * 2) * (2 * x * x + (x > 0));
}

int
main(void)
{
	vlong i, N;

	N = 30000LL;
	for (i = -N; i <= N; i++) {
		assert(f(g(i)) < f(g(i - 1)));
		assert(g(f(i)) > g(f(i - 1)));
	}

	return 0;
}
