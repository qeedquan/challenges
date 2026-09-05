%{

Semen has n candies and Yura m candies.
At the same time they both eat one of their own candies as long as each of them has at least one candy.
Determine how many candies will remain after they stop eating the sweets.

Input
Two integers n and m (1≤n,m≤10^9) - the number of candies at Semen and Yura respectively.

Output
Print the number of candies that will remain.

Examples

Input #1
6 3

Answer #1
3

Input #2
7 7

Answer #2
0

%}

function r = candies(n, m)
	r = max(n, m) - min(n, m);
end

candies(6, 3)
candies(7, 7)
