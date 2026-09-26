#!/usr/bin/env python3

"""

This challenge is simple enough that it's basically all in the title: you're given a positive integer N and you should return the smallest positive integer which is not a divisor of N.

An example: the divisors of N = 24 are 1, 2, 3, 4, 6, 8, 12, 24. The smallest positive integer which is not in that list is 5, so that's the result your solution should find.

This is OEIS sequence A007978.

Rules
You may write a program or a function and use any of the our standard methods of receiving input and providing output.

You may use any programming language, but note that these loopholes are forbidden by default.

This is code-golf, so the shortest valid answer – measured in bytes – wins.

Test Cases
The first 100 terms are:

2, 3, 2, 3, 2, 4, 2, 3, 2, 3, 2, 5, 2, 3, 2, 3, 2, 4, 2, 3, 2, 3, 2, 5, 2,
3, 2, 3, 2, 4, 2, 3, 2, 3, 2, 5, 2, 3, 2, 3, 2, 4, 2, 3, 2, 3, 2, 5, 2, 3,
2, 3, 2, 4, 2, 3, 2, 3, 2, 7, 2, 3, 2, 3, 2, 4, 2, 3, 2, 3, 2, 5, 2, 3, 2,
3, 2, 4, 2, 3, 2, 3, 2, 5, 2, 3, 2, 3, 2, 4, 2, 3, 2, 3, 2, 5, 2, 3, 2, 3
In particular, make sure that your answer works for inputs 1 and 2 in which case the result is larger than the input.

And for some larger test cases:

N          f(N)
1234567    2
12252240   19
232792560  23

"""

# https://oeis.org/A007978
def nondivisor(n):
    if n < 1:
        return 0

    i = 2
    while n%i == 0:
        i += 1
    return i

def main():
    tab = [2, 3, 2, 3, 2, 4, 2, 3, 2, 3, 2, 5, 2, 3, 2, 3, 2, 4, 2, 3, 2, 3, 2, 5, 2, 3, 2, 3, 2, 4, 2, 3, 2, 3, 2, 5, 2, 3, 2, 3, 2, 4, 2, 3, 2, 3, 2, 5, 2, 3, 2, 3, 2, 4, 2, 3, 2, 3, 2, 7, 2, 3, 2, 3, 2, 4, 2, 3, 2, 3, 2, 5, 2, 3, 2, 3, 2, 4, 2, 3, 2, 3, 2, 5, 2, 3, 2, 3, 2, 4, 2, 3, 2, 3, 2, 5, 2, 3, 2, 3]
    
    for i in range(len(tab)):
        assert(nondivisor(i + 1) == tab[i])

    assert(nondivisor(1234567) == 2)
    assert(nondivisor(12252240) == 19)
    assert(nondivisor(232792560) == 23)

main()
