#!/usr/bin/env python3

"""

A weird number is a number that the sum of proper divisors is greater than the number itself and no subset of proper divisors sum to that number.

Examples:

70 is a weird number because its proper divisors (1, 2, 5, 7, 10, 14, and 35) sum to 74, which is greater than 70, and no combination of these numbers sum to 70.

18 is not a weird number because its proper divisors (1, 2, 3, 4, 6, 9) sum to 25, which is greater than 18, but 3, 6, and 9 sum to 18.

Your task is to write the shortest program that inputs through std-in any number n and calculates and prints to a file or std-out the first n weird numbers with newline separation. No hard coding of the answers is allowed (sorry for not specifying this in the beginning).

For more examples, see this page: http://mathworld.wolfram.com/WeirdNumber.html

"""

"""

Ported from @Stefan Pochmann solution

I use the integer s as a bitset, telling me the sums of divisors of i. The k-th bit tells me whether k is a sum of the divisors found.

https://oeis.org/A006037

"""

def gen(n):
    r = []
    i = 0
    while n > 0:
        i += 1
        s = 1
        d = 1
        while d < i:
            if i%d == 0:
                s |= s << d
            d += 1
        s >>= i

        if s > 1 and s&1 == 0:
            r.append(i)
            n -= 1
    return r

def main():
    tab = [70, 836, 4030, 5830]

    assert(gen(len(tab)) == tab)

main()
