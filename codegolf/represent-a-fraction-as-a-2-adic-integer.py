#!/usr/bin/env python3

"""

Objective
Given a reduced fraction whose denominator is positive and odd, represent the fraction as a 2-adic integer.

Introduction to 2-adic integers
Informally
Informally, a 2-adic integer is an infinite string of binary digits that expands to left. As a consequence, 2-adic integers consist a superset of integers represented in two's complement. Addition on 2-adic integers is defined as the usual bit-wise addition-with-carry, and multiplication on 2-adic integers is defined as the same as the schoolbook multiplication.

What's interesting about 2-adic integers is that negation is well-defined. Given a 2-adic integer x, its negation −x is defined as bitNOT(x)+1.
That is, to arithmetically negate a 2-adic integer, bit-wise negate it and add  1.
This is akin to the two's complement representation of signed integers.

Provided that q is a positive odd integer, it's possible to divide any 2-adic integer by q.
Its explicit method of computation requires formal definition of 2-adic integers, which is explained below.

Formally
A formal, alternative representation of the 2-adic integers is a certain subring of the product ring  ∏∞n=1Z/⟨2n⟩ (That is, the Cartesian product of integers modulo 2, integers modulo 4, integers modulo 8, and so on infinitely).
The restriction employed by the 2-adic integers is that, for every positive integer  n, the entry in Z/⟨2n+1⟩ must be equal to the entry in  Z/⟨2n⟩, up to modulo 2n.

Provided that p is a 2-adic integer and q is a positive odd integer, the division p/q is simply entry-wise modular division by q.
This is possible because q is coprime to 2n for every positive integer n, and the division results in a well-defined 2-adic number.

The formal representation above can be turned into the informal representation recursively as follows. The resulting rightmost bit is 0 if the provided entry in  Z/⟨2⟩ is 0, and is 1 otherwise.
For every positive integer n, the n-th (zero-indexed) rightmost bit is 0 if the entry in Z/⟨2^(n+1)⟩ is equal to the entry in  Z/⟨2^n⟩ up to modulo 2^(n+1), and is 1 otherwise. And this correspondence can easily go the other way round.

I/O format
It is known that every rational number amongst the 2-adic integers has repeating informal representation. As such, there shall be two binary strings for the output, one for the non-repeating part, the other for the repeating part. The repeating part shall have at least one bit.

For every input, you must give the shortest expansion as the output. That is, no redundant expansion. For example, provided that the output format is (<repeating part>)<non-repeating part>, the input 1/3 must give (01)1, not (10)11 nor (01)011, as the output.

Otherwise flexible.

Examples
Here, the output format is (<repeating part>)<non-repeating part>.

Input, "Output"

0/1, "(0)"
1/1, "(0)1"
2/1, "(0)10"
-1/1, "(1)"
-2/1, "(1)0"
-3/1, "(1)01"
1/3, "(01)1"
2/3, "(01)10"
4/3, "(01)100"
5/3, "(01)11"
-1/3, "(01)"
-2/3, "(10)"
1/5, "(0110)1"
2/5, "(0110)10"
3/5, "(0011)1"

"""

"""

Ported from @Jonathan Allan solution

A recursive function that accepts the numerator, n, and the denominator, d,
and returns a representation of the 2-adic integer, a list of integers from  [0,2] where a single 2
acts as the separator between the non-empty repeating portion and the, potentially empty, non-repeating portion.

"""
def fraction_to_2adic(numerator, denominator, *rest):
    values = rest if numerator in rest else ()
    result = []
    for value in values:
        result.append(value % 2)
        if numerator == value:
            result.append(2)
    if result:
        return result
    next_n = (numerator - (numerator % 2) * denominator) >> 1
    return fraction_to_2adic(next_n, denominator, numerator, *rest)

def main():
    tests = [
        "0/1 (0)",
        "1/1 (0)1",
        "2/1 (0)10",
        "-1/1 (1)",
        "-2/1 (1)0",
        "-3/1 (1)01",
        "1/3 (01)1",
        "2/3 (01)10",
        "4/3 (01)100",
        "5/3 (01)11",
        "-1/3 (01)",
        "-2/3 (10)",
        "1/5 (0110)1",
        "2/5 (0110)10",
        "3/5 (0011)1"
    ]

    for line in tests:
        test, expected = line.split()
        n, d = map(int, test.split("/"))
        result = fraction_to_2adic(n,d)
        actual = "(" + "".join(map(str, result)).replace("2", ")")
        print(test, "=>", result, "=>", actual)
        assert actual == expected, f"FAIL! Expected: {expected}"

main()
