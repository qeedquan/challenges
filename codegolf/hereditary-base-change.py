#!/usr/bin/env python3

"""

Background
In this challenge, a base-b representation of an integer n is an expression of n as a sum of powers of b, where each term occurs at most b-1 times. For example, the base-4 representation of 2015 is

4^5 + 3*4^4 + 3*4^3 + 4^2 + 3*4 + 3
Now, the hereditary base-b representation of n is obtained by converting the exponents into their base-b representations, then converting their exponents, and so on recursively. Thus the hereditary base-4 representation of 2015 is

4^(4 + 1) + 3*4^4 + 3*4^3 + 4^2 + 3*4 + 3
As a more complex example, the hereditary base-3 representation of

7981676788374679859068493351144698070458
is

2*3^(3^(3 + 1) + 2) + 3 + 1
The hereditary base change of n from b to c, denoted H(b, c, n), is the number obtained by taking the hereditary base-b representation of n, replacing every b by c, and evaluating the resulting expression. For example, the value of

H(3, 2, 7981676788374679859068493351144698070458)
is

2*2^(2^(2 + 1) + 2) + 2 + 1 = 2051
The Challenge
You are given as input three integers b, c, n, for which you may assume n >= 0 and b, c > 1. Your output is H(b, c, n). The shortest byte count wins, and standard loopholes are disallowed. You can write either a function or a full program. You must be able to handle arbitrarily large inputs and outputs (bignums).

Test Cases
4 2 3 -> 3
2 4 3 -> 5
2 4 10 -> 1028
4 4 40000 -> 40000
4 5 40000 -> 906375
5 4 40000 -> 3584
3 2 7981676788374679859068493351144698070458 -> 2051
2 3 2051 -> 35917545547686059365808220080151141317047

Fun Fact
For any integer n, the sequence obtained by

n1 = n
n2 = H(2, 3, n1) - 1
n3 = H(3, 4, n2) - 1
n4 = H(4, 5, n3) - 1
....
eventually reaches 0. This is known as Goodstein's theorem.

"""

"""

@xnor

A recursive solution. Like the recursive algorithm to convert between bases, except it recurses on the exponent as well.

We split n into two parts, the current digit n%b, and all other digits n/b. The current place value is stored in the optional parameter s. The current digit is converted to base c with c** and the exponent s is converted recursively. The remainder is then converted the same way, as +H(b,c,n/b,s+1) but the place value s is one higher.

Unlike base conversion, hereditary base conversion required remembering the current place value in the recursion for it to converted.


"""
def H(b, c, n, s=0):
    if n < 1:
        return 0
    return (n%b)*c**H(b, c, s) + H(b, c, n//b, s + 1)

def main():
    assert(H(4, 2, 3) == 3)
    assert(H(2, 4, 3) == 5)
    assert(H(2, 4, 10) == 1028)
    assert(H(4, 4, 40000) == 40000)
    assert(H(4, 5, 40000) == 906375)
    assert(H(5, 4, 40000) == 3584)
    assert(H(3, 2, 7981676788374679859068493351144698070458) == 2051)
    assert(H(2, 3, 2051) == 35917545547686059365808220080151141317047)

main()

