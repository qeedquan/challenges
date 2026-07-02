#!/usr/bin/env python3

"""

A followup to this challenge by Jeremy Collprav, inspired by DLosc solving this in Regenerate. Some sections copied from the linked challenge.

Linking chains
We define a chain to be a string containing exactly one or more of only the - character, or 1 or more of only the _ character, or two chains linked by a =. More formally, a chain follows these 6 criteria:

The type (- or _) of chain must change after each =
Two chains must be linked with an = to change
The chain does not begin or end with a =
No two = may be adjacent
There must be at least 3 characters and both types of chain must appear
The chain must only contain _, - and =
Challenge
This is a sequence challenge, where the sequence is formed by all unique strings that form a valid chain. However, you may choose exactly what order this sequence is in, so long as your program is consistent and deterministic in this order. You must define your order in your answer.

Having chosen an order, you may then do one of the three tasks:

Take a non-negative/positive integer n as input and output the nth element in the sequence. This may be 0 or 1 indexed

Take a positive integer n as input and output the first n elements in the sequence, separated by a non-empty character that is not any of -, _ or =

Output the entire sequence, separated by a non-empty character that is not any of -, _ or =

You may output in any format that supports infinite outputs, such as a stream, a generator, or outputting without natural halt (stopping due to physical limitations such as memory is fine). Take a look through the default output methods for other possible methods.

This is a code-golf challenge, so the shortest code in bytes in each language wins.

A sample sequence
The most obvious sequence can be constructed by examining all possible links of each ascending length:

-=_
_=-
--=_
-=__
__=-
_=--
---=_
--=__
-=___
-=_=-
___=-
__=--
_=---
_=-=_
----=_
---=__
--=___
--=_=-
-=____
-=__=-
-=_=--
____=-
___=--
__=---
__=-=_
and so on. This sequence is implemented in this brute-force Jelly answer, which you can use to test for larger inputs. The top link was provided by Unrelated String's answer to the linked challenge.

"""

"""

Ported from @xnor solution

Prints the sequence forever, sorted by number of non-= characters. Based on Ajax1234's generator.
The idea is to do a BFS on valid strings by branching on either prepending a copy of the first character, or the other one of _- separated by an =.
Strings without an = aren't printed.

"""

def gen(n):
    l = ['_', '-']
    e = '='
    i = 0
    for s in l:
        if i >= n:
            break

        if e in s:
            print(s)
            i += 1
        
        a = s[0] + s
        b = l[0] + e + s
        if s > e:
            b = l[1] + e + s
        l += [a, b]

def main():
    gen(10)

main()
