#!/usr/bin/env python3

def solve(n):
    print("The parity of %s is %d (mod 2)." % (bin(n)[2:], n.bit_count()))

def main():
    solve(1)
    solve(2)
    solve(10)
    solve(21)

main()

