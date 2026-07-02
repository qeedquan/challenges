#!/usr/bin/env python3

def solve(n):
    if n < 2:
        return "Not an Automorphic number."

    N = str(n)
    N2 = str(n * n)
    if N2.endswith(N):
        return "Automorphic number of %d-digit." % (len(N))
    return "Not an Automorphic number."

def main():
    print(solve(5))
    print(solve(76))
    print(solve(34))

main()
