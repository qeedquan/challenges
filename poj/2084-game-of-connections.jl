#!/usr/bin/env julia

#=

Description

This is a small but ancient game. You are supposed to write down the numbers 1, 2, 3, . . . , 2n - 1, 2n consecutively in clockwise order on the ground to form a circle, and then, to draw some straight line segments to connect them into number pairs. Every number must be connected to exactly one another.
And, no two segments are allowed to intersect.
It's still a simple game, isn't it? But after you've written down the 2n numbers, can you tell me in how many different ways can you connect the numbers into pairs? Life is harder, right?

Input

Each line of the input file will be a single positive number n, except the last line, which is a number -1.
You may assume that 1 <= n <= 100.

Output

For each n, print in a single line the number of ways to connect the 2n numbers into pairs.

Sample Input

2
3
-1

Sample Output

2
5

Source

Shanghai 2004 Preliminary

=#

# https://oeis.org/A000108
function catalan(n)
	return binomial(2*n, n) ÷ (n + 1)
end

@assert(catalan(2) == 2)
@assert(catalan(3) == 5)
