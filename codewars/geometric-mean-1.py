#!/usr/bin/env python3

"""

For a variable, x, that may have different values, the geometric mean is defined as:

http://i.imgur.com/tD9bZui.png

Suposse that you have to calculate the geometric mean for a research where the amount of values of x is rather small.

Implement the function geometric_meanI(), (geometricMeanI javascript)that receives an array with the different values of the variable and outputs the geometric mean value.

The negative values and strings will be discarded for the calculations.

Nevertheless if the amount of total invalid values is too high, the function will return 0 (Nothing in Haskell). The tolerance for invalid values of the variable will be as follows:

amount of entries      maximum invalid entries
  2 - 10                       1
  From 11 and above       10 % of total of entries

You do not have to round the results.

"""

import numpy as np

def geometric_mean(a):
    n = len(a)
    c = 0
    p = 1
    for x in a:
        if (isinstance(x, float) or isinstance(x, int)) and x > 0:
            p *= x
            c += 1
    if n - c > 1:
        return 0
    return p**(1/c)

def main():
    arr = [2, 3, 4, 6]
    assert(np.allclose(geometric_mean(arr), 3.46410161514))

    arr = [2, 3, 4, 6, -5]
    assert(np.allclose(geometric_mean(arr), 3.46410161514))

    arr = [2, 3, 4, 6, '5']
    assert(np.allclose(geometric_mean(arr), 3.46410161514))

    arr = [2, 3, 4, 6, - 5, '5']
    assert(np.allclose(geometric_mean(arr), 0))

    arr = [2, 2, 3, 4, 10, 8, 1, 4, 6, 7, 2]
    assert(np.allclose(geometric_mean(arr), 3.59348221822))

    arr = [2, 2, 3, 4, 10, -4, 8, 1, 4, 6, 7, 2]
    assert(np.allclose(geometric_mean(arr), 3.59348221822))

    arr = [2, 2, 3, 0, 4, 10, -4, 8, 1, 4, 6, 7, 2]
    assert(np.allclose(geometric_mean(arr), 0.0))

    arr = [2, 2, 3, 4, 10, -4, 8, 1, 4, 6, 7, 2, '']
    assert(np.allclose(geometric_mean(arr), 0))

main()
