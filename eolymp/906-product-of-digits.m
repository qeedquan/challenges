%{

Given a three-digit positive integer n. Find the product of its digits.

Input
One three-digit positive integer n.

Output
Print the product of the digits of n.

Examples
Input #1
235

Answer #1
30

%}

function r = solve(n)
	a = mod(floor(n / 100), 10);
	b = mod(floor(n / 10), 10);
	c = mod(n, 10);
	r = a * b * c;
end

solve(235)
