--[[

Given three distinct integers a, b, and c, find the medium number between all of them.

The medium number is the number that is neither the minimum nor the maximum of the given three numbers.

For example, the median of 5,2,6 is 5, since the minimum is 2 and the maximum is 6.

Input
The first line contains a single integer t (1≤t≤6840) — the number of test cases.

The description of each test case consists of three distinct integers a, b, c (1≤a,b,c≤20).

Output

For each test case, output a single integer — the medium number of the three numbers.

Example

input
9
5 2 6
14 3 4
20 2 1
1 2 3
11 19 12
10 8 20
6 20 3
4 1 3
19 8 4

output
5
4
2
2
12
10
6
3
8

--]]

function mid(a, b, c)
	x = {a, b, c}
	table.sort(x)
	return x[2]
end

assert(mid(5, 2, 6) == 5)
assert(mid(14, 3, 4) == 4)
assert(mid(20, 2, 1) == 2)
assert(mid(1, 2, 3) == 2)
assert(mid(11, 19, 12) == 12)
assert(mid(10, 8, 20) == 10)
assert(mid(6, 20, 3) == 6)
assert(mid(4, 1, 3) == 3)
assert(mid(19, 8, 4) == 8)
