#!/usr/bin/env python3

"""

What is Permutation Coefficient
Permutation refers to the process of arranging all the members of a given set to form a sequence. The number of permutations on a set of n elements is given by n! , where “!” represents factorial. The Permutation Coefficient represented by P(n, k) is used to represent the number of ways to obtain an ordered subset having k elements from a set of n elements.

Mathematically,

P(n, k) = n.(n-1).(n-2) ... (n-k+1)

which is 0 when k > n, and otherwise equal to
n! / (n-k)!

Examples:
P(10, 2) = 90
P(10, 3) = 720
P(10, 0) = 1
P(10, 1) = 10
To Calculate the Permutation Coefficient, you can use the following recursive approach:

P(n, k) = P(n-1, k) + k * P(n-1, k-1)

Though, this approach can be slow at times. So Dynamic approach is preferred mostly.

Example of Dynamic Approach (Python)
https://tio.run/##fZHLDoIwEEX3fMVdFtEEdEdk5Q@wb1iQ2GpBpqSWhV@PlEdARCdNps2cufNo/bJ3Tae2vQqJWpiqsblVmi5aSMloj9KP4cEdIEUCzkNIbaCgCCanm2AlAkR@NkKTOaiYIRqhSWulMYTjWWKVXiliynUzcx/VlAQrkCQIlyKTpVxlvMi69qN1ong8xd@M7oYDov4VgH2jCyuwW/C983@0ep42u1XXDelqh33cCNsY6kKU8XLYILlRQq/s3NHzaqPIsu3f89v2DQ
def permutationCoeff(n, k): 
  
    P = [[0 for i in range(k + 1)]  
            for j in range(n + 1)] 
  
    for i in range(n + 1): 
        for j in range(min(i, k) + 1): 
  
            if (j == 0): 
                P[i][j] = 1
  
            else: 
                P[i][j] = P[i - 1][j] + ( 
                           j * P[i - 1][j - 1]) 
  
            if (j < k): 
                P[i][j + 1] = 0
    return P[n][k] 
  
n = 10
k = 2

print(permutationCoeff(n, k))


Input Format
{n} {k}

Output Format
{PermutationCoefficient}

Test Cases
INPUT - 100 2
OUTPUT - 9900

INPUT - 69 5
OUTPUT - 1348621560

INPUT - 20 19
OUTPUT - 2432902008176640000

INPUT - 15 11
OUTPUT - 54486432000
Constraints in input
N will always be greater than or equal to K.

(Not to be confused with Binomial Coefficient)

"""

from math import perm

def main():
    assert(perm(100, 2) == 9900)
    assert(perm(69, 5) == 1348621560)
    assert(perm(20, 19) == 2432902008176640000)
    assert(perm(15, 11) == 54486432000)

main()
