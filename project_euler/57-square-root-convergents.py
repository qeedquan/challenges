#!/usr/bin/env python3

"""

It is possible to show that the square root of two can be expressed as an infinite continued fraction.

sqrt(2) = 1 + 1/(2 + 1/(2 + 1/(2 + ...)))

By expanding this for the first four iterations, we get:

1 + 1/2 = 3/2 = 1.5
1 + 1/(2 + 1/2) = 7/5 = 1.4
1 + 1/(2 + 1/(2 + 1/2)) = 17/12 ~ 1.466...
1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 ~ 1.41379...

The next three expansions are 99/70, 239/169, 577/408, but the eight expansion 1393/985 is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.

In the first one-thousand expansions, how many fractions contain a numerator with more digits than the denominator?

"""

# https://oeis.org/A155046
def solve(n):
    a, b, c = 1, 1, 0
    for i in range(1, n+1):
        a, b = a + 2*b, a + b
        if len(str(a)) > len(str(b)):
            c += 1
    return c

def main():
    print(solve(1000))

main()
