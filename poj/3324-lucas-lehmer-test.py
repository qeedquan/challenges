#!/usr/bin/env python3

"""

Description

In mathematics, the Lucas-Lehmer test is a primality test for Mersenne numbers (numbers of the form 2^n - 1). The test was originally developed by Edouard Lucas in 1856, and subsequently improved by Lucas in 1878 and Derrick Henry Lehmer in the 1930s. The well-known distributed computing project Great Internet Mersenne Prime Search (GIMPS) uses the test to locate Mersenne primes (Mersenne numbers that are also prime numbers). As of the time when this problem is composed, the largest known Mersenne prime is 232,382,657 − 1, which was discovered on September 4, 2006 by Curtis Cooper and Steven Boone.

The test works as follows. Let Mp = 2^p - 1 be the Mersenne number to test with p a positive integer (in real applications only large primes are of interest since primality of Mp is easy to determine when p is relatively small and if p is composite, so is Mp). Define a sequence {si} for all i ≥ 0 by

s0 = 4;
si = s^2[i-1] - 2 for all i > 0.

Then Mp is prime iff

s[p-2] ≡ 0 (mod Mp).

The number s[p-2] mod Mp is called the Lucas-Lehmer residue of p.

Your task is to write a simple implementation of the Lucas-Lehmer test.

Input

The input contains one or more positive integers below 8,192 which are not necessarily primes, one on a each line. End-of-file (EOF) indicates the end of input.

Output

For each integer in the input, output its Lucas-Lehmer residue in hexadecimal using digits 0 through 9 and lowercase letters a through f, each on a separate line.

Sample Input

59
61

Sample Output

64099e5fcbcaf36
0

Source

POJ Monthly--2007.08.05, frkstyc

"""

# https://en.wikipedia.org/wiki/Lucas%E2%80%93Lehmer_primality_test
# https://oeis.org/A003010
def residue(p):
    M = 2**p - 1
    s = 4
    for i in range(p - 2):
        s = (s**2 - 2) % M
    return hex(s)[2:]

def main():
    assert(residue(59) == "64099e5fcbcaf36")
    assert(residue(61) == "0")

main()
