#!/usr/bin/env python3

"""

At the first big break, Petrusha had m hryvnias, but already at the second break he was so hungry that he decided to spend all his money on delicious pies.
How many pies can Petrusha buy if they are sold for n hryvnias?

Input
Two positive integers m and n.

Output
Print the number of pies Petrusha can buy.

Examples

Input #1
27 10

Answer #1
2

"""

def solve(m, n):
    if n == 0:
        return 0
    return m//n

def main():
    assert(solve(27, 10) == 2)

main()
