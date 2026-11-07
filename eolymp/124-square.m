%{

Find the perimeter and area of a square.

Input
Each line contains a single integer n (1≤n≤1000) — the side length of a square.

Output
For each test case, output the perimeter and area of the square on one line.

Examples
Input #1
3
5
10

Answer #1
12 9
20 25
40 100

%}

function r = solve(n)
	r = [n*4, n*n];
end

solve(3)
solve(5)
solve(10)
