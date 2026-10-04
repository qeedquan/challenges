#!/usr/bin/env python3

"""

The triangular numbers, Tn, may be obtained by this formula:

T(n)= n*(n+1) / 2


We select, for example, the first 5 (n terms) consecutive terms of this sequence.

They will be: 1, 3, 6, 10 and 15

Now we want to obtain, again for example, the first 8 (m terms) consecutive multiples to all of these five triangular numbers.

The least common multiple of them will be, 30, so the first eight multiple terms (for the sequence of the above five triangular numbers) will be:

30, 60, 90, 120, 150, 180, 210 and 240

Finally the sum of all these multiples will be: 30 + 60 + 90 + 120 + 150 + 180 + 210 + 240 = 1080

We want a function that may calculate this sum with different values of n and m terms.

Let's see some cases:

n = 5
m = 8
# Should return 1080

Another case:

n = 7
m = 10
# Should return 23100

The values of n and m will be always integer values higher than 2.

Enjoy it!!

"""

from math import lcm

def solve(n, m):
    l = 1
    for k in range(1, n + 1):
        l = lcm(l, k*(k+1)//2)
    return l*m*(m+1)//2

def main():
    assert(solve(5, 8) == 1080)
    assert(solve(7, 10) == 23100)

main()
