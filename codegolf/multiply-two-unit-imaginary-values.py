#!/usr/bin/env python3

"""

In this challenge, you will be given two numbers with magnitude 1, all positive coefficients and
only a single dimension from the Cayley-Dickson algebras (i.e. the direct limit of the Cayley-Dickson construction),
and you must return the product of the two numbers. The order of the numbers is important, or otherwise your r may have the wrong sign.

In other words, you receive two numbers both in the form ex where x≥0 and x is an integer, and you must output the product.

The Cayley-Dickson algebras are algebras recursively constructed from the real numbers in a particular way.
Given an algebra of dimensionality 2^n (n being a non-negative integer), it constructs an algebra of dimensionality 2^n + 1 by
combining two numbers of the previous dimensionality (e.g. complex numbers (dimension 2^1=2)
can be represented as the combination of two real numbers (dimension 2^0=1),
and quaternions (dimension 2^2=4) as the combination of two complex numbers (dimension 2^1=2).)

3+5i=(3,5)

3+5i+2j+7k=(3+5i,2+7i)=((3,5),(2,7))

Note that dimensional components are usually represented as ex, x being a non-negative integer.

e0 = 1
e1 = i
e2 = j
e3 = k

etc.

Firstly, in the Cayley-Dickson construction, the conjugate of a number  (a,b)∗is (a∗,−b),
and the conjugate of a real number is just itself.
In other words, the conjugate of a number is where every dimension is negated apart from the real dimension.

Multiplication is given by the formula:
(a,b)×(c,d)=(ac−d∗b,da+bc∗)

Where * represents conjugation as previously defined.

Any reasonable representation of the two numbers are allowed, as long as the representation supports ordering.

Test cases (up to 16 dimensions)
Note that your program must theoretically work for all higher dimensions if your language’s number type supported infinite precision,
infinite size integers, and no limits on e.g. recursion.

https://i.sstatic.net/p8VUT4fg.png

Example
Input 1:  e2
Input 2:  e10
Output:  −e8

"""

# Ported from @Anders Kaseorg solution
def mul(i, j):
    r = i ^ j
    if i == 0:
        return r, 1

    l = r | -r
    if i&~l != 0:
        z = (i & l) | (r + l)
        s = -mul(z, 1)[1]
    else:
        s = mul(j, r)[1]
    return r, s

def main():
    for i in range(16):
        for j in range(16):
            k, sign = mul(i, j)
            print({-1: "-", 1: " "}[sign] + f"e{k:<2}", end=" ")
        print()

main()
