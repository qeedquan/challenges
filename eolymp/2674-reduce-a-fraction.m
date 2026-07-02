%{

Reduce the given fraction to lowest terms.

Input
The numerator and denominator of the fraction are given (integers, with absolute values no more than 10^9).

Output
Print the numerator and denominator of the simplified fraction, separated by a space.

Examples
Input #1
2 4

Answer #1
1 2

Input #2
-12 15

Answer #2
-4 5

%}

function r = solve(n, d)
	m = gcd(n, d);
	r = [n/m, d/m];
end

solve(2, 4)
solve(-12, 15)
