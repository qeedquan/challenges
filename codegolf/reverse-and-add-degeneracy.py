#!/usr/bin/env python3

"""

Intro
Reverse and add is as simple as it sounds, take n and add it to its digits in reverse order. (e.g. 234 + 432 = 666).

If you apply this process repeatedly some numbers will eventually hit a prime number, and some will never reach a prime.

Example
I currently have

11431 rep.

11431 is not prime
11431 + 13411 = 24842 which is not prime
24842 + 24842 = 49684 which is not prime
49684 + 48694 = 98378 which is not prime
98378 + 87389 = 185767 which is prime!
This number hits a prime

In contrast any multiple of 3 will never hit a prime, this is because the all multiples of 3 have a digit sum that is a multiple of 3 and vice versa. Thus reverse and add on a multiple of 3 will always result in a new multiple of 3 and thus never a prime.

Task
Take a positive integer n and determine if repeatedly reversing and adding will ever result in a prime number. Output a truthy or falsy value. Either truthy for reaches a prime and falsy value for does not or the other way around both are acceptable.

Prime numbers will be considered to reach a prime number in zero iterations.

This is code-golf so try to make your code as short as possible.

Test Cases
True for reaches a prime false for never reaches a prime

11 -> True
11431 -> True
13201 -> True
13360 -> True
13450 -> True
1019410 -> True
1019510 -> True
22 -> False
1431 -> False
15621 -> False
14641 -> False

Hint
While I was writing this challenge I discovered a cool trick that makes this problem a good deal easier. It is not impossible without this trick and it is not trivial with it either but it does help. I had a lot of fun discovering this so I will leave it in a spoiler below.

Repeated reverse and add will always hit a multiple of 11 in 6 iterations or less. If it does not hit a prime before it hits a multiple of 11 it will never hit a prime.

"""

from sympy import *

def digits(n):
    d = []
    while True:
        d.append(n % 10)
        n //= 10
        if n == 0:
            break
    return d

def reverse(n):
    r = 0
    d = digits(n)
    for v in d:
        r = (r * 10) + v
    return r

def primeable(n):
    while not isprime(n):
        if n%11 == 0:
            return False
        n += reverse(n)
    return True

def main():
    assert(primeable(11) == True)
    assert(primeable(11431) == True)
    assert(primeable(13201) == True)
    assert(primeable(13360) == True)
    assert(primeable(13450) == True)
    assert(primeable(1019410) == True)
    assert(primeable(1019510) == True)
    assert(primeable(22) == False)
    assert(primeable(1431) == False)
    assert(primeable(15621) == False)
    assert(primeable(14641) == False)

main()
