#!/usr/bin/env lua

--[[

On 4chan, a popular game is get. Every post on the site gets a sequential post ID. Since you can't influence or determine them, people try to guess (at least a part of) their own post number, usually the first few digits.
Another version of the game is called dubs, and it's goal is to get repeating digits at the end of the number (i.e 1234555).

Your task, if you wish to accept it, is to write a program that takes a post id as input (standard integer, you can assume below 2^32), and returns how many repeating digits are on the end.

Rules
Standard loopholes are disallowed.
The program can be a function, full program, REPL command, whatever works, really, as long as no external uncounted code/arguments are needed to run it.
Input can come from STDIN, function arguments, command line argument, file, whatever suits you.
Test Cases
Input: 14892093
Output: 1

Input: 12344444
Output: 5

Input: 112311
Output: 2

Input: 888888
Output: 6

Input: 135866667 //Post number I got on /pol/ few days ago, rip
Output: 1

--]]

function dubs(n)
	local c = 0
	local d = n % 10
	while n > 0 do
		if d ~= n%10 then
			break
		end
		n = n // 10
		c = c + 1
	end
	return c
end

assert(dubs(14892093) == 1)
assert(dubs(12344444) == 5)
assert(dubs(112311) == 2)
assert(dubs(888888) == 6)
assert(dubs(135866667) == 1)
