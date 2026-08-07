#!/usr/bin/env python3

"""

Here's an interesting sequence discovered by Paul Loomis, a mathematician at Bloomsburg University. From his page on this sequence:

Define
f(n) = f(n-1) + (the product of the nonzero digits of f(n-1))
f(0) = x, with x as any positive integer, written in base 10.

So, starting with f(0)=1, you get the following sequence
1, 2, 4, 8, 16, 22, 26, 38, 62, 74, 102, 104, ...

So far, so standard. The interesting property comes into play when you take any other integer as the starting point, eventually the sequence converges into a point along the above x=1 sequence. For example, starting with x=3 yields
3, 6, 12, 14, 18, 26, 38, 62, 74, 102, ...

Here are some more sequences, each shown only until they reach 102:

5, 10, 11, 12, 14, 18, 26, 38, 62, 74, 102, ...
7, 14, 18, 26, 38, 62, 74, 102, ...
9, 18, 26, 38, 62, 74, 102, ...
13, 16, 22, 26, 38, 62, 74, 102, ...
15, 20, 22, 26, 38, 62, 74, 102, ...
17, 24, 32, 38, 62, 74, 102, ...
19, 28, 44, 60, 66, 102, ...
He conjectured, and empirically proved up to x=1,000,000, that this property (i.e., that all input numbers converge to the same sequence) holds true.

The Challenge

Given a positive input integer 0 < x < 1,000,000, output the number where the f(x) sequence converges to the f(1) sequence. For example, for x=5, this would be 26, since that's the first number in common to both sequences.

 x output
 1 1
 5 26
19 102
63 150056

Rules
If applicable, you can assume that the input/output will fit in your language's native Integer type.
The input and output can be given by any convenient method.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

"""

def f(a, b=1):
    if a == b:
        return a

    s = repr(a)
    s = s.replace('0', '1')
    s = '*'.join(s)
    v = eval(s)
    x = sorted([a + v, b])
    return f(x[0], x[1])

def main():
    assert(f(1) == 1)
    assert(f(5) == 26)
    assert(f(19) == 102)
    assert(f(63) == 150056)

main()
