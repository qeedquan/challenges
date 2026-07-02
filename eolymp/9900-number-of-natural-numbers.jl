#!/usr/bin/env julia

#=

The program receives a natural number n as input. Your task is to output the count of natural numbers that are less than or equal to n.

Input
A natural number n, where n is not greater than 10^18.

Output
Output the count of natural numbers that do not exceed n.

Examples
Input #1
123

Answer #1
123

=#

function solve(n)
	if n < 0
		return 0
	end
	return n
end

println(solve(4))
println(solve(123))

