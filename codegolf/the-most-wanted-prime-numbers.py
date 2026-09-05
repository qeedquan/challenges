#!/usr/bin/env python3

"""

Output a sequence of all the primes that are of the following form: 123...91011...(n-1)n(n-1)..11109...321. That is, ascending decimal numbers up to some n, followed by a descending tail, all concatenated.

Background
Recently, Numberphile posted a video about primes that follow this pattern.

Output
1 -> 12345678910987654321 (n=10)
2 -> 123...244524462445...321 (n=2446)
No more terms are known, but it's likely that there are infinitely many.

"""

from sympy import isprime

# https://oeis.org/A173426
def A173426(n):
    if n < 1:
        return 0
    
    s = ""
    for d in range(1, n + 1):
        s += str(d)
    for d in range(n - 1, 0, -1):
        s += str(d)
    return int(s)

def most_wanted_prime(n):
    r = 0
    i = 0
    m = 0
    while m < n:
        r = A173426(i)
        if isprime(r):
            m += 1
        i += 1
    return r

def main():
    print(most_wanted_prime(1))

main()
