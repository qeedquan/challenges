#!/usr/bin/env python3

"""

First 15 numbers of the A046173:

1, 99, 9701, 950599, 93149001, 9127651499, 894416697901, 87643708742799, 8588189040096401, 841554882220704499, 82463790268588944501, 8080609891439495856599, 791817305570802005002201, 77590015336047156994359099, 7603029685627050583442189501
Your task is simple, output the first 20 numbers of this sequence on separate lines.

A simple explanation to this sequence, (you can also refer to the link above), is
As n increases, this sequence is approximately geometric with common ratio r = lim(n->oo) a(n)/a(n-1) = (sqrt(2) + sqrt(3))^4 = 49 + 20*sqrt(6)

This is code-golf, so shortest code wins!

"""

# https://oeis.org/A046173
def seq(n):
    if n < 0:
        return 0

    a, b = 1, 99
    for i in range(n):
        a, b = b, 98*b - a
    return a

def main():
    tab = [
        1, 99, 9701, 950599, 93149001, 9127651499, 894416697901,
        87643708742799, 8588189040096401, 841554882220704499,
        82463790268588944501, 8080609891439495856599, 791817305570802005002201,
        77590015336047156994359099, 7603029685627050583442189501
    ]

    for i in range(len(tab)):
        assert(seq(i) == tab[i])

main()
