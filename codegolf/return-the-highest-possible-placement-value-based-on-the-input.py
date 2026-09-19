#!/usr/bin/env python3

"""

Introduction
The challenge itself was something I came across and had to try and figure out for a personal of project of mine. I ended up branching out and asking family members if they could provide an equation to meet the requirements.

Note: I have (with the help of others) found a solution for this but now I'm just trying to see how others would approach this.

Challenge
Take the following scenario where the left hand side number is N (the input):

N    Output
0 -> 9
1 -> 99
2 -> 999
3 -> 9999
4 -> 99,999
5 -> 999,999
...
15 -> 9,999,999,999,999,999
So, essentially, for an input number N, your program must provide the highest integer with N + 1 decimal places.

Note: Commas are not required to separate the numbers, I placed them above purely for readability.

Criteria of Success
The criteria of success is based on the following:

Shortest in terms of code size

"""

# https://oeis.org/A002283
def equation(n):
    return 10**(n+1) - 1

def main():
    assert(equation(0) == 9)
    assert(equation(1) == 99)
    assert(equation(2) == 999)
    assert(equation(3) == 9999)
    assert(equation(4) == 99999)
    assert(equation(5) == 999999)
    assert(equation(15) == 9999999999999999)

main()
