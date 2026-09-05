#!/usr/bin/env python3

r"""

The cartesian product of two sets A and B, written "A × B" is equal to the set of all possible combinations of values from both sets. Here's an example, taken from Mathstopia ( https://www.mathstopia.net/sets/cartesian-product ):

https://www.mathstopia.net/wp-content/uploads/2021/01/cartesian-products.jpg

Your task
Implement function cart_prod, which returns the cartesian product (in the form of tuples) of any number of sets passed to it (note the * before sets in the function definition). Also,

The cartesian product A × B × C, where A, B and C are sets, is equal to (A × B) × C. See bottom of description for a concrete e×ample.
If no set is passed in, return a set containing an tempty tuple.
If a single set is passed in, return a set of tuples of the elements of the set.
If any of the sets passed in is empty, return an empty set.

Note : You are not allowed to use the word "itertools" in your solution (as in, from itertools import product ¯\(ツ)/¯).

Ecample with three sets

If A = {1, 2}; B = {'x', 'y'}; C = {δ, γ} Then A × B × C = {(1, 'x', δ), (1, 'x', γ), (1, 'y', δ), (1, 'y', γ),
                  (2, 'x', δ), (2, 'x', γ), (2, 'y', δ), (2, 'y', γ)} Note that the cardinality (number of elements) of a cartesian product is always equal to the product of the cardinalities of the sets in the cartesian product (here, |A| = |B| = |C| = 2, therefore |A × B × C| = 8).

"""

def cartesian_products(*a):
    p = {()}
    for s in a:
        q = set()
        for r in p:
            for e in s:
                q.add(r + (e,))
        p = q
    return p

A = {1, 2}
B = {'x', 'y'}
C = {'δ', 'γ'}
print(cartesian_products(A, B, C))

