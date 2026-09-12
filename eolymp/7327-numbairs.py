#!/usr/bin/env python3

"""

Consider the number of the form a^(a^a)... where a is a positive integer that can appear in the notation twice or more, ^ is power operation.
Let us call such numbers numbairs (which stands for number + stairs).
For instance 27=3^3 and 16=2^(2^2) are numbairs.
Number 1 is a numbair too since 1=1^1.
Numbers 2, 3, 5 are not numbairs because they cannot be represented in the required form.
Find out how many numbairs there are between 1 and n inclusive.

Input
One integer n (1≤n≤10^9).

Output
Print the number of numbairs not exceeding n.

Examples
Input #1
5

Answer #1
2

"""

from bisect import bisect_left

# https://oeis.org/A257309
def solve(n):
    tab = [
        1, 4, 16, 27, 256, 3125, 46656, 65536, 823543, 16777216, 387420489,
        10000000000, 285311670611, 7625597484987, 8916100448256, 302875106592253,
        11112006825558016, 437893890380859375, 18446744073709551616,
        827240261886336764177, 39346408075296537575424, 1978419655660313589123979,
        104857600000000000000000000
    ]
    return bisect_left(tab, n)

def main():
    assert(solve(5) == 2)

main()
