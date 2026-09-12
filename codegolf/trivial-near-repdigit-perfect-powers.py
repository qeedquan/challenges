#!/usr/bin/env python3

"""

Task

Output the sequence that precisely consists of the following integers in increasing order:

the 2nd and higher powers of 10 (10^i where i >= 2),
the squares of powers of 10 times 2 or 3 ((2 * 10^i)^2 and (3 * 10^i)^2 where i >= 1), and
the cubes of powers of 10 times 2 ((2 * 10^i)^3 where i >= 1).

First few terms of this sequence look like this:

100, 400, 900, 1000, 8000, 10000, 40000, 90000, 100000,
1000000, 4000000, 8000000, 9000000, 10000000, 100000000, 400000000,
900000000, 1000000000, 8000000000, 10000000000, ...

You can use any of sequence I/O methods:

Without input, output the sequence infinitely.
Given n, output the nth number of the sequence (0- or 1-indexed).
Given n, output the first n numbers of the sequence.
Standard code-golf rules apply. The shortest code in bytes wins.

The section below explains the title, but you don't need to read it to solve the challenge.

Background
A repdigit is a positive integer whose digits are all the same in base 10. A perfect power is an integer that can be made by raising an integer to the power of 2 or higher, i.e. ab where a,b are integers and b≥2.

6^5=7776 is an interesting number. It is a perfect power, and it is only 1 away from a repdigit 7777. This raises a question: are there any other numbers that are perfect powers and close to a repdigit?

A near-repdigit [1] is a k-digit positive integer such that k>=2 and exactly k-1 of the digits are the same. [1] provides the full list of perfect squares that are near-repdigits:

16, 25, 36, 49, 64, 81, 121, 144, 225, 441, 484, 676, 1444, 44944 plus the trivial ones in the form of a*100^i, where a is one of 1, 4, or 9.

[2] provides another result for perfect cubes and higher powers. It shows that, not counting the trivial ones 10^i and 8*1000^i, the list of near-repdigit perfect powers for any specific exponent is finite.
(Note that this does not imply that the list of nontrivial such numbers as a whole is finite; to the best of my knowledge, it is an open question.)
I ran my program up to 1024 but did not find any non-square ones except 27, 32, 343, 7776.

The following is the list of all near-repdigit perfect powers up to 10^10.

16, 25, 27, 32, 36, 49, 64, 81, 100, 121, 144, 225, 343, 400, 441, 484,
676, 900, 1000, 1444, 7776, 8000, 10000, 40000, 44944, 90000, 100000,
1000000, 4000000, 8000000, 9000000, 10000000, 100000000, 400000000,
900000000, 1000000000, 8000000000, 10000000000
[1] A. Gica and L. Panaitopol, On Oblath’s problem

[2] O. Kihel and F. Luca, Perfect Powers With All Equal Digits But One

"""

def gen(n):
    r, i, j, k, l = [], 2, 1, 1, 1
    while len(r) < n:
        a = 10**i
        b = (2 * 10**j)**2
        c = (3 * 10**k)**2
        d = (2 * 10**l)**3
        m = min(a, b, c, d)
        if m == a:
            r.append(a)
            i += 1
        elif m == b:
            r.append(b)
            j += 1
        elif m == c:
            r.append(c)
            k += 1
        elif m == d:
            r.append(d)
            l += 1
    return r

def main():
    tab = [100, 400, 900, 1000, 8000, 10000, 40000, 90000, 100000, 1000000, 4000000, 8000000, 9000000, 10000000, 100000000, 400000000, 900000000, 1000000000, 8000000000, 10000000000]

    assert(gen(len(tab)) == tab)

main()

