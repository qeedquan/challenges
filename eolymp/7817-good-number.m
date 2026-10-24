%{

A number is considered "good" if it consists only of odd digits.
For example, the number 157953 is good, while the number 2452117 is not.
Determine how many n-digit good numbers exist.

Input
One positive integer n (1≤n≤20).

Output
Print the number of n-digit good numbers.

Examples
Input #1
4

Answer #1
625

%}

% https://oeis.org/A000351
function r = solve(n)
	r = 5^n;
end

solve(4)
