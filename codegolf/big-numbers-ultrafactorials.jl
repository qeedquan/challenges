#!/usr/bin/env julia

#=

Ultrafactorials
The ultrafactorials are a sequence of numbers which can be generated using the following function:

a(n)=n!^n!

The resulting values rise extremely quickly. Side note: This is entry A046882 in the OEIS. Also related are the hyperfactorials, a still quite huge, but a bit smaller sequence: A002109

Your task
Your task is to implement these numbers into your language. Your program will calculate the sum of all ultrafactorials from 0 up to inclusive n.

Input
Your program may only take one input: a number, which resembles the last a(n)
 ultrafactorial to be added to the sum. The Input is assured to be positive or 0.

Output
Your output is all up to you, as long as there's the visible sum of the numbers somewhere.

Rules
You can assume all integers, therefore integer input, and using integer counting loops to produce some results.
Test cases
Input: -1
Output: Any kind of error (because -1! is undefined), or no handling at all

Input: 0
Output: 1

Input: 1
Output: 2

Input: 2
Output: 6

Input: 3
Output: 46662
Challenge
This is code-golf, so the answer with the least length in bytes wins!

=#

# https://oeis.org/A046882
function ultrafactorial(n)
	if n < 0
		return -1
	end

	x = factorial(n)
	return x^x
end

function gigafactorial(n)
	r = 0
	for i in 0:n
		r += ultrafactorial(i)
	end
	return r
end

@assert(gigafactorial(0) == 1)
@assert(gigafactorial(1) == 2)
@assert(gigafactorial(2) == 6)
@assert(gigafactorial(3) == 46662)
