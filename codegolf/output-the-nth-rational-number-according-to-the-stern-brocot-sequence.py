#!/usr/bin/env python3

"""

The Stern-Brocot sequence is a Fibonnaci-like sequence which can be constructed as follows:

1. Initialise the sequence with s(1) = s(2) = 1
2. Set counter n = 1
3. Append s(n) + s(n+1) to the sequence
4. Append s(n+1) to the sequence
5. Increment n, return to step 3

This is equivalent to:

       1 if n = 1
s(n) = s(n/2) if n is even
       s((n-1)/2) + s((n+1)/2) otherwise

Amongst other properties, the Stern-Brocot sequence can be used to generate every possible positive rational number. Every rational number will be generated exactly once, and it will always appear in its simplest terms; for example, 1/3 is the 4th rational number in the sequence, but the equivalent numbers 2/6, 3/9 etc won't appear at all.

We can define the nth rational number as r(n) = s(n) / s(n+1), where s(n) is the nth Stern-Brocot number, as described above.

Your challenge is to write a program or function which will output the nth rational number generated using the Stern-Brocot sequence.

The algorithms described above are 1-indexed; if your entry is 0-indexed, please state in your answer
The algorithms described are for illustrative purposes only, the output can be derived in any way you like (other than hard-coding)
Input can be via STDIN, function parameters, or any other reasonable input mechanism
Ouptut can be to STDOUT, console, function return value, or any other reasonable output stream
Output must be as a string in the form a/b, where a and b are the relevant entries in the Stern-Brocot sequence. Evaluating the fraction before output is not permissable. For example, for input 12, output should be 2/5, not 0.4.
Standard loopholes are disallowed
This is code-golf, so shortest answer in bytes will win.

Test cases

The test cases here are 1-indexed.

n    r(n)
--  ------
1    1/1
2    1/2
3    2/1
4    1/3
5    3/2
6    2/3
7    3/1
8    1/4
9    4/3
10   3/5
11   5/2
12   2/5
13   5/3
14   3/4
15   4/1
16   1/5
17   5/4
18   4/7
19   7/3
20   3/8
50   7/12
100  7/19
1000 11/39
OEIS entry: A002487
Excellent Numberphile video discussing the sequence: Infinite Fractions

"""

# https://oeis.org/A002487
def s(n):
    if n < 1:
        return 0
    if n == 1:
        return 1
    if n&1 == 0:
        return s(n//2)
    return s((n-1)//2) + s((n+1)//2)

def r(n):
    return (s(n), s(n+1))

def main():
    assert(r(1) == (1, 1))
    assert(r(2) == (1, 2))
    assert(r(3) == (2, 1))
    assert(r(4) == (1, 3))
    assert(r(5) == (3, 2))
    assert(r(6) == (2, 3))
    assert(r(7) == (3, 1))
    assert(r(8) == (1, 4))
    assert(r(9) == (4, 3))
    assert(r(10) == (3, 5))
    assert(r(11) == (5, 2))
    assert(r(12) == (2, 5))
    assert(r(13) == (5, 3))
    assert(r(14) == (3, 4))
    assert(r(15) == (4, 1))
    assert(r(16) == (1, 5))
    assert(r(17) == (5, 4))
    assert(r(18) == (4, 7))
    assert(r(19) == (7, 3))
    assert(r(20) == (3, 8))
    assert(r(50) == (7, 12))
    assert(r(100) == (7, 19))
    assert(r(1000) == (11, 39))

main()
