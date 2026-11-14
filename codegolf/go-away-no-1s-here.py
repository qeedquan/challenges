#!/usr/bin/env python3

"""

I was playing around with some numbers and found a sequence that, of course, is on OEIS. It is A005823: Numbers whose ternary expansion contains no 1's. It goes:

a(2n) = 3*a(n)+2

a(2n+1) = 3*a(n+1)

a(1) = 0

a = 0,2,6,8,18,20,24,26,54....

I wrote a CJam program that generates the first n of these numbers by converting the index to binary, replacing the 1's with 2's, and converting from ternary to decimal.

I also noticed that any even number can be obtained by taking the sum of two numbers in the sequence (sometimes the number with itself).

The Challenge:

Given any non-negative even number as input, output the indices of two numbers in the sequence that sum to it. (Note that sometimes multiple pairs are possible.)

The Rules:

Specify if you're using 0- or 1-indexing.
If you're outputting as a string, put a delimiter between the two indices.
You are allowed to output as a complex number.
If you so desire, you can output every valid pair.
Code Golf: shortest answer wins
Test Cases
I use 0-indexing. Here I list every possible output for each input, but you only need to output one.

0:      [0 0]
2:      [1 0]
4:      [1 1]
6:      [2 0]
8:      [2 1]   [3 0]
10:     [3 1]
12:     [2 2]
14:     [3 2]
16:     [3 3]
18:     [4 0]
30:     [6 2]
32:     [6 3]   [7 2]
46:     [7 5]
50:     [7 6]
120:    [10 10]
338:    [19 18]
428:    [30 23] [31 22]
712:    [33 27] [35 25] [41 19] [43 17] [49 11] [51 9]  [57 3]  [59 1]
1016:   [38 37] [39 36]
Thanks to @Luis Mendo for test case help.

Related: Is it within the Cantor set?
https://codegolf.stackexchange.com/questions/108838/is-it-within-the-cantor-set

"""

from functools import lru_cache

@lru_cache(maxsize=None)
def f(n):
    if n < 1:
        return 0

    r = 2 * f(n//3)
    if (n//2)%3 > 0:
        r += 1
    return r

@lru_cache(maxsize=None)
def g(n):
    if n < 1:
        return 0

    r = 2 * g(n//3)
    if (n//2)%3 > 1:
        r += 1
    return r

"""

https://oeis.org/A005823 (related)

@xnor

f=lambda n:[n and(n/2%3>r)+2*f(n/3)[r]for r in 0,1]

The task can be done like this:

Halve the input
Convert to ternary list
Split that into two binary lists that sum elementwise to it
Convert those lists from binary
We can do the splitting in (3) by converting 0->0,1->1,2->1 for one list and 0->0,1->0,2->1 for the other. That is, by checking is the value is above a threshold of 0 or 1.

The two values can be found by respective recursive functions:

p=lambda n:n and(n/2%3>0)+2*p(n/3)
q=lambda n:n and(n/2%3>1)+2*q(n/3)
The function f combines the two of these in a list comprehension. This makes it inefficient due to exponential branching.

If complex numbers could be output, we could save 10 bytes with:

f=lambda n:n and(n%6>1)+n%6/4*1j+2*f(n/3)

"""

def seq(n):
    return f(n), g(n)

def main():
    print(seq(0))
    print(seq(2))
    print(seq(4))
    print(seq(6))
    print(seq(8))
    print(seq(10))
    print(seq(12))
    print(seq(14))
    print(seq(16))
    print(seq(18))
    print(seq(30))
    print(seq(32))
    print(seq(46))
    print(seq(50))
    print(seq(120))
    print(seq(338))
    print(seq(428))
    print(seq(712))
    print(seq(1016))

main()
