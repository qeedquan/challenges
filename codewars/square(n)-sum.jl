#!/usr/bin/env julia

#=

Complete the square sum function so that it squares each number passed into it and then sums the results together.

For example, for [1, 2, 2] it should return 9 because 1^2 + 2^2 + 2^2 = 9.

=#

function squaresum(numbers)
	return reduce(+, map((x) -> x^2, numbers))
end

println(squaresum([1, 2, 2]))
println(squaresum([0, 3, 4, 5]))
println(squaresum([0]))

