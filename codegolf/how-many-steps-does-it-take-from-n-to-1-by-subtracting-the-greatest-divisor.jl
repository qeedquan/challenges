#=

Inspired by this question over at Mathematics.

The Problem

Let n be a natural number ≥ 2. Take the biggest divisor of n – which is different from n itself – and subtract it from n. Repeat until you get 1.

The Question

How many steps does it take to reach 1 for a given number n ≥ 2.

Detailed Example

Let n = 30.

The greatest divisor of:

1.   30 is 15  -->  30 - 15 = 15
2.   15 is  5  -->  15 -  5 = 10
3.   10 is  5  -->  10 -  5 =  5
4.    5 is  1  -->   5 -  1 =  4
5.    4 is  2  -->   4 -  2 =  2
6.    2 is  1  -->   2 -  1 =  1
It takes 6 steps to reach 1.

Input

Input is an integer n, where n ≥ 2.
Your program should support input up to the language's maximum integer value.
Output

Simply output the number of steps, like 6.
Leading/trailing whitespaces or newlines are fine.

Examples

f(5)        --> 3
f(30)       --> 6
f(31)       --> 7
f(32)       --> 5
f(100)      --> 8
f(200)      --> 9
f(2016^155) --> 2015
Requirements

You can get input from STDIN, command line arguments, as function parameters or from the closest equivalent.
You can write a program or a function. If it is an anonymous function, please include an example of how to invoke it.
This is code-golf so shortest answer in bytes wins.
Standard loopholes are disallowed.
This series can be found on OEIS as well: A064097

A quasi-logarithm defined inductively by a(1) = 0 and a(p) = 1 + a(p-1) if p is prime and a(n*m) = a(n) + a(m) if m,n > 1.

=#

using Primes

# https://oeis.org/A064097
function quasilog(n)
	if n < 2
		return 0
	end
	return quasilog(n - n ÷ first(factor(n))[1]) + 1
end

@assert(quasilog(5) == 3)
@assert(quasilog(30) == 6)
@assert(quasilog(31) == 7)
@assert(quasilog(32) == 5)
@assert(quasilog(100) == 8)
@assert(quasilog(200) == 9)
@assert(quasilog(big(2016)^155) == 2015)
