#!/usr/bin/env python3

"""

Create a function that takes an argument n and sums even Fibonacci numbers up to n's index in the Fibonacci sequence.

Example:

sumFibs(5) === 2 // (0, 1, 1, 2, 3, 5);2 is the only even number in the sequence and doesn't have another number in the sequence to get added to in the indexed Fibonacci sequence.
Example:

sumFibs(9) === 44; // (0, 1, 1, 2, 3, 5, 8, 13, 21, 34)
// 2 + 8 + 34 = 44;

"""

from sympy import fibonacci

# https://oeis.org/A099919 (related)
def sumfibs(n):
    n //= 3
    if n < 0:
        return 0
    return (fibonacci(3*n + 2) - 1) // 2

def sumfibsbf(n):
    r, a, b = 0, 0, 1
    for i in range(2, n + 1):
        a, b = b, a + b
        if b%2 == 0:
            r += b
    return r

def main():
    assert(sumfibs(5) == 2)
    assert(sumfibs(9) == 44)
    assert(sumfibs(10) == 44)
    assert(sumfibs(11) == 44)
    for i in range(1000):
        assert(sumfibs(i) == sumfibsbf(i))

main()
