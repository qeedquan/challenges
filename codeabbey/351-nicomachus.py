#!/usr/bin/env python3

"""

You probably know from childhood various arithmetical "tricks" when person is asked to think of some secret number, do some operations to it, tell the result - and got the initial secret number correctly guessed by "magician".

Nicomachus was a Greek matematician living about 2 thousand years ago. Among his works is Introduction to Arithmetics and it describes probably one of the earliest of such "tricks":

think of the secret number, from 1 to 100
tell me the remainders of dividing it by 3, 5 and 7
and I'll guess your secret by this remainders
For example, if secret value is 50, remainders in order are 2, 0 and 1. This supposedly is enough for the guesser to figure out the secret. We shall try slightly advanced version of this trick. You are to be the "magician".

Problem Statement
We are to guess several secret values. For this we use 7 divisors, all small primes - and ask for remainders left after dividing secrets by these divisors.

Input gives 7 divisors in the first line.
Next line contains N - number of secret values to guess.
And then there follow N lines containing 7 remainders each.

Answer should tell N secret values, corresponding to each line of remainders. All of them should be minimum possible positive values producing the given remainders.

Example

input:

17 13 11 19
3
1 4 3 4
15 8 0 16
1 4 9 3

answer:

19517 814 13550

"""

from sympy.ntheory.modular import crt

# https://en.wikipedia.org/wiki/Chinese_remainder_theorem
def solve(divisors, remainders):
    solution, _ = crt(divisors, remainders)
    return solution

def main():
    assert(solve([17, 13, 11, 19], [1, 4, 3, 4]) == 19517)
    assert(solve([17, 13, 11, 19], [15, 8, 0, 16]) == 814)
    assert(solve([17, 13, 11, 19], [1, 4, 9, 3]) == 13550)

    for i in range(1, 3*5*7):
        assert(solve([3, 5, 7], [i%3, i%5, i%7]) == i)

    for i in range(1, 2**16):
        assert(solve([2**16], [i%2**16]) == i)

main()
