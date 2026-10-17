#!/usr/bin/env python3

"""

The negative binary system is a positional numeral system with base −2.
As in the binary system, any non-negative integer can be represented in this system.
For example, 3 10 =111 −2.
The negative binary system can also represent negative numbers as easily as positive ones: −3 10=1101 −2.
Some numbers have identical representations in both the binary and negative binary systems.
In this problem, you are to find the n-th integer whose representation is the same in both systems.

Input
The first line contains the number of test cases. Each of the next lines contains an integer N (1<N≤10^9).

Output
For each test case, output the n-th integer whose representation is the same in both the binary and negative binary systems, each on a separate line.

Examples
Input #1
3
1
10
100

Answer #1
0
65
5125

"""

def dec2nbin(n):
    if n == 0:
        return 0

    d = []
    while n != 0:
        n, r = divmod(n, -2)
        if r < 0:
            n += 1
            r += 2
        d.append(str(r))
    return int("".join(d[::-1]))

# https://oeis.org/A000695
def solve(n):
    n -= 1
    if n < 0:
        return 0

    n = bin(n)[2:]
    x = len(n)
    return sum(int(n[i]) * 4**(x - 1 - i) for i in range(x))

def solvebf(n):
    if n < 1:
        return 0

    i = j = 0
    while j < n:
        if str(dec2nbin(i)) == bin(i)[2:]:
            j += 1
        i += 1
    return i - 1

def main():
    tab = [
        0, 1, 4, 5, 16, 17, 20, 21, 64, 65, 68, 69, 80, 81, 84, 85, 256, 257,
        260, 261, 272, 273, 276, 277, 320, 321, 324, 325, 336, 337, 340, 341,
        1024, 1025, 1028, 1029, 1040, 1041, 1044, 1045, 1088, 1089, 1092, 1093,
        1104, 1105, 1108, 1109, 1280, 1281, 1284, 1285
    ]

    assert(solve(1) == 0)
    assert(solve(10) == 65)
    assert(solve(100) == 5125)

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i])

    for i in range(200):
        assert(solve(i) == solvebf(i))

main()
