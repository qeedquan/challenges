#!/usr/bin/env python3

"""

Given a positive integer number n output its perfect radical.

Definition
A perfect radical r of a positive integer n is the lowest integer root of n of any index i:

r = ith_sqrt(n)

where r is an integer.

In other words i is the maximum exponent such that r raised to i is n:

n=r^i

This is OEIS A052410.

Special cases
For n=1 we don't really care about the degree i as we are asked to return r in this challenge.

Just take r=1 for n=1.
Since there is an OEIS for this and it starts from 1 you don't have to handle n=0.

Note

A positive integer n is expressed in the form 100...000 if we convert it to base r
For example the perfect radical of 128 is 2 which is 1000000 in base 2, a 1 followed by i−1 0s.

Input: a positive integer. You don't not have to handle inputs not supported by your language (obviously, abusing this is a standard loophole.)

Output: the perfect radical of that number.

You may instead choose to take a positive integer n and output the radicals of the first n positive integers, or to output the infinite list of radicals.

Test cases
This is a list of all numbers n≤10000 where n≠r (expect for n=1, included as an edge case, included also some cases where r==n for completeness sake ) :

[n, r]
[1, 1],
[2,2],
[3,3],
[4, 2],
[5,5],
[6,6],
[7,7],
[8, 2],
[9, 3],
[10,10],
[16, 2],
[25, 5],
[27, 3],
[32, 2],
[36, 6],
[49, 7],
[64, 2],
[81, 3],
[100, 10],
[121, 11],
[125, 5],
[128, 2],
[144, 12],
[169, 13],
[196, 14],
[216, 6],
[225, 15],
[243, 3],
[256, 2],
[289, 17],
[324, 18],
[343, 7],
[361, 19],
[400, 20],
[441, 21],
[484, 22],
[512, 2],
[529, 23],
[576, 24],
[625, 5],
[676, 26],
[729, 3],
[784, 28],
[841, 29],
[900, 30],
[961, 31],
[1000, 10],
[1024, 2],
[1089, 33],
[1156, 34],
[1225, 35],
[1296, 6],
[1331, 11],
[1369, 37],
[1444, 38],
[1521, 39],
[1600, 40],
[1681, 41],
[1728, 12],
[1764, 42],
[1849, 43],
[1936, 44],
[2025, 45],
[2048, 2],
[2116, 46],
[2187, 3],
[2197, 13],
[2209, 47],
[2304, 48],
[2401, 7],
[2500, 50],
[2601, 51],
[2704, 52],
[2744, 14],
[2809, 53],
[2916, 54],
[3025, 55],
[3125, 5],
[3136, 56],
[3249, 57],
[3364, 58],
[3375, 15],
[3481, 59],
[3600, 60],
[3721, 61],
[3844, 62],
[3969, 63],
[4096, 2],
[4225, 65],
[4356, 66],
[4489, 67],
[4624, 68],
[4761, 69],
[4900, 70],
[4913, 17],
[5041, 71],
[5184, 72],
[5329, 73],
[5476, 74],
[5625, 75],
[5776, 76],
[5832, 18],
[5929, 77],
[6084, 78],
[6241, 79],
[6400, 80],
[6561, 3],
[6724, 82],
[6859, 19],
[6889, 83],
[7056, 84],
[7225, 85],
[7396, 86],
[7569, 87],
[7744, 88],
[7776, 6],
[7921, 89],
[8000, 20],
[8100, 90],
[8192, 2],
[8281, 91],
[8464, 92],
[8649, 93],
[8836, 94],
[9025, 95],
[9216, 96],
[9261, 21],
[9409, 97],
[9604, 98],
[9801, 99],
[10000, 10]

Rules
Input/output can be given by any convenient method.
You can print it to STDOUT, return it as a function result or error message/s.
Either a full program or a function are acceptable.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

"""

# https://oeis.org/A052410
def gen(n):
    r = [1] + [0]*(n - 1)
    for i in range(2, n + 1):
        if not r[i - 1]:
            j = i
            while j <= n:
                r[j - 1] = i
                j *= i
    return r

def main():
    tab = [
        [1, 1],
        [2, 2],
        [3, 3],
        [4, 2],
        [5, 5],
        [6, 6],
        [7, 7],
        [8, 2],
        [9, 3],
        [10, 10],
        [16, 2],
        [25, 5],
        [27, 3],
        [32, 2],
        [36, 6],
        [49, 7],
        [64, 2],
        [81, 3],
        [100, 10],
        [121, 11],
        [125, 5],
        [128, 2],
        [144, 12],
        [169, 13],
        [196, 14],
        [216, 6],
        [225, 15],
        [243, 3],
        [256, 2],
        [289, 17],
        [324, 18],
        [343, 7],
        [361, 19],
        [400, 20],
        [441, 21],
        [484, 22],
        [512, 2],
        [529, 23],
        [576, 24],
        [625, 5],
        [676, 26],
        [729, 3],
        [784, 28],
        [841, 29],
        [900, 30],
        [961, 31],
        [1000, 10],
        [1024, 2],
        [1089, 33],
        [1156, 34],
        [1225, 35],
        [1296, 6],
        [1331, 11],
        [1369, 37],
        [1444, 38],
        [1521, 39],
        [1600, 40],
        [1681, 41],
        [1728, 12],
        [1764, 42],
        [1849, 43],
        [1936, 44],
        [2025, 45],
        [2048, 2],
        [2116, 46],
        [2187, 3],
        [2197, 13],
        [2209, 47],
        [2304, 48],
        [2401, 7],
        [2500, 50],
        [2601, 51],
        [2704, 52],
        [2744, 14],
        [2809, 53],
        [2916, 54],
        [3025, 55],
        [3125, 5],
        [3136, 56],
        [3249, 57],
        [3364, 58],
        [3375, 15],
        [3481, 59],
        [3600, 60],
        [3721, 61],
        [3844, 62],
        [3969, 63],
        [4096, 2],
        [4225, 65],
        [4356, 66],
        [4489, 67],
        [4624, 68],
        [4761, 69],
        [4900, 70],
        [4913, 17],
        [5041, 71],
        [5184, 72],
        [5329, 73],
        [5476, 74],
        [5625, 75],
        [5776, 76],
        [5832, 18],
        [5929, 77],
        [6084, 78],
        [6241, 79],
        [6400, 80],
        [6561, 3],
        [6724, 82],
        [6859, 19],
        [6889, 83],
        [7056, 84],
        [7225, 85],
        [7396, 86],
        [7569, 87],
        [7744, 88],
        [7776, 6],
        [7921, 89],
        [8000, 20],
        [8100, 90],
        [8192, 2],
        [8281, 91],
        [8464, 92],
        [8649, 93],
        [8836, 94],
        [9025, 95],
        [9216, 96],
        [9261, 21],
        [9409, 97],
        [9604, 98],
        [9801, 99],
        [10000, 10],
    ]

    r = gen(tab[len(tab)-1][0])
    for i, v in tab:
        assert(r[i - 1] == v)

main()
