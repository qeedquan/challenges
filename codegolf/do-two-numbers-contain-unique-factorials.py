#!/usr/bin/env python3

"""

Break two numbers up into their factorials; if they share any, return a falsey value. Otherwise, return a truthy value. (inspired by this recent question)

In other words, write each input number as the sum of factorials (of positive integers) in the greediest possible way; return a truthy value if no factorial appears in both representations, a falsey value otherwise.

Example
Given 20 and 49:

20 = 3! + 3! + 3! + 2!
49 = 4! + 4! + 1!
No factorial appears in both representations, so return a truthy value.

Given 32 and 132:

132 = 5! + 3! + 3!
 32 = 4! + 3! + 2!
3! appears in both representations, so return a falsey value.

I/O
Input and output can be through any standard means.

Input will always be two nonnegative integers; no upper bound on these integers other than what your language requires.

Output should be a truthy or falsey value. These values don't necessarily have to be consistent for different inputs, as long as every output is correctly truthy/falsey.

Test Cases
If one input is 0, the answer will always be truthy. Other truthy test cases:

{6, 3}, {4, 61}, {73, 2}, {12, 1}, {240, 2}, {5, 264}, {2, 91}, {673, 18},
 {3, 12}, {72, 10}, {121, 26}, {127, 746}
If both inputs are odd integers, or if both inputs are the same positive integer, then the output will always be falsey. Other falsey test cases:

{8, 5}, {7, 5}, {27, 47}, {53, 11}, {13, 123}, {75, 77}, {163, 160}, {148, 53},
 {225, 178}, {285, 169}, {39, 51}, {207, 334}, {153, 21}, {390, 128}, {506, 584},
 {626, 370}, {819, 354}

This is code-golf, so fewest bytes wins!

"""

# Ported from @xnor solution
def share(a, b, d=2):
    if a < 1:
        return True
    x = (a % d) * (b % d)
    y = share(a//d, b//d, d + 1)
    return x < y

def main():
    assert(share(6, 3) == True)
    assert(share(4, 61) == True)
    assert(share(73, 2) == True)
    assert(share(12, 1) == True)
    assert(share(240, 2) == True)
    assert(share(5, 264) == True)
    assert(share(2, 91) == True)
    assert(share(673, 18) == True)
    assert(share(3, 12) == True)
    assert(share(72, 10) == True)
    assert(share(121, 26) == True)
    assert(share(127, 746) == True)

    assert(share(8, 5) == False)
    assert(share(7, 5) == False)
    assert(share(27, 47) == False)
    assert(share(53, 11) == False)
    assert(share(13, 123) == False)
    assert(share(75, 77) == False)
    assert(share(163, 160) == False)
    assert(share(148, 53) == False)
    assert(share(225, 178) == False)
    assert(share(285, 169) == False)
    assert(share(39, 51) == False)
    assert(share(207, 334) == False)
    assert(share(153, 21) == False)
    assert(share(390, 128) == False)
    assert(share(506, 584) == False)
    assert(share(626, 370) == False)
    assert(share(819, 354) == False)

main()
