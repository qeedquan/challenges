#!/usr/bin/env python3

"""

We've had powerful numbers, yes, but what about highly powerful numbers?

Highly powerful numbers
Let n be a positive integer in the form

n = p1^e_p1(n) * p2^e_p2(n) * pk^ep_k(n)

for distinct, increasing primes  p1,p2,...,pk and, where  epi(n) is a positive integer for all i=1,2,...,k.
Note that we don't include zero exponents here.

Now, for such an n, define

prodexp(n) = 1                      if n = 1
             Sum[i=1, k] e^p_i(n)   if n > 1

Such an n is said to be highly powerful if, for all 1≤m<n, prodexp(m)<prodexp(n).

For example, n=8 is a highly powerful number as we have prodexp(n)=3 and

m prodexp(m)

1 1

2 1

3 1

4 2

5 1

6 1

7 1

All of which are strictly less than 3=prodexp(8).
Whereas n=7 is not highly powerful as prodexp(7)=1<2=prodexp(4).

The first few highly powerful numbers are

1, 4, 8, 16, 32, 64, 128, 144, 216, 288, 432, 864, 1296, 1728, 2592
This is A005934 on OEIS.

This is a standard sequence challenge. You may choose whether to

Take a positive integer n and output the nth highly powerful number (you may choose between 0 and 1 indexing)
Take a positive integer n and output the first n highly powerful numbers
Output all highly powerful numbers indefinitely
This is a code-golf challenge, so the shortest answer in bytes in each language wins.

"""

from sympy import *

# https://oeis.org/A005934
def gen(L):
    r = []
    m = n = 0
    while len(r) < L:
        n += 1
        t = prod(factorint(n).values())
        if t > m:
            r.append(n)
        m = max(m, t)
    return r

def main():
    tab = [
        1, 4, 8, 16, 32, 64, 128, 144, 216, 288, 432, 864, 1296, 1728, 2592,
        3456, 5184, 7776, 10368, 15552, 20736, 31104, 41472, 62208, 86400
    ]

    assert(gen(len(tab)) == tab)

main()
