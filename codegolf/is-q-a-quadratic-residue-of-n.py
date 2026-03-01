#!/usr/bin/env python3

"""

Given two inputs q n determine if q is a quadratic residue of n.

That is, is there an x where x**2 == q (mod n) or is q a square mod n?

Input

Two integers q and n, where q and n are any integers 0 <= q < n.

Output

A truthy or a falsey.

Optionally, print any (or all) x that is x**2 == q (mod n)

Examples

>>> quadratic_residue(1, 5)
True
>>> quadratic_residue(3, 8)
False
>>> quadratic_residue(15, 22)
True
Rules

Your code must be a program or a function. The inputs can be in any order. This is code golf, so shortest code in bytes wins.

If anything is unclear or otherwise needs fixing, please let me know.

Bonuses

2-byte bonus if your function accepts q as any arbitrary integer.

"""

def quadratic_residue(q, n):
    if n == 0:
        return False

    for x in range(n):
        if (x*x)%n == q:
            return True
    return False

def main():
    assert(quadratic_residue(1, 5) == True)
    assert(quadratic_residue(3, 8) == False)
    assert(quadratic_residue(15, 22) == True)

main()
