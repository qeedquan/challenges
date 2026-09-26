#!/usr/bin/env julia

#=

Everybody knows pi the mathematical constant, the ratio of a circle's circumference to its diameter.

3.14159265358979323846264338327950288419716939937510...
You probably also know e the mathematical constant, the base of a natural logarithm.

2.71828182845904523536028747135266249775724709369996...
But... do you know pie? It is one of the most important constants (to me). It is the digits of pi and e interleaved.

32.1741185298216852385485997094352233854366206248373...
As a decimal expansion:

3, 2, 1, 7, 4, 1, 1, 8, 5, 2, 9, 8, 2, 1, 6, 8, 5, 2...
This is OEIS sequence A001355.

KEYWORD: nonn,base,dumb,easy

It is a very dumb sequence.

Challenge
Write a program/function that takes a non-negative integer n and outputs the nth digit of pie.

Specifications
Standard I/O rules apply.
Standard loopholes are forbidden.
Your solution must work for at least 50 digits of each constant which means it should work for at least a 100 terms of the sequence (please, try not to hardcode :P).
The output for 2 or 3 is not a decimal point.
Your solution can either be 0-indexed or 1-indexed but please specify which.
This challenge is not about finding the shortest approach in all languages, rather, it is about finding the shortest approach in each language.
Your code will be scored in bytes, usually in the encoding UTF-8, unless specified otherwise.
Built-in functions that compute this sequence are allowed but including a solution that doesn't rely on a built-in is encouraged.
Explanations, even for "practical" languages, are encouraged.
Test cases
These are 0-indexed.

Input   Output

1       2
2       1
11      8
14      6
21      4
24      9
31      5
In a few better formats:

1 2 11 14 21 24 31
1, 2, 11, 14, 21, 24, 31

2 3 12 15 22 25 32
2, 3, 12, 15, 22, 25, 32

=#

# https://oeis.org/A001355
function πℯ(n)
	if n < 1
		return -1
	end

	setprecision(BigFloat, n*10)
	if n%2 == 1
		s = string(BigFloat(π))
	else
		s = string(BigFloat(ℯ))
	end
	
	s = replace(s, "." => "")
	return Int(s[n÷2 + n%2]) - Int('0')
end

tab = [3, 2, 1, 7, 4, 1, 1, 8, 5, 2, 9, 8, 2, 1, 6, 8, 5, 2, 3, 8, 5, 4, 8, 5, 9, 9, 7, 0, 9, 4, 3, 5, 2, 2, 3, 3, 8, 5, 4, 3, 6, 6, 2, 0, 6, 2, 4, 8, 3, 7, 3, 4, 8, 7, 3, 1, 2, 3, 7, 5, 9, 2, 5, 6, 0, 6, 2, 2, 8, 4, 8, 9, 4, 7, 1, 7, 9, 5, 7, 7, 1, 2, 6, 4, 9, 7, 3, 0, 9, 9, 9, 3, 3, 6, 7, 9, 5, 9, 1, 9]

for i in 1:length(tab)
	@assert(πℯ(i) == tab[i])
end
