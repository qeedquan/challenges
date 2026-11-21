#!/usr/bin/env python3

"""

Who needs to compare things case insensitively when you're able to generate every permutation of uppercase and lowercase? No one! That's the answer. No one does.
Your task is to achieve this feat; generate all possible permutations of uppercase/lowercase for a given input.

Input
A string of printable standard ascii characters. Input should not be assumed to be all lowercase. Input will always be at least one character.

Output
Every permutation of uppercase and lowercase for the inputted string (no duplicates).
This should only change characters with a small and large version (numbers will stay the same).
Each permutation must be output as a string or a list of characters; lists of singleton strings are not allowed.

Examples
a1a
['a1a', 'a1A', 'A1a', 'A1A']

abc
['abc', 'abC', 'aBc', 'aBC', 'Abc', 'AbC', 'ABc', 'ABC']

Hi!
['hi!', 'hI!', 'Hi!', 'HI!']
Scoring
This is code-golf, so the shortest answer (in bytes) wins.

As a fun extra see how much additional effort it will take to handle the extended ascii characters, here is an extra test case:

ž1a -> ['ž1a', 'ž1A', 'Ž1a', 'Ž1A']
(your program does not need to support this)

"""

def caseperm(s):
    l = []
    for i in range(len(s)):
        if s[i].isalpha():
            l.append(i) 

    p = []
    n = len(l)
    for i in range(1<<n):
        for j in range(n):
            k = l[j]
            c = s[k].upper()
            if i&(1<<j) == 0:
                c = s[k].lower()
            s = s[:k] + c + s[k+1:]
        p.append(s)
   
    return p

def test(s, r):
    p = caseperm(s)
    print(p)
    assert(set(p) == set(r))

def main():
    test('a1a', ['a1a', 'a1A', 'A1a', 'A1A'])
    test('abc', ['abc', 'abC', 'aBc', 'aBC', 'Abc', 'AbC', 'ABc', 'ABC'])
    test('Hi!', ['hi!', 'hI!', 'Hi!', 'HI!'])
    test('ž1a', ['ž1a', 'ž1A', 'Ž1a', 'Ž1A'])

main()
