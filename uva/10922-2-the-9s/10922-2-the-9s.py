#!/usr/bin/env python3

def digsum(n):
    r = 0
    while n > 0:
        r += n % 10
        n //= 10
    return r

def degree9(n):
    if n < 0 or n%9 != 0:
        return 0

    d = 1
    while True:
        n = digsum(n)
        if n < 10 or n%9 != 0:
            break
        d += 1
    return d

def solve(n):
    d = degree9(n)
    if d == 0:
        return f"{n} is not a multiple of 9."
    return f"{n} is a multiple of 9 and has 9-degree {d}."

def main():
    assert(solve(999999999999999999999) == "999999999999999999999 is a multiple of 9 and has 9-degree 3.")
    assert(solve(9) == "9 is a multiple of 9 and has 9-degree 1.")
    assert(solve(9999999999999999999999999999998) == "9999999999999999999999999999998 is not a multiple of 9.")

main()

