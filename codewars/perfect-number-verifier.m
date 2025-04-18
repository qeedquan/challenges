%{

A perfect number is a number in which the sum of its divisors (excluding itself) are equal to itself.

Write a function that can verify if the given integer n is a perfect number, and return True if it is, or return False if not.

Examples
n = 28 has the following divisors: 1, 2, 4, 7, 14, 28

1 + 2 + 4 + 7 + 14 = 28 therefore 28 is a perfect number, so you should return True

Another example:

n = 25 has the following divisors: 1, 5, 25

1 + 5 = 6 therefore 25 is not a perfect number, so you should return False

%}

pkg load symbolic

% https://oeis.org/A000396
function r = perfect(n)
	r = sum(divisors(sym(n))) - n == n;
end

for i = 1:50
	if (perfect(i))
		i
	end
end

