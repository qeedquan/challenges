#!/usr/bin/env python3

"""

Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:

Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
Example 2:

Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".

Example 3:

Input: n = 5
Output: 68

Constraints:

1 <= n <= 2 * 10^4

Hint 1
Use dynamic programming.

Hint 2
Let dp[i][j] be the number of strings of length i that ends with the j-th vowel.

Hint 3
Deduce the recurrence from the given relations between vowels.

"""

import numpy as np

def count_vowel_permutation(n):
    if n < 1:
        return 0

    T = np.array([
        [0, 1, 1, 0, 1],
        [1, 0, 1, 0, 0],
        [0, 1, 0, 1, 0],
        [0, 0, 1, 0, 0],
        [0, 0, 1, 1, 0],
    ], dtype=object)
    
    T = np.linalg.matrix_power(T, n - 1)
    return sum(map(sum, T)) % 1_000_000_007

def main():
    assert(count_vowel_permutation(1) == 5)
    assert(count_vowel_permutation(2) == 10)
    assert(count_vowel_permutation(5) == 68)

main()

