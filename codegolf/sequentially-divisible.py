#!/usr/bin/env python3

"""

Sometimes to fall asleep, I'll count as high as I can, whilst skipping numbers that are not square-free. I get a little thrill when I get to skip over several numbers in a row - for example, 48,49,50 are all NOT square-free (48 is divisible by 2^2, 49 by 7^2, and 50 by 5^2).

This led me to wondering about the earliest example of adjacent numbers divisible by some arbitrary sequence of divisors.

Input
Input is an ordered list a = [a_0, a_1, ...] of strictly positive integers containing at least 1 element.

Output
Output is the smallest positive integer n with the property that a_0 divides n, a_1 divides n+1, and more generally a_k divides n+k. If no such n exists, the function/program's behavior is not defined.

Test Cases
[15] -> 15
[3,4,5] -> 3
[5,4,3] -> 55
[2,3,5,7] -> 158
[4,9,25,49] -> 29348
[11,7,5,3,2] -> 1518
Scoring
This is code-golf; shortest result (per language) wins bragging rights. The usual loopholes are excluded.

"""

def f(x):
    n = 1
    while n:
        n += 1
        if all((n + i)%m < 1 for i, m in enumerate(x)):
            return n
    return 0

def main():
    assert(f([15]) == 15)
    assert(f([3, 4, 5]) == 3)
    assert(f([5, 4, 3]) == 55)
    assert(f([2, 3, 5, 7]) == 158)
    assert(f([4, 9, 25, 49]) == 29348)
    assert(f([11, 7, 5, 3, 2]) == 1518)

main()
