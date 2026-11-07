#!/usr/bin/env python3

"""

Task
Consider a sequence of numbers a0, a1, ..., an, in which an element is equal to the sum of squared digits of the previous element. The sequence ends once an element that has already been in the sequence appears again.

Given the first element a0, find the length of the sequence.

Example
For a0 = 16, the output should be 9

Here's how elements of the sequence are constructed:

a0 = 16

a1 = 12 + 62 = 37

a2 = 32 + 72 = 58

a3 = 52 + 82 = 89

a4 = 82 + 92 = 145

a5 = 12 + 42 + 52 = 42

a6 = 42 + 22 = 20

a7 = 22 + 02 = 4

a8 = 42 = 16, which has already occurred before (a0)

Thus, there are 9 elements in the sequence.

For a0 = 103, the output should be 4

The sequence goes as follows: 103 -> 10 -> 1 -> 1, 4 elements altogether.

Input/Output
[input] integer a0

First element of a sequence, positive integer.

Constraints: 1 ≤ a0 ≤ 650.

[output] an integer

"""

def square_digits_sequence(a0):
    m = {}
    x = a0
    while x not in m:
        m[x] = True
        x = sum(list(map(lambda v: int(v)**2, list(str(x)))))
    return len(m) + 1

def main():
    assert(square_digits_sequence(16) == 9)
    assert(square_digits_sequence(103) == 4)
    assert(square_digits_sequence(1) == 2)
    assert(square_digits_sequence(86) == 4)
    assert(square_digits_sequence(6) == 18)

main()
