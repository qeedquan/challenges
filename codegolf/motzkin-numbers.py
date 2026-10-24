#!/usr/bin/env python3

"""

The nth Motzkin Number is the number of paths from (0, 0) to (n, 0) where each step is of the form (1, -1), (1, 0) or (1, 1), and the path never goes below y = 0.

Here's an illustration of these paths for n = 1, 2, 3, 4, from the above link:

https://i.stack.imgur.com/wWeee.gif

The desired sequence is OEIS A001006. OEIS has some other characterizations of the sequence.

You will be given a positive integer n as input. You should output the nth Motzkin Number.

Here are Motzkin numbers 1 to 10:

1, 2, 4, 9, 21, 51, 127, 323, 835, 2188
All standard input and output methods are allowed. Standard loopholes apply.

This is code golf. Fewest bytes wins.

"""

import scipy.special as sc

"""

https://oeis.org/A001006 
https://mathworld.wolfram.com/MotzkinNumber.html

M[n] = 2F1((1-n)/2, -n/2, 2, 4)

2F1 is the gaussian hypergeometric function

"""
def motzkin(n):
    return round(sc.hyp2f1((1-n)/2, -n/2, 2, 4))

def main():
    tab = [1, 1, 2, 4, 9, 21, 51, 127, 323, 835, 2188, 5798, 15511, 41835, 113634, 310572, 853467, 2356779, 6536382, 18199284, 50852019, 142547559, 400763223, 1129760415, 3192727797, 9043402501, 25669818476, 73007772802, 208023278209, 593742784829]

    for i in range(len(tab)):
        assert(motzkin(i) == tab[i])

main()
