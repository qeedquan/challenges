#!/usr/bin/env sage

"""

Your challenge is to print any 100 consecutive digits of π. You must give the index at which that subsequence appears. The 3 is not included.

For example, you could print any of the following:

1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679 (index 0)
8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196 (index 100)
4428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273 (index 200)
Output may be as a string / digit list / etc.

To ensure answers actually produce known digits of pi, all answers must be verifiable through the Pi API (note: This API counts the 3, your answer should not).

This is code-golf, shortest wins!

"""

def main():
	R = RealField(1500);
	s = str(R(pi))
	print(s[2:102])
	print(s[102:202])
	print(s[202:302])

main()
