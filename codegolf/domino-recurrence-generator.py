#!/usr/bin/env python3

r"""

Challenge
We once had a challenge to count domino tilings of m by n grid, and we all know that, for any fixed number of rows,
the number of domino tilings by columns forms a linear recurrence.
Then why not have a challenge to compute the linear recurrence?!

Let's define  Dm(n) as the number of domino tilings on a grid of m rows and n columns.
Then the task is: given a single integer m≥1 as input, output the linear recurrence relation for Dm(n).


If the relation has order  k (that is, Dm(n+k) depends on k previous terms),
you need to output the coefficients ai of the recurrence relation

Dm(n+k) = a[k−1]*Dm(n+k−1) + a[k−2]*Dm(n+k−2) + ⋯ + a[0]*Dm(n)

in the order of a0 to ak−1 or the reverse.
There are infinitely many correct such relations; you don't need to minimize the order of the relation.
But, to ensure that the result is at least minimally useful, the order k cannot exceed 2m for any input value of m.

(Side note: An actual sequence is defined only if the initial k terms are given along with the recurrence equation.
That part is omitted for simplicity of output, and to give incentive to approaches not using the brute-forced terms.)

Note that, for odd m, every odd-column term will be zero, so you will get a recurrence different from the OEIS entries which strip away zeroes (e.g. 3 rows, 5 rows, 7 rows).

Standard code-golf rules apply. The shortest code in bytes wins.

Examples
Here are the representations from the OEIS, adjusted for odd m. Initial terms start at Dm(0),
and the coefficients are presented from ak−1 to a0.
Again, your program only needs to output the coefficients.
To empirically check the correctness of your output of length k,
plug in the k initial terms from the respective OEIS entry, and see if the next k terms agree.

m = 1
Initial terms [1, 0]  # D(0) = 1, D(1) = 0
Coefficients  [0, 1]  # D(n+2) = D(n)

m = 2
Initial terms [1, 1]
Coefficients  [1, 1]

m = 3
Initial terms [1, 0, 3, 0]
Coefficients  [0, 4, 0, -1]  # D(n+4) = 4D(n+2) - D(n)

m = 4
Initial terms [1, 1, 5, 11]
Coefficients  [1, 5, 1, -1]

m = 5
Initial terms [1, 0, 8, 0, 95, 0, 1183, 0]
Coefficients  [0, 15, 0, -32, 0, 15, 0, -1]

m = 6
Initial terms [1, 1, 13, 41, 281, 1183, 6728, 31529]
Coefficients  [1, 20, 10, -38, -10, 20, -1, -1]

Possible approaches
There is at least one way to find the recurrence without brute forcing the tilings, outlined below:

1. Compute the transition matrix A of 2m states, so that the target sequence is in the form of Dm(n)=uT*A^n*v for some column vectors  u,v.

2. Find the characteristic polynomial or minimal polynomial of  A as
x^k - a[k-1]*x^(k-1) - a[k]*2x^(k-2) - ⋯ - a0

3. Then the corresponding recurrence relation is
sn + k = a[k−1]*s^(n+k-1) + a[k−2]*s^(n+k−2) + ⋯ + a[0]*s^n

An example algorithm of computing the minimal polynomial of a matrix can be found on this pdf.
https://bulletin.pan.pl/(56-4)391.pdf

(Of course, you can just brute force the domino tilings for small  n and plug into a recurrence finder.)

"""

import re
import sympy
import sympy.abc

"""

Ported from @Arnauld solution

How?
State transitions
Given n−1 rows that are entirely filled and given an nth row which is partially filled with state Sm(n),
we want to find out what are the compatible states Sm(n+1) for the next row.

In the example below, we have m=5 and S5(n)=7 (in blue).
There are three valid ways of setting the next row while completing the nth row.
The compatible states S5(n+1) for the next row are 24, 27 and 30.

https://i.sstatic.net/pjHts.png

As a rule of thumb, empty cells in the nth row have to be filled with vertical dominoes (in yellow)
and we may then insert horizontal dominoes (in green) in the remaining free spaces of the new row.

In the Python code, we use the variables k and i for Sm(n) and Sm(n+1) respectively.

For the vertical dominoes, we make sure that the bits that are cleared in k are not cleared in i by testing if the following expression evaluates to 0:

~k & ~i & N
where N is a constant bit mask set to 2^m-1.

For the horizontal dominoes, we make sure that the islands of bits that are set in both k and i all include an even number of bits. We do that with a regular expression:

re.match("0b(0*11)*0*$", bin(k & i))
Both tests are combined into:

~k & ~i & N < bool(re.match("0b(0*11)*0*$", bin(k & i)))
Number of valid tilings
The variable a holds a list of 2^m entries describing how many times each state appeared in the previous iteration.
We update a by using the above tests: the new value for a[i] is the sum of all previous values a[k] for all pairs of compatible states (k,i):

a = [sum(a[k] * (...) for k in R) for i in R]
The total number of valid tilings is the number of times we reach the 'full' state (2^m−1) for the last row, which is a[-1].

Final solution
We use this method to compute the first 2m+2 terms of the sequence in the list L and inject it into find_linear_recurrence() to get the final solution.

Note: According to OEIS (and as already pointed out by fireflame241), computing  2⌈m/2⌉ terms would be enough and would make the code faster, but also a bit longer.
https://oeis.org/A187596#:%7E:text=linear%20recurrence%20of%20order

"""

def dominoes(m):
    L = [1]
    N = 2**m - 1
    a = [0]*N + L
    for _ in [0] + list(range(N + 1)):
        b = []
        for i in range(N + 1):
            v = 0
            for k in range(N + 1):
                if ((~k & ~i & N) == 0 and re.match("0b(0*11)*0*$", bin(k & i))):
                    v += a[k]
            b.append(v)
        a = b
        L += a[-1:]

    S = sympy.sequence(L, (sympy.abc.n, 1, N + 3))
    r = S.find_linear_recurrence(N + 3)
    return r

def main():
    assert(dominoes(1) == [0, 1])
    assert(dominoes(2) == [1, 1])
    assert(dominoes(3) == [0, 4, 0, -1])
    assert(dominoes(4) == [1, 5, 1, -1])
    assert(dominoes(5) == [0, 15, 0, -32, 0, 15, 0, -1])
    assert(dominoes(6) == [1, 20, 10, -38, -10, 20, -1, -1])

main()
