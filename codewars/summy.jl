#!/usr/bin/env julia

#=

Write a function that takes a string which has integers inside it separated by spaces, and your task is to convert each integer in the string into an integer and return their sum.

Example
summy("1 2 3")  ==> 6

Good luck!

=#

function summy(numbers...)
	sum = 0
	for i in 1:length(numbers)
		sum += numbers[i]
	end
	return sum
end

@assert(summy(1, 2, 3) == 6)
@assert(summy(4, 5, 6) == 15)

