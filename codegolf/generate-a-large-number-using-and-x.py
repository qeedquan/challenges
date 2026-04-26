#!/usr/bin/env python3

"""

Let's play a game using only +, ×, and = operations!

Start with a single variable initialized as x0=1. A program is a sequence of assignments using only the following operations:

xi:=xj+xk
xi:=xj×xk
Each assignment defines a new variable xi, or overwrites an existing one. In the program below, we end up with x0=36 using four operations:

x1 = x0 + x0  # 2
x2 = x1 + x0  # 3
x3 = x1 * x2  # 6
x0 = x3 * x3  # 36
You may only use variables that have already been defined earlier in the program, and there is no limit on the number of variables that can be defined.

Task
Construct a program that exactly produces x0=2^1279−1, in the fewest number of operations. For example, the program above would achieve a score of 4 for x0=36.

"""

"""

@Neil

I calculated this by hand so a computer search would probably find a better score.

"""

def gen():
	x0 = 1    
	x2 = x0 + x0
	x3 = x0 + x2
	x5 = x2 + x3
	x1 = x3 * x5 # 15
	x4 = x1 + x2 # 17
	x1 = x1 * x4 # 255
	x4 = x1 + x2 # 257
	x1 = x1 * x4 # 65535
	x4 = x1 + x1 # 131070
	x1 = x4 + x0 # 131071
	x4 = x1 + x2 # 131073
	x1 = x1 * x4 # 2^34-1
	x4 = x1 + x1 # 2^35-2
	x1 = x4 + x0 # 2^35-1
	x4 = x1 + x2 # 2^35+1
	x1 = x1 * x4 # 2^70-1
	x4 = x1 + x1 # 2^71-2
	x1 = x4 + x0 # 2^71-1
	x4 = x1 * x3 # 2^71*3-3
	x4 = x4 + x3 # 2^71*3
	x6 = x1 * x1 # 2^142-2^72+1
	x4 = x4 + x6 # 2^142+2^71+1
	x1 = x1 * x4 # 2^213-1
	x4 = x1 * x3 # 2^213*3-3
	x4 = x4 + x3 # 2^213*3
	x6 = x1 * x1 # 2^426-2^214+1
	x4 = x4 + x6 # 2^426+2^213+1
	x1 = x1 * x4 # 2^639-1
	x4 = x1 + x2 # 2^639+1
	x1 = x1 * x4 # 2^1278-1
	x1 = x1 * x2 # 2^1279-2
	x0 = x0 + x1 # 2^1279-1
	return x0

def main():
    assert(gen() == 2**1279 - 1)

main()

