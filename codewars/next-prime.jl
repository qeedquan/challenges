#!/usr/bin/env julia

#=

Get the next prime number!

You will get a number n (>= 0) and your task is to find the next prime number.

Make sure to optimize your code: there will numbers tested up to about 10^12.

Examples
5   =>  7
12  =>  13

=#

using Primes

function next(n)
	return nextprime(n + 1)
end

println(next(5))
println(next(7))
println(next(12))

