%{

Challenge
Given a non-negative integer, find the sum of its digits.
Rules
Your program must take a non-negative integer as input.
Your program should output the sum of the digits of the input integer.
Your program should be able to handle inputs up to 10^100.

Examples
If the input is 123, the output should be 6 (1 + 2 + 3).
If the input is 888, the output should be 24 (8 + 8 + 8).
If the input is 1024, the output should be 7 (1 + 0 + 2 + 4).
If the input is 3141592653589793238462643383279502884197169399375105820974944592, the output should be 315.

Format
Your program should take input from standard input (stdin) and output the result to standard output (stdout).
Your program should be runnable in a Unix-like environment.

Test cases

Input:

123
Output:

6

Input:

888
Output:

24

Input:

1024

Output:

7

Input:

3141592653589793238462643383279502884197169399375105820974944592
Output:

315

Scoring
This is a code-golf challenge, so the shortest code (in bytes) wins.

%}

% https://oeis.org/A007953
function r = digsum(n)
	r = 0;
	while n > 0
		r += mod(n, 10);
		n = fix(n / 10);
	end
end

function main
	tab = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 8, 9, 10, 11, 12, 13, 14, 15];

	for i=1:length(tab)
		assert(digsum(i - 1) == tab(i));
	end
end

main
