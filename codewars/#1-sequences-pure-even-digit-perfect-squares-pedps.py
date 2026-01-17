#!/usr/bin/env python3

"""

The integer 64 is the first integer that has all of its digits even and furthermore, is a perfect square.

The second one is 400 and the third one 484.

Give the numbers of this sequence that are in the range [a,b] (both values inclusive)

Examples:

even_digit_squares(100, 1000) == [400, 484] # the output should be sorted.
even_digit_squares(1000, 4000) == []
Features of the random tests for even_digit_squares(a, b)

number of Tests = 167
maximum value for a = 1e10
maximum value for b = 1e12
You do not have to check the entries, a and b always positive integers and a < b

Happy coding!!

"""

from math import isqrt

# https://oeis.org/A030098
def even_digit_squares(a, b):
    r = []
    for i in range(isqrt(a), isqrt(b) + 1, 2):
        if all(d in "02468" for d in str(i*i)):
            r.append(i*i)
    return r

def main():
    tab = [
        0, 4, 64, 400, 484, 4624, 6084, 6400, 8464, 26244, 28224, 40000, 40804,
        48400, 68644, 88804, 228484, 242064, 248004, 446224, 462400, 608400,
        640000, 806404, 824464, 846400, 868624, 2022084, 2226064, 2244004,
        2624400, 2822400, 2862864, 4000000, 4008004, 4080400
    ]

    assert(even_digit_squares(0, max(tab)) == tab)
    assert(even_digit_squares(100, 1000) == [400, 484])
    assert(even_digit_squares(1000, 4000) == [])

main()
