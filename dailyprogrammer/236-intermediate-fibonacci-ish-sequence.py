#!/usr/bin/env python3

"""

Description
The Fibonacci Sequence is a famous integer series in the field of mathematics. The sequence is recursively defined for n > 1 by the formula f(n) = f(n-1) + f(n-2). In plain english, each term in the sequence is found by adding the previous two terms together. Given the starting values of f(0) = 0 and f(1) = 1 the first ten terms of the sequence are:

0 1 1 2 3 5 8 13 21 34

We will notice however that some numbers are left out of the sequence and don't get any of the fame, 9 is an example. However, if we were to start the sequence with a different value for f(1) we will generate a new sequence of numbers. Here is the series for f(1) = 3:

0 3 3 6 9 15 24 39 102 165

We now have a sequence that contains the number 9. What joy!
Today you will write a program that will find the lowest positive integer for f(1) that will generate a Fibonacci-ish sequence containing the desired integer (let's call it x).

Input description
Your input will be a single positive integer x.

Sample Input 1: 21

Sample Input 2: 84

Output description
The sequence of integers generated using the recursion relation starting from 0 and ending at the desired integer x with the lowest value of f(1).

Sample Output 1: 0 1 1 2 3 5 8 13 21

Sample Output 2: 0 4 4 8 12 20 32 52 84

Challenge Inputs
Input 1: 0
Input 2: 578
Input 3: 123456789

Notes/Hints
Large inputs (such as input 3) may take some time given your implementation. However, there is a relationship between sequences generated using f(1) > 1 and the classic sequence that can be exploited.

Bonus
Make your program run as fast as possible.

Credit
This challenge was suggsted by u/nmacholl. Have a good challenge idea? Consider submitting it to r/dailyprogrammer_ideas and we might use it

"""

from itertools import count
from functools import lru_cache

@lru_cache(maxsize=None)
def fib(f1, n):
    if n < 1:
        return 0
    if n == 1:
        return f1
    return fib(f1, n - 1) + fib(f1, n - 2)

def find(n):
    m = 1
    for i in count(3):
        f = fib(1, i)
        if n%f == 0:
            m = i
        if f > n:
            break
    return m

"""

@Blackshell

It turns out that what the Fibonacci-ish sequences contain just multiples of the regular Fibonacci sequence.
The factor is the value of f(1).
To find the lowest possible value of f(1),
you have to iterate over the regular Fibonacci sequence to find the highest member of it that is a factor of the given integer x.
Divide x by that number and you have your value of f(1).

"""

def solve(n):
    p = find(n)
    f1 = n // fib(1, p)
    return [fib(f1, i) for i in range(p + 1)]

def main():
    print(solve(0))
    print(solve(21))
    print(solve(84))
    print(solve(578))
    print(solve(123456789))
    for i in range(1000000):
        assert(i in solve(i))

main()
