#!/usr/bin/env python3

"""

Find K — the number of N-digit natural numbers that contain at least one digit 7.

Input
The only positive integer N (1≤N≤10).

Output
Output the number K.

Examples

Input #1
2

Answer #1
18

"""

# https://oeis.org/A088924
def solve(n):
    if n < 1:
        return 0
    return 10**n - 10**(n - 1) - 8*9**(n - 1)

def main():
    tab = [
        1, 18, 252, 3168, 37512, 427608, 4748472, 51736248, 555626232, 5900636088,
        62105724792, 648951523128, 6740563708152, 69665073373368, 716985660360312,
        7352870943242808, 75175838489185272, 766582546402667448
    ]

    assert(solve(2) == 18)

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i])

main()
