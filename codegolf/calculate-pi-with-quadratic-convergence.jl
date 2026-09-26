#=

Write a function or complete program that takes a positive number n and performs n steps of an iterative algorithm for calculating π that has quadratic convergence (i.e. it approximately doubles the number of accurate digits at every iteration) then returns or prints out 2n correct digits (including the beginning 3). One such algorithm is the Gauss–Legendre algorithm, but you are free to use a different algorithm if you prefer.

Examples:

input 1 → output 3.1
input 2 → output 3.141
input 5 → output 3.1415926535897932384626433832795

Requirements:

Each iteration of the algorithm must perform a constant number of basic operations such as addition, subtraction, multiplication, division, power and root (with integer exponent/degree) - each such operation on "big" integer/decimal numbers is counted as one even if it involves one or more loops internally. To be clear, trigonometric functions and powers involving complex numbers are not basic operations.
The algorithm is expected to have an initialization step which must also have a constant number of operations.
If the algorithm needs 1 or 2 more iterations to get to 2n correct digits, you can perform up to n+2 iterations instead of just n.
If it wasn't clear enough, after the correct 2n digits, your program must not print anything else (such as more correct digits, wrong digits or the complete works of Shakespeare).
Your program must support values of n from 1 to at least 20.
Your program should not take more than an hour for n=20 on a modern computer (not a hard rule, but try to keep it reasonable).
The program must not obtain more than 20 accurate digits after the initialization and first iteration of the algorithm.
The program must be runnable in Linux using freely available software.
The source code must use only ASCII characters.

Scoring:

Straightforward code golf, shortest code wins.

=#

# https://en.wikipedia.org/wiki/Gauss%E2%80%93Legendre_algorithm
function glpi(n)
	a = BigFloat(1)
	b = BigFloat(1/sqrt(2))
	t = BigFloat(1/4)
	p = BigFloat(1)
	for i in 0:2^n
		A = (a + b) / 2
		B = sqrt(a*b)
		T = t - p*(a-A)^2
		P = 2*p
		(a, b, t, p) = (A, B, T, P)
	end
	
	return (a + b)^2 / (4*t)
end

println(glpi(1))
println(glpi(2))
println(glpi(5))
