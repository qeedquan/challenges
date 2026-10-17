#!/usr/bin/env python3

"""

This challenge is a harder version of this one.

https://codegolf.stackexchange.com/questions/71924/bijective-mapping-from-integers-to-a-variable-number-of-bits

A variable number of trits is an array of 0 or more trits (a trit is a ternary digit). So [0, 2, 2, 1] is a variable number of trits, but so is [].

Write a function or program that, given an non-negative integer returns a variable number of trits such that every integer has a one-to-one (bijective) mapping with an array.

There are an infinite amount of such mappings, you are free to construct one as you please, but it must be one-to-one. Your mapping must conceptually be one-to-one for an arbitrarily sized integer, but it's OK if your implementation fails for large integers due to numerical limits of types in your preferred language (e.g. C's int).

As an example of what is not a one-to-one mapping, is simply listing the ternary digits of the integer. In such a system 5 becomes [1, 2] (because 1*3^1 + 2*3^0 = 5), but it's not one-to-one, because [0, 1, 2] also means 5 (because 0*3^2 + 1*3^1 + 2*3^0 = 5).

It should be fairly obvious that a mapping is not one-to-one if it skips an integer (e.g. it doesn't work for 5), but I'd like to make it clear that skipping a variable trit array is also not one-to-one. You must map to every possible variable trit array, including [].

Bonus challenge
You will be awarded the official Super Smaht® Award™ if your answer includes an algorithm (not necessarily in your golfed program) that not only works for base 2 or 3, but for all bases.

Shortest code in bytes wins.

"""

def convba(n, b, p):
    if b <= 0:
        return []

    r = 0
    d = []
    while n > 0:
        d.append(n % b)
        n //= b
    return d[::-1]

def int2str(a):
    s = ""
    for v in a:
        s += str(v)
    return s

"""

@Anders Kaseorg

tjyhQ3
Explanation:

    Q    Input number.
   h     Add 1.
  y      Multiply by 2.
 j   3   Convert to base 3 as a list.
t        Remove the first element.
Test suite

Inverse function: Pyth, 14 bytes
t/i+-2%sQ2Q3 2
Explanation:

        Q        Input list.
       s         Sum.
      %  2       Modulo 2.
    -2           Subtract from 2.
   +      Q      Prepend to input list.
  i        3     Convert from base 3.
 /           2   Divide by 2.
t                Subtract 1.
Test suite

The bijection looks like this:

0: []
1: [1]
2: [0]
3: [2]
4: [0, 1]
5: [1, 0]
6: [1, 2]
7: [2, 1]
8: [0, 0]
9: [0, 2]
10: [1, 1]
11: [2, 0]
12: [2, 2]
13: [0, 0, 1]
14: [0, 1, 0]
15: [0, 1, 2]
16: [0, 2, 1]
17: [1, 0, 0]
18: [1, 0, 2]
19: [1, 1, 1]
⋮
General base
To make this work in any base b, simply replace 3 with b, 2 with (b − 1), and y with *(b − 1).

"""
def num2trit(n):
    return convba(2*n + 2, 3, 10)[1:]

def trit2num(a):
    x = [2 - (sum(a) % 2)] + a
    r = int(int2str(x), base=3)
    return r//2 - 1 

def main():
    tab = [[], [1], [0], [2], [0, 1], [1, 0], [1, 2], [2, 1], [0, 0], [0, 2], [1, 1], [2, 0], [2, 2], [0, 0, 1], [0, 1, 0], [0, 1, 2], [0, 2, 1], [1, 0, 0], [1, 0, 2], [1, 1, 1]]

    for i in range(len(tab)):
        assert(num2trit(i) == tab[i])
        assert(trit2num(num2trit(i)) == i)
    
main()
