#!/usr/bin/env python3

"""

Definitions
An algebraic number is a number that is a zero of a non-zero polynomial with integer coefficients. For example, the square root of 2 is algebraic, because it is a zero of x^2 - 2.
A transcendental number is a real number which is not algebraic.
Task
You are to choose a transcendental number.

Then, write a program/function that takes a positive integer n and output the n-th decimal digit after the decimal point of your chosen transcendental number. You must state clearly in your submission, which transcendental number is used.

You can use 0-indexing or 1-indexing.

Example
e^2=7.389056098... is a transcendental number. For this number:

n output
1 3
2 8
3 9
4 0
5 5
6 6
7 0
8 9
9 8
...
Note that the initial 7 is ignored.

As I mentioned above, you can choose other transcendental numbers.

Scoring
This is code-golf. Lowest score in bytes wins.

"""

"""

https://oeis.org/A054054

@xnor:
Claim: This number c is transcendental

Proof: Note that c is very sparse: almost all of its digits are zero. That's because large n, there's high probability n has a zero digit, giving a digit min of zero. Moreover, c has long runs of consecutive zeroes. We use an existing result that states this means c is transcendental.

Following this math.SE question, let Z(k) represent the position of the k'th nonzero digit of c, and let c_k be that nonzero digit, a whole number between 1 and 9. Then, we express the decimal expansion of c, but only taking the nonzero digits, as as the sum over k=1,2,3,... of c_k/10^Z(k).

We use the result of point 4 of this answer by George Lowther: that c is transcendental if there are infinitely many runs of zeroes that are at least a constant fraction of the number of digits so far. Formally, there must be an ε>0 so that Z(k+1)/Z(k) > 1+ε for infinitely many k. We'll use ε=1/9

For any number of digits d, take k with Z(k) = 99...99 with d nines. Such a k exists because this digit in c is a 9, and so nonzero. Counting up from 99...99, these numbers all contain a zero digit, so it marks the start of a long run of zeroes in c. The next nonzero digit isn't until Z(k+1) = 1111...11 with d+1 ones. The ratio Z(k+1)/Z(k) slightly exceeds 1+1/9.

This satisfies the condition for every d, implying the result.

"""
def seq(n):
    if n < 10:
        return max(0, n)
    return min(n%10, seq(n//10))

def main():
    tab = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 0, 1, 2, 3, 4, 4, 4, 4, 4, 4, 0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 0, 1, 2, 3, 4, 5, 6, 6, 6, 6, 0, 1, 2, 3, 4, 5, 6, 7, 7, 7, 0, 1, 2, 3, 4, 5, 6, 7, 8, 8, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0]

    for i in range(len(tab)):
        assert(seq(i) == tab[i])

main()
