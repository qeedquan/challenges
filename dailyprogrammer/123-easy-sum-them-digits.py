#!/usr/bin/env python3

"""

As a crude form of hashing function, Lars wants to sum the digits of a number. Then he wants to sum the digits of the result, and repeat until he have only one digit left. He learnt that this is called the digital root of a number, but the Wikipedia article is just confusing him.

Can you help him implement this problem in your favourite programming language?

It is possible to treat the number as a string and work with each character at a time. This is pretty slow on big numbers, though, so Lars wants you to at least try solving it with only integer calculations (the modulo operator may prove to be useful!).

Author: TinyLebowski

Formal Inputs & Outputs
Input Description
A positive integer, possibly 0.

Output Description
An integer between 0 and 9, the digital root of the input number.

Sample Inputs & Outputs
Sample Input
31337

Sample Output
8, because 3+1+3+3+7=17 and 1+7=8

Challenge Input
1073741824

Challenge Input Solution
?

Note
None

"""

# https://en.wikipedia.org/wiki/Digital_root
def digroot(x):
    if x == 0:
        return 0
    return 1 + ((x - 1) % 9)

def main():
    assert(digroot(0) == 0)
    assert(digroot(31337) == 8)
    assert(digroot(1073741824) == 1)
    assert(digroot(12345) == 6)

main()
