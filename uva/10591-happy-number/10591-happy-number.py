#!/usr/bin/env python3

def digsum2(n):
    r = 0
    while n > 0:
        r += (n % 10)**2
        n //= 10
    return r

# https://oeis.org/A007770
def happy(n):
    m = {}
    while n not in m and n != 1:
        m[n] = True
        n = digsum2(n)
    return n == 1

def gen(n):
    r = []
    i = 1
    while len(r) < n:
        if happy(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [
        1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 49, 68, 70, 79, 82, 86, 91, 94,
        97, 100, 103, 109, 129, 130, 133, 139, 167, 176, 188, 190, 192, 193,
        203, 208, 219, 226, 230, 236, 239, 262, 263, 280, 291, 293, 301, 302,
        310, 313, 319, 320, 326, 329, 331, 338
    ]

    assert(happy(7) == True)
    assert(happy(4) == False)
    assert(happy(13) == True)

    assert(gen(len(tab)) == tab)

main()

