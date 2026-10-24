#!/usr/bin/env python3

"""

Take as input an integer in any reasonable format.

Then, output all the proper sub-strings of the base-10 digits of that integer that are powers of two, in any reasonable format.

Test cases
10230 -> [1, 2]
13248 -> [32, 1, 2, 4, 8]
333 -> []
331 -> [1]
32 -> [2] # As 32 is not a proper sub-string, since it is the whole string.
322 -> [32, 2, 2]
106 -> [1]
302 -> [2]
464 -> [4, 4, 64]
655365536 -> [65536, 65536]

"""

def ispow2(n):
    return n > 0 and (n&(n-1) == 0)

def extract(n):
    r = []
    s = str(n)
    n = len(s)
    for i in range(n):
        if s[i] == '0':
            continue

        for j in range(i+1, n+1):
            t = s[i:j]
            if s == t:
                break

            x = int(t)
            if ispow2(x):
                r.append(x)
    return r

def main():
    assert(extract(10230) == [1, 2])
    assert(extract(13248) == [1, 32, 2, 4, 8])
    assert(extract(333) == [])
    assert(extract(331) == [1])
    assert(extract(32) == [2])
    assert(extract(322) == [32, 2, 2])
    assert(extract(106) == [1])
    assert(extract(302) == [2])
    assert(extract(464) == [4, 64, 4])
    assert(extract(655365536) == [65536, 65536])

main()
