#!/usr/bin/env julia

#=

Given a, b, c the length of the three sides of a triangle, say if the triangle is right-angled (i.e. has one angle equal to 90 degrees) or not.

Input
Three positive integer values in any order

Output
Either a specific true output (true, 1, yes, ...) or a specific false output (false, 0, no, ...)

Example
5, 3, 4        --> yes
3, 5, 4        --> yes
12, 37, 35     --> yes
21, 38, 50     --> no
210, 308, 250  --> no

Rules
The input and output can be given in any convenient format.
In your submission, please state the true and the false values.
No need to handle negative values or invalid edge triple
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
If possible, please include a link to an online testing environment so other people can try out your code!
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

=#

#=

@DELETE_ME

The problem is equivalent to being given three numbers a, b, c, and asking if there is a permutation such that a² + b² = c².
This is equivalent to whether (a² + b² + c²) ÷ 2 is one of a², b² or c², so the program just checks that.

=#

function right(a, b, c)
	s = (a^2 + b^2 + c^2) ÷ 2
	return s == a^2 || s == b^2 || s == c^2
end

@assert(right(5, 3, 4) == true)
@assert(right(3, 5, 4) == true)
@assert(right(12, 37, 35) == true)
@assert(right(21, 38, 50) == false)
@assert(right(210, 308, 250) == false)

