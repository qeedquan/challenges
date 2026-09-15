#!/usr/bin/env python3

"""

Implement a function which filters out array values which satisfy the given predicate.

reject([1, 2, 3, 4, 5, 6], (n) => n % 2 === 0)  =>  [1, 3, 5]

"""

def reject(sequence, predicate):
    return [x for x in sequence if not predicate(x)]

def main():
    assert(reject([1, 2, 3, 4, 5, 6], lambda x: x%2 == 0) == [1, 3, 5])
    assert(reject(['a', 'b', 3, 'd'], lambda x: type(x) == int) == ['a', 'b', 'd'])
    assert(reject(['a', 'b', 3, 'd'], lambda x: type(x) == str) == [3])

main()
