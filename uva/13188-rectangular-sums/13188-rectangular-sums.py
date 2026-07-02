#!/usr/bin/env python3

def son(n):
    return n*(n + 1)//2

def sos(n):
    return n*(n + 1)*(2*n + 1)//6

def seq(n, i):
    mod = 1_000_000_007
    a = (n + 1 - i) * (i*i*i + i) // 2
    b = (sos(n) + son(n)) - (sos(i) + son(i))
    b = b*i // 2
    b -= i * (n - i) * i * (i + 1) // 2
    return (a + b) % mod

def solve(n):
    return seq(n, n//2 + 1)

def main():
    assert(solve(1) == 1)
    assert(solve(2) == 5)
    assert(solve(3) == 16)
    assert(solve(4) == 42)
    assert(solve(5) == 84)
    assert(solve(14) == 3612)

main()

