%{

Given a two-digit positive integer. Find the sum and the product of its digits.

Input
One two-digit positive integer n (10≤n≤99).

Output
Print in one line the sum and the product of digits of number n.

Examples
Input #1
46

Answer #1
10 24

%}

function r = solve(n)
	a = mod(floor(n/10), 10);
	b = mod(n, 10);
	r = [a + b, a * b];
end

solve(46)
