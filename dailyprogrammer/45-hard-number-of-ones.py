#!/usr/bin/env python3

"""

If you list all positive integers less than or equal to 20, you get this:

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

If you count the number of times the digit "1" appears in that list, you get 12. Define a function f(n) which gives the number of 1's needed to write out all numbers 1 to n in decimal notation.

Here is a couple of example values for f(n):

f(20) = 12
f(1234) = 689
f(5123) = 2557
f(70000) = 38000
f(123321) = 93395
f( 3^35 ) = 90051450678399649
By the way, all numbers in this problem, inputs and outputs alike, fit into 64-bit integers.

Can you implement f(n) in a way that is faster than just listing the values less than n and counting the instances of 1?

What is f( 520 )?

Bonus: A curious thing happens when you try and calculate f(35199981). You get 35199981, the same number you put in. You can prove that the number of times f(n) is equal to n is finite. What is the sum of all n such that f(n) == n?

Since this problem is harder than most problems here, I'll give you two hints for solving it.

Hint for calculating f(n):

The numbers f(10^n - 1) (i.e. f(9), f(99), f(999), f(9999), ....) all follow a very regular pattern that is
trivial to evaluate. If you figure out this pattern (it's not very complicated), you should
be able to figure out what (for instance) f(99999) is instantaneously.
Once you have f(99999), what is f(100000)? What is f(200000)? What is f(299999)?
Hint for the bonus:

There are 83 such numbers, and they are all less than 10^11
Good luck!

Thanks to Rinfiyks for posting this problem in r/dailyprogrammer_ideas! Do you have a problem you think would be good for us? Head over there and post it!

"""

def n1s(n):
    if n < 1:
        return 0

    r = n1s(n//10)
    if n%10 == 1:
        r += 1
    return r

def n1t(n):
    if n < 2:
        return 0

    r = n1s(n//10)*(n%10) + n//10 + 10*n1t(n//10)
    if n%10 > 1:
        r += 1
    return r

# https://oeis.org/A094798
def solve(n):
    return n1t(n + 1)

def main():
    tab = [
        1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 13, 13,
        13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16,
        16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18
    ]

    assert(solve(20) == 12)
    assert(solve(1234) == 689)
    assert(solve(5123) == 2557)
    assert(solve(70000) == 38000)
    assert(solve(123321) == 93395)
    assert(solve(3**35) == 90051450678399649)
    assert(solve(5**20) == 134507752666859)

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i])

main()
