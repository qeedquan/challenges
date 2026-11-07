#!/usr/bin/env julia

#=

Pentagonal numbers are the number of dots that can be shown in a pentagonal pattern of dots. Let's represent the nth pentagonal number by P(n). The following figure depicts pentagonal patterns for n ∈ {1, 2, 3, 4, 5}.

https://hr-challenge-images.s3.amazonaws.com/2520/pentagonal-numbers.png

Your task is to find the value of P(n) for a given n.

Input
The first line will contain an integer T, which represents the number of test cases. Then T lines, each representing a single test case, follow. Each test case contains an integer n.

Output
For each test case, print the nth pentagonal number, P(n), in separate line.

Constraints
1 <= T <= 10^5
1 <= n <= 10^5

Sample Input
5
1
2
3
4
5

Sample Output
1
5
12
22
35

Explanation
Above image contains the pentagonal pattern for all n's.

=#

# https://oeis.org/A000326
function pentagonal(n)
	return (3*n^2 - n) ÷ 2
end

@assert(pentagonal(1) == 1)
@assert(pentagonal(2) == 5)
@assert(pentagonal(3) == 12)
@assert(pentagonal(4) == 22)
@assert(pentagonal(5) == 35)

