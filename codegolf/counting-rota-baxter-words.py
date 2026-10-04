#!/usr/bin/env python3

"""

A Rota-Baxter word, w, is a string made of the symbols a, (, and ) such that the following are satisfied:

The (s and )s are balanced.
aa, )( and () do not occur as contiguous substrings.
w does not begin with a ( and end with a ). That is it either begins with a or ends with a.
If ((v)) is a contiguous substring, then v is not a balanced string.
For example the following is valid:

a(a)a(a(a)a)
However none of the following are:

((a)    -- Parentheses are not balanced
aa(a)   -- Illegal substring
a(a)(a) -- Illegal substring
a()a    -- Illegal substring
(a)a(a) -- Begins and ends with parentheses
((a(a)))a  -- The string "a(a)" is enclosed twice

Task
Given a positive number n output the number of Rota-Baxter words containing exactly n as. You do not have to output the words themselves.

You may use any default sequence input output methods.

This is code-golf so the goal is to minimize the size of your source code as measured in bytes.

Test cases
The terms of the sequence can be found on OEIS: A157418

I've explicitly calculated all the words for up to 4 as

a

(a)a
a(a)

((a)a)a
(a(a))a
a((a)a)
a(a(a))
a(a)a

(((a)a)a)a
((a(a))a)a
((a)a(a))a
(a((a)a))a
(a(a(a)))a
a(((a)a)a)
a((a(a))a)
a((a)a(a))
a(a((a)a))
a(a(a(a)))
a(a(a)a)
(a(a)a)a
(a)a(a)a
a(a)a(a)
a((a)a)a
a(a(a))a

"""

from math import comb

def S(n):
    r = 0
    for i in range(1, n//2 + 1):
        r += comb(n, i - 1) * comb(2*(n - i), n) // (n - i)
    return r

"""

https://oeis.org/A157418

@Jonathan Allan

The number of Rota-Baxter words with n as with an a at only the left (or, equivalently, right) end is:

S(n) = Sum[i=1, floor(n/2)] binomial(n, i-1) * binomial(2*(n-i), n) / (n - i)

S(n-1) also gives the number of Rota-Baxter words with n as with an a at both ends, except when n=1 we have S(0)=0 rather than the required result of 1.

The number of Rota-Baxter words with n>1 as is then 2S(n)+S(n-1).


"""
def rota_baxter_words(n):
    if n < 1:
        return 0
    if n == 1:
        return 1
    return 2*S(n) + S(n - 1)

def main():
    tab = [
        1, 2, 5, 16, 55, 202, 773, 3052, 12339, 50830, 212593, 900368, 3853551,
        16641554, 72423661, 317312532, 1398490091, 6195882006, 27578607593,
        123270393880, 553075982311, 2489989595162, 11245131702245, 50929608736796
    ]
    for i in range(len(tab)):
        assert(rota_baxter_words(i + 1) == tab[i])

main()
