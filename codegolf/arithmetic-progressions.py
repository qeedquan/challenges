#!/usr/bin/env python3

"""

Your task is to analyse the input and output the formula for the n-th term if it is an arithmetic sequence, otherwise it should print "NAAP".

Input
Input (from STDIN) will consist of few numbers, between 4 to 10 numbers where each number will be in the range between -1000 and 1000 inclusive, separated by a delimiter (a space or a comma or a semi-colon [whichever is to your preference]). Here are some example inputs.

12,14,16,18       //valid
-3 4 5 1 -2 -4    //valid
45;35;-35         //invalid (only three numbers are present instead of the minimum of 4 numbers)
2,32;21,321       //invalid (it uses two different delimiters: `,` and `;`)

Output
The program should first check whether the input is an arithmetic progression or not.

Arithmetic Progressions (AP) in a nutshell: Every AP will have a common difference. This is the difference between the $n$ and ${n-1}$ th terms (basically $a(n+1) - a(n)$ where a is the function for the sequnce).
This difference stays the same for any value of $n$ in an AP. If there is no common difference, then it is not an arithmetic sequence.
To calculate the value of the n-th term, use this formula $a(n) = a(1) + (n-1)d$ where $a(1)$ is the first term and $d$ is the common difference.

If it is not an arithmetic progression, then the program should print the error message "NAAP" (short for "Not An Arithmetic Progression").

If it is an arithmetic progression, then the program should print the simplified n-th term of the sequence to STDOUT.

Example:

> 1,3,5,7,9
2n-1
Explanation: This is an AP because there is a common difference ($3 - 1 = 2$). Then you use the formula $a(n) = a(1) + (n-1)d$

an=a1+(n−1)d
an=1+(n−1)2
an=1+2n−2
an=2n−1

Therefore output is 2n-1 (notice the absence of spaces)

Standard loopholes are disallowed by default.

You are allowed to create a function if you want (with the array of numbers as your parameter). If not, then you must create a full program that takes input as a string or an array and outputs accordingly.

Test cases:

1.
1,3,5,7,9
2n-1

2.
1 3 12312 7 9
NAAP

3.
-6;8;22;36;50
14n-20

4.
5,1,-3,-7,-11,-15
-4n+9

5.
-5,-7,-9,-11,-13,-15
-2n-3

6.
3,3,3,3,3,3,3,3,3
0n+3

7.
-4,-5,-6,-7
-1n-3

This is code-golf so the shortest code in bytes wins! (sorry for bad math-jax)

Any suggestions are welcome!

"""

from sympy import interpolate, degree
from sympy.abc import n

def arithmetic_progression(sequence):
    function = interpolate(sequence, n)
    if degree(function) >= 2:
        return "NAAP"
    return function

def main():
    assert(arithmetic_progression([1, 3, 5, 7, 9]) == 2*n - 1)
    assert(arithmetic_progression([1, 3, 12312, 7, 9]) == "NAAP")
    assert(arithmetic_progression([-6, 8, 22, 36, 50]) == 14*n - 20)
    assert(arithmetic_progression([5, 1, -3, -7, -11, -15]) == -4*n + 9)
    assert(arithmetic_progression([-5, -7, -9, -11, -13, -15]) == -2*n - 3)
    assert(arithmetic_progression([3, 3, 3, 3, 3, 3, 3, 3, 3]) == 0*n + 3)
    assert(arithmetic_progression([-4, -5, -6, -7]) == -1*n - 3)

main()
