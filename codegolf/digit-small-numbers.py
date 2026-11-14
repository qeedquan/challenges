#!/usr/bin/env python3

"""

A digit small number is a positive integer  n such for any two numbers that multiply to n, their total number of digits is more than the digits in n.

In otherwords: there are no two positive integers a and b such that:

ab=n
and
⌊log10(a)⌋+⌊log10(b)⌋<⌊log10(n)⌋

For example 363 is digit small. It can be made as the product of two numbers 3 ways

1×363=3633×121=36311×33=363

Each time we have 4 digits on the left hand side and 3 on the right hand side.

As another example 48 is not digit small because we can write it as

6×8=48

where each side of the equation has 2 digits in total.

Task
Given a positive number output one of two distinct values depending on whether the input was digit small.
For example you could output 1 when the input is digit small and 0 if it is not, or True and False etc.

This is code-golf so answers will be scored in bytes.

Test cases
Here are the first 25 digit small numbers:

1,2,3,4,5,6,7,8,9,11,13,17,19,22,23,26,29,31,33,34,37,38,39,41,43

Hint
If you drop the test cases into OEIS you will get A122427. This sequence is useful, but you will have to prove where it is the same, or find the cases in which it is different.

"""

"""

https://oeis.org/A122427 (related)

@alephalpha

Let #n denote the number of digits in n.
Then n has a divisor d that is lexicographically greater than n ⟺
d∗10#n−#d>n ⟺
n/d<10#n−#d ⟺
#(n/d)≤#n−#d ⟺
n is not digit small.

"""

def dsn(n):
    if n < 1:
        return False

    for i in range(n):
        if str(i) > str(n) and n%i == 0:
            return False
    return True

def gen(n):
    r = []
    i = 1
    while len(r) < n:
        if dsn(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 13, 17, 19, 22, 23, 26, 29, 31, 33, 34, 37, 38, 39, 41, 43]

    assert(gen(len(tab)) == tab)

main()
