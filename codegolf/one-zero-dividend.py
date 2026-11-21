#!/usr/bin/env python3

"""

Challenge description
For every positive integer n there exists a number having the form of 111...10...000 that is divisible by n i.e. a decimal number that starts with all 1's and ends with all 0's. This is very easy to prove: if we take a set of n+1 different numbers in the form of 111...111 (all 1's), then at least two of them will give the same remainder after division by n (as per pigeonhole principle). The difference of these two numbers will be divisible by n and will have the desired form. Your aim is to write a program that finds this number.

Input description
A positive integer.

Output description
A number p in the form of 111...10...000, such that p ≡ 0 (mod n). If you find more than one - display any of them (doesn't need to be the smallest one).

Notes
Your program has to give the answer in a reasonable amount of time. Which means brute-forcing is not permited:

p = 0
while (p != 11..10.00 and p % n != 0)
    p++
Neither is this:

do
    p = random_int()
while (p != 11..10.00 and p % n != 0)
Iterating through the numbers in the form of 11..10..00 is allowed.

Your program doesn't need to handle an arbitrarily large input - the upper bound is whatever your language's upper bound is.

Sample outputs
2: 10
3: 1110
12: 11100
49: 1111111111111111111111111111111111111111110
102: 1111111111111111111111111111111111111111111111110

"""

from sympy import totient

"""

@xnor

It would suffice to use the factorial n! instead of φ(n), but printing that many ones does not have a reasonable run-time.

Claim: 9φ(n) ones followed by n zeroes is a multiple of n.

Proof: First, let's prove this for the case that n is not a multiple of 2,3,or 5. We'll show the number with consisting of φ(n) ones is a multiple of n.

The number made of k ones equals (10^k-1)/9. Since n is not a multiple of 3, this is a multiple of n as long as 10^k-1 is a factor of n, or equivalently if 10^k≡1 mod n.
Note that this formulation makes apparent that if k works for the number of ones, then so does any multiple of k.

So, we're looking for k to be a multiple of the order of k in the multiplicative group modulo n.
By Lagrange's Theorem, any such order is a divisor of the size of the group.
Since the elements of the group are the number from 1 to n that are relatively prime to n, its size is the Euler totient function φ(n).
So, we've shown that 10φ(n)≡1 mod n, and so the number made of φ(n) ones is a multiple of n.

Now, let's handle potential factors of 3 in n. We know that 10^φ(n)-1 is a multiple of n, but (10^φ(n)-1)/9 might not be.
But, (10^9φ(n)-1)/9 is a multiple of 9 because it consists of 9φ(n) ones, so the sum of its digits a multiple of 9. And we've noted that multiplying the exponent k by a constant preserves the divisibility.

Now, if n has factors of 2's and 5's, we need to add zeroes to end of the output.
It way more than suffices to use n zeroes (in fact log2(n) would do). So, if our input n is split as n = 2a × 5b × m, it suffices to have 9φ(m) ones to be a multiple of n, multiplied by 10n to be a multiple of 2a×5b.
And, since n is a multiple of m, it suffices to use 9φ(n) ones. So, it works to have 9φ(n) ones followed by n zeroes.

"""

def ozd(n):
    if n < 1:
        return 0
    return int('1'*9*totient(n) + '0'*n)

def test(n):
    z = ozd(n)
    assert(z%n == 0)
    assert((z-n)%n == 0)

def main():
    for i in range(1, 250):
        test(i)

main()
