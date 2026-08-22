%{

Given n integers. Find out how many of them are different.

Input
The first line contains the number of integers n (1≤n≤10^6).
The second line contains n integers, each of which does not exceed 2⋅10^9 in absolute value.

Output
Print the number of different integers among the given ones.

Examples

Input #1
1
3

Answer #1
1

Input #2
5
9 15 22 15 22

Answer #2
3

%}

function r = solve(x)
	r = length(unique(x));
end

solve([3])
solve([9, 15, 22, 15, 22])
