#!/usr/bin/env python3

"""

Summary
Given a Hash made up of keys and values, invert the hash by swapping them.

Examples
Given:

  { a: '1',
    b: '2',
    c: '3' }

Return:

  { 1: 'a',
    2: 'b',
    3: 'c' }

Given:

  { foo:   'bar',
    hello: 'world' }

Return:

  { bar:   'foo',
    world: 'hello' }

Notes
Keys and values may be of any type appropriate for use as a key.
All hashes provided as input will have unique values, so the inversion is involutive. In other words, do not worry about identical values stored under different keys.

"""

def invert(m):
    r = {}
    for k in m:
        r[m[k]] = k
    return r

def main():
    print(invert({'a': '1', 'b': '2', 'c': '3'}))
    print(invert({'foo': 'bar', 'hello': 'world'}))

main()
