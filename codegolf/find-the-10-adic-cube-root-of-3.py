#!/usr/bin/env python3

"""

I like to think of a 10-adic number as a number that goes infinitely to the left, or an integer modulo a very very large power of 10.

Things carry infinitely to the left and vanish. To see what I mean, note that ...6667 * 3 = 1 in the 10-adic land, since the "2" that carries to the left goes to infinity.

Addition and multiplication make sense for 10-adic numbers, since the last n digits of the sum/product only depend on the last n digits of the summands/multiplicands.

Given n, you need to print the last n digits of the 10-adic cube root of 3, i.e. x satisfiying x*x*x = 3.

It ends:

...878683312291648481630318492665160423850087895134587
Your code must terminate for n=1000 before submission.

Let's say that if the number you need to print begins with zero, then you don't need to print the leading zeroes, since it isn't actually the point to print extra zeroes.

This is code-golf. Shortest answer in bytes wins.

"""

"""

@xnor

The pow function efficiently computes the modular exponent 3**(10**k*2/3+1)%10**k.

We're asked to find a solution to r**3 = 3 (mod 10**k). We want to find an exponent e for which the map x -> x**e is inverse to cubing x -> x**3 working mod 10**k, just as the decryption and encryption exponents in RSA cancel to produce the original value. This means that (x**3)**e = x (mod 10**k) for all x. (We'll assume throughout that gcd(x,10) = 1.) Then, we can recover r by inverting the cubing to get r = 3**e (mod 10**k).

Expanding out (r**3)**e = r (mod 10**k), we get

r**(3*e-1) = 1 (mod 10**k)
We're looking for an exponent 3*e-1 that guarantees that multiplying that many copies gives us 1.

Multiplication modulo 10**k forms a group for invertible numbers, that is those with gcd(x,10) = 1. By Lagrange's Theorem, x**c = 1 where c is the count of elements in the group. For the group modulo N, that count is the Euler totient value φ(N), the number of values from 1 to N that are relatively prime to N. So, we have r**φ(10**k) = 1 (mod 10**k). Therefore, its suffices for 3*e-1 to be a multiple of φ(10**k).

We compute

φ(10**k) = φ(5**k) φ(2**k)= 4 * 5**(k-1) * 2**(k-1) = 4 * 10**(k-1)`
So, we want 3*e-1 to be a multiple of 4 * 10**(k-1)

3*e - 1 = r * 4 * 10**(k-1)
e = (4r * 10**(k-1) + 1)/3
Many choices are possible for r, but r=5 gives the short expression

e = (2 * 10**k + 1)/3
with e a whole number. A little golfing using floor-division shortens e to 10**k*2/3+1, and expressing r = 3**e (mod 10**k) gives the desired result r.

"""

def solve(n):
    return pow(3, (2 * 10**n)//3 + 1, 10**n)

def main():
    print(solve(3))

main()
