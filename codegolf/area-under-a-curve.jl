#!/usr/bin/env julia

#=

Write a program that when given five integers as input, outputs the value given by the following integral:

Integrate[from=d, to=e, ax^2 + bx + c] dx

Input is five integers (in any reasonable format) in the order a b c d e where each number corresponds to the variables in the image above.
No built in integral functions allowed.
Output must be a base ten float, precise to +/- 1e-3.
Least number of bytes wins.

=#

function area(a, b, c, d, e)
	return a*e^3/3 + b*e^2/2 + c*e - a*d^3/3 - b*d^2/2 - c*d
end

println(area(1, 2, 3, 4, 7))
