#!/usr/bin/env python3

"""

Some background
In math, a group is a tuple (G,∗) where G is a set and ∗ is an operation on G such that for any two elements x,y∈G,x∗y∈G.

For some x,y,z∈G, basic group axioms are as follows:

G is closed under ∗, i.e. x∗y∈G
The operation ∗ is associative, i.e. x∗(y∗z)=(x∗y)∗zG has an identity element, i.e. there exists e∈G such that x∗e=x for all x
The operation ∗ is invertible, i.e. there exist a,b∈G such that a∗x=y and y∗b=x
Okay, so those are groups. Now we define an Abelian group as a group (G,∗) such that ∗ is a commutative operation. That is, x∗y=y∗x.

Last definition. The order of a group (G,∗), denoted |G|, is the number of elements in the set G.

Task
The Abelian orders are the integers n such that every group of order n is Abelian. The sequence of Abelian orders is A051532 in OEIS. Your job is to produce the n
th term of this sequence (1-indexed) given an integer n. You must support input up to the largest integer such that nothing will overflow.

Input can come from function arguments, command line arguments, STDIN, or whatever is convenient.

Output can be returned from a function, printed to STDOUT, or whatever is convenient. Nothing should be written to STDERR.

Score is number of bytes, shortest wins.

Examples
Here are the first 25 terms of the sequence:

1, 2, 3, 4, 5, 7, 9, 11, 13, 15, 17, 19, 23, 25, 29, 31, 33, 35, 37, 41, 43, 45, 47, 49, 51

"""

from sympy import *

# https://oeis.org/A051532
def abelian(n):
    if n == 1:
        return True

    f = factorint(n)
    p, e = f.keys(), f.values()
    if max(e) >= 3:
        return False

    for pi in p:
        for pj in p:
            for k in range(1, f[pi] + 1):
                if (pi**k)%pj == 1:
                    return False
    return True

def gen(n):
    r = []
    i = 1
    while len(r) < n:
        if abelian(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [1, 2, 3, 4, 5, 7, 9, 11, 13, 15, 17, 19, 23, 25, 29, 31, 33, 35, 37, 41, 43, 45, 47, 49, 51, 53, 59, 61, 65, 67, 69, 71, 73, 77, 79, 83, 85, 87, 89, 91, 95, 97, 99, 101, 103, 107, 109, 113, 115, 119, 121, 123, 127, 131, 133, 137, 139, 141, 143, 145, 149, 151, 153, 157, 159, 161]
   
    assert(gen(len(tab)) == tab)

main()
