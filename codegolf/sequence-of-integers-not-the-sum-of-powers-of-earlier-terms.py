#!/usr/bin/env python3

"""

Starting with 1, output the sequence of integers which cannot be represented as the sum of powers of earlier terms. Each previous term can be used at most once, and the exponents must be non-negative integers.

This sequence starts:

1, 2, 6, 12, 25, 85, 194, 590, 1695, 4879, 19077, 83994, 167988
For example, after 1 and 2:

3=11+21, so 3 is not in the sequence
4=22, so 4 is not in the sequence
5=11+22, so 5 is not in the sequence
6 cannot be represented in this way, so 6 is in the sequence etc.
The powers can also be 0; for example, 24 = 1^1 +2^4 + 6^1 + 12^0, so 24 is not in the sequence.

This is OEIS A034875.

Rules
As with standard sequence challenges, you may choose to either:
Take an input n and output the nth term of the sequence
Take an input nand output the first n terms
Output the sequence indefinitely, e.g. using a generator
You may use 0- or 1-indexing
You may use any standard I/O method
Standard loopholes are forbidden
This is code-golf, so the shortest code in bytes wins

"""

# https://oeis.org/A034875
def gen(n):
    if n < 1:
        return []

    r = []
    m = 1
    d = 1
    while len(r) < n-1:
        q = 3
        s = (~m & (m + 1)).bit_length() - 1
        d += s
        m >>= s
        for v in r:
            w = q
            l = 1
            while l <= d:
                q |= (w << l)
                l *= v
            
            if q&(1<<d) != 0:
                break
        else:
            r.append(d)

        m |= q >> d
    
    return [1] + r

def main():
    tab = [1, 2, 6, 12, 25, 85, 194, 590, 1695, 4879, 19077, 83994, 167988, 1041780, 2448645, 9677725]
    
    assert(gen(len(tab)) == tab)

main()
