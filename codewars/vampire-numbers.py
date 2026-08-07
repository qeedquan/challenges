#!/usr/bin/env python3

"""

Vampire Numbers
Our loose definition of Vampire Numbers can be described as follows:

6 * 21 = 126
# 6 and 21 would be valid 'fangs' for a vampire number as the 
# digits 6, 1, and 2 are present in both the product and multiplicands

10 * 11 = 110
# 110 is not a vampire number since there are three 1's in the
# multiplicands, but only two 1's in the product

Create a function that can receive two 'fangs' and determine if the product of the two is a valid vampire number.

"""

from collections import Counter

def vampire(a, b):
    c0 = Counter(str(a * b))
    c1 = Counter(str(a) + str(b))
    return c0 == c1

def main():
    assert(vampire(6, 21) == True)
    assert(vampire(10, 11) == False)
    assert(vampire(21, 6) == True)
    assert(vampire(204, 615) == True)
    assert(vampire(30, -51) == True)
    assert(vampire(-246, -510) == False)
    assert(vampire(210, 600) == True)

main()
