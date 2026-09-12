%{

Count the number of prime numbers in the given interval [l,r] (0≤l≤r≤2147483647, r−l≤10^6).

Input
Two integers l and r.

Output
Print the number of primes in the interval [l,r].

Examples

Input #1
2 11

Answer #1
5

%}

function p = solve(l, r)
	p = length(primes(r)) - length(primes(l - 1));
end

solve(2, 11)
