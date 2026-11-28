#!/usr/bin/env sage

"""

The challenge
The plastic number is a number related to the golden ratio, with many interesting mathematical properties. As such, there are many approaches that can be used to calculate the number.

In order to precisely specify the number for the purposes of this challenge, we'll use the following definition (although there are plenty of equivalent definitions, and you can use any definition you wish as long as it comes to the same number):

The plastic number is a real number ρ such that ρ³=ρ+1.

Your challenge is to write a program or function which takes an integer x as input (with x > 1), and produces an approximation to ρ as output, such that the larger the value of x gets, the closer the output gets to ρ (with at most finitely many exceptions; staying at the same value counts as "closer" for this purpose), and for any positive number δ, there's some input x to your program that produces an output that's within δ of ρ.

Clarifications
If you're outputting via a method that inherently outputs strings (e.g. the standard output stream), you can format output either in decimal (e.g. 1.3247179572), or as a ratio of two integers with a / character between them.
If you're outputting as a value within your programming language (e.g. returning from a function), it must be of a fixed-point, floating-point, or rational type. (In particular, you can't use data types that store numbers symbolically, unless they're used only to hold the ratio of two integers. So if you're using Mathematica or a similar language, you'll need to include the extra code to actually generate the digits of the output.)
Your answer must work in a hypothetical variant of your language in which integers can be arbitrarily large, and memory (including stack) is unlimited. You may not assume that floating-point arithmetic in your language is arbitrarily accurate, but must instead use its actual accuracy (meaning that outputting a floating-point number is only going to be possible in languages where the accuracy of floating-point numbers can be controlled at runtime).
x can have any meaning you want (so long as increasing it gives more accurate outputs). I imagine that most submissions will have it control the number of digits of output to produce, or the number of iterations of the algorithm used by your program to converge on the plastic number, but other meanings are acceptable.
Testcase
Here are the first few digits of the plastic number:

1.32471795724474602596090885
More digits are available on OEIS.

Victory condition
As usual for code-golf, shorter is better, measured in bytes. However, feel free to post answers even if they don't win, so long as they add something (e.g. a different language, or a different algorithm) to the existing answers.

"""

# https://oeis.org/A060006
def plastic(n):
	a = ((3 + sqrt(23/3))/6)^(1/3)
	b = ((3 - sqrt(23/3))/6)^(1/3)
	return numerical_approx(a + b, digits=n)

def main():
	tab = [1, 3, 2, 4, 7, 1, 7, 9, 5, 7, 2, 4, 4, 7, 4, 6, 0, 2, 5, 9, 6, 0, 9, 0, 8, 8, 5, 4, 4, 7, 8, 0, 9, 7, 3, 4, 0, 7, 3, 4, 4, 0, 4, 0, 5, 6, 9, 0, 1, 7, 3, 3, 3, 6, 4, 5, 3, 4, 0, 1, 5, 0, 5, 0, 3, 0, 2, 8, 2, 7, 8, 5, 1, 2, 4, 5, 5, 4, 7, 5, 9, 4, 0, 5, 4, 6, 9, 9, 3, 4, 7, 9, 8, 1, 7, 8, 7, 2, 8, 0, 3, 2, 9, 9, 1]

	x = plastic(len(tab))
	s = str(x)
	s = s.replace('.', '')
	for i in range(len(tab)):
		assert(int(s[i]) == tab[i])

main()
