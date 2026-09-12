#!/usr/bin/env python3

"""

A number is a Mersenne Prime if it is both prime and can be written in the form 2m-1, where m is a positive integer.

For example:

7 is a Mersenne Prime because it is 23-1
11 is not a Mersenne Prime because it cannot be written as 2m-1
15 is not a Mersenne Prime because it is not prime
The first few Mersenne primes:

3
7
31
127
8191
Your task:

Take a user input (it will be a positive integer) - let's call it n
Find the nth Mersenne prime and output it in the format shown below
Example output:

With an input of 4, the output should be 127. (But this is sequence so any form of output is allowed)

I'll add my attempt at this as an answer, but I'm sure that it can be golfed down a bit.

As this is code-golf, all languages are accepted, and the shortest answer wins!

"""

from sympy.ntheory.factor_ import *

# https://oeis.org/A000668
def gen(n):
    r = []
    i = 1
    while len(r) < n:
        r.append(2**mersenne_prime_exponent(i) - 1)
        i += 1
    return r

def main():
    tab = [3, 7, 31, 127, 8191, 131071, 524287, 2147483647, 2305843009213693951, 618970019642690137449562111, 162259276829213363391578010288127, 170141183460469231731687303715884105727]

    assert(gen(len(tab)) == tab)

main()
