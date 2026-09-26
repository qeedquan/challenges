#!/usr/bin/env julia

#=

In order to celebrate Twice's 5th anniversary, Tzuyu and Sana decided to play a game.

Tzuyu gave Sana two integers a and b and a really important quest.

In order to complete the quest, Sana has to output the smallest possible value of (a⊕x) + (b⊕x) for any given x, where ⊕ denotes the bitwise XOR operation.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤10^4). Description of the test cases follows.

The only line of each test case contains two integers a and b (1≤a,b≤10^9).

Output
For each testcase, output the smallest possible value of the given expression.

Example

input
6
6 12
4 9
59 832
28 14
4925 2912
1 1

output
10
13
891
18
6237
0

Note
For the first test case Sana can choose x=4 and the value will be (6⊕4) + (12⊕4) = 2+8 = 10. It can be shown that this is the smallest possible value.

=#

function xorwice(a, b)
	return a ⊻ b
end

@assert(xorwice(6, 12) == 10)
@assert(xorwice(4, 9) == 13)
@assert(xorwice(59, 832) == 891)
@assert(xorwice(28, 14) == 18)
@assert(xorwice(4925, 2912) == 6237)
@assert(xorwice(1, 1) == 0)
