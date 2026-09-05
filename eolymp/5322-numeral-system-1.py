#!/usr/bin/env python3

"""

The number a is given in binary notation. Print the number a in hexadecimal notation without leading zeros.

Input
The number a in binary notation, 0<length of a number≤10^4.

Output
Print the number a in hexadecimal notation, using symbols ′0′,…,′9′ and ′A′,…,′F′.

Examples

Input #1
1

Answer #1
1

Input #2
10

Answer #2
2

"""

def solve(s):
    return hex(int(s, 2))[2:]

def main():
    assert(solve("1") == "1")
    assert(solve("10") == "2")

main()
