#!/usr/bin/env python3

"""

Given n (the number of players), t (the threshold value), and s (the secret), output the n secrets generated by Shamir's Secret Sharing algorithm.

The Algorithm
For the purposes of this challenge, the computations will be done in GF(251) (the finite field of size 251, otherwise known as the integers mod 251). Ordinarily, the field would be chosen such that its size is a prime much greater than n. To simplify the challenge, the field size will be constant. 251 has been chosen because it is the largest prime representable by an 8-bit unsigned integer.

Generate t-1 random integers in the (inclusive) range [0, 250]. Label these a1 through at-1.
Construct a t-1th degree polynomial using s as the constant value and the random integers from step 1 as the coefficients of the powers of x: f(x) = s + x*a1 + x2*a2 + ... + xt-1*at-1.
Output (f(z) mod 251) for each z in the (inclusive) range [1, n].
Reference Implementation
#!/usr/bin/env python3
from __future__ import print_function
import random
import sys

# Shamir's Secret Sharing algorithm
# Input is taken on the command line, in the format "python shamir.py n t s"

n, t, s = [int(x) for x in sys.argv[1:4]]
if t > n:
    print("Error: t must be less than or equal to n")
    exit()
if n not in range(2, 251):
    print("Error: n must be a positive integer less than 251")
    exit()
if t not in range(2, 251):
    print("Error: t must be a positive integer less than 251")
    exit()
if s not in range(251):
    print("Error: s must be a non-negative integer less than 251")
    exit()
p = 251
a = [random.randrange(0, 251) for x in range(t-1)]

def f(x):
    return s + sum(c*x**(i+1) for i,c in enumerate(a))

# Outputting the polynomial is for explanatory purposes only, and should not be included
#  in the output for the challenge
print("f(x) = {0} + {1}".format(s, ' + '.join('{0}*x^{1}'.format(c, i+1) for i,c in enumerate(a))))
for z in range(1, n+1):
    print(f(z) % p)
Verification
The following Stack Snippet can be used to verify outputs:

Show code snippet

Rules
s will be a non-negative integer less than 251, and n and t will be positive integers less than 251 and greater than 1. Furthermore, you are guaranteed that the inputs are valid (meaning t <= n).
Input and output can be in any reasonable, unambiguous, and consistent format.
Random numbers are to be sampled from a uniform distribution - each possible value should have equal probability of being chosen.

"""

import random
import sys

def f(a, s, x):
    return s + sum(c*x**(i+1) for i, c in enumerate(a))

def main():
    if len(sys.argv) < 4:
        print("usage: n t s")
        exit(2)

    n, t, s = [int(x) for x in sys.argv[1:4]]
    if t > n:
        print("Error: t must be less than or equal to n")
        exit(1)
    if n not in range(2, 251):
        print("Error: n must be a positive integer less than 251")
        exit(1)
    if t not in range(2, 251):
        print("Error: t must be a positive integer less than 251")
        exit(1)
    if s not in range(251):
        print("Error: s must be a non-negative integer less than 251")
        exit(1)
    
    p = 251
    a = [random.randrange(0, 251) for x in range(t-1)]

    print("f(x) = {0} + {1}".format(s, ' + '.join('{0}*x^{1}'.format(c, i+1) for i, c in enumerate(a))))
    for z in range(1, n+1):
        print(f(a, s, z) % p)

main()