#!/usr/bin/env python3

"""

Introduction
Consider a sequence of integers f defined as follows:

f(2)=2
If n is an odd prime, then f(n)=f(n−1)+f(n+1)2
If n=p⋅q is composite, then f(n)=f(p)⋅f(q)
It's not very hard to see that f(n)=n for every n≥2, and thus computing f wouldn't be a very interesting challenge. Let's make a twist to the definition: halve the first case and double the second case. We get a new sequence g defined as follows:

g(2)=1
If n is an odd prime, then g(n)=g(n-1)+g(n+1)
If n=p⋅q is composite, then g(n)=g(p)⋅g(q)

The task
Your task is to take an integer n≥2 as input, and produce g(n) as output. You don't have to worry about integer overflow, but you should be able to compute g(1025)=81 correctly, and your algorithm should theoretically work for arbitrarily large inputs.

You can write a full program or a function. The lowest byte count wins.

Example
I claimed above that g(1025)=81, so let's compute it by hand. The prime factorization of 1025 gives

1025 = 5*5*41 => g(1025) = g(5)*g(5)*g(41)
Since 41 is prime, we get

g(41) = g(40) + g(42)
Next, we compute the prime factorizations of 40 and 42:

40 = 2*2*2*5 => g(40) = g(2)*g(2)*g(2)*g(5) = g(5)
42 = 2*3*7 => g(42) = g(2)*g(3)*g(7) = g(3)*g(7)
For these small primes we get

g(3) = g(2) + g(4) = 1 + 1 = 2
g(5) = g(4) + g(6) = 1 + 2 = 3
g(7) = g(6) + g(8) = 2 + 1 = 3

This means that

g(41) = g(40) + g(42) = g(5) + g(3)*g(7) = 3 + 2*3 = 9

and

g(1025) = g(5)*g(5)*g(41) = 3*3*9 = 81
Test cases

Here are the values of g up to 50.

2 -> 1
3 -> 2
4 -> 1
5 -> 3
6 -> 2
7 -> 3
8 -> 1
9 -> 4
10 -> 3
11 -> 5
12 -> 2
13 -> 5
14 -> 3
15 -> 6
16 -> 1
17 -> 5
18 -> 4
19 -> 7
20 -> 3
21 -> 6
22 -> 5
23 -> 7
24 -> 2
25 -> 9
26 -> 5
27 -> 8
28 -> 3
29 -> 9
30 -> 6
31 -> 7
32 -> 1
33 -> 10
34 -> 5
35 -> 9
36 -> 4
37 -> 11
38 -> 7
39 -> 10
40 -> 3
41 -> 9
42 -> 6
43 -> 11
44 -> 5
45 -> 12
46 -> 7
47 -> 9
48 -> 2
49 -> 9
50 -> 9

"""

from functools import *
from sympy import *

@lru_cache(maxsize=None)
def f(n):
    if n < 2:
        return 0
    if n == 2:
        return 1

    if isprime(n):
        return f(n - 1) + f(n + 1)

    r = 1
    p = factorint(n)
    for x in p:
        for _ in range(p[x]):
            r *= f(x)
    return r

def main():
    tab = [1, 2, 1, 3, 2, 3, 1, 4, 3, 5, 2, 5, 3, 6, 1, 5, 4, 7, 3, 6, 5, 7, 2, 9, 5, 8, 3, 9, 6, 7, 1, 10, 5, 9, 4, 11, 7, 10, 3, 9, 6, 11, 5, 12, 7, 9, 2, 9, 9]
    for i in range(len(tab)):
        assert(f(i + 2) == tab[i])

main()

