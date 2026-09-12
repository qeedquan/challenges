#!/usr/bin/env python3

"""

Inspired by a question over at Stack Overflow. The title here is entirely my fault.

The challenge
Given a list of positive integers containing at least two entries, replace each number by the minimum of all entries excluding itself.

Test cases
[4 3 2 5]    ->  [2 2 3 2]
[4 2 2 5]    ->  [2 2 2 2]
[6 3 5 5 8]  ->  [3 5 3 3 3]
[7 1]        ->  [1 7]
[9 9]        ->  [9 9]
[9 8 9]      ->  [8 9 8]

Rules
The algorithm should theoretically work for any input size (greater than one) and values (positive integers). It's accepted if the program is limited by time, memory or data types and so only works for numbers up to a given value, or for input size up to a given value.

Programs or functions are allowed, in any programming language. Standard loopholes are forbidden.

Input can be taken by any reasonable means; and with any format. Same for output. Input and output formats may be different.

Shortest code in bytes wins.

"""

def modest_minimum(a):
    r = []
    for i in range(len(a)):
        r.append(min(a[:i] + a[i + 1:]))
    return r

def main():
    assert(modest_minimum([4, 3, 2, 5]) == [2, 2, 3, 2])
    assert(modest_minimum([4, 2, 2, 5]) == [2, 2, 2, 2])
    assert(modest_minimum([6, 3, 5, 5, 8]) == [3, 5, 3, 3, 3])
    assert(modest_minimum([7, 1]) == [1, 7])
    assert(modest_minimum([9, 9]) == [9, 9])
    assert(modest_minimum([9, 8, 9]) == [8, 9, 8])

main()
