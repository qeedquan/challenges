%{

Given a two-digit positive integer. Print the number after swapping its digits.

Input
One two-digit positive integer n (10≤n≤99).

Output
Print the number after swapping the digits of n.

Examples

Input #1
83

Answer #1
38

%}

function r = solve(n)
	a = mod(n, 10);
	b = idivide(n, int32(10), 'floor');
	r = (a * 10) + b;
end

solve(83)

