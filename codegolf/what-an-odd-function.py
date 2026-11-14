#!/usr/bin/env python3

"""

Your task here will be to implement a function1 that forms a permutation on the positive integers (A bijection from the positive integers onto themselves). This means that each positive integer should appear exactly once in the permutation. The catch is your function should have a larger probability of outputting an odd number than an even number.

Now this may seem strange or impossible. Surely there are just as many odd numbers as even numbers? And while this intuition is correct for finite sets it actually does not hold for infinite sets. For example take the following permutation:

1 3 2 5 7 4 9 11 6 13 15 8 17 19 10 21 23 12 25 27 14 29 31 16 33 35 18 37 39 20 41 43 22 45 47 24 49 51 26 53 55 ...
If you take any subsection of the sequence with size greater than  1
  you will have at least as many odd numbers as even numbers, thus it seems that the probability of any random term being odd is greater than that of being even. You will also note every number odd or even number will eventually appear in the sequence and can only appear once. Thus the sequence is a true permutation.

Definition of Probability
To avoid confusion or ambiguity I am going to clearly lay out what is meant by probability in this question.

Let us say we have a function f.
The probability of a number being odd will be defined as the limit of ratio odd members of the set to the size of the set f{1…n} as n tends towards infinity.

lim[n->oo] |x { x in {1..n}, odd(f(x)) } / n


For example the aforementioned function would have a probability of being odd of  2/3
 .

This is code-golf so answers will be scored in bytes with less bytes being better.

Extra Challenges
Here are some fun ideas to play around with and perhaps try to implement.
These are just for fun and do not affect scoring in any way.
Some of these are not even valid solutions to this challenge,
and an answer which only includes solutions to challenges 2 or 3 is not a valid answer, and is liable to be deleted.

Write a permutation with an odd probability of 1. (this is possible)

Write a permutation that has more odd numbers than even numbers in f{1…n} for any n but has a odd probability of 1/2.

Write a permutation that has no defined probability (that is there is no limit). (Now a standalone challenge here)

1: Here function will mean program or function. It is just a piece of code that takes input and produces output.

"""

from sympy import factorint

"""

@Dennis

Swaps 2s and 3s in the input's prime factorization. The probability of odds is 2/3.

"""

def f(n):
    if n < 1:
        return 0
    
    r = 1
    f = factorint(n)
    for p in f:
        if p == 2:
            r *= 3**f[p]
        elif p == 3:
            r *= 2**f[p]
        else:
            r *= p**f[p]
    return r

def main():
    for i in range(1, 101):
        print(i, f(i))

main()
