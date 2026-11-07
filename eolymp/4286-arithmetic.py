#!/usr/bin/env python3

"""

Misha is Stepan's younger brother who studies in the first grade.
He is very inquisitive and constantly pesters Stepan with questions: And how much? And why? Today is not an exception.
Misha caligraphically writes out the numbers in a row and asks: _How many different digits are in this number_.
On the first examples Stepan quickly found the answer.
But further Misha wrote larger numbers.
This became a problem for Stepan.

Help Stepan - write a program that determines how many different digits are in Misha's number.

Input
One integer n (1≤n≤10^1000) written by Misha.

Output
Print the number of different digits in the number.

Examples

Input #1
1233

Answer #1
3

"""

def solve(n):
    return len(set(str(abs(n))))

def main():
    assert(solve(1233) == 3)

main()
