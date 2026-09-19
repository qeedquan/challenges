#!/usr/bin/env julia

#=

Please excuse the punny title.

This is a question is inspired by A Curious Property of 82000. In it, the author points out that the number 82000 is binary in base 2, 3, 4, and 5. The post then poses the question "is there a number that is binary in bases 2, 3, 4, 5, and 6"? (For those curious, I've checked values up to 10^1,000,000 and so far the answer is no.)

This got me thinking: given a number, what bases is it binary in?

Our curious number, 82000, is actually binary in six bases:

Base 2 = 10100000001010000
Base 3 = 11011111001
Base 4 = 110001100
Base 5 = 10111000
Base 81999 = 11
Base 82000 = 10
Not all numbers will have binary bases that are sequential. Consider the number 83521. It's binary in bases 2, 17, 289, 83520, and 83521.

Your challenge is to determine and display which bases a number is binary in.

Rules
A number is considered "binary" in a given base if its representation in that base consists of only zeroes and ones. 110110 is a binary value, while 12345 is not, A380F is definitely not.
Your number will be provided on standard input. It will be an integer value between 2 and 2^32-1 inclusive and will be provided in base-10 format.
In ascending order, display each base greater than one that the number is binary in. Each base should be on its own line. If you include the binary value in that base (see the bonus scoring below), separate the base and the binary value with a space. Only output to standard out will be judged, standard error and other sources will be ignored.
Scoring
Your score is your program's size in bytes. The lower the score, the better.

Bonus:
If your program also outputs the binary values in the found bases, multiply your score by 0.75
Your displayed binary value should have no extra punctuation, no extraneous zeroes, no decimal point, just zeroes and ones.

Examples
Input:

82000
Output (receives bonus):

2 10100000001010000
3 11011111001
4 110001100
5 10111000
81999 11
82000 10
Input:

1234321
Output (no bonus):

2
1111
1234320
1234321

=#

function bases(n)
	println("n=", n)
	for j = 2:n
		d = digits(n, base=j)
		if all(i -> i ∈ 0:1, d)
			println(j, " ", reverse(d))
		end
	end
	println()
end

bases(Integer(82000))
bases(Integer(1234321))
